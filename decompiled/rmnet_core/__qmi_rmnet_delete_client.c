__int64 __fastcall _qmi_rmnet_delete_client(__int64 a1, _QWORD *a2, unsigned int a3)
{
  _QWORD *v6; // x22
  __int64 v7; // x0

  if ( !(unsigned int)rtnl_is_locked(a1) && (_qmi_rmnet_delete_client___already_done & 1) == 0 )
  {
    _qmi_rmnet_delete_client___already_done = 1;
    _warn_printk("RTNL: assertion failed at %s (%d)\n", "../vendor/qcom/opensource/datarmnet/core/qmi_rmnet.c", 688);
    __break(0x800u);
  }
  v6 = a2 + 3;
  v7 = a2[a3 + 3];
  if ( v7 || (v7 = a2[a3 + 5]) != 0 )
  {
    if ( dfc_qmap )
      dfc_qmap_client_exit(v7);
    else
      dfc_qmi_client_exit(v7);
    v6[a3] = 0;
    a2[a3 + 5] = 0;
  }
  if ( a2[1] || a2 && (*v6 || a2[4]) || a2[2] || a2[5] || a2[6] )
    return 1;
  rmnet_reset_qmi_pt(a1);
  kfree(a2);
  return 0;
}
