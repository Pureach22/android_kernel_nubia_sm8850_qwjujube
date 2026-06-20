__int64 __fastcall md_register_panic_entries(int a1, __int64 a2, __int64 **a3)
{
  __int64 v6; // x22
  __int64 v7; // x20
  __int64 *v8; // x24
  __int64 v9; // x8
  unsigned __int64 v10; // x12
  __int64 v11; // x9
  __int64 v12; // x8
  __int64 v13; // x2
  unsigned int v14; // w0
  unsigned int v16; // w19
  unsigned __int64 StatusReg; // x24
  __int64 v18; // x25

  v6 = (__int64)a1 << 12;
  v7 = _kmalloc_noprof(v6, 3520);
  if ( !v7 )
    return 4294967274LL;
  while ( 1 )
  {
    v8 = (__int64 *)_kmalloc_cache_noprof(_fortify_panic, 3520, 24);
    if ( !v8 )
      break;
    v9 = v7 << 8 >> 8;
    v10 = (unsigned __int64)(v9 + 0x8000000000LL) >> 38;
    v11 = memstart_addr + v9 + 0x8000000000LL;
    v12 = v9 - kimage_voffset;
    if ( v10 )
      v13 = v12;
    else
      v13 = v11;
    v14 = md_register_minidump_entry(a2, v7, v13, (__int64)a1 << 12);
    if ( (v14 & 0x80000000) != 0 )
    {
      v16 = v14;
      kfree(v8);
      goto LABEL_15;
    }
    v8[2] = 0;
    *v8 = v7;
    v8[1] = (unsigned int)(a1 << 12);
    if ( (a1 & 0xFFFFFLL) == 0 )
      goto LABEL_10;
    if ( v6 )
    {
      *(_BYTE *)v7 = 0;
LABEL_10:
      __dmb(0xBu);
      *a3 = v8;
      return 0;
    }
    __break(1u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v18 = *(_QWORD *)(StatusReg + 80);
    v6 = (__int64)a1 << 12;
    *(_QWORD *)(StatusReg + 80) = &_start_alloc_tags;
    v7 = _kmalloc_noprof(v6, 3520);
    *(_QWORD *)(StatusReg + 80) = v18;
    if ( !v7 )
      return 4294967274LL;
  }
  v16 = -22;
LABEL_15:
  kfree(v7);
  return v16;
}
