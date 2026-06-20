__int64 __fastcall eusb2_repeater_reg_write(__int64 *a1, unsigned __int16 a2, char a3)
{
  int v4; // w20
  int v5; // w8
  __int64 v6; // x0
  __int64 result; // x0
  __int64 v8; // x8
  int v9; // w9
  unsigned int v10; // w19
  _BYTE v11[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v12; // [xsp+8h] [xbp-8h]

  v4 = a2;
  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *((unsigned __int16 *)a1 + 48);
  v6 = a1[11];
  v11[0] = a3;
  result = regmap_bulk_write(v6, v5 + (unsigned int)a2, v11, 1);
  if ( (_DWORD)result )
  {
    v8 = *a1;
    v9 = *((unsigned __int16 *)a1 + 48);
    v10 = result;
    dev_err(v8, "bulk write failed: addr=0x%04x, ret=%d\n", v9 + v4, result);
    result = v10;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
