__int64 __fastcall zte_timezone_setup(__int64 a1)
{
  __int64 result; // x0
  _QWORD v2[2]; // [xsp+0h] [xbp-10h] BYREF

  v2[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2[0] = 0;
  result = kstrtoll(a1, 0, v2);
  if ( !(_DWORD)result )
  {
    result = 1;
    zte_timezone = v2[0];
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
