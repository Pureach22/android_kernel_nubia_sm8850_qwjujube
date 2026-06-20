__int64 __fastcall _qdf_nbuf_get_tso_info(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned int v4; // w26
  int v5; // w28
  __int64 *v6; // x25
  unsigned int v7; // w8
  const void *v8; // x3
  unsigned int v9; // w21
  char v10; // w22
  unsigned int v11; // w19
  unsigned int v12; // w19
  __int64 v13; // x8
  __int64 v14; // x21
  int v15; // w22
  int v16; // w23
  int v17; // w8
  int v18; // w9
  int *v19; // x8
  __int64 v20; // x19
  int v21; // w0
  __int64 v22; // x22
  __int64 v23; // x8
  __int64 v24; // x4
  __int64 v25; // x28
  int v26; // w24
  __int64 v27; // x8
  unsigned int v28; // w27
  unsigned int v29; // w23
  const char **v30; // x21
  char v31; // w0
  __int64 v32; // x23
  __int64 v33; // x0
  __int64 v34; // x28
  unsigned int v35; // w4
  int v36; // w22
  __int64 v37; // x24
  unsigned int v38; // w27
  unsigned __int64 v39; // x28
  __int64 v40; // x21
  const char **v41; // x19
  char v42; // w0
  __int64 v43; // x0
  __int64 v44; // x19
  __int64 v45; // x10
  __int64 result; // x0
  int v47; // w9
  int v48; // w14
  __int64 v49; // x11
  __int64 v50; // x8
  unsigned int v51; // w24
  unsigned __int64 v52; // x8
  unsigned __int64 v53; // x8
  unsigned __int64 v54; // x8
  unsigned __int64 v55; // x8
  unsigned __int64 v56; // x8
  unsigned __int64 v57; // x9
  __int64 v58; // x8
  unsigned int v59; // w23
  int v60; // w26
  __int64 *v61; // x9
  unsigned int v62; // w22
  int v63; // w8
  int v64; // w10
  __int64 v65; // x0
  unsigned int v66; // w19
  bool v67; // cf
  unsigned int v68; // w27
  __int64 v69; // x8
  signed int v70; // w4
  __int64 v71; // x8
  __int64 v72; // x8
  __int64 v73; // x9
  __int64 v74; // t1
  __int64 v75; // x11
  unsigned int v76; // w22
  __int64 *v77; // x27
  unsigned int v78; // w25
  const char **v79; // x19
  char v80; // w0
  char v81; // w24
  __int64 v82; // x0
  const char *v83; // x0
  const char *v84; // x2
  __int64 v85; // x24
  const void *v86; // x4
  const void *v87; // x5
  __int64 v88; // x8
  __int64 v89; // x23
  __int16 v90; // w10
  __int16 v91; // w11
  __int16 v92; // w9
  const char *v93; // x0
  const char *v94; // x2
  __int64 v95; // x0
  int v96; // w26
  char v97; // w23
  const char *v98; // x0
  const char *v99; // x2
  char v100; // w0
  __int64 v101; // x0
  int v102; // [xsp+14h] [xbp-8Ch]
  __int64 v103; // [xsp+18h] [xbp-88h]
  __int16 v104; // [xsp+20h] [xbp-80h]
  __int64 v105; // [xsp+28h] [xbp-78h]
  _DWORD *v106; // [xsp+28h] [xbp-78h]
  __int64 v107; // [xsp+30h] [xbp-70h]
  unsigned __int64 v108; // [xsp+30h] [xbp-70h]
  __int64 v109; // [xsp+38h] [xbp-68h]
  int v110; // [xsp+44h] [xbp-5Ch]
  __int64 v111; // [xsp+48h] [xbp-58h]
  __int64 v112; // [xsp+50h] [xbp-50h]
  unsigned int v113; // [xsp+58h] [xbp-48h]
  __int64 v114; // [xsp+60h] [xbp-40h]
  __int64 v115; // [xsp+68h] [xbp-38h]
  unsigned int v116; // [xsp+74h] [xbp-2Ch]
  unsigned int v118; // [xsp+80h] [xbp-20h]
  __int64 *v119; // [xsp+80h] [xbp-20h]
  int v120; // [xsp+8Ch] [xbp-14h]
  int v121; // [xsp+8Ch] [xbp-14h]
  unsigned int v122; // [xsp+90h] [xbp-10h]
  char v123; // [xsp+90h] [xbp-10h]
  int v124; // [xsp+94h] [xbp-Ch] BYREF
  __int64 v125; // [xsp+98h] [xbp-8h]

  v4 = 0;
  v125 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_DWORD *)(a2 + 112);
  v6 = *(__int64 **)(a3 + 8);
  v112 = *(_QWORD *)(a3 + 24);
  v7 = *(unsigned __int16 *)(*(_QWORD *)(a2 + 216) + *(unsigned int *)(a2 + 212) + 4LL);
  *(_DWORD *)(v112 + 8) = 0;
  v118 = v7;
  v8 = *(const void **)(a2 + 224);
  v9 = ((*(unsigned __int16 *)(*(_QWORD *)(a2 + 216) + *(unsigned __int16 *)(a2 + 182) + 12LL) >> 2) & 0x3C)
     + *(unsigned __int16 *)(a2 + 182)
     - *(unsigned __int16 *)(a2 + 186);
  v10 = v9 + (_BYTE)v8;
  v11 = (v9 + (_DWORD)v8) & 7;
  if ( v11 )
  {
    v85 = a3;
    qdf_trace_msg(69, 0, "%pK,Len %d %d", v8, v9, v11);
    v86 = *(const void **)(a2 + 216);
    v87 = *(const void **)(a2 + 224);
    if ( (int)v87 - (int)v86 < v11 )
    {
      qdf_trace_msg(69, 0, "[%d]Insufficient headroom,[%pK],[%pK],[%d]", 4657, v86, v87, v11);
      v4 = 0;
    }
    else
    {
      v88 = *(_QWORD *)(a2 + 40);
      v89 = v10 & 7;
      if ( v88 )
        *(_QWORD *)(a2 + 40) = v88 - v89;
      skb_push(a2, v10 & 7);
      qdf_mem_move(*(void **)(a2 + 224), (const void *)(*(_QWORD *)(a2 + 224) + v89), v9);
      v4 = v11;
      v90 = *(_WORD *)(a2 + 184);
      v91 = *(_WORD *)(a2 + 182);
      v92 = *(_WORD *)(a2 + 186) - v11;
      *(_DWORD *)(a2 + 112) -= v11;
      *(_WORD *)(a2 + 186) = v92;
      *(_WORD *)(a2 + 184) = v90 - v11;
      *(_WORD *)(a2 + 182) = v91 - v11;
    }
    a3 = v85;
  }
  v12 = *(unsigned __int16 *)(a2 + 180);
  v13 = *(unsigned __int16 *)(a2 + 120);
  if ( v12 == 43144 || v12 == 129 )
  {
    if ( !*(_WORD *)(a2 + 120) )
    {
      v14 = 14;
      goto LABEL_8;
    }
    if ( (unsigned int)v13 > 3 )
    {
      v14 = v13 - 4;
LABEL_8:
      v15 = 0;
      v16 = -(int)v14;
      while ( 1 )
      {
        v17 = *(_DWORD *)(a2 + 112);
        v18 = *(_DWORD *)(a2 + 116);
        v124 = 0;
        if ( v16 + v15 + v17 - v18 < 4 )
        {
          if ( !a2
            || ((v20 = a3, v21 = skb_copy_bits(a2, (unsigned int)v14, &v124, 4), a3 = v20, v21 >= 0)
              ? (v19 = &v124)
              : (v19 = nullptr),
                !v19) )
          {
LABEL_21:
            v12 = 0;
            goto LABEL_112;
          }
        }
        else
        {
          v19 = (int *)(*(_QWORD *)(a2 + 224) + v14);
          if ( !v19 )
            goto LABEL_21;
        }
        if ( v15 == -28 )
          goto LABEL_21;
        v12 = *((unsigned __int16 *)v19 + 1);
        if ( v12 != 43144 && v12 != 129 )
          goto LABEL_22;
        v14 += 4;
        v15 -= 4;
      }
    }
    v12 = 0;
    __break(0x800u);
    goto LABEL_112;
  }
LABEL_22:
  v115 = a3;
  if ( v12 == 8 )
  {
    v23 = *(_QWORD *)(a2 + 216);
    v22 = *(unsigned __int16 *)(a2 + 184);
    v24 = *(unsigned __int8 *)(v23 + v22 + 9);
    if ( (_DWORD)v24 != 6 )
    {
      qdf_trace_msg(56, 2, "%s: TSO IPV4 proto 0x%x not TCP", "__qdf_nbuf_get_tso_cmn_seg_info", v24);
      goto LABEL_113;
    }
    v120 = v5;
    v105 = 0;
    v113 = bswap32(*(unsigned __int16 *)(v23 + v22 + 4)) >> 16;
    v107 = 1;
  }
  else
  {
    if ( v12 != 56710 )
    {
LABEL_112:
      qdf_trace_msg(56, 2, "%s: TSO: ethertype 0x%x is not supported!", "__qdf_nbuf_get_tso_cmn_seg_info", v12);
      goto LABEL_113;
    }
    LODWORD(v22) = *(unsigned __int16 *)(a2 + 184);
    v23 = *(_QWORD *)(a2 + 216);
    v120 = v5;
    v107 = 0;
    LOWORD(v113) = 0;
    v105 = 0x100000;
  }
  v25 = *(unsigned __int16 *)(a2 + 182);
  v26 = *(unsigned __int16 *)(a2 + 186);
  v27 = v23 + v25;
  v114 = *(_QWORD *)(a2 + 224);
  v28 = *(_DWORD *)(v27 + 4);
  v111 = v27;
  v29 = *(unsigned __int16 *)(v27 + 12);
  v30 = *(const char ***)(a1 + 40);
  v31 = is_vmalloc_addr(v114);
  if ( (v31 & 1) != 0 && (dma_map_single_attrs___already_done & 1) == 0 )
  {
    v123 = v31;
    dma_map_single_attrs___already_done = 1;
    v93 = (const char *)dev_driver_string(v30);
    v94 = v30[14];
    if ( !v94 )
      v94 = *v30;
    _warn_printk("%s %s: rejecting DMA map of vmalloc memory\n", v93, v94);
    __break(0x800u);
    if ( (v123 & 1) != 0 )
      goto LABEL_110;
  }
  else if ( (v31 & 1) != 0 )
  {
LABEL_110:
    qdf_trace_msg(56, 2, "%s: DMA mapping error!", "qdf_nbuf_tso_map_frag");
    v95 = printk(
            &unk_AAA255,
            "0",
            "qdf_nbuf_tso_map_frag",
            "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/qdf/linux/src/qdf_nbuf.c");
    dump_stack(v95);
    goto LABEL_113;
  }
  v32 = ((v29 >> 2) & 0x3C) + (_DWORD)v25 - v26;
  v33 = dma_map_page_attrs(
          v30,
          ((unsigned __int64)((v114 << 8 >> 8) + 0x8000000000LL) >> 12 << 6) - 0x140000000LL,
          v114 & 0xFFF,
          v32,
          1,
          0);
  if ( v33 == -1 )
    goto LABEL_110;
  v34 = v33;
  qdf_mem_dp_tx_skb_cnt_inc();
  qdf_mem_dp_tx_skb_inc((int)v32);
  qdf_mem_skb_total_inc((int)v32);
  if ( !v34 )
  {
LABEL_113:
    qdf_trace_msg(56, 3, "%s: TSO: error getting common segment info", "__qdf_nbuf_get_tso_info");
LABEL_114:
    result = 0;
    goto LABEL_115;
  }
  v35 = bswap32(v28);
  v36 = v22 - v26;
  v109 = v34;
  if ( v12 == 56710 )
    v37 = (*(unsigned __int16 *)(*(_QWORD *)(a2 + 216) + *(unsigned __int16 *)(a2 + 182) + 12LL) >> 2) & 0x3C;
  else
    v37 = (unsigned int)(v32 - v36);
  v116 = v35;
  qdf_trace_msg(
    69,
    0,
    "%s seq# %u eit hdr len %u l2 len %u  skb len %u\n",
    "__qdf_nbuf_get_tso_cmn_seg_info",
    v35,
    v32,
    (unsigned __int16)v36,
    *(_DWORD *)(a2 + 112));
  v38 = *(_DWORD *)(a2 + 112) - *(_DWORD *)(a2 + 116) - v32;
  v39 = *(_QWORD *)(a2 + 224) + v32 + v4;
  if ( v38 >= v118 )
    v40 = v118;
  else
    v40 = v38;
  if ( (_DWORD)v40 )
  {
    v41 = *(const char ***)(a1 + 40);
    v42 = is_vmalloc_addr(v39);
    if ( (v42 & 1) != 0 && (dma_map_single_attrs___already_done & 1) == 0 )
    {
      v96 = v32;
      v97 = v42;
      dma_map_single_attrs___already_done = 1;
      v98 = (const char *)dev_driver_string(v41);
      v99 = v41[14];
      if ( !v99 )
        v99 = *v41;
      _warn_printk("%s %s: rejecting DMA map of vmalloc memory\n", v98, v99);
      v100 = v97;
      LODWORD(v32) = v96;
      __break(0x800u);
      if ( (v100 & 1) != 0 )
        goto LABEL_119;
    }
    else if ( (v42 & 1) != 0 )
    {
      goto LABEL_119;
    }
    v43 = dma_map_page_attrs(
            v41,
            ((unsigned __int64)(((__int64)(v39 << 8) >> 8) + 0x8000000000LL) >> 12 << 6) - 0x140000000LL,
            v39 & 0xFFF,
            v40,
            1,
            0);
    if ( v43 != -1 )
    {
      v44 = v43;
      qdf_mem_dp_tx_skb_cnt_inc();
      qdf_mem_dp_tx_skb_inc(v40);
      qdf_mem_skb_total_inc(v40);
      if ( !v44 )
        goto LABEL_114;
      goto LABEL_46;
    }
LABEL_119:
    qdf_trace_msg(56, 2, "%s: DMA mapping error!", "qdf_nbuf_tso_map_frag");
    v101 = printk(
             &unk_AAA255,
             "0",
             "qdf_nbuf_tso_map_frag",
             "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/qdf/linux/src/qdf_nbuf.c");
    dump_stack(v101);
    goto LABEL_114;
  }
  v44 = 0;
LABEL_46:
  qdf_trace_msg(69, 0, "%s[%d] skb frag len %d tso frag len %d\n", "__qdf_nbuf_get_tso_info", 5167, v38, v40);
  v45 = v115;
  result = 0;
  v47 = *(_DWORD *)(v115 + 4);
  *(_DWORD *)(v115 + 4) = 0;
  *(_BYTE *)v115 = 1;
  v110 = v47;
  if ( !v47 || !v6 )
    goto LABEL_115;
  v121 = v120 - v32;
  v122 = 0;
  v48 = (unsigned __int16)v32;
  v102 = (unsigned __int16)v32;
  v49 = v105 | (v107 << 16) | (v107 << 19);
  v50 = v37 << 48;
  v51 = v118;
  v103 = v49;
  v104 = v32;
  v108 = v50 | ((unsigned __int64)(unsigned __int16)v36 << 32);
  while ( 2 )
  {
    *((_DWORD *)v6 + 8) = 0;
    ++*(_DWORD *)(v45 + 4);
    ++*(_DWORD *)(v112 + 8);
    v6[2] = 0;
    v6[4] = 0;
    v6[21] = 0;
    v6[22] = 0;
    v6[19] = 0;
    v6[20] = 0;
    v6[17] = 0;
    v6[18] = 0;
    v6[15] = 0;
    v6[16] = 0;
    v6[13] = 0;
    v6[14] = 0;
    v6[11] = 0;
    v6[12] = 0;
    v6[9] = 0;
    v6[10] = 0;
    v6[7] = 0;
    v6[8] = 0;
    v6[6] = 0;
    v6[3] = 0;
    v6[5] = 0;
    v6[1] = 33488897;
    *(__int64 *)((char *)v6 + 20) = v49 | (unsigned __int16)v113;
    v119 = v6 + 5;
    v52 = ((unsigned __int64)*(unsigned __int16 *)(v111 + 12) >> 1) & 0x100 | 0x1FF0001;
    v6[1] = v52;
    v53 = v52 | ((unsigned __int64)*(unsigned __int16 *)(v111 + 12) >> 1) & 0x200;
    v6[1] = v53;
    v54 = v53 | ((unsigned __int64)*(unsigned __int16 *)(v111 + 12) >> 1) & 0x800;
    v6[1] = v54;
    v55 = v54 | ((unsigned __int64)*(unsigned __int16 *)(v111 + 12) >> 1) & 0x1000;
    v6[1] = v55;
    v56 = v55 & 0x1FF5FFF | ((unsigned __int64)*(unsigned __int16 *)(v111 + 12) >> 1) & 0x2000;
    v6[1] = v56;
    v57 = *(unsigned __int16 *)(v111 + 12);
    *((_DWORD *)v6 + 4) = v116;
    *((_WORD *)v6 + 20) = v32;
    *((_DWORD *)v6 + 9) = v48;
    v6[1] = v56 & 0x1FF3FFF | (v57 >> 1) & 0x4000;
    v6[6] = v114;
    v6[7] = v109;
    qdf_trace_msg(
      69,
      0,
      "%s %d eit hdr %pK eit_hdr_len %d tcp_seq_num %u tso_info->total_len %u\n",
      "__qdf_nbuf_fill_tso_cmn_seg_info",
      4869);
    if ( v110 == 1 )
      v6[1] = v6[1] & 0xFFFFFFFFFFFFFBFFLL | ((((unsigned __int64)*(unsigned __int16 *)(v111 + 12) >> 11) & 1) << 10);
    if ( !v121 )
    {
LABEL_96:
      result = *(unsigned int *)(v115 + 4);
      goto LABEL_115;
    }
    v58 = *((unsigned int *)v6 + 2);
    v106 = v6 + 2;
    v59 = 1;
    v60 = 1;
    LOWORD(v113) = v113 + 1;
    ++*((_DWORD *)v6 + 8);
    v6[1] = v58 | v108;
    while ( v60 )
    {
      if ( (_DWORD)v40 )
      {
        if ( v59 >= 6 )
          goto LABEL_121;
        v61 = &v119[3 * v59];
        v62 = v59;
        *((_WORD *)v6 + 7) += v40;
        v63 = *((_DWORD *)v6 + 8);
        v64 = *((_DWORD *)v6 + 9);
        *(_WORD *)v61 = v40;
        v61[1] = v39;
        v61[2] = v44;
        *((_DWORD *)v6 + 8) = v63 + 1;
        *((_DWORD *)v6 + 9) = v64 + v40;
        v121 -= v40;
        v116 += v40;
        if ( !v44 )
        {
          v65 = printk(
                  &unk_AAA255,
                  "curr_seg->seg.tso_frags[i].paddr",
                  "__qdf_nbuf_get_tso_info",
                  "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/qdf/linux/src/qdf_nbuf.c");
          dump_stack(v65);
        }
      }
      else
      {
        if ( v59 > 5 )
          goto LABEL_121;
        v62 = v59;
      }
      qdf_trace_msg(
        69,
        0,
        "%s[%d] frag %d frag len %d total_len %u vaddr %pK\n",
        "__qdf_nbuf_get_tso_info",
        5221,
        v59,
        v40,
        *((_DWORD *)v6 + 9),
        (const void *)v119[3 * v62 + 1]);
      if ( !v121 )
        goto LABEL_96;
      v66 = v122;
      if ( v51 <= (unsigned int)v40 )
        goto LABEL_64;
      if ( !(_DWORD)v40 )
      {
        v60 = 1;
        goto LABEL_71;
      }
      if ( *((_DWORD *)v6 + 8) == 6 )
      {
LABEL_64:
        v60 = 0;
        v59 = 1;
        v51 = *(unsigned __int16 *)(*(_QWORD *)(a2 + 216) + *(unsigned int *)(a2 + 212) + 4LL);
        if ( !(_DWORD)v40 )
          goto LABEL_71;
      }
      else
      {
        ++v59;
        v60 = 1;
        v51 -= v40;
      }
      v67 = v38 >= (unsigned int)v40;
      v68 = v38 - v40;
      if ( v68 != 0 && v67 )
      {
        v39 += (unsigned int)v40;
        if ( v68 >= v51 )
          LODWORD(v40) = v51;
        else
          LODWORD(v40) = v68;
        goto LABEL_81;
      }
LABEL_71:
      v69 = *(_QWORD *)(a2 + 216) + *(unsigned int *)(a2 + 212);
      v70 = *(unsigned __int8 *)(v69 + 2);
      if ( !*(_BYTE *)(v69 + 2) )
      {
        qdf_trace_msg(56, 4, "%s: TSO: nr_frags == 0!", "__qdf_nbuf_get_tso_info");
        goto LABEL_114;
      }
      if ( (int)v122 >= v70 )
      {
        qdf_trace_msg(56, 4, "%s: TSO: nr_frags %d j %d", "__qdf_nbuf_get_tso_info", v70, v122);
        goto LABEL_114;
      }
      if ( v122 > 0x11 )
LABEL_121:
        __break(0x5512u);
      v71 = v69 + 16LL * v122;
      v74 = *(_QWORD *)(v71 + 88);
      v72 = v71 + 88;
      v73 = v74;
      v68 = *(_DWORD *)(v72 + 8);
      if ( v68 >= v51 )
        LODWORD(v40) = v51;
      else
        LODWORD(v40) = *(_DWORD *)(v72 + 8);
      if ( (v73 & 1) != 0 )
        v75 = 0;
      else
        v75 = v73;
      v39 = (((v75 << 6) + 0xFFFFD000000000LL) & 0xFFFFFFFFFFF000LL | 0xFF00000000000000LL)
          + *(unsigned int *)(v72 + 12);
      v66 = v122 + 1;
LABEL_81:
      qdf_trace_msg(
        69,
        0,
        "%s[%d] skb frag len %d tso frag %d len tso_seg_size %d\n",
        "__qdf_nbuf_get_tso_info",
        5282,
        v68,
        v40,
        v51);
      if ( !v39 )
      {
        qdf_trace_msg(69, 0, "%s: Fragment virtual addr is NULL", "__qdf_nbuf_get_tso_info");
        goto LABEL_114;
      }
      v122 = v66;
      v76 = v68;
      v77 = v6;
      v78 = v51;
      v79 = *(const char ***)(a1 + 40);
      v80 = is_vmalloc_addr(v39);
      v81 = v80;
      if ( (v80 & 1) != 0 && (dma_map_single_attrs___already_done & 1) == 0 )
      {
        dma_map_single_attrs___already_done = 1;
        v83 = (const char *)dev_driver_string(v79);
        v84 = v79[14];
        if ( !v84 )
          v84 = *v79;
        _warn_printk("%s %s: rejecting DMA map of vmalloc memory\n", v83, v84);
        __break(0x800u);
        if ( (v81 & 1) != 0 )
          goto LABEL_119;
      }
      else if ( (v80 & 1) != 0 )
      {
        goto LABEL_119;
      }
      v82 = dma_map_page_attrs(
              v79,
              ((unsigned __int64)(((__int64)(v39 << 8) >> 8) + 0x8000000000LL) >> 12 << 6) - 0x140000000LL,
              v39 & 0xFFF,
              (unsigned int)v40,
              1,
              0);
      if ( v82 == -1 )
        goto LABEL_119;
      v44 = v82;
      qdf_mem_dp_tx_skb_cnt_inc();
      qdf_mem_dp_tx_skb_inc((int)v40);
      qdf_mem_skb_total_inc((int)v40);
      v51 = v78;
      v6 = v77;
      v38 = v76;
      if ( !v44 )
        goto LABEL_114;
    }
    qdf_trace_msg(69, 0, "%s tcp_seq_num: %u", "__qdf_nbuf_get_tso_info", *v106);
    if ( --v110 )
    {
      v49 = v103;
      LOWORD(v32) = v104;
      v6 = (__int64 *)*v6;
      v45 = v115;
      v48 = v102;
      if ( v6 )
        continue;
    }
    else
    {
      v45 = v115;
      v6[1] = v6[1] & 0xFFFFFFFFFFFFFF7FLL | ((((unsigned __int64)*(unsigned __int16 *)(v111 + 12) >> 8) & 1) << 7);
    }
    break;
  }
  result = *(unsigned int *)(v45 + 4);
LABEL_115:
  _ReadStatusReg(SP_EL0);
  return result;
}
