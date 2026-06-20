__int64 __fastcall init_iovad_attr(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v4; // x20
  __int64 result; // x0
  __int64 v6; // x8
  unsigned int v7; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v8; // [xsp+8h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a2 + 744);
  v7 = 0;
  if ( of_find_property(v4, "qcom,iova-best-fit", 0) )
    *(_QWORD *)(a3 + 128) |= 0x10000uLL;
  result = of_property_read_variable_u32_array(v4, "qcom,iova-max-align-shift", &v7, 1, 0);
  if ( (result & 0x80000000) == 0 )
  {
    v6 = v7;
    if ( v7 >= 0x100 )
    {
      v6 = 9;
      __break(0x800u);
    }
    *(_QWORD *)(a3 + 128) |= v6;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
