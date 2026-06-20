__int64 __fastcall zte_power_supply_set_battery_charged(_DWORD *a1, __int64 a2)
{
  _DWORD *v2; // x8

  if ( (a1[278] & 0x80000000) != 0 )
    return 4294967274LL;
  if ( *(_DWORD *)(*(_QWORD *)a1 + 8LL) != 1 )
    return 4294967274LL;
  v2 = *(_DWORD **)(*(_QWORD *)a1 + 80LL);
  if ( !v2 )
    return 4294967274LL;
  if ( *(v2 - 1) != 1866051055 )
    __break(0x8228u);
  ((void (__fastcall *)(_DWORD *, __int64))v2)(a1, a2);
  return 0;
}
