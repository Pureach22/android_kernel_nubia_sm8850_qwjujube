__int64 __fastcall _ipa3_del_hdr(__int64 a1, char a2)
{
  unsigned int v3; // w19
  __int64 v4; // x0
  __int64 v5; // x20
  __int64 v6; // x8
  __int64 v7; // x9
  __int64 v8; // x23
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x8
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x8
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x8
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 result; // x0
  __int64 v21; // x8
  __int64 v22; // x0
  __int64 v23; // x0
  int v24; // w8
  int v25; // w5
  __int64 v26; // x8
  __int64 v27; // x0
  __int64 v28; // x8
  __int64 *v29; // x9
  __int64 v30; // x10
  __int64 **v31; // x8
  __int64 v32; // x10
  __int64 *v33; // x11
  __int64 *v34; // x2
  _QWORD *v35; // x8
  __int64 v36; // x9
  __int64 v37; // x8
  __int64 v38; // x8
  __int64 v39; // x0
  __int64 v40; // x0

  v3 = a1;
  v4 = ipa3_id_find(a1);
  if ( !v4 )
  {
    if ( (unsigned int)__ratelimit(&_ipa3_del_hdr__rs, "__ipa3_del_hdr") )
    {
      printk(&unk_3DE445, "__ipa3_del_hdr");
      v14 = ipa3_ctx;
      if ( !ipa3_ctx )
        return 4294967274LL;
    }
    else
    {
      v14 = ipa3_ctx;
      if ( !ipa3_ctx )
        return 4294967274LL;
    }
    v15 = *(_QWORD *)(v14 + 34152);
    if ( v15 )
    {
      ipc_log_string(v15, "ipa %s:%d lookup failed\n", "__ipa3_del_hdr", 839);
      v14 = ipa3_ctx;
    }
    v16 = *(_QWORD *)(v14 + 34160);
    if ( v16 )
      ipc_log_string(v16, "ipa %s:%d lookup failed\n", "__ipa3_del_hdr", 839);
    return 4294967274LL;
  }
  v5 = v4;
  if ( *(_DWORD *)(v4 + 16) != 1468208647 )
  {
    if ( (unsigned int)__ratelimit(&_ipa3_del_hdr__rs_24, "__ipa3_del_hdr") )
    {
      printk(&unk_3FB3F2, "__ipa3_del_hdr");
      v17 = ipa3_ctx;
      if ( !ipa3_ctx )
        return 4294967274LL;
    }
    else
    {
      v17 = ipa3_ctx;
      if ( !ipa3_ctx )
        return 4294967274LL;
    }
    v18 = *(_QWORD *)(v17 + 34152);
    if ( v18 )
    {
      ipc_log_string(v18, "ipa %s:%d bad parm\n", "__ipa3_del_hdr", 844);
      v17 = ipa3_ctx;
    }
    v19 = *(_QWORD *)(v17 + 34160);
    if ( v19 )
      ipc_log_string(v19, "ipa %s:%d bad parm\n", "__ipa3_del_hdr", 844);
    return 4294967274LL;
  }
  v6 = ipa3_ctx;
  v7 = 28872;
  if ( *(_BYTE *)(v4 + 350) )
    v7 = 28656;
  v8 = ipa3_ctx + v7;
  if ( ipa3_ctx )
  {
    v9 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v9 )
    {
      ipc_log_string(
        v9,
        "ipa %s:%d del hdr of len=%d hdr_cnt=%d ofst=%d\n",
        "__ipa3_del_hdr",
        851,
        *(_DWORD *)(v5 + 276),
        *(_DWORD *)(v8 + 208),
        *(_DWORD *)(*(_QWORD *)(v5 + 328) + 16LL));
      v6 = ipa3_ctx;
    }
    v10 = *(_QWORD *)(v6 + 34160);
    if ( v10 )
      ipc_log_string(
        v10,
        "ipa %s:%d del hdr of len=%d hdr_cnt=%d ofst=%d\n",
        "__ipa3_del_hdr",
        851,
        *(_DWORD *)(v5 + 276),
        *(_DWORD *)(v8 + 208),
        *(_DWORD *)(*(_QWORD *)(v5 + 328) + 16LL));
  }
  if ( (a2 & 1) != 0 )
  {
    if ( *(_BYTE *)(v5 + 348) == 1 )
    {
      if ( (unsigned int)__ratelimit(&_ipa3_del_hdr__rs_28, "__ipa3_del_hdr") )
      {
        printk(&unk_3B81D3, "__ipa3_del_hdr");
        v11 = ipa3_ctx;
        if ( ipa3_ctx )
          goto LABEL_14;
      }
      else
      {
        v11 = ipa3_ctx;
        if ( ipa3_ctx )
        {
LABEL_14:
          v12 = *(_QWORD *)(v11 + 34152);
          if ( v12 )
          {
            ipc_log_string(v12, "ipa %s:%d proc_ctx already deleted by user\n", "__ipa3_del_hdr", 854);
            v11 = ipa3_ctx;
          }
          v13 = *(_QWORD *)(v11 + 34160);
          if ( v13 )
            ipc_log_string(v13, "ipa %s:%d proc_ctx already deleted by user\n", "__ipa3_del_hdr", 854);
        }
      }
      return 4294967274LL;
    }
    if ( strcmp((const char *)(v5 + 280), "ipa_lan_hdr") )
      goto LABEL_39;
    v21 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v22 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v22 )
      {
        ipc_log_string(
          v22,
          "ipa %s:%d Trying to delete hdr %s offset=%u\n",
          "__ipa3_del_hdr",
          861,
          (const char *)(v5 + 280),
          *(_DWORD *)(*(_QWORD *)(v5 + 328) + 16LL));
        v21 = ipa3_ctx;
      }
      v23 = *(_QWORD *)(v21 + 34160);
      if ( v23 )
        ipc_log_string(
          v23,
          "ipa %s:%d Trying to delete hdr %s offset=%u\n",
          "__ipa3_del_hdr",
          861,
          (const char *)(v5 + 280),
          *(_DWORD *)(*(_QWORD *)(v5 + 328) + 16LL));
    }
    if ( *(_DWORD *)(*(_QWORD *)(v5 + 328) + 16LL) )
    {
LABEL_39:
      *(_BYTE *)(v5 + 348) = 1;
      goto LABEL_40;
    }
    if ( (unsigned int)__ratelimit(&_ipa3_del_hdr__rs_33, "__ipa3_del_hdr") )
    {
      printk(&unk_3F226A, "__ipa3_del_hdr");
      v38 = ipa3_ctx;
      if ( ipa3_ctx )
      {
LABEL_67:
        v39 = *(_QWORD *)(v38 + 34152);
        if ( v39 )
        {
          ipc_log_string(v39, "ipa %s:%d User cannot delete default header\n", "__ipa3_del_hdr", 864);
          v38 = ipa3_ctx;
        }
        v40 = *(_QWORD *)(v38 + 34160);
        if ( v40 )
        {
          ipc_log_string(v40, "ipa %s:%d User cannot delete default header\n", "__ipa3_del_hdr", 864);
          return 0xFFFFFFFFLL;
        }
      }
    }
    else
    {
      v38 = ipa3_ctx;
      if ( ipa3_ctx )
        goto LABEL_67;
    }
    return 0xFFFFFFFFLL;
  }
LABEL_40:
  v24 = *(_DWORD *)(v5 + 336);
  v25 = v24 - 1;
  *(_DWORD *)(v5 + 336) = v24 - 1;
  if ( v24 == 1 )
  {
    v28 = *(_QWORD *)(v5 + 320);
    if ( v28 )
    {
      ((void (__fastcall *)(_QWORD, _QWORD, _QWORD))_ipa3_del_hdr_proc_ctx)(*(unsigned int *)(v28 + 76), 0, 0);
    }
    else
    {
      v29 = *(__int64 **)(v5 + 328);
      v30 = *((unsigned int *)v29 + 5);
      if ( (unsigned int)v30 > 6 )
      {
        __break(0x5512u);
        JUMPOUT(0xC6998);
      }
      v31 = (__int64 **)v29[1];
      v32 = v8 + 16 * v30 + 112;
      if ( *v31 == v29 && (v33 = (__int64 *)*v29, *(__int64 **)(*v29 + 8) == v29) )
      {
        v33[1] = (__int64)v31;
        *v31 = v33;
      }
      else
      {
        _list_del_entry_valid_or_report(*(_QWORD *)(v5 + 328));
      }
      v34 = *(__int64 **)v32;
      if ( *(_QWORD *)(*(_QWORD *)v32 + 8LL) != v32 || v29 == (__int64 *)v32 || v34 == v29 )
      {
        _list_add_valid_or_report(v29, v32);
      }
      else
      {
        v34[1] = (__int64)v29;
        *v29 = (__int64)v34;
        v29[1] = v32;
        *(_QWORD *)v32 = v29;
      }
    }
    v35 = *(_QWORD **)(v5 + 8);
    if ( *v35 == v5 && (v36 = *(_QWORD *)v5, *(_QWORD *)(*(_QWORD *)v5 + 8LL) == v5) )
    {
      *(_QWORD *)(v36 + 8) = v35;
      *v35 = v36;
    }
    else
    {
      _list_del_entry_valid_or_report(v5);
    }
    *(_QWORD *)v5 = 0xDEAD000000000100LL;
    *(_QWORD *)(v5 + 8) = 0xDEAD000000000122LL;
    --*(_DWORD *)(v8 + 208);
    v37 = ipa3_ctx;
    *(_DWORD *)(v5 + 16) = 0;
    kmem_cache_free(*(_QWORD *)(v37 + 29392), v5);
    ipa3_id_remove(v3);
    return 0;
  }
  v26 = ipa3_ctx;
  if ( !ipa3_ctx )
    return 0;
  v27 = *(_QWORD *)(ipa3_ctx + 34152);
  if ( v27 )
  {
    ipc_log_string(v27, "ipa %s:%d hdr_hdl %x ref_cnt %d\n", "__ipa3_del_hdr", 872, v3, v25);
    v26 = ipa3_ctx;
  }
  result = *(_QWORD *)(v26 + 34160);
  if ( result )
  {
    ipc_log_string(result, "ipa %s:%d hdr_hdl %x ref_cnt %d\n", "__ipa3_del_hdr", 872, v3, *(_DWORD *)(v5 + 336));
    return 0;
  }
  return result;
}
