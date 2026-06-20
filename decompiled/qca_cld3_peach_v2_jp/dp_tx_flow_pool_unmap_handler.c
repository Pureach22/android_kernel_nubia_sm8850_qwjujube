__int64 __fastcall dp_tx_flow_pool_unmap_handler(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        unsigned int a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v12; // x25
  _QWORD *v13; // x26
  __int64 v14; // x27
  __int64 v15; // x23
  __int64 v16; // x22
  unsigned int v17; // w21
  __int64 v19; // x19
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  _DWORD *v28; // x10
  __int64 result; // x0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  unsigned __int64 v38; // x24
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  const char *v47; // x2
  __int64 v48; // x4
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v50; // x8
  void (*v51)(void); // x8
  __int64 v52; // x8
  __int64 v53; // x8
  __int64 v54; // x20
  __int64 ref_by_id_5; // x0
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  unsigned int v78; // w8
  unsigned int v79; // w8
  unsigned __int8 v80[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v81; // [xsp+8h] [xbp-8h]

  v15 = a4;
  v16 = a3;
  v17 = a2;
  v81 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v19 = *(_QWORD *)(a1 + 8);
  v80[0] = 6;
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: flow_id %d flow_type %d flow_pool_id %d",
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    "dp_tx_flow_pool_unmap_handler",
    (unsigned __int8)a2,
    (unsigned __int8)a3,
    (unsigned __int8)a4);
  if ( !a1 )
  {
    result = qdf_trace_msg(
               0x45u,
               2u,
               "%s: pdev is NULL",
               v20,
               v21,
               v22,
               v23,
               v24,
               v25,
               v26,
               v27,
               "dp_tx_flow_pool_unmap_handler");
    goto LABEL_16;
  }
  v28 = *(_DWORD **)(v19 + 1840);
  ++*(_WORD *)(v19 + 12882);
  if ( *(v28 - 1) != -1613044571 )
    __break(0x822Au);
  result = ((__int64 (__fastcall *)(__int64, _QWORD, unsigned __int8 *, __int64))v28)(v19, v17, v80, 30);
  if ( (result & 1) == 0 )
  {
    if ( v80[0] >= 6u )
      v38 = (unsigned int)v15;
    else
      v38 = v80[0];
    if ( v80[0] < 6u )
      LOBYTE(v17) = v80[0];
    if ( (unsigned __int8)v38 >= 7u )
      goto LABEL_49;
    v15 = v19 + 296LL * (unsigned __int8)v38;
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: pool status: %d",
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      "dp_tx_flow_pool_unmap_handler",
      *(unsigned int *)(v15 + 2320));
    if ( *(_DWORD *)(v15 + 2320) == 6 )
    {
      v47 = "%s: flow pool id: %d is inactive, ignore unmap";
      v48 = (unsigned __int8)v38;
LABEL_15:
      result = qdf_trace_msg(
                 0x45u,
                 2u,
                 v47,
                 v39,
                 v40,
                 v41,
                 v42,
                 v43,
                 v44,
                 v45,
                 v46,
                 "dp_tx_flow_pool_unmap_handler",
                 v48);
      goto LABEL_16;
    }
    if ( (_BYTE)v16 )
    {
      v47 = "%s: flow type %d not supported !!!";
      v48 = (unsigned __int8)v16;
      goto LABEL_15;
    }
    if ( (unsigned __int8)v17 >= 6u )
    {
LABEL_49:
      __break(0x5512u);
    }
    else
    {
      v38 = *(_QWORD *)(a1 + 8);
      v12 = (unsigned __int8)v17;
      v13 = (_QWORD *)(v38 + 22400);
      v16 = *(_QWORD *)(v38 + 22400 + 8LL * (unsigned __int8)v17);
      if ( (wlan_cfg_get_dp_tx_page_pool_enabled(*(_QWORD *)(v38 + 40)) & 1) == 0 )
        goto LABEL_40;
      v14 = 22448;
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v38 + 22448);
        if ( !v16 )
          goto LABEL_38;
      }
      else
      {
        raw_spin_lock_bh(v38 + 22448);
        *(_QWORD *)(v38 + 22456) |= 1uLL;
        if ( !v16 )
        {
LABEL_38:
          v13[v12] = 0;
          v53 = *(_QWORD *)(v38 + 22456);
          if ( (v53 & 1) != 0 )
          {
            *(_QWORD *)(v38 + 22456) = v53 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(v38 + v14);
          }
          else
          {
            raw_spin_unlock(v38 + v14);
          }
LABEL_40:
          v54 = *(_QWORD *)(a1 + 8);
          ref_by_id_5 = dp_vdev_get_ref_by_id_5(v54, v17, 7u);
          if ( ref_by_id_5 )
          {
            *(_QWORD *)(ref_by_id_5 + 42432) = 0;
            dp_vdev_unref_delete(v54, ref_by_id_5, 7u, adrastea_hostdef, v56, v57, v58, v59, v60, v61, v62, v63);
          }
          else
          {
            qdf_trace_msg(
              0x45u,
              2u,
              "%s: invalid vdev_id %d",
              v56,
              v57,
              v58,
              v59,
              v60,
              v61,
              v62,
              v63,
              "dp_tx_flow_pool_vdev_unmap",
              (unsigned __int8)v17);
          }
          result = dp_tx_delete_flow_pool(v19, v15 + 2256, v64, v65, v66, v67, v68, v69, v70, v71);
          goto LABEL_16;
        }
      }
      if ( *(_BYTE *)(v16 + 56) != 1 )
        goto LABEL_38;
      _X9 = (unsigned int *)(v16 + 60);
      __asm { PRFM            #0x11, [X9] }
      do
      {
        v78 = __ldxr(_X9);
        v79 = v78 - 1;
      }
      while ( __stlxr(v79, _X9) );
      __dmb(0xBu);
      if ( v79 )
        goto LABEL_38;
      if ( *(_BYTE *)(v16 + 56) != 1 )
      {
LABEL_37:
        _qdf_mem_free(v16);
        goto LABEL_38;
      }
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (v50 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v50 + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(v50 + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v16 + 40);
        if ( *(_QWORD *)v16 )
          goto LABEL_30;
        goto LABEL_34;
      }
    }
    raw_spin_lock_bh(v16 + 40);
    *(_QWORD *)(v16 + 48) |= 1uLL;
    if ( *(_QWORD *)v16 )
    {
LABEL_30:
      v51 = *(void (**)(void))(*(_QWORD *)(v38 + 8) + 272LL);
      if ( v51 )
      {
        if ( *((_DWORD *)v51 - 1) != 820154707 )
          __break(0x8228u);
        v51();
        *(_QWORD *)(v16 + 8) = 0;
        *(_QWORD *)(v16 + 16) = 0;
        *(_QWORD *)v16 = 0;
      }
    }
LABEL_34:
    v52 = *(_QWORD *)(v16 + 48);
    if ( (v52 & 1) != 0 )
    {
      *(_QWORD *)(v16 + 48) = v52 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v16 + 40);
    }
    else
    {
      raw_spin_unlock(v16 + 40);
    }
    *(_BYTE *)(v16 + 56) = 0;
    goto LABEL_37;
  }
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
