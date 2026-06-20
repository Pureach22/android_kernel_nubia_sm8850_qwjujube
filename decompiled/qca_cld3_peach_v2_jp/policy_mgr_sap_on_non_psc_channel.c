__int64 __fastcall policy_mgr_sap_on_non_psc_channel(__int64 a1, _DWORD *a2, unsigned int a3)
{
  __int64 result; // x0
  __int64 v7; // x0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 v16; // x20
  int curr_6g_power_type; // w23
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  unsigned int *v34; // x8
  __int64 v35; // x21
  _DWORD s[129]; // [xsp+4h] [xbp-20Ch] BYREF
  __int64 v37; // [xsp+208h] [xbp-8h]

  v37 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, sizeof(s));
  result = wlan_reg_is_6ghz_chan_freq(*a2);
  if ( (result & 1) != 0 )
  {
    v7 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a3, 24);
    if ( v7 )
    {
      v16 = v7;
      curr_6g_power_type = wlan_mlme_get_curr_6g_power_type();
      qdf_mem_set(s, 0x204u, 0);
      if ( (unsigned int)policy_mgr_get_pcl_for_existing_conn(
                           a1,
                           1u,
                           (__int64)s,
                           &s[128],
                           (__int64)&s[102],
                           0x66u,
                           0,
                           a3,
                           v18,
                           v19,
                           v20,
                           v21,
                           v22,
                           v23,
                           v24,
                           v25) )
      {
        qdf_trace_msg(
          0x4Fu,
          2u,
          "%s: Unable to get PCL for SAP",
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          "policy_mgr_sap_on_non_psc_channel");
      }
      else if ( s[128] )
      {
        v35 = 0;
        while ( 1 )
        {
          if ( v35 == 102 )
            __break(0x5512u);
          if ( wlan_reg_is_6ghz_chan_freq(s[v35]) && s[v35] == *a2 && (curr_6g_power_type & 0xFFFFFFFE) == 2 )
            break;
          if ( ++v35 >= (unsigned __int64)s[128] )
            goto LABEL_14;
        }
        qdf_trace_msg(
          0x4Fu,
          8u,
          "%s: STA is in PSC channel %d in VLP/C2C mode, Hence SAP + STA allowed in PSC",
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          "policy_mgr_sap_on_non_psc_channel");
        *a2 = 0;
      }
      else
      {
LABEL_14:
        v34 = (unsigned int *)s[0];
        *a2 = s[0];
      }
      result = wlan_objmgr_vdev_release_ref(v16, 0x18u, v34, v26, v27, v28, v29, v30, v31, v32, v33);
    }
    else
    {
      result = qdf_trace_msg(
                 0x4Fu,
                 2u,
                 "%s: vdev %d is not present",
                 v8,
                 v9,
                 v10,
                 v11,
                 v12,
                 v13,
                 v14,
                 v15,
                 "policy_mgr_sap_on_non_psc_channel",
                 (unsigned __int8)a3);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
