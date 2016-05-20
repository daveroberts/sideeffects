#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

// the method named log conflicts
void logger(char *level, char *msg){ printf("LOG[%s] [%s]\n",level, msg); }
void setStatus(char *status){ printf("Current status set to: %s\n", status); }
void notify(char *obj){ printf("Called notify message on object: %s\n", obj); }
bool eStop(){ bool dbLookupResult = false; return false; }
void saveFile(char *info){ printf("Info written to file [[%s]]\n", info); }

char* logic(char *param1, char *param2, void (*f_log)(), void (*f_setStatus)(), void (*f_notify)(), bool (*f_eStop)(), void (*f_saveFile)()){
  char *result = (char*)malloc(9999); // I don't write C, improvements welcome
  if (f_setStatus != NULL){ f_setStatus("running"); }
  sprintf(result, "%s::%s", param1, param2);
  if (f_log != NULL){ f_log("INFO", "About to do Step 2, this could take awhile"); }
  sprintf(result, "%s::%s", result, "step2");
  if (f_log != NULL){ f_log("INFO", "Completed step 2"); }
  sprintf(result, "%s::%s", result, "step3");
  if (f_notify != NULL){ f_notify("randomobjectnotify"); }
  if (f_eStop != NULL && f_eStop()){
    if (f_setStatus != NULL){ f_setStatus("stopped"); }
    return "stoppedresult";
  }
  sprintf(result, "%s::%s", result, "step4");
  if (f_setStatus != NULL){ f_setStatus("completed"); }
  if (f_saveFile != NULL){ f_saveFile("Logic completed for params"); } // I didn't concat the params, not sure how without allocating a new string
  return result;
}

main()
{
  printf("Calling logic as a pure function\n");
  char *result = logic("param1", "param2", NULL, NULL, NULL, NULL, NULL);
  printf("%s\n", result);
  free(result);

  printf("Calling logic as a regular function\n");
  result = logic("param1", "param2", logger, setStatus, notify, eStop, saveFile);
  printf("%s\n", result);
  free(result);
}

