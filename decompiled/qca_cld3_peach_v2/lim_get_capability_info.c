__int64 __fastcall lim_get_capability_info(
        __int64 a1,
        __int16 *a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  int v13; // w8
  __int64 v14; // x21
  unsigned __int8 *v15; // x8
  int v16; // w9
  __int16 v17; // w8
  __int16 v18; // w9
  __int16 v19; // w8
  _BYTE *v20; // x9

  *a2 = 0;
  v13 = *(_DWORD *)(a3 + 88);
  if ( (unsigned int)(v13 - 1) < 2 )
  {
    *a2 = 1;
  }
  else if ( v13 == 3 || v13 == 6 )
  {
    *a2 = 0;
  }
  else
  {
    v14 = a3;
    qdf_trace_msg(
      0x35u,
      3u,
      "%s: can't get capability, role is UNKNOWN!!",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "lim_get_capability_info");
    a3 = v14;
  }
  if ( *(_DWORD *)(a3 + 88) == 1 )
    v15 = (unsigned __int8 *)(a3 + 1620);
  else
    v15 = (unsigned __int8 *)(*(_QWORD *)(a1 + 8) + 5652LL);
  v16 = *v15;
  v17 = *a2;
  if ( v16 )
  {
    v17 |= 0x10u;
    *a2 = v17;
  }
  if ( *(_BYTE *)(*(_QWORD *)(a1 + 8) + 1298LL) )
    v18 = v17 | 0x20;
  else
    v18 = v17;
  v19 = v18 & 0xFF3F;
  *a2 = v18 & 0xFF3F;
  if ( *(_BYTE *)(a3 + 154) != 3 )
  {
    if ( *(_DWORD *)(a3 + 88) == 1 || *(_BYTE *)(*(_QWORD *)(a1 + 8) + 5604LL) == 1 )
    {
      v19 = v18 & 0xFB3F | ((*(_BYTE *)(a3 + 250) & 1) << 10);
      *a2 = v19;
    }
    v20 = *(_BYTE **)(a1 + 8);
    if ( *(_DWORD *)(a3 + 7028) && v20[1061] == 1 )
    {
      v19 |= 0x100u;
      *a2 = v19;
      v20 = *(_BYTE **)(a1 + 8);
    }
    if ( v20[5668] == 1 )
    {
      v19 |= 0x200u;
      *a2 = v19;
      v20 = *(_BYTE **)(a1 + 8);
    }
    if ( v20[3636] == 1 )
    {
      v19 |= 0x800u;
      *a2 = v19;
    }
    *a2 = v19 & 0xEFFF | ((*(_BYTE *)(a1 + 17480) & 1) << 12);
    qdf_trace_msg(0x35u, 8u, "%s: RRM: %d", a4, a5, a6, a7, a8, a9, a10, a11, "lim_get_capability_info");
    *a2 = *a2 & 0x3FFF | (*(_WORD *)(*(_QWORD *)(a1 + 8) + 5616LL) << 14);
  }
  return 0;
}
