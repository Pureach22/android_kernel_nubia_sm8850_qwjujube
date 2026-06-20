__int64 __fastcall zte_power_supply_get_property(__int64 a1, __int64 a2)
{
  __int64 (__fastcall *v2)(__int64, __int64); // x8

  if ( *(int *)(a1 + 1112) <= 0 )
  {
    if ( *(_BYTE *)(a1 + 1109) )
      return 4294967277LL;
    else
      return 4294967285LL;
  }
  else
  {
    v2 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)a1 + 48LL);
    if ( *((_DWORD *)v2 - 1) != -2056590187 )
      __break(0x8228u);
    return v2(a1, a2);
  }
}
