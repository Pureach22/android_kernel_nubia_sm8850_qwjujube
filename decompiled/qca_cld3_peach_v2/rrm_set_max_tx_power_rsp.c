__int64 __fastcall rrm_set_max_tx_power_rsp(
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
  __int64 v12; // x20
  __int64 session_by_bssid; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned int v23; // w22
  __int64 v24; // x21
  unsigned int v25; // w20
  unsigned __int8 v26; // w24
  __int64 v27; // x28
  char v28; // w25
  unsigned __int8 v30[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v31; // [xsp+8h] [xbp-8h]

  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *(_QWORD *)(a2 + 8);
  v30[0] = 0;
  if ( *(_DWORD *)v12 == -1 && *(__int16 *)(v12 + 4) == -1 )
  {
    if ( *(_WORD *)(a1 + 3992) )
    {
      v26 = 0;
      do
      {
        v27 = *(_QWORD *)(a1 + 12264) + 14000LL * v26;
        if ( *(_BYTE *)(v27 + 70) == 1 )
        {
          v28 = *(_BYTE *)(v12 + 12);
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: Cache Mgmt Tx Power: %d",
            a3,
            a4,
            a5,
            a6,
            a7,
            a8,
            a9,
            a10,
            "rrm_cache_mgmt_tx_power");
          if ( v27 )
            *(_BYTE *)(v27 + 7040) = v28;
          else
            *(_BYTE *)(a1 + 20225) = v28;
        }
        ++v26;
      }
      while ( *(unsigned __int16 *)(a1 + 3992) > (unsigned int)v26 );
    }
    v25 = 0;
  }
  else
  {
    session_by_bssid = pe_find_session_by_bssid(a1, (unsigned __int8 *)v12, v30);
    if ( session_by_bssid )
    {
      v23 = *(char *)(v12 + 12);
      v24 = session_by_bssid;
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: Cache Mgmt Tx Power: %d",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "rrm_cache_mgmt_tx_power",
        v23);
      v25 = 0;
      *(_BYTE *)(v24 + 7040) = v23;
    }
    else
    {
      v25 = 16;
    }
  }
  _qdf_mem_free(*(_QWORD *)(a2 + 8));
  *(_QWORD *)(a2 + 8) = 0;
  _ReadStatusReg(SP_EL0);
  return v25;
}
