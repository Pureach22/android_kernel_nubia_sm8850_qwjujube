__int64 __fastcall rpmh_regulator_arc_list_voltage(__int64 a1, unsigned int a2)
{
  __int64 v3; // x8

  v3 = *(_QWORD *)(rdev_get_drvdata() + 336);
  if ( *(_DWORD *)(v3 + 208) <= a2 )
    return 0;
  if ( a2 < 0x20 )
    return *(unsigned int *)(v3 + 4LL * a2 + 80);
  __break(0x5512u);
  return rpmh_regulator_arc_set_voltage_sel();
}
