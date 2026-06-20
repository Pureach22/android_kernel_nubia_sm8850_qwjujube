__int64 __fastcall ucfg_dp_destroy_intf(__int64 a1, unsigned __int8 *a2)
{
  __int64 context; // x19
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x4
  __int64 v13; // x5
  __int64 v14; // x6
  __int64 v15; // x7
  __int64 intf_by_macaddr; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x20
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  unsigned __int64 StatusReg; // x8
  __int64 v43; // x0
  unsigned __int64 v44; // x8
  unsigned __int64 v45; // x9
  __int64 v46; // x8
  __int64 v48; // x4
  __int64 v49; // x5
  __int64 v50; // x6
  __int64 v51; // x7

  context = dp_get_context();
  if ( a2 )
  {
    v12 = *a2;
    v13 = a2[1];
    v14 = a2[2];
    v15 = a2[5];
  }
  else
  {
    v14 = 0;
    v12 = 0;
    v13 = 0;
    v15 = 0;
  }
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: DP interface destroy addr:%02x:%02x:%02x:**:**:%02x",
    v4,
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    "ucfg_dp_destroy_intf",
    v12,
    v13,
    v14,
    v15);
  intf_by_macaddr = dp_get_intf_by_macaddr(context, (__int64)a2);
  if ( intf_by_macaddr )
  {
    v25 = intf_by_macaddr;
    if ( *(_DWORD *)(intf_by_macaddr + 28) == 1 )
      dp_config_direct_link(intf_by_macaddr, 0, 0, v17, v18, v19, v20, v21, v22, v23, v24);
    v26 = dp_nud_deinit_tracking(v25);
    dp_mic_deinit_work(v25, v26, v27, v28, v29, v30, v31, v32, v33);
    if ( *(_DWORD *)(v25 + 3704) )
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: list length not equal to zero",
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        "qdf_list_destroy");
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(context + 264);
    }
    else
    {
      raw_spin_lock_bh(context + 264);
      *(_QWORD *)(context + 272) |= 1uLL;
    }
    v43 = qdf_list_remove_node(context + 280, (_QWORD *)(v25 + 32));
    *(_QWORD *)(context + (((unsigned __int64)*(unsigned __int8 *)(v25 + 48) >> 3) & 0x18) + 360) &= ~(1LL << *(_BYTE *)(v25 + 48));
    v44 = *(unsigned __int8 *)(v25 + 48);
    if ( v44 > 5 )
    {
      __break(0x5512u);
      return ucfg_dp_set_cmn_dp_handle(v43);
    }
    else
    {
      v45 = context + 8 * v44;
      v46 = *(_QWORD *)(context + 272);
      *(_QWORD *)(v45 + 304) = 0;
      if ( (v46 & 1) != 0 )
      {
        *(_QWORD *)(context + 272) = v46 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(context + 264);
      }
      else
      {
        raw_spin_unlock(context + 264);
      }
      _qdf_mem_free(v25);
      return 0;
    }
  }
  else
  {
    if ( a2 )
    {
      v48 = *a2;
      v49 = a2[1];
      v50 = a2[2];
      v51 = a2[5];
    }
    else
    {
      v50 = 0;
      v48 = 0;
      v49 = 0;
      v51 = 0;
    }
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: DP interface not found addr:%02x:%02x:%02x:**:**:%02x",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "ucfg_dp_destroy_intf",
      v48,
      v49,
      v50,
      v51);
    return 16;
  }
}
