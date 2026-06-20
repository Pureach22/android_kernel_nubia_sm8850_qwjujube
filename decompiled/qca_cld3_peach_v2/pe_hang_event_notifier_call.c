__int64 __fastcall pe_hang_event_notifier_call(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x8
  unsigned __int16 v4; // w12
  unsigned __int8 i; // w9
  __int64 v6; // x13
  __int64 v7; // x12
  __int64 v8; // x12

  if ( !a3 )
    return 0x8000;
  v3 = *(_QWORD *)(a1 + 24);
  if ( !v3 )
    return 0x8000;
  v4 = *(_WORD *)(v3 + 3992);
  if ( v4 )
  {
    for ( i = 0; v4 > (unsigned int)i; ++i )
    {
      v6 = *(_QWORD *)(v3 + 12264) + 14000LL * i;
      if ( *(_BYTE *)(v6 + 70) )
      {
        v7 = *(unsigned int *)(a3 + 8);
        if ( (unsigned int)v7 > 0xBC )
          return 0x8000;
        v8 = *(_QWORD *)a3 + v7;
        *(_WORD *)v8 = 773;
        *(_BYTE *)(v8 + 2) = *(_BYTE *)(v6 + 10);
        *(_BYTE *)(v8 + 3) = *(_DWORD *)(v6 + 72);
        *(_BYTE *)(v8 + 4) = *(_DWORD *)(v6 + 76);
        *(_BYTE *)(v8 + 5) = *(_DWORD *)(v6 + 80);
        *(_BYTE *)(v8 + 6) = *(_DWORD *)(v6 + 84);
        *(_DWORD *)(a3 + 8) += 7;
        v4 = *(_WORD *)(v3 + 3992);
      }
    }
  }
  return 1;
}
