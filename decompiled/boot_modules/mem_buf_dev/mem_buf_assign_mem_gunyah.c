__int64 __fastcall mem_buf_assign_mem_gunyah(unsigned int a1, __int64 a2, unsigned int *a3)
{
  int v6; // w0
  unsigned __int64 v7; // x0
  unsigned __int64 v8; // x19
  _DWORD *v9; // x20
  __int64 v10; // x27
  __int64 v11; // x25
  __int64 v12; // x26
  __int64 v13; // x24
  unsigned __int64 v14; // x23
  unsigned __int64 v15; // x8
  _DWORD *v16; // x9
  int v17; // w10
  unsigned int v18; // w0
  unsigned int v19; // w21
  unsigned __int64 StatusReg; // x28
  __int64 v22; // [xsp+8h] [xbp-8h]

  v6 = mem_buf_vm_uses_gunyah(*((_QWORD *)a3 + 1), *a3);
  if ( v6 < 1 )
  {
    LODWORD(v9) = v6;
    return (unsigned int)v9;
  }
  v7 = mem_buf_sgt_to_gh_sgl_desc(a2);
  v8 = v7;
  if ( v7 < 0xFFFFFFFFFFFFF001LL )
  {
    v10 = *a3;
    v11 = *((_QWORD *)a3 + 1);
    v12 = *((_QWORD *)a3 + 2);
    v13 = 4 * v10;
    v14 = 4 * v10 + 4;
    v9 = (_DWORD *)_kmalloc_noprof(v14, 3264);
    if ( !v9 )
    {
LABEL_25:
      LODWORD(v9) = -12;
      goto LABEL_26;
    }
    while ( 1 )
    {
      *v9 = v10;
      if ( !(_DWORD)v10 )
        break;
      v15 = 0;
      while ( v13 != v15 )
      {
        if ( v14 < v15 + 4 )
          break;
        if ( v13 == v15 )
          break;
        v16 = &v9[v15 / 4];
        LOWORD(v9[v15 / 4 + 1]) = *(_DWORD *)(v11 + v15);
        if ( v14 < v15 + 6 )
          break;
        v17 = *(_DWORD *)(v12 + v15);
        v15 += 4LL;
        *((_BYTE *)v16 + 6) = v17;
        if ( v13 == v15 )
          goto LABEL_13;
      }
      __break(1u);
      StatusReg = _ReadStatusReg(SP_EL0);
      v22 = *(_QWORD *)(StatusReg + 80);
      *(_QWORD *)(StatusReg + 80) = &mem_buf_vmid_perm_list_to_gh_acl__alloc_tag;
      v9 = (_DWORD *)_kmalloc_noprof(4 * v10 + 4, 3264);
      *(_QWORD *)(StatusReg + 80) = v22;
      if ( !v9 )
        goto LABEL_25;
    }
LABEL_13:
    if ( (unsigned __int64)v9 >= 0xFFFFFFFFFFFFF001LL )
      goto LABEL_26;
    if ( a1 )
    {
      if ( a1 == 2 )
      {
        v18 = ghd_rm_mem_share(0, a3[7], a3[8], v9, v8, 0, a3 + 6);
      }
      else
      {
        if ( a1 != 1 )
        {
          printk(&unk_139CD, "mem_buf_assign_mem_gunyah", a1);
          v18 = -22;
LABEL_23:
          v19 = v18;
          printk(&unk_12F8D, "mem_buf_assign_mem_gunyah", v18);
          kfree(v9);
          LODWORD(v9) = v19;
LABEL_26:
          kvfree(v8);
          return (unsigned int)v9;
        }
        v18 = ghd_rm_mem_lend(0, a3[7], a3[8], v9, v8, 0, a3 + 6);
      }
    }
    else
    {
      v18 = gh_rm_mem_donate(0, a3[7], a3[8], v9, v8, 0, a3 + 6);
    }
    if ( (v18 & 0x80000000) == 0 )
    {
      kfree(v9);
      kvfree(v8);
      LODWORD(v9) = 0;
      return (unsigned int)v9;
    }
    goto LABEL_23;
  }
  LODWORD(v9) = v7;
  return (unsigned int)v9;
}
