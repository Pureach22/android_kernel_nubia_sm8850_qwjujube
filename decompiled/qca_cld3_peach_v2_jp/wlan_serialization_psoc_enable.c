__int64 __fastcall wlan_serialization_psoc_enable(__int64 a1)
{
  __int64 psoc_obj; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  char v11; // w8
  __int64 v13; // x20
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x0

  psoc_obj = wlan_serialization_get_psoc_obj(a1);
  if ( psoc_obj )
  {
    if ( a1 )
      v11 = 6 * *(_BYTE *)(a1 + 49) + 8;
    else
      v11 = 8;
    *(_BYTE *)(psoc_obj + 14968) = v11;
    v13 = psoc_obj;
    wlan_minidump_log(psoc_obj, 14992, a1, 50, "wlan_ser_psoc_obj");
    qdf_trace_msg(
      0x4Cu,
      8u,
      "%s: max_active_cmds %d",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "wlan_serialization_psoc_enable",
      *(unsigned __int8 *)(v13 + 14968));
    v22 = _qdf_mem_malloc(
            (unsigned __int64)*(unsigned __int8 *)(v13 + 14968) << 6,
            "wlan_serialization_psoc_enable",
            89);
    *(_QWORD *)(v13 + 14960) = v22;
    return 2 * (unsigned int)(v22 == 0);
  }
  else
  {
    qdf_trace_msg(
      0x4Cu,
      2u,
      "%s: invalid ser_soc_obj",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "wlan_serialization_psoc_enable");
    return 16;
  }
}
