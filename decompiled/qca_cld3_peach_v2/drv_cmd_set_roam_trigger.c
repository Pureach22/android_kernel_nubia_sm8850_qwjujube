__int64 __fastcall drv_cmd_set_roam_trigger(__int64 a1, __int64 a2, __int64 a3, unsigned __int8 a4)
{
  unsigned int v6; // w0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  unsigned int v15; // w21
  unsigned int v16; // w22
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 result; // x0
  _BYTE v34[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v35; // [xsp+8h] [xbp-8h]

  v35 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v34[0] = 0;
  v6 = kstrtos8(a3 + a4 + 1, 10, v34);
  if ( (v6 & 0x80000000) != 0 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: kstrtou8 failed Input value may be out of range[%d - %d]",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "drv_cmd_set_roam_trigger",
      4294967196LL,
      4294967246LL);
    result = 4294967274LL;
  }
  else if ( (unsigned __int8)(v34[0] + 100) >= 0x33u )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Neighbor lookup threshold value %d is out of range (Min: %d Max: %d)",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "drv_cmd_set_roam_trigger",
      180,
      4294967196LL,
      4294967246LL);
    result = 4294967274LL;
  }
  else
  {
    v15 = -v34[0];
    v16 = v6;
    qdf_mtrace(51, 51, 5u, *(_BYTE *)(a1 + 8), (unsigned __int8)-v34[0]);
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Set Roam trigger: Neighbor lookup threshold = %d",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "drv_cmd_set_roam_trigger",
      (unsigned __int8)v15);
    if ( (unsigned int)sme_set_neighbor_lookup_rssi_threshold(*(_QWORD *)(a2 + 16), *(unsigned __int8 *)(a1 + 8), v15) )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Failed to set roam trigger, try again",
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        "drv_cmd_set_roam_trigger");
      result = 0xFFFFFFFFLL;
    }
    else
    {
      result = v16;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
