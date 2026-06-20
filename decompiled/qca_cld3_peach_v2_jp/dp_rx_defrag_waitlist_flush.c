__int64 __fastcall dp_rx_defrag_waitlist_flush(__int64 a1)
{
  unsigned int v2; // w20
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  unsigned __int64 StatusReg; // x8
  __int64 v12; // x8
  _QWORD *v13; // x12
  __int64 v14; // x10
  unsigned int v15; // w12
  _QWORD *v16; // x12
  _QWORD *v17; // x13
  __int64 v18; // x8
  __int64 result; // x0
  __int64 v20; // x25
  unsigned __int64 v21; // x23
  __int64 v22; // x24
  __int64 v23; // x8
  _QWORD *v24; // x9
  _QWORD *v25; // x8
  __int64 v26; // x8
  __int64 v27; // x20
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 v36; // x21
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  __int64 v45; // x8
  __int64 v46; // [xsp+0h] [xbp-20h] BYREF
  __int64 v47; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v48[2]; // [xsp+10h] [xbp-10h] BYREF

  v48[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = jiffies_to_msecs(jiffies);
  v46 = 0;
  v47 = 0;
  v48[0] = &v47;
  qdf_trace_msg(0x45u, 8u, "%s: Current time  %u", v3, v4, v5, v6, v7, v8, v9, v10, "dp_rx_defrag_waitlist_flush", v2);
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 13136);
    v12 = *(_QWORD *)(a1 + 13112);
    if ( v12 )
      goto LABEL_8;
    goto LABEL_15;
  }
  raw_spin_lock_bh(a1 + 13136);
  *(_QWORD *)(a1 + 13144) |= 1uLL;
  v12 = *(_QWORD *)(a1 + 13112);
  if ( !v12 )
  {
LABEL_15:
    v15 = *(_DWORD *)(a1 + 13128) + v2;
    goto LABEL_16;
  }
LABEL_8:
  while ( 1 )
  {
    v14 = *(_QWORD *)(v12 + 8);
    v15 = *(_DWORD *)(v12 + 104);
    if ( v15 > v2 )
      break;
    if ( *(_DWORD *)v12 <= 0x10u )
    {
      v16 = *(_QWORD **)(v12 + 16);
      v17 = (_QWORD *)(v14 + 16);
      if ( !v14 )
        v17 = (_QWORD *)(a1 + 13120);
      *v17 = v16;
      *v16 = *(_QWORD *)(v12 + 8);
      *(_QWORD *)(v12 + 8) = 0;
      *(_QWORD *)(v12 + 16) = 0;
      if ( a1 )
        --*(_DWORD *)(a1 + 13608);
      *(_QWORD *)(v12 + 8) = 0;
      v13 = (_QWORD *)v48[0];
      *(_QWORD *)(v12 + 16) = v48[0];
      *v13 = v12;
      v48[0] = v12 + 8;
    }
    v12 = v14;
    if ( !v14 )
      goto LABEL_15;
  }
LABEL_16:
  v18 = *(_QWORD *)(a1 + 13144);
  *(_DWORD *)(a1 + 13132) = v15;
  if ( (v18 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 13144) = v18 & 0xFFFFFFFFFFFFFFFELL;
    result = raw_spin_unlock_bh(a1 + 13136);
    v20 = v47;
    if ( v47 )
      goto LABEL_18;
  }
  else
  {
    result = raw_spin_unlock(a1 + 13136);
    v20 = v47;
    if ( v47 )
    {
LABEL_18:
      v21 = _ReadStatusReg(SP_EL0);
      do
      {
        v22 = *(_QWORD *)(v20 + 8);
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (*(_DWORD *)(v21 + 16) & 0xF0000) != 0
          || (*(_DWORD *)(v21 + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(v20 + 72);
        }
        else
        {
          raw_spin_lock_bh(v20 + 72);
          *(_QWORD *)(v20 + 80) |= 1uLL;
        }
        v23 = *(_QWORD *)(v20 + 8);
        v24 = *(_QWORD **)(v20 + 16);
        if ( v23 )
          v25 = (_QWORD *)(v23 + 16);
        else
          v25 = v48;
        *v25 = v24;
        *v24 = *(_QWORD *)(v20 + 8);
        v26 = *(_QWORD *)(v20 + 80);
        v27 = *(_QWORD *)(v20 + 112);
        *(_QWORD *)(v20 + 8) = 0;
        *(_QWORD *)(v20 + 16) = 0;
        if ( (v26 & 1) != 0 )
        {
          *(_QWORD *)(v20 + 80) = v26 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(v20 + 72);
        }
        else
        {
          raw_spin_unlock(v20 + 72);
        }
        result = dp_txrx_peer_get_ref_by_id_0(a1, *(unsigned __int16 *)(v27 + 8), &v46);
        v36 = result;
        if ( result == v27 )
        {
          if ( (_ReadStatusReg(DAIF) & 0x80) != 0
            || (*(_DWORD *)(v21 + 16) & 0xF0000) != 0
            || (*(_DWORD *)(v21 + 16) & 0xFF00) != 0 )
          {
            raw_spin_lock(v20 + 72);
          }
          else
          {
            raw_spin_lock_bh(v20 + 72);
            *(_QWORD *)(v20 + 80) |= 1uLL;
          }
          dp_rx_reorder_flush_frag(v27, *(_DWORD *)v20, v37, v38, v39, v40, v41, v42, v43, v44);
          v45 = *(_QWORD *)(v20 + 80);
          if ( (v45 & 1) != 0 )
          {
            *(_QWORD *)(v20 + 80) = v45 & 0xFFFFFFFFFFFFFFFELL;
            result = raw_spin_unlock_bh(v20 + 72);
            if ( !v36 )
              goto LABEL_19;
LABEL_37:
            result = dp_txrx_peer_unref_delete(v46, 4u, v28, v29, v30, v31, v32, v33, v34, v35);
            goto LABEL_19;
          }
          result = raw_spin_unlock(v20 + 72);
        }
        if ( v36 )
          goto LABEL_37;
LABEL_19:
        v20 = v22;
      }
      while ( v22 );
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
