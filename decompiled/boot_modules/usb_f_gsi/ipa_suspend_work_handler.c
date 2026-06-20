__int64 __fastcall ipa_suspend_work_handler(__int64 *a1)
{
  __int64 *v2; // x20
  int v3; // w3
  unsigned int v4; // w23
  unsigned int v5; // w21
  unsigned int v6; // w22
  __int64 v7; // x8
  char v8; // w24
  _DWORD *v9; // x25
  __int64 v10; // x0
  unsigned int v11; // w21
  const char *v12; // x3
  __int64 v13; // x0
  _BYTE v15[4]; // [xsp+0h] [xbp-10h] BYREF
  _BYTE v16[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v17; // [xsp+8h] [xbp-8h]

  v2 = a1 - 38;
  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *((unsigned __int8 *)a1 - 19);
  v16[0] = 0;
  v15[0] = v3;
  if ( a1 != qword_130 )
  {
    ipc_log_string(a1[130], "%s: f_suspend:%d", "ipa_suspend_work_handler", v3);
    if ( (unsigned int)usb_gsi_ep_op(*a1, v15, 12) )
    {
      ipc_log_string(a1[130], "%s: Calling xdci_suspend", "ipa_suspend_work_handler");
      goto LABEL_5;
    }
LABEL_8:
    v10 = *a1;
    v16[0] = 0;
    usb_gsi_ep_op(v10, v16, 11);
    v11 = -14;
    if ( !v2 )
      goto LABEL_29;
    goto LABEL_25;
  }
  if ( !(unsigned int)usb_gsi_ep_op(0xEA040000A964LL, v15, 12) )
    goto LABEL_8;
LABEL_5:
  v4 = *((_DWORD *)a1 - 20);
  v6 = *((_DWORD *)a1 + 57);
  v5 = *((_DWORD *)a1 + 58);
  v7 = a1[93];
  if ( *(_DWORD *)(**(_QWORD **)(*(a1 - 32) + 48) + 72LL) < 5u )
  {
    v8 = 1;
    v9 = *(_DWORD **)(v7 + 32);
    if ( !v2 )
      goto LABEL_15;
LABEL_11:
    if ( (v8 & 1) != 0 )
      v12 = "true";
    else
      v12 = "false";
    ipc_log_string(a1[130], "%s: remote_wakeup_allowed:%s", "usb_gsi_remote_wakeup_allowed", v12);
    goto LABEL_15;
  }
  v8 = *((_BYTE *)a1 - 19);
  v9 = *(_DWORD **)(v7 + 32);
  if ( v2 )
    goto LABEL_11;
LABEL_15:
  if ( *(v9 - 1) != -108795553 )
    __break(0x8239u);
  v11 = ((__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD, _QWORD))v9)(v5, v6, v4, v8 & 1);
  if ( v11 != -115 )
  {
    if ( v11 == -14 )
    {
      v13 = *a1;
      v16[0] = 0;
      usb_gsi_ep_op(v13, v16, 11);
      gsi_wakeup_host(v2);
      if ( !v2 )
        goto LABEL_29;
    }
    else if ( v11 )
    {
      if ( !v2 )
        goto LABEL_29;
      ipc_log_string(a1[130], "%s: Error %d for %d", "ipa_suspend_work_handler", v11, *((_DWORD *)a1 - 20));
      printk(&unk_121D7, "ipa_suspend_work_handler");
    }
    else
    {
      *((_DWORD *)a1 + 96) = 7;
      if ( !v2 )
      {
        v11 = 0;
        goto LABEL_29;
      }
      ipc_log_string(a1[130], "%s: STATE SUSPENDED", "ipa_suspend_work_handler");
      v11 = 0;
    }
    goto LABEL_25;
  }
  *((_DWORD *)a1 + 96) = 6;
  if ( v2 )
LABEL_25:
    ipc_log_string(a1[130], "%s: xdci_suspend ret %d", "ipa_suspend_work_handler", v11);
LABEL_29:
  _ReadStatusReg(SP_EL0);
  return v11;
}
