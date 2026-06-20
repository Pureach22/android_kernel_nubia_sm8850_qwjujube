__int64 __fastcall adreno_coresight_store_register(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v6; // x22
  __int64 v7; // x20
  int v8; // w0
  _QWORD v10[2]; // [xsp+0h] [xbp-10h] BYREF

  v10[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 152);
  v10[0] = 0;
  v7 = *(_QWORD *)(v6 + 16);
  v8 = kstrtoull(a3, 0, v10);
  if ( v8 )
  {
    a4 = v8;
  }
  else
  {
    rt_mutex_lock(v7 + 11088);
    if ( (*(_BYTE *)(v6 + 24) & 1) != 0 )
    {
      *(_BYTE *)(v7 + 23984) = 0;
      rt_mutex_unlock(v7 + 11088);
      adreno_power_cycle_u32(v7, (_DWORD *)(*(_QWORD *)(a2 + 32) + 8LL), v10[0]);
    }
    else
    {
      rt_mutex_unlock(v7 + 11088);
    }
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
