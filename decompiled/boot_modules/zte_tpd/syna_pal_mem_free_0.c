__int64 __fastcall syna_pal_mem_free_0(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x2

  v2 = syna_request_managed_device();
  if ( v2 )
    return devm_kfree(v2, a1);
  else
    return printk(&unk_3BE43, "syna_pal_mem_free", v3);
}
