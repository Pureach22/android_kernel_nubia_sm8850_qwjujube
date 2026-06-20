__int64 __fastcall mem_buf_gh_acl_desc_to_vmid_perm_list(unsigned int *a1, __int64 *a2, __int64 *a3)
{
  __int64 result; // x0
  __int64 v6; // x25
  unsigned __int64 v8; // x20
  __int64 v9; // x23
  __int64 v10; // x0
  unsigned __int64 v11; // x9
  unsigned __int64 StatusReg; // x24
  __int64 v13; // x26

  result = 4294967274LL;
  if ( a2 && a3 )
  {
    v6 = *a1;
    v8 = 4 * v6;
    v9 = _kmalloc_noprof(4 * v6, 3264);
    if ( v9 )
    {
      while ( 1 )
      {
        v10 = _kmalloc_noprof(4 * v6, 3264);
        if ( !v10 )
          break;
        *a2 = v9;
        *a3 = v10;
        if ( !(_DWORD)v6 )
          return 0;
        v11 = 0;
        while ( v8 > v11 )
        {
          *(_DWORD *)(v9 + v11) = LOWORD(a1[v11 / 4 + 1]);
          if ( 4 * v6 <= v11 )
            break;
          *(_DWORD *)(v10 + v11) = BYTE2(a1[v11 / 4 + 1]);
          v11 += 4LL;
          if ( 4 * v6 == v11 )
            return 0;
        }
        __break(1u);
        v8 = 4 * v6;
        StatusReg = _ReadStatusReg(SP_EL0);
        v13 = *(_QWORD *)(StatusReg + 80);
        *(_QWORD *)(StatusReg + 80) = &mem_buf_gh_acl_desc_to_vmid_perm_list__alloc_tag;
        v9 = _kmalloc_noprof(4 * v6, 3264);
        *(_QWORD *)(StatusReg + 80) = v13;
        if ( !v9 )
          return 4294967284LL;
      }
      kfree(v9);
    }
    return 4294967284LL;
  }
  return result;
}
