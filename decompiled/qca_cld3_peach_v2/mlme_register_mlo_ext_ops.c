__int64 mlme_register_mlo_ext_ops()
{
  __int64 mlo_ctx; // x0
  __int64 result; // x0
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  unsigned int v10; // w19

  mlo_ctx = wlan_objmgr_get_mlo_ctx();
  if ( !mlo_ctx )
    return 16;
  mlo_reg_mlme_ext_cb(mlo_ctx, &mlo_ext_ops);
  result = mlo_mgr_register_link_switch_notifier(0, wlan_cm_link_switch_notif_cb);
  if ( (_DWORD)result )
  {
    if ( (_DWORD)result == 11 )
    {
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: Link switch not supported",
        v2,
        v3,
        v4,
        v5,
        v6,
        v7,
        v8,
        v9,
        "mlme_register_mlo_ext_ops");
      return 0;
    }
    else
    {
      v10 = result;
      qdf_trace_msg(
        0x68u,
        2u,
        "%s: Failed to register link switch notifier for mlme!",
        v2,
        v3,
        v4,
        v5,
        v6,
        v7,
        v8,
        v9,
        "mlme_register_mlo_ext_ops");
      return v10;
    }
  }
  return result;
}
