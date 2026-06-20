__int64 __fastcall mhi_process_sleeping_events(__int64 result)
{
  unsigned int v1; // w8
  __int64 v2; // x21
  __int64 v3; // x19
  unsigned int i; // w20

  v1 = *(_DWORD *)(result + 212);
  if ( v1 )
  {
    v2 = *(_QWORD *)(result + 248);
    v3 = result;
    for ( i = 0; i < v1; ++i )
    {
      if ( (*(_BYTE *)(v2 + 258) & 1) == 0
        && *(_DWORD *)(v2 + 32) == 2
        && *(_QWORD *)(v2 + 80) != *(_QWORD *)(v2 + 72)
                                 + *(_QWORD *)(**(_QWORD **)(v3 + 264) + 44LL * *(unsigned int *)(v2 + 16) + 28)
                                 - *(_QWORD *)(v2 + 48) )
      {
        result = queue_work_on(32, *(_QWORD *)(v3 + 448), v2 + 208);
        v1 = *(_DWORD *)(v3 + 212);
      }
      v2 += 264;
    }
  }
  return result;
}
