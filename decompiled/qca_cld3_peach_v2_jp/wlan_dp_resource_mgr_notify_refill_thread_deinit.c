__int64 wlan_dp_resource_mgr_notify_refill_thread_deinit()
{
  __int64 result; // x0
  double v1; // d0
  double v2; // d1
  double v3; // d2
  double v4; // d3
  double v5; // d4
  double v6; // d5
  double v7; // d6
  double v8; // d7
  __int64 v9; // x19
  unsigned __int64 StatusReg; // x8
  __int64 v11; // x8

  result = dp_get_context();
  if ( !result )
    return qdf_trace_msg(
             0x45u,
             2u,
             "%s: DP context is NULL",
             v1,
             v2,
             v3,
             v4,
             v5,
             v6,
             v7,
             v8,
             "wlan_dp_resource_mgr_notify_refill_thread_deinit");
  v9 = *(_QWORD *)(result + 3000);
  if ( v9 )
  {
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v9 + 216);
      v11 = *(_QWORD *)(v9 + 224);
    }
    else
    {
      raw_spin_lock_bh(v9 + 216);
      v11 = *(_QWORD *)(v9 + 224) | 1LL;
      *(_QWORD *)(v9 + 224) = v11;
    }
    *(_BYTE *)(v9 + 232) = 1;
    if ( (v11 & 1) != 0 )
    {
      *(_QWORD *)(v9 + 224) = v11 & 0xFFFFFFFFFFFFFFFELL;
      return raw_spin_unlock_bh(v9 + 216);
    }
    else
    {
      return raw_spin_unlock(v9 + 216);
    }
  }
  return result;
}
