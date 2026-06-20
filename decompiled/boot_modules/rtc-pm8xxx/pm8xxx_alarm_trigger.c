bool __fastcall pm8xxx_alarm_trigger(__int64 a1, _QWORD *a2)
{
  unsigned int *v3; // x20
  int updated; // w8
  _BOOL8 result; // x0

  v3 = (unsigned int *)a2[3];
  rtc_update_irq(*a2, 1, 160);
  updated = regmap_update_bits_base(a2[1], v3[3], v3[6], 0, 0, 0, 0);
  result = 0;
  if ( !updated )
    return (unsigned int)regmap_update_bits_base(a2[1], v3[4], 1, 0, 0, 0, 0) == 0;
  return result;
}
