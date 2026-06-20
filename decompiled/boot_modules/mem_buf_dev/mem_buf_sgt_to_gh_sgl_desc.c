__int64 __fastcall mem_buf_sgt_to_gh_sgl_desc(__int64 a1)
{
  unsigned __int64 v1; // x22
  unsigned __int64 v3; // x20
  __int64 v4; // x1
  _DWORD *v5; // x21
  int v6; // w8
  __int64 v7; // x0
  unsigned int v8; // w26
  unsigned __int64 v9; // x8
  _QWORD *v10; // x10
  unsigned __int64 StatusReg; // x23
  __int64 v12; // x24

  v1 = *(unsigned int *)(a1 + 12);
  v3 = (16 * v1) | 6;
  v5 = (_DWORD *)_kvmalloc_node_noprof(v3, 0, 3264, 0xFFFFFFFFLL);
  if ( !v5 )
    return -12;
  while ( 1 )
  {
    v6 = *(_DWORD *)(a1 + 12);
    *v5 = v6;
    if ( !v6 )
      break;
    v1 *= 16LL;
    v7 = *(_QWORD *)a1;
    v8 = 0;
    while ( 1 )
    {
      v9 = 16LL * (int)v8;
      if ( v1 <= v9 )
        break;
      v10 = (_QWORD *)((char *)&v5[4 * v8 + 1] + 2);
      *v10 = *(unsigned int *)(v7 + 8)
           + (((*(_QWORD *)v7 & 0x3FFFFFFFFFFFFFCLL) - -64LL * (memstart_addr >> 12)) << 6)
           + 0x5000000000LL;
      if ( v3 < (v9 | 0xE) )
        break;
      ++v8;
      v10[1] = *(unsigned int *)(v7 + 12);
      v7 = sg_next(v7, v4);
      if ( v8 >= *(_DWORD *)(a1 + 12) )
        return (__int64)v5;
    }
    __break(1u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v12 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &mem_buf_sgt_to_gh_sgl_desc__alloc_tag;
    v5 = (_DWORD *)_kvmalloc_node_noprof(v3, 0, 3264, 0xFFFFFFFFLL);
    *(_QWORD *)(StatusReg + 80) = v12;
    if ( !v5 )
      return -12;
  }
  return (__int64)v5;
}
