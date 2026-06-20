void sub_77340()
{
  unsigned int v0; // w24
  int v1; // w26
  unsigned __int64 StatusReg; // x27
  __int64 v3; // x28

  StatusReg = _ReadStatusReg(SP_EL0);
  v3 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &_ieee80211_request_sched_scan_start__alloc_tag;
  if ( is_mul_ok(v1, v0) )
    _kmalloc_noprof((int)v0 * (__int64)v1, 3520);
  *(_QWORD *)(StatusReg + 80) = v3;
  JUMPOUT(0x771A8);
}
