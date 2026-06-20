__int64 __fastcall htc_wait_recv_ctrl_message(__int64 a1)
{
  unsigned int v2; // w19
  unsigned __int64 StatusReg; // x8
  __int64 v4; // x8

  if ( (dword_B804 & 8) != 0 )
    qdf_trace_msg(56, 2, "%s: +HTCWaitCtrlMessageRecv\n", "htc_wait_recv_ctrl_message");
  if ( (unsigned int)qdf_wait_single_event(a1 + 3368, *(unsigned int *)(a1 + 3068)) )
  {
    v2 = 16;
    if ( (dword_B804 & 1) != 0 )
      qdf_trace_msg(56, 2, "%s: Failed to receive control message\n", "htc_wait_recv_ctrl_message");
  }
  else
  {
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 2976);
      v4 = *(_QWORD *)(a1 + 2984);
    }
    else
    {
      raw_spin_lock_bh(a1 + 2976);
      v4 = *(_QWORD *)(a1 + 2984) | 1LL;
      *(_QWORD *)(a1 + 2984) = v4;
    }
    *(_BYTE *)(a1 + 3408) = 1;
    if ( (v4 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 2984) = v4 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 2976);
    }
    else
    {
      raw_spin_unlock(a1 + 2976);
    }
    v2 = 0;
    if ( (dword_B804 & 8) != 0 )
      qdf_trace_msg(56, 2, "%s: -HTCWaitCtrlMessageRecv success\n", "htc_wait_recv_ctrl_message");
  }
  return v2;
}
