__int64 __fastcall kgsl_pwrscale_update(__int64 result)
{
  __int64 v1; // x19
  int v2; // w8

  if ( *(_QWORD *)(result + 11112) )
  {
    v1 = result;
    if ( *(_BYTE *)(result + 11880) == 1 )
    {
      result = ktime_get(result);
      if ( result >= *(_QWORD *)(v1 + 12016) )
      {
        v2 = *(_DWORD *)(v1 + 11120);
        *(_QWORD *)(v1 + 12016) = result + 10000000;
        if ( v2 != 128 )
          return kthread_queue_work(*(_QWORD *)(v1 + 11968), v1 + 11976);
      }
    }
  }
  else
  {
    __break(0x800u);
  }
  return result;
}
