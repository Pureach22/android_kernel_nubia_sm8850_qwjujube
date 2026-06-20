__int64 __fastcall dp_mst_sim_reset_work(__int64 a1)
{
  __int64 v1; // x19
  int v2; // w8

  v1 = *(_QWORD *)(a1 + 32);
  mutex_lock(v1 + 688);
  v2 = *(_DWORD *)(v1 + 776);
  *(_DWORD *)(v1 + 736) = 0;
  *(_DWORD *)(v1 + 776) = v2 - 1;
  return mutex_unlock(v1 + 688);
}
