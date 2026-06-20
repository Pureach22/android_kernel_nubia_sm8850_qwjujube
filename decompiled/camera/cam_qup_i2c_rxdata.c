__int64 __fastcall cam_qup_i2c_rxdata(__int64 a1, __int64 a2, __int16 a3, __int16 a4)
{
  unsigned int v4; // w8
  __int64 v5; // x0
  unsigned int v6; // w19
  int v7; // w0
  __int64 result; // x0
  unsigned int v9; // w20
  _WORD v10[4]; // [xsp+8h] [xbp-28h] BYREF
  __int64 v11; // [xsp+10h] [xbp-20h]
  __int16 v12; // [xsp+18h] [xbp-18h]
  __int16 v13; // [xsp+1Ah] [xbp-16h]
  __int16 v14; // [xsp+1Ch] [xbp-14h]
  __int16 v15; // [xsp+1Eh] [xbp-12h]
  __int64 v16; // [xsp+20h] [xbp-10h]
  __int64 v17; // [xsp+28h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(unsigned __int16 *)(a1 + 2);
  v5 = *(_QWORD *)(a1 + 24);
  v10[2] = a3;
  v11 = a2;
  v6 = v4 >> 1;
  v16 = a2;
  v10[1] = 0;
  v10[3] = 0;
  v13 = 1;
  v14 = a4;
  v10[0] = v4 >> 1;
  v12 = v10[0];
  v15 = 0;
  v7 = i2c_transfer(v5, v10, 2);
  if ( v7 < 0 )
  {
    v9 = v7;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x4000000000LL,
      1,
      "cam_qup_i2c_rxdata",
      43,
      "failed 0x%x",
      v6);
    result = v9;
  }
  else if ( v7 == 2 )
  {
    result = 0;
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x4000000000LL,
      1,
      "cam_qup_i2c_rxdata",
      51,
      "i2c transfer failed, i2c_msg_size:%d rc:%d",
      2,
      v7);
    result = 4294967291LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
