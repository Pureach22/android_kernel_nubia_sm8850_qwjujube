__int64 __fastcall dp_pdev_update_fast_rx_flag(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10)
{
  unsigned int v11; // w20
  unsigned __int64 StatusReg; // x8
  __int64 v13; // x8
  __int64 v14; // x8
  __int64 result; // x0

  if ( (*(_BYTE *)(a10 + 95436) & 1) == 0 )
  {
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a10 + 312);
      v13 = *(_QWORD *)(a10 + 296);
      if ( v13 )
      {
LABEL_7:
        while ( (*(_BYTE *)(v13 + 56) & 1) == 0 && (*(_BYTE *)(v13 + 80) & 1) == 0 && !*(_DWORD *)(v13 + 64) )
        {
          v13 = *(_QWORD *)(v13 + 104);
          if ( !v13 )
            goto LABEL_11;
        }
        v11 = 0;
        v14 = *(_QWORD *)(a10 + 320);
        if ( (v14 & 1) != 0 )
          goto LABEL_15;
        goto LABEL_12;
      }
    }
    else
    {
      raw_spin_lock_bh(a10 + 312);
      *(_QWORD *)(a10 + 320) |= 1uLL;
      v13 = *(_QWORD *)(a10 + 296);
      if ( v13 )
        goto LABEL_7;
    }
LABEL_11:
    v11 = 1;
    v14 = *(_QWORD *)(a10 + 320);
    if ( (v14 & 1) != 0 )
    {
LABEL_15:
      *(_QWORD *)(a10 + 320) = v14 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a10 + 312);
      goto LABEL_13;
    }
LABEL_12:
    raw_spin_unlock(a10 + 312);
    goto LABEL_13;
  }
  v11 = 0;
LABEL_13:
  result = qdf_trace_msg(
             0x7Cu,
             5u,
             "%s: Updated Rx fast flag to %u",
             a1,
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             "dp_pdev_update_fast_rx_flag",
             v11);
  *(_BYTE *)(a10 + 24) = v11;
  return result;
}
