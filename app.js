const $ = id => document.getElementById(id);
let demoOn = true, packetCount = 0, timer = null;
const alerts = [];
function addTerminal(text){const t=$('terminal');const row=document.createElement('div');row.textContent=`${new Date().toLocaleTimeString()}  ${text}`;t.appendChild(row);while(t.children.length>80)t.removeChild(t.firstChild);t.scrollTop=t.scrollHeight;}
function addAlert(level,msg){const item={level,msg,time:new Date().toLocaleTimeString()};alerts.unshift(item);alerts.splice(8);renderAlerts();}
function renderAlerts(){$('alerts').replaceChildren();if(!alerts.length){$('alerts').innerHTML='<div class="empty">No alerts received.</div>';return;}alerts.forEach(a=>{const d=document.createElement('div');d.className='alert '+(a.level==='CRITICAL'?'critical':'');const b=document.createElement('b');b.textContent=`${a.level} · ${a.msg}`;const s=document.createElement('small');s.textContent=a.time;d.append(b,s);$('alerts').appendChild(d);});}
function ingest(p,raw='') {
 if(!p || typeof p!=='object') throw new Error('Packet must be a JSON object');
 packetCount++; $('packets').textContent=packetCount;
 if(p.rssi!==undefined && p.rssi!==null){$('rssi').textContent=`${p.rssi} dBm`;$('linkQuality').textContent=Number(p.rssi)>-80?'STRONG':Number(p.rssi)>-105?'MARGINAL':'WEAK';$('signal').textContent=$('linkQuality').textContent;}
 if(p.battery!==undefined && p.battery!==null)$('battery').textContent=`${p.battery}%`;
 if(p.temperature!==undefined && p.temperature!==null)$('temperature').textContent=`${Number(p.temperature).toFixed(1)} °C`;
 if(Number.isFinite(Number(p.lat))&&Number.isFinite(Number(p.lon))){$('lat').textContent=Number(p.lat).toFixed(5);$('lon').textContent=Number(p.lon).toFixed(5);$('coords').textContent=`${$('lat').textContent}, ${$('lon').textContent}`;}
 $('node').textContent=p.node||'unknown';
 const al=String(p.alert||'NORMAL').toUpperCase();$('alertLevel').textContent=al;$('systemStatus').textContent=al==='NORMAL'?'NOMINAL':al;
 if(al==='CRITICAL'||al==='SOS'||al==='LOW_BATTERY')addAlert('CRITICAL',`${al} from ${p.node||'node'}`);
 else if(al!=='NORMAL')addAlert('WARNING',`${al} from ${p.node||'node'}`);
 $('mission').textContent=p.mission||'TELEMETRY RECEIVED';
 addTerminal(raw||JSON.stringify(p));
}
function demoPacket(){const p={type:'telemetry',node:'relay-01',seq:packetCount+1,rssi:-Math.round(58+Math.random()*35),battery:Math.round(92+Math.random()*7),temperature: +(26+Math.random()*5).toFixed(1),lat:17.6868+(Math.random()-.5)*.004,lon:83.2185+(Math.random()-.5)*.004,alert:Math.random()>.96?'LINK_WARNING':'NORMAL'};ingest(p);$('mode').textContent='DEMO MODE · SIMULATED';}
function startDemo(){clearInterval(timer);if(demoOn){demoPacket();timer=setInterval(demoPacket,3500);}}
$('toggleDemo').addEventListener('click',()=>{demoOn=!demoOn;$('toggleDemo').textContent=demoOn?'PAUSE DEMO':'RESUME DEMO';if(demoOn)startDemo();else{clearInterval(timer);$('mode').textContent='DEMO PAUSED';}});
$('packetForm').addEventListener('submit',e=>{e.preventDefault();const raw=$('packetInput').value.trim();if(!raw)return;try{ingest(JSON.parse(raw),raw);$('packetInput').value='';}catch(err){addTerminal('PARSE ERROR: '+err.message);addAlert('WARNING','Invalid JSON packet');}});
startDemo();
