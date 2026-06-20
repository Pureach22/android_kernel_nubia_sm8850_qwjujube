__int64 dump_thread_func()
{
  __int64 v1; // x2
  unsigned int v2; // w8
  __int64 v3; // x0
  _QWORD v4[2]; // [xsp+0h] [xbp-10h] BYREF

  v4[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4[0] = 0;
  if ( (((__int64 (*)(void))kthread_should_stop)() & 1) == 0 )
  {
    do
    {
      v1 = boot_log_pos;
      v2 = boot_log_buf_left;
      while ( (kmsg_dump_get_line(&iter, 1, v1, v2, v4) & 1) != 0 )
      {
        v1 = boot_log_pos + v4[0];
        v2 = boot_log_buf_left - LODWORD(v4[0]);
        boot_log_pos += v4[0];
        boot_log_buf_left -= LODWORD(v4[0]);
        if ( !v4[0] )
          goto LABEL_2;
      }
      v3 = schedule_timeout_interruptible(250);
    }
    while ( (kthread_should_stop(v3) & 1) == 0 );
  }
LABEL_2:
  _ReadStatusReg(SP_EL0);
  return 0;
}
