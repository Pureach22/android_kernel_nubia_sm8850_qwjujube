__int64 __fastcall do_maxfreq_release_work(__int64 a1)
{
  if ( ifas_log_enable )
    a1 = printk(&unk_EDD7, "do_maxfreq_release_work");
  return do_maxfreq_release(a1);
}
