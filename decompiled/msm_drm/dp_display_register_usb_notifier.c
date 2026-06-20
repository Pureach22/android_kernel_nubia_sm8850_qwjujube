__int64 __fastcall dp_display_register_usb_notifier(__int64 a1)
{
  unsigned __int64 phy_by_phandle; // x0
  __int64 result; // x0
  int v4; // w19
  __int64 v5; // x0
  unsigned __int64 StatusReg; // x20
  __int64 v7; // x0
  unsigned __int64 v8; // x19

  phy_by_phandle = devm_usb_get_phy_by_phandle(*(_QWORD *)(a1 + 24) + 16LL, "usb-phy", 0);
  if ( phy_by_phandle && phy_by_phandle < 0xFFFFFFFFFFFFF001LL )
  {
    *(_QWORD *)(a1 + 4464) = dp_display_usb_notifier;
    *(_DWORD *)(a1 + 4480) = 2;
    result = atomic_notifier_chain_register(phy_by_phandle + 224, a1 + 4464);
    if ( (_DWORD)result )
    {
      v4 = result;
      if ( !g_dp_display || (v5 = *(_QWORD *)(g_dp_display + 56)) == 0 )
        v5 = 0;
      StatusReg = _ReadStatusReg(SP_EL0);
      result = ipc_log_string(v5, "[d][%-4d]failed to register for usb event: %d\n", *(_DWORD *)(StatusReg + 1800), v4);
      if ( (_drm_debug & 4) != 0 )
        return _drm_dev_dbg(
                 0,
                 0,
                 0,
                 "[msm-dp-debug][%-4d]failed to register for usb event: %d\n",
                 *(_DWORD *)(StatusReg + 1800),
                 v4);
    }
  }
  else
  {
    if ( !g_dp_display || (v7 = *(_QWORD *)(g_dp_display + 56)) == 0 )
      v7 = 0;
    v8 = _ReadStatusReg(SP_EL0);
    result = ipc_log_string(v7, "[d][%-4d]unable to get usbphy\n", *(_DWORD *)(v8 + 1800));
    if ( (_drm_debug & 4) != 0 )
      return _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]unable to get usbphy\n", *(_DWORD *)(v8 + 1800));
  }
  return result;
}
