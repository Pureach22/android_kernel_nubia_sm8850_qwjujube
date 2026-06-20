__int64 __fastcall get_vmperm_from_ion_flags(__int64 a1, __int64 *a2, __int64 *a3, unsigned int *a4)
{
  __int64 result; // x0
  unsigned int v9; // w22
  unsigned __int64 v10; // x24
  __int64 v11; // x23
  __int64 v12; // x27
  unsigned __int64 v13; // x28
  int vmid_perms; // w0
  unsigned __int64 StatusReg; // x26
  __int64 v16; // x27

  result = 4294967274LL;
  if ( a2 && a3 && a4 )
  {
    v9 = _sw_hweight64(a1);
    v10 = 4LL * v9;
    v11 = _kmalloc_noprof(v10, 3520);
    if ( v11 )
    {
      while ( 1 )
      {
        v12 = _kmalloc_noprof(4LL * v9, 3520);
        if ( !v12 )
          break;
        if ( (a1 & 0xFFFFFFFF80007FFFLL) != 0 || (unsigned int)populate_vm_list(a1, v11, v9) )
        {
          printk(&unk_DF78, "get_vmperm_from_ion_flags");
          kfree(v12);
          kfree(v11);
          return 4294967274LL;
        }
        if ( !v9 )
        {
LABEL_13:
          *a2 = v11;
          *a3 = v12;
          *a4 = v9;
          return 0;
        }
        v13 = 0;
        a1 = 4LL * v9;
        while ( v10 > v13 )
        {
          vmid_perms = msm_secure_get_vmid_perms(*(unsigned int *)(v11 + v13));
          if ( 4 * (unsigned __int64)v9 <= v13 )
            break;
          *(_DWORD *)(v12 + v13) = vmid_perms;
          v13 += 4LL;
          if ( a1 == v13 )
            goto LABEL_13;
        }
        __break(1u);
        v10 = 4LL * v9;
        StatusReg = _ReadStatusReg(SP_EL0);
        v16 = *(_QWORD *)(StatusReg + 80);
        *(_QWORD *)(StatusReg + 80) = &get_vmperm_from_ion_flags__alloc_tag;
        v11 = _kmalloc_noprof(v10, 3520);
        *(_QWORD *)(StatusReg + 80) = v16;
        if ( !v11 )
          return 4294967284LL;
      }
      kfree(v11);
    }
    return 4294967284LL;
  }
  return result;
}
