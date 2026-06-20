__int64 __fastcall ipa3_teth_bridge_disconnect(int a1)
{
  __int64 v1; // x19
  __int64 v2; // x20
  unsigned int v3; // w0
  __int64 result; // x0
  unsigned int v5; // w19

  v1 = ipa3_teth_ctx;
  if ( a1 == 20 )
    v2 = 164;
  else
    v2 = 160;
  v3 = ((__int64 (__fastcall *)(_QWORD))ipa_pm_deactivate_sync)(*(unsigned int *)(ipa3_teth_ctx + v2));
  if ( v3 )
  {
    v5 = v3;
    printk(&unk_3E21FE, "ipa3_teth_bridge_disconnect");
    return v5;
  }
  else
  {
    result = ((__int64 (__fastcall *)(_QWORD))ipa_pm_deregister)(*(unsigned int *)(v1 + v2));
    *(_DWORD *)(v1 + v2) = -1;
  }
  return result;
}
