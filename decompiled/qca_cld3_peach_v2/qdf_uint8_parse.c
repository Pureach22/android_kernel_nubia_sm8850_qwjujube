__int64 __fastcall qdf_uint8_parse(__int64 a1, _BYTE *a2)
{
  __int64 result; // x0
  _QWORD v4[2]; // [xsp+0h] [xbp-10h] BYREF

  v4[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4[0] = 0;
  result = qdf_uint64_parse(a1, v4);
  if ( !(_DWORD)result )
  {
    if ( v4[0] > 0xFFu )
    {
      result = 46;
    }
    else
    {
      result = 0;
      *a2 = v4[0];
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
