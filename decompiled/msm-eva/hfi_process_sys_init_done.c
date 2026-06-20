__int64 __fastcall hfi_process_sys_init_done(int a1, _DWORD *a2, __int64 a3, __int64 a4)
{
  __int64 result; // x0
  unsigned __int64 v7; // x8
  int v8; // w0
  unsigned __int64 StatusReg; // x8
  int v10; // w22
  _DWORD *v11; // x23

  if ( (msm_cvp_debug & 0x100) != 0 && !msm_cvp_debug_out )
  {
    v11 = a2;
    printk(&unk_90ABC, "core", a3, a4);
    a2 = v11;
  }
  if ( *a2 > 0xFu )
  {
    if ( a2[3] )
    {
      v8 = hfi_map_err_status((unsigned int)a2[2]);
      if ( v8 && (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        StatusReg = _ReadStatusReg(SP_EL0);
        v10 = v8;
        printk(&unk_95A25, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
        v8 = v10;
      }
    }
    else
    {
      v8 = 0;
      if ( (msm_cvp_debug & 0x100) != 0 && !msm_cvp_debug_out )
      {
        printk(&unk_89DEB, "core", a3, a4);
        v8 = 0;
      }
    }
    *(_DWORD *)a3 = 1;
    *(_DWORD *)(a3 + 24) = v8;
    *(_DWORD *)(a3 + 28) = 32;
    *(_DWORD *)(a3 + 8) = a1;
    *(_DWORD *)(a3 + 12) = 0;
    *(_QWORD *)(a3 + 16) = 0;
    memset((void *)(a3 + 32), 0, 0x2E0u);
    return 0;
  }
  else
  {
    result = 4294967289LL;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v7 = _ReadStatusReg(SP_EL0);
      printk(&unk_90242, *(unsigned int *)(v7 + 1800), *(unsigned int *)(v7 + 1804), &unk_8E7CE);
      return 4294967289LL;
    }
  }
  return result;
}
