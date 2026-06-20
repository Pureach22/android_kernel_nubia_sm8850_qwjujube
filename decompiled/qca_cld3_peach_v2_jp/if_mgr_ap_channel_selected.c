__int64 __fastcall if_mgr_ap_channel_selected(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8
  __int64 v11; // x19
  int v13; // w21
  int mode_specific_conn_info; // w22
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 result; // x0
  __int64 v24; // [xsp+0h] [xbp-20h] BYREF
  __int64 v25; // [xsp+8h] [xbp-18h]
  int v26; // [xsp+10h] [xbp-10h]
  __int64 v27; // [xsp+18h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)(a1 + 152);
  v26 = 0;
  v24 = 0;
  v25 = 0;
  if ( !v10 || (v11 = *(_QWORD *)(v10 + 80)) == 0 )
  {
    qdf_trace_msg(0x78u, 8u, "%s: PSOC NULL", a3, a4, a5, a6, a7, a8, a9, a10, "if_mgr_ap_channel_selected", v24);
    result = 16;
    goto LABEL_21;
  }
  v13 = *(_DWORD *)(a2 + 32);
  mode_specific_conn_info = (unsigned __int8)policy_mgr_get_mode_specific_conn_info(*(_QWORD *)(v10 + 80), &v24, 0, 0);
  if ( mode_specific_conn_info )
  {
    if ( (_DWORD)v24 != v13 && (policy_mgr_are_2_freq_on_same_mac(v11) & 1) != 0 )
      goto LABEL_18;
    if ( mode_specific_conn_info == 1 )
      goto LABEL_19;
    if ( HIDWORD(v24) != v13 && (policy_mgr_are_2_freq_on_same_mac(v11) & 1) != 0 )
      goto LABEL_18;
    if ( mode_specific_conn_info == 2 )
      goto LABEL_19;
    if ( (_DWORD)v25 != v13 && (policy_mgr_are_2_freq_on_same_mac(v11) & 1) != 0 )
      goto LABEL_18;
    if ( mode_specific_conn_info == 3 )
      goto LABEL_19;
    if ( HIDWORD(v25) != v13 && (policy_mgr_are_2_freq_on_same_mac(v11) & 1) != 0 )
    {
LABEL_18:
      qdf_trace_msg(
        0x78u,
        8u,
        "%s: STA and SAP are in MCC, teardown TDLS",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "if_mgr_ap_channel_selected",
        v24);
      wlan_tdls_check_and_teardown_links_sync(v11, a1);
      goto LABEL_19;
    }
    if ( mode_specific_conn_info != 4 )
    {
      if ( v26 == v13 || (policy_mgr_are_2_freq_on_same_mac(v11) & 1) == 0 )
      {
        if ( mode_specific_conn_info != 5 )
          __break(0x5512u);
        goto LABEL_19;
      }
      goto LABEL_18;
    }
  }
LABEL_19:
  result = 0;
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return result;
}
