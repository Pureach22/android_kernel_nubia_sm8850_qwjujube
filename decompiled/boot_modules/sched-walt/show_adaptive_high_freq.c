__int64 __fastcall show_adaptive_high_freq(__int64 a1, __int64 a2)
{
  return (int)scnprintf(a2, 4096, "%lu\n", *(unsigned int *)(a1 + 200));
}
