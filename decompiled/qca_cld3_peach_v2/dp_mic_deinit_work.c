__int64 __fastcall dp_mic_deinit_work(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  __int64 v12; // x0
  __int64 v13; // x8

  result = qdf_trace_msg(
             0x45u,
             5u,
             "%s: DeInitialize the MIC error work",
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             "dp_mic_deinit_work");
  if ( *(_DWORD *)(a1 + 3448) )
  {
    cancel_work_sync(a1 + 3400);
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 3464);
    }
    else
    {
      raw_spin_lock_bh(a1 + 3464);
      *(_QWORD *)(a1 + 3472) |= 1uLL;
    }
    v12 = *(_QWORD *)(a1 + 3456);
    *(_DWORD *)(a1 + 3448) = 0;
    if ( v12 )
    {
      _qdf_mem_free(v12);
      *(_QWORD *)(a1 + 3456) = 0;
    }
    v13 = *(_QWORD *)(a1 + 3472);
    if ( (v13 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 3472) = v13 & 0xFFFFFFFFFFFFFFFELL;
      return raw_spin_unlock_bh(a1 + 3464);
    }
    else
    {
      return raw_spin_unlock(a1 + 3464);
    }
  }
  return result;
}
