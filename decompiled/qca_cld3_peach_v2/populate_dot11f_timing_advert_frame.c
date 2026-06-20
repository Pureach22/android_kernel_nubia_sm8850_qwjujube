__int64 __fastcall populate_dot11f_timing_advert_frame(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  __int16 v5; // w9
  char v7; // w8

  v2 = *(_QWORD *)(a1 + 8);
  if ( *(_BYTE *)(v2 + 5652) == 1 )
  {
    *(_WORD *)(a2 + 8) |= 0x10u;
    v2 = *(_QWORD *)(a1 + 8);
  }
  if ( *(_BYTE *)(v2 + 1298) == 1 )
  {
    *(_WORD *)(a2 + 8) |= 0x20u;
    v2 = *(_QWORD *)(a1 + 8);
  }
  if ( *(_BYTE *)(v2 + 1061) == 1 )
  {
    *(_WORD *)(a2 + 8) |= 0x100u;
    v2 = *(_QWORD *)(a1 + 8);
  }
  if ( *(_BYTE *)(v2 + 5668) == 1 )
  {
    *(_WORD *)(a2 + 8) |= 0x200u;
    v2 = *(_QWORD *)(a1 + 8);
  }
  v5 = *(_WORD *)(a2 + 8);
  if ( *(_BYTE *)(v2 + 3636) == 1 )
  {
    v5 |= 0x800u;
    *(_WORD *)(a2 + 8) = v5;
    v2 = *(_QWORD *)(a1 + 8);
  }
  *(_WORD *)(a2 + 8) = v5 & 0x3FFF | (*(_WORD *)(v2 + 5616) << 14);
  populate_dot11f_country(a1, a2 + 10, 0);
  v7 = *(_BYTE *)(*(_QWORD *)(a1 + 8) + 4627LL);
  *(_BYTE *)(a2 + 258) = 1;
  *(_BYTE *)(a2 + 259) = v7;
  *(_WORD *)(a2 + 260) = 257;
  return 0;
}
