__int64 __fastcall bcl_config_vph_cb(__int64 a1, __int64 a2, unsigned int *a3)
{
  __int64 v3; // x2
  __int64 result; // x0
  unsigned int v5; // w19
  int v6; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v7; // [xsp+8h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *a3;
  v6 = 0;
  result = bcl_set_adc_value(a1 - 1896, a2, v3, &v6);
  if ( (result & 0x80000000) != 0 )
  {
    v5 = result;
    printk(&unk_86F8, "bcl_pmic5", "bcl_config_vph_cb");
    result = v5;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
