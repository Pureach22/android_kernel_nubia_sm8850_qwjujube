__int64 __fastcall qcom_hwspinlock_unlock(__int64 a1)
{
  __int64 v1; // x19
  __int64 result; // x0
  void *v3; // x0
  int v4; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v5; // [xsp+8h] [xbp-8h]

  v5 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD *)(a1 + 16);
  v4 = 0;
  if ( (unsigned int)regmap_field_read(v1, &v4) )
  {
    v3 = &unk_717A;
LABEL_8:
    result = printk(v3, "qcom_hwspinlock_unlock");
    goto LABEL_5;
  }
  if ( v4 != 1 )
    printk(&unk_7145, "qcom_hwspinlock_unlock");
  result = regmap_field_update_bits_base(v1, 0xFFFFFFFFLL, 0, 0, 0, 0);
  if ( (_DWORD)result )
  {
    v3 = &unk_71A0;
    goto LABEL_8;
  }
LABEL_5:
  _ReadStatusReg(SP_EL0);
  return result;
}
