__int64 __fastcall sub_22C560(long double a1, long double a2, long double a3, float a4)
{
  __int64 v4; // x21

  LOWORD(a4) = *(_WORD *)(v4 + 744);
  return send_process_ll_stats_set_cmd_tlv(a1, a2, a3, a4);
}
