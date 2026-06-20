__int64 __fastcall wlan_connectivity_mlo_reconfig_event(__int64 a1)
{
  unsigned __int64 time_of_the_day_us; // x8
  unsigned int v3; // w19
  __int64 result; // x0
  __int64 ap_link_by_link_id; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  unsigned __int16 *v14; // x8
  unsigned int v15; // w0
  char v16; // w8
  const char *v17; // x2
  __int64 v18; // [xsp+8h] [xbp-38h] BYREF
  unsigned __int64 v19; // [xsp+10h] [xbp-30h]
  __int64 v20; // [xsp+18h] [xbp-28h]
  __int64 v21; // [xsp+20h] [xbp-20h]
  __int64 v22; // [xsp+28h] [xbp-18h]
  __int64 v23; // [xsp+30h] [xbp-10h]
  __int64 v24; // [xsp+38h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v22 = 0;
  v23 = 0;
  v20 = 0;
  v18 = 0;
  v19 = 0;
  v21 = ktime_get(a1) / 1000;
  time_of_the_day_us = qdf_get_time_of_the_day_us();
  v3 = *(unsigned __int8 *)(a1 + 93);
  result = *(_QWORD *)(a1 + 1360);
  v19 = time_of_the_day_us;
  LODWORD(v22) = 1;
  BYTE5(v22) = v3;
  if ( !result )
    goto LABEL_11;
  ap_link_by_link_id = mlo_mgr_get_ap_link_by_link_id(result, v3);
  if ( !ap_link_by_link_id )
  {
    v17 = "%s: linl: %d Link info not found";
LABEL_10:
    result = qdf_trace_msg(
               0x68u,
               2u,
               v17,
               v6,
               v7,
               v8,
               v9,
               v10,
               v11,
               v12,
               v13,
               "wlan_connectivity_mlo_reconfig_event",
               v3);
    goto LABEL_11;
  }
  v14 = *(unsigned __int16 **)(ap_link_by_link_id + 32);
  if ( !v14 )
  {
    v17 = "%s: link: %d Chan info not found";
    goto LABEL_10;
  }
  v15 = wlan_reg_freq_to_band(*v14);
  if ( v15 < 3 )
    v16 = v15 + 1;
  else
    v16 = 0;
  BYTE4(v22) = v16;
  result = host_diag_event_report_payload(3416, 48, &v18);
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
