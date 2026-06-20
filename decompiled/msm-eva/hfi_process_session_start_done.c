__int64 __fastcall hfi_process_session_start_done(int a1, _DWORD *a2, __int64 a3, __int64 a4)
{
  __int64 result; // x0
  unsigned __int64 StatusReg; // x9
  __int64 v6; // x21
  int v7; // w22
  __int64 v8; // x23
  int v9; // w0
  int v10; // w19
  _DWORD *v11; // x21
  __int64 v12; // x22
  unsigned __int64 v13; // x8
  int v14; // w20

  if ( (msm_cvp_debug & 0x2000) != 0 && !msm_cvp_debug_out )
  {
    v10 = a1;
    v11 = a2;
    v12 = a3;
    printk(&unk_8F4EB, "sess", (unsigned int)a2[2], a4);
    a1 = v10;
    a2 = v11;
    a3 = v12;
    if ( !v11 )
    {
LABEL_5:
      result = 4294967289LL;
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        StatusReg = _ReadStatusReg(SP_EL0);
        printk(&unk_82FFE, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
        return 4294967289LL;
      }
      return result;
    }
  }
  else if ( !a2 )
  {
    goto LABEL_5;
  }
  if ( *a2 <= 0x37u )
    goto LABEL_5;
  v6 = (unsigned int)a2[2];
  v7 = a1;
  v8 = a3;
  v9 = hfi_map_err_status((unsigned int)a2[3]);
  if ( v9 && (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v13 = _ReadStatusReg(SP_EL0);
    v14 = v9;
    printk(&unk_95A25, *(unsigned int *)(v13 + 1800), *(unsigned int *)(v13 + 1804), &unk_8E7CE);
    v9 = v14;
  }
  *(_DWORD *)(v8 + 24) = v9;
  *(_DWORD *)v8 = 15;
  *(_DWORD *)(v8 + 8) = v7;
  *(_DWORD *)(v8 + 12) = 0;
  *(_QWORD *)(v8 + 16) = v6;
  memset((void *)(v8 + 28), 0, 0x2E4u);
  return 0;
}
