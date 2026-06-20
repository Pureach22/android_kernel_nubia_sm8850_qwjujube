__int64 __fastcall adreno_drain_and_idle(__int64 *a1)
{
  __int64 result; // x0

  result = adreno_drain(a1);
  if ( !(_DWORD)result )
    return adreno_wait_idle((__int64)a1);
  return result;
}
