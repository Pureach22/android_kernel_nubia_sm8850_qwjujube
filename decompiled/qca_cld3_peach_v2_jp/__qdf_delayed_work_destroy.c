__int64 _qdf_delayed_work_destroy()
{
  return cancel_delayed_work_sync();
}
