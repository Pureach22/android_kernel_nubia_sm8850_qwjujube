__int64 __fastcall hfi_util_kv_helper_dump(__int64 result)
{
  __int64 v1; // x19
  unsigned int v2; // w20

  if ( !result )
    return printk(&unk_2733C5, "hfi_util_kv_helper_dump");
  v1 = result;
  if ( *(_DWORD *)(result + 4) )
  {
    v2 = 0;
    do
    {
      result = printk(&unk_22057F, "hfi_util_kv_helper_dump");
      ++v2;
    }
    while ( v2 < *(_DWORD *)(v1 + 4) );
  }
  return result;
}
