__int64 __fastcall qcedev_sha_update_max_xfer(__int64 a1, __int64 a2, size_t a3)
{
  size_t v3; // x23
  size_t v4; // x25
  unsigned __int64 v5; // x24
  int v8; // w28
  size_t v9; // x8
  __int64 v10; // x21
  __int64 v11; // x8
  size_t v12; // x26
  unsigned __int64 v13; // x22
  size_t v14; // x24
  void *v15; // x22
  unsigned __int64 v16; // x25
  unsigned __int64 v17; // x26
  size_t v19; // x27
  void *v20; // x0
  size_t v21; // x2
  unsigned __int64 v22; // x8
  unsigned int *v23; // x21
  unsigned int v24; // t1
  unsigned __int64 v25; // x26
  size_t v26; // x27
  size_t v27; // x26
  unsigned int v28; // w27
  const void *v29; // x1
  void *v30; // x0
  unsigned int v31; // w0
  unsigned int v32; // w20
  unsigned __int64 v33; // x26
  unsigned __int64 StatusReg; // x21
  __int64 v35; // x24
  size_t n; // [xsp+8h] [xbp-8h]

  v4 = *(unsigned int *)(a2 + 124);
  v5 = *(unsigned int *)(a1 + 316);
  v8 = v5 + v4;
  if ( (unsigned int)(v5 + v4) > 0x40 )
  {
    v3 = a3;
    v14 = (unsigned int)(v8 + 128);
    v15 = (void *)_kmalloc_noprof(v14, 3264);
    if ( v15 )
      goto LABEL_12;
    return 4294967284LL;
  }
  if ( (unsigned int)v4 >= 0x41 )
    goto LABEL_40;
  if ( !(_DWORD)v5 )
  {
LABEL_15:
    *(_DWORD *)(a2 + 124) = v8;
    return 0;
  }
  v9 = 0;
  v10 = a2 + v4 + 60;
  while ( 1 )
  {
    v4 = v9 + 16;
    if ( v9 == 256 )
    {
      while ( 1 )
      {
LABEL_40:
        __break(0x5512u);
        _fortify_panic(15, a3);
        v33 = v5;
        StatusReg = _ReadStatusReg(SP_EL0);
        v35 = *(_QWORD *)(StatusReg + 80);
        *(_QWORD *)(StatusReg + 80) = &qcedev_sha_update_max_xfer__alloc_tag;
        v15 = (void *)_kmalloc_noprof(v33, 3264);
        *(_QWORD *)(StatusReg + 80) = v35;
        v14 = v33;
        if ( !v15 )
          return 4294967284LL;
LABEL_12:
        if ( (_DWORD)v4 )
        {
          memcpy((void *)(((unsigned __int64)v15 + 63) & 0xFFFFFFFFFFFFFFC0LL), (const void *)(a2 + 60), v4);
          v16 = (((unsigned __int64)v15 + 63) & 0xFFFFFFFFFFFFFFC0LL) + v4;
          v17 = *(_QWORD *)(a1 + 56);
          if ( !v17 )
            goto LABEL_20;
        }
        else
        {
          v16 = ((unsigned __int64)v15 + 63) & 0xFFFFFFFFFFFFFFC0LL;
          v17 = *(_QWORD *)(a1 + 56);
          if ( !v17 )
            goto LABEL_20;
        }
        v19 = *(unsigned int *)(a1 + 64);
        if ( (v19 & 0x80000000) != 0 )
        {
          __break(0x800u);
LABEL_19:
          v20 = v15;
          v21 = v14;
LABEL_29:
          memset(v20, 0, v21);
          kfree(v15);
          return 4294967282LL;
        }
        _check_object_size(v16, *(unsigned int *)(a1 + 64), 0);
        if ( inline_copy_from_user(v16, v17, v19) )
          goto LABEL_19;
LABEL_20:
        v22 = *(unsigned int *)(a1 + 312);
        n = v14;
        v4 = v16 + *(unsigned int *)(a1 + 64);
        if ( (unsigned int)v22 < 2 )
        {
LABEL_31:
          *(_QWORD *)(a1 + 872) = v3;
          v27 = v8 - ((v8 + 63) & 0xFFFFFFC0) + 64;
          v28 = ((v8 + 63) & 0xFFFFFFC0) - 64;
          sg_init_one(v3, ((unsigned __int64)v15 + 63) & 0xFFFFFFFFFFFFFFC0LL, v28);
          *(_DWORD *)(a1 + 864) = v28;
          if ( v8 - ((v8 + 63) & 0xFFFFFFC0) != -64 )
          {
            v29 = (const void *)(v4 - v27);
            *(_QWORD *)(a2 + 60) = 0;
            v30 = (void *)(a2 + 60);
            *(_QWORD *)(a2 + 108) = 0;
            *(_QWORD *)(a2 + 116) = 0;
            *(_QWORD *)(a2 + 92) = 0;
            *(_QWORD *)(a2 + 100) = 0;
            *(_QWORD *)(a2 + 76) = 0;
            *(_QWORD *)(a2 + 84) = 0;
            *(_QWORD *)(a2 + 68) = 0;
            if ( (unsigned int)v27 >= 0x41 && (qcedev_sha_update_max_xfer___already_done_118 & 1) == 0 )
            {
              qcedev_sha_update_max_xfer___already_done_118 = 1;
              _warn_printk(
                "memcpy: detected field-spanning write (size %zu) of single %s (size %zu)\n",
                v27,
                "field \"&handle->sha_ctxt.trailing_buf[0]\" at ../vendor/qcom/opensource/securemsm-kernel/crypto-qti/qcedev.c:1108",
                0x40u);
              v29 = (const void *)(v4 - v27);
              v30 = (void *)(a2 + 60);
              __break(0x800u);
            }
            memcpy(v30, v29, v27);
          }
          *(_DWORD *)(a2 + 124) = v27;
          v31 = submit_req((__int64 *)a1, (__int64 *)a2);
          *(_WORD *)(a2 + 128) = 0;
          v32 = v31;
          memset(v15, 0, n);
          kfree(v15);
          return v32;
        }
        v23 = (unsigned int *)(a1 + 80);
        v5 = 1;
        while ( v5 != 16 )
        {
          v25 = *((_QWORD *)v23 - 1);
          if ( v25 )
          {
            v26 = *v23;
            if ( (v26 & 0x80000000) != 0 )
            {
              __break(0x800u);
LABEL_28:
              v21 = n;
              v20 = v15;
              goto LABEL_29;
            }
            _check_object_size(v4, *v23, 0);
            if ( inline_copy_from_user(v4, v25, v26) )
              goto LABEL_28;
            v22 = *(unsigned int *)(a1 + 312);
          }
          v24 = *v23;
          v23 += 4;
          ++v5;
          v4 += v24;
          if ( v5 >= v22 )
            goto LABEL_31;
        }
      }
    }
    v12 = a1 + v9;
    v13 = *(_QWORD *)(a1 + v9 + 56);
    if ( !v13 )
      goto LABEL_5;
    v3 = *(unsigned int *)(v12 + 64);
    if ( (v3 & 0x80000000) != 0 )
      break;
    _check_object_size(v10, *(unsigned int *)(v12 + 64), 0);
    if ( inline_copy_from_user(v10, v13, v3) )
      return 4294967282LL;
LABEL_5:
    v11 = *(unsigned int *)(v12 + 64);
    v5 = (unsigned int)(v5 - v11);
    v10 += v11;
    v9 = v4;
    if ( !(_DWORD)v5 )
      goto LABEL_15;
  }
  __break(0x800u);
  return 4294967282LL;
}
