__int64 __fastcall qcom_hwspinlock_bust(__int64 a1, int a2)
{
  __int64 v4; // x20
  unsigned int v5; // w0
  unsigned int updated; // w8
  __int64 result; // x0
  const char *v8; // x1
  unsigned int v9; // w20
  int v10; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+8h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 16);
  v10 = 0;
  v5 = regmap_field_read(v4, &v10);
  if ( v5 )
  {
    v9 = v5;
    v8 = "unable to query spinlock owner\n";
    goto LABEL_8;
  }
  if ( v10 == a2 )
  {
    updated = regmap_field_update_bits_base(v4, 0xFFFFFFFFLL, 0, 0, 0, 0);
    result = 0;
    if ( updated )
    {
      v8 = "failed to bust spinlock\n";
      v9 = updated;
LABEL_8:
      dev_err(**(_QWORD **)a1, v8);
      result = v9;
    }
  }
  else
  {
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
