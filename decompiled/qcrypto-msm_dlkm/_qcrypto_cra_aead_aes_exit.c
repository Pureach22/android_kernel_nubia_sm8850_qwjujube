__int64 __fastcall qcrypto_cra_aead_aes_exit(_QWORD *a1, __int64 a2)
{
  __int64 v3; // x0
  __int64 result; // x0

  if ( (_QWORD *)a1[5] != a1 + 5 )
    printk(&unk_122F8, a2);
  v3 = a1[30];
  if ( v3 )
    crypto_destroy_tfm(v3, v3 + 8);
  result = a1[31];
  if ( result )
    result = crypto_destroy_tfm(result, result + 16);
  a1[30] = 0;
  a1[31] = 0;
  return result;
}
