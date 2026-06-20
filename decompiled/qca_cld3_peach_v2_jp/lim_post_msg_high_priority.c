__int64 __fastcall lim_post_msg_high_priority(__int64 a1, unsigned __int16 *a2)
{
  return scheduler_post_msg_by_priority(53, a2, 1);
}
