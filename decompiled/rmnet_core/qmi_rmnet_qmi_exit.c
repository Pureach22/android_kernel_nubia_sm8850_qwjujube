__int64 __fastcall qmi_rmnet_qmi_exit(__int64 result, __int64 a2)
{
  __int64 v2; // x19
  __int64 v4; // x21
  __int64 v5; // x0

  if ( result )
  {
    v2 = result;
    if ( !(unsigned int)rtnl_is_locked(result) && (qmi_rmnet_qmi_exit___already_done & 1) == 0 )
    {
      qmi_rmnet_qmi_exit___already_done = 1;
      _warn_printk("RTNL: assertion failed at %s (%d)\n", "../vendor/qcom/opensource/datarmnet/core/qmi_rmnet.c", 850);
      __break(0x800u);
    }
    v4 = *(_QWORD *)(v2 + 8);
    if ( !v4 )
      v4 = *(_QWORD *)(v2 + 16);
    wda_qmi_client_release(v4);
    v5 = qmi_rmnet_work_exit(a2);
    rmnet_ll_wq_exit(v5);
    if ( v4 )
    {
      wda_qmi_client_exit(v4);
      *(_QWORD *)(v2 + 8) = 0;
      *(_QWORD *)(v2 + 16) = 0;
    }
    result = _qmi_rmnet_delete_client(a2, v2, 0);
    if ( (_DWORD)result )
      return _qmi_rmnet_delete_client(a2, v2, 1);
  }
  return result;
}
