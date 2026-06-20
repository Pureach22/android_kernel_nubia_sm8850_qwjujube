__int64 rmnet_shs_lpm_ring()
{
  __int64 v0; // x0
  __int64 v1; // x0
  __int64 v2; // x1
  __int64 v3; // x8
  _QWORD v5[16]; // [xsp+0h] [xbp-80h] BYREF

  v5[15] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v5, 0, 120);
  rmnet_shs_create_ping_boost_msg_resp((unsigned int)rmnet_shs_perf_duration, v5);
  rmnet_shs_genl_msg_direct_send_to_userspace(v5);
  v0 = ktime_get_with_offset(1);
  v1 = ns_to_timespec64(v0);
  v3 = v2 + 1000000000 * v1;
  if ( v1 > 0x225C17D03LL )
    v3 = 0x7FFFFFFFFFFFFFFFLL;
  qword_19478 = v3;
  _ReadStatusReg(SP_EL0);
  return 0;
}
