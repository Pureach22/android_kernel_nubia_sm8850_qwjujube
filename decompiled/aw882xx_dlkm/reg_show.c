__int64 __fastcall reg_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x24
  int v4; // w25
  int v6; // w22
  int v7; // w21
  __int64 v8; // x20
  int v10; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+8h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 152);
  v10 = 0;
  v4 = *(_DWORD *)(*(_QWORD *)(v3 + 96) + 28LL);
  if ( v4 < 1 )
  {
    v8 = 0;
  }
  else
  {
    v6 = 0;
    v7 = 0;
    v8 = 0;
    do
    {
      aw882xx_i2c_read(*(_QWORD *)(v3 + 56), v7++, &v10);
      v8 += snprintf((char *)(a3 + v8), 4096 - v8, "reg:0x%02x=0x%04x\n", v6, v10);
      v6 = (unsigned __int8)v7;
    }
    while ( v4 > (unsigned int)(unsigned __int8)v7 );
  }
  _ReadStatusReg(SP_EL0);
  return v8;
}
