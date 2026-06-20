__int64 __fastcall ipa3_lan_rx_pyld_hdlr(__int64 a1, __int64 a2)
{
  __int64 v2; // x19
  unsigned int v3; // w5
  unsigned int v4; // w4
  int v5; // w23
  __int64 v7; // x0
  void *v8; // x0
  __int64 (__fastcall *v9)(_QWORD); // x8
  __int64 v10; // x0
  unsigned int size; // w0
  unsigned int v12; // w21
  __int64 v13; // x8
  __int64 v14; // x0
  __int64 v15; // x8
  __int64 v16; // x0
  __int64 v17; // x8
  unsigned int v18; // w9
  __int64 v19; // x11
  __int64 v20; // x12
  _QWORD *v21; // x8
  __int64 v22; // x9
  __int64 v23; // x9
  __int64 v24; // x11
  __int64 v25; // x12
  __int64 v26; // x9
  __int64 v27; // x11
  __int64 v28; // x12
  __int64 v29; // x8
  __int64 v30; // x8
  unsigned int v31; // w8
  __int64 v32; // x8
  __int64 v33; // x0
  __int64 v34; // x0
  __int64 v35; // x0
  __int64 v36; // x8
  __int64 v37; // x0
  __int64 v38; // x0
  __int64 v39; // x23
  __int64 v40; // x8
  __int64 v41; // x0
  __int64 v42; // x0
  __int64 v43; // x8
  __int64 v44; // x0
  __int64 v45; // x0
  __int64 v46; // x0
  unsigned int v47; // w28
  int v48; // w8
  unsigned int v49; // w27
  __int64 v50; // x9
  unsigned int v51; // w22
  unsigned int v52; // w27
  __int64 v53; // x0
  __int64 v54; // x0
  __int64 v55; // x0
  int *v56; // x8
  int v57; // w10
  __int64 v58; // x8
  __int64 v59; // x0
  __int64 v60; // x0
  __int64 v61; // x8
  __int64 v62; // x9
  __int64 v63; // x0
  __int64 v64; // x0
  int *v65; // x8
  int v66; // w10
  int v67; // w23
  __int64 v68; // x8
  __int64 v69; // x0
  __int64 v70; // x0
  __int64 v71; // x8
  void *v72; // x9
  void *v73; // x8
  int v74; // w9
  unsigned int v75; // w26
  __int64 v76; // x2
  __int64 v77; // x0
  int v78; // w9
  __int64 v79; // x23
  void *v80; // x0
  int v81; // w8
  int v82; // w9
  unsigned int v83; // w8
  unsigned int v84; // w26
  unsigned int v85; // w4
  __int64 v86; // x0
  __int64 v87; // x0
  __int64 v88; // x8
  __int64 v89; // x0
  _DWORD *v90; // x9
  __int64 v91; // x8
  __int64 v92; // x9
  __int64 v93; // x0
  __int64 v94; // x0
  __int64 v95; // x8
  __int64 v96; // x0
  __int64 v97; // x0
  __int64 v98; // x8
  __int64 v99; // x0
  __int64 v100; // x0
  __int64 v101; // x8
  __int64 v102; // x0
  __int64 v103; // x0
  __int64 v104; // x8
  __int64 v105; // x0
  __int64 v106; // x0
  unsigned int v113; // w8
  unsigned int v114; // w8
  unsigned int v115; // w4
  __int64 v116; // x0
  __int64 v117; // x0
  __int64 v118; // x0
  __int64 v119; // x21
  size_t v120; // x22
  void *v121; // x0
  __int64 v122; // x8
  __int64 v123; // x0
  __int64 v124; // x1
  __int64 v126; // x0
  size_t v127; // x22
  __int64 v128; // x21
  void *v129; // x0
  __int64 v130; // x8
  __int64 v131; // x0
  __int64 v132; // x0
  __int64 v133; // x8
  __int64 v134; // x0
  _DWORD *v135; // x9
  __int64 v136; // x0
  __int64 v137; // x8
  __int64 v138; // x0
  __int64 v139; // x0
  __int64 v140; // x8
  __int64 v141; // x0
  __int64 v142; // x0
  __int64 v143; // x8
  __int64 v144; // x0
  __int64 v145; // x0
  unsigned int v146; // [xsp+10h] [xbp-90h]
  unsigned __int64 v147; // [xsp+18h] [xbp-88h]
  void *v148; // [xsp+20h] [xbp-80h]
  unsigned int v149; // [xsp+2Ch] [xbp-74h]
  unsigned __int64 v150; // [xsp+30h] [xbp-70h]
  __int64 v151; // [xsp+38h] [xbp-68h] BYREF
  __int64 v152; // [xsp+40h] [xbp-60h]
  __int64 v153; // [xsp+48h] [xbp-58h]
  __int64 v154; // [xsp+50h] [xbp-50h]
  __int64 v155; // [xsp+58h] [xbp-48h]
  __int64 v156; // [xsp+60h] [xbp-40h]
  __int64 v157; // [xsp+68h] [xbp-38h]
  __int64 v158; // [xsp+70h] [xbp-30h]
  __int64 v159; // [xsp+78h] [xbp-28h]
  __int64 v160; // [xsp+80h] [xbp-20h]
  __int64 v161; // [xsp+88h] [xbp-18h]
  __int64 v162; // [xsp+90h] [xbp-10h]
  __int64 v163; // [xsp+98h] [xbp-8h]

  v2 = a1;
  v163 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_DWORD *)(a1 + 112);
  v161 = 0;
  v162 = 0;
  v159 = 0;
  v160 = 0;
  v157 = 0;
  v158 = 0;
  v155 = 0;
  v156 = 0;
  v153 = 0;
  v154 = 0;
  v151 = 0;
  v152 = 0;
  if ( v3 )
  {
    v4 = *(_DWORD *)(a2 + 184);
    v5 = *(_DWORD *)(a1 + 40);
    if ( v4 )
    {
      if ( ipa3_ctx )
      {
        v7 = *(_QWORD *)(ipa3_ctx + 34160);
        if ( v7 )
        {
          ipc_log_string(v7, "ipa %s:%d len_partial %d\n", "ipa3_lan_rx_pyld_hdlr", 3959, v4);
          v4 = *(_DWORD *)(a2 + 184);
        }
      }
      v8 = (void *)skb_push(v2, v4);
      memcpy(v8, *(const void **)(*(_QWORD *)(a2 + 168) + 224LL), *(unsigned int *)(a2 + 184));
      v9 = *(__int64 (__fastcall **)(_QWORD))(a2 + 144);
      v10 = *(_QWORD *)(a2 + 168);
      *(_DWORD *)(a2 + 184) = 0;
      if ( *((_DWORD *)v9 - 1) != 303786302 )
        __break(0x8228u);
      a1 = v9(v10);
      *(_QWORD *)(a2 + 168) = 0;
      goto LABEL_9;
    }
    v115 = *(_DWORD *)(a2 + 176);
    if ( !v115 )
    {
LABEL_9:
      size = ipahal_pkt_status_get_size(a1);
      if ( !*(_DWORD *)(v2 + 112) )
        goto LABEL_205;
      v12 = size;
      v147 = (v5 + 31) & 0xFFFFFFE0;
      v148 = &unk_3B7A49;
      v149 = 0;
      v150 = 0;
      v146 = 0x2000 - v5;
      _ReadStatusReg(SP_EL0);
      while ( 1 )
      {
        v13 = ipa3_ctx;
        *(_BYTE *)(a2 + 188) = 0;
        if ( v13 )
        {
          v14 = *(_QWORD *)(v13 + 34160);
          if ( v14 )
            ipc_log_string(v14, "ipa %s:%d LEN_REM %d\n", "ipa3_lan_rx_pyld_hdlr", 4031, *(_DWORD *)(v2 + 112));
        }
        if ( *(_DWORD *)(v2 + 112) < v12 )
        {
          if ( *(_QWORD *)(a2 + 168) )
          {
            __break(0x800u);
            v122 = ipa3_ctx;
            if ( !ipa3_ctx )
              goto LABEL_201;
          }
          else
          {
            v122 = ipa3_ctx;
            if ( !ipa3_ctx )
              goto LABEL_201;
          }
          v123 = *(_QWORD *)(v122 + 34160);
          if ( !v123 )
            goto LABEL_201;
          ipc_log_string(v123, "ipa %s:%d status straddles buffer\n", "ipa3_lan_rx_pyld_hdlr", 4035);
          goto LABEL_200;
        }
        ((void (__fastcall *)(_QWORD, __int64 *))ipahal_pkt_status_parse)(*(_QWORD *)(v2 + 224), &v151);
        v15 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v16 = *(_QWORD *)(ipa3_ctx + 34160);
          if ( v16 )
          {
            ipc_log_string(
              v16,
              "ipa %s:%d STATUS opcode=%d src=%d dst=%d len=%d\n",
              "ipa3_lan_rx_pyld_hdlr",
              4047,
              v152,
              BYTE2(v158),
              BYTE3(v158),
              HIDWORD(v153));
            v15 = ipa3_ctx;
          }
        }
        if ( *(_DWORD *)(v15 + 52488) )
        {
          *(_DWORD *)(v15 + 52488) = 0;
          v67 = ((__int64 (__fastcall *)(_QWORD))ipa3_get_client_by_pipe)(BYTE2(v158));
          printk(&unk_3AC9D8, "ipa3_lan_rx_pyld_hdlr");
          v68 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v69 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v69 )
            {
              ipc_log_string(
                v69,
                "ipa %s:%d Client %s woke up the system\n",
                "ipa3_lan_rx_pyld_hdlr",
                4051,
                ipa_clients_strings[v67]);
              v68 = ipa3_ctx;
            }
            v70 = *(_QWORD *)(v68 + 34160);
            if ( v70 )
              ipc_log_string(
                v70,
                "ipa %s:%d Client %s woke up the system\n",
                "ipa3_lan_rx_pyld_hdlr",
                4051,
                ipa_clients_strings[v67]);
          }
          if ( v2 )
          {
            v71 = *(_QWORD *)(v2 + 16);
            v72 = (void *)(v71 + 296);
            _ZF = v71 == 0;
            v73 = v148;
            if ( !_ZF )
              v73 = v72;
            v148 = v73;
          }
        }
        v17 = *(_QWORD *)(a2 + 1768);
        if ( v17 )
        {
          v18 = *(_DWORD *)(v17 + 2880);
          if ( v18 >= 0x1F )
            goto LABEL_243;
          v19 = v151;
          v20 = v152;
          v21 = (_QWORD *)(v17 + 96LL * v18);
          v22 = v154;
          v21[2] = v153;
          v21[3] = v22;
          *v21 = v19;
          v21[1] = v20;
          v23 = v158;
          v24 = v155;
          v25 = v156;
          v21[6] = v157;
          v21[7] = v23;
          v21[4] = v24;
          v21[5] = v25;
          v26 = v162;
          v27 = v159;
          v28 = v160;
          v21[10] = v161;
          v21[11] = v26;
          v21[8] = v27;
          v21[9] = v28;
          ++*(_DWORD *)(*(_QWORD *)(a2 + 1768) + 2880LL);
          v29 = *(_QWORD *)(a2 + 1768);
          if ( *(_DWORD *)(v29 + 2880) == 30 )
            *(_DWORD *)(v29 + 2880) = 0;
        }
        if ( (unsigned int)v152 > 6 )
          goto LABEL_89;
        if ( ((1 << v152) & 0x4D) == 0 )
        {
          if ( (_DWORD)v152 == 1 )
          {
            if ( (unsigned int)__ratelimit(&ipa3_lan_rx_pyld_hdlr__rs, "ipa3_lan_rx_pyld_hdlr") )
            {
              printk(&unk_3FB2D9, "ipa3_lan_rx_pyld_hdlr");
              v40 = ipa3_ctx;
              if ( ipa3_ctx )
              {
LABEL_56:
                v41 = *(_QWORD *)(v40 + 34152);
                if ( v41 )
                {
                  ipc_log_string(
                    v41,
                    "ipa %s:%d Frag packets received on lan consumer\n",
                    "ipa3_lan_rx_pyld_hdlr",
                    4073);
                  v40 = ipa3_ctx;
                }
                v42 = *(_QWORD *)(v40 + 34160);
                if ( v42 )
                  ipc_log_string(
                    v42,
                    "ipa %s:%d Frag packets received on lan consumer\n",
                    "ipa3_lan_rx_pyld_hdlr",
                    4073);
              }
            }
            else
            {
              v40 = ipa3_ctx;
              if ( ipa3_ctx )
                goto LABEL_56;
            }
            if ( (unsigned int)__ratelimit(&ipa3_lan_rx_pyld_hdlr__rs_329, "ipa3_lan_rx_pyld_hdlr") )
            {
              printk(&unk_3E95AB, "ipa3_lan_rx_pyld_hdlr");
              v43 = ipa3_ctx;
              if ( ipa3_ctx )
              {
LABEL_62:
                v44 = *(_QWORD *)(v43 + 34152);
                if ( v44 )
                {
                  ipc_log_string(
                    v44,
                    "ipa %s:%d STATUS opcode=%d src=%d dst=%d src ip=%x\n",
                    "ipa3_lan_rx_pyld_hdlr",
                    4076,
                    v152,
                    BYTE2(v158),
                    BYTE3(v158),
                    HIDWORD(v159));
                  v43 = ipa3_ctx;
                }
                v45 = *(_QWORD *)(v43 + 34160);
                if ( v45 )
                  ipc_log_string(
                    v45,
                    "ipa %s:%d STATUS opcode=%d src=%d dst=%d src ip=%x\n",
                    "ipa3_lan_rx_pyld_hdlr",
                    4076,
                    v152,
                    BYTE2(v158),
                    BYTE3(v158),
                    HIDWORD(v159));
              }
            }
            else
            {
              v43 = ipa3_ctx;
              if ( ipa3_ctx )
                goto LABEL_62;
            }
LABEL_11:
            skb_pull(v2, v12);
            goto LABEL_12;
          }
LABEL_89:
          if ( (unsigned int)__ratelimit(&ipa3_lan_rx_pyld_hdlr__rs_332, "ipa3_lan_rx_pyld_hdlr") )
          {
            printk(&unk_3B21A1, "ipa3_lan_rx_pyld_hdlr");
            v58 = ipa3_ctx;
            if ( !ipa3_ctx )
              goto LABEL_11;
          }
          else
          {
            v58 = ipa3_ctx;
            if ( !ipa3_ctx )
              goto LABEL_11;
          }
          v59 = *(_QWORD *)(v58 + 34152);
          if ( v59 )
          {
            ipc_log_string(v59, "ipa %s:%d unsupported opcode(%d)\n", "ipa3_lan_rx_pyld_hdlr", 4081, v152);
            v58 = ipa3_ctx;
          }
          v60 = *(_QWORD *)(v58 + 34160);
          if ( v60 )
            ipc_log_string(v60, "ipa %s:%d unsupported opcode(%d)\n", "ipa3_lan_rx_pyld_hdlr", 4081, v152);
          goto LABEL_11;
        }
        v30 = ipa3_ctx;
        if ( HIDWORD(v152) <= 0xE )
        {
          ++*(_DWORD *)(ipa3_ctx + 4LL * HIDWORD(v152) + 32292);
          v30 = ipa3_ctx;
        }
        v31 = *(_DWORD *)(v30 + 34308);
        if ( v31 <= BYTE3(v158) || v31 <= BYTE2(v158) )
          break;
        if ( (v153 & 0x10) == 0 )
          goto LABEL_69;
LABEL_46:
        if ( ipa3_ctx )
        {
          v38 = *(_QWORD *)(ipa3_ctx + 34160);
          if ( v38 )
            ipc_log_string(v38, "ipa %s:%d TAG packet arrived\n", "ipa3_lan_rx_pyld_hdlr", 4102);
        }
        if ( v151 == 1468208643 )
        {
          skb_pull(v2, v12);
          if ( *(_DWORD *)(v2 + 112) <= 7u )
          {
            printk(&unk_3DE2FB, "ipa3_lan_rx_pyld_hdlr");
            v137 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v138 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v138 )
              {
                ipc_log_string(v138, "ipa %s:%d TAG arrived without packet\n", "ipa3_lan_rx_pyld_hdlr", 4106);
                v137 = ipa3_ctx;
              }
              v139 = *(_QWORD *)(v137 + 34160);
              if ( v139 )
                ipc_log_string(v139, "ipa %s:%d TAG arrived without packet\n", "ipa3_lan_rx_pyld_hdlr", 4106);
            }
            goto LABEL_205;
          }
          v39 = **(_QWORD **)(v2 + 224);
          skb_pull(v2, 8);
          complete(v39);
          _X9 = (unsigned int *)(v39 + 32);
          __asm { PRFM            #0x11, [X9] }
          do
          {
            v113 = __ldxr(_X9);
            v114 = v113 - 1;
          }
          while ( __stlxr(v114, _X9) );
          __dmb(0xBu);
          if ( !v114 )
            kfree(v39);
          goto LABEL_12;
        }
        v150 = v151 | 0xFFFF000000000000LL;
        if ( ipa3_ctx )
        {
          v46 = *(_QWORD *)(ipa3_ctx + 34160);
          if ( v46 )
            ipc_log_string(
              v46,
              "ipa %s:%d tx_pkt recv = %pK\n",
              "ipa3_lan_rx_pyld_hdlr",
              4118,
              (const void *)(v151 | 0xFFFF000000000000LL));
        }
LABEL_69:
        if ( !HIDWORD(v153) )
        {
          if ( ipa3_ctx )
          {
            v55 = *(_QWORD *)(ipa3_ctx + 34160);
            if ( v55 )
              ipc_log_string(v55, "ipa %s:%d Skip aggr close status\n", "ipa3_lan_rx_pyld_hdlr", 4122);
          }
          skb_pull(v2, v12);
          v56 = (int *)(ipa3_ctx + 32292);
          v57 = *(_DWORD *)(ipa3_ctx + 32292) - 1;
          ++*(_DWORD *)(ipa3_ctx + 32832);
          *v56 = v57;
          goto LABEL_12;
        }
        v47 = BYTE2(v158);
        if ( 0xEEEEEEEEEEEEEEEFLL * ((*(_QWORD *)(a2 + 1624) - ipa3_ctx - 168) >> 5) == BYTE3(v158) )
        {
          v48 = HIDWORD(v152);
          if ( !HIDWORD(v152) )
          {
            if ( (((__int64 (__fastcall *)(_QWORD))ipahal_is_rule_miss_id)(WORD2(v157)) & 1) != 0 )
              *(_BYTE *)(a2 + 188) = 1;
            v48 = HIDWORD(v152);
            if ( *(_DWORD *)(v2 + 112) == v12 && !HIDWORD(v152) )
            {
              if ( !*(_QWORD *)(a2 + 168) )
              {
                v122 = ipa3_ctx;
                if ( ipa3_ctx )
                  goto LABEL_222;
                goto LABEL_201;
              }
              __break(0x800u);
              v122 = ipa3_ctx;
              if ( !ipa3_ctx )
                goto LABEL_201;
LABEL_222:
              v136 = *(_QWORD *)(v122 + 34160);
              if ( !v136 )
              {
LABEL_201:
                if ( *(_BYTE *)(v122 + 45390) )
                  v124 = 2080;
                else
                  v124 = 3264;
                *(_QWORD *)(a2 + 168) = skb_copy(v2, v124);
                *(_DWORD *)(a2 + 184) = *(_DWORD *)(v2 + 112);
                goto LABEL_205;
              }
              ipc_log_string(v136, "ipa %s:%d Ins header in next buffer\n", "ipa3_lan_rx_pyld_hdlr", 4147);
LABEL_200:
              v122 = ipa3_ctx;
              goto LABEL_201;
            }
          }
          v49 = v149;
          v50 = ipa3_ctx;
          if ( *(_DWORD *)(*(_QWORD *)(a2 + 1624) + 4LL) != 127 )
            v49 = ((HIDWORD(v153) + 3) & 0xFFFFFFFC) - HIDWORD(v153);
          v51 = v49;
          v52 = v49 + HIDWORD(v153);
          if ( ipa3_ctx )
          {
            v53 = *(_QWORD *)(ipa3_ctx + 34160);
            if ( v53 )
            {
              ipc_log_string(
                v53,
                "ipa %s:%d pad %d pkt_len %d len %d\n",
                "ipa3_lan_rx_pyld_hdlr",
                4167,
                v51,
                HIDWORD(v153),
                v52);
              v48 = HIDWORD(v152);
              v50 = ipa3_ctx;
            }
            if ( v48 == 1 )
            {
              if ( v50 )
              {
                v54 = *(_QWORD *)(v50 + 34160);
                if ( v54 )
                {
                  ipc_log_string(v54, "ipa %s:%d Dropping packet on DeAggr Exception\n", "ipa3_lan_rx_pyld_hdlr", 4172);
                  v50 = ipa3_ctx;
                }
              }
LABEL_115:
              *(_BYTE *)(a2 + 188) = 1;
            }
          }
          else if ( v48 == 1 )
          {
            goto LABEL_115;
          }
          v74 = *(unsigned __int8 *)(v50 + 45390);
          if ( HIDWORD(v153) + v12 >= *(_DWORD *)(v2 + 112) )
            v75 = *(_DWORD *)(v2 + 112);
          else
            v75 = HIDWORD(v153) + v12;
          if ( v74 )
            v76 = 2080;
          else
            v76 = 3264;
          v77 = _netdev_alloc_skb(0, v75 + 256, v76);
          v149 = v51;
          if ( v77 )
          {
            v78 = *(_DWORD *)(v77 + 208);
            v79 = v77;
            v80 = (void *)(*(_QWORD *)(v77 + 224) + 256LL);
            *(_QWORD *)(v79 + 224) = v80;
            *(_DWORD *)(v79 + 208) = v78 + 256;
            memcpy(v80, *(const void **)(v2 + 224), (int)v75);
            v81 = *(_DWORD *)(v79 + 224);
            v82 = *(_DWORD *)(v79 + 216);
            *(_DWORD *)(v79 + 112) = v75;
            v83 = v75 + v81 - v82;
            v84 = v52 + v12;
            *(_DWORD *)(v79 + 208) = v83;
            v85 = *(_DWORD *)(v2 + 112);
            if ( v85 >= v52 + v12 )
            {
              skb_trim(v79, HIDWORD(v153) + v12);
              if ( ipa3_ctx )
              {
                v87 = *(_QWORD *)(ipa3_ctx + 34160);
                if ( v87 )
                  ipc_log_string(v87, "ipa %s:%d rx avail for %d\n", "ipa3_lan_rx_pyld_hdlr", 4191, BYTE3(v158));
              }
              if ( *(_BYTE *)(a2 + 188) == 1 )
              {
                dev_kfree_skb_any_reason(v79, 2);
              }
              else if ( HIDWORD(v153) >= 0x1801 )
              {
                printk(&unk_3BDE49, "ipa3_lan_rx_pyld_hdlr");
                v95 = ipa3_ctx;
                if ( ipa3_ctx )
                {
                  v96 = *(_QWORD *)(ipa3_ctx + 34152);
                  if ( v96 )
                  {
                    ipc_log_string(v96, "ipa %s:%d packet size invalid\n", "ipa3_lan_rx_pyld_hdlr", 4197);
                    v95 = ipa3_ctx;
                  }
                  v97 = *(_QWORD *)(v95 + 34160);
                  if ( v97 )
                    ipc_log_string(v97, "ipa %s:%d packet size invalid\n", "ipa3_lan_rx_pyld_hdlr", 4197);
                }
                printk(&unk_3FDDCE, "ipa3_lan_rx_pyld_hdlr");
                v98 = ipa3_ctx;
                if ( ipa3_ctx )
                {
                  v99 = *(_QWORD *)(ipa3_ctx + 34152);
                  if ( v99 )
                  {
                    ipc_log_string(v99, "ipa %s:%d STATUS opcode=%d\n", "ipa3_lan_rx_pyld_hdlr", 4199, v152);
                    v98 = ipa3_ctx;
                  }
                  v100 = *(_QWORD *)(v98 + 34160);
                  if ( v100 )
                    ipc_log_string(v100, "ipa %s:%d STATUS opcode=%d\n", "ipa3_lan_rx_pyld_hdlr", 4199, v152);
                }
                printk(&unk_3A356C, "ipa3_lan_rx_pyld_hdlr");
                v101 = ipa3_ctx;
                if ( ipa3_ctx )
                {
                  v102 = *(_QWORD *)(ipa3_ctx + 34152);
                  if ( v102 )
                  {
                    ipc_log_string(
                      v102,
                      "ipa %s:%d src=%d dst=%d len=%d\n",
                      "ipa3_lan_rx_pyld_hdlr",
                      4203,
                      BYTE2(v158),
                      BYTE3(v158),
                      HIDWORD(v153));
                    v101 = ipa3_ctx;
                  }
                  v103 = *(_QWORD *)(v101 + 34160);
                  if ( v103 )
                    ipc_log_string(
                      v103,
                      "ipa %s:%d src=%d dst=%d len=%d\n",
                      "ipa3_lan_rx_pyld_hdlr",
                      4203,
                      BYTE2(v158),
                      BYTE3(v158),
                      HIDWORD(v153));
                }
                *(_BYTE *)(a2 + 188) = 1;
                dev_kfree_skb_any_reason(v79, 2);
              }
              else
              {
                *(_DWORD *)(v79 + 232) = *(_DWORD *)(v79 + 112)
                                       + v146 * (unsigned __int64)((v84 + 31) & 0xFFFFFFE0) / v147
                                       + 248;
                v88 = *(_QWORD *)(a2 + 1624);
                v89 = *(_QWORD *)(v88 + 368);
                v90 = *(_DWORD **)(v88 + 376);
                if ( *(v90 - 1) != 420538815 )
                  __break(0x8229u);
                ((void (__fastcall *)(__int64, _QWORD, __int64))v90)(v89, 0, v79);
              }
            }
            else
            {
              if ( ipa3_ctx )
              {
                v86 = *(_QWORD *)(ipa3_ctx + 34160);
                if ( v86 )
                  ipc_log_string(v86, "ipa %s:%d SPL skb len %d len %d\n", "ipa3_lan_rx_pyld_hdlr", 4181, v85, v52);
              }
              *(_QWORD *)(a2 + 168) = v79;
              *(_DWORD *)(a2 + 176) = v84 - *(_DWORD *)(v2 + 112);
              *(_DWORD *)(a2 + 180) = v51;
              v84 = *(_DWORD *)(v2 + 112);
            }
          }
          else
          {
            printk(&unk_3B7F0D, "ipa3_lan_rx_pyld_hdlr");
            v104 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v105 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v105 )
              {
                ipc_log_string(v105, "ipa %s:%d fail to alloc skb\n", "ipa3_lan_rx_pyld_hdlr", 4220);
                v104 = ipa3_ctx;
              }
              v106 = *(_QWORD *)(v104 + 34160);
              if ( v106 )
                ipc_log_string(v106, "ipa %s:%d fail to alloc skb\n", "ipa3_lan_rx_pyld_hdlr", 4220);
            }
            if ( *(_DWORD *)(v2 + 112) >= v52 )
            {
              v84 = v52 + v12;
            }
            else
            {
              *(_QWORD *)(a2 + 168) = 0;
              *(_DWORD *)(a2 + 176) = v52 + v12 - *(_DWORD *)(v2 + 112);
              *(_DWORD *)(a2 + 180) = v51;
              v84 = *(_DWORD *)(v2 + 112);
            }
          }
          skb_pull(v2, v84);
          if ( *(_DWORD *)(ipa3_ctx + 34308) <= v47 )
            __break(0x800u);
          if ( v47 >= 0x24 )
LABEL_243:
            __break(0x5512u);
          v91 = ipa3_ctx;
          v92 = ipa3_ctx + 480LL * v47;
          if ( *(_BYTE *)(v92 + 520) == 1 )
          {
            v93 = *(_QWORD *)(v92 + 640);
            if ( v93 )
            {
              ipa3_write_done_common(v93, v150);
              v91 = ipa3_ctx;
            }
          }
          if ( v91 )
          {
            v94 = *(_QWORD *)(v91 + 34160);
            if ( v94 )
              ipc_log_string(v94, "ipa %s:%d tx comp imp for %d\n", "ipa3_lan_rx_pyld_hdlr", 4233, v47);
          }
          v150 = 0;
          goto LABEL_12;
        }
        if ( *(_DWORD *)(ipa3_ctx + 34308) <= (unsigned int)BYTE2(v158) )
        {
          __break(0x800u);
          if ( v47 >= 0x24 )
            goto LABEL_243;
        }
        else if ( BYTE2(v158) >= 0x24u )
        {
          goto LABEL_243;
        }
        v61 = ipa3_ctx;
        v62 = ipa3_ctx + 480LL * v47;
        if ( *(_BYTE *)(v62 + 520) == 1 )
        {
          v63 = *(_QWORD *)(v62 + 640);
          if ( v63 )
          {
            ipa3_write_done_common(v63, v150);
            v61 = ipa3_ctx;
          }
        }
        if ( v61 )
        {
          v64 = *(_QWORD *)(v61 + 34160);
          if ( v64 )
            ipc_log_string(v64, "ipa %s:%d tx comp exp for %d\n", "ipa3_lan_rx_pyld_hdlr", 4238, BYTE2(v158));
        }
        skb_pull(v2, v12);
        v150 = 0;
        v65 = (int *)(ipa3_ctx + 32292);
        v66 = *(_DWORD *)(ipa3_ctx + 32292) - 1;
        ++*(_DWORD *)(ipa3_ctx + 32828);
        *v65 = v66;
LABEL_12:
        if ( !*(_DWORD *)(v2 + 112) )
          goto LABEL_205;
      }
      if ( (unsigned int)__ratelimit(&ipa3_lan_rx_pyld_hdlr__rs_335, "ipa3_lan_rx_pyld_hdlr") )
      {
        printk(&unk_3A6A9E, "ipa3_lan_rx_pyld_hdlr");
        v32 = ipa3_ctx;
        if ( !ipa3_ctx )
          goto LABEL_39;
      }
      else
      {
        v32 = ipa3_ctx;
        if ( !ipa3_ctx )
          goto LABEL_39;
      }
      v33 = *(_QWORD *)(v32 + 34152);
      if ( v33 )
      {
        ipc_log_string(v33, "ipa %s:%d status fields invalid\n", "ipa3_lan_rx_pyld_hdlr", 4090);
        v32 = ipa3_ctx;
      }
      v34 = *(_QWORD *)(v32 + 34160);
      if ( v34 )
        ipc_log_string(v34, "ipa %s:%d status fields invalid\n", "ipa3_lan_rx_pyld_hdlr", 4090);
LABEL_39:
      v35 = __ratelimit(&ipa3_lan_rx_pyld_hdlr__rs_338, "ipa3_lan_rx_pyld_hdlr");
      if ( (_DWORD)v35 )
      {
        v35 = printk(&unk_3C0C15, "ipa3_lan_rx_pyld_hdlr");
        v36 = ipa3_ctx;
        if ( !ipa3_ctx )
          goto LABEL_45;
      }
      else
      {
        v36 = ipa3_ctx;
        if ( !ipa3_ctx )
          goto LABEL_45;
      }
      v37 = *(_QWORD *)(v36 + 34152);
      if ( v37 )
      {
        ipc_log_string(
          v37,
          "ipa %s:%d STATUS opcode=%d src=%d dst=%d len=%d\n",
          "ipa3_lan_rx_pyld_hdlr",
          4093,
          v152,
          BYTE2(v158),
          BYTE3(v158),
          HIDWORD(v153));
        v36 = ipa3_ctx;
      }
      v35 = *(_QWORD *)(v36 + 34160);
      if ( v35 )
        v35 = ipc_log_string(
                v35,
                "ipa %s:%d STATUS opcode=%d src=%d dst=%d len=%d\n",
                "ipa3_lan_rx_pyld_hdlr",
                4093,
                v152,
                BYTE2(v158),
                BYTE3(v158),
                HIDWORD(v153));
LABEL_45:
      __break(0x800u);
      ((void (__fastcall *)(__int64))ipa_assert)(v35);
      if ( (v153 & 0x10) == 0 )
        goto LABEL_69;
      goto LABEL_46;
    }
    if ( ipa3_ctx )
    {
      v116 = *(_QWORD *)(ipa3_ctx + 34160);
      if ( v116 )
      {
        ipc_log_string(
          v116,
          "ipa %s:%d rem %d skb %d pad %d\n",
          "ipa3_lan_rx_pyld_hdlr",
          3973,
          v115,
          v3,
          *(_DWORD *)(a2 + 180));
        v115 = *(_DWORD *)(a2 + 176);
        v3 = *(_DWORD *)(v2 + 112);
      }
    }
    v117 = *(_QWORD *)(a2 + 168);
    if ( v115 <= v3 )
    {
      if ( v117 )
      {
        v126 = skb_copy_expand();
        if ( v126 )
        {
          v127 = *(unsigned int *)(a2 + 176);
          v128 = v126;
          v129 = (void *)skb_put(v126, (unsigned int)v127);
          memcpy(v129, *(const void **)(v2 + 224), v127);
          skb_trim(v128, (unsigned int)(*(_DWORD *)(v128 + 112) - *(_DWORD *)(a2 + 180)));
          *(_DWORD *)(v128 + 232) = *(_DWORD *)(v128 + 112) + 248;
          if ( *(_BYTE *)(a2 + 188) == 1 )
          {
            dev_kfree_skb_any_reason(v128, 2);
          }
          else
          {
            v133 = *(_QWORD *)(a2 + 1624);
            v134 = *(_QWORD *)(v133 + 368);
            v135 = *(_DWORD **)(v133 + 376);
            if ( *(v135 - 1) != 420538815 )
              __break(0x8229u);
            ((void (__fastcall *)(__int64, _QWORD, __int64))v135)(v134, 0, v128);
          }
        }
        else
        {
          printk(&unk_3FDD91, "ipa3_lan_rx_pyld_hdlr");
          v143 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v144 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v144 )
            {
              ipc_log_string(v144, "ipa %s:%d copy expand failed\n", "ipa3_lan_rx_pyld_hdlr", 3997);
              v143 = ipa3_ctx;
            }
            v145 = *(_QWORD *)(v143 + 34160);
            if ( v145 )
              ipc_log_string(v145, "ipa %s:%d copy expand failed\n", "ipa3_lan_rx_pyld_hdlr", 3997);
          }
        }
        dev_kfree_skb_any_reason(*(_QWORD *)(a2 + 168), 2);
        v115 = *(_DWORD *)(a2 + 176);
      }
      a1 = skb_pull(v2, v115);
      *(_QWORD *)(a2 + 168) = 0;
      *(_QWORD *)(a2 + 176) = 0;
      goto LABEL_9;
    }
    if ( v117 )
    {
      v118 = skb_copy_expand();
      v119 = v118;
      if ( v118 )
      {
        v120 = *(unsigned int *)(v2 + 112);
        v121 = (void *)skb_put(v118, (unsigned int)v120);
        memcpy(v121, *(const void **)(v2 + 224), v120);
      }
      else
      {
        printk(&unk_3FDD91, "ipa3_lan_rx_pyld_hdlr");
        v140 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v141 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v141 )
          {
            ipc_log_string(v141, "ipa %s:%d copy expand failed\n", "ipa3_lan_rx_pyld_hdlr", 4017);
            v140 = ipa3_ctx;
          }
          v142 = *(_QWORD *)(v140 + 34160);
          if ( v142 )
            ipc_log_string(v142, "ipa %s:%d copy expand failed\n", "ipa3_lan_rx_pyld_hdlr", 4017);
        }
      }
      dev_kfree_skb_any_reason(*(_QWORD *)(a2 + 168), 2);
      *(_QWORD *)(a2 + 168) = v119;
      v115 = *(_DWORD *)(a2 + 176);
      v3 = *(_DWORD *)(v2 + 112);
    }
    *(_DWORD *)(a2 + 176) = v115 - v3;
  }
  else
  {
    printk(&unk_3F7EB5, "ipa3_lan_rx_pyld_hdlr");
    v130 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v131 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v131 )
      {
        ipc_log_string(v131, "ipa %s:%d ZLT packet arrived to AP\n", "ipa3_lan_rx_pyld_hdlr", 3954);
        v130 = ipa3_ctx;
      }
      v132 = *(_QWORD *)(v130 + 34160);
      if ( v132 )
        ipc_log_string(v132, "ipa %s:%d ZLT packet arrived to AP\n", "ipa3_lan_rx_pyld_hdlr", 3954);
    }
  }
LABEL_205:
  ipa3_skb_recycle(v2);
  _ReadStatusReg(SP_EL0);
  return 0;
}
