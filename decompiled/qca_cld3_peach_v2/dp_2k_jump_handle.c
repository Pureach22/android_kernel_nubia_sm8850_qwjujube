__int64 __fastcall dp_2k_jump_handle(__int64 a1, __int64 a2, __int64 a3, unsigned __int16 a4, unsigned int a5)
{
  unsigned __int64 StatusReg; // x8
  __int64 v11; // x22
  __int64 v12; // x8
  __int64 result; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 **v22; // x8
  __int64 *v23; // x24
  __int64 v24; // x25
  __int64 v25; // x23
  __int64 v26; // x25
  unsigned __int64 v27; // x8
  __int64 v28; // x8
  unsigned int v29; // w8
  unsigned int v36; // w10
  char v37; // w9
  __int64 v38; // x8
  __int64 v39; // x9
  _DWORD *v40; // x8
  __int64 v41; // x9
  __int64 v42; // x4
  __int64 v43; // x1
  __int64 v44; // x0
  __int64 v45; // x22
  unsigned int v48; // w9

  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 13304);
  }
  else
  {
    raw_spin_lock_bh(a1 + 13304);
    *(_QWORD *)(a1 + 13312) |= 1uLL;
  }
  if ( *(_DWORD *)(a1 + 13324) > (unsigned int)a4 )
  {
    v11 = *(_QWORD *)(*(_QWORD *)(a1 + 13136) + 8LL * a4);
    if ( !v11 )
      goto LABEL_9;
    if ( *(unsigned __int8 *)(v11 + 388) <= 2u )
    {
      v29 = *(_DWORD *)(v11 + 40);
      while ( v29 )
      {
        _X12 = (unsigned int *)(v11 + 40);
        __asm { PRFM            #0x11, [X12] }
        while ( 1 )
        {
          v36 = __ldxr(_X12);
          if ( v36 != v29 )
            break;
          if ( !__stlxr(v29 + 1, _X12) )
          {
            __dmb(0xBu);
            break;
          }
        }
        _ZF = v36 == v29;
        v29 = v36;
        if ( _ZF )
        {
          _X8 = (unsigned int *)(v11 + 280);
          __asm { PRFM            #0x11, [X8] }
          do
            v48 = __ldxr(_X8);
          while ( __stxr(v48 + 1, _X8) );
          goto LABEL_9;
        }
      }
    }
  }
  v11 = 0;
LABEL_9:
  v12 = *(_QWORD *)(a1 + 13312);
  if ( (v12 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 13312) = v12 & 0xFFFFFFFFFFFFFFFELL;
    result = raw_spin_unlock_bh(a1 + 13304);
    if ( v11 )
      goto LABEL_11;
LABEL_52:
    v45 = jiffies;
    if ( dp_2k_jump_handle___last_ticks - jiffies + 125 < 0 )
    {
      result = qdf_trace_msg(
                 0x82u,
                 5u,
                 "%s: %pK: peer not found",
                 v14,
                 v15,
                 v16,
                 v17,
                 v18,
                 v19,
                 v20,
                 v21,
                 "dp_2k_jump_handle",
                 a1);
      dp_2k_jump_handle___last_ticks = v45;
    }
    goto LABEL_54;
  }
  result = raw_spin_unlock(a1 + 13304);
  if ( !v11 )
    goto LABEL_52;
LABEL_11:
  if ( *(_DWORD *)(v11 + 408) == 1 && (v22 = *(__int64 ***)(v11 + 416)) != nullptr )
  {
    v23 = *v22;
    if ( *v22 )
      goto LABEL_14;
  }
  else
  {
    v23 = *(__int64 **)v11;
    if ( *(_QWORD *)v11 )
    {
LABEL_14:
      if ( (unsigned __int8)a5 < 0x11u )
      {
        v26 = *(_QWORD *)(v11 + 88) + 144LL * (unsigned __int8)a5;
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (v27 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v27 + 16) & 0xF0000) != 0)
          || (*(_DWORD *)(v27 + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(v26 + 88);
        }
        else
        {
          raw_spin_lock_bh(v26 + 88);
          *(_QWORD *)(v26 + 96) |= 1uLL;
        }
        if ( *(_DWORD *)(v26 + 68) == 1 && !*(_BYTE *)(v26 + 108) )
        {
          v37 = *(_BYTE *)(v26 + 109);
          v38 = *(_QWORD *)(v26 + 96);
          *(_BYTE *)(v26 + 108) = 1;
          *(_BYTE *)(v26 + 120) = 38;
          *(_BYTE *)(v26 + 109) = v37 + 1;
          if ( (v38 & 1) != 0 )
          {
            *(_QWORD *)(v26 + 96) = v38 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(v26 + 88);
          }
          else
          {
            raw_spin_unlock(v26 + 88);
          }
          v39 = *(_QWORD *)(a1 + 8);
          v40 = *(_DWORD **)(v39 + 168);
          if ( v40 )
          {
            if ( a1 )
            {
              ++*(_DWORD *)(a1 + 14116);
              v40 = *(_DWORD **)(v39 + 168);
            }
            v41 = *(_QWORD *)(v11 + 24);
            v42 = *(unsigned __int8 *)(v26 + 120);
            v43 = *(unsigned __int8 *)(v41 + 59);
            v44 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v41 + 24) + 8LL) + 16LL);
            if ( *(v40 - 1) != -1677196783 )
              __break(0x8228u);
            ((void (__fastcall *)(__int64, __int64, __int64, _QWORD, __int64, __int64))v40)(
              v44,
              v43,
              v11 + 44,
              a5,
              v42,
              1);
          }
        }
        else
        {
          v28 = *(_QWORD *)(v26 + 96);
          if ( (v28 & 1) != 0 )
          {
            *(_QWORD *)(v26 + 96) = v28 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(v26 + 88);
          }
          else
          {
            raw_spin_unlock(v26 + 88);
          }
        }
      }
      else
      {
        v24 = jiffies;
        if ( dp_2k_jump_handle___last_ticks_16 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(0x45u, 5u, "%s: invalid tid", v14, v15, v16, v17, v18, v19, v20, v21, "dp_2k_jump_handle");
          dp_2k_jump_handle___last_ticks_16 = v24;
        }
      }
      if ( (dp_rx_deliver_special_frame(a1, v23, a2, 1, a3) & 1) != 0 )
      {
        if ( a1 )
          ++*(_DWORD *)(a1 + 14120);
        return dp_peer_unref_delete(v11, 4u, v14, v15, v16, v17, v18, v19, v20, v21);
      }
      goto LABEL_32;
    }
  }
  v25 = jiffies;
  if ( dp_2k_jump_handle___last_ticks_14 - jiffies + 125 < 0 )
  {
    qdf_trace_msg(
      0x82u,
      5u,
      "%s: %pK: txrx_peer not found",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "dp_2k_jump_handle",
      a1);
    dp_2k_jump_handle___last_ticks_14 = v25;
  }
LABEL_32:
  result = dp_peer_unref_delete(v11, 4u, v14, v15, v16, v17, v18, v19, v20, v21);
LABEL_54:
  if ( a1 )
    ++*(_DWORD *)(a1 + 14124);
  if ( a2 )
    return _qdf_nbuf_free(a2);
  return result;
}
