__int64 __fastcall wcd_usbss_page_write(__int64 a1, _WORD *a2)
{
  unsigned int v4; // w22
  int v5; // w8
  unsigned int v6; // w20
  __int64 result; // x0
  unsigned int v8; // w21
  __int64 v9; // x8
  unsigned int v10; // w21
  _BYTE v11[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v12; // [xsp+8h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = (unsigned __int16)*a2;
  v5 = *(unsigned __int8 *)(a1 + 313);
  v6 = v4 >> 8;
  v11[0] = HIBYTE(*a2);
  if ( v5 == 1 )
  {
    if ( v6 == *(unsigned __int8 *)(a1 + 312) )
    {
      result = 0;
    }
    else
    {
      result = wcd_usbss_i2c_write_device(a1, 0, v11, 1);
      if ( (result & 0x80000000) != 0 )
      {
        v9 = *(_QWORD *)(a1 + 8);
        v10 = result;
        dev_err(v9, "page write error, pg_num: 0x%x\n", v6);
        result = v10;
      }
      else
      {
        *(_BYTE *)(a1 + 312) = BYTE1(v4);
      }
    }
  }
  else
  {
    result = wcd_usbss_i2c_write_device(a1, 0, v11, 1);
    if ( (result & 0x80000000) != 0 )
    {
      v8 = result;
      printk(&unk_B9B1);
      result = v8;
    }
    else
    {
      *(_BYTE *)(a1 + 312) = BYTE1(v4);
      *(_BYTE *)(a1 + 313) = 1;
    }
  }
  *a2 = (unsigned __int8)v4;
  _ReadStatusReg(SP_EL0);
  return result;
}
