__int64 __fastcall pe_find_session_by_peer_sta(
        __int64 a1,
        unsigned __int8 *a2,
        unsigned __int8 *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  int v12; // w8
  unsigned __int8 i; // w22
  __int64 v16; // x9
  __int64 v17; // x4
  __int64 v18; // x5
  __int64 v19; // x6
  __int64 v20; // x7
  __int64 result; // x0
  __int16 v22; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v23; // [xsp+8h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *(unsigned __int16 *)(a1 + 3992);
  v22 = 0;
  if ( v12 )
  {
    for ( i = 0; (unsigned __int16)v12 > (unsigned int)i; ++i )
    {
      v16 = *(_QWORD *)(a1 + 12264) + 10792LL * i;
      if ( *(_BYTE *)(v16 + 70) )
      {
        if ( dph_lookup_hash_entry(a4, a5, a6, a7, a8, a9, a10, a11, a1, a2, &v22, v16 + 360) )
        {
          *a3 = i;
          result = *(_QWORD *)(a1 + 12264) + 10792LL * i;
          goto LABEL_12;
        }
        LOWORD(v12) = *(_WORD *)(a1 + 3992);
      }
    }
  }
  if ( a2 )
  {
    v17 = *a2;
    v18 = a2[1];
    v19 = a2[2];
    v20 = a2[5];
  }
  else
  {
    v19 = 0;
    v17 = 0;
    v18 = 0;
    v20 = 0;
  }
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: Session lookup fails for Peer: %02x:%02x:%02x:**:**:%02x",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "pe_find_session_by_peer_sta",
    v17,
    v18,
    v19,
    v20);
  result = 0;
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
