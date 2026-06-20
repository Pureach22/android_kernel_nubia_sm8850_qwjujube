__int64 __fastcall syna_pal_mem_free(__int64 a1)
{
  __int64 result; // x0
  __int64 v3; // x2

  result = syna_request_managed_device();
  if ( !result )
    return printk(&unk_3BE43, "syna_pal_mem_free", v3);
  if ( a1 )
    return devm_kfree(result, a1);
  return result;
}
