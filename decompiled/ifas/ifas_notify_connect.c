void __fastcall ifas_notify_connect(int pid, int connectedAPI, unsigned __int64 id)
{
  int v4; // w2
  int v5; // w20

  v4 = connectedAPI;
  if ( ifas_log_enable )
  {
    v5 = pid;
    printk(&unk_F335, "ifas_notify_connect");
    pid = v5;
    v4 = connectedAPI;
  }
  perfmgr_notify_connect(pid, id, v4);
}
