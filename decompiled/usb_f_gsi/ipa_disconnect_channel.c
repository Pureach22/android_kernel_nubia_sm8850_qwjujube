__int64 __fastcall ipa_disconnect_channel(__int64 *a1)
{
  __int64 *v2; // x20
  __int64 v3; // x2
  __int64 v4; // x0
  __int64 v5; // x1
  __int64 (__fastcall *v6)(__int64, __int64, __int64); // x8
  int v7; // w0
  __int64 v8; // x0
  __int64 result; // x0

  v2 = a1 - 38;
  if ( a1 != qword_130 )
    ipc_log_string(a1[130], "%s: Calling xdci_disconnect", "ipa_disconnect_channel");
  v3 = *((unsigned int *)a1 - 20);
  v5 = *((unsigned int *)a1 + 57);
  v4 = *((unsigned int *)a1 + 58);
  v6 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(a1[93] + 16);
  if ( *((_DWORD *)v6 - 1) != 1770373914 )
    __break(0x8228u);
  v7 = v6(v4, v5, v3);
  if ( v2 && v7 )
  {
    ipc_log_string(a1[130], "%s: IPA disconnect failed %d", "ipa_disconnect_channel", v7);
    printk(&unk_10702, "ipa_disconnect_channel");
  }
  else if ( !v2 )
  {
    goto LABEL_9;
  }
  ipc_log_string(a1[130], "%s: xdci_disconnect done", "ipa_disconnect_channel");
LABEL_9:
  v8 = *a1;
  *(__int64 *)((char *)a1 + 228) = 0xFFFFFFEAFFFFFFEALL;
  if ( v8 )
  {
    usb_gsi_ep_op(v8, a1 + 2, 10);
    msm_ep_set_mode(*a1, 0);
  }
  result = a1[1];
  if ( result )
  {
    usb_gsi_ep_op(result, a1 + 13, 10);
    return msm_ep_set_mode(a1[1], 0);
  }
  return result;
}
