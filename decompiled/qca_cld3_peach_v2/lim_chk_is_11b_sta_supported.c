__int64 __fastcall lim_chk_is_11b_sta_supported(
        __int64 a1,
        unsigned __int8 *a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        int a6)
{
  unsigned int v6; // w8
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 v16; // x4
  __int64 v17; // x5
  __int64 v18; // x6
  __int64 v19; // x7

  if ( a6 != 2 )
    return 1;
  v6 = 1;
  if ( !*(_BYTE *)(a4 + 3260) && (*(_BYTE *)(*(_QWORD *)(a1 + 8) + 3406LL) & 1) != 0 )
  {
    lim_send_assoc_rsp_mgmt_frame(a1, 18, 1, a2, a5, 0, a3, 0, a4 + 3756);
    if ( a2 )
    {
      v16 = *a2;
      v17 = a2[1];
      v18 = a2[2];
      v19 = a2[5];
    }
    else
    {
      v18 = 0;
      v16 = 0;
      v17 = 0;
      v19 = 0;
    }
    qdf_trace_msg(
      0x35u,
      3u,
      "%s: Rejecting Re/Assoc req from 11b STA: %02x:%02x:%02x:**:**:%02x",
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      "lim_chk_is_11b_sta_supported",
      v16,
      v17,
      v18,
      v19);
    return 0;
  }
  return v6;
}
