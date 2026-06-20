__int64 __fastcall dp_peer_update_state(__int64 a1, int a2)
{
  unsigned __int64 StatusReg; // x8
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  unsigned int v13; // w21
  __int64 v14; // x8
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v24; // [xsp+0h] [xbp-10h]
  __int64 v25; // [xsp+8h] [xbp-8h]

  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 384);
  }
  else
  {
    raw_spin_lock_bh(a1 + 384);
    *(_QWORD *)(a1 + 392) |= 1uLL;
  }
  v13 = *(unsigned __int8 *)(a1 + 380);
  if ( a2 <= 2 )
  {
    if ( a2 != 1 )
      goto LABEL_18;
    if ( v13 - 4 >= 0xFFFFFFFE )
      goto LABEL_19;
  }
  else
  {
    if ( a2 != 3 )
    {
      if ( a2 == 4 )
      {
        if ( v13 == 3 )
          goto LABEL_20;
LABEL_19:
        qdf_trace_msg(
          0x45u,
          1u,
          "%s: Invalid state shift from %u to %u peer %02x:%02x:%02x:**:**:%02x",
          v5,
          v6,
          v7,
          v8,
          v9,
          v10,
          v11,
          v12,
          "dp_peer_update_state",
          *(unsigned __int8 *)(a1 + 380),
          (unsigned int)a2,
          *(unsigned __int8 *)(a1 + 44),
          *(unsigned __int8 *)(a1 + 45),
          *(unsigned __int8 *)(a1 + 46),
          *(unsigned __int8 *)(a1 + 49));
        goto LABEL_20;
      }
      if ( (*(_BYTE *)(a1 + 120) & 0x10) == 0 )
      {
        if ( v13 - 3 >= 2 )
          goto LABEL_19;
        goto LABEL_20;
      }
LABEL_18:
      if ( v13 == 1 )
        goto LABEL_20;
      goto LABEL_19;
    }
    if ( v13 - 1 >= 2 )
      goto LABEL_19;
  }
LABEL_20:
  v14 = *(_QWORD *)(a1 + 392);
  *(_BYTE *)(a1 + 380) = a2;
  if ( (v14 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 392) = v14 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 384);
  }
  else
  {
    raw_spin_unlock(a1 + 384);
  }
  LODWORD(v25) = *(unsigned __int8 *)(a1 + 49);
  LODWORD(v24) = *(unsigned __int8 *)(a1 + 46);
  return qdf_trace_msg(
           0x45u,
           5u,
           "%s: Updating peer state from %u to %u mac %02x:%02x:%02x:**:**:%02x\n",
           v15,
           v16,
           v17,
           v18,
           v19,
           v20,
           v21,
           v22,
           "dp_peer_update_state",
           v13,
           (unsigned int)a2,
           *(unsigned __int8 *)(a1 + 44),
           *(unsigned __int8 *)(a1 + 45),
           v24,
           v25);
}
