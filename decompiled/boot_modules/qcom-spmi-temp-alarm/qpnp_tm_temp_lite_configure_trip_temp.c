__int64 __fastcall qpnp_tm_temp_lite_configure_trip_temp(__int64 a1, __int64 a2)
{
  unsigned int v4; // w2

  mutex_lock(a2 + 64);
  v4 = *(_DWORD *)a1;
  *(_QWORD *)(a1 + 16) = *(unsigned int *)(a2 + 52);
  LODWORD(a1) = qpnp_tm_set_temp_lite_thresh((__int64 *)a2, *(_DWORD *)(a2 + 52), v4);
  ++*(_DWORD *)(a2 + 52);
  mutex_unlock(a2 + 64);
  return (unsigned int)a1;
}
