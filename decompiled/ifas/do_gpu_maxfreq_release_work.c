__int64 do_gpu_maxfreq_release_work()
{
  if ( ifas_log_enable )
    printk(&unk_EDD7, "do_gpu_maxfreq_release_work");
  return gpu_do_maxfreq_release();
}
