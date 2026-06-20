__int64 _qdf_delayed_work_stop_sync()
{
  return cancel_delayed_work_sync() & 1;
}
