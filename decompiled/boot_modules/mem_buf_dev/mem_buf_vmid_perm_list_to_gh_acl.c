__int64 __fastcall mem_buf_vmid_perm_list_to_gh_acl(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 v6; // x23
  unsigned __int64 v7; // x21
  __int64 result; // x0
  __int64 v9; // x8
  __int64 v10; // x9
  int v11; // w10
  unsigned __int64 StatusReg; // x24
  __int64 v13; // x25

  v6 = 4LL * a3;
  v7 = v6 + 4;
  result = _kmalloc_noprof(v6 + 4, 3264);
  if ( !result )
    return -12;
  while ( 1 )
  {
    *(_DWORD *)result = a3;
    if ( !a3 )
      break;
    v9 = 0;
    while ( v7 >= v9 + 4 )
    {
      if ( v6 == v9 )
        break;
      v10 = result + v9;
      *(_WORD *)(result + v9 + 4) = *(_DWORD *)(a1 + v9);
      if ( v7 < v9 + 6 )
        break;
      v11 = *(_DWORD *)(a2 + v9);
      v9 += 4;
      *(_BYTE *)(v10 + 6) = v11;
      if ( v6 == v9 )
        return result;
    }
    __break(1u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v13 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &mem_buf_vmid_perm_list_to_gh_acl__alloc_tag;
    result = _kmalloc_noprof(v6 + 4, 3264);
    *(_QWORD *)(StatusReg + 80) = v13;
    if ( !result )
      return -12;
  }
  return result;
}
