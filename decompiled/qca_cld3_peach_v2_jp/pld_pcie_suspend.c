__int64 __fastcall pld_pcie_suspend(__int64 a1, unsigned int a2)
{
  _DWORD *v4; // x8

  v4 = *(_DWORD **)(*(_QWORD *)pld_get_global_context() + 56LL);
  if ( *(v4 - 1) != -1590536230 )
    __break(0x8228u);
  return ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))v4)(a1 + 200, 0, a2);
}
