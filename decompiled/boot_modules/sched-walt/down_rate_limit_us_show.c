__int64 __fastcall down_rate_limit_us_show(__int64 a1, __int64 a2)
{
  return (int)scnprintf(a2, 4096, "%u\n", *(_DWORD *)(a1 + 172));
}
