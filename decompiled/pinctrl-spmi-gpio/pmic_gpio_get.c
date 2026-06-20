__int64 __fastcall pmic_gpio_get(__int64 a1, unsigned int a2)
{
  __int64 data; // x0
  _BYTE *v4; // x19
  _QWORD *v5; // x20
  unsigned int v6; // w0
  __int64 result; // x0
  unsigned int v8; // w19
  unsigned int v9; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  data = gpiochip_get_data();
  v4 = *(_BYTE **)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(data + 16) + 16LL) + 8LL) + 24LL * a2 + 16);
  if ( v4[2] == 1 )
  {
    if ( (v4[7] & 1) != 0 )
    {
      v9 = 0;
      v5 = (_QWORD *)data;
      v6 = regmap_read(*(_QWORD *)(data + 8), (unsigned int)*(unsigned __int16 *)v4 + 16, &v9);
      if ( (v6 & 0x80000000) != 0 )
      {
        v8 = v6;
        dev_err(*v5, "read 0x%x failed\n", 16);
        result = v8;
      }
      else
      {
        result = v9;
        if ( (v9 & 0x80000000) == 0 )
        {
          result = v9 & 1;
          v4[4] = v9 & 1;
        }
      }
    }
    else
    {
      result = (unsigned __int8)v4[4];
    }
  }
  else
  {
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
