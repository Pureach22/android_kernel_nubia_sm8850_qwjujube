__int64 __fastcall cvp_msgq_deinit(__int64 a1)
{
  if ( *(_QWORD *)(a1 + 88) )
    kthread_stop();
  return 0;
}
