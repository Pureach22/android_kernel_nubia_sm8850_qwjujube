__int64 __fastcall gmu_fp_store(__int64 a1, int a2)
{
  int v2; // w19

  v2 = a2 & 0x7FFFF;
  if ( (*(_QWORD *)&a2 & 0x7FFFFLL) != *(_DWORD *)(a1 + 1536) )
  {
    rt_mutex_lock(a1 + 11088);
    *(_DWORD *)(a1 + 1536) = v2;
    rt_mutex_unlock(a1 + 11088);
  }
  return 0;
}
