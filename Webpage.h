// Webpage.h
#ifndef _WEBPAGE_h
#define _WEBPAGE_h

PROGMEM const char* website  =

"<!DOCTYPE html>	\r\n\
<html lang=\"de\">	\r\n\
<head>	\r\n\
  <title>AmbientESP</title>	\r\n\
  <meta charset=\"utf-8\">	\r\n\
  <meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">   	\r\n\
  <link rel=\"stylesheet\" href=\"https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css\"> 	\r\n\
  <link rel=\"stylesheet\" href=\"https://cdnjs.cloudflare.com/ajax/libs/bootstrap-slider/9.7.0/css/bootstrap-slider.min.css\"> 	\r\n\
    	\r\n\
  <script src=\"https://ajax.googleapis.com/ajax/libs/jquery/3.1.1/jquery.min.js\"></script>  	\r\n\
  <script src=\"https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js\"></script>  	\r\n\
  <script src=\"https://cdnjs.cloudflare.com/ajax/libs/bootstrap-slider/9.7.0/bootstrap-slider.min.js\"></script>	\r\n\
	\r\n\
<style>	\r\n\
    	\r\n\
html {	\r\n\
    height: 100%;	\r\n\
}	\r\n\
 	\r\n\
body {	\r\n\
    height: 100%;	\r\n\
    margin: 0;	\r\n\
    background-color: black;	\r\n\
    background-repeat: no-repeat;	\r\n\
    background-attachment: fixed;	\r\n\
    color: white; 	\r\n\
    font-size: 18px;	\r\n\
}	\r\n\
#HSV {	\r\n\
	height: 100%;	\r\n\
    border-radius: 5px;	\r\n\
    margin-top: 5px;	\r\n\
    margin-bottom: 10px;	\r\n\
    margin-left: 8px;	\r\n\
    margin-right: 8px;	\r\n\
    padding: 10px;	\r\n\
    background: hsla(0,0%,100%,0.1);	\r\n\
}	\r\n\
        	\r\n\
#HV .slider-selection,	\r\n\
#SV .slider-selection,	\r\n\
#LV .slider-selection {	\r\n\
	background: grey;	\r\n\
}	\r\n\
    	\r\n\
	\r\n\
    	\r\n\
#HV .round,	\r\n\
#SV .round,	\r\n\
#LV .round {	\r\n\
	background: brand-primary;	\r\n\
    width: 35px;	\r\n\
    height: 35px;	\r\n\
    top: -8px;	\r\n\
}	\r\n\
    	\r\n\
    .row {	\r\n\
       margin-top: 5px; 	\r\n\
    }	\r\n\
    	\r\n\
	\r\n\
    #NachtlichtSybi {	\r\n\
        background-color: mistyrose;	\r\n\
    }	\r\n\
    	\r\n\
    #NachtlichtMichi {	\r\n\
        background-color: skyblue;	\r\n\
    }	\r\n\
	\r\n\
.slider-horizontal {width: 100% !important;}    	\r\n\
    	\r\n\
        	\r\n\
</style>	\r\n\
	\r\n\
    	\r\n\
</head>	\r\n\
<body>	\r\n\
	\r\n\
<div class=\"container-fluid\"> 	\r\n\
    <div class=\"row\" id=\"HSV\">	\r\n\
  	\r\n\
 	\r\n\
 <!--<form method=\"post\">-->	\r\n\
<p>	\r\n\
    Farbe <input type=\"text\" class=\"span2\" value=\"\" data-slider-min=\"0\" data-slider-max=\"160\" data-slider-step=\"1\" data-slider-value=\"30\" data-slider-id=\"HV\" id=\"H\" data-slider-tooltip=\"hide\" data-slider-handle=\"round\" />	\r\n\
<p>	\r\n\
Sättigung <input type=\"text\" class=\"span2\" value=\"\" data-slider-min=\"0\" data-slider-max=\"255\" data-slider-step=\"1\" data-slider-value=\"125\" data-slider-id=\"SV\" id=\"S\" data-slider-tooltip=\"hide\" data-slider-handle=\"round\" />	\r\n\
</p>	\r\n\
<p>	\r\n\
Helligkeit <input type=\"text\" class=\"span2\" value=\"\" data-slider-min=\"0\" data-slider-max=\"255\" data-slider-step=\"1\" data-slider-value=\"124\" data-slider-id=\"LV\" id=\"V\" data-slider-tooltip=\"hide\" data-slider-handle=\"round\" />	\r\n\
</p>	\r\n\
       <!-- </form>-->	\r\n\
   </div> 	\r\n\
 	\r\n\
    <div class=\"row\">	\r\n\
        <div class=\"col-sm-12\">	\r\n\
            Nachtlicht	\r\n\
        </div>	\r\n\
    </div>	\r\n\
    	\r\n\
<div class=\"row\">	\r\n\
    <div class=\"col-sm-12\">	\r\n\
        <div class=\"btn-group btn-group-justified\" role=\"group\" aria-label=\"Nachtlicht\">	\r\n\
            <div class=\"btn-group\" role=\"group\">	\r\n\
                <button type=\"button\" class=\"btn btn-lg\" data-loading-text=\"an...\" id=\"NachtlichtSybi\">Left</button>	\r\n\
            </div>	\r\n\
            <div class=\"btn-group\" role=\"group\">	\r\n\
                <button type=\"button\" class=\"btn btn-lg\" data-loading-text=\"an...\" id=\"NachtlichtMichi\">Right</button>	\r\n\
            </div>	\r\n\
        </div>	\r\n\
    </div>	\r\n\
</div>	\r\n\
    	\r\n\
<div class=\"row\">	\r\n\
    <div class=\"col-sm-12\">	\r\n\
        Sonnen...	\r\n\
    </div>	\r\n\
</div>	\r\n\
    	\r\n\
<div class=\"row\">	\r\n\
    <div class=\"col-sm-12\">	\r\n\
        <div class=\"btn-group btn-group-justified\" role=\"group\" aria-label=\"Sonnen\">	\r\n\
            <div class=\"btn-group\" role=\"group\">	\r\n\
                <button type=\"button\" class=\"btn btn-warning btn-lg\" data-loading-text=\"startet...\" id=\"Sunrise\">aufgang</button>	\r\n\
            </div>	\r\n\
            <div class=\"btn-group\" role=\"group\">	\r\n\
                <button type=\"button\" class=\"btn btn-danger btn-lg\"  data-loading-text=\"startet...\" id=\"Sunset\">untergang</button>	\r\n\
            </div>	\r\n\
        </div>	\r\n\
    </div>  	\r\n\
</div>	\r\n\
    	\r\n\
<div class=\"row\">	\r\n\
    <div class=\"col-sm-12\">	\r\n\
        Wecker	\r\n\
    </div>	\r\n\
</div>	\r\n\
	\r\n\
<div class=\"row\">	\r\n\
    <div class=\"col-sm-12\">	\r\n\
        <div class=\"input-group input-group-lg\">	\r\n\
              <input type=\"text\" class=\"form-control\" placeholder=\"6:50\" id=\"wecker\">	\r\n\
              <span class=\"input-group-btn\">	\r\n\
                <button class=\"btn btn-default\" type=\"button\" data-loading-text=\"wird gesetzt...\" id=\"WeckerStellen\">Los!</button>	\r\n\
              </span>	\r\n\
        </div><!-- /input-group -->	\r\n\
    </div>	\r\n\
 </div>	\r\n\
    	\r\n\
<div class=\"row\">	\r\n\
    <div class=\"col-sm-12\">	\r\n\
        <button type=\"button\" class=\"btn btn-default btn-block btn-lg\" data-loading-text=\"aus...\" id=\"Off\">Aus</button>	\r\n\
    </div>	\r\n\
</div>	\r\n\
    	\r\n\
	\r\n\
    	\r\n\
	\r\n\
	\r\n\
 </div>	\r\n\
</body>	\r\n\
	\r\n\
<script type=\"text/javascript\">	\r\n\
 	\r\n\
var timeoutID;	\r\n\
var h, s,v;	\r\n\
var bTimerSet = false;	\r\n\
var strPlaceHolderTime = 'z.B. \"6:30\" eintragen';	\r\n\
    	\r\n\
    	\r\n\
	\r\n\
var GetHSVValues = function() {	\r\n\
    	\r\n\
    	\r\n\
    $.post( \"set.php\", { hsv: \"?\" })	\r\n\
        .done(function(data) {	\r\n\
        	\r\n\
            h.setValue(data.h);	\r\n\
            s.setValue(data.s);	\r\n\
            v.setValue(data.v);	\r\n\
            HSVChange();	\r\n\
    })    	\r\n\
	\r\n\
};	\r\n\
  	\r\n\
    	\r\n\
var HSVChange = function() {	\r\n\
    	\r\n\
    	\r\n\
	var hue = h.getValue()/255.0*360.0;		\r\n\
	var sat = s.getValue()/255.0*100.0;		\r\n\
	var val = v.getValue()/255.0*100.0;		\r\n\
    	\r\n\
    if(val.toFixed(0) > 0)	\r\n\
    {	\r\n\
    	$(document.body).css('background', 'linear-gradient(hsla(' + hue.toFixed(0) + ',' + sat.toFixed(0) + '%,' + '50%,' + sat.toFixed(0) /100.0 + ')' +  (val.toFixed(0)-50) + '%,black)');	\r\n\
    }	\r\n\
    else	\r\n\
    {	\r\n\
        $(document.body).css('background','black');   	\r\n\
    }	\r\n\
 	\r\n\
};	\r\n\
    	\r\n\
var HChange = function() {	\r\n\
      	\r\n\
    if(bTimerSet == false)	\r\n\
    {	\r\n\
        bTimerSet = true;	\r\n\
        timeoutID = window.setTimeout(HChangeStop, 100);     	\r\n\
    }	\r\n\
 	\r\n\
};	\r\n\
	\r\n\
var SChange = function() {	\r\n\
      	\r\n\
    if(bTimerSet == false)	\r\n\
    {	\r\n\
        bTimerSet = true;	\r\n\
        timeoutID = window.setTimeout(SChangeStop, 100);     	\r\n\
    }	\r\n\
 	\r\n\
};	\r\n\
	\r\n\
var VChange = function() {	\r\n\
      	\r\n\
    if(bTimerSet == false)	\r\n\
    {	\r\n\
        bTimerSet = true;	\r\n\
        timeoutID = window.setTimeout(VChangeStop, 100);     	\r\n\
    }	\r\n\
 	\r\n\
};	\r\n\
	\r\n\
	\r\n\
	\r\n\
function HChangeStop() {	\r\n\
    	\r\n\
     HSVChange();	\r\n\
    	\r\n\
     $.post( 	\r\n\
         \"set.php\", 	\r\n\
         { hue: h.getValue() })	\r\n\
     	\r\n\
         .done( function(data) 	\r\n\
        {	\r\n\
          bTimerSet = false;	\r\n\
        }); 	\r\n\
    	\r\n\
    	\r\n\
}	\r\n\
    	\r\n\
    	\r\n\
function SChangeStop() {	\r\n\
    	\r\n\
     HSVChange();	\r\n\
    	\r\n\
     $.post( 	\r\n\
         \"set.php\", 	\r\n\
         { sat: s.getValue() })	\r\n\
     	\r\n\
         .done( function(data) 	\r\n\
        {	\r\n\
          bTimerSet = false;	\r\n\
        }); 	\r\n\
        	\r\n\
}	\r\n\
    	\r\n\
    	\r\n\
function VChangeStop() {	\r\n\
    	\r\n\
     HSVChange();	\r\n\
    	\r\n\
     $.post( 	\r\n\
         \"set.php\", 	\r\n\
         { val: v.getValue() })	\r\n\
     	\r\n\
         .done( function(data) 	\r\n\
        {	\r\n\
          bTimerSet = false;	\r\n\
        });	\r\n\
}	\r\n\
    	\r\n\
    	\r\n\
    	\r\n\
var h =  $('#H').slider()	\r\n\
		.on('change', HSVChange)	\r\n\
        .on('change', HChange)	\r\n\
		.data('slider');	\r\n\
var s = $('#S').slider()	\r\n\
		.on('change', HSVChange)	\r\n\
        .on('change', SChange)	\r\n\
		.data('slider');	\r\n\
var v = $('#V').slider()	\r\n\
		.on('change', HSVChange)	\r\n\
        .on('change', VChange)	\r\n\
		.data('slider');  	\r\n\
    	\r\n\
    	\r\n\
	\r\n\
	\r\n\
	\r\n\
$( document ).ready(function() {	\r\n\
    	\r\n\
	\r\n\
GetHSVValues();   	\r\n\
 	\r\n\
    	\r\n\
$.post( \"set.php\", { Wecker: \"?\" })	\r\n\
        .done(function(data) {	\r\n\
            strPlaceHolderTime = \"Gestellt auf \" + String(data.hour) + \":\" + String(data.minute) + \" Uhr\";	\r\n\
            $(\"#wecker\").attr(\"placeholder\",strPlaceHolderTime); 	\r\n\
        })	\r\n\
       	\r\n\
    	\r\n\
	\r\n\
           	\r\n\
	\r\n\
 $('body').attr('unselectable','on')	\r\n\
     .css({'-moz-user-select':'-moz-none',	\r\n\
           '-moz-user-select':'none',	\r\n\
           '-o-user-select':'none',	\r\n\
           '-khtml-user-select':'none', /* you could also put this in a class */	\r\n\
           '-webkit-user-select':'none',/* and add the CSS class here instead */	\r\n\
           '-ms-user-select':'none',	\r\n\
           'user-select':'none'	\r\n\
        }).bind('selectstart', function(){ return false; });	\r\n\
	\r\n\
    	\r\n\
    $(\"#Sunrise\").on('click', function(){	\r\n\
       var $btn = $(this).button('loading')	\r\n\
        	\r\n\
       $.post( \"set.php\", { ChangeState: \"Sunrise\" })	\r\n\
        .done(function(data) {	\r\n\
          $btn.button('reset');	\r\n\
        })	\r\n\
        .fail(function(data) {	\r\n\
          //$btn.button('reset');	\r\n\
          //alert('Fehler: ' + data);	\r\n\
        })	\r\n\
    });	\r\n\
	\r\n\
    $(\"#Sunset\").on('click', function(){	\r\n\
       var $btn = $(this).button('loading')	\r\n\
        	\r\n\
       $.post( \"set.php\", { ChangeState: \"Sunset\" })	\r\n\
        .done(function(data) {	\r\n\
          $btn.button('reset');	\r\n\
        })	\r\n\
        .fail(function(data) {	\r\n\
          //$btn.button('reset');	\r\n\
          //alert('Fehler: ' + data);	\r\n\
        })	\r\n\
    });	\r\n\
    	\r\n\
    $(\"#Off\").on('click', function(){	\r\n\
       var $btn = $(this).button('loading')	\r\n\
        	\r\n\
       $.post( \"set.php\", { ChangeState: \"Off\" })	\r\n\
        .done(function(data) {	\r\n\
          $btn.button('reset');	\r\n\
           timeoutID = window.setTimeout(GetHSVValues, 10000);	\r\n\
        })	\r\n\
       	\r\n\
        .fail(function(data) {	\r\n\
          //$btn.button('reset');	\r\n\
          //alert('Fehler: ' + data);	\r\n\
        })	\r\n\
    });	\r\n\
    	\r\n\
    $(\"#WeckerStellen\").on('click', function(){	\r\n\
       var $btn = $(this).button('loading')	\r\n\
        	\r\n\
       $.post( \"set.php\", { Wecker: $('#wecker').val() })	\r\n\
        .done(function(data) {	\r\n\
          $btn.button('reset');	\r\n\
        })	\r\n\
        .fail(function(data) {	\r\n\
          //$btn.button('reset');	\r\n\
          //alert('Fehler: ' + data);	\r\n\
        })	\r\n\
    });	\r\n\
        	\r\n\
    $(\"#NachtlichtSybi\").on('click', function(){	\r\n\
       var $btn = $(this).button('loading')	\r\n\
        	\r\n\
       $.post( \"set.php\", { Nachtlicht: \"Sybi\" })	\r\n\
        .done(function(data) {	\r\n\
          $btn.button('reset');	\r\n\
        })	\r\n\
        .fail(function(data) {	\r\n\
          //$btn.button('reset');	\r\n\
          //alert('Fehler: ' + data);	\r\n\
        })	\r\n\
    });	\r\n\
    	\r\n\
	\r\n\
    $(\"#NachtlichtMichi\").on('click', function(){	\r\n\
       var $btn = $(this).button('loading')	\r\n\
        	\r\n\
       $.post( \"set.php\", { Nachtlicht: \"Michi\" })	\r\n\
        .done(function(data) {	\r\n\
          $btn.button('reset');	\r\n\
        })	\r\n\
        .fail(function(data) {	\r\n\
          //$btn.button('reset');	\r\n\
          //alert('Fehler: ' + data);	\r\n\
        })	\r\n\
    });	\r\n\
    	\r\n\
	\r\n\
    	\r\n\
});	\r\n\
 </script>	\r\n\
    	\r\n\
</html>";
#endif
