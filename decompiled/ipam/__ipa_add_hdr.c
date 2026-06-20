__int64 __fastcall _ipa_add_hdr(__int64 a1, char a2, __int64 *a3)
{
  __int64 v5; // x22
  __int64 v6; // x19
  int v7; // w23
  size_t v8; // x0
  unsigned __int64 v9; // x2
  char v10; // w26
  int v11; // w9
  char v12; // w10
  int v13; // w8
  __int16 v14; // w11
  __int64 v15; // x27
  __int64 v16; // x9
  _BOOL4 v17; // w25
  __int64 v18; // x8
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 result; // x0
  __int64 v22; // x24
  __int64 v23; // x8
  __int64 v24; // x0
  __int64 v25; // x0
  unsigned int v26; // w8
  unsigned int v27; // w28
  __int64 v28; // x8
  __int64 v29; // x9
  __int64 v30; // x8
  __int64 v31; // x11
  unsigned int v32; // w12
  __int64 v33; // x24
  bool v34; // zf
  __int64 v35; // x11
  __int64 v36; // x23
  int v37; // w7
  int v38; // w10
  __int64 v39; // x0
  int v40; // w22
  __int64 v41; // x0
  int v42; // w23
  __int64 v43; // x24
  __int64 v44; // x23
  int v45; // w25
  __int64 v46; // x0
  __int64 v47; // x8
  __int64 v48; // x5
  __int64 v49; // x0
  const char *v50; // x7
  __int64 v51; // x0
  const char *v52; // x7
  int v53; // w0
  int v54; // w8
  __int64 v55; // x8
  __int64 v56; // x0
  __int64 v57; // x0
  __int64 v58; // x8
  __int64 v59; // x20
  __int64 v60; // x8
  __int64 v61; // x8
  __int64 v62; // x0
  __int64 v63; // x0
  unsigned int v64; // w21
  int v65; // w20
  __int64 v66; // x8
  __int64 v67; // x0
  __int64 v68; // x0
  __int64 v69; // x8
  unsigned __int64 StatusReg; // x23
  __int64 v71; // x24
  __int64 v72; // x8
  __int64 v73; // x0
  __int64 v74; // x0

  if ( *(_DWORD *)(a1 + 288) >= 4u )
  {
    if ( (unsigned int)__ratelimit(&_ipa_add_hdr__rs_95, "__ipa_add_hdr") )
      printk(&unk_3BE19D, "__ipa_add_hdr");
    v18 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v19 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v19 )
      {
        ipc_log_string(v19, "ipa %s:%d invalid hdr type %d\n", "__ipa_add_hdr", 586, *(_DWORD *)(a1 + 288));
        v18 = ipa3_ctx;
      }
      v20 = *(_QWORD *)(v18 + 34160);
      if ( v20 )
        ipc_log_string(v20, "ipa %s:%d invalid hdr type %d\n", "__ipa_add_hdr", 586, *(_DWORD *)(a1 + 288));
    }
    return 0xFFFFFFFFLL;
  }
  LOBYTE(v5) = a2;
  v6 = kmem_cache_alloc_noprof(*(_QWORD *)(ipa3_ctx + 29392), 3520);
  if ( !v6 )
    return 0xFFFFFFFFLL;
  while ( 1 )
  {
    *(_QWORD *)v6 = v6;
    *(_QWORD *)(v6 + 8) = v6;
    v7 = *(unsigned __int8 *)(a1 + 287);
    memcpy((void *)(v6 + 20), (const void *)(a1 + 32), *(unsigned __int8 *)(a1 + 287));
    *(_DWORD *)(v6 + 276) = v7;
    v8 = strnlen((const char *)a1, 0x20u);
    if ( v8 >= 0x21 )
    {
      _fortify_panic(2, 32, v8 + 1);
      goto LABEL_114;
    }
    v9 = v8 == 32 ? 32LL : v8 + 1;
    if ( v9 < 0x21 )
      break;
LABEL_114:
    _fortify_panic(7, 32, v9);
LABEL_115:
    __break(0x5512u);
    v69 = ipa3_ctx;
    StatusReg = _ReadStatusReg(SP_EL0);
    v71 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &_ipa_add_hdr__alloc_tag;
    v6 = kmem_cache_alloc_noprof(*(_QWORD *)(v69 + 29392), 3520);
    *(_QWORD *)(StatusReg + 80) = v71;
    if ( !v6 )
      return 0xFFFFFFFFLL;
  }
  v10 = v5 & 1;
  sized_strscpy(v6 + 280, a1);
  v11 = *(_DWORD *)(a1 + 288);
  v12 = *(_BYTE *)(a1 + 304);
  v13 = *(unsigned __int8 *)(a1 + 292);
  v14 = *(_WORD *)(a1 + 306);
  *(_BYTE *)(v6 + 349) = v5 & 1;
  *(_DWORD *)(v6 + 312) = v11;
  *(_BYTE *)(v6 + 344) = v12;
  v15 = ipa3_ctx;
  *(_DWORD *)(v6 + 16) = 1468208647;
  *(_BYTE *)(v6 + 316) = v13;
  *(_WORD *)(v6 + 346) = v14;
  v16 = **(_QWORD **)(v15 + 34176);
  v17 = *(_DWORD *)(v16 + 156) && (v13 || *(_DWORD *)(a1 + 300) == 11738) || *(_DWORD *)(v16 + 152) == 0;
  *(_BYTE *)(v6 + 350) = !v17;
  v22 = v15 + 28656;
  while ( 1 )
  {
    v22 = *(_QWORD *)v22;
    if ( v22 == v15 + 28656 )
      break;
    if ( !strcmp((const char *)(v22 + 280), (const char *)(v6 + 280)) && (v5 & 1) != 0 )
    {
LABEL_30:
      if ( (unsigned int)__ratelimit(&_ipa_add_hdr__rs_101, "__ipa_add_hdr") )
        printk(&unk_3B503F, "__ipa_add_hdr");
      v23 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v24 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v24 )
        {
          ipc_log_string(
            v24,
            "ipa %s:%d IPACM Trying to add hdr %s len=%d, duplicate entry, return old one\n",
            "__ipa_add_hdr",
            617,
            (const char *)(v6 + 280),
            *(_DWORD *)(v6 + 276));
          v23 = ipa3_ctx;
        }
        v25 = *(_QWORD *)(v23 + 34160);
        if ( v25 )
          ipc_log_string(
            v25,
            "ipa %s:%d IPACM Trying to add hdr %s len=%d, duplicate entry, return old one\n",
            "__ipa_add_hdr",
            617,
            (const char *)(v6 + 280),
            *(_DWORD *)(v6 + 276));
      }
      if ( a3 )
        *a3 = v22;
      kmem_cache_free(*(_QWORD *)(ipa3_ctx + 29392), v6);
      return 0;
    }
  }
  v22 = v15 + 28872;
  while ( 1 )
  {
    v22 = *(_QWORD *)v22;
    if ( v22 == v15 + 28872 )
      break;
    if ( !strcmp((const char *)(v22 + 280), (const char *)(v6 + 280)) && (v5 & 1) != 0 )
      goto LABEL_30;
  }
  v26 = *(unsigned __int8 *)(a1 + 287);
  if ( v26 < 9 )
  {
    v27 = 0;
    goto LABEL_51;
  }
  if ( v26 < 0x11 )
  {
    v27 = 1;
    goto LABEL_51;
  }
  if ( v26 < 0x19 )
  {
    v27 = 2;
    goto LABEL_51;
  }
  if ( v26 < 0x25 )
  {
    v27 = 3;
    goto LABEL_51;
  }
  if ( v26 < 0x41 )
  {
    v27 = 4;
    goto LABEL_51;
  }
  if ( v26 > 0x80 || *(_DWORD *)(v15 + 32240) <= 0x10u )
  {
    if ( (unsigned int)__ratelimit(&_ipa_add_hdr__rs_104, "__ipa_add_hdr") )
      printk(&unk_3BB2A2, "__ipa_add_hdr");
    v61 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v62 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v62 )
      {
        ipc_log_string(v62, "ipa %s:%d unexpected hdr len %d\n", "__ipa_add_hdr", 644, *(unsigned __int8 *)(a1 + 287));
        v61 = ipa3_ctx;
      }
      v63 = *(_QWORD *)(v61 + 34160);
      if ( v63 )
        ipc_log_string(v63, "ipa %s:%d unexpected hdr len %d\n", "__ipa_add_hdr", 644, *(unsigned __int8 *)(a1 + 287));
    }
    goto LABEL_95;
  }
  v27 = 5;
LABEL_51:
  v28 = 28656;
  if ( v17 )
    v28 = 28872;
  v29 = 152;
  v5 = v15 + v28;
  v30 = **(_QWORD **)(v15 + 34176);
  v31 = v5 + 16LL * v27;
  if ( v17 )
    v29 = 156;
  v32 = *(_DWORD *)(v30 + v29);
  v33 = *(_QWORD *)(v31 + 112);
  v34 = v33 == v31 + 112;
  v35 = v27;
  if ( !v34 )
  {
    v36 = v5 + 16LL * v27;
    goto LABEL_57;
  }
  v37 = *(_DWORD *)(v5 + 212);
  v38 = ipa_hdr_bin_sz[v27];
  if ( v38 + v37 <= v32 )
  {
LABEL_69:
    v44 = v35;
    v45 = v38;
    v46 = kmem_cache_alloc_noprof(*(_QWORD *)(ipa3_ctx + 29400), 3520);
    v33 = v46;
    if ( !v46 )
    {
      printk(&unk_3DE5DD, "__ipa_add_hdr");
      v72 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v73 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v73 )
        {
          ipc_log_string(v73, "ipa %s:%d failed to alloc hdr offset object\n", "__ipa_add_hdr", 694);
          v72 = ipa3_ctx;
        }
        v74 = *(_QWORD *)(v72 + 34160);
        if ( v74 )
          ipc_log_string(v74, "ipa %s:%d failed to alloc hdr offset object\n", "__ipa_add_hdr", 694);
      }
      goto LABEL_95;
    }
    *(_QWORD *)v46 = v46;
    *(_QWORD *)(v46 + 8) = v46;
    *(_DWORD *)(v46 + 16) = *(_DWORD *)(v5 + 212);
    *(_DWORD *)(v46 + 20) = v27;
    *(_DWORD *)(v5 + 212) += v45;
    list_add_0(v46, v5 + 16 * v44 + 16);
  }
  else
  {
    if ( !v17 )
    {
      if ( v15 )
      {
        v39 = *(_QWORD *)(v15 + 34160);
        if ( v39 )
        {
          v40 = ipa_hdr_bin_sz[v27];
          ipc_log_string(
            v39,
            "ipa %s:%d SRAM header table was full allocting DDR header table! Requested: %d Left: %d name %s, end %d\n",
            "__ipa_add_hdr",
            663,
            v38,
            v32 - v37,
            (const char *)(v6 + 280),
            v37);
          v35 = v27;
          v38 = v40;
          v15 = ipa3_ctx;
          v30 = **(_QWORD **)(ipa3_ctx + 34176);
        }
      }
      v32 = *(_DWORD *)(v30 + 156);
      *(_BYTE *)(v6 + 350) = 0;
      v5 = v15 + 28872;
    }
    v36 = v5 + 16 * v35;
    v33 = *(_QWORD *)(v36 + 112);
    if ( v33 == v36 + 112 )
    {
      if ( *(_DWORD *)(v5 + 212) + v38 <= v32 )
      {
        if ( v15 )
        {
          v41 = *(_QWORD *)(v15 + 34160);
          if ( v41 )
          {
            v42 = v38;
            v43 = v35;
            ipc_log_string(
              v41,
              "ipa %s:%d No free offset in DDR allocating new offset Requested: %d Left: %d name %s, end %d\n",
              "__ipa_add_hdr",
              678,
              v38,
              v32 - *(_DWORD *)(v5 + 212),
              (const char *)(v6 + 280),
              *(_DWORD *)(v5 + 212));
            v35 = v43;
            v38 = v42;
          }
        }
        goto LABEL_69;
      }
      v64 = v32;
      v65 = v38;
      printk(&unk_3F53E8, "__ipa_add_hdr");
      v66 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v67 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v67 )
        {
          ipc_log_string(
            v67,
            "ipa %s:%d No space in DDR header buffer! Requested: %d Left: %d name %s, end %d\n",
            "__ipa_add_hdr",
            673,
            v65,
            v64 - *(_DWORD *)(v5 + 212),
            (const char *)(v6 + 280),
            *(_DWORD *)(v5 + 212));
          v66 = ipa3_ctx;
        }
        v68 = *(_QWORD *)(v66 + 34160);
        if ( v68 )
          ipc_log_string(
            v68,
            "ipa %s:%d No space in DDR header buffer! Requested: %d Left: %d name %s, end %d\n",
            "__ipa_add_hdr",
            673,
            v65,
            v64 - *(_DWORD *)(v5 + 212),
            (const char *)(v6 + 280),
            *(_DWORD *)(v5 + 212));
      }
LABEL_95:
      v60 = ipa3_ctx;
      *(_DWORD *)(v6 + 16) = 0;
      kmem_cache_free(*(_QWORD *)(v60 + 29392), v6);
      return 0xFFFFFFFFLL;
    }
LABEL_57:
    _list_del_entry_0(v33);
    list_add_0(v33, v36 + 16);
  }
  *(_QWORD *)(v6 + 328) = v33;
  *(_BYTE *)(v33 + 24) = v10;
  list_add_0(v6, v5);
  v47 = ipa3_ctx;
  v48 = (unsigned int)(*(_DWORD *)(v5 + 208) + 1);
  *(_DWORD *)(v5 + 208) = v48;
  if ( v47 )
  {
    v49 = *(_QWORD *)(v47 + 34152);
    if ( v49 )
    {
      if ( *(_BYTE *)(v6 + 350) )
        v50 = "SRAM";
      else
        v50 = (const char *)&unk_3C9BE0;
      ipc_log_string(
        v49,
        "ipa %s:%d add hdr of sz=%d hdr_cnt=%d ofst=%d to %s table\n",
        "__ipa_add_hdr",
        726,
        *(unsigned __int8 *)(a1 + 287),
        v48,
        *(unsigned int *)(*(_QWORD *)(v6 + 328) + 16LL),
        v50);
      v47 = ipa3_ctx;
    }
    v51 = *(_QWORD *)(v47 + 34160);
    if ( v51 )
    {
      if ( *(_BYTE *)(v6 + 350) )
        v52 = "SRAM";
      else
        v52 = (const char *)&unk_3C9BE0;
      ipc_log_string(
        v51,
        "ipa %s:%d add hdr of sz=%d hdr_cnt=%d ofst=%d to %s table\n",
        "__ipa_add_hdr",
        726,
        *(unsigned __int8 *)(a1 + 287),
        *(unsigned int *)(v5 + 208),
        *(unsigned int *)(*(_QWORD *)(v6 + 328) + 16LL),
        v52);
    }
  }
  v53 = ipa3_id_alloc(v6);
  if ( v53 < 0 )
  {
    if ( (unsigned int)__ratelimit(&_ipa_add_hdr__rs_116, "__ipa_add_hdr") )
    {
      printk(&unk_3BE1BE, "__ipa_add_hdr");
      v55 = ipa3_ctx;
      if ( ipa3_ctx )
        goto LABEL_87;
    }
    else
    {
      v55 = ipa3_ctx;
      if ( ipa3_ctx )
      {
LABEL_87:
        v56 = *(_QWORD *)(v55 + 34152);
        if ( v56 )
        {
          ipc_log_string(v56, "ipa %s:%d failed to alloc id\n", "__ipa_add_hdr", 730);
          v55 = ipa3_ctx;
        }
        v57 = *(_QWORD *)(v55 + 34160);
        if ( v57 )
          ipc_log_string(v57, "ipa %s:%d failed to alloc id\n", "__ipa_add_hdr", 730);
      }
    }
    if ( v33 )
    {
      v58 = *(unsigned int *)(v33 + 20);
      if ( (unsigned int)v58 > 6 )
        goto LABEL_115;
      v59 = v5 + 16 * v58;
      _list_del_entry_0(v33);
      list_add_0(v33, v59 + 112);
    }
    *(_QWORD *)(v6 + 328) = 0;
    --*(_DWORD *)(v5 + 208);
    _list_del_entry_0(v6);
    *(_QWORD *)v6 = 0xDEAD000000000100LL;
    *(_QWORD *)(v6 + 8) = 0xDEAD000000000122LL;
    goto LABEL_95;
  }
  v54 = *(_DWORD *)(v6 + 336);
  *(_DWORD *)(v6 + 340) = v53;
  *(_DWORD *)(a1 + 296) = v53;
  result = 0;
  *(_DWORD *)(v6 + 336) = v54 + 1;
  if ( a3 )
    *a3 = v6;
  return result;
}
