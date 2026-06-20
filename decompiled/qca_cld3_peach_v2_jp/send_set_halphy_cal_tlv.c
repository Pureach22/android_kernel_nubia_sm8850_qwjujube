__int64 __fastcall send_set_halphy_cal_tlv(__int64 a1, unsigned __int8 *a2)
{
  unsigned int v4; // w21
  __int64 v5; // x0
  _DWORD *v6; // x21
  __int64 v7; // x19
  __int64 v8; // x1
  double (__fastcall *v9)(__int64, __int64); // x8
  double v10; // d0
  int v11; // w0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7

  v4 = 16;
  v5 = wmi_buf_alloc_fl(a1, 0x10u, "send_set_halphy_cal_tlv", 0x587Bu);
  if ( v5 )
  {
    v6 = *(_DWORD **)(v5 + 224);
    v7 = v5;
    *v6 = 64749580;
    v8 = *a2;
    v9 = *(double (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 728) + 3664LL);
    if ( *((_DWORD *)v9 - 1) != -2112860426 )
      __break(0x8228u);
    v10 = v9(a1, v8);
    v6[1] = v11;
    v6[2] = *((_DWORD *)a2 + 1);
    v6[3] = *((_DWORD *)a2 + 2);
    v4 = wmi_unified_cmd_send_fl(
           a1,
           v7,
           0x10u,
           0x4047u,
           "send_set_halphy_cal_tlv",
           0x588Bu,
           v10,
           v12,
           v13,
           v14,
           v15,
           v16,
           v17,
           v18);
    if ( v4 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: WMI_PDEV_SET_HALPHY_CAL_BMAP_CMDID send returned Error %d",
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        "send_set_halphy_cal_tlv",
        v4);
      wmi_buf_free();
    }
  }
  return v4;
}
