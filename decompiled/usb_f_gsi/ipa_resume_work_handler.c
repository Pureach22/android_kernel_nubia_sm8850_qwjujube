__int64 __fastcall ipa_resume_work_handler(__int64 *a1)
{
  __int64 *v2; // x20
  __int64 v3; // x2
  __int64 v4; // x0
  __int64 v5; // x1
  __int64 (__fastcall *v6)(__int64, __int64, __int64); // x8
  int v7; // w0
  __int64 v8; // x0
  __int64 result; // x0
  _BYTE v10[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+8h] [xbp-8h]

  v2 = a1 - 38;
  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 != qword_130 )
    ipc_log_string(a1[130], "%s: Calling xdci_resume", "ipa_resume_work_handler");
  v3 = *((unsigned int *)a1 - 20);
  v5 = *((unsigned int *)a1 + 57);
  v4 = *((unsigned int *)a1 + 58);
  v6 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(a1[93] + 40);
  if ( *((_DWORD *)v6 - 1) != 1770373914 )
    __break(0x8228u);
  v7 = v6(v4, v5, v3);
  if ( v2 && v7 )
  {
    ipc_log_string(a1[130], "%s: xdci_resume ret %d", "ipa_resume_work_handler", v7);
LABEL_9:
    ipc_log_string(a1[130], "%s: xdci_resume done", "ipa_resume_work_handler");
    goto LABEL_10;
  }
  if ( v2 )
    goto LABEL_9;
LABEL_10:
  v8 = *a1;
  v10[0] = 0;
  result = usb_gsi_ep_op(v8, v10, 11);
  _ReadStatusReg(SP_EL0);
  return result;
}
