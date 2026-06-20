__int64 __fastcall rt_bus_hint_store(__int64 a1, unsigned int a2)
{
  int v2; // w2

  if ( (*(_BYTE *)(*(_QWORD *)(a1 + 14264) + 34LL) & 0x80) != 0 && *(_DWORD *)(a1 + 10940) != a2 )
  {
    if ( *(_DWORD *)(a1 + 9156) >= a2 )
      v2 = a2;
    else
      v2 = 0;
    adreno_power_cycle_u32(a1, (_DWORD *)(a1 + 10940), v2);
  }
  return 0;
}
