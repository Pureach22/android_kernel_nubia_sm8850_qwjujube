__int64 __fastcall aw22xxx_reg_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v4; // x8
  _QWORD *v5; // x21
  __int64 v6; // x22
  __int64 v7; // x20
  _BYTE v9[4]; // [xsp+0h] [xbp-10h] BYREF
  _BYTE v10[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+8h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 152);
  v10[0] = 0;
  v9[0] = 0;
  v5 = (_QWORD *)(v4 - 16);
  aw22xxx_i2c_read((_QWORD *)(v4 - 16), 255, v9);
  v6 = 0;
  v7 = 0;
  while ( 1 )
  {
    if ( !v9[0] && (aw22xxx_reg_access[v6] & 1) == 0 )
      goto LABEL_2;
    aw22xxx_i2c_read(v5, v6, v10);
    if ( 4096 - v7 <= (unsigned __int64)snprintf((char *)(a3 + v7), 4096 - v7, "reg:0x%02x=0x%02x \n", v6, v10[0]) )
      break;
    v7 += strlen((const char *)(a3 + v7));
LABEL_2:
    if ( ++v6 == 256 )
      goto LABEL_8;
  }
  v7 = -14;
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return v7;
}
