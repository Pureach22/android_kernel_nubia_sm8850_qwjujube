__int64 __fastcall extract_twt_ack_comp_event_tlv(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 *a10,
        __int64 a11)
{
  __int64 v11; // x29
  __int64 v12; // x30
  __int64 v13; // x8
  unsigned int v14; // w9
  int v15; // w9
  __int64 result; // x0
  int v17; // w9
  __int64 v18; // x8
  _DWORD *v19; // x9
  int v20; // w8

  if ( !a10 )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: evt_buf is NULL",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "extract_twt_ack_comp_event_tlv",
      v11,
      v12);
    return 4;
  }
  v13 = *a10;
  *(_DWORD *)a11 = *(_DWORD *)(*a10 + 4);
  *(_WORD *)(a11 + 4) = *(_DWORD *)(v13 + 8);
  *(_BYTE *)(a11 + 6) = *(_WORD *)(v13 + 10);
  *(_BYTE *)(a11 + 7) = *(_BYTE *)(v13 + 11);
  *(_WORD *)(a11 + 8) = *(_DWORD *)(v13 + 12);
  *(_DWORD *)(a11 + 12) = *(_DWORD *)(v13 + 16);
  v14 = *(_DWORD *)(v13 + 20) - 253955;
  if ( v14 > 6 )
    v15 = 5;
  else
    v15 = dword_A2DEB8[v14];
  *(_DWORD *)(a11 + 16) = v15;
  result = 0;
  v17 = *(_DWORD *)(v13 + 20);
  if ( v17 <= 253956 )
  {
    if ( v17 == 253955 )
    {
      v18 = *(unsigned int *)(v13 + 24);
      if ( (unsigned int)v18 > 0x13 )
      {
        v20 = 9;
        goto LABEL_22;
      }
      v19 = dword_A2DED4;
      goto LABEL_21;
    }
    if ( v17 != 253956 )
      return result;
    v18 = *(unsigned int *)(v13 + 24);
    if ( (unsigned int)v18 <= 0x11 )
    {
      v19 = dword_A2DF24;
      goto LABEL_21;
    }
  }
  else
  {
    if ( v17 != 253957 )
    {
      if ( v17 == 253958 )
      {
        v18 = *(unsigned int *)(v13 + 24);
        if ( (unsigned int)v18 > 0xB )
        {
          v20 = 7;
          goto LABEL_22;
        }
        v19 = dword_A2DF6C;
        goto LABEL_21;
      }
      if ( v17 != 253961 )
        return result;
    }
    v18 = *(unsigned int *)(v13 + 24);
    if ( (unsigned int)v18 <= 0xB )
    {
      v19 = dword_A2DF9C;
LABEL_21:
      v20 = v19[v18];
      goto LABEL_22;
    }
  }
  v20 = 6;
LABEL_22:
  result = 0;
  *(_DWORD *)(a11 + 20) = v20;
  return result;
}
