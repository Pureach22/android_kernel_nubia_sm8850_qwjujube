__int64 __fastcall hvx_rm_driver_probe(__int64 a1)
{
  __int64 v2; // x0
  unsigned __int64 v3; // x0
  unsigned __int64 v5; // x20
  int v6; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v7; // [xsp+8h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 760);
  v6 = 0;
  of_property_read_variable_u32_array(v2, "#cooling-cells", &v6, 1, 0);
  if ( v6 )
  {
    v3 = thermal_of_cooling_device_register(*(_QWORD *)(a1 + 760), "hvx", 0, hvx_cooling_ops);
    if ( v3 >= 0xFFFFFFFFFFFFF001LL )
    {
      v5 = v3;
      dev_err(a1 + 16, "HVX thermal driver reg failed\n");
      v3 = v5;
    }
    qword_A480 = v3;
  }
  _ReadStatusReg(SP_EL0);
  return 0;
}
