__int64 __fastcall tpg_hw_acquire(__int64 a1)
{
  __int64 v1; // x8
  __int64 v3; // x8
  unsigned int v4; // w19

  if ( !a1 )
    return 4294967274LL;
  v1 = *(_QWORD *)(a1 + 32);
  if ( !v1 || !*(_QWORD *)(v1 + 16) )
    return 4294967274LL;
  mutex_lock(a1 + 48);
  v3 = a1;
  if ( (unsigned int)(**(_DWORD **)(a1 + 32) - 0x10000000) >= 6 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x200000000LL,
      1,
      "tpg_hw_acquire",
      854,
      "TPG[%d] Unsupported HW Version",
      *(_DWORD *)a1);
    v3 = a1;
    v4 = -22;
  }
  else
  {
    v4 = 0;
  }
  *(_QWORD *)(v3 + 256) = -1;
  mutex_unlock(v3 + 48);
  return v4;
}
