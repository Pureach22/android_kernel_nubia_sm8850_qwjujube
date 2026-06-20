__int64 __fastcall enable_regulators(__int64 a1)
{
  __int64 v2; // x20
  __int64 v3; // x21
  int v4; // w0
  unsigned int v6; // w20
  __int64 v7; // x21

  if ( *(int *)(a1 + 408) < 1 )
    return 0;
  v2 = 0;
  v3 = 0;
  while ( 1 )
  {
    regulator_set_voltage(
      *(_QWORD *)(*(_QWORD *)(a1 + 400) + v2),
      *(unsigned int *)(*(_QWORD *)(a1 + 400) + v2 + 8),
      0x7FFFFFFF);
    regulator_set_load(*(_QWORD *)(*(_QWORD *)(a1 + 400) + v2), *(unsigned int *)(*(_QWORD *)(a1 + 400) + v2 + 12));
    v4 = regulator_enable(*(_QWORD *)(*(_QWORD *)(a1 + 400) + v2));
    if ( v4 )
      break;
    ++v3;
    v2 += 16;
    if ( v3 >= *(int *)(a1 + 408) )
      return 0;
  }
  v6 = v4;
  dev_err(*(_QWORD *)a1, "Regulator enable failed(rc:%d)\n", v4);
  if ( *(_DWORD *)(a1 + 408) - 1 >= 0 )
  {
    v7 = 16LL * (unsigned int)(*(_DWORD *)(a1 + 408) - 1);
    do
    {
      regulator_set_voltage(*(_QWORD *)(*(_QWORD *)(a1 + 400) + v7), 0, 0x7FFFFFFF);
      regulator_set_load(*(_QWORD *)(*(_QWORD *)(a1 + 400) + v7), 0);
      regulator_disable(*(_QWORD *)(*(_QWORD *)(a1 + 400) + v7));
      v7 -= 16;
    }
    while ( v7 != -16 );
  }
  return v6;
}
