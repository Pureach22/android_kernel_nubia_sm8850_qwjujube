__int64 __fastcall sde_vm_populate_sgl(__int64 a1)
{
  _QWORD **v1; // x19
  __int64 v2; // x21
  _QWORD *v3; // x8
  unsigned __int64 v4; // x20
  _DWORD *v5; // x0
  _QWORD *v6; // x8
  unsigned int v7; // w11
  unsigned int v8; // w10
  unsigned __int64 v9; // x12
  unsigned __int64 v10; // x12
  bool v11; // cf
  unsigned __int64 v12; // x12
  _QWORD *v13; // x11
  unsigned __int64 v14; // x12
  _DWORD *v15; // x20
  unsigned __int64 StatusReg; // x22
  __int64 v18; // x23

  v1 = (_QWORD **)(a1 + 16);
  sde_vm_sort_and_align((unsigned __int64 *)(a1 + 16));
  LODWORD(v2) = -1;
  v3 = v1;
  do
  {
    v3 = (_QWORD *)*v3;
    v2 = (unsigned int)(v2 + 1);
  }
  while ( v3 != v1 );
  v4 = (16 * v2) | 6;
  v5 = (_DWORD *)_kmalloc_noprof(v4, 3520);
  if ( !v5 )
    return 12;
  while ( 1 )
  {
    v6 = *v1;
    *v5 = v2;
    if ( v6 == v1 )
      break;
    v7 = 0;
    while ( 1 )
    {
      v8 = v7;
      v9 = (16LL * v7) | 6;
      v11 = v4 >= v9;
      v10 = v4 - v9;
      v11 = v11 && v10 >= 8;
      if ( !v11 )
        break;
      v12 = 16LL * v7;
      v13 = (_QWORD *)((char *)v5 + v12 + 6);
      v12 |= 0xEu;
      *v13 = *(v6 - 2);
      v11 = v4 >= v12;
      v14 = v4 - v12;
      if ( !v11 || v14 < 8 )
        break;
      v13[1] = *(v6 - 1);
      v7 = v8 + 1;
      v6 = (_QWORD *)*v6;
      if ( v6 == v1 )
        goto LABEL_15;
    }
    __break(1u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v18 = *(_QWORD *)(StatusReg + 80);
    v4 = (16 * v2) | 6;
    *(_QWORD *)(StatusReg + 80) = &sde_vm_populate_sgl__alloc_tag;
    v5 = (_DWORD *)_kmalloc_noprof(v4, 3520);
    *(_QWORD *)(StatusReg + 80) = v18;
    if ( !v5 )
      return 12;
  }
LABEL_15:
  v15 = v5;
  msm_dss_clean_io_mem(v1);
  return (__int64)v15;
}
