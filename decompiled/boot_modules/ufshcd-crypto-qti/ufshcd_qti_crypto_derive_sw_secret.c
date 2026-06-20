__int64 __fastcall ufshcd_qti_crypto_derive_sw_secret(__int64 a1)
{
  unsigned int *v1; // x19
  __int64 result; // x0
  unsigned int v3; // w19

  if ( a1 == 4544 )
  {
    __break(0x800u);
    atomic_load(v1);
    JUMPOUT(0x66AC);
  }
  result = qcom_ice_derive_sw_secret(*(_QWORD *)(*(_QWORD *)(a1 - 4360) + 152LL));
  if ( (_DWORD)result )
  {
    v3 = result;
    printk(&unk_6A22, "ufshcd_qti_crypto_derive_sw_secret", (unsigned int)result);
    return v3;
  }
  return result;
}
