__int64 __fastcall wma_wait_tx_complete(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _QWORD *context; // x20
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  _QWORD *v21; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 result; // x0
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 v39; // x8
  _DWORD *v40; // x8
  unsigned int v41; // w21
  __int64 v42; // x1
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  unsigned int v51; // w23
  __int64 v52; // x8
  _DWORD *v53; // x8
  __int64 v54; // x1
  _QWORD v55[3]; // [xsp+8h] [xbp-28h] BYREF
  char v56[4]; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v57; // [xsp+28h] [xbp-8h]

  v57 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v56[0] = 0;
  memset(v55, 0, sizeof(v55));
  context = _cds_get_context(71, (__int64)"wma_wait_tx_complete", a3, a4, a5, a6, a7, a8, a9, a10);
  v21 = _cds_get_context(54, (__int64)"wma_is_vdev_valid", v13, v14, v15, v16, v17, v18, v19, v20);
  if ( !v21 )
    goto LABEL_26;
  if ( *((unsigned __int16 *)v21 + 81) <= a2 )
  {
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: vdev_id: %d is invalid, max_bssid: %d",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "wma_is_vdev_valid",
      a2);
    goto LABEL_26;
  }
  if ( (*(_BYTE *)(v21[65] + 488LL * a2 + 184) & 1) == 0 )
  {
LABEL_26:
    result = qdf_trace_msg(
               0x36u,
               2u,
               "%s: Vdev is not valid: %d",
               v22,
               v23,
               v24,
               v25,
               v26,
               v27,
               v28,
               v29,
               "wma_wait_tx_complete",
               a2);
    goto LABEL_27;
  }
  result = ucfg_mlme_get_delay_before_vdev_stop(*(_QWORD *)(a1 + 24), v56);
  if ( (_DWORD)result )
    result = qdf_trace_msg(
               0x36u,
               2u,
               "%s: Failed to get delay before vdev stop",
               v31,
               v32,
               v33,
               v34,
               v35,
               v36,
               v37,
               v38,
               "wma_wait_tx_complete");
  if ( !context || !*context )
  {
LABEL_28:
    result = qdf_trace_msg(
               0x89u,
               8u,
               "%s: Invalid Instance:",
               v31,
               v32,
               v33,
               v34,
               v35,
               v36,
               v37,
               v38,
               "cdp_txrx_get_pdev_param");
    goto LABEL_27;
  }
  v39 = *(_QWORD *)(*context + 8LL);
  if ( v39 )
  {
    v40 = *(_DWORD **)(v39 + 104);
    if ( v40 )
    {
      v41 = (unsigned __int8)v56[0];
      v42 = *(unsigned __int8 *)(*(_QWORD *)(a1 + 32) + 40LL);
      if ( *(v40 - 1) != 1753033934 )
        __break(0x8228u);
      result = ((__int64 (__fastcall *)(_QWORD *, __int64, __int64, _QWORD *))v40)(context, v42, 19, v55);
      if ( !(_DWORD)result && LODWORD(v55[0]) && v41 >= 2 )
      {
        v51 = v41 >> 1;
        while ( 1 )
        {
          qdf_trace_msg(
            0x36u,
            3u,
            "%s: Waiting for outstanding packet to drain",
            v43,
            v44,
            v45,
            v46,
            v47,
            v48,
            v49,
            v50,
            "wma_wait_tx_complete");
          result = qdf_wait_for_event_completion(a1 + 384, 2u);
          if ( !*context )
            goto LABEL_28;
          v52 = *(_QWORD *)(*context + 8LL);
          if ( v52 )
          {
            v53 = *(_DWORD **)(v52 + 104);
            if ( v53 )
            {
              v54 = *(unsigned __int8 *)(*(_QWORD *)(a1 + 32) + 40LL);
              if ( *(v53 - 1) != 1753033934 )
                __break(0x8228u);
              result = ((__int64 (__fastcall *)(_QWORD *, __int64, __int64, _QWORD *))v53)(context, v54, 19, v55);
              if ( !(_DWORD)result )
              {
                if ( LODWORD(v55[0]) )
                {
                  if ( (_BYTE)--v51 )
                    continue;
                }
              }
            }
          }
          break;
        }
      }
    }
  }
LABEL_27:
  _ReadStatusReg(SP_EL0);
  return result;
}
