__int64 __fastcall cam_sensor_utils_parse_pm_ctrl_flag(__int64 a1, __int64 a2)
{
  __int64 result; // x0

  result = of_get_next_parent();
  if ( a2 && result )
  {
    if ( *(_QWORD *)(a2 + 8) )
    {
      result = of_find_property(result, "qcom,pm-ctrl-client", 0);
      *(_BYTE *)(*(_QWORD *)(a2 + 8) + 16LL) = result != 0;
    }
  }
  return result;
}
