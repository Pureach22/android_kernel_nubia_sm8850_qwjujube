__int64 __fastcall pld_pcie_collect_driver_dump(__int64 a1, __int64 a2, __int64 a3)
{
  _DWORD *v6; // x8

  v6 = *(_DWORD **)(*(_QWORD *)pld_get_global_context() + 96LL);
  if ( !v6 )
    return 4294967274LL;
  if ( *(v6 - 1) != 112519437 )
    __break(0x8228u);
  return ((__int64 (__fastcall *)(__int64, _QWORD, __int64, __int64))v6)(a1 + 200, 0, a2, a3);
}
