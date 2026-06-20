__int64 __fastcall swr_connect_port(
        __int64 a1,
        __int64 a2,
        unsigned __int8 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7)
{
  __int64 v7; // x19
  int v8; // w20
  _BYTE *v17; // x20
  __int64 v18; // x28
  __int64 v19; // x0
  __int64 v20; // x8
  int v21; // w8
  char v22; // w8
  char v23; // w8
  unsigned __int64 v24; // x8
  _DWORD *v25; // x9
  _BYTE *v26; // x12
  char v27; // w13
  _DWORD *v28; // x8
  unsigned __int64 StatusReg; // x28
  size_t (*v30)(const char *, size_t); // x0
  __int64 v31; // [xsp+8h] [xbp-8h]

  v7 = *(_QWORD *)(a1 + 32);
  if ( v7 )
  {
    v8 = a3;
    if ( a3 >= 0xFu )
    {
      if ( (unsigned int)__ratelimit(&swr_connect_port__rs_14, "swr_connect_port") )
      {
        dev_err(v7, "%s: num_port %d exceeds max port %d\n", "swr_connect_port", v8, 14);
        return 4294967274LL;
      }
      return 4294967274LL;
    }
    v17 = (_BYTE *)_kmalloc_cache_noprof(strnlen, 3520, 172);
    if ( v17 )
    {
      while ( 1 )
      {
        mutex_lock(v7 + 936);
        v18 = *(unsigned __int8 *)(v7 + 8408);
        if ( *(_BYTE *)(v7 + 8408) )
          break;
        v21 = 0;
LABEL_16:
        v19 = krealloc_noprof(*(_QWORD *)(v7 + 8392), (unsigned int)(8 * v21 + 8), 3264);
        if ( !v19 )
        {
          mutex_unlock(v7 + 936);
          kfree(v17);
          if ( (unsigned int)__ratelimit(&swr_connect_port__rs_20, "swr_connect_port") )
            dev_err(v7, "%s Not able to allocate\nmaster port transaction memory\n", "swr_connect_port");
          return 4294967284LL;
        }
        v22 = *(_BYTE *)(v7 + 8408);
        *(_QWORD *)(v7 + 8392) = v19;
        *(_BYTE *)(v7 + 8408) = v22 + 1;
LABEL_19:
        *(_QWORD *)(v19 + 8LL * (unsigned int)v18) = v17;
        mutex_unlock(v7 + 936);
        v23 = *(_BYTE *)(a1 + 64);
        *v17 = v18;
        v17[2] = a3;
        v17[1] = v23;
        if ( !a3 )
        {
LABEL_26:
          v28 = *(_DWORD **)(v7 + 8416);
          if ( *(v28 - 1) != -194885138 )
            __break(0x8228u);
          return ((__int64 (__fastcall *)(__int64, _BYTE *))v28)(v7, v17);
        }
        v24 = 0;
        v25 = v17 + 116;
        while ( v24 <= 0xA8 )
        {
          v17[v24 + 3] = *(_BYTE *)(a2 + v24);
          if ( v24 > 0x9A )
            break;
          v17[v24 + 17] = *(_BYTE *)(a6 + v24);
          if ( v24 > 0x22 )
            break;
          v26 = &v17[v24];
          *(v25 - 21) = *(_DWORD *)(a5 + 4 * v24);
          v27 = *(_BYTE *)(a7 + v24);
          v26[88] = *(_BYTE *)(a4 + v24);
          v26[102] = v27;
          if ( v24 > 0xD )
            break;
          ++v24;
          *v25++ = 0;
          if ( a3 == v24 )
            goto LABEL_26;
        }
        __break(1u);
        StatusReg = _ReadStatusReg(SP_EL0);
        v30 = strnlen;
        v31 = *(_QWORD *)(StatusReg + 80);
        *(_QWORD *)(StatusReg + 80) = &swr_connect_port__alloc_tag;
        v17 = (_BYTE *)_kmalloc_cache_noprof(v30, 3520, 172);
        *(_QWORD *)(StatusReg + 80) = v31;
        if ( !v17 )
          return 4294967284LL;
      }
      v19 = *(_QWORD *)(v7 + 8392);
      v20 = 0;
      do
      {
        if ( !*(_QWORD *)(v19 + 8 * v20) )
        {
          LODWORD(v18) = (unsigned __int8)v20;
          goto LABEL_19;
        }
        ++v20;
      }
      while ( v18 != v20 );
      v21 = *(unsigned __int8 *)(v7 + 8408);
      if ( (_DWORD)v18 != 255 )
        goto LABEL_16;
      mutex_unlock(v7 + 936);
      kfree(v17);
      if ( (unsigned int)__ratelimit(&swr_connect_port__rs_16, "swr_connect_port") )
        dev_err(v7, "%s Max tid reached\n", "swr_connect_port");
    }
    return 4294967284LL;
  }
  else
  {
    if ( !(unsigned int)__ratelimit(&swr_connect_port__rs, "swr_connect_port") )
      return 4294967274LL;
    printk(&unk_9A20, "swr_connect_port");
    return 4294967274LL;
  }
}
