__int64 __fastcall stm_ftrace_unlink(__int64 a1)
{
  return unregister_ftrace_export(a1 + 48);
}
