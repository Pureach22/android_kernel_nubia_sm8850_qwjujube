__int64 __fastcall ucfg_wlan_ftm_testmode_cmd(__int64 a1)
{
  __int64 comp_private_obj; // x0

  comp_private_obj = wlan_objmgr_pdev_get_comp_private_obj(a1, 0x17u);
  if ( !comp_private_obj )
    return 16;
  *(_QWORD *)(comp_private_obj + 24) = 0;
  return wlan_ftm_cmd_send(a1);
}
