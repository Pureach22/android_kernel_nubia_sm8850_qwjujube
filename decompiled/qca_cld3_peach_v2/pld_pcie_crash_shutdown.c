__int64 __fastcall pld_pcie_crash_shutdown(__int64 a1)
{
  __int64 result; // x0
  _DWORD *v3; // x8

  result = pld_get_global_context();
  v3 = *(_DWORD **)(*(_QWORD *)result + 48LL);
  if ( v3 )
  {
    if ( *(v3 - 1) != 258479119 )
      __break(0x8228u);
    return ((__int64 (__fastcall *)(__int64, _QWORD))v3)(a1 + 200, 0);
  }
  return result;
}
