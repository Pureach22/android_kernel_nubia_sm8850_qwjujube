__int64 __fastcall swr_disconnect_port(__int64 a1, __int64 a2, unsigned __int8 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x19
  int v6; // w20
  _BYTE *v13; // x20
  __int64 v14; // x26
  __int64 v15; // x0
  __int64 v16; // x8
  int v17; // w8
  char v18; // w8
  char v19; // w8
  unsigned __int64 v20; // x8
  _BYTE *v21; // x10
  char v22; // w11
  _DWORD *v23; // x8
  unsigned __int64 StatusReg; // x26
  __int64 v25; // x27
  size_t (*v26)(const char *, size_t); // x0

  v5 = *(_QWORD *)(a1 + 32);
  if ( v5 )
  {
    v6 = a3;
    if ( a3 >= 0xFu )
    {
      if ( (unsigned int)__ratelimit(&swr_disconnect_port__rs_27, "swr_disconnect_port") )
      {
        dev_err(v5, "%s: num_port %d exceeds max port %d\n", "swr_disconnect_port", v6, 14);
        return 4294967274LL;
      }
      return 4294967274LL;
    }
    v13 = (_BYTE *)_kmalloc_cache_noprof(strnlen, 3520, 172);
    if ( v13 )
    {
      while ( 1 )
      {
        mutex_lock(v5 + 936);
        v14 = *(unsigned __int8 *)(v5 + 8408);
        if ( *(_BYTE *)(v5 + 8408) )
          break;
        v17 = 0;
LABEL_16:
        v15 = krealloc_noprof(*(_QWORD *)(v5 + 8392), (unsigned int)(8 * v17 + 8), 3264);
        if ( !v15 )
        {
          mutex_unlock(v5 + 936);
          kfree(v13);
          if ( (unsigned int)__ratelimit(&swr_disconnect_port__rs_31, "swr_disconnect_port") )
            dev_err(v5, "%s Not able to allocate\nmaster port transaction memory\n", "swr_disconnect_port");
          return 4294967284LL;
        }
        v18 = *(_BYTE *)(v5 + 8408);
        *(_QWORD *)(v5 + 8392) = v15;
        *(_BYTE *)(v5 + 8408) = v18 + 1;
LABEL_19:
        *(_QWORD *)(v15 + 8LL * (unsigned int)v14) = v13;
        mutex_unlock(v5 + 936);
        v19 = *(_BYTE *)(a1 + 64);
        *v13 = v14;
        v13[2] = a3;
        v13[1] = v19;
        if ( !a3 )
        {
LABEL_25:
          v23 = *(_DWORD **)(v5 + 8424);
          if ( *(v23 - 1) != -194885138 )
            __break(0x8228u);
          return ((__int64 (__fastcall *)(__int64, _BYTE *))v23)(v5, v13);
        }
        v20 = 0;
        while ( v20 <= 0xA8 )
        {
          v13[v20 + 3] = *(_BYTE *)(a2 + v20);
          if ( v20 > 0x53 )
            break;
          v13[v20 + 88] = *(_BYTE *)(a4 + v20);
          if ( v20 > 0x45 )
            break;
          v21 = &v13[v20];
          v22 = *(_BYTE *)(a5 + v20++);
          v21[102] = v22;
          if ( a3 == v20 )
            goto LABEL_25;
        }
        __break(1u);
        StatusReg = _ReadStatusReg(SP_EL0);
        v25 = *(_QWORD *)(StatusReg + 80);
        v26 = strnlen;
        *(_QWORD *)(StatusReg + 80) = &swr_disconnect_port__alloc_tag;
        v13 = (_BYTE *)_kmalloc_cache_noprof(v26, 3520, 172);
        *(_QWORD *)(StatusReg + 80) = v25;
        if ( !v13 )
          return 4294967284LL;
      }
      v15 = *(_QWORD *)(v5 + 8392);
      v16 = 0;
      do
      {
        if ( !*(_QWORD *)(v15 + 8 * v16) )
        {
          LODWORD(v14) = (unsigned __int8)v16;
          goto LABEL_19;
        }
        ++v16;
      }
      while ( v14 != v16 );
      v17 = *(unsigned __int8 *)(v5 + 8408);
      if ( (_DWORD)v14 != 255 )
        goto LABEL_16;
      mutex_unlock(v5 + 936);
      kfree(v13);
      if ( (unsigned int)__ratelimit(&swr_disconnect_port__rs_28, "swr_disconnect_port") )
        dev_err(v5, "%s Max tid reached\n", "swr_disconnect_port");
    }
    return 4294967284LL;
  }
  else
  {
    if ( !(unsigned int)__ratelimit(&swr_disconnect_port__rs, "swr_disconnect_port") )
      return 4294967274LL;
    printk(&unk_9A20, "swr_disconnect_port");
    return 4294967274LL;
  }
}
