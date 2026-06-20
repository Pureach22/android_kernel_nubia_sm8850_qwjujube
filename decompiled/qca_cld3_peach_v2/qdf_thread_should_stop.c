__int64 qdf_thread_should_stop()
{
  return kthread_should_stop() & 1;
}
