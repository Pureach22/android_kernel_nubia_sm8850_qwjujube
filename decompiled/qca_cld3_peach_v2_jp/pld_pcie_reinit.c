__int64 __fastcall pld_pcie_reinit(__int64 a1, __int64 a2)
{
  _DWORD *v4; // x8

  v4 = *(_DWORD **)(*(_QWORD *)pld_get_global_context() + 40LL);
  if ( !v4 )
    return 4294967277LL;
  if ( *(v4 - 1) != -979153776 )
    __break(0x8228u);
  return ((__int64 (__fastcall *)(__int64, _QWORD, __int64, __int64))v4)(a1 + 200, 0, a1, a2);
}
