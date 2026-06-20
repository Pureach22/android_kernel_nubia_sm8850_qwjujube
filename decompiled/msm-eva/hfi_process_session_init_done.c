__int64 __fastcall hfi_process_session_init_done(int a1, _DWORD *a2, __int64 a3, __int64 a4)
{
  __int64 result; // x0
  unsigned __int64 v7; // x8
  __int64 v8; // x23
  int v9; // w0
  _DWORD *v10; // x21
  unsigned __int64 StatusReg; // x8
  int v12; // w22

  if ( (msm_cvp_debug & 0x2000) != 0 && !msm_cvp_debug_out )
  {
    v10 = a2;
    printk(&unk_930DA, "sess", (unsigned int)a2[2], a4);
    a2 = v10;
  }
  if ( *a2 > 0x13u )
  {
    v8 = (unsigned int)a2[2];
    v9 = hfi_map_err_status((unsigned int)a2[3]);
    if ( v9 && (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      v12 = v9;
      printk(&unk_95A25, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
      v9 = v12;
    }
    *(_DWORD *)a3 = 11;
    *(_DWORD *)(a3 + 24) = v9;
    *(_DWORD *)(a3 + 28) = 732;
    *(_DWORD *)(a3 + 8) = a1;
    *(_DWORD *)(a3 + 12) = 0;
    *(_QWORD *)(a3 + 16) = v8;
    memset((void *)(a3 + 32), 0, 0x2E0u);
    return 0;
  }
  else
  {
    result = 4294967289LL;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v7 = _ReadStatusReg(SP_EL0);
      printk(&unk_8BD9E, *(unsigned int *)(v7 + 1800), *(unsigned int *)(v7 + 1804), &unk_8E7CE);
      return 4294967289LL;
    }
  }
  return result;
}
