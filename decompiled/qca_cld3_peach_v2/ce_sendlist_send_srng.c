__int64 __fastcall ce_sendlist_send_srng(__int64 a1, __int64 a2, unsigned int *a3, unsigned __int16 a4)
{
  __int64 v4; // x24
  unsigned int v5; // w23
  unsigned __int64 StatusReg; // x8
  _DWORD *v11; // x8
  unsigned int v12; // w9
  unsigned int v13; // w10
  bool v14; // cf
  unsigned int v15; // w9
  unsigned int v16; // w21
  unsigned int v17; // w23
  __int64 v18; // x25
  __int64 v19; // x6
  __int64 v20; // x7
  __int64 v21; // x8

  v4 = *(_QWORD *)(a1 + 136);
  v5 = *a3;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 168);
  }
  else
  {
    raw_spin_lock_bh(a1 + 168);
    *(_QWORD *)(a1 + 176) |= 1uLL;
  }
  v11 = *(_DWORD **)(v4 + 80);
  v12 = v11[30];
  v13 = v11[34];
  v14 = v13 >= v12;
  v15 = v13 - v12;
  if ( v15 == 0 || !v14 )
    v15 += v11[9];
  if ( v15 / v11[11] - 1 < v5 )
  {
    v16 = 2;
LABEL_15:
    v21 = *(_QWORD *)(a1 + 176);
    if ( (v21 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 176) = v21 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 168);
    }
    else
    {
      raw_spin_unlock(a1 + 168);
    }
    return v16;
  }
  v17 = v5 - 1;
  if ( !v17 )
  {
LABEL_14:
    v16 = ce_send_nolock_srng(a1, a2, *(_QWORD *)&a3[8 * v17 + 4], a3[8 * v17 + 6], a4, a3[8 * v17 + 7]);
    ((void (__fastcall *)(__int64, __int64))qdf_nbuf_set_state)(a2, 8);
    qdf_dp_trace(a2, 0x1Cu, 0xFFu, *(_QWORD *)(a2 + 224), 8u, 0, v19, v20);
    goto LABEL_15;
  }
  v18 = 0;
  while ( v18 != 104 )
  {
    ce_send_nolock_srng(a1, 3469655791LL, *(_QWORD *)&a3[v18 + 4], a3[v18 + 6], a4, a3[v18 + 7] | 0x10000);
    v18 += 8;
    if ( 8LL * v17 == v18 )
    {
      if ( v17 <= 0xC )
        goto LABEL_14;
      break;
    }
  }
  __break(0x5512u);
  return ce_revoke_recv_next_srng();
}
