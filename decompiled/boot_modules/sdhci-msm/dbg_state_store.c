__int64 __fastcall dbg_state_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v6; // x21
  _BYTE v8[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 152);
  v8[0] = 0;
  if ( (capable(21) & 1) != 0 )
  {
    if ( (unsigned int)kstrtobool(a3, v8) )
      a4 = -22;
    else
      *(_BYTE *)(v6 + 2168) = v8[0];
  }
  else
  {
    a4 = -13;
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
