__int64 __fastcall rmnet_ctl_unregister_client(__int64 a1)
{
  __int64 v3; // x0

  raw_spin_lock(&client_lock);
  if ( qword_6B08 == a1 )
  {
    qword_6B08 = 0;
    v3 = raw_spin_unlock(&client_lock);
    synchronize_rcu(v3);
    kfree(a1);
    debugfs_remove(qword_6B10);
    ipc_log_context_destroy(qword_6B20);
    qword_6B10 = 0;
    qword_6B18 = 0;
    qword_6B20 = 0;
    return 0;
  }
  else
  {
    raw_spin_unlock(&client_lock);
    return 4294967274LL;
  }
}
