__int64 __fastcall policy_mgr_get_sap_bw(__int64 a1, _DWORD *a2)
{
  __int64 v4; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x20
  double ap_oper_ch_width; // d0
  int v15; // w0
  unsigned int *v16; // x8
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 result; // x0
  int v25; // [xsp+8h] [xbp-28h] BYREF
  __int16 v26; // [xsp+Ch] [xbp-24h]
  _QWORD v27[4]; // [xsp+10h] [xbp-20h] BYREF

  v27[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v27, 0, 24);
  v26 = 0;
  v25 = 0;
  if ( (unsigned int)policy_mgr_get_mode_specific_conn_info(a1, v27, &v25, 1) == 1 && wlan_reg_is_6ghz_chan_freq(v27[0]) )
  {
    v4 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
           a1,
           (unsigned __int8)v25,
           24);
    if ( v4 )
    {
      v13 = v4;
      ap_oper_ch_width = wlan_mlme_get_ap_oper_ch_width();
      *a2 = v15;
      wlan_objmgr_vdev_release_ref(v13, 0x18u, v16, ap_oper_ch_width, v17, v18, v19, v20, v21, v22, v23);
      result = 0;
    }
    else
    {
      qdf_trace_msg(
        0x4Fu,
        2u,
        "%s: vdev %d is NULL",
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        "policy_mgr_get_sap_bw",
        (unsigned __int8)v25);
      result = 4;
    }
  }
  else
  {
    result = 11;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
