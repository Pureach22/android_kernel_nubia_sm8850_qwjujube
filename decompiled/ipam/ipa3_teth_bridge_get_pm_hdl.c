__int64 __fastcall ipa3_teth_bridge_get_pm_hdl(int a1)
{
  __int64 v1; // x9
  __int64 result; // x0

  v1 = 160;
  if ( a1 == 20 )
    v1 = 164;
  result = *(unsigned int *)(ipa3_teth_ctx + v1);
  if ( (_DWORD)result == -1 )
  {
    printk(&unk_3B6579, "ipa3_teth_bridge_get_pm_hdl");
    return 4294967274LL;
  }
  return result;
}
