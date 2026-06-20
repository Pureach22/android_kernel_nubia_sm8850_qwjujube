__int64 __fastcall pld_pcie_notify_handler(__int64 a1, unsigned int a2)
{
  __int64 result; // x0
  _DWORD *v5; // x8

  result = pld_get_global_context();
  v5 = *(_DWORD **)(*(_QWORD *)result + 80LL);
  if ( v5 )
  {
    if ( *(v5 - 1) != 1825293426 )
      __break(0x8228u);
    return ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))v5)(a1 + 200, 0, a2);
  }
  return result;
}
