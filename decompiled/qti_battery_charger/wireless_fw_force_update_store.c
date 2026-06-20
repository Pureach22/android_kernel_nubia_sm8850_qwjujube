__int64 __fastcall wireless_fw_force_update_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v6; // x2
  __int64 result; // x0
  _BYTE v8[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8[0] = 0;
  if ( (unsigned int)kstrtobool(a3, v8) || v8[0] != 1 )
  {
    result = -22;
  }
  else
  {
    LODWORD(result) = wireless_fw_update((_QWORD *)(a1 - 8), 1, v6);
    if ( (int)result >= 0 )
      result = a4;
    else
      result = (int)result;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
