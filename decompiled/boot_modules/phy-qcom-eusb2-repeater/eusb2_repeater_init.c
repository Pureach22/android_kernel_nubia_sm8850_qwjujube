__int64 __fastcall eusb2_repeater_init(__int64 a1)
{
  _QWORD *v1; // x21
  __int64 v2; // x19
  int v3; // w22
  unsigned int *v4; // x23
  __int64 v5; // x20
  unsigned int v6; // w8
  __int64 result; // x0
  __int64 v8; // x0
  __int64 v9; // x20
  int v10; // w10
  unsigned int v11; // w9
  __int64 v12; // x20
  unsigned int v13; // w19
  int v14; // [xsp+8h] [xbp-18h] BYREF
  _BYTE v15[4]; // [xsp+Ch] [xbp-14h] BYREF
  _BYTE v16[4]; // [xsp+10h] [xbp-10h] BYREF
  _BYTE v17[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v18; // [xsp+18h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD **)(a1 + 152);
  v2 = v1[1];
  v3 = *((_DWORD *)v1 + 10);
  v4 = *(unsigned int **)v1[4];
  v5 = *(_QWORD *)(*v1 + 744LL);
  v17[0] = v4[4];
  v16[0] = v4[8];
  v6 = v4[10];
  v14 = 0;
  v15[0] = v6;
  of_property_read_variable_u8_array(v5, "qcom,tune-usb2-amplitude", v15, 1, 0);
  of_property_read_variable_u8_array(v5, "qcom,tune-usb2-disc-thres", v16, 1, 0);
  of_property_read_variable_u8_array(v5, "qcom,tune-usb2-preem", v17, 1, 0);
  result = regulator_bulk_enable(*(unsigned int *)(v1[4] + 24LL), v1[3]);
  if ( !(_DWORD)result )
  {
    regmap_write(v2, (unsigned int)(v3 + 70), 128);
    regmap_write(v2, (unsigned int)(v3 + 91), *v4);
    regmap_write(v2, (unsigned int)(v3 + 90), v4[1]);
    regmap_write(v2, (unsigned int)(v3 + 89), v4[2]);
    regmap_write(v2, (unsigned int)(v3 + 88), v4[3]);
    regmap_write(v2, (unsigned int)(v3 + 86), v4[5]);
    regmap_write(v2, (unsigned int)(v3 + 85), v4[6]);
    regmap_write(v2, (unsigned int)(v3 + 84), v4[7]);
    regmap_write(v2, (unsigned int)(v3 + 82), v4[9]);
    regmap_write(v2, (unsigned int)(v3 + 80), v4[11]);
    regmap_write(v2, (unsigned int)(v3 + 87), v17[0]);
    regmap_write(v2, (unsigned int)(v3 + 83), v16[0]);
    v8 = regmap_write(v2, (unsigned int)(v3 + 81), v15[0]);
    v9 = ktime_get(v8);
    result = regmap_read(v2, (unsigned int)(v3 + 8), &v14);
    if ( !(_DWORD)result )
    {
      v12 = v9 + 5000;
      while ( 1 )
      {
        if ( (v14 & 0x80) != 0 )
        {
          LODWORD(result) = 0;
          goto LABEL_3;
        }
        if ( ktime_get(result) > v12 )
          break;
        usleep_range_state(3, 10, 2);
        __yield();
        result = regmap_read(v2, (unsigned int)(v3 + 8), &v14);
        if ( (_DWORD)result )
          goto LABEL_3;
      }
      LODWORD(result) = regmap_read(v2, (unsigned int)(v3 + 8), &v14);
    }
LABEL_3:
    v10 = result;
    if ( (unsigned int)result | v14 & 0x80 )
      v11 = 0;
    else
      v11 = -110;
    if ( (_DWORD)result )
      result = (unsigned int)result;
    else
      result = v11;
    if ( v10 || (v14 & 0x80) == 0 )
    {
      v13 = result;
      dev_err(*v1, "initialization timed-out\n");
      result = v13;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
