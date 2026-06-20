__int64 __fastcall rmnet_frag_descriptor_add_frag(__int64 a1, __int64 a2, int a3, int a4)
{
  __int64 v8; // x0
  __int64 v9; // x8
  __int64 v10; // x9
  __int64 v11; // x2
  __int64 *v12; // x1
  unsigned int v20; // w9

  v8 = _kmalloc_cache_noprof(nla_put, 2336, 32);
  if ( !v8 )
    return 4294967284LL;
  *(_QWORD *)v8 = v8;
  v9 = a2;
  *(_QWORD *)(v8 + 8) = v8;
  v10 = *(_QWORD *)(a2 + 8);
  if ( (v10 & 1) != 0 )
    v9 = v10 - 1;
  _X8 = (unsigned int *)(v9 + 52);
  __asm { PRFM            #0x11, [X8] }
  do
    v20 = __ldxr(_X8);
  while ( __stxr(v20 + 1, _X8) );
  v11 = a1 + 16;
  v12 = *(__int64 **)(a1 + 24);
  *(_QWORD *)(v8 + 16) = a2;
  *(_DWORD *)(v8 + 24) = a4;
  *(_DWORD *)(v8 + 28) = a3;
  if ( v8 == a1 + 16 || v12 == (__int64 *)v8 || *v12 != v11 )
  {
    _list_add_valid_or_report(v8, v12, v11);
  }
  else
  {
    *(_QWORD *)(a1 + 24) = v8;
    *(_QWORD *)v8 = v11;
    *(_QWORD *)(v8 + 8) = v12;
    *v12 = v8;
  }
  *(_DWORD *)(a1 + 48) += a4;
  return 0;
}
