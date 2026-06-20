__int64 __fastcall sub_270204(__int64 a1, __int64 a2)
{
  unsigned int *v2; // x18

  __ldaxr(v2);
  return policy_mgr_get_connection_for_vdev_id(a1, a2);
}
