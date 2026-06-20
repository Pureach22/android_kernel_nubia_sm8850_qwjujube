__int64 __fastcall wma_mcc_vdev_tx_pause_evt_handler(
        __int64 a1,
        __int64 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _QWORD *context; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  _QWORD *v21; // x20
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v31; // x24
  unsigned int v32; // w27
  __int64 v33; // x25
  unsigned int v34; // w21
  bool v35; // cc
  int v36; // w4
  __int64 v37; // x8
  _DWORD *v38; // x8
  __int64 v39; // x8
  _QWORD *v40; // x0
  __int64 v41; // x1
  __int64 v42; // x3
  _QWORD *v43; // x0
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  __int64 v52; // x8
  __int64 v53; // x5
  _QWORD *v54; // x0
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  __int64 v63; // x8
  _QWORD *v64; // x0
  __int64 v65; // x8
  int v66; // w22
  _QWORD *v67; // x0
  __int64 v68; // x8
  __int64 v69; // x8
  _DWORD *v70; // x8
  __int64 v71; // x3
  int v72; // w22
  _QWORD *v73; // x0
  __int64 v74; // x8
  __int64 v75; // x8

  context = _cds_get_context(71, (__int64)"wma_mcc_vdev_tx_pause_evt_handler", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( a2 )
  {
    v21 = context;
    if ( (ucfg_pmo_get_wow_bus_suspend(*(_QWORD *)(a1 + 24)) & 1) != 0 )
    {
      qdf_trace_msg(
        0x36u,
        8u,
        "%s: Suspend is in progress: Pause/Unpause Tx is NoOp",
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        "wma_mcc_vdev_tx_pause_evt_handler");
      return 0;
    }
    if ( v21 )
    {
      v31 = *a2;
      v32 = *(_DWORD *)(*a2 + 12);
      if ( !v32 )
        return 0;
      v33 = 0;
      v34 = 0;
      while ( 1 )
      {
        if ( *(unsigned __int16 *)(a1 + 162) <= (unsigned int)(unsigned __int16)v34 )
          return 0;
        if ( (v32 & 1) != 0 )
        {
          if ( *(_QWORD *)(*(_QWORD *)(a1 + 520) + v33) )
          {
            v36 = *(_DWORD *)(v31 + 8);
            if ( v36 != 1 )
            {
              if ( v36 )
              {
                qdf_trace_msg(
                  0x36u,
                  2u,
                  "%s: Not Valid Action Type %d",
                  v22,
                  v23,
                  v24,
                  v25,
                  v26,
                  v27,
                  v28,
                  v29,
                  "wma_process_vdev_tx_pause_evt");
                goto LABEL_31;
              }
              if ( *(_DWORD *)(v31 + 4) == 9 )
              {
                if ( !*v21 )
                {
                  qdf_trace_msg(
                    0x89u,
                    8u,
                    "%s: invalid instance",
                    v22,
                    v23,
                    v24,
                    v25,
                    v26,
                    v27,
                    v28,
                    v29,
                    "cdp_fc_vdev_pause");
                  goto LABEL_31;
                }
                v37 = *(_QWORD *)(*v21 + 120LL);
                if ( !v37 )
                  goto LABEL_31;
                v38 = *(_DWORD **)(v37 + 48);
                if ( !v38 )
                  goto LABEL_31;
LABEL_27:
                v40 = v21;
                v41 = v34;
                v42 = 9;
                if ( *(v38 - 1) != 875705606 )
                  __break(0x8228u);
LABEL_29:
                ((void (__fastcall *)(_QWORD *, __int64, __int64, __int64))v38)(v40, v41, 1, v42);
                goto LABEL_31;
              }
              v54 = _cds_get_context(54, (__int64)"wma_vdev_get_pause_bitmap", v22, v23, v24, v25, v26, v27, v28, v29);
              if ( v54 )
              {
                v63 = v54[65];
                if ( v63 + v33 )
                {
                  if ( !*(_WORD *)(v63 + v33 + 238) )
                    goto LABEL_49;
LABEL_56:
                  v72 = *(_DWORD *)(v31 + 4);
                  v73 = _cds_get_context(54, (__int64)"wma_vdev_set_pause_bit", v55, v56, v57, v58, v59, v60, v61, v62);
                  if ( v73 )
                  {
                    v74 = v73[65];
                    if ( v74 + v33 )
                      *(_WORD *)(v74 + v33 + 238) |= 1 << v72;
                    else
                      qdf_trace_msg(
                        0x36u,
                        2u,
                        "%s: Interface is NULL",
                        v22,
                        v23,
                        v24,
                        v25,
                        v26,
                        v27,
                        v28,
                        v29,
                        "wma_vdev_set_pause_bit");
                  }
                  goto LABEL_31;
                }
                qdf_trace_msg(
                  0x36u,
                  2u,
                  "%s: Interface is NULL",
                  v55,
                  v56,
                  v57,
                  v58,
                  v59,
                  v60,
                  v61,
                  v62,
                  "wma_vdev_get_pause_bitmap");
              }
LABEL_49:
              if ( *v21 )
              {
                v69 = *(_QWORD *)(*v21 + 120LL);
                if ( v69 )
                {
                  v70 = *(_DWORD **)(v69 + 48);
                  if ( v70 )
                  {
                    v71 = *(unsigned int *)(v31 + 4);
                    if ( *(v70 - 1) != 875705606 )
                      __break(0x8228u);
                    ((void (__fastcall *)(_QWORD *, _QWORD, __int64, __int64))v70)(v21, v34, 1, v71);
                  }
                }
              }
              else
              {
                qdf_trace_msg(
                  0x89u,
                  8u,
                  "%s: invalid instance",
                  v55,
                  v56,
                  v57,
                  v58,
                  v59,
                  v60,
                  v61,
                  v62,
                  "cdp_fc_vdev_pause");
              }
              goto LABEL_56;
            }
            if ( *(_DWORD *)(v31 + 4) == 9 )
            {
              if ( *v21 )
              {
                v39 = *(_QWORD *)(*v21 + 120LL);
                if ( !v39 )
                  goto LABEL_31;
                v38 = *(_DWORD **)(v39 + 56);
                if ( !v38 )
                  goto LABEL_31;
                goto LABEL_27;
              }
              goto LABEL_69;
            }
            v64 = _cds_get_context(54, (__int64)"wma_vdev_get_pause_bitmap", v22, v23, v24, v25, v26, v27, v28, v29);
            if ( !v64 )
              goto LABEL_31;
            v65 = v64[65];
            if ( !(v65 + v33) )
            {
              qdf_trace_msg(
                0x36u,
                2u,
                "%s: Interface is NULL",
                v22,
                v23,
                v24,
                v25,
                v26,
                v27,
                v28,
                v29,
                "wma_vdev_get_pause_bitmap");
              goto LABEL_31;
            }
            if ( *(_WORD *)(v65 + v33 + 238) )
            {
              v66 = *(_DWORD *)(v31 + 4);
              v67 = _cds_get_context(54, (__int64)"wma_vdev_clear_pause_bit", v22, v23, v24, v25, v26, v27, v28, v29);
              if ( v67 )
              {
                v68 = v67[65];
                if ( v68 + v33 )
                  *(_WORD *)(v68 + v33 + 238) &= ~(1 << v66);
                else
                  qdf_trace_msg(
                    0x36u,
                    2u,
                    "%s: Interface is NULL",
                    v22,
                    v23,
                    v24,
                    v25,
                    v26,
                    v27,
                    v28,
                    v29,
                    "wma_vdev_clear_pause_bit");
              }
              if ( !*(_WORD *)(*(_QWORD *)(a1 + 520) + v33 + 238) )
              {
                if ( *v21 )
                {
                  v75 = *(_QWORD *)(*v21 + 120LL);
                  if ( !v75 )
                    goto LABEL_31;
                  v38 = *(_DWORD **)(v75 + 56);
                  if ( !v38 )
                    goto LABEL_31;
                  v42 = *(unsigned int *)(v31 + 4);
                  v40 = v21;
                  v41 = v34;
                  if ( *(v38 - 1) != 875705606 )
                    __break(0x8228u);
                  goto LABEL_29;
                }
LABEL_69:
                qdf_trace_msg(
                  0x89u,
                  8u,
                  "%s: invalid instance",
                  v22,
                  v23,
                  v24,
                  v25,
                  v26,
                  v27,
                  v28,
                  v29,
                  "cdp_fc_vdev_unpause");
              }
            }
LABEL_31:
            v43 = _cds_get_context(54, (__int64)"wma_vdev_get_pause_bitmap", v22, v23, v24, v25, v26, v27, v28, v29);
            if ( v43 )
            {
              v52 = v43[65];
              if ( v52 + v33 )
              {
                v53 = *(unsigned __int16 *)(v52 + v33 + 238);
LABEL_36:
                qdf_trace_msg(
                  0x36u,
                  8u,
                  "%s: vdev_id %d, pause_map 0x%x, pause type %d, action %d",
                  v44,
                  v45,
                  v46,
                  v47,
                  v48,
                  v49,
                  v50,
                  v51,
                  "wma_mcc_vdev_tx_pause_evt_handler",
                  v34,
                  v53,
                  *(unsigned int *)(v31 + 4),
                  *(unsigned int *)(v31 + 8));
                goto LABEL_11;
              }
              qdf_trace_msg(
                0x36u,
                2u,
                "%s: Interface is NULL",
                v44,
                v45,
                v46,
                v47,
                v48,
                v49,
                v50,
                v51,
                "wma_vdev_get_pause_bitmap");
            }
            v53 = 0;
            goto LABEL_36;
          }
          qdf_trace_msg(
            0x36u,
            2u,
            "%s: vdev is NULL for %d",
            v22,
            v23,
            v24,
            v25,
            v26,
            v27,
            v28,
            v29,
            "wma_mcc_vdev_tx_pause_evt_handler",
            v34);
        }
LABEL_11:
        v35 = v32 > 1;
        ++v34;
        v33 += 488;
        v32 >>= 1;
        if ( !v35 )
          return 0;
      }
    }
  }
  else
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Invalid roam event buffer",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "wma_mcc_vdev_tx_pause_evt_handler");
  }
  return 4294967274LL;
}
