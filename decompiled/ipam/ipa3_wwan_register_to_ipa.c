__int64 __fastcall ipa3_wwan_register_to_ipa(int a1)
{
  const char *v1; // x21
  const char *v2; // x22
  __int64 v3; // x25
  __int64 v4; // x19
  unsigned __int64 ipc_logbuf; // x0
  __int64 v6; // x8
  __int64 v7; // x9
  __int64 v8; // x20
  unsigned __int64 v9; // x2
  __int64 v10; // x8
  __int64 v11; // x0
  __int64 v12; // x0
  int v13; // w9
  __int64 v14; // x22
  int v15; // w9
  char *v16; // x8
  int v17; // w9
  int v18; // w14
  int v19; // w15
  int v20; // w12
  __int64 v21; // x0
  unsigned __int64 v22; // x20
  int v23; // w8
  __int64 v24; // x0
  __int64 v25; // x0
  unsigned int v26; // w0
  unsigned int v27; // w21
  __int64 v28; // x0
  __int64 v29; // x0
  int v30; // w9
  __int64 v31; // x8
  int v32; // w10
  __int64 v33; // x26
  __int64 v34; // x0
  __int64 v35; // x0
  __int64 v36; // x0
  __int64 v37; // x0
  unsigned int v38; // w0
  __int64 v39; // x0
  __int64 v40; // x0
  __int64 v41; // x0
  int v42; // w21
  __int64 v43; // x0
  __int64 v44; // x0
  unsigned __int64 StatusReg; // x23
  __int64 v46; // x26
  __int64 (*v47)(_QWORD, _QWORD, const char *, ...); // x0
  __int64 v48; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v51; // [xsp+0h] [xbp-340h] BYREF
  __int64 v52; // [xsp+8h] [xbp-338h]
  _DWORD *v53; // [xsp+10h] [xbp-330h]
  const void *v54; // [xsp+18h] [xbp-328h] BYREF
  _DWORD *v55; // [xsp+20h] [xbp-320h]
  __int64 v56; // [xsp+28h] [xbp-318h] BYREF
  char *v57; // [xsp+30h] [xbp-310h]
  _DWORD v58[82]; // [xsp+38h] [xbp-308h] BYREF
  _DWORD s[100]; // [xsp+180h] [xbp-1C0h] BYREF
  char string[8]; // [xsp+310h] [xbp-30h] BYREF
  __int64 v61; // [xsp+318h] [xbp-28h]
  __int64 v62; // [xsp+320h] [xbp-20h]
  __int64 v63; // [xsp+328h] [xbp-18h]
  __int64 v64; // [xsp+330h] [xbp-10h]

  LODWORD(v4) = a1;
  v64 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v56 = 0;
  v57 = nullptr;
  memset(s, 0, sizeof(s));
  v54 = nullptr;
  v55 = nullptr;
  memset(v58, 0, sizeof(v58));
  v52 = 0;
  v53 = nullptr;
  v51 = 0;
  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    if ( (unsigned int)v4 >= 0xF )
      goto LABEL_84;
    ipc_log_string(
      ipc_logbuf,
      "ipa-wan %s:%d index(%d) device[%s]:\n",
      "ipa3_wwan_register_to_ipa",
      1189,
      v4,
      (const char *)(rmnet_ipa3_ctx + 32LL * (unsigned int)v4 + 560));
  }
  ipc_logbuf = ipa3_get_ipc_logbuf_low();
  if ( ipc_logbuf )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf_low();
    if ( (unsigned int)v4 > 0xE )
      goto LABEL_84;
    v3 = (unsigned int)v4;
    ipc_log_string(
      ipc_logbuf,
      "ipa-wan %s:%d index(%d) device[%s]:\n",
      "ipa3_wwan_register_to_ipa",
      1189,
      v4,
      (const char *)(rmnet_ipa3_ctx + 32LL * (unsigned int)v4 + 560));
  }
  else
  {
    if ( (unsigned int)v4 > 0xE )
      goto LABEL_84;
    v3 = (unsigned int)v4;
  }
  v6 = rmnet_ipa3_ctx;
  v7 = rmnet_ipa3_ctx + 32 * v3;
  if ( (*(_BYTE *)(v7 + 578) & 1) != 0 )
    goto LABEL_28;
  v2 = (const char *)(v7 + 556);
  LODWORD(v1) = *(_DWORD *)(v7 + 556);
  v62 = 0;
  v63 = 0;
  *(_QWORD *)string = 0;
  v61 = 0;
  v8 = _kmalloc_cache_noprof(scnprintf, 3520, 312);
  if ( !v8 )
  {
LABEL_87:
    v27 = -12;
LABEL_88:
    if ( (unsigned int)__ratelimit(&ipa3_wwan_register_to_ipa__rs, "ipa3_wwan_register_to_ipa") )
    {
      printk(&unk_3AAF99, "ipa3_wwan_register_to_ipa");
      if ( !ipa3_get_ipc_logbuf() )
      {
LABEL_91:
        if ( ipa3_get_ipc_logbuf_low() )
        {
          ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            ipc_logbuf_low,
            "ipa-wan %s:%d ipa_add_mux_hdr failed (%d)\n",
            "ipa3_wwan_register_to_ipa",
            1195,
            v4);
        }
        goto LABEL_96;
      }
    }
    else if ( !ipa3_get_ipc_logbuf() )
    {
      goto LABEL_91;
    }
    v48 = ipa3_get_ipc_logbuf();
    ipc_log_string(v48, "ipa-wan %s:%d ipa_add_mux_hdr failed (%d)\n", "ipa3_wwan_register_to_ipa", 1195, v4);
    goto LABEL_91;
  }
  while ( 1 )
  {
    *(_WORD *)v8 = 257;
    *(_DWORD *)(v8 + 304) = 11738;
    snprintf(string, 0x20u, "%s%d", "dmux_hdr_v4_", (_DWORD)v1);
    ipc_logbuf = strnlen(string, 0x20u);
    if ( ipc_logbuf < 0x21 )
      break;
LABEL_85:
    _fortify_panic(2, 32, ipc_logbuf + 1);
LABEL_86:
    _fortify_panic(7, 32, v9);
    StatusReg = _ReadStatusReg(SP_EL0);
    v46 = *(_QWORD *)(StatusReg + 80);
    v47 = scnprintf;
    *(_QWORD *)(StatusReg + 80) = &ipa3_add_qmap_hdr__alloc_tag;
    v8 = _kmalloc_cache_noprof(v47, 3520, 312);
    *(_QWORD *)(StatusReg + 80) = v46;
    if ( !v8 )
      goto LABEL_87;
  }
  if ( ipc_logbuf == 32 )
    v9 = 32;
  else
    v9 = ipc_logbuf + 1;
  if ( v9 >= 0x21 )
    goto LABEL_86;
  sized_strscpy(v8 + 4, string);
  if ( *(_BYTE *)(rmnet_ipa3_ctx + 1984) == 1
    && ((*(_BYTE *)(rmnet_ipa3_ctx + 1992) & 1) != 0 || (int)ipa3_ctx_get_type(0) >= 17) )
  {
    *(_BYTE *)(v8 + 37) = (_BYTE)v1;
    *(_BYTE *)(v8 + 291) = 8;
    LOBYTE(v1) = 0;
    *(_BYTE *)(v8 + 36) = 64;
    *(_DWORD *)(v8 + 38) = -2147221504;
    v10 = 43;
    *(_BYTE *)(v8 + 42) = 0;
  }
  else
  {
    *(_BYTE *)(v8 + 291) = 4;
    v10 = 37;
  }
  *(_BYTE *)(v8 + v10) = (_BYTE)v1;
  if ( ipa3_get_ipc_logbuf() )
  {
    v11 = ipa3_get_ipc_logbuf();
    ipc_log_string(
      v11,
      "ipa-wan %s:%d header (%s) with mux-id: (%d)\n",
      "ipa3_add_qmap_hdr",
      442,
      string,
      *(unsigned __int8 *)(v8 + 37));
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v12 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(
      v12,
      "ipa-wan %s:%d header (%s) with mux-id: (%d)\n",
      "ipa3_add_qmap_hdr",
      442,
      string,
      *(unsigned __int8 *)(v8 + 37));
  }
  if ( (unsigned int)ipa_add_hdr(v8) )
  {
    printk(&unk_3F3888, "ipa3_add_qmap_hdr");
    if ( ipa3_get_ipc_logbuf() )
    {
      v41 = ipa3_get_ipc_logbuf();
      ipc_log_string(v41, "ipa-wan %s:%d fail to add IPA_QMAP hdr\n", "ipa3_add_qmap_hdr", 444);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v42 = 444;
      goto LABEL_78;
    }
LABEL_79:
    kfree(v8);
    v27 = -1;
    goto LABEL_88;
  }
  if ( *(_DWORD *)(v8 + 304) )
  {
    printk(&unk_3F3888, "ipa3_add_qmap_hdr");
    if ( ipa3_get_ipc_logbuf() )
    {
      v43 = ipa3_get_ipc_logbuf();
      ipc_log_string(v43, "ipa-wan %s:%d fail to add IPA_QMAP hdr\n", "ipa3_add_qmap_hdr", 450);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v42 = 450;
LABEL_78:
      v44 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v44, "ipa-wan %s:%d fail to add IPA_QMAP hdr\n", "ipa3_add_qmap_hdr", v42);
    }
    goto LABEL_79;
  }
  *((_DWORD *)v2 + 6) = *(_DWORD *)(v8 + 300);
  kfree(v8);
  v6 = rmnet_ipa3_ctx;
  *(_BYTE *)(rmnet_ipa3_ctx + 32 * v3 + 578) = 1;
LABEL_28:
  v13 = *(unsigned __int8 *)(v6 + 1992);
  v14 = 32 * v3;
  s[0] = 0;
  v57 = (char *)s;
  if ( v13 )
    v15 = 97;
  else
    v15 = 35;
  s[39] = v15;
  snprintf((char *)&s[41], 0x20u, "%s%d", "dmux_hdr_v4_", *(_DWORD *)(v6 + v14 + 556));
  v16 = v57;
  *((_DWORD *)v57 + 50) = 1;
  if ( *(_BYTE *)(rmnet_ipa3_ctx + 1992) )
    v17 = 97;
  else
    v17 = 35;
  *((_DWORD *)v16 + 89) = v17;
  snprintf(v16 + 364, 0x20u, "%s%d", "dmux_hdr_v4_", *(unsigned int *)(rmnet_ipa3_ctx + v14 + 556));
  v55 = v58;
  LODWORD(v56) = 2;
  v58[0] = 0;
  v58[1] |= 0x4000u;
  v18 = *(unsigned __int8 *)(rmnet_ipa3_ctx + 1992);
  v19 = *(_DWORD *)(rmnet_ipa3_ctx + v14 + 556);
  *(_QWORD *)&v58[41] = __PAIR64__(v58[42], 1) | 0x400000000000LL;
  if ( v18 )
    v20 = 96;
  else
    v20 = 34;
  v58[39] = v20;
  v58[7] = v19 << 24;
  v58[8] = -16777216;
  v58[48] = *(_DWORD *)(rmnet_ipa3_ctx + v14 + 556) << 24;
  v58[49] = -16777216;
  if ( !v18 )
  {
    v30 = *(_DWORD *)(rmnet_ipa3_ctx + 1036);
    v58[80] = 34;
    LODWORD(v54) = 2;
    ipc_logbuf = _kmalloc_noprof((unsigned int)(216 * v30), 3264);
    v22 = ipc_logbuf;
    if ( !ipc_logbuf )
      goto LABEL_95;
    v31 = rmnet_ipa3_ctx;
    v53 = (_DWORD *)ipc_logbuf;
    LOBYTE(v51) = 1;
    v32 = *(_DWORD *)(rmnet_ipa3_ctx + 1036);
    HIDWORD(v51) = 35;
    LODWORD(v52) = v32;
    if ( v32 < 1 )
    {
LABEL_62:
      v38 = ipa3_register_intf_ext((const char *)(v31 + 32 * v3 + 560), (unsigned int *)&v56, &v54, &v51);
      if ( v38 )
      {
        v27 = v38;
        if ( (unsigned int)__ratelimit(&ipa3_wwan_register_to_ipa__rs_559, "ipa3_wwan_register_to_ipa") )
        {
          printk(&unk_3DF53C, "ipa3_wwan_register_to_ipa");
          if ( ipa3_get_ipc_logbuf() )
          {
LABEL_65:
            v39 = ipa3_get_ipc_logbuf();
            ipc_log_string(
              v39,
              "ipa-wan %s:%d [%s]:ipa3_register_intf failed %d\n",
              "ipa3_wwan_register_to_ipa",
              1305,
              (const char *)(rmnet_ipa3_ctx + 32 * v3 + 560),
              v27);
          }
        }
        else if ( ipa3_get_ipc_logbuf() )
        {
          goto LABEL_65;
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v40 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            v40,
            "ipa-wan %s:%d [%s]:ipa3_register_intf failed %d\n",
            "ipa3_wwan_register_to_ipa",
            1305,
            (const char *)(rmnet_ipa3_ctx + 32 * v3 + 560),
            v27);
        }
LABEL_69:
        kfree(v22);
        goto LABEL_96;
      }
LABEL_68:
      v27 = 0;
      *(_BYTE *)(rmnet_ipa3_ctx + 32 * v3 + 577) = 1;
      goto LABEL_69;
    }
    v4 = 0;
    v1 = "ipa-wan %s:%d action: %d mux:%d\n";
    v33 = 49;
    v2 = "ipa3_wwan_register_to_ipa";
    while ( v4 != 36 )
    {
      memcpy(&v53[v33 - 49], (const void *)(ipa3_qmi_ctx + v33 * 4 - 196), 0xD8u);
      LOBYTE(v53[v33]) = *(_DWORD *)(rmnet_ipa3_ctx + 32 * v3 + 556);
      if ( ipa3_get_ipc_logbuf() )
      {
        v34 = ipa3_get_ipc_logbuf();
        ipc_log_string(
          v34,
          "ipa-wan %s:%d index %d ip: %d rt-tbl:%d\n",
          "ipa3_wwan_register_to_ipa",
          1292,
          v4,
          v53[v33 - 49],
          v53[v33 - 1]);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v35 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(
          v35,
          "ipa-wan %s:%d index %d ip: %d rt-tbl:%d\n",
          "ipa3_wwan_register_to_ipa",
          1292,
          v4,
          v53[v33 - 49],
          v53[v33 - 1]);
      }
      if ( ipa3_get_ipc_logbuf() )
      {
        v36 = ipa3_get_ipc_logbuf();
        ipc_log_string(
          v36,
          "ipa-wan %s:%d action: %d mux:%d\n",
          "ipa3_wwan_register_to_ipa",
          1295,
          v53[v33 - 2],
          LOBYTE(v53[v33]));
      }
      ipc_logbuf = ipa3_get_ipc_logbuf_low();
      if ( ipc_logbuf )
      {
        v37 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(
          v37,
          "ipa-wan %s:%d action: %d mux:%d\n",
          "ipa3_wwan_register_to_ipa",
          1295,
          v53[v33 - 2],
          LOBYTE(v53[v33]));
      }
      v31 = rmnet_ipa3_ctx;
      ++v4;
      v33 += 54;
      if ( v4 >= *(int *)(rmnet_ipa3_ctx + 1036) )
        goto LABEL_62;
    }
LABEL_84:
    __break(0x5512u);
    goto LABEL_85;
  }
  v58[80] = 96;
  LODWORD(v54) = 2;
  v21 = _kmalloc_cache_noprof(raw_spin_lock_irqsave, 3264, 216);
  v22 = v21;
  if ( v21 )
  {
    v53 = (_DWORD *)v21;
    LODWORD(v52) = 1;
    v23 = *(_DWORD *)(rmnet_ipa3_ctx + 32 * v3 + 556);
    *(_DWORD *)v21 = 2;
    *(_BYTE *)(v21 + 196) = v23;
    if ( ipa3_get_ipc_logbuf() )
    {
      v24 = ipa3_get_ipc_logbuf();
      ipc_log_string(
        v24,
        "ipa-wan %s:%d ip: %d mux:%d\n",
        "ipa3_wwan_register_to_ipa",
        1259,
        *v53,
        *((unsigned __int8 *)v53 + 196));
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v25 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v25,
        "ipa-wan %s:%d ip: %d mux:%d\n",
        "ipa3_wwan_register_to_ipa",
        1259,
        *v53,
        *((unsigned __int8 *)v53 + 196));
    }
    v26 = ipa3_register_intf_ext((const char *)(rmnet_ipa3_ctx + 32 * v3 + 560), (unsigned int *)&v56, &v54, &v51);
    if ( !v26 )
      goto LABEL_68;
    v27 = v26;
    if ( (unsigned int)__ratelimit(&ipa3_wwan_register_to_ipa__rs_551, "ipa3_wwan_register_to_ipa") )
    {
      printk(&unk_3D97BE, "ipa3_wwan_register_to_ipa");
      if ( ipa3_get_ipc_logbuf() )
      {
LABEL_46:
        v28 = ipa3_get_ipc_logbuf();
        ipc_log_string(
          v28,
          "ipa-wan %s:%d [%d]ipa3_register_intf failed %d\n",
          "ipa3_wwan_register_to_ipa",
          1268,
          v4,
          v27);
      }
    }
    else if ( ipa3_get_ipc_logbuf() )
    {
      goto LABEL_46;
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v29 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v29,
        "ipa-wan %s:%d [%d]ipa3_register_intf failed %d\n",
        "ipa3_wwan_register_to_ipa",
        1268,
        v4,
        v27);
    }
    goto LABEL_69;
  }
LABEL_95:
  v27 = -12;
LABEL_96:
  _ReadStatusReg(SP_EL0);
  return v27;
}
