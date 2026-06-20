__int64 __fastcall pm8xxx_rtc_alarm_irq_enable(__int64 a1, int a2)
{
  __int64 v3; // x20
  unsigned int *v4; // x21
  __int64 v5; // x2
  __int64 v6; // x3
  __int64 result; // x0
  int v8; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 152);
  v8 = 0;
  v4 = *(unsigned int **)(v3 + 24);
  v5 = v4[6];
  if ( a2 )
    v6 = (unsigned int)v5;
  else
    v6 = 0;
  result = regmap_update_bits_base(*(_QWORD *)(v3 + 8), v4[3], v5, v6, 0, 0, 0);
  if ( !(_DWORD)result )
  {
    if ( a2 || (result = regmap_bulk_write(*(_QWORD *)(v3 + 8), v4[5], &v8, 4), !(_DWORD)result) )
      result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
