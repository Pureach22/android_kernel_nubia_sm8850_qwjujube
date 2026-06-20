__int64 __fastcall qmi_rmnet_work_exit(__int64 result)
{
  __int64 v1; // x19
  __int64 qmi_pt; // x0
  unsigned __int64 v9; // x10

  if ( rmnet_ps_wq && rmnet_work )
  {
    rmnet_work_quit = 1;
    v1 = result;
    qmi_info_ptr = 0;
    synchronize_rcu(result);
    rmnet_work_inited = 0;
    cancel_delayed_work_sync(rmnet_work);
    destroy_workqueue(rmnet_ps_wq);
    qmi_pt = rmnet_get_qmi_pt(v1);
    if ( qmi_pt )
    {
      _X8 = (unsigned __int64 *)(qmi_pt + 64);
      __asm { PRFM            #0x11, [X8] }
      do
        v9 = __ldxr(_X8);
      while ( __stxr(v9 & 0xFFFFFFFFFFFFFFFELL, _X8) );
    }
    rmnet_ps_wq = 0;
    result = kfree(rmnet_work);
    rmnet_work = 0;
  }
  return result;
}
