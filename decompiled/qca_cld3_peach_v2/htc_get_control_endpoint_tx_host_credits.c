__int64 __fastcall htc_get_control_endpoint_tx_host_credits(__int64 result, _DWORD *a2)
{
  __int64 v3; // x19
  unsigned __int64 StatusReg; // x8
  __int64 v5; // x8
  __int64 v6; // x8

  if ( result && a2 )
  {
    v3 = result;
    *a2 = 0;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(result + 2992);
    }
    else
    {
      raw_spin_lock_bh(result + 2992);
      *(_QWORD *)(v3 + 3000) |= 1uLL;
    }
    if ( *(_WORD *)(v3 + 12) == 256 )
    {
      v5 = v3 + 8;
    }
    else if ( *(_WORD *)(v3 + 340) == 256 )
    {
      v5 = v3 + 336;
    }
    else if ( *(_WORD *)(v3 + 668) == 256 )
    {
      v5 = v3 + 664;
    }
    else if ( *(_WORD *)(v3 + 996) == 256 )
    {
      v5 = v3 + 992;
    }
    else if ( *(_WORD *)(v3 + 1324) == 256 )
    {
      v5 = v3 + 1320;
    }
    else if ( *(_WORD *)(v3 + 1652) == 256 )
    {
      v5 = v3 + 1648;
    }
    else if ( *(_WORD *)(v3 + 1980) == 256 )
    {
      v5 = v3 + 1976;
    }
    else if ( *(_WORD *)(v3 + 2308) == 256 )
    {
      v5 = v3 + 2304;
    }
    else
    {
      if ( *(_WORD *)(v3 + 2636) != 256 )
        goto LABEL_28;
      v5 = v3 + 2632;
    }
    *a2 = *(_DWORD *)(v5 + 288);
LABEL_28:
    v6 = *(_QWORD *)(v3 + 3000);
    if ( (v6 & 1) == 0 )
      return raw_spin_unlock(v3 + 2992);
    *(_QWORD *)(v3 + 3000) = v6 & 0xFFFFFFFFFFFFFFFELL;
    return raw_spin_unlock_bh(v3 + 2992);
  }
  if ( (dword_B804 & 1) != 0 )
    return qdf_trace_msg(
             56,
             2,
             "%s: %s: invalid args",
             "htc_get_control_endpoint_tx_host_credits",
             "htc_get_control_endpoint_tx_host_credits");
  return result;
}
