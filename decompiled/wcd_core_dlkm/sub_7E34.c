__int64 __fastcall sub_7E34(int a1, int a2, int a3, __int64 a4, char *a5)
{
  unsigned __int16 *v5; // x30
  int v6; // w3

  v6 = __ldaxr(v5);
  return msm_cdc_set_supply_min_voltage(a1, a2, a3, v6, a5);
}
