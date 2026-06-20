__int64 __fastcall stats_enable_show_1(__int64 a1, __int64 a2, __int64 a3)
{
  return (int)scnprintf(a3, 4096, "%d\n", *(unsigned __int8 *)(a1 - 16));
}
