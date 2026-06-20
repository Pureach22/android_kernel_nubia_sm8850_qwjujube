__int64 __fastcall drm_dp_mst_topology_mgr_suspend(__int64 a1)
{
  _QWORD *v2; // x0
  __int64 result; // x0
  char v4[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v5; // [xsp+8h] [xbp-8h]

  v5 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  mutex_lock(a1 + 800);
  v2 = *(_QWORD **)(a1 + 128);
  v4[0] = 5;
  drm_dp_dpcd_write(v2, 0x111u, (__int64)v4, 1);
  mutex_unlock(a1 + 800);
  flush_work(a1 + 1272);
  flush_work(a1 + 1024);
  flush_work(a1 + 1176);
  mutex_lock(a1 + 800);
  if ( (*(_BYTE *)(a1 + 896) & 1) != 0 && *(_QWORD *)(a1 + 904) )
    drm_dp_mst_topology_mgr_invalidate_mstb();
  result = mutex_unlock(a1 + 800);
  _ReadStatusReg(SP_EL0);
  return result;
}
