__int64 __fastcall wlan_mlo_mgr_vdev_destroyed_notification(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 result; // x0

  _ReadStatusReg(SP_EL0);
  if ( *(_DWORD *)(a1 + 80) | *(unsigned __int16 *)(a1 + 84) )
  {
    qdf_trace_msg(
      0x8Fu,
      8u,
      "%s: MLD addr%02x:%02x:%02x:**:**:%02x",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "wlan_mlo_mgr_vdev_destroyed_notification",
      *(unsigned __int8 *)(a1 + 80),
      *(unsigned __int8 *)(a1 + 81),
      *(unsigned __int8 *)(a1 + 82),
      *(unsigned __int8 *)(a1 + 85));
    result = mlo_dev_ctx_deinit(a1);
  }
  else
  {
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
