#!/usr/bin/env node
console.log("Calling logic as a pure function");
const result1 = logic("param1", "param2");
console.log("Result is: "+result1);
console.log();
console.log("Calling logic as a regular function");
const result2 = logic("param3","param4",
  (level, msg)=>{console.log("LOG["+level+"] ["+msg+"]");},
  (status)=>{console.log("Current status set to: "+status);},
  (obj)=>{console.log("Called notify message on object: "+obj);},
  ()=>{dbLookupResult = false; return false;},
  (info)=>{console.log("Info written to file [["+info+"]]");}
)
console.log("Result is "+result2);

function logic(param1, param2, log, setStatus, notify, eStop, saveFile){
  if (setStatus){ setStatus("running"); }
  const s1 = param1+"::"+param2;
  if (log){ log("INFO", "About to do Step 2, this could take awhile"); }
  const s2 = s1+"::step2";
  if (log){ log("INFO", "Completed step 2"); }
  const s3 = s2+"::step3";
  if (notify){ notify("randomobjectnotify"); }
  if (eStop && eStop()){
    if (setStatus){ setStatus("stopped"); }
    return "stoppedresult";
  }
  const s4 = s3+"::step4";
  if (setStatus){ setStatus("completed"); }
  if (saveFile){ saveFile("Logic completed for params "+param1+"::"+param2); }
  return s4;
}
