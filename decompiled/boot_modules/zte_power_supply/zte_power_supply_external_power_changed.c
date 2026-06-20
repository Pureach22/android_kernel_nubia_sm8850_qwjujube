int *__fastcall zte_power_supply_external_power_changed(int *result, __int64 a2)
{
  __int64 (__fastcall *v2)(int *, __int64); // x8

  if ( result[278] >= 1 )
  {
    v2 = *(__int64 (__fastcall **)(int *, __int64))(*(_QWORD *)result + 72LL);
    if ( v2 )
    {
      if ( *((_DWORD *)v2 - 1) != 1866051055 )
        __break(0x8228u);
      return (int *)v2(result, a2);
    }
  }
  return result;
}
