void __fastcall ifas_notify_qudeq(int qudeq, unsigned int startend, int pid, unsigned __int64 id)
{
  int v4; // w19
  unsigned __int64 v5; // x20

  if ( qudeq == 1 && !startend )
  {
    if ( ifas_log_enable )
    {
      v4 = pid;
      v5 = id;
      printk(&unk_EA66, "ifas_notify_qudeq");
      pid = v4;
      id = v5;
    }
    perfmgr_notify_qudeq(pid, id);
  }
}
