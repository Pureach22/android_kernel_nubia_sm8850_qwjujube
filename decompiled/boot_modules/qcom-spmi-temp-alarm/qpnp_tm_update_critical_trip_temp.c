__int64 __fastcall qpnp_tm_update_critical_trip_temp(__int64 a1, int a2)
{
  __int64 v2; // x8
  __int64 v5; // x22
  __int64 v6; // x20
  unsigned __int8 v7; // w9
  __int64 v9; // x8
  int v10; // w8
  int v11; // w9
  char v12; // w9

  v2 = *(_QWORD *)(a1 + 128);
  v5 = *(_QWORD *)(v2 + 8);
  v6 = *(_QWORD *)(v2 + 80);
  if ( (mutex_is_locked(a1 + 64) & 1) == 0 )
    __break(0x800u);
  if ( a2 == -274000 || v5 > a2 )
  {
    *(_DWORD *)(a1 + 40) = 0;
    v7 = 8;
    return regmap_write(*(_QWORD *)a1, (unsigned int)(*(_DWORD *)(a1 + 48) + 64), v7);
  }
  if ( v6 >= a2 )
  {
    *(_DWORD *)(a1 + 40) = ((int)v6 - a2) / -5000 + 3;
LABEL_11:
    v10 = 1;
    goto LABEL_12;
  }
  v9 = *(_QWORD *)(a1 + 120);
  *(_DWORD *)(a1 + 40) = 3;
  if ( v9 )
    goto LABEL_11;
  dev_warn(
    *(_QWORD *)(a1 + 8),
    "No ADC is configured and critical temperature %d mC is above the maximum stage 2 threshold of %ld mC! Configuring st"
    "age 2 shutdown at %ld mC.\n",
    a2,
    v6,
    v6);
  v10 = 0;
LABEL_12:
  if ( *(_DWORD *)(a1 + 24) == 9
    && ((v11 = *(_DWORD *)(a1 + 28), (unsigned int)(v11 - 256) < 2) || (unsigned int)(v11 - 1) <= 1) )
  {
    v7 = *(_BYTE *)(a1 + 40) | 8;
  }
  else
  {
    v12 = *(_BYTE *)(a1 + 40);
    if ( v10 )
      v7 = v12 | 0x48;
    else
      v7 = v12 | 8;
  }
  return regmap_write(*(_QWORD *)a1, (unsigned int)(*(_DWORD *)(a1 + 48) + 64), v7);
}
