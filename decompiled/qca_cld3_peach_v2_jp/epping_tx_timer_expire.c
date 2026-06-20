__int64 __fastcall epping_tx_timer_expire(
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
  __int64 *v11; // x20
  __int64 *v12; // x9
  __int64 v13; // x8
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x8
  int v31; // w8
  unsigned __int64 StatusReg; // x8
  __int64 v33; // x20
  unsigned int multiplier; // w0
  __int64 v35; // x8

  result = qdf_trace_msg(
             0x33u,
             4u,
             "%s: queue len: %d\n",
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             "epping_tx_timer_expire",
             *(unsigned int *)(a1 + 64));
  if ( *(_DWORD *)(a1 + 64) && (v11 = *(__int64 **)(a1 + 48)) != nullptr )
  {
    while ( 1 )
    {
      v12 = *(__int64 **)(a1 + 56);
      --*(_DWORD *)(a1 + 64);
      if ( v11 == v12 )
      {
        v13 = 0;
        *(_QWORD *)(a1 + 56) = 0;
      }
      else
      {
        v13 = *v11;
      }
      *(_QWORD *)(a1 + 48) = v13;
      *v11 = 0;
      htc_set_nodrop_pkt(*(_QWORD *)(*(_QWORD *)a1 + 56LL), 1);
      if ( (unsigned int)epping_tx_send_int(v11, a1) )
        break;
      htc_set_nodrop_pkt(*(_QWORD *)(*(_QWORD *)a1 + 56LL), 0);
      result = qdf_trace_msg(
                 0x33u,
                 4u,
                 "%s: nodrop: %pK xmit ok in timer\n",
                 v22,
                 v23,
                 v24,
                 v25,
                 v26,
                 v27,
                 v28,
                 v29,
                 "epping_tx_timer_expire",
                 v11);
      v11 = *(__int64 **)(a1 + 48);
      if ( !v11 )
        goto LABEL_8;
    }
    qdf_trace_msg(
      0x33u,
      1u,
      "%s: nodrop: %pK xmit fail in timer\n",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "epping_tx_timer_expire",
      v11);
    v30 = *(_QWORD *)(a1 + 48);
    if ( !v30 )
      *(_QWORD *)(a1 + 56) = v11;
    *v11 = v30;
    v31 = *(_DWORD *)(a1 + 64);
    *(_QWORD *)(a1 + 48) = v11;
    *(_DWORD *)(a1 + 64) = v31 + 1;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 32);
    }
    else
    {
      raw_spin_lock_bh(a1 + 32);
      *(_QWORD *)(a1 + 40) |= 1uLL;
    }
    if ( *(_DWORD *)(a1 + 128) != 1 )
    {
      *(_DWORD *)(a1 + 128) = 1;
      v33 = jiffies;
      multiplier = qdf_timer_get_multiplier();
      mod_timer(a1 + 72, v33 + multiplier);
    }
    v35 = *(_QWORD *)(a1 + 40);
    if ( (v35 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 40) = v35 & 0xFFFFFFFFFFFFFFFELL;
      return raw_spin_unlock_bh(a1 + 32);
    }
    else
    {
      return raw_spin_unlock(a1 + 32);
    }
  }
  else
  {
LABEL_8:
    *(_DWORD *)(a1 + 128) = 0;
  }
  return result;
}
