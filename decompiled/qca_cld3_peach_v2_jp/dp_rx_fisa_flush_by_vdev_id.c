__int64 __fastcall dp_rx_fisa_flush_by_vdev_id(__int64 a1, unsigned __int8 a2)
{
  __int64 v4; // x26
  __int64 v5; // x20
  __int64 v6; // x27
  __int64 ref_by_id_3; // x0
  unsigned __int64 v8; // x8
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x21
  __int64 v18; // x28
  unsigned __int64 StatusReg; // x22
  __int64 v20; // x24
  __int64 v21; // x0
  __int16 v22; // w9
  __int64 v23; // x0
  _QWORD *v24; // x25
  __int64 v25; // x8
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x8

  v4 = *(_QWORD *)(dp_get_context() + 1480);
  v5 = *(_QWORD *)v4;
  v6 = *(unsigned __int16 *)(v4 + 32);
  ref_by_id_3 = dp_vdev_get_ref_by_id_3(a1, a2);
  if ( ref_by_id_3 )
  {
    v17 = ref_by_id_3;
    if ( (_DWORD)v6 )
    {
      v18 = 0;
      StatusReg = _ReadStatusReg(SP_EL0);
      while ( 1 )
      {
        v8 = *(unsigned __int8 *)(v5 + 144);
        if ( v8 <= 7 )
          break;
LABEL_5:
        ++v18;
        v5 += 336;
        if ( v6 == v18 )
          goto LABEL_30;
      }
      v20 = v4 + 440 + 16 * v8;
      if ( *(_BYTE *)(v4 + 608) == 1 )
      {
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
          || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(v20);
        }
        else
        {
          raw_spin_lock_bh(v20);
          *(_QWORD *)(v20 + 8) |= 1uLL;
        }
      }
      v21 = *(_QWORD *)(v5 + 152);
      if ( v17 == v21 )
      {
        v22 = *(_WORD *)(v5 + 194);
        *(_WORD *)(v5 + 62) = *(_WORD *)(v5 + 56);
        *(_WORD *)(v5 + 64) = v22;
        dp_rx_fisa_flush_flow(v21, v5);
        *(_WORD *)(v5 + 60) = 0;
        if ( *(_BYTE *)(v4 + 609) == 1 && *(_BYTE *)(v4 + 608) == 1 )
        {
          v23 = _qdf_mem_malloc(0x60u, "dp_fisa_rx_fst_del_queue", 1479);
          if ( v23 )
          {
            *(_DWORD *)(v23 + 76) = v18;
            v24 = (_QWORD *)v23;
            *(_QWORD *)(v23 + 64) = v17;
            *(_BYTE *)(v23 + 74) = *(_BYTE *)(v17 + 59);
            *(_DWORD *)(v23 + 80) = 1;
            if ( (_ReadStatusReg(DAIF) & 0x80) != 0
              || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
              || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
            {
              raw_spin_lock(v4 + 48);
            }
            else
            {
              raw_spin_lock_bh(v4 + 48);
              *(_QWORD *)(v4 + 56) |= 1uLL;
            }
            qdf_list_insert_back((_QWORD *)(v4 + 408), v24);
            v25 = *(_QWORD *)(v4 + 56);
            if ( (v25 & 1) != 0 )
            {
              *(_QWORD *)(v4 + 56) = v25 & 0xFFFFFFFFFFFFFFFELL;
              raw_spin_unlock_bh(v4 + 48);
              if ( *(_DWORD *)(v4 + 612) )
                goto LABEL_22;
            }
            else
            {
              raw_spin_unlock(v4 + 48);
              if ( *(_DWORD *)(v4 + 612) )
              {
LABEL_22:
                *(_BYTE *)(v4 + 616) = 1;
                qdf_trace_msg(
                  0x45u,
                  5u,
                  "%s: defer fst update task in WoW",
                  v26,
                  v27,
                  v28,
                  v29,
                  v30,
                  v31,
                  v32,
                  v33,
                  "dp_fisa_rx_fst_del_queue");
                goto LABEL_26;
              }
            }
            queue_work_on(32, *(_QWORD *)(v4 + 400), v4 + 352);
          }
        }
      }
LABEL_26:
      v8 = *(unsigned __int8 *)(v4 + 608);
      if ( (_DWORD)v8 == 1 )
      {
        v34 = *(_QWORD *)(v20 + 8);
        if ( (v34 & 1) != 0 )
        {
          *(_QWORD *)(v20 + 8) = v34 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(v20);
        }
        else
        {
          raw_spin_unlock(v20);
        }
      }
      goto LABEL_5;
    }
LABEL_30:
    dp_vdev_unref_delete(a1, v17, 2u, (unsigned int *)v8, v9, v10, v11, v12, v13, v14, v15, v16);
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: null vdev by vdev_id %d",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "dp_rx_fisa_flush_by_vdev_id",
      a2);
    return 16;
  }
}
