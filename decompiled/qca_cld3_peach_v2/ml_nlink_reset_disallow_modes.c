__int64 __fastcall ml_nlink_reset_disallow_modes(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x20

  v1 = *(_QWORD *)(result + 1360);
  if ( v1 )
  {
    if ( *(_QWORD *)(v1 + 2224) )
    {
      qdf_mutex_acquire(v1 + 1656);
      v2 = *(_QWORD *)(v1 + 2224);
      qdf_mem_set((void *)(v2 + 1456), 0x20u, 0);
      *(_DWORD *)(v2 + 1452) = 0;
      return qdf_mutex_release(v1 + 1656);
    }
  }
  return result;
}
