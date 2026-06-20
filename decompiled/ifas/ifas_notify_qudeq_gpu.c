void __fastcall ifas_notify_qudeq_gpu(int qudeq, unsigned int startend, int pid, unsigned __int64 id)
{
  unsigned int v4; // w19
  int v5; // w20
  unsigned __int64 v6; // x21

  if ( qudeq == 1 )
  {
    if ( ifas_log_enable )
    {
      v4 = startend;
      v5 = pid;
      v6 = id;
      printk(&unk_10762, "ifas_notify_qudeq_gpu");
      startend = v4;
      pid = v5;
      id = v6;
    }
    perfmgr_notify_qudeq_gpu(startend, pid, id);
  }
}
