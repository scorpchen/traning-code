    function init(){
        id = setInterval("showAd()", 3000);
    }
    function showAd(){
        var adEle = document.getElementById("img");
        adEle.style.display = "block";
        clearInterval(id);
        id = setInterval("hiddenAd()", 3000);
    }
    function hiddenAd(){
        document.getElementById("img").style.display = "none";
        clearInterval(id);
    }
