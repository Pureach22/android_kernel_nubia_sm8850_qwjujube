size_t __fastcall speed_store(__int64 a1, unsigned __int64 a2, unsigned __int64 a3)
{
  __int64 v4; // x20
  size_t v5; // x19
  unsigned int v8; // w4
  unsigned int v9; // [xsp+4h] [xbp-1Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-18h] BYREF
  __int16 v11; // [xsp+10h] [xbp-10h]
  __int64 v12; // [xsp+18h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = mAWP1921;
  v9 = 0;
  if ( a3 >= 9 )
    v5 = 9;
  else
    v5 = a3;
  v11 = 0;
  v10 = 0;
  _check_object_size(&v10, v5, 0);
  if ( (unsigned int)inline_copy_from_user((__int64)&v10, a2, v5) )
    goto LABEL_5;
  printk(&unk_8434, "speed_store", 390);
  if ( (_DWORD)v10 == 1751607656 && WORD2(v10) == 10 )
  {
    v8 = 24;
LABEL_21:
    v9 = v8;
    goto LABEL_22;
  }
  if ( !((unsigned int)v10 ^ 0xA64696D | BYTE4(v10)) )
  {
    v8 = 20;
    goto LABEL_21;
  }
  if ( !((unsigned int)v10 ^ 0xA776F6C | BYTE4(v10)) )
  {
    v8 = 18;
    goto LABEL_21;
  }
  if ( (unsigned int)kstrtouint(&v10, 0, &v9) )
  {
LABEL_5:
    v5 = -22;
    goto LABEL_6;
  }
  if ( 3 * v9 <= 0x117 )
    v8 = 3 * v9 / 0xA;
  else
    v8 = 27;
  v9 = 3 * v9 / 0xA;
LABEL_22:
  *(_DWORD *)(v4 + 2088) = v8;
  printk(&unk_8620, "speed_store", 414);
  if ( *(int *)(v4 + 2084) >= 1 )
    awp1921_i2c_write(v4, 20, (4 * (*(_WORD *)(v4 + 2088) & 0x1F)) | 2u);
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return v5;
}
