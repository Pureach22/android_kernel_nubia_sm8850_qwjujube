__int64 __fastcall sub_24E810(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6, __int64 a7)
{
  unsigned int *v7; // x18
  __int64 v8; // x7

  v8 = __ldaxr(v7);
  return policy_mgr_get_connection_for_vdev_id(a1, a2, a3, a4, a5, a6, a7, v8);
}
