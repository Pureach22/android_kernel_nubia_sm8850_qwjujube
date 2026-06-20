__int64 __fastcall tsens_enable_irq(_QWORD *a1)
{
  _DWORD *v1; // x9
  __int64 v3; // x0
  __int64 v4; // x2
  __int64 result; // x0

  v1 = (_DWORD *)a1[318];
  v3 = a1[14];
  if ( *v1 <= 2u )
    v4 = 1;
  else
    v4 = 7;
  result = regmap_field_update_bits_base(v3, 0xFFFFFFFFLL, v4, 0, 0, 0);
  if ( (result & 0x80000000) != 0 )
    return dev_err(*a1, "%s: failed to enable interrupts\n", "tsens_enable_irq");
  return result;
}
