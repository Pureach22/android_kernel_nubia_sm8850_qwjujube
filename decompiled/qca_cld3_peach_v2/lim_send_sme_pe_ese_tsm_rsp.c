__int64 __fastcall lim_send_sme_pe_ese_tsm_rsp(__int64 a1, __int64 a2)
{
  __int64 session_by_bssid; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  char v13; // w8
  __int16 v14; // w2
  __int16 v15; // w8
  __int64 result; // x0
  _BYTE v17[4]; // [xsp+4h] [xbp-3Ch] BYREF
  __int64 v18; // [xsp+8h] [xbp-38h] BYREF
  __int64 v19; // [xsp+10h] [xbp-30h]
  __int64 v20; // [xsp+18h] [xbp-28h]
  __int64 v21; // [xsp+20h] [xbp-20h]
  __int64 v22; // [xsp+28h] [xbp-18h]
  __int64 v23; // [xsp+30h] [xbp-10h]
  __int64 v24; // [xsp+38h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v22 = 0;
  v23 = 0;
  v20 = 0;
  v21 = 0;
  v18 = 0;
  v19 = 0;
  v17[0] = 0;
  session_by_bssid = pe_find_session_by_bssid(a1, a2 + 12, v17);
  if ( session_by_bssid )
  {
    v13 = *(_BYTE *)(session_by_bssid + 10);
    *(_WORD *)a2 = 5201;
    v14 = v17[0];
    *(_BYTE *)(a2 + 4) = v13;
    *(_BYTE *)(a2 + 40) = *(_BYTE *)(session_by_bssid + 7050);
    v15 = *(_WORD *)(session_by_bssid + 7051);
    LOWORD(v18) = 5201;
    v19 = a2;
    *(_WORD *)(a2 + 42) = v15;
    HIDWORD(v18) = 0;
    qdf_trace(53, 6u, v14, 5201);
    result = sys_process_mmh_msg(a1, &v18);
  }
  else
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Session not found for the Sta peer:%02x:%02x:%02x:**:**:%02x",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "lim_send_sme_pe_ese_tsm_rsp",
      *(unsigned __int8 *)(a2 + 12),
      *(unsigned __int8 *)(a2 + 13),
      *(unsigned __int8 *)(a2 + 14),
      *(unsigned __int8 *)(a2 + 17));
    _qdf_mem_free(*(_QWORD *)(a2 + 48));
    result = _qdf_mem_free(a2);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
