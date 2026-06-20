__int64 __fastcall msm_m31_eusb2_phy_power(_QWORD *a1, char a2)
{
  __int64 result; // x0
  int v4; // w0
  int v5; // w0
  int v6; // w0
  unsigned int v7; // w0
  unsigned int v8; // w0
  int v9; // w0
  unsigned int v10; // w0
  unsigned int v11; // w0
  int v12; // w0
  int v13; // w0
  unsigned int v14; // w20
  unsigned int v15; // w20

  if ( *((_BYTE *)a1 + 469) == (a2 & 1) )
    return 0;
  if ( (a2 & 1) == 0 )
  {
    v9 = readl_relaxed(a1[49]);
    writel_relaxed(v9 & 0xFFFFFFFE, a1[49]);
    __dsb(0xFu);
    v10 = regulator_disable(a1[55]);
    if ( v10 )
      dev_err(*a1, "Unable to disable vdda12:%d\n", v10);
    goto LABEL_16;
  }
  v4 = regulator_set_load(a1[56], 7757);
  if ( v4 < 0 )
  {
    v14 = v4;
    dev_err(*a1, "Unable to set HPM of vdd_refgen:%d\n", v4);
    result = v14;
LABEL_34:
    *((_BYTE *)a1 + 469) = 0;
    return result;
  }
  if ( (unsigned int)regulator_set_voltage(a1[56], *((unsigned int *)a1 + 115), *((unsigned int *)a1 + 116)) )
  {
    dev_err(*a1, "Unable to set voltage for hsusb vdd_refgen\n");
    goto LABEL_31;
  }
  if ( !(unsigned int)regulator_enable(a1[56]) )
  {
    v5 = regulator_set_load(a1[54], 7757);
    if ( v5 < 0 )
    {
      dev_err(*a1, "Unable to set HPM of vdd:%d\n", v5);
LABEL_27:
      v13 = regulator_disable(a1[56]);
      if ( v13 )
        dev_err(*a1, "Unable to disable vdd_refgen:%d\n", v13);
      goto LABEL_29;
    }
    if ( (unsigned int)regulator_set_voltage(a1[54], *((unsigned int *)a1 + 115), *((unsigned int *)a1 + 116)) )
    {
      dev_err(*a1, "Unable to set voltage for hsusb vdd\n");
      goto LABEL_24;
    }
    if ( (unsigned int)regulator_enable(a1[54]) )
    {
      dev_err(*a1, "Unable to enable VDD\n");
LABEL_22:
      if ( (unsigned int)regulator_set_voltage(a1[54], *((unsigned int *)a1 + 114), *((unsigned int *)a1 + 116)) )
        dev_err(*a1, "unable to set voltage for hsusb vdd\n");
LABEL_24:
      if ( (regulator_set_load(a1[54], 0) & 0x80000000) != 0 )
        dev_err(*a1, "Unable to set LPM of vdd\n");
      if ( *((_BYTE *)a1 + 469) != 1 )
        return 4294967274LL;
      goto LABEL_27;
    }
    v6 = regulator_set_load(a1[55], 5905);
    if ( v6 < 0 )
    {
      dev_err(*a1, "Unable to set HPM of vdda12:%d\n", v6);
LABEL_20:
      v12 = regulator_disable(a1[54]);
      if ( v12 )
        dev_err(*a1, "Unable to disable vdd:%d\n", v12);
      goto LABEL_22;
    }
    v7 = regulator_set_voltage(a1[55], 1200000, 1200000);
    if ( v7 )
    {
      dev_err(*a1, "Unable to set voltage for vdda12:%d\n", v7);
LABEL_18:
      if ( (regulator_set_load(a1[55], 0) & 0x80000000) != 0 )
        dev_err(*a1, "Unable to set LPM of vdda12\n");
      goto LABEL_20;
    }
    v8 = regulator_enable(a1[55]);
    if ( !v8 )
    {
      __dsb(0xFu);
      writel_relaxed(1, a1[49]);
      *((_BYTE *)a1 + 469) = 1;
      return 0;
    }
    dev_err(*a1, "Unable to enable vdda12:%d\n", v8);
LABEL_16:
    v11 = regulator_set_voltage(a1[55], 0, 1200000);
    if ( v11 )
      dev_err(*a1, "Unable to set (0) voltage for vdda12:%d\n", v11);
    goto LABEL_18;
  }
  dev_err(*a1, "Unable to enable VDD refgen\n");
LABEL_29:
  if ( (unsigned int)regulator_set_voltage(a1[56], *((unsigned int *)a1 + 114), *((unsigned int *)a1 + 116)) )
    dev_err(*a1, "unable to set voltage for hsusb vdd_refgen\n");
LABEL_31:
  result = regulator_set_load(a1[56], 0);
  if ( (result & 0x80000000) != 0 )
  {
    v15 = result;
    dev_err(*a1, "Unable to set LPM of vdd_refgen\n");
    result = v15;
  }
  if ( *((_BYTE *)a1 + 469) == 1 )
    goto LABEL_34;
  return 4294967274LL;
}
