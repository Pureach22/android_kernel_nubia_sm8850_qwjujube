// Alternative name is 'init_module'
int __cdecl ifas_init()
{
  __int64 v0; // x0
  int v1; // w19

  v0 = proc_mkdir("perfmgr", 0);
  if ( proc_create("perf_ioctl", 436, v0, &Fops) )
  {
    qbuffer_notifyworkqueue = alloc_workqueue("%s", (const char *)0x2001A);
    if ( qbuffer_notifyworkqueue )
    {
      _mutex_init(&notify_lock, "&notify_lock", &ifas_init___key);
      _mutex_init(&list_lock, "&list_lock", &ifas_init___key_34);
      connected_buffer_list = (__int64)&connected_buffer_list;
      qword_D410 = (__int64)&connected_buffer_list;
      perfmgr_policy_init();
      if ( ifas_log_enable )
        printk(&unk_10079, "ifas_init");
      return 0;
    }
    else
    {
      return -14;
    }
  }
  else
  {
    v1 = -12;
    printk(&unk_EAA1, "Creating file node ");
  }
  return v1;
}
