'use strict';

var videoplay = document.querySelector('video#player')


//设备的展示与选择
var audioSource = document.querySelector("select#audioSource");
var audioOutput = document.querySelector("select#audioOutput");
var videoSource = document.querySelector("select#videoSource");

var filtersSelect = document.querySelector("select#filter");

var snapshot = document.querySelector("button#snapshot");
var picture = document.querySelector("canvas#picture");

picture.width = 320;
picture.height = 240;


var divConstraints = document.querySelector('div#constraints');

//record
var recvideo = document.querySelector('video#recplayer');
var btnRecord = document.querySelector('button#record');
var btnPlay = document.querySelector('button#recplay');
var btnDownload = document.querySelector('button#download');

var buffer;//保存采集的视频流二进制datas
var mediaRecorder;


/***
 * 参数deviceInfos是设备信息的数组
 */
function gotDevices(deviceInfos) {    
    deviceInfos.forEach((deviceInfo) => {
        console.log(deviceInfo.kind + ':label = ' + deviceInfo.label + ':id = ' + deviceInfo.deviceId + ':groupId = ' + deviceInfo.groupId);
        var option = document.createElement('option');
        option.value = deviceInfo.deviceId;
        option.text = deviceInfo.label;
        if(deviceInfo.kind === 'audioinput'){       //deviceInfo.kind来判断种类;音频
            audioSource.appendChild(option);
        }else if(deviceInfo.kind === 'audiooutput'){        //音频输出
            audioOutput.appendChild(option);
        }else if(deviceInfo.kind === 'videoinput' ){           //视频
            videoSource.appendChild(option);
        }

    });
}

//获取流
function gotMediaStream (stream){
    

    var videoTrack = stream.getVideoTracks()[0];//获取video track 这里取第一个
    var videoConstraints =  videoTrack.getSettings();//获取所有的约束
    
    divConstraints.textContent = JSON.stringify(videoConstraints,null,2)//转换成JSON，第一個参数是約束，第二個参数null，第三個参数是缩进空格
    window.stream = stream;//赋值给全局window
    videoplay.srcObject = stream;

    return navigator.mediaDevices.enumerateDevices();   //成功获取流；并返回一个promise；用于后边对设备的判断
}

//错误处理
function handleError (err){
    console.log(err);
}

function start(){
    if( !navigator.mediaDevices || !navigator.mediaDevices.getUserMedia ){
        console.log('getUserMedia is not support!');
        return;
    }else{

        //https://developer.mozilla.org/en-US/docs/Web/API/Media_Streams_API/Constraints#example__constraint_exerciser 可以参考下重点掌握feature

        var deviceId = videoSource.value;   //获取设备ID；用于当设备选择改变的时候改变设备
        var constraints = {
            video : {
                width:640,
                height:480,
                frameRate:30,    //帧率
                facingMode:'user',    //facingMode摄像头的q前置还是后置的设置 user enviroment
                deviceId:deviceId ? deviceId :undefined
            },
            audio : {
                noiseSupression:true,   //降噪
                echoCancellation:true,  //回音消除设置成true
            },
            
        }
        navigator.mediaDevices.getUserMedia(constraints)
        .then(gotMediaStream)   //获取流
        .then(gotDevices)       //设备获取处理
        .catch(handleError);
    }
}
start();
videoSource.onchange = start;       //在视频規則改变的时候，即onchange时候重新调用start函数;实现设备的切换

filtersSelect.onchange = function(){        //视频特效
    videoplay.className = filtersSelect.value;      //设置视频的className方便加滤镜
}

snapshot.onclick = function(){
    picture.className = filtersSelect.value;    //设置滤镜
    picture.getContext('2d').drawImage(videoplay,   //数据源
                                        0,0,            //开始和结束位置
                                        picture.width,      //画布宽
                                        picture.height)     //画布高
}



btnRecord.onclick = () => {
    if(btnRecord.textContent === 'Start Record'){
        startRecord();
        btnRecord.textContent = 'Stop Record';
        btnPlay.disabled = true;
        btnDownload.disabled = true;
    }else{
        stopRecord();
        btnRecord.textContent = 'Start Record';
        btnPlay.disabled = false;
        btnDownload.disabled = false;
    }
}


function handleDataAvailable(e){
    if(e && e.data && e.data.size>0){
        buffer.push(e.data)
    }
}

//
// var types = ["video/webm",
//              "audio/webm",
//              "video/webm\;codecs=vp8",
//              "video/webm\;codecs=daala",
//              "video/webm\;codecs=h264",
//              "audio/webm\;codecs=opus",
//              "video/mpeg"];


function startRecord(){
    buffer = [];
    var options = {
        mimType:'video/webm;codecs=vp8,audio/webm'//这里可以配置音视频编解码 这里没有配置audio
    } 
    if(!MediaRecorder.isTypeSupported(options.mimType)){//检查mimtype是否支持
        console.error(`${options.mimType} is not supported!`)
        return;
    }
    try{
        mediaRecorder = new MediaRecorder(window.stream,options);
    }catch(e){
        console.log('Failed to create MediaRecorder,e')
        return;
    }
    mediaRecorder.ondataavailable = handleDataAvailable;//数据有效时候处理
    mediaRecorder.start(10);//传入时间分片 每隔多少时间push data 1次
}
function stopRecord(){
    mediaRecorder.stop();
}

// https://developer.mozilla.org/zh-CN/docs/Web/API/Blob
btnPlay.onclick = () => {
    var blob = new Blob(buffer,{type:'video/webm'});//生成一個blob可以處理buffer的對象；buffer就是剛剛錄製的一個數據
    recvideo.src = window.URL.createObjectURL(blob);//使用 Blob 创建一个指向类型化数组的URL
    recvideo.srcObject = null; //srcObject 主要是用直播推流中使用 https://developer.mozilla.org/en-US/docs/Web/API/HTMLMediaElement/srcObject
    recvideo.controls = true;//控制播放
    recvideo.play();//獲取流之後調用play播放video
}

/***
 * 本地下载文件
 */
btnDownload.onclick = () => {
    var blob = new Blob(buffer,{type:'video/webm'});
    var url = window.URL.createObjectURL(blob);
    var a = document.createElement('a');

    a.href = url;
    a.style.display = 'none';
    a.download = 'aaa.webm';
    a.click();
}