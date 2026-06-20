__int64 __fastcall wireless_fw_update_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 result; // x0
  _BYTE v7[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v8; // [xsp+8h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7[0] = 0;
  if ( (unsigned int)kstrtobool(a3, v7) || v7[0] != 1 )
  {
    result = -22;
  }
  else
  {
    LODWORD(result) = wireless_fw_update(a1 - 8, 0);
    if ( (int)result >= 0 )
      result = a4;
    else
      result = (int)result;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
