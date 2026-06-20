__int64 __fastcall lim_process_sme_deauth_req(__int64 a1, __int64 a2)
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
  _BYTE v14[4]; // [xsp+Ch] [xbp-24h] BYREF
  __int64 v15; // [xsp+10h] [xbp-20h] BYREF
  __int64 v16; // [xsp+18h] [xbp-18h] BYREF
  int v17; // [xsp+20h] [xbp-10h]
  __int64 v18; // [xsp+28h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(const void **)(a2 + 8);
  v17 = 0;
  v15 = 0;
  v16 = 0;
  v14[0] = 0;
  qdf_mem_copy(&v15, v4, 0x14u);
  if ( pe_find_session_by_bssid(a1, (char *)&v15 + 5, v14) )
  {
    result = _lim_process_sme_deauth_req(a1, *(const void **)(a2 + 8));
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
      "lim_process_sme_deauth_req",
      BYTE5(v15),
      BYTE6(v15),
      HIBYTE(v15),
      BYTE2(v16));
    result = lim_send_sme_deauth_ntf(a1, (char *)&v16 + 3, 500, 4, 1, BYTE4(v15));
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
