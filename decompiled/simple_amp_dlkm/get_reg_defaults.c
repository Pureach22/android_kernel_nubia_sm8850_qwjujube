__int64 __fastcall get_reg_defaults(_QWORD *a1, __int64 *a2, _QWORD *a3, __int64 a4)
{
  int *v6; // x22
  __int64 result; // x0
  int v9; // w3
  __int64 v10; // x8

  if ( !a3 )
    return printk(&unk_C254, "get_reg_defaults", 0, a4);
  v6 = (int *)a3 + 151;
  result = regmap_read(*a3, 1079510018, (char *)a3 + 604);
  if ( (_DWORD)result )
    result = dev_err(a3[1], "%s: Regmap read failed for reg %u: %d\n", "get_reg_defaults", 1079510018, result);
  v9 = *v6;
  if ( *v6 == 1 )
  {
    *a1 = &simple_amp_reg_defaults_V2;
    v10 = 68;
    goto LABEL_8;
  }
  if ( !v9 )
  {
    *a1 = &simple_amp_reg_defaults_V1;
    v10 = 64;
LABEL_8:
    *a2 = v10;
    return result;
  }
  return dev_err(a3[1], "%s: unknown chip version: %d\n", "get_reg_defaults", v9);
}
