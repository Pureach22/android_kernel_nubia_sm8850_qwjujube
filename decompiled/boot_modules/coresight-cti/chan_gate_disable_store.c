__int64 __fastcall chan_gate_disable_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 result; // x0
  unsigned int v7; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v8; // [xsp+8h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = 0;
  if ( (unsigned int)kstrtoint(a3, 0, &v7) )
  {
    result = -22;
  }
  else
  {
    LODWORD(result) = cti_channel_gate_op(a1, 1, v7);
    if ( (_DWORD)result )
      result = (int)result;
    else
      result = a4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
