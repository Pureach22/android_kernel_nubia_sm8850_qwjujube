__int64 __fastcall qcrypto_aes_skcipher_exit(__int64 a1, __int64 a2)
{
  __int64 result; // x0

  if ( *(_QWORD *)(a1 + 40) != a1 + 40 )
  {
    printk(&unk_12785, a2);
    result = *(_QWORD *)(a1 + 240);
    if ( !result )
      goto LABEL_4;
    goto LABEL_3;
  }
  result = *(_QWORD *)(a1 + 240);
  if ( result )
LABEL_3:
    result = crypto_destroy_tfm(result, result + 8);
LABEL_4:
  *(_QWORD *)(a1 + 240) = 0;
  return result;
}
