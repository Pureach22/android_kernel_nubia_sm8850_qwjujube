__int64 __fastcall eusb2_repeater_power(_QWORD *a1, char a2)
{
  __int64 result; // x0
  int v4; // w0
  unsigned int v5; // w0
  unsigned int v6; // w0
  int v7; // w0
  unsigned int v8; // w0
  char v9; // w8
  unsigned int v10; // w0
  unsigned int v11; // w0
  unsigned int v12; // w0
  unsigned int v13; // w0
  unsigned int v14; // w20

  if ( *((_BYTE *)a1 + 120) == (a2 & 1) )
    return 0;
  if ( (a2 & 1) == 0 )
  {
    v10 = regulator_disable(a1[14]);
    if ( v10 )
      dev_err(*a1, "Unable to disable vdd3:%d\n", v10);
    goto LABEL_13;
  }
  v4 = regulator_set_load(a1[13], "reg");
  if ( v4 < 0 )
  {
    v14 = v4;
    dev_err(*a1, "Unable to set HPM of vdd18:%d\n", v4);
    goto LABEL_23;
  }
  v5 = regulator_set_voltage(a1[13], 1800000, 1800000);
  if ( !v5 )
  {
    v6 = regulator_enable(a1[13]);
    if ( v6 )
    {
      dev_err(*a1, "Unable to enable vdd18:%d\n", v6);
LABEL_19:
      v13 = regulator_set_voltage(a1[13], 0, 1800000);
      if ( v13 )
        dev_err(*a1, "Unable to set (0) voltage for vdd18:%d\n", v13);
      goto LABEL_21;
    }
    v7 = regulator_set_load(a1[14], 3500);
    if ( v7 < 0 )
    {
      dev_err(*a1, "Unable to set HPM of vdd3:%d\n", v7);
LABEL_17:
      v12 = regulator_disable(a1[13]);
      if ( v12 )
        dev_err(*a1, "Unable to disable vdd18:%d\n", v12);
      goto LABEL_19;
    }
    v8 = regulator_set_voltage(a1[14], 3075000, 3300000);
    if ( v8 )
    {
      dev_err(*a1, "Unable to set voltage for vdd3:%d\n", v8);
LABEL_15:
      if ( (regulator_set_load(a1[14], 0) & 0x80000000) != 0 )
        dev_err(*a1, "Unable to set (0) HPM of vdd3\n");
      goto LABEL_17;
    }
    result = regulator_enable(a1[14]);
    if ( !(_DWORD)result )
    {
      v9 = 1;
LABEL_25:
      *((_BYTE *)a1 + 120) = v9;
      return result;
    }
    dev_err(*a1, "Unable to enable vdd3:%d\n", (unsigned int)result);
LABEL_13:
    v11 = regulator_set_voltage(a1[14], 0, 3300000);
    if ( v11 )
      dev_err(*a1, "Unable to set (0) voltage for vdd3:%d\n", v11);
    goto LABEL_15;
  }
  dev_err(*a1, "Unable to set voltage for vdd18:%d\n", v5);
LABEL_21:
  v14 = regulator_set_load(a1[13], 0);
  if ( (v14 & 0x80000000) != 0 )
    dev_err(*a1, "Unable to set LPM of vdd18\n");
LABEL_23:
  if ( *((_BYTE *)a1 + 120) == 1 )
  {
    v9 = 0;
    result = v14;
    goto LABEL_25;
  }
  return 4294967274LL;
}
