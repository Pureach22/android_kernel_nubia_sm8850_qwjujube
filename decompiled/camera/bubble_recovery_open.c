__int64 __fastcall bubble_recovery_open(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  return simple_attr_open(
           a1,
           a2,
           cam_req_mgr_debug_get_bubble_recovery,
           cam_req_mgr_debug_set_bubble_recovery,
           "%lld\n",
           a6);
}
