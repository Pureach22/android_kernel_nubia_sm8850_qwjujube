__int64 __fastcall adc5_gen3_read_raw(__int64 a1, __int64 a2, _DWORD *a3, __int64 a4, __int64 a5)
{
  _QWORD *v6; // x0
  __int64 v7; // x8
  __int64 v8; // x20
  __int64 result; // x0
  _WORD v10[2]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+8h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD **)(a1 + 1040);
  v7 = *(_QWORD *)(a2 + 16);
  v10[0] = 0;
  v8 = v6[6] + 200 * v7;
  if ( a5 )
  {
    if ( a5 == 1 )
    {
      result = adc5_gen3_do_conversion(v6, (int *)(v6[6] + 200 * v7), v10);
      if ( (result & 0x80000000) == 0 )
      {
        LODWORD(result) = qcom_adc5_hw_scale(
                            *(unsigned int *)(v8 + 40),
                            *(unsigned int *)(v8 + 16),
                            *(_QWORD *)(v8 + 64),
                            v10[0],
                            a3);
        if ( (int)result >= 0 )
          result = 1;
        else
          result = (unsigned int)result;
      }
    }
    else
    {
      result = 4294967274LL;
    }
  }
  else
  {
    result = adc5_gen3_do_conversion(v6, (int *)(v6[6] + 200 * v7), v10);
    if ( (result & 0x80000000) == 0 )
    {
      result = 1;
      *a3 = v10[0];
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
