__int64 __fastcall heuristics_scid_remove(__int64 a1)
{
  __int64 result; // x0

  if ( (of_property_match_string(*(_QWORD *)(*(_QWORD *)(a1 + 112) + 744LL), "compatible", "qcom,sun-llcc") & 0x80000000) != 0 )
    result = heuristics_set_param_v2(a1, 0);
  else
    result = heuristics_set_param(a1, 0);
  *(_QWORD *)(a1 + 168) = 0;
  return result;
}
