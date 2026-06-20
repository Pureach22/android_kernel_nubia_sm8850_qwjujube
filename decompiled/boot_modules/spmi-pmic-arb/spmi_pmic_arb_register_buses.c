__int64 __fastcall spmi_pmic_arb_register_buses(__int64 a1, __int64 a2)
{
  __int64 v2; // x20
  __int64 result; // x0
  __int64 v6; // x22

  v2 = *(_QWORD *)(a2 + 760);
  if ( (unsigned int)of_device_is_compatible(v2, "qcom,spmi-pmic-arb") )
    return spmi_pmic_arb_bus_init(a2, v2, a1);
  result = of_get_next_available_child(v2, 0);
  if ( result )
  {
    v6 = result;
    do
    {
      if ( (of_node_name_eq(v6, "spmi") & 1) != 0 )
      {
        result = spmi_pmic_arb_bus_init(a2, v6, a1);
        if ( (_DWORD)result )
          break;
      }
      result = of_get_next_available_child(v2, v6);
      v6 = result;
    }
    while ( result );
  }
  return result;
}
