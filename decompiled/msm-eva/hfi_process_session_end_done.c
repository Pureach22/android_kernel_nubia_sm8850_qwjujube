__int64 __fastcall hfi_process_session_end_done(int a1, _DWORD *a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x21
  int v5; // w22
  __int64 v6; // x23
  int v7; // w0
  __int64 result; // x0
  int v9; // w19
  _DWORD *v10; // x21
  __int64 v11; // x22
  unsigned __int64 v12; // x8
  unsigned __int64 StatusReg; // x8
  int v14; // w20

  if ( (msm_cvp_debug & 0x2000) != 0 && !msm_cvp_debug_out )
  {
    v9 = a1;
    v10 = a2;
    v11 = a3;
    printk(&unk_96509, "sess", (unsigned int)a2[2], a4);
    a2 = v10;
    a1 = v9;
    a3 = v11;
    if ( !v10 )
      goto LABEL_11;
  }
  else if ( !a2 )
  {
    goto LABEL_11;
  }
  if ( *a2 == 16 )
  {
    v4 = (unsigned int)a2[2];
    v5 = a1;
    v6 = a3;
    v7 = hfi_map_err_status((unsigned int)a2[3]);
    if ( v7 && (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      v14 = v7;
      printk(&unk_95A25, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
      v7 = v14;
    }
    *(_DWORD *)(v6 + 24) = v7;
    *(_DWORD *)v6 = 12;
    *(_DWORD *)(v6 + 8) = v5;
    *(_DWORD *)(v6 + 12) = 0;
    *(_QWORD *)(v6 + 16) = v4;
    memset((void *)(v6 + 28), 0, 0x2E4u);
    return 0;
  }
LABEL_11:
  result = 4294967289LL;
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v12 = _ReadStatusReg(SP_EL0);
    printk(&unk_825FF, *(unsigned int *)(v12 + 1800), *(unsigned int *)(v12 + 1804), &unk_8E7CE);
    return 4294967289LL;
  }
  return result;
}
