__int64 __fastcall dp_peer_rx_reorder_queue_setup_be(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        unsigned int a4,
        char a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  __int64 v13; // x22
  __int64 v14; // x8
  int v15; // w9
  unsigned int v16; // w8
  __int64 v17; // x8
  __int64 v18; // x9
  __int64 v19; // x19
  unsigned int v20; // w21
  unsigned __int64 StatusReg; // x8
  __int64 v24; // x0
  unsigned int v25; // w24
  __int64 result; // x0
  __int64 v28; // x3
  __int64 v29; // x0
  __int64 v30; // x0
  __int64 v31; // x0
  __int64 v32; // x8
  __int64 v33; // x3
  unsigned int v34; // w9
  __int64 v35; // x3
  __int64 v36; // x3
  __int64 v37; // x3
  __int64 v38; // [xsp+0h] [xbp-30h] BYREF
  __int64 v39; // [xsp+8h] [xbp-28h]
  __int64 v40; // [xsp+10h] [xbp-20h]
  __int64 v41; // [xsp+18h] [xbp-18h]
  __int64 v42; // [xsp+20h] [xbp-10h]
  __int64 v43; // [xsp+28h] [xbp-8h]

  v13 = a2;
  v43 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = *(_QWORD *)(a1 + 1128);
  v41 = 0;
  v42 = 0;
  v39 = 0;
  v40 = 0;
  v15 = *(unsigned __int8 *)(v14 + 74576);
  v16 = *(_DWORD *)(a2 + 408);
  v38 = 0;
  if ( v15 )
  {
    if ( (v16 != 1 || !*(_QWORD *)(a2 + 416)) && *(__int16 *)(a2 + 16) != -1 )
    {
      v17 = 0;
      v18 = 56;
      while ( 1 )
      {
        if ( ((a3 >> v17) & 1) != 0 )
        {
          if ( *(_QWORD *)(*(_QWORD *)(a2 + 88) + v18) )
          {
            if ( !a3 )
            {
              qdf_trace_msg(
                0x81u,
                2u,
                "%s: tid_bitmap=0. All tids setup fail",
                a6,
                a7,
                a8,
                a9,
                a10,
                a11,
                a12,
                a13,
                "dp_peer_rx_reorder_queue_setup_be");
              goto LABEL_25;
            }
          }
          else
          {
            a3 &= ~(unsigned int)(1LL << v17);
          }
        }
        ++v17;
        v18 += 144;
        if ( v17 == 17 )
          goto LABEL_21;
      }
    }
    qdf_trace_msg(
      0x81u,
      8u,
      "%s: Invalid peer id for dp_peer:%pK",
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      "dp_peer_rx_reorder_queue_setup_be",
      a2,
      v38);
LABEL_21:
    result = 0;
    goto LABEL_62;
  }
  v19 = a1;
  if ( v16 == 1 )
  {
    v28 = a5 & 1;
    if ( *(_BYTE *)(a1 + 20100) == 1 )
      result = dp_peer_rx_reorder_multi_q_setup(a2, a3, a4, v28);
    else
      result = dp_peer_rx_reorder_q_setup_per_tid(a2, a3, a4, v28);
  }
  else
  {
    if ( v16 == 2 )
    {
      v20 = a3;
      qdf_mem_set(&v38, 0x28u, 0);
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v13 + 480);
        if ( !*(_BYTE *)(v13 + 437) )
          goto LABEL_28;
      }
      else
      {
        raw_spin_lock_bh(v13 + 480);
        *(_QWORD *)(v13 + 488) |= 1uLL;
        if ( !*(_BYTE *)(v13 + 437) )
          goto LABEL_28;
      }
      v24 = dp_peer_find_hash_find(v19, (int)v13 + 428);
      if ( v24 )
      {
        v25 = 1;
        v38 = v24;
LABEL_29:
        if ( *(_BYTE *)(v13 + 449) )
        {
          v29 = dp_peer_find_hash_find(v19, (int)v13 + 440);
          if ( v29 )
            *(&v38 + v25++) = v29;
        }
        if ( *(_BYTE *)(v13 + 461) )
        {
          v30 = dp_peer_find_hash_find(v19, (int)v13 + 452);
          if ( v30 )
            *(&v38 + v25++) = v30;
        }
        if ( *(_BYTE *)(v13 + 473) )
        {
          v31 = dp_peer_find_hash_find(v19, (int)v13 + 464);
          if ( v31 )
            *(&v38 + v25++) = v31;
        }
        v32 = *(_QWORD *)(v13 + 488);
        if ( (v32 & 1) != 0 )
          goto LABEL_88;
        raw_spin_unlock(v13 + 480);
        LOBYTE(v42) = v25;
        if ( !v25 )
          goto LABEL_21;
        while ( 1 )
        {
          v13 = 20100;
          v33 = a5 & 1;
          if ( (*(_BYTE *)(v19 + 20100) & 1) != 0 )
          {
            result = dp_peer_rx_reorder_multi_q_setup(v38, v20, a4, v33);
            v34 = (unsigned __int8)v42;
            if ( (_DWORD)result )
              goto LABEL_49;
          }
          else
          {
            result = dp_peer_rx_reorder_q_setup_per_tid(v38, v20, a4, v33);
            v34 = (unsigned __int8)v42;
            if ( (_DWORD)result )
              goto LABEL_49;
          }
          if ( v34 < 2 )
            goto LABEL_74;
          v35 = a5 & 1;
          if ( (*(_BYTE *)(v19 + 20100) & 1) != 0 )
            result = dp_peer_rx_reorder_multi_q_setup(v39, v20, a4, v35);
          else
            result = dp_peer_rx_reorder_q_setup_per_tid(v39, v20, a4, v35);
          v34 = (unsigned __int8)v42;
          if ( (_DWORD)result )
            goto LABEL_49;
          if ( (unsigned __int8)v42 < 3u )
            goto LABEL_74;
          v36 = a5 & 1;
          result = (*(_BYTE *)(v19 + 20100) & 1) != 0
                 ? dp_peer_rx_reorder_multi_q_setup(v40, v20, a4, v36)
                 : dp_peer_rx_reorder_q_setup_per_tid(v40, v20, a4, v36);
          v34 = (unsigned __int8)v42;
          if ( (_DWORD)result )
            goto LABEL_49;
          if ( (unsigned __int8)v42 < 4u )
            goto LABEL_74;
          v37 = a5 & 1;
          result = (*(_BYTE *)(v19 + 20100) & 1) != 0
                 ? dp_peer_rx_reorder_multi_q_setup(v41, v20, a4, v37)
                 : dp_peer_rx_reorder_q_setup_per_tid(v41, v20, a4, v37);
          v34 = (unsigned __int8)v42;
          if ( (_DWORD)result )
          {
LABEL_49:
            if ( !v34 )
              goto LABEL_62;
            v19 = (unsigned int)result;
            if ( v38 )
            {
              dp_peer_unref_delete(v38, 7);
              v34 = (unsigned __int8)v42;
              result = (unsigned int)v19;
            }
            v38 = 0;
            if ( v34 < 2 )
              goto LABEL_62;
            if ( v39 )
            {
              dp_peer_unref_delete(v39, 7);
              v34 = (unsigned __int8)v42;
              result = (unsigned int)v19;
            }
            v39 = 0;
            if ( v34 < 3 )
              goto LABEL_62;
            if ( v40 )
            {
              dp_peer_unref_delete(v40, 7);
              v34 = (unsigned __int8)v42;
              result = (unsigned int)v19;
            }
            v40 = 0;
            if ( v34 < 4 )
              goto LABEL_62;
            v32 = v41;
            if ( v41 )
            {
              dp_peer_unref_delete(v41, 7);
              v34 = (unsigned __int8)v42;
              result = (unsigned int)v19;
            }
            v41 = 0;
            if ( v34 <= 4 )
              goto LABEL_62;
            goto LABEL_87;
          }
          if ( (unsigned __int8)v42 <= 4u )
          {
LABEL_74:
            if ( !v34 )
              goto LABEL_21;
            if ( v38 )
            {
              dp_peer_unref_delete(v38, 7);
              v34 = (unsigned __int8)v42;
            }
            v38 = 0;
            if ( v34 < 2 )
              goto LABEL_21;
            if ( v39 )
            {
              dp_peer_unref_delete(v39, 7);
              v34 = (unsigned __int8)v42;
            }
            v39 = 0;
            if ( v34 < 3 )
              goto LABEL_21;
            if ( v40 )
            {
              dp_peer_unref_delete(v40, 7);
              v34 = (unsigned __int8)v42;
            }
            v40 = 0;
            if ( v34 < 4 )
              goto LABEL_21;
            if ( v41 )
            {
              dp_peer_unref_delete(v41, 7);
              v34 = (unsigned __int8)v42;
            }
            v41 = 0;
            if ( v34 <= 4 )
              goto LABEL_21;
          }
LABEL_87:
          __break(0x5512u);
LABEL_88:
          *(_QWORD *)(v13 + 488) = v32 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(v13 + 480);
          LOBYTE(v42) = v25;
          if ( !v25 )
            goto LABEL_21;
        }
      }
LABEL_28:
      v25 = 0;
      goto LABEL_29;
    }
    qdf_trace_msg(
      0x81u,
      2u,
      "%s: invalid peer type %d",
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      "dp_peer_rx_reorder_queue_setup_be",
      v16);
LABEL_25:
    result = 16;
  }
LABEL_62:
  _ReadStatusReg(SP_EL0);
  return result;
}
