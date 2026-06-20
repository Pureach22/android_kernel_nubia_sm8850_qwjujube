__int64 __fastcall tp_BBAT_test_read(__int64 a1, __int64 a2, __int64 a3, __int64 *a4)
{
  __int64 result; // x0
  __int64 v5; // x8
  __int64 (*v9)(void); // x8
  int v10; // w0
  __int64 v11; // x1
  __int64 v12; // x2
  int v13; // w3
  int v14; // w0
  int v15; // w22
  char s[32]; // [xsp+8h] [xbp-18h] BYREF
  __int16 v17; // [xsp+10h] [xbp-10h]
  __int64 v18; // [xsp+18h] [xbp-8h]

  result = 0;
  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *a4;
  v17 = 0;
  *(_QWORD *)s = 0;
  if ( !v5 )
  {
    v9 = *(__int64 (**)(void))(tpd_cdev + 3632);
    if ( v9 )
    {
      /* CFI check removed */
      v10 = v9();
      if ( v10 )
      {
        v15 = v10;
        printk(unk_3CAA2, v11, v12);
        v13 = v15;
      }
      else
      {
        v13 = 0;
      }
    }
    else
    {
      v13 = 2 * (*(_BYTE *)(tpd_cdev + 20) == 0);
    }
    v14 = snprintf(s, 0xAu, "%d\n", v13);
    result = simple_read_from_buffer(a2, a3, a4, s, v14);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
