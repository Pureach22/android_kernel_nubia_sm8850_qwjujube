__int64 __fastcall populate_dot11f_probe_req_mlo_ie(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10)
{
  __int64 v10; // x8
  __int64 v11; // x19
  __int16 v12; // w11
  char v13; // w12
  int v14; // w8
  char v15; // w11
  char v16; // w9
  __int16 v17; // w12
  __int16 v18; // w8
  __int64 result; // x0
  __int64 v20; // x20
  int v21; // w10
  __int64 v22; // x9

  if ( !a10 )
    goto LABEL_10;
  v10 = *(_QWORD *)(a10 + 16);
  if ( !v10 || !*(_QWORD *)(v10 + 1360) )
    goto LABEL_10;
  v11 = a10 + 10874;
  v12 = *(_WORD *)(a10 + 10874);
  *(_WORD *)(a10 + 12969) = 2;
  v13 = *(_WORD *)(a10 + 12967);
  *(_BYTE *)(a10 + 12966) = 107;
  *(_WORD *)(a10 + 10874) = v12 & 0xFFF8 | 1;
  *(_WORD *)(a10 + 12967) = v13 & 8 | 0x11;
  *(_DWORD *)(a10 + 12962) = 16711687;
  if ( (*(_BYTE *)(v10 + 49) & 8) != 0 )
  {
    v20 = a10;
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Do not populate sta profile in MLO IE",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "populate_dot11f_probe_req_mlo_ie");
    a10 = v20;
    LOWORD(v14) = 0;
  }
  else
  {
    v14 = *(unsigned __int8 *)(*(_QWORD *)(a10 + 112) + 4368LL);
    if ( *(_BYTE *)(*(_QWORD *)(a10 + 112) + 4368LL) )
    {
      v15 = *(_BYTE *)(*(_QWORD *)(a10 + 112) + 4430LL);
      v16 = *(_BYTE *)(*(_QWORD *)(a10 + 112) + 4478LL);
      *(_WORD *)(a10 + 10902) = *(_WORD *)(a10 + 10902) & 0xFFE0
                              | *(_BYTE *)(*(_QWORD *)(a10 + 112) + 4382LL) & 0xF
                              | 0x10;
      *(_DWORD *)(a10 + 10898) = 33554436;
      if ( v14 != 1 )
      {
        v17 = *(_WORD *)(a10 + 11418);
        *(_DWORD *)(a10 + 11414) = 33554436;
        *(_WORD *)(a10 + 11418) = v17 & 0xFFE0 | v15 & 0xF | 0x10;
        if ( v14 != 2 )
        {
          *(_WORD *)(a10 + 11934) = *(_WORD *)(a10 + 11934) & 0xFFE0 | v16 & 0xF | 0x10;
          *(_DWORD *)(a10 + 11930) = 33554436;
          if ( v14 != 3 )
          {
            v18 = *(_WORD *)(a10 + 12450);
            *(_WORD *)(a10 + 12448) = 0;
            *(_WORD *)(a10 + 12450) = v18 & 0xFFF0;
            __break(0x5512u);
LABEL_10:
            qdf_trace_msg(
              0x35u,
              2u,
              "%s: Null value",
              a1,
              a2,
              a3,
              a4,
              a5,
              a6,
              a7,
              a8,
              "populate_dot11f_probe_req_mlo_ie");
            return 29;
          }
        }
      }
    }
  }
  v21 = *(_DWORD *)(a10 + 72);
  v22 = *(_QWORD *)(a10 + 112);
  result = 0;
  *(_WORD *)(v11 + 22) = v14;
  *(_BYTE *)(v22 + 4545) = v21 == 2;
  return result;
}
