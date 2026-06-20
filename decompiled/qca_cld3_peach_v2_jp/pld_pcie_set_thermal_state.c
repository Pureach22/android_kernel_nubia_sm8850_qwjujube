__int64 __fastcall pld_pcie_set_thermal_state(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 global_context; // x0
  _DWORD *v7; // x8

  global_context = pld_get_global_context();
  if ( !global_context )
    return 4294967274LL;
  v7 = *(_DWORD **)(*(_QWORD *)global_context + 136LL);
  if ( !v7 )
    return 4294966772LL;
  if ( *(v7 - 1) != 1940371796 )
    __break(0x8228u);
  return ((__int64 (__fastcall *)(__int64, __int64, _QWORD))v7)(a1 + 200, a2, a3);
}
