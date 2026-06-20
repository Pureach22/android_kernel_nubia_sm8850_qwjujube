__int64 __fastcall dp_ipa_uc_attach(__int64 a1)
{
  __int64 v2; // x8
  __int64 v3; // x20
  __int64 v4; // x0
  __int64 v5; // x8
  unsigned int v6; // w21
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x23
  __int64 v16; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x8
  int v26; // w10
  int v27; // w9
  __int64 v28; // x10
  __int64 v30; // x0
  __int64 v31; // x8
  unsigned __int64 v32; // x13
  __int64 v33; // x10
  __int64 v34; // x8
  __int64 v35; // x1
  __int64 v41; // x22
  __int64 v42; // x27
  __int64 v43; // x0
  __int64 v44; // x8
  __int64 v45; // x24
  unsigned int v46; // w9
  __int64 v47; // x10
  __int64 v48; // x25
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  __int64 v57; // x8
  __int64 v58; // x26
  _DWORD *v59; // x8
  int v60; // w23
  unsigned int v61; // w21
  char v62; // w24
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  _DWORD *v71; // x2
  double v72; // d0
  double v73; // d1
  double v74; // d2
  double v75; // d3
  double v76; // d4
  double v77; // d5
  double v78; // d6
  double v79; // d7
  _QWORD v81[2]; // [xsp+0h] [xbp-60h] BYREF
  __int64 v82; // [xsp+10h] [xbp-50h]
  __int64 v83; // [xsp+18h] [xbp-48h]
  __int64 v84; // [xsp+20h] [xbp-40h]
  __int64 v85; // [xsp+28h] [xbp-38h]
  __int64 v86; // [xsp+30h] [xbp-30h]
  __int64 v87; // [xsp+38h] [xbp-28h]
  __int64 v88; // [xsp+40h] [xbp-20h]
  __int64 v89; // [xsp+48h] [xbp-18h]
  __int64 v90; // [xsp+50h] [xbp-10h]
  __int64 v91; // [xsp+58h] [xbp-8h]

  v91 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (wlan_cfg_is_ipa_enabled(*(_QWORD *)(a1 + 40)) & 1) == 0 )
    goto LABEL_36;
  v2 = *(_QWORD *)(a1 + 40);
  v3 = *(_QWORD *)(a1 + 7640);
  v89 = 0;
  v90 = 0;
  v4 = *(_QWORD *)(a1 + 1128);
  v5 = *(_QWORD *)(v2 + 776);
  v87 = 0;
  v88 = 0;
  v85 = 0;
  v86 = 0;
  v83 = 0;
  v84 = 0;
  v81[1] = 0;
  v82 = 0;
  v81[0] = 0;
  v6 = *(unsigned __int8 *)(v5 + 18);
  hal_get_srng_params(v4, v3, (__int64)v81);
  v15 = (int)v82;
  if ( (int)v82 - 16 <= 0 )
  {
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: incorrect value for buffer count %u",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "dp_tx_ipa_uc_attach");
    v61 = -22;
LABEL_39:
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: DP IPA UC TX attach fail code %d",
      v63,
      v64,
      v65,
      v66,
      v67,
      v68,
      v69,
      v70,
      "dp_ipa_uc_attach",
      v61);
    goto LABEL_40;
  }
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: requested %d buffers to be posted to wbm ring",
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    "dp_tx_ipa_uc_attach");
  v16 = _qdf_mem_malloc(8 * v15, "dp_tx_ipa_uc_attach", 1893);
  *(_QWORD *)(a1 + 18064) = v16;
  if ( !v16 )
  {
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: IPA WBM Ring Tx buf pool vaddr alloc fail",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "dp_tx_ipa_uc_attach");
LABEL_38:
    v61 = -12;
    goto LABEL_39;
  }
  v25 = *(_QWORD *)(a1 + 1128);
  v26 = *(_DWORD *)(v3 + 116);
  v27 = **(_DWORD **)(v3 + 128);
  *(_DWORD *)(v3 + 136) = v27;
  if ( v26 )
  {
    if ( (*(_BYTE *)(v3 + 78) & 4) != 0 )
    {
      v28 = *(unsigned int *)(v3 + 120);
      if ( (_DWORD)v28 != v27 )
      {
        _X22 = *(_QWORD *)(v3 + 16) + 4 * v28;
        if ( _X22 )
        {
          v30 = *(_QWORD *)(*(_QWORD *)(v25 + 8) + 40LL);
          if ( (*(_BYTE *)(v30 + 844) & 0x40) == 0 )
          {
            v31 = _X22 << 8 >> 8;
            v32 = (unsigned __int64)(v31 + 0x8000000000LL) >> 38;
            v33 = memstart_addr + v31 + 0x8000000000LL;
            v34 = v31 - kimage_voffset;
            if ( v32 )
              v35 = v34;
            else
              v35 = v33;
            _dma_sync_single_for_cpu(v30, v35);
          }
          __asm { PRFM            #0, [X22] }
        }
      }
    }
  }
  v41 = (unsigned int)(v15 - 17);
  if ( (_DWORD)v15 == 17 )
  {
LABEL_25:
    v60 = 0;
    v61 = 0;
    v62 = 1;
  }
  else
  {
    v42 = 0;
    while ( 1 )
    {
      v43 = _qdf_nbuf_frag_alloc(*(_QWORD *)(a1 + 24), 2055, 0, 256, 0, "dp_tx_ipa_uc_attach", 1912);
      if ( !v43 )
        goto LABEL_29;
      v44 = *(unsigned int *)(v3 + 136);
      v45 = v43;
      v46 = (unsigned int)(*(_DWORD *)(v3 + 44) + v44) % *(_DWORD *)(v3 + 36);
      if ( v46 == *(_DWORD *)(v3 + 120)
        || (v47 = *(_QWORD *)(v3 + 16), *(_DWORD *)(v3 + 136) = v46, (v48 = v47 + 4 * v44) == 0) )
      {
        qdf_trace_msg(
          0x45u,
          4u,
          "%s: Failed to get WBM ring entry",
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          "dp_tx_ipa_uc_attach");
        _qdf_nbuf_free(v45);
LABEL_29:
        v60 = 0;
        v61 = 0;
        v62 = 1;
        goto LABEL_30;
      }
      if ( (unsigned int)_qdf_nbuf_map_single(*(_QWORD *)(a1 + 24), v43, 0) )
        break;
      v57 = 80;
      if ( (*(_BYTE *)(v45 + 68) & 4) == 0 )
        v57 = 40;
      v58 = *(_QWORD *)(v45 + v57);
      qdf_mem_dp_tx_skb_cnt_inc();
      qdf_mem_dp_tx_skb_inc(*(unsigned int *)(v45 + 212));
      v59 = *(_DWORD **)(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 1472LL);
      if ( *(v59 - 1) != -1494657337 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v59)(v48, v58, 0, v6);
      *(_QWORD *)(*(_QWORD *)(a1 + 18064) + 8 * v42++) = v45;
      if ( v41 == v42 )
        goto LABEL_25;
    }
    qdf_trace_msg(0x45u, 2u, "%s: nbuf map failed", v49, v50, v51, v52, v53, v54, v55, v56, "dp_tx_ipa_uc_attach");
    _qdf_nbuf_free(v45);
    v62 = 0;
    v61 = -14;
    v60 = 1;
LABEL_30:
    LODWORD(v41) = v42;
  }
  v71 = *(_DWORD **)(v3 + 144);
  if ( (*(_DWORD *)(v3 + 76) & 0x80000000) != 0 )
    *v71 = *(_DWORD *)(v3 + 120);
  else
    hal_delayed_reg_write(*(_QWORD *)(a1 + 1128), (unsigned __int8 *)v3, (__int64)v71, *(_DWORD *)(v3 + 120));
  *(_DWORD *)(a1 + 18016) = v41;
  if ( !(_DWORD)v41 )
  {
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: No IPA WDI TX buffer allocated!",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "dp_tx_ipa_uc_attach");
    _qdf_mem_free(*(_QWORD *)(a1 + 18064));
    *(_QWORD *)(a1 + 18064) = 0;
    goto LABEL_38;
  }
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: IPA WDI TX buffer: %d allocated",
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    "dp_tx_ipa_uc_attach",
    (unsigned int)v41);
  if ( (v62 & 1) != 0 )
  {
LABEL_36:
    v61 = 0;
    goto LABEL_40;
  }
  qdf_trace_msg(
    0x45u,
    2u,
    "%s: DP IPA UC TX attach fail code %d",
    v72,
    v73,
    v74,
    v75,
    v76,
    v77,
    v78,
    v79,
    "dp_ipa_uc_attach",
    v61);
  if ( v60 )
  {
    dp_tx_ipa_uc_detach(a1);
    v61 = -14;
  }
LABEL_40:
  _ReadStatusReg(SP_EL0);
  return v61;
}
