__int64 __fastcall wireless_fw_crc_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  int v6; // w8
  __int64 result; // x0
  __int16 v8; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = 0;
  v6 = kstrtou16(a3, 0, &v8);
  result = -22;
  if ( !v6 && v8 )
  {
    result = a4;
    *(_WORD *)(a1 + 1076) = v8;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
