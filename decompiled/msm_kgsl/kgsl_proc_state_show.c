__int64 __fastcall kgsl_proc_state_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 result; // x0

  if ( (*(_QWORD *)(a1 + 288) & 2LL) != 0 )
    LODWORD(result) = scnprintf(a3, 4096, "foreground\n");
  else
    LODWORD(result) = scnprintf(a3, 4096, "background\n");
  return (int)result;
}
