__int64 __fastcall dp_service_srngs(
        unsigned __int8 *a1,
        int a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x21
  __int64 v12; // x10
  __int64 v13; // x11
  unsigned __int64 v15; // x24
  __int64 v16; // x8
  unsigned int v17; // w26
  unsigned int v18; // w23
  int v19; // w25
  int v20; // w22
  int v21; // w22
  unsigned __int64 v22; // x27
  __int64 v23; // x25
  __int64 v24; // x19
  unsigned int v25; // w28
  unsigned int v26; // w0
  unsigned int v28; // w0
  __int64 *v29; // x19
  _DWORD *v30; // x8
  __int64 v31; // x1
  unsigned int v32; // w0
  unsigned int v33; // w27
  __int64 v34; // x8
  int v36; // w19
  int v37; // w0
  unsigned int v38; // w25
  unsigned int v39; // w24
  unsigned __int64 v45; // x9
  unsigned __int64 v48; // x9
  __int64 v49; // [xsp+0h] [xbp-50h]
  __int64 v50; // [xsp+8h] [xbp-48h]
  __int64 v51; // [xsp+10h] [xbp-40h]
  __int64 v52; // [xsp+18h] [xbp-38h]
  int v53; // [xsp+24h] [xbp-2Ch]
  int v54; // [xsp+28h] [xbp-28h]
  int v55; // [xsp+2Ch] [xbp-24h]
  __int64 v56; // [xsp+38h] [xbp-18h]
  __int64 v57; // [xsp+40h] [xbp-10h]
  int v58; // [xsp+4Ch] [xbp-4h]

  v11 = *((_QWORD *)a1 + 2);
  v12 = a3 >> 6;
  v13 = 1LL << a3;
  v15 = 7200;
  v16 = v11 + 12944;
  v56 = v12;
  v57 = 1LL << a3;
LABEL_49:
  _X8 = (unsigned __int64 *)(v16 + 8 * v12);
  __asm { PRFM            #0x11, [X8] }
  do
  {
    v45 = __ldxr(_X8);
    v12 = __stxr(v45 | v13, _X8);
  }
  while ( (_DWORD)v12 );
  v17 = *a1;
  v18 = a1[1];
  v19 = a1[3];
  v20 = a1[5];
  v54 = a1[4];
  if ( is_dp_verbose_debug_enabled == 1 )
  {
    v36 = a2;
    LODWORD(v52) = a1[6];
    LODWORD(v51) = a1[7];
    LODWORD(v50) = a1[2];
    LODWORD(v49) = a1[5];
    qdf_trace_msg(
      0x45u,
      8u,
      "%s: tx %x rx %x rx_err %x rx_wbm_rel %x reo_status %x rx_mon_ring %x host2rxdma %x rxdma2host %x",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "dp_service_srngs",
      *a1,
      a1[1],
      a1[3],
      a1[4],
      v49,
      v50,
      v51,
      v52);
    a2 = v36;
  }
  v16 = *(unsigned __int8 *)(v11 + v15);
  v53 = v20;
  v21 = a2;
  v55 = v19;
  v58 = a2;
  if ( *(_BYTE *)(v11 + v15) )
  {
    v21 = a2;
    v22 = 0;
    v23 = 7368;
    v24 = 1;
    do
    {
      if ( ((v17 >> *(_BYTE *)(*(_QWORD *)(*(_QWORD *)(v11 + 40) + 776LL) + v24)) & 1) != 0 )
      {
        if ( v22 >= 5 )
        {
LABEL_48:
          __break(0x5512u);
          goto LABEL_49;
        }
        v25 = dp_tx_comp_handler(a1, v11, *(_QWORD *)(v11 + v23), (unsigned int)v22, (unsigned int)v21);
        if ( v25 )
        {
          ++*(_DWORD *)&a1[4 * v22 + 36];
          if ( is_dp_verbose_debug_enabled == 1 )
            qdf_trace_msg(
              0x45u,
              8u,
              "%s: tx mask 0x%x index %d, budget %d, work_done %d",
              a4,
              a5,
              a6,
              a7,
              a8,
              a9,
              a10,
              a11,
              "dp_service_srngs",
              v17,
              (unsigned int)v22,
              (unsigned int)v21,
              v25);
        }
        v21 -= v25;
        if ( v21 < 1 )
          goto LABEL_52;
        v16 = *(unsigned __int8 *)(v11 + v15);
      }
      ++v22;
      v23 += 80;
      v24 += 4;
    }
    while ( v22 < (unsigned int)v16 );
  }
  if ( !v55 )
    goto LABEL_57;
  v26 = dp_rx_err_process(a1, v11, *(_QWORD *)(v11 + 6400), (unsigned int)v21);
  if ( v26 )
  {
    _ZF = is_dp_verbose_debug_enabled == 1;
    ++*((_DWORD *)a1 + 23);
    if ( _ZF )
    {
      v38 = v26;
      qdf_trace_msg(
        0x45u,
        8u,
        "%s: REO Exception Ring: work_done %d budget %d",
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        "dp_service_srngs",
        v26,
        (unsigned int)v21);
      v26 = v38;
    }
  }
  v21 -= v26;
  if ( v21 >= 1 )
  {
LABEL_57:
    if ( !v54 )
      goto LABEL_58;
    v28 = dp_rx_wbm_err_process(a1, v11, *(_QWORD *)(v11 + 6720), (unsigned int)v21);
    if ( v28 )
    {
      _ZF = is_dp_verbose_debug_enabled == 1;
      ++*((_DWORD *)a1 + 24);
      if ( _ZF )
      {
        v39 = v28;
        qdf_trace_msg(
          0x45u,
          8u,
          "%s: WBM Release Ring: work_done %d budget %d",
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          a11,
          "dp_service_srngs",
          v28,
          (unsigned int)v21);
        v28 = v39;
      }
    }
    v21 -= v28;
    if ( v21 >= 1 )
    {
LABEL_58:
      if ( v18 && *(_BYTE *)(v11 + 12896) )
      {
        v15 = 0;
        v29 = (__int64 *)(v11 + 5760);
        while ( 1 )
        {
          v16 = v18 >> v15;
          if ( (v16 & 1) != 0 )
          {
            if ( v15 > 7 )
              goto LABEL_48;
            v30 = *(_DWORD **)(v11 + 1336);
            v31 = *v29;
            if ( *(v30 - 1) != 636479746 )
              __break(0x8228u);
            v32 = ((__int64 (__fastcall *)(unsigned __int8 *, __int64, _QWORD, _QWORD))v30)(
                    a1,
                    v31,
                    (unsigned int)v15,
                    (unsigned int)v21);
            if ( v32 )
            {
              ++*(_DWORD *)&a1[4 * v15 + 56];
              if ( is_dp_verbose_debug_enabled == 1 )
              {
                v33 = v32;
                qdf_trace_msg(
                  0x45u,
                  8u,
                  "%s: rx mask 0x%x ring %d, work_done %d budget %d",
                  a4,
                  a5,
                  a6,
                  a7,
                  a8,
                  a9,
                  a10,
                  a11,
                  "dp_service_srngs",
                  v18,
                  (unsigned int)v15,
                  v32,
                  (unsigned int)v21);
                v32 = v33;
              }
              v21 -= v32;
              if ( v21 < 1 )
                break;
            }
          }
          ++v15;
          v29 += 10;
          if ( v15 >= *(unsigned __int8 *)(v11 + 12896) )
            goto LABEL_37;
        }
      }
      else
      {
LABEL_37:
        if ( v53 && (unsigned int)dp_reo_status_ring_handler((__int64)a1, v11) )
          ++*((_DWORD *)a1 + 25);
        if ( v11 && (v34 = *(_QWORD *)(v11 + 20112)) != 0 && (*(_BYTE *)(v34 + 408) & 2) != 0
          || (v37 = dp_process_lmac_rings((__int64)a1, v21)) == 0
          || (v21 -= v37, v21 >= 1) )
        {
          ++*((_DWORD *)a1 + 46);
        }
      }
    }
  }
LABEL_52:
  _X8 = (unsigned __int64 *)(v11 + 12944 + 8 * v56);
  __asm { PRFM            #0x11, [X8] }
  do
    v48 = __ldxr(_X8);
  while ( __stxr(v48 & ~v57, _X8) );
  return (unsigned int)(v58 - v21);
}
