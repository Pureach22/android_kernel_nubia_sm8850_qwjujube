__int64 __fastcall dp_rx_wbm_err_process(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x8
  __int64 (__fastcall *v6)(__int64, __int64, __int64, __int64, char *); // x8
  __int64 v7; // x0
  __int64 v8; // x28
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x25
  _DWORD *v18; // x8
  __int64 (__fastcall *v19)(_QWORD); // x8
  unsigned int v20; // w0
  _DWORD *v21; // x8
  unsigned int v22; // w23
  __int64 *ref_by_id_2; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x26
  __int64 v33; // x27
  int v34; // w24
  __int64 v35; // x22
  unsigned int v36; // w20
  __int64 v37; // x8
  char v38; // w9
  char v39; // w9
  unsigned int v40; // w20
  unsigned int v41; // w5
  int v42; // w4
  unsigned __int64 v43; // x10
  unsigned int v44; // w4
  __int64 v45; // x20
  __int64 *v46; // x0
  __int64 v47; // x20
  int v48; // w10
  unsigned int v49; // w8
  int v50; // w9
  __int64 v51; // x0
  __int64 v52; // x1
  __int64 v53; // x2
  __int64 v54; // x3
  __int64 v55; // x4
  __int64 v56; // x0
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  __int64 v65; // x20
  __int64 v66; // x23
  unsigned int v67; // w8
  int v68; // w5
  __int64 v69; // x0
  __int64 v70; // x1
  __int64 v71; // x2
  __int64 *v72; // x3
  char v73; // w4
  _DWORD *v74; // x8
  __int64 v75; // x20
  unsigned __int8 (__fastcall *v76)(_QWORD); // x8
  __int64 (__fastcall *v77)(_QWORD); // x8
  __int64 (__fastcall *v78)(_QWORD); // x8
  unsigned __int8 (__fastcall *v79)(_QWORD); // x8
  __int64 (__fastcall *v80)(_QWORD); // x8
  __int64 (__fastcall *v81)(_QWORD); // x8
  __int64 (__fastcall *v82)(_QWORD); // x8
  char v83; // w0
  char v84; // w8
  __int64 v85; // x20
  __int64 v86; // x20
  __int64 v87; // x0
  __int64 v89; // [xsp+0h] [xbp-50h]
  __int64 v90; // [xsp+8h] [xbp-48h]
  unsigned int v91; // [xsp+24h] [xbp-2Ch]
  __int64 v92; // [xsp+28h] [xbp-28h]
  _QWORD v93[2]; // [xsp+40h] [xbp-10h] BYREF

  v93[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a2 + 1128);
  v93[0] = 0;
  v92 = v5;
  v6 = *(__int64 (__fastcall **)(__int64, __int64, __int64, __int64, char *))(a2 + 1712);
  if ( *((_DWORD *)v6 - 1) != 1996224321 )
    __break(0x8228u);
  v7 = v6(a1, a2, a3, a4, (char *)v93 + 4);
  if ( v7 )
  {
    v8 = v7;
    v91 = 0;
    do
    {
      v17 = *(_QWORD *)(v8 + 224);
      v18 = *(_DWORD **)(*(_QWORD *)(*(_QWORD *)(a2 + 1128) + 74392LL) + 1584LL);
      if ( *(v18 - 1) != -128330861 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _QWORD *, __int64))v18)(v17, v93, 4);
      v19 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(a2 + 1128) + 74392LL) + 600LL);
      if ( *((_DWORD *)v19 - 1) != 855462014 )
        __break(0x8228u);
      v20 = v19(v17);
      v21 = *(_DWORD **)(a2 + 1432);
      if ( *(v21 - 1) != 1020823628 )
        __break(0x8228u);
      v22 = ((__int64 (__fastcall *)(__int64, _QWORD))v21)(a2, v20);
      ref_by_id_2 = (__int64 *)dp_peer_get_ref_by_id_2(a2, v22);
      if ( ref_by_id_2 )
      {
        v32 = *ref_by_id_2;
        v33 = (__int64)ref_by_id_2;
        if ( *ref_by_id_2 )
        {
          v34 = 1;
          if ( (*(_BYTE *)(v8 + 84) & 2) != 0 )
            goto LABEL_44;
          goto LABEL_17;
        }
        dp_peer_unref_delete((__int64)ref_by_id_2, 4u, v24, v25, v26, v27, v28, v29, v30, v31);
      }
      v45 = jiffies;
      if ( dp_rx_wbm_err_process___last_ticks - jiffies + 125 < 0 )
      {
        LODWORD(v90) = (LODWORD(v93[0]) >> 19) & 0x1F;
        LODWORD(v89) = (LODWORD(v93[0]) >> 17) & 3;
        qdf_trace_msg(
          0x45u,
          5u,
          "%s: peer is null peer_id %u err_src %u, REO: push_rsn %u err_code %u, RXDMA: push_rsn %u err_code %u hit %llu",
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          "dp_rx_wbm_err_process",
          (unsigned __int16)v22,
          v93[0] & 7,
          HIBYTE(LODWORD(v93[0])) & 3,
          (LODWORD(v93[0]) >> 26) & 0x1F,
          v89,
          v90,
          *(_QWORD *)(a2 + 13720));
        v34 = 0;
        v32 = 0;
        v33 = 0;
        dp_rx_wbm_err_process___last_ticks = v45;
        if ( (*(_BYTE *)(v8 + 84) & 2) != 0 )
        {
LABEL_44:
          v46 = dp_rx_sg_create(a2, (__int64 *)v8);
          v35 = *v46;
          if ( v46 )
            _qdf_nbuf_free((__int64)v46);
          v47 = jiffies;
          if ( dp_rx_wbm_err_process___last_ticks_54 - jiffies + 125 < 0 )
          {
            qdf_trace_msg(
              0x45u,
              5u,
              "%s: scattered msdu dropped",
              v9,
              v10,
              v11,
              v12,
              v13,
              v14,
              v15,
              v16,
              "dp_rx_wbm_err_process");
            dp_rx_wbm_err_process___last_ticks_54 = v47;
            if ( !v34 )
              goto LABEL_7;
            goto LABEL_6;
          }
          goto LABEL_71;
        }
      }
      else
      {
        v34 = 0;
        v32 = 0;
        v33 = 0;
        if ( (*(_BYTE *)(v8 + 84) & 2) != 0 )
          goto LABEL_44;
      }
LABEL_17:
      v35 = *(_QWORD *)v8;
      v36 = v93[0];
      if ( (unsigned int)wlan_cfg_per_pdev_lmac_ring(*(_QWORD *)(a2 + 40))
        && (unsigned __int8)wlan_cfg_get_pdev_idx(*(_QWORD *)(a2 + 40), (v36 >> 13) & 3) )
      {
        v37 = 0;
LABEL_26:
        v40 = 0;
        v39 = 1;
        goto LABEL_27;
      }
      v37 = *(_QWORD *)(a2 + 72);
      if ( !v37 )
        goto LABEL_26;
      v38 = v34 ^ 1;
      if ( (*(_BYTE *)(v37 + 17) & 2) == 0 )
        v38 = 1;
      if ( (v38 & 1) == 0 && (*(_BYTE *)(v32 + 10) & 8) != 0 )
      {
        v40 = (*(_DWORD *)(v8 + 48) >> 18) & 0xF;
        v39 = 0;
      }
      else
      {
        v39 = 0;
        v40 = 0;
      }
LABEL_27:
      v41 = v93[0];
      if ( (v93[0] & 7) != 1 )
      {
        if ( (v93[0] & 7) != 2 )
          goto LABEL_71;
        v42 = HIBYTE(LODWORD(v93[0])) & 3;
        if ( v42 == 1 )
        {
          v51 = a2;
          v52 = v8;
          v53 = v32;
          v54 = v17;
          v55 = 2;
LABEL_70:
          dp_rx_err_route_hdl(v51, v52, v53, v54, v55, v40);
          goto LABEL_71;
        }
        if ( v42 )
        {
          qdf_trace_msg(
            0x82u,
            1u,
            "%s: invalid reo push reason %u",
            v9,
            v10,
            v11,
            v12,
            v13,
            v14,
            v15,
            v16,
            "dp_rx_wbm_err_process");
LABEL_142:
          _qdf_nbuf_free(v8);
          v87 = printk(
                  &unk_9BB309,
                  "expr",
                  "__dp_assert_always_internal",
                  "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_internal.h");
          dump_stack(v87);
          goto LABEL_71;
        }
        if ( a2 )
        {
          v43 = ((unsigned __int64)LODWORD(v93[0]) >> 26) & 0x1F;
          if ( (unsigned int)v43 >= 0xF )
            __break(0x5512u);
          ++*(_DWORD *)(a2 + 13908 + 4 * v43);
        }
        if ( (v39 & 1) == 0 )
          ++*(_DWORD *)(v37 + 508);
        v44 = (v41 >> 26) & 0x1F;
        if ( v44 <= 6 )
        {
          if ( !v44 )
          {
            v74 = *(_DWORD **)(a2 + 1720);
            if ( *(v74 - 1) != 450902238 )
              __break(0x8228u);
            ((void (__fastcall *)(__int64, __int64, __int64, _QWORD, __int64, _QWORD, _QWORD))v74)(
              a2,
              v8,
              v17,
              (v41 >> 13) & 3,
              v32,
              0,
              v40);
            goto LABEL_71;
          }
          if ( v44 == 5 )
          {
            if ( v34 )
              ++*(_DWORD *)(v32 + 3256LL * v40 + 3164);
            v79 = *(unsigned __int8 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(a2 + 1128) + 74392LL) + 560LL);
            if ( *((_DWORD *)v79 - 1) != -1147376687 )
              __break(0x8228u);
            if ( v79(v17) )
            {
              v80 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(v92 + 74392) + 392LL);
              if ( *((_DWORD *)v80 - 1) != 855462014 )
                __break(0x8228u);
              v91 = v80(v17);
            }
            v81 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(a2 + 1128) + 74392LL) + 1272LL);
            if ( *((_DWORD *)v81 - 1) != 855462014 )
              __break(0x8228u);
            *(_WORD *)(v8 + 60) = v81(v17);
            *(_QWORD *)v8 = 0;
            dp_2k_jump_handle(a2, v8, v17, v22, v91);
            goto LABEL_71;
          }
          if ( v44 != 6 )
            goto LABEL_100;
        }
        else
        {
          if ( ((v41 >> 26) & 0x1F) > 0xA )
          {
            if ( v44 == 11 || v44 == 13 )
            {
              if ( v34 )
                ++*(_DWORD *)(v32 + 3256LL * v40 + 3156);
              goto LABEL_68;
            }
            goto LABEL_100;
          }
          if ( v44 == 7 )
          {
            if ( v34 )
              ++*(_DWORD *)(v32 + 3256LL * v40 + 3160);
            v76 = *(unsigned __int8 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(a2 + 1128) + 74392LL) + 560LL);
            if ( *((_DWORD *)v76 - 1) != -1147376687 )
              __break(0x8228u);
            if ( v76(v17) )
            {
              v77 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(v92 + 74392) + 392LL);
              if ( *((_DWORD *)v77 - 1) != 855462014 )
                __break(0x8228u);
              v91 = v77(v17);
            }
            v78 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(a2 + 1128) + 74392LL) + 1272LL);
            if ( *((_DWORD *)v78 - 1) != 855462014 )
              __break(0x8228u);
            *(_WORD *)(v8 + 60) = v78(v17);
            *(_QWORD *)v8 = 0;
            dp_rx_oor_handle(a2, v8, v22, v17);
            goto LABEL_71;
          }
          if ( v44 != 8 )
          {
LABEL_100:
            v75 = jiffies;
            if ( dp_rx_wbm_err_process___last_ticks_56 - jiffies + 125 < 0 )
            {
              qdf_trace_msg(
                0x45u,
                5u,
                "%s: Got pkt with REO ERROR: %d",
                v9,
                v10,
                v11,
                v12,
                v13,
                v14,
                v15,
                v16,
                "dp_rx_wbm_err_process");
              dp_rx_wbm_err_process___last_ticks_56 = v75;
            }
            goto LABEL_68;
          }
        }
        v56 = dp_peer_get_ref_by_id_2(a2, v22);
        if ( v56 )
        {
          v65 = jiffies;
          if ( dp_rx_err_handle_bar___last_ticks - jiffies + 125 < 0 )
          {
            v66 = v56;
            qdf_trace_msg(
              0x45u,
              5u,
              "%s: BAR update to H.W is skipped",
              v57,
              v58,
              v59,
              v60,
              v61,
              v62,
              v63,
              v64,
              "dp_rx_err_handle_bar");
            v56 = v66;
            dp_rx_err_handle_bar___last_ticks = v65;
          }
          if ( a2 )
            ++*(_DWORD *)(a2 + 14124);
          dp_peer_unref_delete(v56, 4u, v57, v58, v59, v60, v61, v62, v63, v64);
        }
        goto LABEL_68;
      }
      v48 = (LODWORD(v93[0]) >> 17) & 3;
      if ( v48 == 2 )
      {
        qdf_trace_msg(
          0x82u,
          2u,
          "%s: rxdma push reason %u",
          v9,
          v10,
          v11,
          v12,
          v13,
          v14,
          v15,
          v16,
          "dp_rx_wbm_err_process",
          2);
        if ( a2 )
          ++*(_DWORD *)(a2 + 14140);
        goto LABEL_68;
      }
      if ( v48 == 1 )
      {
        v51 = a2;
        v52 = v8;
        v53 = v32;
        v54 = v17;
        v55 = 1;
        goto LABEL_70;
      }
      if ( v48 )
      {
        qdf_trace_msg(
          0x45u,
          2u,
          "%s: invalid rxdma push reason %u, wbm_err 0x%x",
          v9,
          v10,
          v11,
          v12,
          v13,
          v14,
          v15,
          v16,
          "dp_rx_wbm_err_process",
          3);
        goto LABEL_142;
      }
      if ( a2 )
        ++*(_DWORD *)(a2 + 13776 + 4 * (((unsigned __int64)LODWORD(v93[0]) >> 19) & 0x1F));
      if ( (v39 & 1) == 0 )
        ++*(_DWORD *)(v37 + 500);
      v49 = (v41 >> 19) & 0x1F;
      if ( v49 <= 7 )
      {
        switch ( v49 )
        {
          case 3u:
            v82 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(v92 + 74392) + 504LL);
            if ( !v82 )
              goto LABEL_139;
            if ( *((_DWORD *)v82 - 1) != -1147376687 )
              __break(0x8228u);
            v83 = v82(v17);
            v84 = v34 ^ 1;
            if ( !v83 )
              v84 = 1;
            if ( (v84 & 1) != 0 )
            {
LABEL_139:
              if ( !v34 )
              {
                dp_rx_process_rxdma_err(
                  a2,
                  v8,
                  v17,
                  nullptr,
                  (LODWORD(v93[0]) >> 19) & 0x1F,
                  (LODWORD(v93[0]) >> 13) & 3,
                  v40);
                goto LABEL_7;
              }
              ++*(_DWORD *)(v32 + 3256LL * v40 + 3148);
              _qdf_nbuf_free(v8);
              goto LABEL_6;
            }
            dp_rx_process_mic_error(a2, v8, v17, (__int64 *)v32);
            ++*(_DWORD *)(v32 + 3256LL * v40 + 3144);
            goto LABEL_71;
          case 4u:
            dp_rx_process_mic_error(a2, v8, v17, (__int64 *)v32);
            if ( !v34 )
              goto LABEL_7;
            ++*(_DWORD *)(v32 + 3256LL * v40 + 3144);
            goto LABEL_6;
          case 5u:
LABEL_86:
            if ( v34 )
            {
              ++*(_DWORD *)(v32 + 3256LL * v40 + 3168);
              v41 = v93[0];
            }
            v67 = v41 >> 19;
            v68 = (v41 >> 13) & 3;
            v69 = a2;
            v70 = v8;
            v71 = v17;
            v72 = (__int64 *)v32;
            v73 = v67 & 0x1F;
LABEL_96:
            dp_rx_process_rxdma_err(v69, v70, v71, v72, v73, v68, v40);
LABEL_71:
            if ( !v34 )
              goto LABEL_7;
            goto LABEL_6;
        }
LABEL_131:
        _qdf_nbuf_free(v8);
        v85 = jiffies;
        if ( dp_rx_wbm_err_process___last_ticks_58 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x45u,
            2u,
            "%s: RXDMA error %d",
            v9,
            v10,
            v11,
            v12,
            v13,
            v14,
            v15,
            v16,
            "dp_rx_wbm_err_process",
            (LODWORD(v93[0]) >> 19) & 0x1F);
          dp_rx_wbm_err_process___last_ticks_58 = v85;
        }
        goto LABEL_71;
      }
      if ( ((v41 >> 19) & 0x1F) <= 0xF )
      {
        if ( v49 == 8 )
          goto LABEL_86;
        if ( v49 != 15 )
          goto LABEL_131;
        if ( v34 )
        {
          ++*(_QWORD *)(v32 + 2224 + 3256LL * v40 + 840);
          if ( (*(_BYTE *)(v8 + 68) & 4) != 0 )
            v50 = *(unsigned __int16 *)(v8 + 66);
          else
            v50 = 0;
          *(_QWORD *)(v32 + 2224 + 3256LL * v40 + 848) += (unsigned int)(*(_DWORD *)(v8 + 112) + v50);
        }
LABEL_68:
        _qdf_nbuf_free(v8);
        goto LABEL_71;
      }
      if ( v49 != 16 )
      {
        if ( v49 == 17 )
        {
          v68 = (v41 >> 13) & 3;
          v69 = a2;
          v70 = v8;
          v71 = v17;
          v72 = (__int64 *)v32;
          v73 = 17;
          goto LABEL_96;
        }
        goto LABEL_131;
      }
      _qdf_nbuf_free(v8);
      if ( !v34 )
        goto LABEL_7;
      v86 = jiffies;
      if ( dp_rx_amsdu_adr_mismatch_hdl___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x45u,
          2u,
          "%s: RXDMA error %d",
          v9,
          v10,
          v11,
          v12,
          v13,
          v14,
          v15,
          v16,
          "dp_rx_amsdu_adr_mismatch_hdl",
          16);
        dp_rx_amsdu_adr_mismatch_hdl___last_ticks = v86;
      }
LABEL_6:
      dp_txrx_peer_unref_delete(v33, 4u, v9, v10, v11, v12, v13, v14, v15, v16);
LABEL_7:
      v8 = v35;
    }
    while ( v35 );
  }
  _ReadStatusReg(SP_EL0);
  return HIDWORD(v93[0]);
}
