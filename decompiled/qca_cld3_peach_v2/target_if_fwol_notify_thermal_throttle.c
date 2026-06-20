__int64 __fastcall target_if_fwol_notify_thermal_throttle(__int64 a1, __int64 a2)
{
  __int64 psoc_obj; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 (__fastcall *v13)(__int64, __int64); // x8
  const char *v14; // x2
  unsigned int v15; // w1
  __int64 result; // x0

  psoc_obj = fwol_get_psoc_obj(a1);
  if ( !psoc_obj )
  {
    v14 = "%s: Failed to get FWOL Obj";
LABEL_8:
    v15 = 2;
LABEL_15:
    qdf_trace_msg(0x49u, v15, v14, v5, v6, v7, v8, v9, v10, v11, v12, "target_if_fwol_notify_thermal_throttle");
    return 4;
  }
  if ( !a2 )
  {
    v14 = "%s: info Null";
    goto LABEL_8;
  }
  v13 = *(__int64 (__fastcall **)(__int64, __int64))(psoc_obj + 1408);
  if ( !v13 )
  {
    v14 = "%s: No notify thermal_throttle callback";
    goto LABEL_14;
  }
  if ( *(_DWORD *)(a2 + 4) == 4 )
  {
    v14 = "%s: Invalid thermal target lvl";
LABEL_14:
    v15 = 8;
    goto LABEL_15;
  }
  if ( *((_DWORD *)v13 - 1) != 76461256 )
    __break(0x8228u);
  result = v13(a1, a2);
  if ( (_DWORD)result )
  {
    v14 = "%s: notify thermal_throttle failed.";
    goto LABEL_14;
  }
  return result;
}
