__int64 __fastcall lim_process_sme_disassoc_req(__int64 a1, __int64 a2)
{
  const void *v4; // x1
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 result; // x0
  _BYTE v14[4]; // [xsp+4h] [xbp-2Ch] BYREF
  int v15; // [xsp+8h] [xbp-28h] BYREF
  __int16 v16; // [xsp+Ch] [xbp-24h]
  _QWORD v17[4]; // [xsp+10h] [xbp-20h] BYREF

  v17[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(const void **)(a2 + 8);
  memset(v17, 0, 22);
  v14[0] = 0;
  v16 = 0;
  v15 = 0;
  qdf_mem_copy(v17, v4, 0x16u);
  if ( pe_find_session_by_bssid(a1, (char *)v17 + 5, v14) )
  {
    result = _lim_process_sme_disassoc_req(a1, *(const void **)(a2 + 8), v5, v6, v7, v8, v9, v10, v11, v12);
  }
  else
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: session not found for bssid:%02x:%02x:%02x:**:**:%02x",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "lim_process_sme_disassoc_req",
      BYTE5(v17[0]),
      BYTE6(v17[0]),
      HIBYTE(v17[0]),
      BYTE2(v17[1]));
    result = lim_send_sme_disassoc_ntf(a1, (char *)&v17[1] + 3, &v15, 500);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
