__int64 __fastcall hfi_process_session_rel_buf_done(int a1, _DWORD *a2, __int64 a3, __int64 a4)
{
  __int64 result; // x0
  unsigned __int64 v5; // x9
  _DWORD *v8; // x20
  __int64 v9; // x23
  int v10; // w0
  unsigned __int64 StatusReg; // x8
  int v12; // w20

  if ( a2 && *a2 > 0x3Bu )
  {
    v8 = a2;
    if ( (msm_cvp_debug & 0x2000) != 0 && !msm_cvp_debug_out )
    {
      printk(&unk_9653A, "sess", (unsigned int)a2[2], a4);
      a2 = v8;
    }
    v9 = (unsigned int)a2[2];
    v10 = hfi_map_err_status((unsigned int)a2[3]);
    if ( v10 && (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      v12 = v10;
      printk(&unk_95A25, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
      v10 = v12;
    }
    *(_DWORD *)(a3 + 24) = v10;
    *(_DWORD *)a3 = 23;
    *(_DWORD *)(a3 + 8) = a1;
    *(_DWORD *)(a3 + 12) = 0;
    *(_QWORD *)(a3 + 16) = v9;
    memset((void *)(a3 + 28), 0, 0x2E4u);
    return 0;
  }
  else
  {
    result = 4294967289LL;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v5 = _ReadStatusReg(SP_EL0);
      printk(&unk_8EB41, *(unsigned int *)(v5 + 1800), *(unsigned int *)(v5 + 1804), &unk_8E7CE);
      return 4294967289LL;
    }
  }
  return result;
}
