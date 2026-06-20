__int64 __fastcall stm_ftrace_link(__int64 a1)
{
  *(_QWORD *)(a1 + 56) = stm_ftrace_write;
  *(_DWORD *)(a1 + 64) = 7;
  return register_ftrace_export(a1 + 48);
}
