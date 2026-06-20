__int64 __fastcall adreno_ringbuffer_stop(__int64 result)
{
  __int64 v1; // x19
  int v2; // w22
  __int64 v3; // x20

  if ( *(int *)(result + 19632) >= 1 )
  {
    v1 = result;
    v2 = 0;
    v3 = result + 14392;
    do
    {
      result = kgsl_cancel_events(v1, v3);
      ++v2;
      v3 += 1320;
    }
    while ( v2 < *(_DWORD *)(v1 + 19632) );
  }
  return result;
}
