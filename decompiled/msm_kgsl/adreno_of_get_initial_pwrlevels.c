__int64 __fastcall adreno_of_get_initial_pwrlevels(_DWORD *a1, __int64 a2)
{
  int v4; // w8
  __int64 result; // x0
  unsigned int v6; // w8
  unsigned int v7; // w9
  unsigned int v8; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = 0;
  if ( (of_property_read_variable_u32_array(a2, "qcom,initial-pwrlevel", &v8, 1, 0) & 0x80000000) != 0
    || (v4 = v8, (v8 & 0x80000000) != 0)
    || v8 >= a1[309] )
  {
    v4 = 1;
    __break(0x800u);
    v8 = 1;
  }
  a1[302] = v4;
  a1[305] = v4;
  a1[306] = 0;
  result = of_property_read_variable_u32_array(a2, "qcom,initial-min-pwrlevel", &v8, 1, 0);
  if ( (result & 0x80000000) != 0 )
  {
    v6 = a1[309] - 1;
    v7 = a1[309];
    if ( (v6 & 0x80000000) != 0 )
    {
LABEL_11:
      v6 = v7 - 1;
      goto LABEL_12;
    }
  }
  else
  {
    v6 = v8;
    v7 = a1[309];
    if ( (v8 & 0x80000000) != 0 )
      goto LABEL_11;
  }
  if ( v6 >= v7 || v6 < a1[305] )
    goto LABEL_11;
LABEL_12:
  a1[308] = v6;
  _ReadStatusReg(SP_EL0);
  a1[307] = v6;
  return result;
}
