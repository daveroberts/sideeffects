def logic(param1, param2, log = nil, setStatus = nil, notify = nil, eStop = nil, saveFile = nil)
  setStatus.call("running") if setStatus
  s1 = "#{param1}::#{param2}"
  log.call("INFO", "About to do Step 2, this could take awhile") if log
  s2 = "#{s1}::step2"
  log.call("INFO", "Completed step 2") if log
  s3 = "#{s2}::step3"
  notify.call("randomobjectnotify") if notify
  if (eStop != nil && eStop.call)
    setStatus.call("stopped") if setStatus
    return "stoppedresult"
  end
  s4 = "#{s3}::step4"
  setStatus.call("completed") if setStatus
  saveFile.call("Logic completed for params #{param1}::#{param2}") if saveFile
  return s4
end

puts "Calling logic as a pure function"
result = logic("param1", "param2")
puts "Result is #{result}"

puts "Calling logic as a regular function"
result = logic(
  "param1",
  "param2",
  ->(level, msg){puts "LOG[#{level}] [#{msg}]"},
  ->(status){puts "Current status set to: #{status}"},
  ->(obj){puts "Called notify message on object: #{obj}"},
  ->(){dbLookupResult = false},
  ->(info){puts "Info written to file [[#{info}]]"}
)
puts "Result is: #{result}"
