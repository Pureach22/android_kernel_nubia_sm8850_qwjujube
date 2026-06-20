__int64 __fastcall qdf_int32_parse(__int64 a1, _DWORD *a2)
{
  __int64 result; // x0
  _QWORD v4[2]; // [xsp+0h] [xbp-10h] BYREF

  v4[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4[0] = 0;
  result = qdf_int64_parse(a1, v4);
  if ( !(_DWORD)result )
  {
    if ( v4[0] == SLODWORD(v4[0]) )
    {
      result = 0;
      *a2 = v4[0];
    }
    else
    {
      result = 46;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
