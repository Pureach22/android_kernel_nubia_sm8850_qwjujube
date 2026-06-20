__int64 __fastcall tp_test_read(__int64 a1, __int64 a2, __int64 a3, __int64 *a4)
{
  __int64 result; // x0
  __int64 v5; // x8
  __int64 v8; // x22
  __int64 v10; // x1
  __int64 v11; // x1
  __int64 v12; // x2
  int v13; // w3
  int v14; // w0
  char s[32]; // [xsp+8h] [xbp-18h] BYREF
  __int16 v16; // [xsp+10h] [xbp-10h]
  __int64 v17; // [xsp+18h] [xbp-8h]

  result = 0;
  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *a4;
  v16 = 0;
  *(_QWORD *)s = 0;
  if ( !v5 )
  {
    v8 = tpd_cdev;
    v10 = *(unsigned __int8 *)(tpd_cdev + 2632);
    if ( (_DWORD)v10 == 255 )
    {
      printk(unk_3CABE, *(unsigned __int8 *)(tpd_cdev + 1094), a3);
      if ( (*(_BYTE *)(v8 + 29) & 1) != 0 )
      {
        printk(unk_37549, v11, v12);
        v13 = 0;
      }
      else
      {
        printk(unk_39294, v11, v12);
        v13 = 2;
      }
    }
    else
    {
      printk(unk_3408C, v10, a3);
      v13 = 1;
    }
    v14 = snprintf(s, 0xAu, "%d\n", v13);
    result = simple_read_from_buffer(a2, a3, a4, s, v14);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
