void ipa3_set_resorce_groups_min_max_limits()
{
  __int64 v0; // x8
  __int64 v1; // x0
  __int64 v2; // x0
  __int64 v3; // x20
  int v4; // w22
  __int64 v5; // x28
  int v6; // w19
  __int64 v7; // x10
  __int64 v8; // x10
  __int64 v9; // x0
  __int64 v10; // x0
  unsigned int v11; // w19
  __int64 v12; // x27
  __int64 v13; // x28
  __int64 v14; // x26
  __int64 v15; // x20
  char *v16; // x25
  __int64 v17; // x8
  __int64 v18; // x0
  __int64 v19; // x0
  unsigned int v20; // w19
  __int64 v21; // x27
  __int64 v22; // x26
  char *v23; // x24
  __int64 v24; // x8
  __int64 v25; // x0
  __int64 v26; // x0
  __int64 v27; // x19
  unsigned int v28; // w9
  unsigned __int64 v29; // x8
  __int64 v30; // x8
  __int64 v31; // x20
  __int64 v32; // x22
  __int64 v33; // x8
  unsigned __int64 v34; // x8
  __int64 v35; // x8
  unsigned __int64 v36; // x8
  char *v37; // x8
  __int64 v38; // x9
  unsigned int v39; // w10
  __int64 v40; // x0
  __int64 v41; // x0
  __int64 v42; // x8
  __int64 v43; // x0
  __int64 v44; // x0
  __int64 v45; // [xsp+8h] [xbp-48h]
  unsigned int v46; // [xsp+10h] [xbp-40h]
  int v47; // [xsp+18h] [xbp-38h]
  int v48; // [xsp+1Ch] [xbp-34h]
  __int64 v49; // [xsp+20h] [xbp-30h] BYREF
  __int64 v50; // [xsp+28h] [xbp-28h]
  __int64 v51; // [xsp+34h] [xbp-1Ch] BYREF
  unsigned __int64 v52; // [xsp+3Ch] [xbp-14h]
  int v53; // [xsp+44h] [xbp-Ch]
  __int64 v54; // [xsp+48h] [xbp-8h]

  v54 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v0 = ipa3_ctx;
  v49 = 0;
  v50 = 0;
  if ( ipa3_ctx )
  {
    v1 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v1 )
    {
      ipc_log_string(v1, "ipa %s:%d ENTER\n", "ipa3_set_resorce_groups_min_max_limits", 12348);
      v0 = ipa3_ctx;
    }
    v2 = *(_QWORD *)(v0 + 34160);
    if ( v2 )
    {
      ipc_log_string(v2, "ipa %s:%d ENTER\n", "ipa3_set_resorce_groups_min_max_limits", 12348);
      v0 = ipa3_ctx;
    }
  }
  v3 = *(unsigned __int8 *)(v0 + 32244);
  if ( *(unsigned __int8 *)(v0 + 32244) <= 0xBu )
  {
    if ( *(unsigned __int8 *)(v0 + 32244) <= 3u )
    {
      if ( (unsigned int)(v3 - 1) >= 3 )
      {
        v6 = 0;
        v4 = 1;
        v5 = 8;
        v7 = 3;
        goto LABEL_18;
      }
    }
    else if ( (unsigned int)(v3 - 4) >= 3 )
    {
      if ( (unsigned int)(v3 - 9) < 3 )
      {
LABEL_17:
        v6 = 0;
        v4 = 1;
        v5 = 5;
        v7 = 2;
LABEL_18:
        v45 = v7;
        v48 = 1;
        goto LABEL_26;
      }
      if ( (_DWORD)v3 != 8 )
        goto LABEL_108;
      goto LABEL_107;
    }
LABEL_23:
    v6 = 0;
    v4 = 1;
    v48 = 0;
LABEL_24:
    v5 = 5;
    v8 = 2;
    goto LABEL_25;
  }
  if ( *(unsigned __int8 *)(v0 + 32244) <= 0x10u )
  {
    if ( *(unsigned __int8 *)(v0 + 32244) <= 0xEu )
    {
      if ( (unsigned int)(v3 - 12) < 2 )
        goto LABEL_17;
      if ( (_DWORD)v3 != 14 )
        goto LABEL_108;
LABEL_107:
      v4 = 0;
      v48 = 0;
      v6 = 0;
      goto LABEL_24;
    }
    goto LABEL_23;
  }
  if ( (unsigned int)(v3 - 17) < 4 )
  {
LABEL_9:
    v4 = 1;
    v5 = 5;
    v45 = 3;
    v6 = 1;
    v48 = 1;
    goto LABEL_26;
  }
  if ( (unsigned int)(v3 - 21) >= 2 )
  {
    if ( (_DWORD)v3 == 23 )
      goto LABEL_9;
LABEL_108:
    printk(&unk_3B30E4, "ipa3_set_resorce_groups_min_max_limits");
    v42 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v43 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v43 )
      {
        ipc_log_string(v43, "ipa %s:%d invalid hw type index\n", "ipa3_set_resorce_groups_min_max_limits", 12437);
        v42 = ipa3_ctx;
      }
      v44 = *(_QWORD *)(v42 + 34160);
      if ( v44 )
        ipc_log_string(v44, "ipa %s:%d invalid hw type index\n", "ipa3_set_resorce_groups_min_max_limits", 12437);
    }
    __break(0x800u);
    goto LABEL_103;
  }
  v6 = 0;
  v4 = 1;
  v5 = 5;
  v8 = 3;
  v48 = 0;
LABEL_25:
  v45 = v8;
LABEL_26:
  if ( v0 )
  {
    v9 = *(_QWORD *)(v0 + 34152);
    if ( v9 )
    {
      ipc_log_string(
        v9,
        "ipa %s:%d Assign source rsrc groups min-max limits\n",
        "ipa3_set_resorce_groups_min_max_limits",
        12442);
      v0 = ipa3_ctx;
    }
    v10 = *(_QWORD *)(v0 + 34160);
    if ( v10 )
      ipc_log_string(
        v10,
        "ipa %s:%d Assign source rsrc groups min-max limits\n",
        "ipa3_set_resorce_groups_min_max_limits",
        12442);
  }
  v47 = v6;
  v11 = 0;
  v12 = 448 * v3;
  v13 = 56 * v5;
  v14 = 0;
  v46 = v3;
  v15 = 448 * v3 - 10725;
  v16 = (char *)&ipa3_rsrc_src_grp_config + v12;
  do
  {
    if ( (unsigned __int64)(v12 + v14) >> 9 > 0x14 )
      goto LABEL_74;
    LODWORD(v49) = *(_DWORD *)&v16[v14];
    if ( (unsigned __int64)(v12 + v14 + 4) > 0x2A00 )
      goto LABEL_74;
    HIDWORD(v49) = *(_DWORD *)&v16[v14 + 4];
    if ( (unsigned __int64)(v15 + v14 - 19) < 0xFFFFFFFFFFFFD600LL )
      goto LABEL_74;
    LODWORD(v50) = *(_DWORD *)&v16[v14 + 8];
    if ( (unsigned __int64)(v15 + v14 - 16) < 0xFFFFFFFFFFFFD5FFLL )
      goto LABEL_74;
    HIDWORD(v50) = *(_DWORD *)&v16[v14 + 12];
    ipa3_write_rsrc_grp_type_reg(0, v11, 1, &v49);
    if ( v4 )
    {
      if ( (unsigned __int64)(v15 + v14 - 11) < 0xFFFFFFFFFFFFD600LL )
        goto LABEL_74;
      LODWORD(v49) = *(_DWORD *)&v16[v14 + 16];
      if ( (unsigned __int64)(v15 + v14 - 8) < 0xFFFFFFFFFFFFD5FFLL )
        goto LABEL_74;
      HIDWORD(v49) = *(_DWORD *)&v16[v14 + 20];
      if ( (unsigned __int64)(v15 + v14 - 3) < 0xFFFFFFFFFFFFD600LL )
        goto LABEL_74;
      LODWORD(v50) = *(_DWORD *)&v16[v14 + 24];
      if ( (unsigned __int64)(v15 + v14) < 0xFFFFFFFFFFFFD5FFLL )
        goto LABEL_74;
      HIDWORD(v50) = *(_DWORD *)&v16[v14 + 28];
      ipa3_write_rsrc_grp_type_reg(2, v11, 1, &v49);
      if ( v48 )
      {
        if ( (unsigned __int64)(v15 + v14 + 5) < 0xFFFFFFFFFFFFD600LL )
          goto LABEL_74;
        LODWORD(v49) = *(_DWORD *)&v16[v14 + 32];
        if ( (unsigned __int64)(v15 + v14 + 8) < 0xFFFFFFFFFFFFD5FFLL )
          goto LABEL_74;
        HIDWORD(v49) = *(_DWORD *)&v16[v14 + 36];
        if ( (unsigned __int64)(v15 + v14 + 13) < 0xFFFFFFFFFFFFD600LL )
          goto LABEL_74;
        LODWORD(v50) = *(_DWORD *)&v16[v14 + 40];
        if ( (unsigned __int64)(v15 + v14 + 16) < 0xFFFFFFFFFFFFD5FFLL )
          goto LABEL_74;
        HIDWORD(v50) = *(_DWORD *)&v16[v14 + 44];
        ipa3_write_rsrc_grp_type_reg(4, v11, 1, &v49);
      }
    }
    v14 += 56;
    ++v11;
  }
  while ( v13 != v14 );
  v13 = (__int64)&off_1F7000;
  v17 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v18 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v18 )
    {
      ipc_log_string(
        v18,
        "ipa %s:%d Assign destination rsrc groups min-max limits\n",
        "ipa3_set_resorce_groups_min_max_limits",
        12459);
      v17 = ipa3_ctx;
    }
    v19 = *(_QWORD *)(v17 + 34160);
    if ( v19 )
      ipc_log_string(
        v19,
        "ipa %s:%d Assign destination rsrc groups min-max limits\n",
        "ipa3_set_resorce_groups_min_max_limits",
        12459);
  }
  v20 = 0;
  v21 = 0;
  v22 = 168LL * v46;
  v23 = (char *)&ipa3_rsrc_dst_grp_config + v22;
  while ( 1 )
  {
    if ( (unsigned __int64)(v22 + v21) > 0xFBF )
      goto LABEL_74;
    LODWORD(v49) = *(_DWORD *)&v23[v21];
    if ( (unsigned __int64)(v22 + v21 + 4) > 0xFC0 )
      goto LABEL_74;
    HIDWORD(v49) = *(_DWORD *)&v23[v21 + 4];
    if ( (unsigned __int64)(v22 + v21 - 4024) < 0xFFFFFFFFFFFFF040LL )
      goto LABEL_74;
    LODWORD(v50) = *(_DWORD *)&v23[v21 + 8];
    if ( (unsigned __int64)(v22 + v21 - 4021) < 0xFFFFFFFFFFFFF03FLL )
      goto LABEL_74;
    HIDWORD(v50) = *(_DWORD *)&v23[v21 + 12];
    ipa3_write_rsrc_grp_type_reg(0, v20, 0, &v49);
    if ( v4 )
    {
      if ( (unsigned __int64)(v22 + v21 - 4016) < 0xFFFFFFFFFFFFF040LL )
        goto LABEL_74;
      LODWORD(v49) = *(_DWORD *)&v23[v21 + 16];
      if ( (unsigned __int64)(v22 + v21 - 4013) < 0xFFFFFFFFFFFFF03FLL )
        goto LABEL_74;
      HIDWORD(v49) = *(_DWORD *)&v23[v21 + 20];
      if ( (unsigned __int64)(v22 + v21 - 4008) < 0xFFFFFFFFFFFFF040LL )
        goto LABEL_74;
      LODWORD(v50) = *(_DWORD *)&v23[v21 + 24];
      if ( (unsigned __int64)(v22 + v21 - 4005) < 0xFFFFFFFFFFFFF03FLL )
        goto LABEL_74;
      HIDWORD(v50) = *(_DWORD *)&v23[v21 + 28];
      ipa3_write_rsrc_grp_type_reg(2, v20, 0, &v49);
      if ( v48 )
      {
        if ( (unsigned __int64)(v22 + v21 - 4000) < 0xFFFFFFFFFFFFF040LL )
          goto LABEL_74;
        LODWORD(v49) = *(_DWORD *)&v23[v21 + 32];
        if ( (unsigned __int64)(v22 + v21 - 3997) < 0xFFFFFFFFFFFFF03FLL )
          goto LABEL_74;
        HIDWORD(v49) = *(_DWORD *)&v23[v21 + 36];
        if ( (unsigned __int64)(v22 + v21 - 3992) < 0xFFFFFFFFFFFFF040LL )
          goto LABEL_74;
        LODWORD(v50) = *(_DWORD *)&v23[v21 + 40];
        if ( (unsigned __int64)(v22 + v21 - 3989) < 0xFFFFFFFFFFFFF03FLL )
          goto LABEL_74;
        HIDWORD(v50) = *(_DWORD *)&v23[v21 + 44];
        ipa3_write_rsrc_grp_type_reg(4, v20, 0, &v49);
        if ( v47 )
          break;
      }
    }
LABEL_56:
    v21 += 56;
    ++v20;
    if ( 56 * v45 == v21 )
      goto LABEL_75;
  }
  if ( (unsigned __int64)(v22 + v21 - 3984) >= 0xFFFFFFFFFFFFF040LL )
  {
    LODWORD(v49) = *(_DWORD *)&v23[v21 + 48];
    if ( (unsigned __int64)(v22 + v21 - 3981) >= 0xFFFFFFFFFFFFF03FLL )
    {
      HIDWORD(v49) = *(_DWORD *)&v23[v21 + 52];
      ipa3_write_rsrc_grp_type_reg(6, v20, 0, &v49);
      goto LABEL_56;
    }
  }
LABEL_74:
  while ( 1 )
  {
    __break(1u);
LABEL_75:
    v24 = *(_QWORD *)(v13 + 2056);
    if ( *(_DWORD *)(v24 + 32240) >= 0xBu && (*(_DWORD *)(v24 + 32248) | 2) != 3 )
      break;
    if ( v24 )
    {
      v25 = *(_QWORD *)(v24 + 34152);
      if ( v25 )
      {
        ipc_log_string(v25, "ipa %s:%d Assign RX_HPS CMDQ rsrc groups min-max limits\n", "ipa3_configure_rx_hps", 12309);
        v24 = *(_QWORD *)(v13 + 2056);
      }
      v26 = *(_QWORD *)(v24 + 34160);
      if ( v26 )
      {
        ipc_log_string(v26, "ipa %s:%d Assign RX_HPS CMDQ rsrc groups min-max limits\n", "ipa3_configure_rx_hps", 12309);
        v24 = *(_QWORD *)(v13 + 2056);
      }
    }
    if ( *(_DWORD *)(v24 + 32240) < 0x11u )
      v27 = 4;
    else
      v27 = 5;
    ipa3_configure_rx_hps_clients(0, (unsigned int)v27, 0, 1);
    ipa3_configure_rx_hps_clients(0, (unsigned int)v27, 0, 0);
    v24 = *(_QWORD *)(v13 + 2056);
    v28 = *(_DWORD *)(v24 + 32240);
    if ( v28 > 0xB )
      goto LABEL_95;
    v53 = 0;
    v52 = 0;
    v29 = *(unsigned __int8 *)(v24 + 32244);
    if ( v29 > 0x17 )
      goto LABEL_114;
    v30 = 56 * v29;
    if ( (unsigned __int64)(v30 + 8 * v27) <= 0x53F )
    {
      v31 = v27 + 1;
      v32 = 8 * (v27 + 1);
      LODWORD(v51) = ipa3_rsrc_rx_grp_config[2 * v27 + (unsigned __int64)v30 / 4];
      if ( (unsigned __int64)(v30 + v32) <= 0x53F && (unsigned __int64)(v30 + 8 * v31) <= 0x53F )
      {
        HIDWORD(v51) = ipa3_rsrc_rx_grp_config[(unsigned __int64)v30 / 4 + (unsigned __int64)v32 / 4];
        ((void (__fastcall *)(__int64, _QWORD, __int64 *))ipahal_write_reg_n_fields)(87, 0, &v51);
        v33 = *(_QWORD *)(v13 + 2056);
        v53 = 0;
        v52 = 0;
        v34 = *(unsigned __int8 *)(v33 + 32244);
        if ( v34 > 0x17 )
          goto LABEL_114;
        v35 = 56 * v34;
        if ( (unsigned __int64)(v35 + 8 * v27 + 4) <= 0x540 )
        {
          LODWORD(v51) = ipa3_rsrc_rx_grp_config[2 * v27 + 1 + (unsigned __int64)v35 / 4];
          if ( (unsigned __int64)(v35 + v32 + 4) <= 0x540 && (unsigned __int64)(v35 + 8 * v31 + 4) <= 0x540 )
          {
            HIDWORD(v51) = ipa3_rsrc_rx_grp_config[2 * v31 + 1 + (unsigned __int64)v35 / 4];
            ((void (__fastcall *)(__int64, _QWORD, __int64 *))ipahal_write_reg_n_fields)(89, 0, &v51);
            v24 = *(_QWORD *)(v13 + 2056);
            v28 = *(_DWORD *)(v24 + 32240);
LABEL_95:
            if ( (v28 & 0xFFFFFFFC) == 0xC )
            {
              v36 = *(unsigned __int8 *)(v24 + 32244);
              if ( v36 >= 0x18 )
LABEL_114:
                __break(0x5512u);
              v37 = (char *)&ipa3_rsrc_rx_grp_hps_weight_config + 28 * (unsigned int)v36;
              v38 = *(_QWORD *)v37;
              v39 = *((_DWORD *)v37 + 2);
              LODWORD(v37) = *((_DWORD *)v37 + 3);
              v51 = v38;
              v52 = __PAIR64__((unsigned int)v37, v39);
              ((void (__fastcall *)(__int64, _QWORD, __int64 *))ipahal_write_reg_n_fields)(90, 0, &v51);
              v24 = *(_QWORD *)(v13 + 2056);
            }
            break;
          }
        }
      }
    }
  }
  if ( v24 )
  {
    v40 = *(_QWORD *)(v24 + 34152);
    if ( v40 )
    {
      ipc_log_string(v40, "ipa %s:%d EXIT\n", "ipa3_set_resorce_groups_min_max_limits", 12485);
      v24 = *(_QWORD *)(v13 + 2056);
    }
    v41 = *(_QWORD *)(v24 + 34160);
    if ( v41 )
      ipc_log_string(v41, "ipa %s:%d EXIT\n", "ipa3_set_resorce_groups_min_max_limits", 12485);
  }
LABEL_103:
  _ReadStatusReg(SP_EL0);
}
