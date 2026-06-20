__int64 __fastcall hdd_capture_req_timer_expired_handler(
        __int64 result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x20
  _QWORD *v10; // x19
  unsigned __int64 StatusReg; // x8
  __int64 v12; // x8
  const char *v13; // x2

  if ( result )
  {
    v9 = *(_QWORD *)(result + 24);
    v10 = (_QWORD *)result;
    if ( v9 )
    {
      if ( *(_DWORD *)(v9 + 3232) )
      {
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
          || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(result + 39160);
          v12 = v10[4896];
        }
        else
        {
          raw_spin_lock_bh(result + 39160);
          v12 = v10[4896] | 1LL;
          v10[4896] = v12;
        }
        v10[4919] = 0;
        v10[4867] = 0;
        if ( (v12 & 1) != 0 )
        {
          v10[4896] = v12 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(v10 + 4895);
        }
        else
        {
          raw_spin_unlock(v10 + 4895);
        }
        *(_QWORD *)(v9 + 3240) = 0;
        *(_DWORD *)(v9 + 3236) = 0;
        if ( (unsigned int)qdf_mc_timer_get_current_state((__int64)(v10 + 4897)) != 18 )
          return qdf_mc_timer_start((__int64)(v10 + 4897), 0x64u);
        v13 = "%s: invalid timer status";
      }
      else
      {
        qdf_trace_msg(0x33u, 2u, "%s: TSF is not initialized", a2, a3, a4, a5, a6, a7, a8, a9, "hdd_tsf_is_initialized");
        v13 = "%s: tsf not init";
      }
    }
    else
    {
      v13 = "%s: invalid hdd context";
    }
    return qdf_trace_msg(0x33u, 3u, v13, a2, a3, a4, a5, a6, a7, a8, a9, "hdd_capture_req_timer_expired_handler");
  }
  return result;
}
