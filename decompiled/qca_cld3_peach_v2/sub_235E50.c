__int64 __fastcall sub_235E50(__int64 a1, __int64 a2, __int64 a3)
{
  int v3; // wsp
  __int64 v4; // x3

  v4 = (unsigned int)(v3 - 3133440);
  return wmi_unified_thermal_mitigation_param_cmd_send(a1, a2, a3, v4);
}
