__int64 __fastcall ttlm_timer_init(__int64 a1)
{
  return qdf_mc_timer_init(a1 + 736, 0, (__int64)ttlm_req_timeout_cb, a1);
}
