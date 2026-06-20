__int64 __fastcall cvp_hfi_initialize(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 result; // x0
  __int64 v6; // x21
  int v7; // w19
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v9; // x8

  result = _kmalloc_cache_noprof(kmem_cache_destroy, 3520, 200);
  if ( result )
  {
    v6 = result;
    v7 = cvp_iris_hfi_initialize(result, a2, a3);
    if ( v7 != -517 )
    {
      if ( !v7 )
        return v6;
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        StatusReg = _ReadStatusReg(SP_EL0);
        printk(&unk_8415C, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
      }
    }
    kfree(v6);
    return v7;
  }
  else if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v9 = _ReadStatusReg(SP_EL0);
    printk(&unk_938E1, *(unsigned int *)(v9 + 1800), *(unsigned int *)(v9 + 1804), &unk_8E7CE);
    return 0;
  }
  return result;
}
