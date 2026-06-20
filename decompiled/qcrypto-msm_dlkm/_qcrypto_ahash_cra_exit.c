__int64 __fastcall qcrypto_ahash_cra_exit(__int64 a1)
{
  __int64 result; // x0

  if ( *(_QWORD *)(a1 + 32) == a1 + 32 )
  {
    result = *(_QWORD *)(a1 + 144);
    if ( !result )
      return result;
  }
  else
  {
    printk(&unk_11EF2, "_qcrypto_ahash_cra_exit");
    result = *(_QWORD *)(a1 + 144);
    if ( !result )
      return result;
  }
  result = kfree_sensitive(result);
  *(_QWORD *)(a1 + 144) = 0;
  return result;
}
