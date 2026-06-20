__int64 __fastcall ipa3_wan_rx_pyld_hdlr(__int64 a1, __int64 a2)
{
  __int64 v3; // x19
  int v4; // w8
  __int64 v5; // x8
  __int64 v6; // x2
  __int64 v7; // x0
  _DWORD *v8; // x9
  int v9; // w24
  unsigned int v10; // w4
  __int64 v11; // x0
  __int64 v12; // x2
  __int64 v13; // x0
  __int64 skb; // x0
  __int64 v15; // x21
  unsigned int size; // w0
  __int64 v17; // x8
  __int64 v18; // x0
  _DWORD *v19; // x9
  unsigned int v20; // w0
  unsigned int v21; // w4
  unsigned int v22; // w21
  unsigned int v23; // w26
  __int64 v24; // x0
  __int64 v25; // x1
  __int64 v26; // x0
  __int64 v27; // x24
  __int64 v28; // x0
  __int64 v29; // x8
  unsigned int v30; // w9
  __int64 v31; // x11
  __int64 v32; // x12
  _QWORD *v33; // x8
  __int64 v34; // x9
  __int64 v35; // x9
  __int64 v36; // x11
  __int64 v37; // x12
  __int64 v38; // x9
  __int64 v39; // x11
  __int64 v40; // x12
  __int64 v41; // x8
  __int64 v42; // x9
  __int64 v43; // x8
  unsigned int v44; // w10
  int ep_mapping; // w0
  __int64 v46; // x8
  unsigned int v47; // w24
  __int64 v48; // x0
  unsigned int v49; // w25
  __int64 v50; // x0
  unsigned int v51; // w24
  __int64 v52; // x0
  __int64 v53; // x0
  __int64 v54; // x8
  int v55; // w10
  __int64 v56; // x0
  unsigned int v57; // w4
  __int64 v58; // x25
  __int64 v59; // x0
  __int64 v60; // x8
  __int64 v61; // x0
  __int64 v62; // x0
  __int64 v63; // x8
  __int64 v64; // x0
  _DWORD *v65; // x9
  __int64 v66; // x8
  __int64 v67; // x0
  __int64 v68; // x0
  __int64 v69; // x8
  __int64 v70; // x0
  __int64 v71; // x0
  __int64 v72; // x8
  __int64 v73; // x0
  __int64 v74; // x0
  __int64 v75; // x0
  __int64 v76; // x8
  __int64 v77; // x0
  __int64 v78; // x8
  __int64 v79; // x0
  __int64 v80; // x0
  __int64 v81; // x8
  __int64 v82; // x0
  __int64 v83; // x0
  int v84; // w21
  __int64 v85; // x8
  __int64 v86; // x0
  __int64 v87; // x0
  __int64 v88; // x8
  __int64 v89; // x0
  __int64 v90; // x0
  void (__fastcall *v91)(_QWORD); // x8
  unsigned __int64 v93; // [xsp+10h] [xbp-80h]
  __int64 v94; // [xsp+18h] [xbp-78h]
  __int64 v95; // [xsp+20h] [xbp-70h]
  __int64 v96; // [xsp+28h] [xbp-68h] BYREF
  __int64 v97; // [xsp+30h] [xbp-60h]
  __int64 v98; // [xsp+38h] [xbp-58h]
  __int64 v99; // [xsp+40h] [xbp-50h]
  __int64 v100; // [xsp+48h] [xbp-48h]
  __int64 v101; // [xsp+50h] [xbp-40h]
  __int64 v102; // [xsp+58h] [xbp-38h]
  __int64 v103; // [xsp+60h] [xbp-30h]
  __int64 v104; // [xsp+68h] [xbp-28h]
  __int64 v105; // [xsp+70h] [xbp-20h]
  __int64 v106; // [xsp+78h] [xbp-18h]
  __int64 v107; // [xsp+80h] [xbp-10h]
  __int64 v108; // [xsp+88h] [xbp-8h]

  v3 = a1;
  v108 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_DWORD *)(a1 + 112);
  v106 = 0;
  v107 = 0;
  v104 = 0;
  v105 = 0;
  v102 = 0;
  v103 = 0;
  v100 = 0;
  v101 = 0;
  v98 = 0;
  v99 = 0;
  v96 = 0;
  v97 = 0;
  if ( !v4 )
  {
    printk(&unk_3C9A2C, "ipa3_wan_rx_pyld_hdlr");
    v72 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v73 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v73 )
      {
        ipc_log_string(v73, "ipa %s:%d ZLT\n", "ipa3_wan_rx_pyld_hdlr", 4346);
        v72 = ipa3_ctx;
      }
      v74 = *(_QWORD *)(v72 + 34160);
      if ( v74 )
        ipc_log_string(v74, "ipa %s:%d ZLT\n", "ipa3_wan_rx_pyld_hdlr", 4346);
    }
    goto LABEL_137;
  }
  if ( *(_BYTE *)(ipa3_ctx + 43344) == 1 )
  {
    v5 = *(_QWORD *)(a2 + 1624);
    v6 = a1;
    v7 = *(_QWORD *)(v5 + 368);
    v8 = *(_DWORD **)(v5 + 376);
    if ( *(v8 - 1) != 420538815 )
      __break(0x8229u);
    ((void (__fastcall *)(__int64, _QWORD, __int64))v8)(v7, 0, v6);
    goto LABEL_140;
  }
  v9 = *(_DWORD *)(a1 + 40);
  if ( *(void *(__fastcall **)(_QWORD *))(a2 + 360) == ipa3_replenish_rx_cache_recycle )
  {
    v75 = printk(&unk_3E9603, "ipa3_wan_rx_pyld_hdlr");
    v76 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v77 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v77 )
      {
        ipc_log_string(v77, "ipa %s:%d Recycle should enable only with GRO Aggr\n", "ipa3_wan_rx_pyld_hdlr", 4356);
        v76 = ipa3_ctx;
      }
      v75 = *(_QWORD *)(v76 + 34160);
      if ( v75 )
        v75 = ipc_log_string(v75, "ipa %s:%d Recycle should enable only with GRO Aggr\n", "ipa3_wan_rx_pyld_hdlr", 4356);
    }
    a1 = ((__int64 (__fastcall *)(__int64))ipa_assert)(v75);
    v10 = *(_DWORD *)(a2 + 176);
    if ( !v10 )
      goto LABEL_24;
    goto LABEL_8;
  }
  v10 = *(_DWORD *)(a2 + 176);
  if ( v10 )
  {
LABEL_8:
    if ( ipa3_ctx )
    {
      v11 = *(_QWORD *)(ipa3_ctx + 34160);
      if ( v11 )
      {
        ipc_log_string(
          v11,
          "ipa %s:%d rem %d skb %d\n",
          "ipa3_wan_rx_handle_splt_pyld",
          4276,
          v10,
          *(_DWORD *)(v3 + 112));
        v10 = *(_DWORD *)(a2 + 176);
      }
    }
    v12 = *(unsigned int *)(v3 + 112);
    v13 = *(_QWORD *)(a2 + 168);
    if ( v10 <= (unsigned int)v12 )
    {
      if ( v13 )
      {
        skb = ipa3_join_prev_skb(v13, v3, v10);
        if ( skb )
        {
          v15 = skb;
          if ( ipa3_ctx )
          {
            skb = *(_QWORD *)(ipa3_ctx + 34160);
            if ( skb )
              skb = ipc_log_string(
                      skb,
                      "ipa %s:%d removing Status element from skb and sending to WAN client",
                      "ipa3_wan_rx_handle_splt_pyld",
                      4283);
          }
          size = ipahal_pkt_status_get_size(skb);
          skb_pull(v15, size);
          *(_DWORD *)(v15 + 232) = *(_DWORD *)(v15 + 112) + 248;
          v17 = *(_QWORD *)(a2 + 1624);
          v18 = *(_QWORD *)(v17 + 368);
          v19 = *(_DWORD **)(v17 + 376);
          if ( *(v19 - 1) != 420538815 )
            __break(0x8229u);
          ((void (__fastcall *)(__int64, _QWORD, __int64))v19)(v18, 0, v15);
        }
      }
      a1 = skb_pull(v3, *(unsigned int *)(a2 + 176));
      *(_QWORD *)(a2 + 168) = 0;
      *(_DWORD *)(a2 + 176) = 0;
    }
    else
    {
      if ( v13 )
      {
        *(_QWORD *)(a2 + 168) = ipa3_join_prev_skb(v13, v3, v12);
        v10 = *(_DWORD *)(a2 + 176);
        LODWORD(v12) = *(_DWORD *)(v3 + 112);
      }
      *(_DWORD *)(a2 + 176) = v10 - v12;
      a1 = skb_pull(v3, *(unsigned int *)(v3 + 112));
    }
  }
LABEL_24:
  v20 = ipahal_pkt_status_get_size(a1);
  v21 = *(_DWORD *)(v3 + 112);
  if ( !v21 )
    goto LABEL_137;
  v22 = v20;
  v23 = v20 + 4;
  v94 = (unsigned int)(0x2000 - v9);
  v93 = (v9 + 31) & 0xFFFFFFE0;
  v95 = v20;
  while ( 1 )
  {
    if ( ipa3_ctx )
    {
      v26 = *(_QWORD *)(ipa3_ctx + 34160);
      if ( v26 )
      {
        ipc_log_string(v26, "ipa %s:%d LEN_REM %d\n", "ipa3_wan_rx_pyld_hdlr", 4369, v21);
        v21 = *(_DWORD *)(v3 + 112);
      }
    }
    if ( v21 < v22 )
      break;
    ((void (__fastcall *)(_QWORD, __int64 *))ipahal_pkt_status_parse)(*(_QWORD *)(v3 + 224), &v96);
    v27 = *(_QWORD *)(v3 + 224);
    if ( ipa3_ctx )
    {
      v28 = *(_QWORD *)(ipa3_ctx + 34160);
      if ( v28 )
        ipc_log_string(
          v28,
          "ipa %s:%d STATUS opcode=%d src=%d dst=%d len=%d ttl_dec=%d\n",
          "ipa3_wan_rx_pyld_hdlr",
          4379,
          v97,
          BYTE2(v103),
          BYTE3(v103),
          HIDWORD(v98),
          BYTE1(v107));
    }
    v29 = *(_QWORD *)(a2 + 1768);
    if ( v29 )
    {
      v30 = *(_DWORD *)(v29 + 2880);
      if ( v30 >= 0x1F )
        __break(0x5512u);
      v31 = v96;
      v32 = v97;
      v33 = (_QWORD *)(v29 + 96LL * v30);
      v34 = v99;
      v33[2] = v98;
      v33[3] = v34;
      *v33 = v31;
      v33[1] = v32;
      v35 = v103;
      v36 = v100;
      v37 = v101;
      v33[6] = v102;
      v33[7] = v35;
      v33[4] = v36;
      v33[5] = v37;
      v38 = v107;
      v39 = v104;
      v40 = v105;
      v33[10] = v106;
      v33[11] = v38;
      v33[8] = v39;
      v33[9] = v40;
      ++*(_DWORD *)(*(_QWORD *)(a2 + 1768) + 2880LL);
      v41 = *(_QWORD *)(a2 + 1768);
      if ( *(_DWORD *)(v41 + 2880) == 30 )
        *(_DWORD *)(v41 + 2880) = 0;
    }
    if ( (unsigned int)v97 > 6 || ((1 << v97) & 0x45) == 0 )
    {
      printk(&unk_3B21A1, "ipa3_wan_rx_pyld_hdlr");
      v66 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v67 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v67 )
        {
          ipc_log_string(v67, "ipa %s:%d unsupported opcode(%d)\n", "ipa3_wan_rx_pyld_hdlr", 4396, v97);
          v66 = ipa3_ctx;
        }
        v68 = *(_QWORD *)(v66 + 34160);
        if ( v68 )
          ipc_log_string(v68, "ipa %s:%d unsupported opcode(%d)\n", "ipa3_wan_rx_pyld_hdlr", 4396, v97);
      }
      v24 = v3;
      v25 = v22;
      goto LABEL_27;
    }
    v42 = ipa3_ctx;
    v43 = ipa3_ctx + 32288;
    ++*(_DWORD *)(ipa3_ctx + 32288);
    if ( BYTE1(v107) == 1 )
      ++*(_DWORD *)(v43 + 1848);
    v44 = *(_DWORD *)(v43 + 2020);
    if ( v44 <= BYTE3(v103) || v44 <= BYTE2(v103) )
    {
      printk(&unk_3A6A9E, "ipa3_wan_rx_pyld_hdlr");
      v81 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v82 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v82 )
        {
          ipc_log_string(v82, "ipa %s:%d status fields invalid\n", "ipa3_wan_rx_pyld_hdlr", 4406);
          v81 = ipa3_ctx;
        }
        v83 = *(_QWORD *)(v81 + 34160);
        if ( v83 )
          ipc_log_string(v83, "ipa %s:%d status fields invalid\n", "ipa3_wan_rx_pyld_hdlr", 4406);
      }
      goto LABEL_136;
    }
    if ( !HIDWORD(v98) )
    {
      if ( v42 )
      {
        v53 = *(_QWORD *)(v43 + 1872);
        if ( v53 )
          ipc_log_string(v53, "ipa %s:%d Skip aggr close status\n", "ipa3_wan_rx_pyld_hdlr", 4411);
      }
      skb_pull(v3, v22);
      v54 = ipa3_ctx + 32288;
      v55 = *(_DWORD *)(ipa3_ctx + 32836) + 1;
      --*(_DWORD *)(ipa3_ctx + 32288);
      *(_DWORD *)(v54 + 548) = v55;
      goto LABEL_28;
    }
    ep_mapping = ipa_get_ep_mapping(35);
    if ( ep_mapping != BYTE3(v103) )
    {
      v84 = ep_mapping;
      printk(&unk_3F7F1F, "ipa3_wan_rx_pyld_hdlr");
      v85 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v86 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v86 )
        {
          ipc_log_string(
            v86,
            "ipa %s:%d expected endp_dest_idx %d received %d\n",
            "ipa3_wan_rx_pyld_hdlr",
            4420,
            v84,
            BYTE3(v103));
          v85 = ipa3_ctx;
        }
        v87 = *(_QWORD *)(v85 + 34160);
        if ( v87 )
          ipc_log_string(
            v87,
            "ipa %s:%d expected endp_dest_idx %d received %d\n",
            "ipa3_wan_rx_pyld_hdlr",
            4420,
            v84,
            BYTE3(v103));
      }
      goto LABEL_136;
    }
    if ( *(_DWORD *)(v3 + 112) == v22 )
    {
      printk(&unk_3E9639, "ipa3_wan_rx_pyld_hdlr");
      v88 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v89 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v89 )
        {
          ipc_log_string(v89, "ipa %s:%d Ins header in next buffer\n", "ipa3_wan_rx_pyld_hdlr", 4426);
          v88 = ipa3_ctx;
        }
        v90 = *(_QWORD *)(v88 + 34160);
        if ( v90 )
          ipc_log_string(v90, "ipa %s:%d Ins header in next buffer\n", "ipa3_wan_rx_pyld_hdlr", 4426);
      }
      goto LABEL_136;
    }
    v46 = ipa3_ctx;
    v47 = bswap32(*(unsigned __int16 *)(v27 + v95 + 2)) >> 16;
    if ( !ipa3_ctx )
    {
      v49 = v98 & 0x100;
LABEL_64:
      if ( v49 )
        v51 = v23 + v47 + 8;
      else
        v51 = v23 + v47;
      goto LABEL_73;
    }
    v48 = *(_QWORD *)(ipa3_ctx + 34160);
    if ( v48 )
    {
      ipc_log_string(v48, "ipa %s:%d pkt_len with pad %d\n", "ipa3_wan_rx_pyld_hdlr", 4438, v47);
      v46 = ipa3_ctx;
      v49 = v98 & 0x100;
      if ( !ipa3_ctx )
        goto LABEL_64;
      v50 = *(_QWORD *)(ipa3_ctx + 34160);
      if ( v50 )
      {
LABEL_53:
        ipc_log_string(v50, "ipa %s:%d checksum_trailer_exists %d\n", "ipa3_wan_rx_pyld_hdlr", 4443, v49 >> 8);
        if ( v49 )
          v51 = v23 + v47 + 8;
        else
          v51 = v23 + v47;
        if ( ipa3_ctx )
        {
          v52 = *(_QWORD *)(ipa3_ctx + 34160);
          if ( v52 )
            goto LABEL_72;
        }
        goto LABEL_73;
      }
    }
    else
    {
      v49 = v98 & 0x100;
      v50 = *(_QWORD *)(ipa3_ctx + 34160);
      if ( v50 )
        goto LABEL_53;
    }
    if ( v49 )
      v51 = v23 + v47 + 8;
    else
      v51 = v23 + v47;
    v52 = *(_QWORD *)(v46 + 34160);
    if ( v52 )
LABEL_72:
      ipc_log_string(v52, "ipa %s:%d frame_len %d\n", "ipa3_wan_rx_pyld_hdlr", 4449, v51);
LABEL_73:
    v56 = skb_clone(v3, 3264);
    if ( v56 )
    {
      v57 = *(_DWORD *)(v3 + 112);
      v58 = v56;
      if ( v57 >= v51 )
      {
        skb_trim(v56, v51);
        v60 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v61 = *(_QWORD *)(ipa3_ctx + 34160);
          if ( !v61
            || (ipc_log_string(v61, "ipa %s:%d rx avail for %d\n", "ipa3_wan_rx_pyld_hdlr", 4466, BYTE3(v103)),
                (v60 = ipa3_ctx) != 0) )
          {
            v62 = *(_QWORD *)(v60 + 34160);
            if ( v62 )
              ipc_log_string(
                v62,
                "ipa %s:%d removing Status element from skb and sending to WAN client",
                "ipa3_wan_rx_pyld_hdlr",
                4468);
          }
        }
        skb_pull(v58, v22);
        *(_DWORD *)(v58 + 232) = *(_DWORD *)(v58 + 112) + (int)((v51 + 31) & 0xFFFFFFE0) * v94 / v93 + 248;
        v63 = *(_QWORD *)(a2 + 1624);
        v64 = *(_QWORD *)(v63 + 368);
        v65 = *(_DWORD **)(v63 + 376);
        if ( *(v65 - 1) != 420538815 )
          __break(0x8229u);
        ((void (__fastcall *)(__int64, _QWORD, __int64))v65)(v64, 0, v58);
LABEL_88:
        v24 = v3;
        v25 = v51;
        goto LABEL_27;
      }
      if ( ipa3_ctx )
      {
        v59 = *(_QWORD *)(ipa3_ctx + 34160);
        if ( v59 )
          ipc_log_string(v59, "ipa %s:%d SPL skb len %d len %d\n", "ipa3_wan_rx_pyld_hdlr", 4459, v57, v51);
      }
      *(_QWORD *)(a2 + 168) = v58;
    }
    else
    {
      printk(&unk_3F7F52, "ipa3_wan_rx_pyld_hdlr");
      v69 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v70 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v70 )
        {
          ipc_log_string(v70, "ipa %s:%d fail to clone\n", "ipa3_wan_rx_pyld_hdlr", 4479);
          v69 = ipa3_ctx;
        }
        v71 = *(_QWORD *)(v69 + 34160);
        if ( v71 )
          ipc_log_string(v71, "ipa %s:%d fail to clone\n", "ipa3_wan_rx_pyld_hdlr", 4479);
      }
      if ( *(_DWORD *)(v3 + 112) >= v51 )
        goto LABEL_88;
      *(_QWORD *)(a2 + 168) = 0;
    }
    v24 = v3;
    *(_DWORD *)(a2 + 176) = v51 - *(_DWORD *)(v3 + 112);
    v25 = *(unsigned int *)(v3 + 112);
LABEL_27:
    skb_pull(v24, v25);
LABEL_28:
    v21 = *(_DWORD *)(v3 + 112);
    if ( !v21 )
      goto LABEL_137;
  }
  printk(&unk_3C6C8F, "ipa3_wan_rx_pyld_hdlr");
  v78 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v79 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v79 )
    {
      ipc_log_string(v79, "ipa %s:%d status straddles buffer\n", "ipa3_wan_rx_pyld_hdlr", 4371);
      v78 = ipa3_ctx;
    }
    v80 = *(_QWORD *)(v78 + 34160);
    if ( v80 )
      ipc_log_string(v80, "ipa %s:%d status straddles buffer\n", "ipa3_wan_rx_pyld_hdlr", 4371);
  }
LABEL_136:
  __break(0x800u);
LABEL_137:
  v91 = *(void (__fastcall **)(_QWORD))(a2 + 144);
  if ( *((_DWORD *)v91 - 1) != 303786302 )
    __break(0x8228u);
  v91(v3);
LABEL_140:
  _ReadStatusReg(SP_EL0);
  return 0;
}
