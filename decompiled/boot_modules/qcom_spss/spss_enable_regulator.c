__int64 __fastcall spss_enable_regulator(_QWORD *a1, _QWORD *a2)
{
  int v4; // w0
  int v5; // w0
  __int64 result; // x0
  int v7; // w2
  unsigned int v8; // w19
  int v9; // w3
  __int64 v10; // x0
  unsigned int v11; // w20
  int v12; // w2
  __int64 v13; // x0

  if ( !*a2 )
    return 0;
  v4 = regulator_set_voltage(*a2, *((unsigned int *)a2 + 2), 0x7FFFFFFF);
  if ( v4 )
  {
    v7 = *((_DWORD *)a2 + 2);
    v8 = v4;
    dev_err(*a1, "Set voltage %d failed [%d]\n", v7, v4);
    return v8;
  }
  v5 = regulator_set_load(*a2, *((unsigned int *)a2 + 3));
  if ( v5 )
  {
    v9 = v5;
    v10 = *a1;
    v11 = v9;
    dev_err(v10, "Set load %d failed [%d]\n", *((_DWORD *)a2 + 3), v9);
LABEL_10:
    regulator_set_voltage(*a2, 0, 0x7FFFFFFF);
    return v11;
  }
  result = regulator_enable(*a2);
  if ( (_DWORD)result )
  {
    v12 = result;
    v13 = *a1;
    v11 = v12;
    dev_err(v13, "Enable regulator failed [%d]\n", v12);
    regulator_set_load(*a2, 0);
    goto LABEL_10;
  }
  return result;
}
