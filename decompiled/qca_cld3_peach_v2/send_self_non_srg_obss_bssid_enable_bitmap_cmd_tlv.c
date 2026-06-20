__int64 __fastcall send_self_non_srg_obss_bssid_enable_bitmap_cmd_tlv(__int64 a1, int a2, int a3, unsigned __int8 a4)
{
  unsigned int v8; // w22
  __int64 v9; // x0
  _DWORD *v10; // x22
  __int64 v11; // x19
  _DWORD *v12; // x8
  double v13; // d0
  int v14; // w0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7

  v8 = 16;
  v9 = wmi_buf_alloc_fl(a1, 0x10u, "send_self_non_srg_obss_bssid_enable_bitmap_cmd_tlv", 0x3455u);
  if ( v9 )
  {
    v10 = *(_DWORD **)(v9 + 224);
    v11 = v9;
    *v10 = 58982412;
    v12 = *(_DWORD **)(*(_QWORD *)(a1 + 728) + 3680LL);
    if ( *(v12 - 1) != -2112860426 )
      __break(0x8228u);
    v13 = ((double (__fastcall *)(__int64, _QWORD))v12)(a1, a4);
    v10[1] = v14;
    v10[2] = a2;
    v10[3] = a3;
    v8 = wmi_unified_cmd_send_fl(
           a1,
           v11,
           0x10u,
           0x4040u,
           "send_self_non_srg_obss_bssid_enable_bitmap_cmd_tlv",
           0x3469u,
           v13,
           v15,
           v16,
           v17,
           v18,
           v19,
           v20,
           v21);
    if ( v8 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: WMI_PDEV_SET_NON_SRG_OBSS_BSSID_ENABLE_BITMAP_CMDID send returned Error %d",
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        "send_self_non_srg_obss_bssid_enable_bitmap_cmd_tlv",
        v8);
      wmi_buf_free();
    }
  }
  return v8;
}
