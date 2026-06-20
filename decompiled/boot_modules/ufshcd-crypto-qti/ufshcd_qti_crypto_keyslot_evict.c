__int64 __fastcall ufshcd_qti_crypto_keyslot_evict(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7)
{
  __int64 v7; // x19
  __int64 v8; // x21
  unsigned int v9; // w20
  unsigned int v10; // w21

  v7 = a1 - 4544;
  if ( a1 == 4544 )
  {
    __break(0x800u);
    return ((__int64 (__fastcall *)(__int64, __int64, __int64, __int64, __int64, __int64, __int64))ufshcd_qti_crypto_derive_sw_secret)(
             4544,
             a2,
             a3,
             a4,
             a5,
             a6,
             a7);
  }
  else
  {
    v8 = *(_QWORD *)(a1 - 4360);
    if ( *(_BYTE *)(v8 + 176) == 1 )
    {
      printk(&unk_6822, *(unsigned int *)(a1 - 4048), a3);
      return (unsigned int)-22;
    }
    else
    {
      v9 = a3;
      ufshcd_hold(a1 - 4544);
      v10 = qcom_ice_evict_key(*(_QWORD *)(v8 + 152), v9);
      if ( v10 )
        printk(&unk_67F3, "ufshcd_qti_crypto_keyslot_evict", v10);
      ufshcd_release(v7);
    }
    return v10;
  }
}
