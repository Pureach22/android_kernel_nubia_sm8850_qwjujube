__int64 __fastcall disable_regulators(__int64 result)
{
  __int64 v1; // x20
  __int64 v2; // x19

  if ( *(_DWORD *)(result + 408) - 1 >= 0 )
  {
    v1 = 16LL * (unsigned int)(*(_DWORD *)(result + 408) - 1);
    v2 = result;
    do
    {
      regulator_set_voltage(*(_QWORD *)(*(_QWORD *)(v2 + 400) + v1), 0, 0x7FFFFFFF);
      regulator_set_load(*(_QWORD *)(*(_QWORD *)(v2 + 400) + v1), 0);
      result = regulator_disable(*(_QWORD *)(*(_QWORD *)(v2 + 400) + v1));
      v1 -= 16;
    }
    while ( v1 != -16 );
  }
  return result;
}
