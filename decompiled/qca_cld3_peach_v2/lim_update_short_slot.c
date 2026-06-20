__int64 __fastcall lim_update_short_slot(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  _DWORD *v12; // x8
  unsigned int v13; // w19
  __int16 v16; // w8
  __int16 v17; // w8

  if ( *(_BYTE *)(*(_QWORD *)(a1 + 8) + 5604LL) == 1 )
  {
    v12 = (_DWORD *)(a4 + 7232);
    if ( !a4 )
      v12 = (_DWORD *)(a1 + 4840);
    if ( *v12 >= 2u )
    {
      v13 = (*(unsigned __int8 *)(a2 + 11) >> 2) & 1;
      if ( v13 != *(unsigned __int8 *)(a4 + 250) )
      {
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: Shortslot capability of AP changed: %d",
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          a11,
          a12,
          "lim_update_short_slot",
          v13);
        v16 = *(_WORD *)(a4 + 176);
        *(_BYTE *)(a4 + 250) = v13;
        *(_WORD *)(a4 + 176) = v16 & 0xFBFF | ((_WORD)v13 << 10);
        v17 = *(_WORD *)(a3 + 14);
        *(_BYTE *)(a3 + 2) = v13;
        *(_WORD *)(a3 + 14) = v17 | 4;
      }
    }
  }
  return 0;
}
