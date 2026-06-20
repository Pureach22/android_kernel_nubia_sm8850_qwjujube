__int64 __fastcall ucfg_green_ap_config(__int64 a1, char a2)
{
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  const char *v12; // x2
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 result; // x0
  _BYTE v22[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v23; // [xsp+8h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v22[0] = 0;
  if ( (unsigned int)wlan_green_ap_get_capab(a1) == 11 )
  {
    v12 = "%s: GreenAP not supported on radio\n";
LABEL_12:
    qdf_trace_msg(0x5Du, 2u, v12, v4, v5, v6, v7, v8, v9, v10, v11, "ucfg_green_ap_config");
    result = 11;
    goto LABEL_13;
  }
  if ( a2 )
  {
    wlan_objmgr_pdev_iterate_obj_list(
      a1,
      2,
      (void (__fastcall *)(__int64, __int64, __int64))wlan_green_ap_check_mode,
      (__int64)v22,
      0,
      0x27u);
    if ( v22[0] == 1 )
    {
      v12 = "%s: Radio not in AP/RE mode.Feature not supported";
      goto LABEL_12;
    }
    if ( !wlan_objmgr_pdev_get_comp_private_obj(a1, 0x16u) )
    {
      v12 = "%s: green ap context obtained is NULL";
      goto LABEL_12;
    }
    ucfg_green_ap_set_ps_config(a1, a2, v4, v5, v6, v7, v8, v9, v10, v11);
    if ( !(unsigned int)wlan_util_is_vdev_active(a1, 0x27u) )
      wlan_green_ap_start(a1, v13, v14, v15, v16, v17, v18, v19, v20);
  }
  else
  {
    wlan_green_ap_stop(a1, v4, v5, v6, v7, v8, v9, v10, v11);
  }
  result = 0;
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
