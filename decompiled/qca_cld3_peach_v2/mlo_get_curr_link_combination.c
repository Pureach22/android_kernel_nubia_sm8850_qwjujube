__int64 __fastcall mlo_get_curr_link_combination(__int64 a1)
{
  _QWORD *v1; // x8
  __int64 result; // x0
  int v3; // w8

  _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD **)(*(_QWORD *)(a1 + 1360) + 3880LL);
  if ( (unsigned int)v1[9] | (unsigned __int16)WORD2(v1[9]) )
  {
    if ( (unsigned __int8)v1[11] )
      result = 2;
    else
      result = 0;
    if ( (unsigned int)v1[15] | (unsigned __int16)WORD2(v1[15]) )
    {
      if ( (unsigned __int8)v1[17] )
        v3 = 4;
      else
        v3 = 0;
      result = v3 | (unsigned int)result;
    }
  }
  else
  {
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
