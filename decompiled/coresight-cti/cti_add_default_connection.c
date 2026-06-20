__int64 __fastcall cti_add_default_connection(__int64 a1, __int64 a2)
{
  int v3; // w26
  __int64 v5; // x0
  _QWORD *v6; // x21
  __int64 v7; // x25
  unsigned __int64 v8; // x22
  __int64 v9; // x0
  _DWORD *v10; // x24
  _DWORD *v11; // x0
  _DWORD *v12; // x23
  __int64 v13; // x27
  unsigned int v14; // w8
  size_t v15; // x1
  size_t v16; // x25
  size_t v17; // x1

  v3 = *(_DWORD *)(a2 + 68);
  v5 = devm_kmalloc(a1, 64, 3520);
  if ( !v5 )
    return 4294967284LL;
  v6 = (_QWORD *)v5;
  v7 = 4LL * v3;
  v8 = v7 + 24;
  v9 = devm_kmalloc(a1, v7 + 24, 3520);
  if ( !v9 )
    return 4294967284LL;
  v10 = (_DWORD *)v9;
  v11 = (_DWORD *)devm_kmalloc(a1, v7 + 24, 3520);
  if ( !v11 )
    return 4294967284LL;
  v12 = v11;
  *v6 = v10;
  v6[1] = v11;
  if ( v7 != -24 )
  {
    v13 = v7 + 16;
    v14 = (unsigned int)(v3 + 63) >> 3;
    if ( v8 >= 8 )
      v15 = v7 + 16;
    else
      v15 = 0;
    *v10 = v3;
    *v11 = v3;
    v16 = v14 & 0x1FFFFFF8;
    if ( v15 >= v16 )
    {
      memset(v10 + 2, 255, v14 & 0x1FFFFFF8);
      v17 = v8 >= 8 ? v13 : 0LL;
      if ( v17 >= v16 )
      {
        memset(v12 + 2, 255, v16);
        return cti_add_connection_entry(a1, a2, v6, 0, (__int64)"default");
      }
    }
    v11 = (_DWORD *)_fortify_panic(15);
  }
  __break(1u);
  return cti_trigin_gpio_disable(v11);
}
