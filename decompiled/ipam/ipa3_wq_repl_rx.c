_QWORD *__fastcall ipa3_wq_repl_rx(_QWORD *result)
{
  __int64 v1; // x8
  _QWORD *v2; // x19
  _QWORD *v3; // x22
  _DWORD *v4; // x8
  unsigned int v5; // w21
  __int64 v6; // x8
  __int64 v7; // x10
  unsigned int v8; // w9
  unsigned int v9; // w20
  _QWORD *v10; // x27
  __int64 (__fastcall *v11)(__int64, __int64); // x8
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x25
  __int64 v16; // x28
  const char **v17; // x26
  char v18; // w0
  char v19; // w23
  __int64 v20; // x8
  const char *v21; // x0
  const char *v22; // x2
  void (__fastcall *v23)(_QWORD); // x8
  __int64 v24; // x0
  int v25; // w8

  v1 = result[5];
  v2 = result;
  v3 = result - 41;
  _ReadStatusReg(SP_EL0);
  *(_DWORD *)(v1 + 20) = 0;
  v4 = (_DWORD *)result[5];
  v5 = v4[3];
  while ( 1 )
  {
    v8 = (v5 + 1) % v4[4];
    if ( v8 != v4[2] )
    {
      v9 = v5;
      while ( 1 )
      {
        v5 = v8;
        result = (_QWORD *)kmem_cache_alloc_noprof(*(_QWORD *)(ipa3_ctx + 29448), 3520);
        v10 = result;
        if ( !result )
          break;
        result[6] = 0xFFFFFFFE00000LL;
        result[7] = result + 7;
        result[8] = result + 7;
        v11 = (__int64 (__fastcall *)(__int64, __int64))*(v2 - 24);
        v12 = *((unsigned int *)v2 - 42);
        v10[9] = ipa3_wq_rx_avail;
        v10[10] = v3;
        if ( *((_DWORD *)v11 - 1) != 993109518 )
          __break(0x8228u);
        v13 = v11(v12, 3264);
        v10[2] = v13;
        if ( !v13 )
          goto LABEL_28;
        v14 = skb_put(v13, *((unsigned int *)v2 - 42));
        v15 = *((unsigned int *)v2 - 42);
        v16 = v14;
        v17 = *(const char ***)(ipa3_ctx + 34216);
        v18 = is_vmalloc_addr(v14);
        v19 = v18;
        if ( (v18 & 1) != 0 && (dma_map_single_attrs___already_done & 1) == 0 )
        {
          dma_map_single_attrs___already_done = 1;
          v21 = (const char *)dev_driver_string(v17);
          v22 = v17[14];
          if ( !v22 )
            v22 = *v17;
          _warn_printk("%s %s: rejecting DMA map of vmalloc memory\n", v21, v22);
          __break(0x800u);
          if ( (v19 & 1) != 0 )
          {
LABEL_22:
            v10[3] = -1;
LABEL_23:
            if ( (unsigned int)__ratelimit(&ipa3_wq_repl_rx__rs, "ipa3_wq_repl_rx") )
              printk(&unk_3E3A2D, "ipa3_wq_repl_rx");
            v23 = (void (__fastcall *)(_QWORD))*(v2 - 23);
            v24 = v10[2];
            if ( *((_DWORD *)v23 - 1) != 303786302 )
              __break(0x8228u);
            v23(v24);
LABEL_28:
            result = (_QWORD *)kmem_cache_free(*(_QWORD *)(ipa3_ctx + 29448), v10);
            break;
          }
        }
        else if ( (v18 & 1) != 0 )
        {
          goto LABEL_22;
        }
        result = (_QWORD *)dma_map_page_attrs(
                             v17,
                             ((unsigned __int64)((v16 << 8 >> 8) + 0x8000000000LL) >> 12 << 6) - 0x140000000LL,
                             v16 & 0xFFF,
                             v15,
                             2,
                             0);
        v10[3] = result;
        if ( result == (_QWORD *)-1LL )
          goto LABEL_23;
        *(_QWORD *)(*(_QWORD *)v2[5] + 8LL * v9) = v10;
        v9 = v5;
        __dsb(0xFu);
        *(_DWORD *)(v2[5] + 12LL) = v5;
        v20 = v2[5];
        v8 = (v5 + 1) % *(_DWORD *)(v20 + 16);
        if ( v8 == *(_DWORD *)(v20 + 8) )
          goto LABEL_30;
      }
      v5 = v9;
    }
LABEL_30:
    if ( *(_DWORD *)(v2[5] + 12LL) != *(_DWORD *)(v2[5] + 8LL) )
      return result;
    v25 = *(_DWORD *)(v2[162] + 4LL);
    if ( v25 <= 104 )
    {
      if ( v25 == 33 )
      {
LABEL_2:
        v6 = ipa3_ctx;
        v7 = 32868;
      }
      else
      {
        if ( v25 != 35 && v25 != 95 )
          goto LABEL_4;
        v6 = ipa3_ctx;
        v7 = 32848;
      }
LABEL_3:
      ++*(_DWORD *)(v6 + v7);
      goto LABEL_4;
    }
    switch ( v25 )
    {
      case 'i':
        v6 = ipa3_ctx;
        v7 = 32876;
        goto LABEL_3;
      case 'y':
        v6 = ipa3_ctx;
        v7 = 32856;
        goto LABEL_3;
      case '\x7F':
        goto LABEL_2;
    }
LABEL_4:
    result = (_QWORD *)__ratelimit(&ipa3_wq_repl_rx__rs_249, "ipa3_wq_repl_rx");
    if ( (_DWORD)result )
      result = (_QWORD *)printk(&unk_3B7E6E, "ipa3_wq_repl_rx");
    v4 = (_DWORD *)v2[5];
  }
}
