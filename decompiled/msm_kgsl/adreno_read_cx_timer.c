__int64 __fastcall adreno_read_cx_timer(__int64 a1, __int64 a2)
{
  __int64 (__fastcall *v3)(__int64, __int64); // x8

  if ( (*(_QWORD *)(a1 + 14240) & 0x20000) == 0 )
    return 0;
  v3 = (__int64 (__fastcall *)(__int64, __int64))arch_timer_read_counter;
  if ( *(_DWORD *)(arch_timer_read_counter - 4LL) != -1073338243 )
    __break(0x8228u);
  return v3(a1, a2);
}
