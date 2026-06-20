__int64 __fastcall wlansap_filter_ch_based_acs(
        __int64 a1,
        __int64 a2,
        _DWORD *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x8
  unsigned __int64 v12; // x9
  __int64 v13; // x8
  unsigned __int64 i; // x10
  __int64 v15; // x12
  unsigned __int64 v16; // x11
  _DWORD *v17; // x13
  int v18; // w12
  __int64 v19; // x15
  unsigned __int64 v20; // x14
  const char *v22; // x2

  if ( !a1 || !a2 || !a3 )
  {
    v22 = "%s: NULL parameters";
LABEL_21:
    qdf_trace_msg(0x39u, 2u, v22, a4, a5, a6, a7, a8, a9, a10, a11, "wlansap_filter_ch_based_acs");
    return 5;
  }
  v11 = *(_QWORD *)(a1 + 1544);
  if ( !*(_BYTE *)v11 )
  {
    qdf_trace_msg(
      0x39u,
      8u,
      "%s: acs not enabled, no filtering required",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "wlansap_filter_ch_based_acs");
    return 0;
  }
  if ( !*(_QWORD *)(v11 + 32) || !*(_BYTE *)(v11 + 40) )
  {
    v22 = "%s: Empty acs channel list";
    goto LABEL_21;
  }
  v12 = (unsigned int)*a3;
  if ( (_DWORD)v12 )
  {
    v13 = 0;
    for ( i = 0; i < v12; ++i )
    {
      v15 = *(_QWORD *)(a1 + 1544);
      v16 = *(unsigned __int8 *)(v15 + 40);
      if ( *(_BYTE *)(v15 + 40) )
      {
        v17 = *(_DWORD **)(v15 + 32);
        v18 = *(_DWORD *)(a2 + 4 * i);
        if ( *v17 == v18 )
          goto LABEL_9;
        v19 = 1;
        do
        {
          v20 = v19;
          if ( v16 == v19 )
            break;
        }
        while ( v17[v19++] != v18 );
        if ( v20 < v16 )
        {
LABEL_9:
          *(_DWORD *)(a2 + 4 * v13++) = v18;
          v12 = (unsigned int)*a3;
        }
      }
    }
  }
  else
  {
    LODWORD(v13) = 0;
  }
  *a3 = v13;
  return 0;
}
