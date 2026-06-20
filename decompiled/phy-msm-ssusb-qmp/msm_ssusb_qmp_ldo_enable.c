__int64 __fastcall msm_ssusb_qmp_ldo_enable(_QWORD *a1, int a2)
{
  __int64 result; // x0
  int v5; // w0
  __int64 v6; // x1
  unsigned __int64 v7; // x0
  int v8; // w0
  __int64 v9; // x1
  __int64 v10; // x1
  int v11; // w0
  unsigned __int64 v12; // x0
  int v13; // w8
  int v14; // w0
  __int64 v15; // x8
  int v16; // w19
  unsigned int v17; // w20

  if ( *((unsigned __int8 *)a1 + 544) == a2 )
    return 0;
  *((_BYTE *)a1 + 544) = a2 != 0;
  if ( !a2 )
  {
    if ( (unsigned int)regulator_disable(a1[53]) )
      dev_err(*a1, "Unable to disable %s\n", "core_ldo");
    goto LABEL_17;
  }
  v5 = _pm_runtime_resume(*a1, 4);
  if ( v5 < 0 )
  {
    dev_err(*a1, "pm_runtime_get_sync failed with %d\n", v5);
  }
  else
  {
    v7 = a1[56];
    if ( v7 )
    {
      if ( v7 <= 0xFFFFFFFFFFFFF000LL )
      {
        v8 = regulator_enable(v7, v6);
        if ( v8 )
        {
          v17 = v8;
          dev_err(*a1, "err:%d fail to %s usb3_dp_phy_gdsc\n", v8, "enable");
          result = v17;
          if ( (v17 & 0x80000000) != 0 )
            return result;
        }
      }
    }
    if ( (regulator_set_load(a1[50], *((unsigned int *)a1 + 105)) & 0x80000000) == 0 )
    {
      if ( (unsigned int)regulator_set_voltage(a1[50], *((unsigned int *)a1 + 103), *((unsigned int *)a1 + 104)) )
      {
LABEL_33:
        dev_err(*a1, "Unable to set voltage for %s\n", "vdd");
LABEL_23:
        if ( (regulator_set_load(a1[50], 0) & 0x80000000) != 0 )
          dev_err(*a1, "Unable to set LPM of %s\n", "vdd");
        goto LABEL_25;
      }
      if ( (unsigned int)regulator_enable(a1[50], v9) )
      {
        dev_err(*a1, "Unable to enable %s\n", "vdd");
        goto LABEL_22;
      }
      if ( (regulator_set_load(a1[53], *((unsigned int *)a1 + 111)) & 0x80000000) != 0 )
      {
        dev_err(*a1, "Unable to set HPM of %s\n", "core_ldo");
LABEL_20:
        if ( (unsigned int)regulator_disable(a1[50]) )
          dev_err(*a1, "Unable to disable %s\n", "vdd");
LABEL_22:
        if ( !(unsigned int)regulator_set_voltage(
                              a1[50],
                              *((unsigned int *)a1 + (a2 != 0) + 102),
                              *((unsigned int *)a1 + 104)) )
          goto LABEL_23;
        goto LABEL_33;
      }
      if ( (unsigned int)regulator_set_voltage(a1[53], *((unsigned int *)a1 + 109), *((unsigned int *)a1 + 110)) )
      {
LABEL_34:
        dev_err(*a1, "Unable to set voltage for %s\n", "core_ldo");
LABEL_18:
        if ( (regulator_set_load(a1[53], 0) & 0x80000000) != 0 )
          dev_err(*a1, "Unable to set LPM of %s\n", "core_ldo");
        goto LABEL_20;
      }
      result = regulator_enable(a1[53], v10);
      if ( !(_DWORD)result )
        return result;
      dev_err(*a1, "Unable to enable %s\n", "core_ldo");
LABEL_17:
      if ( !(unsigned int)regulator_set_voltage(a1[53], *((unsigned int *)a1 + 108), *((unsigned int *)a1 + 110)) )
        goto LABEL_18;
      goto LABEL_34;
    }
    dev_err(*a1, "Unable to set HPM of %s\n", "vdd");
  }
LABEL_25:
  v11 = _pm_runtime_idle(*a1, 4);
  if ( v11 < 0 )
    dev_err(*a1, "pm_runtime_put_sync failed with %d\n", v11);
  v12 = a1[56];
  v13 = 0;
  if ( v12 && v12 <= 0xFFFFFFFFFFFFF000LL )
  {
    v14 = regulator_disable(v12);
    if ( v14 )
    {
      v15 = *a1;
      v16 = v14;
      dev_err(v15, "err:%d fail to %s usb3_dp_phy_gdsc\n", v14, "disable");
      v13 = v16;
    }
    else
    {
      v13 = 0;
    }
  }
  return v13 & (unsigned int)(v13 >> 31);
}
