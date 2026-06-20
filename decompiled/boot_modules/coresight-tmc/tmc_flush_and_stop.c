__int64 __fastcall tmc_flush_and_stop(__int64 a1)
{
  __int64 v1; // x21
  int v3; // w20
  __int64 v4; // x19
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16);
  v3 = readl_relaxed(*(_QWORD *)(a1 + 8) + 772LL);
  writel_relaxed(v3 | 0x1000u, *(_QWORD *)(a1 + 8) + 772LL);
  writel_relaxed(v3 | 0x1040u, *(_QWORD *)(a1 + 8) + 772LL);
  if ( (unsigned int)coresight_timeout(v1 + 32, 772, 6, 0) )
    dev_err(v1 + 56, "timeout while waiting for completion of Manual Flush\n");
  v4 = *(_QWORD *)(a1 + 16);
  result = coresight_timeout(v4 + 32, 12, 2, 1);
  if ( (_DWORD)result )
    return dev_err(v4 + 56, "timeout while waiting for TMC to be Ready\n");
  return result;
}
