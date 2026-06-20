__int64 __fastcall adreno_drain(__int64 *a1)
{
  __int64 result; // x0
  __int64 v3; // x8
  unsigned int v4; // w19

  *((_DWORD *)a1 + 2180) = 0;
  result = kgsl_active_count_wait();
  if ( (_DWORD)result )
  {
    v3 = *a1;
    v4 = result;
    dev_err(v3, "Timed out waiting for the active count\n");
    return v4;
  }
  return result;
}
