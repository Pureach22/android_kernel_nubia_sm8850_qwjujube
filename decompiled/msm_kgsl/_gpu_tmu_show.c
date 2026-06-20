__int64 __fastcall gpu_tmu_show(__int64 a1, __int64 a2)
{
  __int64 property; // x20
  __int64 string; // x0
  __int64 v5; // x22
  __int64 result; // x0

  _ReadStatusReg(SP_EL0);
  property = of_find_property(*(_QWORD *)(*(_QWORD *)(a1 + 11168) + 760LL), "qcom,tzone-names", 0);
  string = of_prop_next_string(property, 0);
  if ( string )
  {
    v5 = string;
    do
    {
      if ( (unsigned __int64)thermal_zone_get_zone_by_name(v5) <= 0xFFFFFFFFFFFFF000LL )
        thermal_zone_get_temp();
      v5 = of_prop_next_string(property, v5);
    }
    while ( v5 );
  }
  LODWORD(result) = scnprintf(a2, 4096, "%d\n", 0);
  _ReadStatusReg(SP_EL0);
  return (int)result;
}
