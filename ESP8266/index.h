const char _index[] PROGMEM = R"=====(
<!doctype html>
<html lang=en>
<head>
<meta charset=UTF-8>
<meta http-equiv=X-UA-Compatible content="IE=edge">
<meta name=viewport content="width=device-width,initial-scale=1">
<link rel=stylesheet href=styles.css>
<title>socket Car</title>
</head>
<body>
<div class=container>
<div class=header>
<div class=row>
<div class=nav-icon>
<button class="nav-hamburger c-pointer"><svg class=hamburger-icon viewBox="0 0 24 24" fill=none stroke-width=2 stroke-linecap=round stroke-linejoin=round>
<line x1=3 y1=12 x2=21 y2=12></line>
<line x1=3 y1=6 x2=21 y2=6></line>
<line x1=3 y1=18 x2=21 y2=18></line>
</svg></button>
</div>
<div class=c3>
<p class=title>Socket Car</p>
</div>
<div id=status class=c3></div>
</div>
</div>
<div class=content>
<div class=nav-bar>
<div class="nav-tiles df-c">
<p class="t-center py px push-down" id=headlight>Headlight <svg id=headLight-icon viewBox="0 0 24 24" fill=none stroke-linecap=round stroke-linejoin=round>
<circle cx=12 cy=12 r=5></circle>
<line x1=12 y1=1 x2=12 y2=3></line>
<line x1=12 y1=21 x2=12 y2=23></line>
<line x1=4.22 y1=4.22 x2=5.64 y2=5.64></line>
<line x1=18.36 y1=18.36 x2=19.78 y2=19.78></line>
<line x1=1 y1=12 x2=3 y2=12></line>
<line x1=21 y1=12 x2=23 y2=12></line>
<line x1=4.22 y1=19.78 x2=5.64 y2=18.36></line>
<line x1=18.36 y1=5.64 x2=19.78 y2=4.22></line>
</svg></p>
<input class="slider my w-100" type=range id=brightness max=255 min=0 value=0>
</div>
<div class=nav-tiles id=connection>
Offline <div class="dot dot-offline"></div>
</div>
<div class="nav-tiles push-down" id=restart>
Restart
</div>
<div class="nav-tiles push-down" id=deepSleep>
Deep sleep
</div>
<div class="nav-tiles push-down" id=setting>
settings
</div>
<div class="nav-tiles push-down" id=setup>
Credentials
</div>
<div class="nav-tiles push-down" id=darkmode>
Dark Mode
</div>
</div>
<div class=gamepad>
<div class=row-center>
<button class="forward g-btn"></button>
</div>
<div class=row-center>
<button class="left g-btn"></button>
<button class="stop g-btn"><svg viewBox="0 0 24 24" fill=none stroke-linecap=round stroke-linejoin=round>
<circle cx=12 cy=12 r=10></circle>
</svg></button>
<button class="right g-btn"></button>
</div>
<div class=row-center>
<button class="backward g-btn"></button>
</div>
<div class="row-center my">
<input type=range class="slider speed" max=255 min=0 value=0>
<p id=speed-val class=slider-text>0</p>
</div>
</div>
<div class="settings d-n">
<div class=frow>
<p class=s-title>Controls</p>
</div>
<div class=frow>
<div>
<div class=card>
<div class=dfe>
<p class="text t-center">Keyboard Controls</p>
<label class=switch>
<input id=keyboardS type=checkbox onchange=handleController(event)>
<span class=check></span>
</label>
</div>
<div class=dfe>
<button class=card-btn id=key-reset>Reset Defaults</button>
<button class=card-btn onclick=renderKeys()>Cancel</button>
</div>
<table class="table my" id=keyboard-controls>
</table>
</div>
</div>
<div>
<div class=card>
<div class=dfe>
<p class="text t-center">Gamepad Controls</p>
<label class=switch>
<input id=joystickS type=checkbox onchange=handleController(event)>
<span class=check></span>
</label>
</div>
<table class="table my" id=joystick-controls>
<tr class=table-head>
<th>Control</th>
<th>Channel</th>
</tr>
<tr class=table-body>
<td>axis</td>
<td>
<div class=progress>
<div>
<div></div>
</div>
</div>
</td>
</tr>
</table>
</div>
</div>
</div>
<div class=frow>
<p class=s-title>Timed DeepSleep</p>
</div>
<div class=frow>
<div class=card>
<p class="text t-center">DeepSleep</p>
<div class=dfe>
<input type=number class="card-number mx" min=0 max=9999 placeholder=HH oninput=validDs(this) id=dsHH>
<input type=number class="card-number mx" min=0 max=59 placeholder=MM oninput=validDs(this) id=dsMM>
<input type=number class="card-number mx" min=0 max=59 placeholder=SS oninput=validDs(this) id=dsSS>
</div>
<div class=dfe>
<button class=card-btn id=timed-ds>DeepSleep</button>
</div>
</div>
</div>
<div class=frow>
<p class=s-title>Reset Data</p>
</div>
<div class=frow>
<div>
<div class=card>
<div class=dfe>
<p class=text>Reset State</p>
</div>
<div class=dfe>
<button class=card-btn id=reset-state>Reset</button>
</div>
</div>
</div>
<div>
<div class=card>
<div class=dfe>
<p class=text>Reset Credentials</p>
</div>
<div class=dfe>
<button class=card-btn id=reset-creds>Reset</button>
</div>
</div>
</div>
<div>
<div class=card>
<div class=dfe>
<p class=text>Factory Reset</p>
</div>
<div class=dfe>
<button class=card-btn id=reset-all>Reset</button>
</div>
</div>
</div>
</div>
</div>
<div class=setup>
<div>
<div class=card>
<p class="text t-center">STA Credentials</p>
<div class=dfe>
<input class=card-textbox placeholder=SSID id=SSID_STA>
</div>
<div class=dfc><input type=password class=card-textbox placeholder=password id=PASS_STA><div class=pass id=_PASS_STA></div></div>
<div class=dfe>
<button class=card-btn id=SUBMIT_STA>Submit</button>
</div>
</div>
</div>
<div>
<div class=card>
<p class="text t-center">AP Credentials</p>
<div class=dfe>
<input class=card-textbox placeholder=SSID id=SSID_AP>
</div>
<div class=dfc><input type=password class=card-textbox placeholder=password id=PASS_AP><div class=pass id=_PASS_AP></div></div>
<div class=dfe>
<button class=card-btn id=SUBMIT_AP>Submit</button>
</div>
</div>
</div>
</div>
</div>
</div>
<script src=script.js></script>
</body>
</html>
)=====";