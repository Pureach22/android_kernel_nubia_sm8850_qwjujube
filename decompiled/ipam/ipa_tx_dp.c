__int64 __fastcall ipa_tx_dp(unsigned int a1, __int64 a2, unsigned __int8 *a3)
{
  unsigned int ep_mapping; // w0
  unsigned int v7; // w23
  __int64 v8; // x1
  signed int v9; // w26
  unsigned int v10; // w0
  __int64 v11; // x22
  _DWORD *v12; // x8
  void *v13; // x2
  __int64 v14; // x9
  unsigned int v15; // w20
  __int64 v16; // x0
  unsigned int v17; // w8
  __int64 v18; // x8
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x8
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 result; // x0
  unsigned __int64 v25; // x25
  _BYTE *v26; // x21
  unsigned int v27; // w8
  __int64 v28; // x9
  __int64 v29; // x11
  unsigned int v30; // w28
  _BYTE *v31; // x9
  int v32; // w11
  unsigned int v33; // w9
  _BYTE *v34; // x9
  __int64 v35; // x8
  unsigned int v36; // w10
  __int64 v37; // x10
  unsigned int v38; // w8
  _QWORD *v39; // x10
  _BYTE *v40; // x9
  int v41; // w10
  int v42; // w12
  void *v43; // x11
  char v44; // w23
  __int64 v45; // x8
  __int64 v46; // x0
  __int64 v47; // x0
  __int64 v48; // x10
  __int64 v49; // x15
  __int64 v50; // x11
  _BYTE *v51; // x12
  unsigned __int64 v52; // x14
  __int64 v53; // x17
  _BYTE *v54; // x0
  int v55; // w17
  __int64 v56; // x12
  _BYTE *v57; // x10
  __int64 v58; // x8
  __int64 v59; // x0
  __int64 v60; // x0
  __int64 v61; // x8
  __int64 v62; // x0
  __int64 v63; // x0
  int v64; // w20
  __int64 v65; // x8
  __int64 v66; // x0
  __int64 v67; // x0
  __int64 v68; // x8
  __int64 v69; // x9
  __int64 v70; // x10
  __int64 v71; // x11
  _BYTE *v72; // x12
  _BYTE *v73; // x8
  int v74; // w10
  int v75; // w11
  __int64 v76; // x10
  __int64 v77; // x15
  __int64 v78; // x11
  _BYTE *v79; // x12
  unsigned __int64 v80; // x14
  __int64 v81; // x17
  _BYTE *v82; // x0
  int v83; // w17
  unsigned int v84; // w9
  __int64 v85; // x10
  _BYTE *v86; // x9
  unsigned __int64 v87; // x10
  bool v88; // cf
  unsigned __int64 v89; // x10
  __int64 v90; // x8
  __int64 v91; // x0
  __int64 v92; // x0
  __int64 v93; // x8
  __int64 v94; // x0
  __int64 v95; // x0
  __int64 v96; // x8
  __int64 v97; // x0
  __int64 v98; // x0
  __int64 v99; // x8
  __int64 v100; // x0
  __int64 v101; // x0
  __int64 v102; // x8
  __int64 v103; // x0
  __int64 v104; // x0
  __int64 v105; // x8
  __int64 v106; // x0
  __int64 v107; // x0
  char v108; // [xsp+0h] [xbp-150h]
  _BYTE s[312]; // [xsp+8h] [xbp-148h] BYREF
  __int64 v110; // [xsp+140h] [xbp-10h]

  v110 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, sizeof(s));
  if ( !ipa3_ctx )
  {
    printk(&unk_3C3BA9, "ipa_tx_dp");
    v99 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v100 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v100 )
      {
        ipc_log_string(v100, "ipa %s:%d IPA3 driver was not initialized\n", "ipa_tx_dp", 2385);
        v99 = ipa3_ctx;
      }
      v101 = *(_QWORD *)(v99 + 34160);
      if ( v101 )
      {
        ipc_log_string(v101, "ipa %s:%d IPA3 driver was not initialized\n", "ipa_tx_dp", 2385);
        goto LABEL_94;
      }
    }
LABEL_173:
    result = 4294967274LL;
    goto LABEL_174;
  }
  if ( !*(_DWORD *)(a2 + 112) )
  {
    printk(&unk_3E0D01, "ipa_tx_dp");
    v61 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v62 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v62 )
      {
        ipc_log_string(v62, "ipa %s:%d packet size is 0\n", "ipa_tx_dp", 2390);
        v61 = ipa3_ctx;
      }
      v63 = *(_QWORD *)(v61 + 34160);
      if ( v63 )
      {
        ipc_log_string(v63, "ipa %s:%d packet size is 0\n", "ipa_tx_dp", 2390);
LABEL_94:
        result = 4294967274LL;
        goto LABEL_174;
      }
    }
    goto LABEL_173;
  }
  if ( a1 <= 0x85 && (a1 & 1) != 0 )
  {
    ep_mapping = ipa_get_ep_mapping(32);
    if ( ep_mapping == -1 )
    {
      printk(&unk_3DA941, "ipa_tx_dp");
      v96 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v97 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v97 )
        {
          ipc_log_string(v97, "ipa %s:%d Client %u is not mapped\n", "ipa_tx_dp", 2407, 32);
          v96 = ipa3_ctx;
        }
        v98 = *(_QWORD *)(v96 + 34160);
        if ( v98 )
        {
          ipc_log_string(v98, "ipa %s:%d Client %u is not mapped\n", "ipa_tx_dp", 2407, 32);
          goto LABEL_161;
        }
      }
      goto LABEL_144;
    }
    v7 = ep_mapping;
    v9 = ipa_get_ep_mapping(a1);
  }
  else
  {
    v10 = ipa_get_ep_mapping(a1);
    if ( v10 == -1 )
    {
      printk(&unk_3DA941, "ipa_tx_dp");
      v93 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v94 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v94 )
        {
          ipc_log_string(v94, "ipa %s:%d Client %u is not mapped\n", "ipa_tx_dp", 2414, a1);
          v93 = ipa3_ctx;
        }
        v95 = *(_QWORD *)(v93 + 34160);
        if ( v95 )
        {
          ipc_log_string(v95, "ipa %s:%d Client %u is not mapped\n", "ipa_tx_dp", 2414, a1);
          goto LABEL_161;
        }
      }
      goto LABEL_144;
    }
    v7 = v10;
    if ( a3 && a3[1] == 1 )
      v9 = *a3;
    else
      v9 = -1;
  }
  if ( *(_DWORD *)(ipa3_ctx + 52488) )
  {
    *(_DWORD *)(ipa3_ctx + 52488) = 0;
    v64 = ((__int64 (__fastcall *)(_QWORD))ipa3_get_client_by_pipe)(v7);
    printk(&unk_3AC9D8, "ipa_tx_dp");
    v65 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v66 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v66 )
      {
        ipc_log_string(v66, "ipa %s:%d Client %s woke up the system\n", "ipa_tx_dp", 2426, ipa_clients_strings[v64]);
        v65 = ipa3_ctx;
      }
      v67 = *(_QWORD *)(v65 + 34160);
      if ( v67 )
        ipc_log_string(v67, "ipa %s:%d Client %s woke up the system\n", "ipa_tx_dp", 2426, ipa_clients_strings[v64]);
    }
  }
  if ( v7 >= 0x24 )
    goto LABEL_181;
  v11 = *(_QWORD *)(ipa3_ctx + 480LL * (int)v7 + 640);
  if ( !v11 || (v12 = *(_DWORD **)(v11 + 1624), !*v12) )
  {
    if ( (unsigned int)__ratelimit(&ipa_tx_dp__rs, "ipa_tx_dp") )
    {
      printk(&unk_3A6931, "ipa_tx_dp");
      v21 = ipa3_ctx;
      if ( ipa3_ctx )
        goto LABEL_32;
    }
    else
    {
      v21 = ipa3_ctx;
      if ( ipa3_ctx )
      {
LABEL_32:
        v22 = *(_QWORD *)(v21 + 34152);
        if ( v22 )
        {
          ipc_log_string(v22, "ipa %s:%d pipe %d not valid\n", "ipa_tx_dp", 2432, v7);
          v21 = ipa3_ctx;
        }
        v23 = *(_QWORD *)(v21 + 34160);
        if ( v23 )
          ipc_log_string(v23, "ipa %s:%d pipe %d not valid\n", "ipa_tx_dp", 2432, v7);
      }
    }
    result = 4294967264LL;
    goto LABEL_174;
  }
  v13 = &unk_3B7A49;
  if ( a2 )
  {
    v14 = *(_QWORD *)(a2 + 16);
    if ( v14 )
      v13 = (void *)(v14 + 296);
  }
  v15 = *(unsigned __int8 *)(*(_QWORD *)(a2 + 216) + *(unsigned int *)(a2 + 212) + 2LL);
  v16 = ((__int64 (__fastcall *)(_QWORD, __int64, void *, _QWORD))ipa_get_gsi_ep_info)(
          *(unsigned int *)(ipa3_ctx + 480LL * (int)v7 + 172),
          v8,
          v13,
          (unsigned int)v12[1]);
  if ( !v16 )
  {
    printk(&unk_3EEE59, "ipa_tx_dp");
    v102 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v103 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v103 )
      {
        ipc_log_string(v103, "ipa %s:%d failed to get EP %d GSI info\n", "ipa_tx_dp", 2448, v7);
        v102 = ipa3_ctx;
      }
      v104 = *(_QWORD *)(v102 + 34160);
      if ( v104 )
      {
        ipc_log_string(v104, "ipa %s:%d failed to get EP %d GSI info\n", "ipa_tx_dp", 2448, v7);
        goto LABEL_161;
      }
    }
    goto LABEL_144;
  }
  v17 = *(_DWORD *)(v16 + 8);
  if ( (*(_DWORD *)(v16 + 20) & 0xFFFFFFFE) == 2 )
    v17 -= *(unsigned __int8 *)(v16 + 24);
  if ( v15 + 3 > v17 )
  {
    if ( *(_DWORD *)(a2 + 116) && !_pskb_pull_tail(a2) )
    {
      printk(&unk_3B2086, "ipa_tx_dp");
      v18 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v19 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v19 )
        {
          ipc_log_string(v19, "ipa %s:%d Failed to linear skb with %d frags\n", "ipa_tx_dp", 2458, v15);
          v18 = ipa3_ctx;
        }
        v20 = *(_QWORD *)(v18 + 34160);
        if ( v20 )
        {
          ipc_log_string(v20, "ipa %s:%d Failed to linear skb with %d frags\n", "ipa_tx_dp", 2458, v15);
LABEL_161:
          result = 4294967282LL;
          goto LABEL_174;
        }
      }
      goto LABEL_144;
    }
LABEL_42:
    v25 = 312;
    v26 = s;
    memset(s, 0, sizeof(s));
    v15 = 0;
    v108 = 1;
    if ( v9 != -1 )
      goto LABEL_43;
    goto LABEL_40;
  }
  if ( !v15 )
    goto LABEL_42;
  v25 = 104LL * v15 + 312;
  v26 = (_BYTE *)_kmalloc_noprof(v25, 2336);
  if ( !v26 )
  {
    printk(&unk_3F4FF0, "ipa_tx_dp");
    v105 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v106 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v106 )
      {
        ipc_log_string(v106, "ipa %s:%d failed to alloc desc array\n", "ipa_tx_dp", 2471);
        v105 = ipa3_ctx;
      }
      v107 = *(_QWORD *)(v105 + 34160);
      if ( v107 )
      {
        ipc_log_string(v107, "ipa %s:%d failed to alloc desc array\n", "ipa_tx_dp", 2471);
        result = 4294967282LL;
        goto LABEL_174;
      }
    }
    goto LABEL_144;
  }
  v108 = 0;
  if ( v9 != -1 )
  {
LABEL_43:
    v28 = *(_QWORD *)(a2 + 216);
    v29 = *(unsigned __int16 *)(a2 + 184);
    if ( *(_DWORD *)(v11 + 120) == 1 )
    {
      v30 = 1;
      v26[33] = 1;
    }
    else
    {
      v30 = 0;
    }
    if ( *(_DWORD *)(ipa3_ctx + 32240) >= 0x15u )
    {
      v31 = (_BYTE *)(v28 + v29);
      v32 = *v31 & 0xF0;
      if ( v32 == 96 )
      {
        if ( v31[6] == 58 )
        {
LABEL_50:
          v33 = *(_DWORD *)(ipa3_ctx + 34308);
          if ( v33 > 0x24 )
            goto LABEL_181;
          ipa_imm_cmd_modify_ip_packet_init_ex_dest_pipe(*(_QWORD *)(ipa3_ctx + 24LL * v33 + 50208), v9);
          v34 = &v26[104 * v30];
          v35 = ipa3_ctx;
          *((_WORD *)v34 + 18) = *(_DWORD *)(ipa3_ctx + 50156);
          v36 = *(_DWORD *)(v35 + 34308);
          if ( v36 > 0x24 )
            goto LABEL_181;
          v37 = v35 + 24LL * v36;
          v38 = v30;
          v39 = (_QWORD *)(v37 + 50216);
          goto LABEL_107;
        }
      }
      else if ( v32 == 64 && v31[9] == 1 )
      {
        goto LABEL_50;
      }
    }
    if ( (unsigned int)v9 > 0x23 )
      goto LABEL_181;
    if ( *(_BYTE *)(ipa3_ctx + 480LL * v9 + 492) == 1
      && *(_WORD *)(*(_QWORD *)(a2 + 216) + *(unsigned int *)(a2 + 212) + 4LL) )
    {
      v34 = &v26[104 * v30];
      v70 = ipa3_ctx + 24LL * v9;
      v38 = v30;
      *((_WORD *)v34 + 18) = *(_DWORD *)(ipa3_ctx + 50156);
      v39 = (_QWORD *)(v70 + 50216);
    }
    else
    {
      v34 = &v26[104 * v30];
      v38 = v30;
      v71 = ipa3_ctx + 8LL * v9;
      *((_WORD *)v34 + 18) = *(_DWORD *)(ipa3_ctx + 34600);
      v39 = (_QWORD *)(v71 + 34312);
    }
LABEL_107:
    v72 = &v26[104 * v38];
    *((_QWORD *)v34 + 3) = *v39;
    v72[32] = 1;
    *(_DWORD *)v72 = 3;
    v73 = &v26[104 * v30 + 104];
    *((_QWORD *)v72 + 5) = 0;
    *((_QWORD *)v73 + 1) = *(_QWORD *)(a2 + 224);
    v74 = *(_DWORD *)(a2 + 112);
    v75 = *(_DWORD *)(a2 + 116);
    *(_DWORD *)v73 = 1;
    *((_WORD *)v73 + 17) = v74 - v75;
    *((_QWORD *)v73 + 5) = &ipa3_tx_comp_usr_notify_release;
    *((_QWORD *)v73 + 6) = a2;
    if ( a3 )
    {
      if ( a3[1] == 1 && a3[2] == 1 )
        *((_DWORD *)v73 + 14) = v7;
      else
        *((_DWORD *)v73 + 14) = v9;
      if ( a3[16] == 1 )
      {
        v73[32] = 1;
        *((_QWORD *)v73 + 3) = *((_QWORD *)a3 + 1);
      }
      if ( !v15 )
        goto LABEL_126;
    }
    else
    {
      *((_DWORD *)v73 + 14) = v9;
      if ( !v15 )
      {
LABEL_126:
        v44 = v108;
        if ( (v108 & 1) != 0 )
        {
LABEL_135:
          if ( (unsigned int)ipa3_send(v11, (v30 | 2) + v15, (__int64)v26) )
          {
            if ( (unsigned int)__ratelimit(&ipa_tx_dp__rs_124, "ipa_tx_dp") )
            {
              printk(&unk_3A6950, "ipa_tx_dp");
              v90 = ipa3_ctx;
              if ( ipa3_ctx )
                goto LABEL_138;
            }
            else
            {
              v90 = ipa3_ctx;
              if ( ipa3_ctx )
              {
LABEL_138:
                v91 = *(_QWORD *)(v90 + 34152);
                if ( v91 )
                {
                  ipc_log_string(
                    v91,
                    "ipa %s:%d fail to send skb %pK num_frags %u SWP\n",
                    "ipa_tx_dp",
                    2557,
                    (const void *)a2,
                    v15);
                  v90 = ipa3_ctx;
                }
                v92 = *(_QWORD *)(v90 + 34160);
                if ( v92 )
                  ipc_log_string(v92, "ipa %s:%d fail to send skb %pK num_frags %u SWP\n", "ipa_tx_dp", 2557, a2, v15);
              }
            }
LABEL_142:
            if ( (v44 & 1) == 0 )
              kfree(v26);
            goto LABEL_144;
          }
          v68 = ipa3_ctx;
          v69 = 32280;
          goto LABEL_146;
        }
        v84 = v30 + 1 + v15;
        v85 = 104LL * v84;
        if ( v25 >= v85 + 40 && v25 - (v85 + 40) >= 8 )
        {
          v86 = &v26[104 * v84];
          *((_QWORD *)v86 + 5) = *((_QWORD *)v73 + 5);
          if ( v25 >= v85 + 48 && v25 - (v85 + 48) >= 8 )
          {
            v87 = v85 + 56;
            v88 = v25 >= v87;
            v89 = v25 - v87;
            *((_QWORD *)v86 + 6) = *((_QWORD *)v73 + 6);
            if ( v88 && v89 >= 4 )
            {
              *((_DWORD *)v86 + 14) = *((_DWORD *)v73 + 14);
              *((_QWORD *)v73 + 5) = 0;
              goto LABEL_135;
            }
          }
        }
        goto LABEL_180;
      }
    }
    v76 = 0;
    v77 = 96;
    v78 = 104LL * v30;
    v79 = &v26[v78];
    v80 = v25 - v78 - 242;
    while ( v76 != 1872 )
    {
      if ( v25 < v78 + v76 + 224 )
        goto LABEL_180;
      if ( v80 + 18 < 8 )
        goto LABEL_180;
      v81 = *(_QWORD *)(a2 + 216) + *(unsigned int *)(a2 + 212);
      *(_QWORD *)&v79[v76 + 224] = v81 + v77 - 8;
      if ( v25 < v78 + v76 + 208 )
        goto LABEL_180;
      if ( v80 + 34 < 4 )
        goto LABEL_180;
      *(_DWORD *)&v79[v76 + 208] = 2;
      if ( v25 < v78 + v76 + 242 || v80 < 2 )
        goto LABEL_180;
      v82 = &v79[v76];
      v83 = *(_DWORD *)(v81 + v77);
      v76 += 104;
      v80 -= 104LL;
      v77 += 16;
      *((_WORD *)v82 + 121) = v83;
      if ( 104LL * v15 == v76 )
        goto LABEL_126;
    }
LABEL_181:
    __break(0x5512u);
  }
LABEL_40:
  v27 = *(_DWORD *)(v11 + 120);
  if ( v27 == 1 )
    v26[33] = 1;
  else
    v27 = 0;
  v40 = &v26[104 * v27];
  *((_QWORD *)v40 + 1) = *(_QWORD *)(a2 + 224);
  v41 = *(_DWORD *)(a2 + 112);
  v42 = *(_DWORD *)(a2 + 116);
  *(_DWORD *)v40 = 1;
  v43 = &ipa3_tx_comp_usr_notify_release;
  *((_QWORD *)v40 + 5) = &ipa3_tx_comp_usr_notify_release;
  *((_QWORD *)v40 + 6) = a2;
  *((_DWORD *)v40 + 14) = v7;
  *((_WORD *)v40 + 17) = v41 - v42;
  if ( a3 && a3[16] == 1 )
  {
    v40[32] = 1;
    *((_QWORD *)v40 + 3) = *((_QWORD *)a3 + 1);
  }
  v44 = v108;
  if ( (v108 & 1) == 0 )
  {
    if ( v15 )
    {
      v48 = 0;
      v49 = 96;
      v50 = 104LL * v27;
      v51 = &v26[v50];
      v52 = v25 - v50 - 138;
      do
      {
        if ( v48 == 1872 )
          goto LABEL_181;
        if ( v25 < v50 + v48 + 120 )
          goto LABEL_180;
        if ( v52 + 18 < 8 )
          goto LABEL_180;
        v53 = *(_QWORD *)(a2 + 216) + *(unsigned int *)(a2 + 212);
        *(_QWORD *)&v51[v48 + 120] = v53 + v49 - 8;
        if ( v25 < v50 + v48 + 104 )
          goto LABEL_180;
        if ( v52 + 34 < 4 )
          goto LABEL_180;
        *(_DWORD *)&v51[v48 + 104] = 2;
        if ( v25 < v50 + v48 + 138 || v52 < 2 )
          goto LABEL_180;
        v54 = &v51[v48];
        v55 = *(_DWORD *)(v53 + v49);
        v48 += 104;
        v49 += 16;
        v52 -= 104LL;
        *((_WORD *)v54 + 69) = v55;
      }
      while ( 104LL * v15 != v48 );
      v43 = *((void **)v40 + 5);
      v44 = v108;
    }
    v56 = 104LL * (v15 + v27);
    if ( v25 < v56 + 40
      || v25 - (v56 + 40) < 8
      || (v57 = &v26[104 * v15 + 104 * v27], *((_QWORD *)v57 + 5) = v43, v25 < v56 + 48)
      || v25 - (v56 + 48) < 8
      || (*((_QWORD *)v57 + 6) = *((_QWORD *)v40 + 6), v25 < v56 + 56)
      || v25 - (v56 + 56) < 4 )
    {
LABEL_180:
      __break(1u);
      goto LABEL_181;
    }
    *((_DWORD *)v57 + 14) = *((_DWORD *)v40 + 14);
    *((_QWORD *)v40 + 5) = 0;
    if ( (unsigned int)ipa3_send(v11, v15 + v27 + 1, (__int64)v26) )
    {
      if ( (unsigned int)__ratelimit(&ipa_tx_dp__rs_130, "ipa_tx_dp") )
      {
        printk(&unk_3B20B6, "ipa_tx_dp");
        v58 = ipa3_ctx;
        if ( !ipa3_ctx )
          goto LABEL_142;
      }
      else
      {
        v58 = ipa3_ctx;
        if ( !ipa3_ctx )
          goto LABEL_142;
      }
      v59 = *(_QWORD *)(v58 + 34152);
      if ( v59 )
      {
        ipc_log_string(v59, "ipa %s:%d fail to send skb %pK num_frags %u\n", "ipa_tx_dp", 2608, (const void *)a2, v15);
        v58 = ipa3_ctx;
      }
      v60 = *(_QWORD *)(v58 + 34160);
      if ( v60 )
        ipc_log_string(v60, "ipa %s:%d fail to send skb %pK num_frags %u\n", "ipa_tx_dp", 2608, a2, v15);
      goto LABEL_142;
    }
LABEL_100:
    v68 = ipa3_ctx;
    v69 = 32284;
LABEL_146:
    ++*(_DWORD *)(v68 + v69);
    if ( (v44 & 1) != 0 )
    {
      result = 0;
    }
    else
    {
      kfree(v26);
      result = 0;
      ++*(_DWORD *)(ipa3_ctx + 32888);
    }
    goto LABEL_174;
  }
  if ( !(unsigned int)ipa3_send(v11, v27 + 1, (__int64)v26) )
    goto LABEL_100;
  if ( (unsigned int)__ratelimit(&ipa_tx_dp__rs_127, "ipa_tx_dp") )
  {
    printk(&unk_3C0AE1, "ipa_tx_dp");
    v45 = ipa3_ctx;
    if ( ipa3_ctx )
      goto LABEL_61;
LABEL_144:
    result = 4294967282LL;
    goto LABEL_174;
  }
  v45 = ipa3_ctx;
  if ( !ipa3_ctx )
    goto LABEL_144;
LABEL_61:
  v46 = *(_QWORD *)(v45 + 34152);
  if ( v46 )
  {
    ipc_log_string(v46, "ipa %s:%d fail to send skb %pK HWP\n", "ipa_tx_dp", 2587, (const void *)a2);
    v45 = ipa3_ctx;
  }
  v47 = *(_QWORD *)(v45 + 34160);
  if ( !v47 )
    goto LABEL_144;
  ipc_log_string(v47, "ipa %s:%d fail to send skb %pK HWP\n", "ipa_tx_dp", 2587, (const void *)a2);
  result = 4294967282LL;
LABEL_174:
  _ReadStatusReg(SP_EL0);
  return result;
}
