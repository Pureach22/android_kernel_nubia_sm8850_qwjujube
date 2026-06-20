__int64 __fastcall sub_122B1C(__int64 a1, __int64 a2)
{
  unsigned __int64 *v2; // x14

  __ldaxp(v2);
  return cam_common_wait_for_completion_timeout(a1, a2);
}
