__int64 __fastcall pld_pcie_idle_shutdown_cb(__int64 a1)
{
  __int64 global_context; // x0
  _DWORD *v3; // x8

  global_context = pld_get_global_context();
  if ( !*(_QWORD *)(*(_QWORD *)global_context + 32LL) )
    return 4294967277LL;
  v3 = *(_DWORD **)(*(_QWORD *)global_context + 16LL);
  if ( *(v3 - 1) != -1302029260 )
    __break(0x8228u);
  return ((__int64 (__fastcall *)(__int64, _QWORD))v3)(a1 + 200, 0);
}
