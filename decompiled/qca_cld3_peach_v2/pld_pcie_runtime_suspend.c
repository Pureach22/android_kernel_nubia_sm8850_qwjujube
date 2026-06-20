__int64 __fastcall pld_pcie_runtime_suspend(__int64 a1)
{
  _DWORD *v2; // x8

  v2 = *(_DWORD **)(*(_QWORD *)pld_get_global_context() + 104LL);
  if ( !v2 )
    return 4294967277LL;
  if ( *(v2 - 1) != -1302029260 )
    __break(0x8228u);
  return ((__int64 (__fastcall *)(__int64, _QWORD))v2)(a1 + 200, 0);
}
