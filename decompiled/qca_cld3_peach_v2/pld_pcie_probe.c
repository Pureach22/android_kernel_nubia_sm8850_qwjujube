__int64 __fastcall pld_pcie_probe(__int64 a1, __int64 a2)
{
  __int64 global_context; // x0
  _DWORD ***v5; // x21
  __int64 result; // x0
  _DWORD *v7; // x8

  global_context = pld_get_global_context();
  if ( !global_context )
    return 4294967277LL;
  v5 = (_DWORD ***)global_context;
  result = pld_add_dev(global_context, a1 + 200, 0, 0);
  if ( !(_DWORD)result )
  {
    v7 = **v5;
    if ( *(v7 - 1) != -979153776 )
      __break(0x8228u);
    return ((__int64 (__fastcall *)(__int64, _QWORD, __int64, __int64))v7)(a1 + 200, 0, a1, a2);
  }
  return result;
}
