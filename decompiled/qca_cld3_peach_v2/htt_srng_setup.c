__int64 __fastcall htt_srng_setup(__int64 a1, unsigned int a2, __int64 a3, int a4)
{
  __int64 v8; // x0
  unsigned int entrysize; // w0
  __int64 v10; // x20
  unsigned int v11; // w22
  unsigned int v12; // w27
  __int64 v13; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x20
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 *v31; // x8
  __int64 v32; // x22
  __int64 v33; // x10
  __int64 *v34; // x9
  __int64 v35; // x12
  _QWORD *v36; // x11
  __int64 v37; // x11
  __int64 v38; // x24
  __int64 v39; // x28
  __int64 v40; // x26
  int v41; // w27
  int v42; // w25
  int v43; // w6
  int v44; // w8
  __int64 v45; // x24
  int v46; // w8
  int v47; // w8
  int v48; // w9
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  __int64 v57; // x28
  __int64 v58; // x26
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  unsigned int v67; // w25
  unsigned int v68; // w26
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  int v77; // w8
  int v78; // w8
  int v79; // w9
  double v80; // d0
  double v81; // d1
  double v82; // d2
  double v83; // d3
  double v84; // d4
  double v85; // d5
  double v86; // d6
  double v87; // d7
  double v88; // d0
  double v89; // d1
  double v90; // d2
  double v91; // d3
  double v92; // d4
  double v93; // d5
  double v94; // d6
  double v95; // d7
  int v96; // w8
  int v97; // w8
  int v98; // w8
  int v99; // w10
  int v100; // w8
  int v101; // w9
  int v102; // w8
  unsigned int v103; // w9
  int v104; // w8
  int v105; // w9
  __int64 v106; // x0
  double v107; // d0
  double v108; // d1
  double v109; // d2
  double v110; // d3
  double v111; // d4
  double v112; // d5
  double v113; // d6
  double v114; // d7
  __int64 v115; // x22
  int v116; // w8
  int v117; // w8
  unsigned int v118; // w0
  unsigned int v119; // w21
  __int64 result; // x0
  int v121; // [xsp+14h] [xbp-6Ch]
  unsigned int v122; // [xsp+18h] [xbp-68h]
  unsigned int v123; // [xsp+1Ch] [xbp-64h]
  _QWORD v124[2]; // [xsp+20h] [xbp-60h] BYREF
  __int64 v125; // [xsp+30h] [xbp-50h]
  __int64 v126; // [xsp+38h] [xbp-48h]
  __int64 v127; // [xsp+40h] [xbp-40h]
  __int64 v128; // [xsp+48h] [xbp-38h]
  __int64 v129; // [xsp+50h] [xbp-30h]
  __int64 v130; // [xsp+58h] [xbp-28h]
  __int64 v131; // [xsp+60h] [xbp-20h]
  __int64 v132; // [xsp+68h] [xbp-18h]
  __int64 v133; // [xsp+70h] [xbp-10h]
  __int64 v134; // [xsp+78h] [xbp-8h]

  v134 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_QWORD *)(a1 + 16);
  v132 = 0;
  v133 = 0;
  v130 = 0;
  v131 = 0;
  v128 = 0;
  v129 = 0;
  v126 = 0;
  v127 = 0;
  v124[1] = 0;
  v125 = 0;
  v124[0] = 0;
  entrysize = hal_srng_get_entrysize(v8, (unsigned int)a4);
  v10 = *(_QWORD *)(a1 + 8);
  v11 = entrysize;
  v12 = a2;
  if ( (unsigned int)wlan_cfg_per_pdev_lmac_ring(*(_QWORD *)(v10 + 40)) )
  {
    if ( a2 )
      goto LABEL_99;
    v12 = *(unsigned __int8 *)(*(_QWORD *)(v10 + 72) + 1LL);
  }
  v13 = _qdf_nbuf_alloc(*(_QWORD *)(a1 + 56), 64, 8, 4, 1, "dp_htt_htc_msg_alloc", 87);
  if ( !v13 )
  {
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: htt_msg alloc failed ring type %d",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "htt_srng_setup",
      (unsigned int)a4);
LABEL_97:
    result = 16;
LABEL_98:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v22 = v13;
  hal_get_srng_params(*(_QWORD *)(a1 + 16), a3, v124);
  v31 = *(__int64 **)(a1 + 16);
  v122 = v11;
  if ( *(_DWORD *)(a3 + 116) )
  {
    v32 = v31[9253] + *(_QWORD *)(a3 + 128) - v31[9252];
    if ( (*(_DWORD *)(a3 + 76) & 0x80000000) != 0 )
    {
      v34 = v31 + 9255;
      v33 = 9254;
    }
    else
    {
      v33 = 2;
      v34 = (__int64 *)(*v31 + 728);
    }
    v37 = 144;
  }
  else
  {
    if ( (*(_DWORD *)(a3 + 76) & 0x80000000) != 0 )
    {
      v36 = v31 + 9255;
      v35 = 9254;
    }
    else
    {
      v35 = 2;
      v36 = (_QWORD *)(*v31 + 728);
    }
    v34 = v31 + 9253;
    v33 = 9252;
    v32 = *v36 + *(_QWORD *)(a3 + 144) - v31[v35];
    v37 = 128;
  }
  v38 = *v34;
  v39 = *(_QWORD *)(a3 + v37);
  v40 = v31[v33];
  if ( a4 <= 17 )
  {
    if ( a4 > 15 )
    {
      if ( a4 != 16 )
      {
        v42 = 0;
        v43 = 1;
        v121 = 0x1000000;
        v41 = 1;
        goto LABEL_45;
      }
      v42 = 0;
      if ( (wlan_cfg_get_txmon_hw_support(*(_QWORD *)(*(_QWORD *)(a1 + 8) + 40LL)) & 1) != 0 )
        v43 = 11;
      else
        v43 = 2;
    }
    else
    {
      if ( a4 != 14 )
      {
        if ( a4 == 15 )
        {
          v41 = 0;
          v121 = 0;
          v42 = 1;
          v43 = 7;
          goto LABEL_45;
        }
        goto LABEL_42;
      }
      v44 = 18 * v12;
      if ( 18 * v12 + 184 == BYTE4(v129) )
      {
        v41 = 0;
        v42 = 0;
        v121 = 0x2000000;
        v43 = 5;
        goto LABEL_45;
      }
      if ( v44 + 186 == BYTE4(v129) )
      {
        v41 = 0;
        v42 = 0;
        v121 = 0x2000000;
        v43 = 6;
        goto LABEL_45;
      }
      if ( v44 + 185 != BYTE4(v129) )
      {
        if ( v44 + 187 == BYTE4(v129) )
        {
          v41 = 0;
          v42 = 0;
          v121 = 0x2000000;
          v43 = 13;
        }
        else
        {
          if ( v44 + 188 != BYTE4(v129) )
          {
            qdf_trace_msg(
              0x3Fu,
              2u,
              "%s: Ring %d currently not supported",
              v23,
              v24,
              v25,
              v26,
              v27,
              v28,
              v29,
              v30,
              "htt_srng_setup");
            goto LABEL_79;
          }
          v41 = 0;
          v42 = 0;
          v121 = 0x2000000;
          v43 = 15;
        }
        goto LABEL_45;
      }
      v43 = 0;
      v42 = 0;
    }
    v41 = 1;
    v121 = 0x1000000;
    goto LABEL_45;
  }
  if ( a4 <= 23 )
  {
    if ( a4 == 18 )
    {
      v41 = 0;
      if ( (wlan_cfg_get_txmon_hw_support(*(_QWORD *)(*(_QWORD *)(a1 + 8) + 40LL)) & 1) != 0 )
        v43 = 12;
      else
        v43 = 4;
      v42 = 1;
      v121 = 0;
      goto LABEL_45;
    }
    if ( a4 == 19 )
    {
LABEL_29:
      v42 = 0;
      v41 = 1;
      v121 = 0x1000000;
      v43 = 3;
      goto LABEL_45;
    }
LABEL_42:
    qdf_trace_msg(
      0x3Fu,
      2u,
      "%s: Ring currently not supported",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "htt_srng_setup");
LABEL_79:
    _qdf_nbuf_free(v22);
    goto LABEL_97;
  }
  switch ( a4 )
  {
    case 24:
      v42 = 0;
      v41 = 1;
      v121 = 0x1000000;
      v43 = 9;
      break;
    case 25:
      v41 = 0;
      v121 = 0;
      v42 = 1;
      v43 = 10;
      break;
    case 27:
      goto LABEL_29;
    default:
      goto LABEL_42;
  }
LABEL_45:
  v45 = v38 + v39 - v40;
  v123 = v43;
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: ring_type %d ring_id %d htt_ring_id %d hp_addr 0x%llx tp_addr 0x%llx",
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    "htt_srng_setup",
    (unsigned int)a4,
    BYTE4(v129),
    v45);
  if ( *(_DWORD *)(v22 + 116) )
  {
    v46 = 0;
  }
  else
  {
    v48 = *(_DWORD *)(v22 + 208);
    v47 = *(_DWORD *)(v22 + 212);
    if ( (unsigned int)(v47 - v48) > 0x37 )
      goto LABEL_50;
    v46 = v48 - v47;
  }
  if ( (unsigned int)pskb_expand_head(v22, 0, (unsigned int)(v46 + 56), 2080) )
  {
    dev_kfree_skb_any_reason(v22, 1);
    goto LABEL_96;
  }
LABEL_50:
  if ( !skb_put(v22, 56) )
  {
LABEL_96:
    qdf_trace_msg(
      0x3Fu,
      2u,
      "%s: Failed to expand head for SRING_SETUP msg",
      v49,
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      "htt_srng_setup");
    goto LABEL_97;
  }
  v57 = *(_QWORD *)(v22 + 224);
  skb_push(v22, 0);
  *(_DWORD *)v57 = 11;
  v58 = *(_QWORD *)(a1 + 8);
  if ( !(unsigned int)wlan_cfg_per_pdev_lmac_ring(*(_QWORD *)(v58 + 40)) )
  {
    if ( ((v41 | v42) & 1) != 0 )
    {
      v67 = a2 + 1;
      if ( a2 + 1 >= 0x100 )
        printk(
          &unk_94DB9D,
          "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_htt.c",
          932,
          "!((target_pdev_id) & ~((HTT_SRING_SETUP_PDEV_ID_M) >> (HTT_SRING_SETUP_PDEV_ID_S)))");
      goto LABEL_61;
    }
    if ( a2 >= 0x100 )
      printk(
        &unk_94DB9D,
        "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_htt.c",
        934,
        "!((mac_id) & ~((HTT_SRING_SETUP_PDEV_ID_M) >> (HTT_SRING_SETUP_PDEV_ID_S)))");
    goto LABEL_60;
  }
  if ( !a2 )
  {
    if ( ((v41 | v42) & 1) != 0 )
    {
      v67 = *(unsigned __int8 *)(*(_QWORD *)(v58 + 72) + 2LL);
LABEL_61:
      v68 = v122 >> 2;
      *(_DWORD *)v57 |= v67 << 8;
      qdf_trace_msg(0x45u, 5u, "%s: mac_id %d", v59, v60, v61, v62, v63, v64, v65, v66, "htt_srng_setup", a2);
      v77 = 0;
      *(_DWORD *)v57 |= v121 | (v123 << 16);
      *(_DWORD *)(v57 + 4) = 0;
      *(_DWORD *)(v57 + 4) = v124[0];
      *(_DWORD *)(v57 + 8) = 0;
      *(_QWORD *)(v57 + 8) = HIDWORD(v124[0]);
      if ( v122 >= 0x400 )
      {
        printk(
          &unk_94DB9D,
          "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_htt.c",
          958,
          "!((ring_entry_size) & ~((HTT_SRING_SETUP_ENTRY_SIZE_M) >> (HTT_SRING_SETUP_ENTRY_SIZE_S)))");
        v77 = *(_DWORD *)(v57 + 12);
      }
      v78 = v77 | (v68 << 16);
      *(_DWORD *)(v57 + 12) = v78;
      v79 = v125 * v68;
      if ( (unsigned int)v125 * v68 >= 0x10000 )
      {
        printk(
          &unk_94DB9D,
          "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_htt.c",
          960,
          "!(((ring_entry_size * srng_params.num_entries)) & ~((HTT_SRING_SETUP_RING_SIZE_M) >> (HTT_SRING_SETUP_RING_SIZE_S)))");
        v79 = v125 * v68;
        v78 = *(_DWORD *)(v57 + 12);
      }
      *(_DWORD *)(v57 + 12) = v78 | v79;
      qdf_trace_msg(0x45u, 5u, "%s: entry_size %d", v69, v70, v71, v72, v73, v74, v75, v76, "htt_srng_setup", v68);
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: num_entries %d",
        v80,
        v81,
        v82,
        v83,
        v84,
        v85,
        v86,
        v87,
        "htt_srng_setup",
        (unsigned int)v125);
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: ring_size %d",
        v88,
        v89,
        v90,
        v91,
        v92,
        v93,
        v94,
        v95,
        "htt_srng_setup",
        (unsigned int)v125 * v68);
      v96 = *(_DWORD *)(v57 + 12);
      if ( v41 )
      {
        v96 |= 0x2000000u;
        *(_DWORD *)(v57 + 12) = v96;
      }
      v97 = ((_DWORD)v129 << 24) & 0x8000000 | v96;
      *(_DWORD *)(v57 + 12) = v97;
      v98 = ((_DWORD)v129 << 24) & 0x20000000 | v97;
      *(_DWORD *)(v57 + 12) = v98;
      v99 = v129;
      *(_DWORD *)(v57 + 20) = HIDWORD(v32);
      *(_DWORD *)(v57 + 24) = v45;
      *(_QWORD *)(v57 + 28) = HIDWORD(v45);
      *(_DWORD *)(v57 + 12) = (v99 << 24) & 0x10000000 | v98;
      *(_DWORD *)(v57 + 16) = v32;
      *(_DWORD *)(v57 + 32) = v126;
      *(_DWORD *)(v57 + 36) = 0;
      *(_DWORD *)(v57 + 36) = HIDWORD(v126);
      *(_DWORD *)(v57 + 40) = 0;
      *(_DWORD *)(v57 + 40) = v127;
      *(_DWORD *)(v57 + 44) = 0;
      v100 = v128 * v68;
      if ( (unsigned int)v128 * v68 >= 0x8000 )
      {
        printk(
          &unk_94DB9D,
          "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_htt.c",
          1021,
          "!((srng_params.intr_batch_cntr_thres_entries * ring_entry_size) & ~((HTT_SRING_SETUP_INTR_BATCH_COUNTER_TH_M) "
          ">> (HTT_SRING_SETUP_INTR_BATCH_COUNTER_TH_S)))");
        v101 = *(_DWORD *)(v57 + 44);
        v100 = v128 * v68;
      }
      else
      {
        v101 = 0;
      }
      v102 = v101 | v100;
      *(_DWORD *)(v57 + 44) = v102;
      v103 = HIDWORD(v127);
      if ( HIDWORD(v127) >= 0x80000 )
      {
        printk(
          &unk_94DB9D,
          "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_htt.c",
          1023,
          "!((srng_params.intr_timer_thres_us >> 3) & ~((HTT_SRING_SETUP_INTR_TIMER_TH_M) >> (HTT_SRING_SETUP_INTR_TIMER_TH_S)))");
        v103 = HIDWORD(v127);
        v102 = *(_DWORD *)(v57 + 44);
      }
      *(_DWORD *)(v57 + 44) = v102 | (v103 >> 3 << 16);
      *(_DWORD *)(v57 + 48) = 0;
      if ( (v129 & 0x10000) != 0 )
      {
        v104 = HIDWORD(v128);
        if ( HIDWORD(v128) >= 0x10000 )
        {
          printk(
            &unk_94DB9D,
            "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_htt.c",
            1033,
            "!((srng_params.low_threshold) & ~((HTT_SRING_SETUP_INTR_LOW_TH_M) >> (HTT_SRING_SETUP_INTR_LOW_TH_S)))");
          v104 = HIDWORD(v128);
          v105 = *(_DWORD *)(v57 + 48);
        }
        else
        {
          v105 = 0;
        }
        *(_DWORD *)(v57 + 48) = v105 | v104;
      }
      v106 = htt_htc_pkt_alloc(a1);
      if ( v106 )
      {
        *(_QWORD *)v106 = 0;
        *(_QWORD *)(v106 + 32) = dp_htt_h2t_send_complete_free_netbuf;
        v115 = v106;
        *(_QWORD *)(v106 + 48) = *(_QWORD *)(v22 + 224);
        if ( (*(_BYTE *)(v22 + 68) & 4) != 0 )
          v116 = *(unsigned __int16 *)(v22 + 66);
        else
          v116 = 0;
        *(_DWORD *)(v106 + 60) = *(_DWORD *)(v22 + 112) + v116;
        v117 = *(_DWORD *)(a1 + 64);
        *(_WORD *)(v106 + 72) = 13;
        *(_DWORD *)(v106 + 88) = 0;
        *(_BYTE *)(v106 + 80) = 0;
        *(_DWORD *)(v106 + 64) = v117;
        *(_QWORD *)(v106 + 112) = v22;
        v118 = htc_send_pkt(*(_QWORD *)(a1 + 48), v106 + 16);
        if ( v118 )
        {
          v119 = v118;
          ++*(_DWORD *)(a1 + 104);
          _qdf_nbuf_free(v22);
          htt_htc_pkt_free(a1, v115);
          result = v119;
        }
        else
        {
          result = 0;
          if ( (*(_DWORD *)(v115 + 68) | 8) == 9 )
            ++*(_DWORD *)(a1 + 104);
        }
        goto LABEL_98;
      }
      qdf_trace_msg(
        0x45u,
        2u,
        "%s: pkt alloc failed, ring_type %d ring_id %d htt_ring_id %d",
        v107,
        v108,
        v109,
        v110,
        v111,
        v112,
        v113,
        v114,
        "htt_srng_setup",
        (unsigned int)a4,
        BYTE4(v129),
        v123);
      goto LABEL_79;
    }
LABEL_60:
    v67 = a2;
    goto LABEL_61;
  }
LABEL_99:
  __break(0x5512u);
  return htt_h2t_full_mon_cfg();
}
