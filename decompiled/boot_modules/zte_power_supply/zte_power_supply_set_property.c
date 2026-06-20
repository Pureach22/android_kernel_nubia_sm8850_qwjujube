__int64 __fastcall zte_power_supply_set_property(int *a1, __int64 a2)
{
  __int64 (__fastcall *v2)(int *, __int64); // x8

  if ( a1[278] < 1 )
    return 4294967277LL;
  v2 = *(__int64 (__fastcall **)(int *, __int64))(*(_QWORD *)a1 + 56LL);
  if ( !v2 )
    return 4294967277LL;
  if ( *((_DWORD *)v2 - 1) != 469858761 )
    __break(0x8228u);
  return v2(a1, a2);
}
