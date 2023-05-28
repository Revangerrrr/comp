set app = CreateObject("Pervakov.Application")
  
app.SetTitle()
app.ShowTasks()
app.DeleteTask()

app.test = 11
p = app.test()
Wscript.Echo(p)

app.test = 111
p = app.test()
Wscript.Echo(p)
