package main

import "fmt"

type Log func(level string, msg string)
type SetStatus func(status string)
type Notify func(obj string)
type EStop func() bool
type SaveFile func(msg string)

func main() {
	fmt.Println("Calling logic as a pure function")
	var result = logic("param1", "param2", nil, nil, nil, nil, nil)
	fmt.Println("Result is " + result)

	fmt.Println("Calling logic as a regular function")
	result = logic("param1", "param2",
		func(level string, msg string) { fmt.Println("LOG[" + level + "][" + msg + "]") },
		func(status string) { fmt.Println("Current status set to: " + status) },
		func(obj string) { fmt.Println("Called notify message on object: " + obj) },
		func() bool { var dbLookupResult = false; return dbLookupResult },
		func(info string) { fmt.Println("Info written to file [[" + info + "]]") })
	fmt.Println("Result is " + result)
}

func logic(param1 string, param2 string, log Log, setStatus SetStatus, notify Notify, eStop EStop, saveFile SaveFile) string {
	if setStatus != nil {
		setStatus("running")
	}
	var s1 = param1 + "::" + param2
	if log != nil {
		log("INFO", "About to do Step 2, this could take awhile")
	}
	var s2 = s1 + "::step2"
	if log != nil {
		log("INFO", "Completed step 2")
	}
	var s3 = s2 + "::step3"
	if notify != nil {
		notify("randomobjectnotify")
	}
	if eStop != nil && eStop() {
		if setStatus != nil {
			setStatus("stopped")
		}
		return "stoppedresult"
	}
	var s4 = s3 + "::step4"
	if setStatus != nil {
		setStatus("completed")
	}
	if saveFile != nil {
		saveFile("Logic completed for params " + param1 + "::" + param2)
	}
	return s4
}
