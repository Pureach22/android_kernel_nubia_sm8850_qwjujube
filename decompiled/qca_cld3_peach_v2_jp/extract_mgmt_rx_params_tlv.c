__int64 __fastcall extract_mgmt_rx_params_tlv(
        __int64 a1,
        _DWORD *a2,
        __int64 a3,
        _QWORD *a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  _DWORD *v12; // x19
  int v13; // w8
  __int64 v14; // x21
  __int64 v15; // x22
  _DWORD *v16; // x23
  __int64 v17; // x24
  _QWORD *v18; // x25
  __int64 v19; // x20
  __int64 v20; // x20
  __int64 v21; // x20
  __int64 v22; // x20
  _DWORD *v24; // x20
  _QWORD *v25; // x21
  __int64 v26; // x22
  __int64 (*v27)(void); // x9

  if ( !a2 )
  {
    v20 = jiffies;
    if ( extract_mgmt_rx_params_tlv___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Get NULL point message from FW",
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        "extract_mgmt_rx_params_tlv");
      extract_mgmt_rx_params_tlv___last_ticks = v20;
    }
    return 4;
  }
  if ( !a3 )
  {
    v21 = jiffies;
    if ( extract_mgmt_rx_params_tlv___last_ticks_292 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(0x31u, 2u, "%s: Rx event is NULL", a5, a6, a7, a8, a9, a10, a11, a12, "extract_mgmt_rx_params_tlv");
      extract_mgmt_rx_params_tlv___last_ticks_292 = v21;
    }
    return 4;
  }
  v12 = *(_DWORD **)a2;
  v13 = *(_DWORD *)(*(_QWORD *)a2 + 24LL);
  if ( (v13 & 8) != 0 )
  {
    v22 = jiffies;
    if ( extract_mgmt_rx_params_tlv___last_ticks_294 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: RX mgmt frame decrypt error, discard it",
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        "extract_mgmt_rx_params_tlv");
      extract_mgmt_rx_params_tlv___last_ticks_294 = v22;
    }
    return 4;
  }
  if ( (v13 & 0x10) != 0 )
  {
    v14 = jiffies;
    if ( extract_mgmt_rx_params_tlv___last_ticks_296 - jiffies + 125 < 0 )
    {
      v15 = a1;
      v16 = a2;
      v17 = a3;
      v18 = a4;
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: RX mgmt frame MIC mismatch for beacon protected frame",
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        "extract_mgmt_rx_params_tlv");
      a1 = v15;
      a3 = v17;
      a2 = v16;
      a4 = v18;
      extract_mgmt_rx_params_tlv___last_ticks_296 = v14;
    }
  }
  if ( v12[5] > a2[6] )
  {
    v19 = jiffies;
    if ( extract_mgmt_rx_params_tlv___last_ticks_298 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Rx mgmt frame length mismatch, discard it",
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        "extract_mgmt_rx_params_tlv");
      extract_mgmt_rx_params_tlv___last_ticks_298 = v19;
    }
    return 4;
  }
  v24 = a2;
  v25 = a4;
  v26 = a3;
  v27 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 728) + 3672LL);
  if ( *((_DWORD *)v27 - 1) != -2112860426 )
    __break(0x8229u);
  *(_BYTE *)(a3 + 48) = v27();
  *(_DWORD *)v26 = v12[17];
  *(_DWORD *)(v26 + 4) = v12[1];
  *(_DWORD *)(v26 + 8) = v12[2];
  *(_DWORD *)(v26 + 16) = v12[3];
  *(_DWORD *)(v26 + 20) = v12[4];
  *(_DWORD *)(v26 + 24) = v12[5];
  *(_BYTE *)(v26 + 28) = v12[6];
  *(_DWORD *)(v26 + 32) = v12[11];
  *(_DWORD *)(v26 + 36) = v12[12];
  *(_DWORD *)(v26 + 40) = v12[13];
  *(_DWORD *)(v26 + 44) = v12[14];
  *(_BYTE *)(v26 + 12) = v12[7];
  *(_BYTE *)(v26 + 13) = v12[8];
  *(_BYTE *)(v26 + 14) = v12[9];
  *(_BYTE *)(v26 + 15) = v12[10];
  *v25 = *((_QWORD *)v24 + 2);
  return 0;
}
