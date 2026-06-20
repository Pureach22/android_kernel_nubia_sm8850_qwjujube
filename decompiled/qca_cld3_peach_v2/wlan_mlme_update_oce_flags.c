__int64 __fastcall wlan_mlme_update_oce_flags(__int64 result)
{
  __int64 v1; // x21
  __int64 v2; // x19
  unsigned __int16 peer_count_for_mode; // w20
  unsigned __int16 v4; // w22
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  unsigned __int8 v13; // w8
  const char *v14; // x2
  _BYTE v15[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v16; // [xsp+8h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD *)(result + 80);
  if ( v1 )
  {
    v2 = result;
    peer_count_for_mode = wlan_util_get_peer_count_for_mode(result, 1u);
    v4 = wlan_util_get_peer_count_for_mode(v2, 3u);
    result = mlme_get_psoc_ext_obj_fl(v1);
    if ( result )
    {
      if ( peer_count_for_mode | v4 )
        v13 = *(_BYTE *)(result + 3668) & 0xF6;
      else
        v13 = *(_BYTE *)(result + 3668);
      if ( peer_count_for_mode | v4 )
        v14 = "%s: Disable STA OCE probe req rate and defferal updated_fw_value :%d";
      else
        v14 = "%s: Update the STA OCE flags to default INI updated_fw_value :%d";
      v15[0] = v13;
      qdf_trace_msg(0x1Fu, 8u, v14, v5, v6, v7, v8, v9, v10, v11, v12, "wlan_mlme_update_oce_flags", v13);
      result = wlan_objmgr_pdev_iterate_obj_list(
                 v2,
                 2,
                 (void (__fastcall *)(__int64, __int64, __int64))wlan_mlme_send_oce_flags_fw,
                 (__int64)v15,
                 0,
                 2u);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
