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
  _QWORD *v12; // x25
  _QWORD *v13; // x26
  __int64 v14; // x27
  __int64 v16; // x21
  __int64 v17; // x22
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
  __int64 v38; // x24
  unsigned __int8 v39; // w23
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  const char *v48; // x2
  __int64 v49; // x4
  unsigned __int64 v50; // x8
  unsigned __int64 v51; // x8
  void (*v52)(void); // x8
  __int64 v53; // x8
  __int64 v54; // x8
  __int64 v55; // x20
  unsigned __int64 StatusReg; // x8
  __int64 v57; // x21
  unsigned int v58; // w8
  unsigned int v61; // w10
  unsigned int *v62; // x8
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  double v71; // d0
  double v72; // d1
  double v73; // d2
  double v74; // d3
  double v75; // d4
  double v76; // d5
  double v77; // d6
  double v78; // d7
  __int64 v79; // x8
  double v80; // d0
  double v81; // d1
  double v82; // d2
  double v83; // d3
  double v84; // d4
  double v85; // d5
  double v86; // d6
  double v87; // d7
  unsigned int v90; // w9
  __int64 v91; // x8
  unsigned int v98; // w8
  unsigned int v99; // w8
  unsigned __int8 v100[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v101; // [xsp+8h] [xbp-8h]

  v16 = a3;
  v17 = a2;
  v101 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v19 = *(_QWORD *)(a1 + 8);
  v100[0] = 6;
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
    goto LABEL_17;
  }
  v28 = *(_DWORD **)(v19 + 1888);
  ++*(_WORD *)(v19 + 12930);
  if ( *(v28 - 1) != -1613044571 )
    __break(0x822Au);
  result = ((__int64 (__fastcall *)(__int64, _QWORD, unsigned __int8 *, __int64))v28)(v19, (unsigned int)v17, v100, 30);
  if ( (result & 1) == 0 )
  {
    if ( v100[0] >= 6u )
      v38 = a4;
    else
      v38 = v100[0];
    if ( v100[0] >= 6u )
      v39 = v17;
    else
      v39 = v100[0];
    if ( (unsigned __int8)v38 >= 7u )
      goto LABEL_69;
    v17 = v19 + 296LL * (unsigned __int8)v38;
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
      *(unsigned int *)(v17 + 2368));
    if ( *(_DWORD *)(v17 + 2368) == 6 )
    {
      v48 = "%s: flow pool id: %d is inactive, ignore unmap";
      v49 = (unsigned __int8)v38;
LABEL_16:
      result = qdf_trace_msg(
                 0x45u,
                 2u,
                 v48,
                 v40,
                 v41,
                 v42,
                 v43,
                 v44,
                 v45,
                 v46,
                 v47,
                 "dp_tx_flow_pool_unmap_handler",
                 v49);
      goto LABEL_17;
    }
    if ( (_BYTE)v16 )
    {
      v48 = "%s: flow type %d not supported !!!";
      v49 = (unsigned __int8)v16;
      goto LABEL_16;
    }
    if ( v39 >= 6u )
    {
LABEL_69:
      __break(0x5512u);
    }
    else
    {
      v12 = *(_QWORD **)(a1 + 8);
      v38 = v39;
      v13 = v12 + 2807;
      v16 = v12[v39 + 2807];
      if ( (wlan_cfg_get_dp_tx_page_pool_enabled(v12[5]) & 1) == 0 )
      {
LABEL_41:
        v55 = *(_QWORD *)(a1 + 8);
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
          || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(v55 + 18984);
        }
        else
        {
          raw_spin_lock_bh(v55 + 18984);
          *(_QWORD *)(v55 + 18992) |= 1uLL;
        }
        v57 = *(_QWORD *)(v55 + 8 * v38 + 12960);
        if ( v57 )
        {
          v58 = *(_DWORD *)(v57 + 43384);
          while ( v58 )
          {
            _X12 = (unsigned int *)(v57 + 43384);
            __asm { PRFM            #0x11, [X12] }
            while ( 1 )
            {
              v61 = __ldxr(_X12);
              if ( v61 != v58 )
                break;
              if ( !__stlxr(v58 + 1, _X12) )
              {
                __dmb(0xBu);
                break;
              }
            }
            _ZF = v61 == v58;
            v58 = v61;
            if ( _ZF )
            {
              _X8 = (unsigned int *)(v57 + 43416);
              __asm { PRFM            #0x11, [X8] }
              do
                v90 = __ldxr(_X8);
              while ( __stxr(v90 + 1, _X8) );
              v91 = *(_QWORD *)(v55 + 18992);
              if ( (v91 & 1) != 0 )
              {
                *(_QWORD *)(v55 + 18992) = v91 & 0xFFFFFFFFFFFFFFFELL;
                raw_spin_unlock_bh(v55 + 18984);
              }
              else
              {
                raw_spin_unlock(v55 + 18984);
              }
              *(_QWORD *)(v57 + 43256) = 0;
              dp_vdev_unref_delete(v55, v57, 7u, v62, v63, v64, v65, v66, v67, v68, v69, v70);
              goto LABEL_61;
            }
          }
        }
        v79 = *(_QWORD *)(v55 + 18992);
        if ( (v79 & 1) != 0 )
        {
          *(_QWORD *)(v55 + 18992) = v79 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(v55 + 18984);
        }
        else
        {
          raw_spin_unlock(v55 + 18984);
        }
        qdf_trace_msg(
          0x45u,
          2u,
          "%s: invalid vdev_id %d",
          v80,
          v81,
          v82,
          v83,
          v84,
          v85,
          v86,
          v87,
          "dp_tx_flow_pool_vdev_unmap",
          v39);
LABEL_61:
        result = dp_tx_delete_flow_pool(v19, v17 + 2304, v71, v72, v73, v74, v75, v76, v77, v78);
        goto LABEL_17;
      }
      v14 = 2813;
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (v50 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v50 + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(v50 + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v12 + 2813);
        if ( !v16 )
          goto LABEL_39;
      }
      else
      {
        raw_spin_lock_bh(v12 + 2813);
        v12[2814] |= 1uLL;
        if ( !v16 )
        {
LABEL_39:
          v13[v38] = 0;
          v54 = v12[2814];
          if ( (v54 & 1) != 0 )
          {
            v12[2814] = v54 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(&v12[v14]);
          }
          else
          {
            raw_spin_unlock(&v12[v14]);
          }
          goto LABEL_41;
        }
      }
      if ( *(_BYTE *)(v16 + 56) != 1 )
        goto LABEL_39;
      _X9 = (unsigned int *)(v16 + 60);
      __asm { PRFM            #0x11, [X9] }
      do
      {
        v98 = __ldxr(_X9);
        v99 = v98 - 1;
      }
      while ( __stlxr(v99, _X9) );
      __dmb(0xBu);
      if ( v99 )
        goto LABEL_39;
      if ( *(_BYTE *)(v16 + 56) != 1 )
      {
LABEL_38:
        _qdf_mem_free(v16);
        goto LABEL_39;
      }
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (v51 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v51 + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(v51 + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v16 + 40);
        if ( *(_QWORD *)v16 )
          goto LABEL_31;
        goto LABEL_35;
      }
    }
    raw_spin_lock_bh(v16 + 40);
    *(_QWORD *)(v16 + 48) |= 1uLL;
    if ( *(_QWORD *)v16 )
    {
LABEL_31:
      v52 = *(void (**)(void))(v12[1] + 272LL);
      if ( v52 )
      {
        if ( *((_DWORD *)v52 - 1) != 820154707 )
          __break(0x8228u);
        v52();
        *(_QWORD *)(v16 + 8) = 0;
        *(_QWORD *)(v16 + 16) = 0;
        *(_QWORD *)v16 = 0;
      }
    }
LABEL_35:
    v53 = *(_QWORD *)(v16 + 48);
    if ( (v53 & 1) != 0 )
    {
      *(_QWORD *)(v16 + 48) = v53 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v16 + 40);
    }
    else
    {
      raw_spin_unlock(v16 + 40);
    }
    *(_BYTE *)(v16 + 56) = 0;
    goto LABEL_38;
  }
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
