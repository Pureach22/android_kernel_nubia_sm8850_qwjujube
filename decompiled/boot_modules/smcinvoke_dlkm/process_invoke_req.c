__int64 __fastcall process_invoke_req(__int64 a1, __int64 a2)
{
  __int64 v2; // x23
  __int64 v3; // x20
  __int64 v4; // x2
  __int64 result; // x0
  const char *v6; // x2
  int v7; // w3
  int v8; // w4
  __int64 v9; // x19
  unsigned int v10; // w28
  unsigned __int64 v11; // x24
  const char *v12; // x2
  int v13; // w3
  int v14; // w4
  _QWORD *v15; // x21
  unsigned __int64 v16; // x25
  __int64 v17; // x22
  size_t v18; // x26
  int v19; // w27
  __int64 v20; // x2
  int v21; // w24
  void *v22; // x0
  int v23; // w8
  __int64 v24; // x1
  const char *v25; // x0
  unsigned int v26; // w0
  __int64 v27; // x24
  __int64 v28; // x25
  void *v29; // x0
  unsigned __int64 v30; // x8
  __int64 v31; // x9
  unsigned __int64 v32; // x0
  unsigned __int64 StatusReg; // x21
  __int64 v34; // x22
  __int64 v35; // [xsp+8h] [xbp-28h] BYREF
  __int64 v36; // [xsp+10h] [xbp-20h] BYREF
  __int64 v37; // [xsp+18h] [xbp-18h]
  __int64 v38; // [xsp+20h] [xbp-10h]
  __int64 v39; // [xsp+28h] [xbp-8h]

  v2 = a2;
  v39 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 32);
  v37 = 0;
  v38 = 0;
  v35 = 0;
  v36 = 0;
  if ( inline_copy_from_user((int)&v35, a2, 0x20u) )
  {
    result = -14;
    goto LABEL_71;
  }
  if ( v3 && (v3 == 1 || *(_DWORD *)(v3 + 12) == 8) )
  {
    if ( (unsigned int)v35 <= 9 && ((1 << v35) & 0x310) != 0 )
    {
      v22 = &unk_10883;
    }
    else
    {
      if ( (_DWORD)v35 != 5 || HIDWORD(v35) == 4352 )
        goto LABEL_10;
      v22 = &unk_102A7;
    }
    printk(v22, "process_invoke_req", v4);
    result = -22;
    goto LABEL_71;
  }
LABEL_10:
  if ( HIDWORD(v36) != 24 )
  {
    result = -22;
    goto LABEL_71;
  }
  v9 = _kmalloc_cache_noprof(bpf_trace_run3, 3520, 1696);
  if ( !v9 )
  {
LABEL_66:
    result = -12;
    goto LABEL_71;
  }
  while ( 1 )
  {
    v10 = (BYTE4(v35) >> 4) + (BYTE4(v35) & 0xF) + ((HIDWORD(v35) >> 8) & 0xF) + (WORD2(v35) >> 12);
    v11 = HIDWORD(v36) * (unsigned __int64)v10;
    v15 = (_QWORD *)_kmalloc_noprof(v11, print_fmt_cbo_dispatch_wait, v6, v7, v8);
    if ( !v15 )
    {
      v17 = 0;
      v21 = -12;
      goto LABEL_68;
    }
    v16 = 24 * v10 + 24;
    v17 = _kmalloc_noprof(v16, print_fmt_cbo_dispatch_wait, v12, v13, v14);
    if ( !v17 )
    {
      v21 = -12;
      goto LABEL_68;
    }
    v18 = HIDWORD(v36) * v10;
    if ( (v18 & 0x80000000) != 0 )
      goto LABEL_63;
    v19 = v37;
    _check_object_size(v15, HIDWORD(v36) * v10, 0);
    if ( inline_copy_from_user((int)v15, v19, v18) )
      goto LABEL_16;
    if ( !v3 )
      goto LABEL_29;
    v23 = v3 == 1 ? 8 : *(_DWORD *)(v3 + 12);
    if ( v23 != 8 || (_DWORD)v35 != 5 )
      goto LABEL_29;
    if ( v11 >= 8 )
      break;
LABEL_65:
    __break(1u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v34 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &process_invoke_req__alloc_tag;
    v9 = _kmalloc_cache_noprof(bpf_trace_run3, 3520, 1696);
    *(_QWORD *)(StatusReg + 80) = v34;
    if ( !v9 )
      goto LABEL_66;
  }
  if ( *v15 == -1 )
  {
    v29 = &unk_10A76;
    goto LABEL_62;
  }
LABEL_29:
  if ( (unsigned int)marshal_in_req(v17, v15, HIDWORD(v35)) )
  {
    v29 = &unk_1094D;
    goto LABEL_62;
  }
  LODWORD(v36) = 2;
  if ( v3 )
  {
    if ( v3 == 1 )
    {
      v24 = 8;
      v25 = "root";
    }
    else
    {
      v24 = *(unsigned int *)(v3 + 12);
      if ( *(_QWORD *)v3 )
        v25 = *(const char **)v3;
      else
        v25 = "noname";
    }
  }
  else
  {
    v24 = 16;
    v25 = "null";
  }
  trace_process_invoke_req_wait(v25, v24, (unsigned int)v35, HIDWORD(v35));
  v26 = si_object_do_invoke(v9, v3, (unsigned int)v35, v17, &v36);
  if ( !v26 )
  {
    if ( (_DWORD)v36 )
    {
      marshal_in_req_cleanup(v17, 1);
      goto LABEL_40;
    }
    if ( !(unsigned int)marshal_out_req(v15, v17) )
    {
      v27 = HIDWORD(v36) * v10;
      if ( (v27 & 0x80000000) != 0 )
      {
LABEL_63:
        __break(0x800u);
        v21 = -14;
      }
      else
      {
        v28 = v37;
        _check_object_size(v15, HIDWORD(v36) * v10, 1);
        if ( inline_copy_to_user(v28, v15, v27) )
        {
LABEL_16:
          v21 = -14;
          goto LABEL_68;
        }
LABEL_40:
        if ( inline_copy_to_user(v2, &v35, 32) )
          v21 = -14;
        else
          v21 = 0;
      }
      goto LABEL_68;
    }
    v29 = &unk_FFE6;
LABEL_62:
    printk(v29, "process_invoke_req", v20);
    v21 = -22;
    goto LABEL_68;
  }
  v21 = v26;
  printk(&unk_104A8, "process_invoke_req", v26);
  if ( (_DWORD)v36 && (unsigned int)(v21 + 28) <= 0x10 && ((1 << (v21 + 28)) & 0x10041) != 0 )
  {
    marshal_in_req_cleanup(v17, 0);
    v30 = 0;
    v2 = 1;
    v31 = v17;
    while ( 1 )
    {
      if ( *(_DWORD *)v31 == 3 )
      {
        if ( v16 <= v30 + 8 )
          goto LABEL_65;
        v32 = *(_QWORD *)(v31 + 8);
        if ( v32 < 2 || *(_DWORD *)(v32 + 12) != 1 )
          put_si_object();
      }
      else if ( !*(_DWORD *)v31 )
      {
        goto LABEL_68;
      }
      v30 = 24LL * (int)v2;
      v31 = v17 + v30;
      v2 = (unsigned int)(v2 + 1);
      if ( v16 <= v30 )
        goto LABEL_65;
    }
  }
  marshal_in_req_cleanup(v17, 0);
LABEL_68:
  kfree(v17);
  kfree(v15);
  kfree(v9);
  if ( v21 )
    printk(&unk_10976, "process_invoke_req", (unsigned int)v21);
  result = v21;
LABEL_71:
  _ReadStatusReg(SP_EL0);
  return result;
}
