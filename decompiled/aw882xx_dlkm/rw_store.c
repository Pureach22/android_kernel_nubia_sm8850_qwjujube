__int64 __fastcall rw_store(__int64 a1, int a2, char *s, __int64 a4)
{
  __int64 v6; // x21
  char v7; // w1
  unsigned int v8; // w2
  __int64 v9; // x0
  _QWORD v11[2]; // [xsp+0h] [xbp-10h] BYREF

  v11[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 152);
  v11[0] = 0;
  if ( sscanf(s, "%x %x", v11, (char *)v11 + 4) == 2 )
  {
    v7 = v11[0];
    v8 = HIDWORD(v11[0]);
    v9 = *(_QWORD *)(v6 + 56);
    *(_BYTE *)(v6 + 38) = v11[0];
    aw882xx_i2c_write(v9, v7, v8);
  }
  else if ( !(unsigned int)kstrtouint(s, 16, v11) )
  {
    *(_BYTE *)(v6 + 38) = v11[0];
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
