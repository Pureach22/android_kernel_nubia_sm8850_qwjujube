__int64 __fastcall dp_rx_delba_ind_handler(__int64 a1, unsigned __int16 a2, unsigned int a3, unsigned __int16 a4)
{
  __int64 ref_by_id_3; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  unsigned int v17; // w22
  __int64 v18; // x25
  __int64 v19; // x24
  unsigned __int64 StatusReg; // x8
  __int64 v21; // x8
  __int16 v22; // w9
  _DWORD *v23; // x9
  __int64 v24; // x10
  __int64 v25; // x4
  __int64 v26; // x1
  __int64 v27; // x0
  unsigned int v28; // w19
  __int64 v29; // x20
  __int64 v31; // x24
  __int64 v32; // x0

  ref_by_id_3 = dp_peer_get_ref_by_id_3(a1, a2, 0xDu);
  if ( ref_by_id_3 )
  {
    v17 = (unsigned __int8)a3;
    if ( (unsigned __int8)a3 >= 0x11u )
    {
      v31 = ref_by_id_3;
      v32 = printk(
              &unk_9BB309,
              "tid < 17",
              "dp_rx_delba_ind_handler",
              "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_rx_tid.c");
      dump_stack(v32);
      ref_by_id_3 = v31;
    }
    v18 = *(_QWORD *)(ref_by_id_3 + 88) + 144LL * (unsigned __int8)a3;
    if ( *(_QWORD *)(v18 + 32) )
    {
      if ( !*(_BYTE *)(v18 + 108) )
      {
        v19 = ref_by_id_3;
        qdf_trace_msg(
          0x81u,
          5u,
          "%s: %pK: PEER_ID: %d TID: %d, BA win: %d ",
          v9,
          v10,
          v11,
          v12,
          v13,
          v14,
          v15,
          v16,
          "dp_rx_delba_ind_handler",
          a1,
          a2,
          (unsigned __int8)a3,
          a4);
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
          || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(v18 + 88);
          v21 = *(_QWORD *)(v18 + 96);
        }
        else
        {
          raw_spin_lock_bh(v18 + 88);
          v21 = *(_QWORD *)(v18 + 96) | 1LL;
          *(_QWORD *)(v18 + 96) = v21;
        }
        *(_BYTE *)(v18 + 108) = 1;
        v22 = a4 >= 0x3Fu ? 63 : a4;
        *(_WORD *)(v18 + 122) = v22;
        *(_BYTE *)(v18 + 120) = 38;
        if ( (v21 & 1) != 0 )
        {
          *(_QWORD *)(v18 + 96) = v21 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(v18 + 88);
        }
        else
        {
          raw_spin_unlock(v18 + 88);
        }
        ref_by_id_3 = v19;
        v23 = *(_DWORD **)(*(_QWORD *)(a1 + 8) + 168LL);
        if ( v23 )
        {
          v24 = *(_QWORD *)(v19 + 24);
          v25 = *(unsigned __int8 *)(v18 + 120);
          v26 = *(unsigned __int8 *)(v24 + 59);
          v27 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v24 + 24) + 8LL) + 16LL);
          if ( *(v23 - 1) != -1677196783 )
            __break(0x8229u);
          ((void (__fastcall *)(__int64, __int64, __int64, _QWORD, __int64, _QWORD))v23)(v27, v26, v19 + 44, a3, v25, 0);
          ref_by_id_3 = v19;
        }
      }
      v28 = 0;
    }
    else
    {
      v29 = ref_by_id_3;
      qdf_trace_msg(
        0x81u,
        2u,
        "%s: %pK: BA session is not setup for TID:%d ",
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        "dp_rx_delba_ind_handler",
        a1,
        v17);
      ref_by_id_3 = v29;
      v28 = 16;
    }
    dp_peer_unref_delete(ref_by_id_3, 0xDu, v9, v10, v11, v12, v13, v14, v15, v16);
  }
  else
  {
    qdf_trace_msg(
      0x81u,
      2u,
      "%s: %pK: Couldn't find peer from ID %d",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "dp_rx_delba_ind_handler",
      a1,
      a2);
    return 16;
  }
  return v28;
}
