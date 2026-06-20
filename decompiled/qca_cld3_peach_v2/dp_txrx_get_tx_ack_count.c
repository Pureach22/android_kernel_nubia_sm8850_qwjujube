__int64 __fastcall dp_txrx_get_tx_ack_count(
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
  _QWORD *context; // x20
  unsigned __int64 StatusReg; // x8
  __int64 v12; // x8
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  _QWORD *v21; // x8
  unsigned int v22; // w21
  unsigned __int64 v23; // x25
  __int64 v24; // x9
  _DWORD *v25; // x9
  __int64 v26; // x1
  int v27; // w24
  __int64 v28; // x8
  _QWORD *v30; // [xsp+8h] [xbp-18h] BYREF
  _QWORD *v31[2]; // [xsp+10h] [xbp-10h] BYREF

  v31[1] = *(_QWORD **)(_ReadStatusReg(SP_EL0) + 1808);
  context = _cds_get_context(71, (__int64)"dp_txrx_get_tx_ack_count", a2, a3, a4, a5, a6, a7, a8, a9);
  v30 = nullptr;
  v31[0] = nullptr;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 3672);
  }
  else
  {
    raw_spin_lock_bh(a1 + 3672);
    *(_QWORD *)(a1 + 3680) |= 1uLL;
  }
  dp_get_front_link_no_lock(a1, v31);
  dp_get_next_link_no_lock(a1, v31[0], &v30);
  v12 = *(_QWORD *)(a1 + 3680);
  if ( (v12 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 3680) = v12 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 3672);
    v21 = v31[0];
    if ( v31[0] )
      goto LABEL_7;
  }
  else
  {
    raw_spin_unlock(a1 + 3672);
    v21 = v31[0];
    if ( v31[0] )
    {
LABEL_7:
      v22 = 0;
      v23 = _ReadStatusReg(SP_EL0);
      while ( 1 )
      {
        if ( context && *context && (v24 = *(_QWORD *)(*context + 64LL)) != 0 )
        {
          v25 = *(_DWORD **)(v24 + 56);
          if ( v25 )
          {
            v26 = *((unsigned __int8 *)v21 + 24);
            if ( *(v25 - 1) != 210634893 )
              __break(0x8229u);
            v27 = ((__int64 (__fastcall *)(_QWORD *, __int64))v25)(context, v26);
            if ( (_ReadStatusReg(DAIF) & 0x80) != 0 )
              goto LABEL_19;
          }
          else
          {
            v27 = 0;
            if ( (_ReadStatusReg(DAIF) & 0x80) != 0 )
              goto LABEL_19;
          }
        }
        else
        {
          qdf_trace_msg(
            0x45u,
            1u,
            "%s invalid instance",
            v13,
            v14,
            v15,
            v16,
            v17,
            v18,
            v19,
            v20,
            "cdp_get_tx_ack_stats");
          v27 = 0;
          if ( (_ReadStatusReg(DAIF) & 0x80) != 0 )
            goto LABEL_19;
        }
        if ( (*(_DWORD *)(v23 + 16) & 0xF0000) == 0 && (*(_DWORD *)(v23 + 16) & 0xFF00) == 0 )
        {
          raw_spin_lock_bh(a1 + 3672);
          *(_QWORD *)(a1 + 3680) |= 1uLL;
          goto LABEL_20;
        }
LABEL_19:
        raw_spin_lock(a1 + 3672);
LABEL_20:
        v31[0] = v30;
        dp_get_next_link_no_lock(a1, v30, &v30);
        v28 = *(_QWORD *)(a1 + 3680);
        if ( (v28 & 1) != 0 )
        {
          *(_QWORD *)(a1 + 3680) = v28 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(a1 + 3672);
        }
        else
        {
          raw_spin_unlock(a1 + 3672);
        }
        v21 = v31[0];
        v22 += v27;
        if ( !v31[0] )
          goto LABEL_30;
      }
    }
  }
  v22 = 0;
LABEL_30:
  _ReadStatusReg(SP_EL0);
  return v22;
}
