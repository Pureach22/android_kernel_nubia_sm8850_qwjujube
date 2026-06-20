__int64 __fastcall tmc_wait_for_tmcready(__int64 a1)
{
  __int64 v1; // x19
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16);
  result = coresight_timeout(v1 + 32, 12, 2, 1);
  if ( (_DWORD)result )
  {
    dev_err(v1 + 56, "timeout while waiting for TMC to be Ready\n");
    return 4294967280LL;
  }
  return result;
}
