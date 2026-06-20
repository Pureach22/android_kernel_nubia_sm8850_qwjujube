__int64 __fastcall swr_connect_port_v2(
        __int64 a1,
        __int64 a2,
        unsigned __int8 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v8; // x19
  int v9; // w20
  _BYTE *v18; // x20
  __int64 v19; // x22
  __int64 v20; // x0
  __int64 v21; // x8
  int v22; // w8
  char v23; // w8
  char v24; // w8
  unsigned __int64 v25; // x9
  _DWORD *v26; // x10
  _BYTE *v27; // x13
  char v28; // w14
  int v29; // w12
  _DWORD *v30; // x8
  unsigned __int64 StatusReg; // x22
  size_t (*v32)(const char *, size_t); // x0
  __int64 v33; // [xsp+10h] [xbp-10h]

  v8 = *(_QWORD *)(a1 + 32);
  if ( v8 )
  {
    v9 = a3;
    if ( a3 >= 0xFu )
    {
      if ( (unsigned int)__ratelimit(&swr_connect_port_v2__rs_22, "swr_connect_port_v2") )
      {
        dev_err(v8, "%s: num_port %d exceeds max port %d\n", "swr_connect_port_v2", v9, 14);
        return 4294967274LL;
      }
      return 4294967274LL;
    }
    v18 = (_BYTE *)_kmalloc_cache_noprof(strnlen, 3520, 172);
    if ( v18 )
    {
      while ( 1 )
      {
        mutex_lock(v8 + 936);
        v19 = *(unsigned __int8 *)(v8 + 8408);
        if ( *(_BYTE *)(v8 + 8408) )
          break;
        v22 = 0;
LABEL_16:
        v20 = krealloc_noprof(*(_QWORD *)(v8 + 8392), (unsigned int)(8 * v22 + 8), 3264);
        if ( !v20 )
        {
          mutex_unlock(v8 + 936);
          kfree(v18);
          if ( (unsigned int)__ratelimit(&swr_connect_port_v2__rs_26, "swr_connect_port_v2") )
            dev_err(v8, "%s Not able to allocate\nmaster port transaction memory\n", "swr_connect_port_v2");
          return 4294967284LL;
        }
        v23 = *(_BYTE *)(v8 + 8408);
        *(_QWORD *)(v8 + 8392) = v20;
        *(_BYTE *)(v8 + 8408) = v23 + 1;
LABEL_19:
        *(_QWORD *)(v20 + 8LL * (unsigned int)v19) = v18;
        mutex_unlock(v8 + 936);
        v24 = *(_BYTE *)(a1 + 64);
        *v18 = v19;
        v18[2] = a3;
        v18[1] = v24;
        if ( !a3 )
        {
LABEL_26:
          v30 = *(_DWORD **)(v8 + 8416);
          if ( *(v30 - 1) != -194885138 )
            __break(0x8228u);
          return ((__int64 (__fastcall *)(__int64, _BYTE *))v30)(v8, v18);
        }
        v25 = 0;
        v26 = v18 + 116;
        while ( v25 <= 0xA8 )
        {
          v18[v25 + 3] = *(_BYTE *)(a2 + v25);
          if ( v25 > 0x9A )
            break;
          v18[v25 + 17] = *(_BYTE *)(a6 + v25);
          if ( v25 > 0x22 )
            break;
          v27 = &v18[v25];
          *(v26 - 21) = *(_DWORD *)(a5 + 4 * v25);
          v28 = *(_BYTE *)(a7 + v25);
          v27[88] = *(_BYTE *)(a4 + v25);
          v27[102] = v28;
          if ( v25 > 0xD )
            break;
          v29 = *(_DWORD *)(a8 + 4 * v25++);
          *v26++ = v29;
          if ( a3 == v25 )
            goto LABEL_26;
        }
        __break(1u);
        StatusReg = _ReadStatusReg(SP_EL0);
        v32 = strnlen;
        v33 = *(_QWORD *)(StatusReg + 80);
        *(_QWORD *)(StatusReg + 80) = &swr_connect_port_v2__alloc_tag;
        v18 = (_BYTE *)_kmalloc_cache_noprof(v32, 3520, 172);
        *(_QWORD *)(StatusReg + 80) = v33;
        if ( !v18 )
          return 4294967284LL;
      }
      v20 = *(_QWORD *)(v8 + 8392);
      v21 = 0;
      do
      {
        if ( !*(_QWORD *)(v20 + 8 * v21) )
        {
          LODWORD(v19) = (unsigned __int8)v21;
          goto LABEL_19;
        }
        ++v21;
      }
      while ( v19 != v21 );
      v22 = *(unsigned __int8 *)(v8 + 8408);
      if ( (_DWORD)v19 != 255 )
        goto LABEL_16;
      mutex_unlock(v8 + 936);
      kfree(v18);
      if ( (unsigned int)__ratelimit(&swr_connect_port_v2__rs_23, "swr_connect_port_v2") )
        dev_err(v8, "%s Max tid reached\n", "swr_connect_port_v2");
    }
    return 4294967284LL;
  }
  else
  {
    if ( !(unsigned int)__ratelimit(&swr_connect_port_v2__rs, "swr_connect_port_v2") )
      return 4294967274LL;
    printk(&unk_9A20, "swr_connect_port_v2");
    return 4294967274LL;
  }
}
