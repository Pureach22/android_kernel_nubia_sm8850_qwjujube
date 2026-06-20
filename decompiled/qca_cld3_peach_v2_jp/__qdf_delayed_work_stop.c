__int64 _qdf_delayed_work_stop()
{
  return cancel_delayed_work() & 1;
}
