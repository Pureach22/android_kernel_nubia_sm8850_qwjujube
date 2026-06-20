__int64 __fastcall gpu_max_pwrlevel_ceiling_show(__int64 a1, __int64 a2, __int64 a3)
{
  return (int)scnprintf(a3, 4096, "%d\n", gpu_max_pwrlevel_ceiling);
}
