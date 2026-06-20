__int64 __fastcall qcrypto_cra_aead_exit(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  __int64 v3; // t1

  v3 = *(_QWORD *)(a1 + 40);
  result = a1 + 40;
  if ( v3 != result )
    return printk(&unk_122F8, a2);
  return result;
}
