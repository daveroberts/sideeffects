package foo{
  object HelloWorld {
    def main(args: Array[String]): Unit = {
      println("Calling logic as a pure function")
      var result = logic(
        "param1",
        "param2",
        (level:String,msg:String)=>{},
        (status:String)=>{},
        (obj:Any)=>{},
        ()=>{false},
        (info:String)=>{});
      println("Result is: "+result)
      println("Calling logic as a regular function")
      // Regular invocation
      var result2 = logic(
        "param1",
        "param2",
        (level:String,msg:String)=>{
          // call your actual logging framework
          println("LOG["+level+"] ["+msg+"]");
        },
        (status:String)=>{
          // set a variable to check elsewhere
          println("Current status set to: "+status)
        },
        (obj:Any)=>{
          println("Called notify message on object: "+obj);
        },
        ()=>{
          val dbLookupResult = false
          dbLookupResult
        },
        (info:String)=>{
          println("Info written to file [["+info+"]]");
        });
      println("Result is: "+result2)
    }

    def logic(param1: String,
              param2: String,
              log:(String, String)=>Unit,
              setStatus:(String)=>Unit,
              notify:(Any)=>Unit,
              eStop:()=>Boolean,
              saveFile:(String)=>Unit):String = {
      setStatus("running")
      val s1 = param1+"::"+param2
      log("INFO", "About to do Step 2, this could take awhile")
      val s2 = s1+"::step2"
      log("INFO", "Completed step 2")
      val s3 = s2+"::step3"
      notify("randomobjecttonotify")
      if (eStop()){
        setStatus("stopped")
        return "stoppedresult"
      }
      val s4 = s3+"::step4"
      setStatus("completed")
      saveFile("Logic completed for params "+param1+"::"+param2)
      return s4
    }
  }
}
