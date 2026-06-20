__int64 __fastcall _ipa_add_hdr_proc_ctx(unsigned int *a1, char a2)
{
  unsigned int proc_ctx_needed_len; // w22
  __int64 v4; // x25
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x19
  _QWORD *v8; // x23
  __int64 v9; // x8
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x20
  char v13; // w28
  unsigned int v14; // w8
  __int64 v15; // x9
  __int64 v16; // x10
  unsigned int v17; // w8
  __int64 v18; // x9
  unsigned int v19; // w8
  __int64 v20; // x0
  __int64 v21; // x8
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v24; // x8
  __int64 v25; // x0
  __int64 v26; // x0
  __int64 v27; // x8
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 v30; // x8
  __int64 v31; // x0
  __int64 v32; // x0
  _BOOL8 v34; // x27
  _QWORD *v35; // x11
  __int64 v36; // x9
  int *v37; // x26
  _QWORD *v38; // x0
  __int64 v39; // x1
  __int64 v40; // x8
  __int64 v41; // x0
  __int64 v42; // x0
  __int64 v43; // x0
  int v44; // w8
  __int64 *v45; // x1
  __int64 v46; // x2
  int v47; // w5
  __int64 v48; // x8
  __int64 v49; // x0
  __int64 v50; // x0
  unsigned int v51; // w0
  int v52; // w9
  __int64 v53; // x8
  __int64 v54; // x0
  __int64 v55; // x0
  __int64 v56; // x8
  __int64 v57; // x21
  __int64 v58; // x9
  __int64 v59; // x8
  unsigned __int64 StatusReg; // x26
  __int64 v61; // x27
  __int64 v62; // x8
  __int64 v63; // x0
  __int64 v64; // x0
  __int64 v65; // x8
  __int64 v66; // x0
  __int64 v67; // x0
  int v68; // [xsp+14h] [xbp-Ch]
  __int64 v69; // [xsp+18h] [xbp-8h]

  LOBYTE(proc_ctx_needed_len) = a2;
  v4 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v5 = *(_QWORD *)(ipa3_ctx + 34160);
    if ( v5 )
      ipc_log_string(v5, "ipa %s:%d Add processing type %d hdr_hdl %d\n", "__ipa_add_hdr_proc_ctx", 448, *a1, a1[1]);
  }
  if ( *a1 >= 0xD )
  {
    if ( (unsigned int)__ratelimit(&_ipa_add_hdr_proc_ctx__rs, "__ipa_add_hdr_proc_ctx") )
    {
      printk(&unk_3C9C58, "__ipa_add_hdr_proc_ctx");
      v24 = ipa3_ctx;
      if ( !ipa3_ctx )
        return 4294967274LL;
    }
    else
    {
      v24 = ipa3_ctx;
      if ( !ipa3_ctx )
        return 4294967274LL;
    }
    v25 = *(_QWORD *)(v24 + 34152);
    if ( v25 )
    {
      ipc_log_string(v25, "ipa %s:%d invalid processing type %d\n", "__ipa_add_hdr_proc_ctx", 451, *a1);
      v24 = ipa3_ctx;
    }
    v26 = *(_QWORD *)(v24 + 34160);
    if ( v26 )
      ipc_log_string(v26, "ipa %s:%d invalid processing type %d\n", "__ipa_add_hdr_proc_ctx", 451, *a1);
    return 4294967274LL;
  }
  v6 = ipa3_id_find(a1[1]);
  if ( !v6 )
  {
    if ( (unsigned int)__ratelimit(&_ipa_add_hdr_proc_ctx__rs_122, "__ipa_add_hdr_proc_ctx") )
    {
      printk(&unk_3F814C, "__ipa_add_hdr_proc_ctx");
      v27 = ipa3_ctx;
      if ( !ipa3_ctx )
        return 4294967274LL;
    }
    else
    {
      v27 = ipa3_ctx;
      if ( !ipa3_ctx )
        return 4294967274LL;
    }
    v28 = *(_QWORD *)(v27 + 34152);
    if ( v28 )
    {
      ipc_log_string(v28, "ipa %s:%d hdr_hdl is invalid\n", "__ipa_add_hdr_proc_ctx", 457);
      v27 = ipa3_ctx;
    }
    v29 = *(_QWORD *)(v27 + 34160);
    if ( v29 )
      ipc_log_string(v29, "ipa %s:%d hdr_hdl is invalid\n", "__ipa_add_hdr_proc_ctx", 457);
    return 4294967274LL;
  }
  v7 = v6;
  LODWORD(v8) = 1468208647;
  if ( *(_DWORD *)(v6 + 16) != 1468208647 )
  {
    if ( (unsigned int)__ratelimit(&_ipa_add_hdr_proc_ctx__rs_125, "__ipa_add_hdr_proc_ctx") )
    {
      printk(&unk_3F22D3, "__ipa_add_hdr_proc_ctx");
      v30 = ipa3_ctx;
      if ( ipa3_ctx )
        goto LABEL_34;
    }
    else
    {
      v30 = ipa3_ctx;
      if ( ipa3_ctx )
      {
LABEL_34:
        v31 = *(_QWORD *)(v30 + 34152);
        if ( v31 )
        {
          ipc_log_string(
            v31,
            "ipa %s:%d Invalid header cookie %u\n",
            "__ipa_add_hdr_proc_ctx",
            461,
            *(_DWORD *)(v7 + 16));
          v30 = ipa3_ctx;
        }
        v32 = *(_QWORD *)(v30 + 34160);
        if ( v32 )
          ipc_log_string(
            v32,
            "ipa %s:%d Invalid header cookie %u\n",
            "__ipa_add_hdr_proc_ctx",
            461,
            *(unsigned int *)(v7 + 16));
      }
    }
    return 4294967274LL;
  }
  v9 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v10 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v10 )
    {
      ipc_log_string(
        v10,
        "ipa %s:%d Associated header is name=%s\n",
        "__ipa_add_hdr_proc_ctx",
        465,
        (const char *)(v7 + 280));
      v9 = ipa3_ctx;
    }
    v11 = *(_QWORD *)(v9 + 34160);
    if ( v11 )
      ipc_log_string(
        v11,
        "ipa %s:%d Associated header is name=%s\n",
        "__ipa_add_hdr_proc_ctx",
        465,
        (const char *)(v7 + 280));
  }
  v12 = kmem_cache_alloc_noprof(*(_QWORD *)(ipa3_ctx + 29416), 3520);
  if ( !v12 )
  {
LABEL_86:
    printk(&unk_3F22F9, "__ipa_add_hdr_proc_ctx");
    v62 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v63 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v63 )
      {
        ipc_log_string(v63, "ipa %s:%d failed to alloc proc_ctx object\n", "__ipa_add_hdr_proc_ctx", 469);
        v62 = ipa3_ctx;
      }
      v64 = *(_QWORD *)(v62 + 34160);
      if ( v64 )
        ipc_log_string(v64, "ipa %s:%d failed to alloc proc_ctx object\n", "__ipa_add_hdr_proc_ctx", 469);
    }
    return 4294967284LL;
  }
  while ( 1 )
  {
    *(_QWORD *)v12 = v12;
    v13 = proc_ctx_needed_len & 1;
    *(_QWORD *)(v12 + 8) = v12;
    v14 = *a1;
    v15 = *((_QWORD *)a1 + 2);
    v16 = *((_QWORD *)a1 + 3);
    *(_QWORD *)(v12 + 64) = v7;
    *(_DWORD *)(v12 + 20) = v14;
    v17 = a1[8];
    *(_QWORD *)(v12 + 24) = v15;
    *(_QWORD *)(v12 + 32) = v16;
    v18 = *(_QWORD *)(a1 + 9);
    *(_DWORD *)(v12 + 40) = v17;
    v19 = a1[11];
    *(_QWORD *)(v12 + 44) = v18;
    *(_DWORD *)(v12 + 52) = v19;
    ++*(_DWORD *)(v7 + 336);
    v20 = *a1;
    *(_DWORD *)(v12 + 16) = (_DWORD)v8 + 1;
    *(_BYTE *)(v12 + 81) = proc_ctx_needed_len & 1;
    proc_ctx_needed_len = ipahal_get_proc_ctx_needed_len(v20);
    if ( proc_ctx_needed_len > 0x40 )
    {
      if ( (unsigned int)__ratelimit(&_ipa_add_hdr_proc_ctx__rs_131, "__ipa_add_hdr_proc_ctx") )
      {
        printk(&unk_3B508F, "__ipa_add_hdr_proc_ctx");
        v21 = ipa3_ctx;
        if ( !ipa3_ctx )
          goto LABEL_73;
      }
      else
      {
        v21 = ipa3_ctx;
        if ( !ipa3_ctx )
          goto LABEL_73;
      }
      v22 = *(_QWORD *)(v21 + 34152);
      if ( v22 )
      {
        ipc_log_string(v22, "ipa %s:%d unexpected needed len %d\n", "__ipa_add_hdr_proc_ctx", 491, proc_ctx_needed_len);
        v21 = ipa3_ctx;
      }
      v23 = *(_QWORD *)(v21 + 34160);
      if ( v23 )
        ipc_log_string(v23, "ipa %s:%d unexpected needed len %d\n", "__ipa_add_hdr_proc_ctx", 491, proc_ctx_needed_len);
      goto LABEL_73;
    }
    v34 = proc_ctx_needed_len > 0x20;
    v35 = (_QWORD *)(v4 + 29136 + 16 * v34);
    v36 = 176;
    if ( *(_BYTE *)(ipa3_ctx + 30408) )
      v36 = 172;
    v8 = (_QWORD *)*v35;
    v37 = (int *)(v4 + 29168);
    if ( (_QWORD *)*v35 != v35 )
    {
      v38 = (_QWORD *)*v35;
      v69 = v4 + 29136;
      *((_BYTE *)v8 + 24) = v13;
      _list_del_entry_0(v38);
      v39 = v4 + 16 * v34 + 29104;
      goto LABEL_54;
    }
    if ( (unsigned int)(ipa_hdr_proc_ctx_bin_sz[v34] + *(_DWORD *)(v4 + 29172)) > *(_DWORD *)(**(_QWORD **)(ipa3_ctx + 34176)
                                                                                            + v36) )
      break;
    v68 = ipa_hdr_proc_ctx_bin_sz[v34];
    v69 = v4 + 29136;
    v43 = kmem_cache_alloc_noprof(*(_QWORD *)(ipa3_ctx + 29424), 3520);
    v8 = (_QWORD *)v43;
    if ( !v43 )
    {
      printk(&unk_3D5A8B, "__ipa_add_hdr_proc_ctx");
      v65 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v66 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v66 )
        {
          ipc_log_string(v66, "ipa %s:%d failed to alloc offset object\n", "__ipa_add_hdr_proc_ctx", 513);
          v65 = ipa3_ctx;
        }
        v67 = *(_QWORD *)(v65 + 34160);
        if ( v67 )
          ipc_log_string(v67, "ipa %s:%d failed to alloc offset object\n", "__ipa_add_hdr_proc_ctx", 513);
      }
      goto LABEL_73;
    }
    *(_QWORD *)v43 = v43;
    *(_QWORD *)(v43 + 8) = v43;
    v44 = *(_DWORD *)(v4 + 29172);
    *(_BYTE *)(v43 + 24) = v13;
    *(_DWORD *)(v43 + 16) = v44;
    *(_DWORD *)(v43 + 20) = v34;
    *(_DWORD *)(v4 + 29172) = v44 + v68;
    v39 = v4 + 16 * v34 + 29104;
LABEL_54:
    list_add_0(v8, v39);
    *(_QWORD *)(v12 + 56) = v8;
    v45 = (__int64 *)(v4 + 29088);
    v46 = *(_QWORD *)(v4 + 29088);
    if ( *(_QWORD *)(v46 + 8) != v4 + 29088 || (__int64 *)v12 == v45 || v46 == v12 )
    {
      _list_add_valid_or_report(v12, v45);
    }
    else
    {
      *(_QWORD *)(v46 + 8) = v12;
      *(_QWORD *)v12 = v46;
      *(_QWORD *)(v12 + 8) = v45;
      *v45 = v12;
    }
    v47 = *v37 + 1;
    *v37 = v47;
    v48 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v49 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v49 )
      {
        ipc_log_string(
          v49,
          "ipa %s:%d add proc ctx of sz=%d cnt=%d ofst=%d\n",
          "__ipa_add_hdr_proc_ctx",
          540,
          proc_ctx_needed_len,
          v47,
          *((_DWORD *)v8 + 4));
        v48 = ipa3_ctx;
      }
      v50 = *(_QWORD *)(v48 + 34160);
      if ( v50 )
        ipc_log_string(
          v50,
          "ipa %s:%d add proc ctx of sz=%d cnt=%d ofst=%d\n",
          "__ipa_add_hdr_proc_ctx",
          540,
          proc_ctx_needed_len,
          *v37,
          *((_DWORD *)v8 + 4));
    }
    v51 = ipa3_id_alloc(v12);
    if ( (v51 & 0x80000000) == 0 )
    {
      v52 = *(_DWORD *)(v12 + 72);
      a1[2] = v51;
      *(_DWORD *)(v12 + 72) = v52 + 1;
      *(_DWORD *)(v12 + 76) = v51;
      return 0;
    }
    if ( (unsigned int)__ratelimit(&_ipa_add_hdr_proc_ctx__rs_142, "__ipa_add_hdr_proc_ctx") )
    {
      printk(&unk_3BE1BE, "__ipa_add_hdr_proc_ctx");
      v53 = ipa3_ctx;
      if ( !ipa3_ctx )
        goto LABEL_71;
    }
    else
    {
      v53 = ipa3_ctx;
      if ( !ipa3_ctx )
        goto LABEL_71;
    }
    v54 = *(_QWORD *)(v53 + 34152);
    if ( v54 )
    {
      ipc_log_string(v54, "ipa %s:%d failed to alloc id\n", "__ipa_add_hdr_proc_ctx", 544);
      v53 = ipa3_ctx;
    }
    v55 = *(_QWORD *)(v53 + 34160);
    if ( v55 )
      ipc_log_string(v55, "ipa %s:%d failed to alloc id\n", "__ipa_add_hdr_proc_ctx", 544);
LABEL_71:
    v56 = *((unsigned int *)v8 + 5);
    if ( (unsigned int)v56 <= 2 )
    {
      v57 = v69 + 16 * v56;
      _list_del_entry_0(v8);
      list_add_0(v8, v57);
      *(_QWORD *)(v12 + 56) = 0;
      _list_del_entry_0(v12);
      *(_QWORD *)v12 = 0xDEAD000000000100LL;
      *(_QWORD *)(v12 + 8) = 0xDEAD000000000122LL;
      --*v37;
      goto LABEL_73;
    }
    __break(0x5512u);
    v59 = ipa3_ctx;
    StatusReg = _ReadStatusReg(SP_EL0);
    v61 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &_ipa_add_hdr_proc_ctx__alloc_tag;
    v12 = kmem_cache_alloc_noprof(*(_QWORD *)(v59 + 29416), 3520);
    *(_QWORD *)(StatusReg + 80) = v61;
    if ( !v12 )
      goto LABEL_86;
  }
  if ( (unsigned int)__ratelimit(&_ipa_add_hdr_proc_ctx__rs_134, "__ipa_add_hdr_proc_ctx") )
  {
    printk(&unk_3D2BFB, "__ipa_add_hdr_proc_ctx");
    v40 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_73;
  }
  else
  {
    v40 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_73;
  }
  v41 = *(_QWORD *)(v40 + 34152);
  if ( v41 )
  {
    ipc_log_string(v41, "ipa %s:%d hdr proc ctx table overflow\n", "__ipa_add_hdr_proc_ctx", 506);
    v40 = ipa3_ctx;
  }
  v42 = *(_QWORD *)(v40 + 34160);
  if ( v42 )
    ipc_log_string(v42, "ipa %s:%d hdr proc ctx table overflow\n", "__ipa_add_hdr_proc_ctx", 506);
LABEL_73:
  v58 = ipa3_ctx;
  --*(_DWORD *)(v7 + 336);
  *(_DWORD *)(v12 + 16) = 0;
  kmem_cache_free(*(_QWORD *)(v58 + 29416), v12);
  return 0xFFFFFFFFLL;
}
