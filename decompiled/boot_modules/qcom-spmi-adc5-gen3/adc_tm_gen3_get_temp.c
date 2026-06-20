__int64 __fastcall adc_tm_gen3_get_temp(__int64 a1, _DWORD *a2)
{
  __int64 v3; // x0
  __int64 v4; // x20
  int v5; // w8
  __int64 result; // x0
  unsigned __int16 v7; // [xsp+4h] [xbp-Ch]
  __int64 v8; // [xsp+8h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = thermal_zone_device_priv();
  if ( v3 && (v4 = v3, *(_QWORD *)(v3 + 56)) )
  {
    if ( *(_BYTE *)(v3 + 132) == 1 )
    {
      v5 = *(_DWORD *)(v3 + 128);
      result = 0;
      *(_BYTE *)(v4 + 132) = 0;
      *a2 = v5;
    }
    else
    {
      v7 = 0;
      result = adc5_gen3_do_conversion();
      if ( (result & 0x80000000) == 0 )
        result = qcom_adc5_hw_scale(
                   *(unsigned int *)(v4 + 40),
                   *(unsigned int *)(v4 + 16),
                   *(_QWORD *)(v4 + 64),
                   v7,
                   a2);
    }
  }
  else
  {
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
