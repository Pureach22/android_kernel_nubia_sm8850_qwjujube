__int64 __fastcall target_if_fwol_register_event_handler(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x8
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  _BYTE *psoc_obj; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x8
  _QWORD *v21; // x0
  const char *v22; // x2
  unsigned int v23; // w1

  v1 = a1;
  if ( a1 )
  {
    v2 = *(_QWORD *)(a1 + 2800);
    if ( v2 )
      a1 = *(_QWORD *)(v2 + 16);
    else
      a1 = 0;
  }
  if ( (unsigned int)wmi_unified_register_event(a1, 221, (__int64)target_if_fwol_get_elna_bypass_resp) )
    qdf_trace_msg(
      0x49u,
      8u,
      "%s: Failed to register get eLNA bypass event cb",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "target_if_fwol_register_elna_event_handler");
  psoc_obj = (_BYTE *)fwol_get_psoc_obj(v1);
  if ( !psoc_obj )
  {
    v22 = "%s: Failed to get FWOL Obj";
    v23 = 2;
LABEL_20:
    qdf_trace_msg(
      0x49u,
      v23,
      v22,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "target_if_fwol_register_thermal_throttle_handler");
    return 0;
  }
  if ( (psoc_obj[24] & 1) == 0 && (psoc_obj[1440] != 1 || !psoc_obj[92]) )
  {
    v22 = "%s: thermal mitigation or stats offload not enabled";
    goto LABEL_19;
  }
  if ( v1 && (v20 = *(_QWORD *)(v1 + 2800)) != 0 )
    v21 = *(_QWORD **)(v20 + 16);
  else
    v21 = nullptr;
  if ( (unsigned int)wmi_unified_register_event_handler(
                       v21,
                       0x2Du,
                       (__int64)target_if_fwol_thermal_throttle_event_handler,
                       2u,
                       v12,
                       v13,
                       v14,
                       v15,
                       v16,
                       v17,
                       v18,
                       v19) )
  {
    v22 = "%s: Failed to register thermal stats event cb";
LABEL_19:
    v23 = 8;
    goto LABEL_20;
  }
  return 0;
}
