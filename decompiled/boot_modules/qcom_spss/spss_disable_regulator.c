__int64 __fastcall spss_disable_regulator(_QWORD *a1, _QWORD *a2)
{
  int v4; // w0
  int v5; // w0
  int v6; // w8
  __int64 result; // x0
  unsigned int v8; // w19
  int v9; // w3
  __int64 v10; // x0
  unsigned int v11; // w20
  __int64 v12; // x0

  if ( !*a2 )
    return 0;
  v4 = regulator_disable(*a2);
  if ( v4 )
  {
    v8 = v4;
    dev_err(*a1, "Disable regulator failed [%d]\n", v4);
    return v8;
  }
  v5 = regulator_set_voltage(*a2, 0, 0x7FFFFFFF);
  if ( v5 )
  {
    v9 = v5;
    v10 = *a1;
    v11 = v9;
    dev_err(v10, "Set voltage %d failed [%d]\n", 0, v9);
LABEL_10:
    regulator_enable(*a2);
    return v11;
  }
  v6 = regulator_set_load(*a2, 0);
  result = 0;
  if ( v6 )
  {
    v12 = *a1;
    v11 = v6;
    dev_err(v12, "Set load %d failed [%d]\n", 0, v6);
    regulator_set_voltage(*a2, *((unsigned int *)a2 + 2), 0x7FFFFFFF);
    goto LABEL_10;
  }
  return result;
}
