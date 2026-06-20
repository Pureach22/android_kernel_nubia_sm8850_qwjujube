__int64 __fastcall wlan_serialization_register_comp_info_cb(__int64 a1, unsigned int a2, unsigned int a3, __int64 a4)
{
  unsigned int v8; // w0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  unsigned int v17; // w21
  __int64 psoc_obj; // x0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x8

  v8 = wlan_serialization_validate_cmd(a2, a3);
  if ( v8 )
  {
    v17 = v8;
    qdf_trace_msg(
      0x4Cu,
      2u,
      "%s: invalid comp_id %d or cmd_type %d",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "wlan_serialization_register_comp_info_cb",
      a2,
      a3);
    return v17;
  }
  else
  {
    psoc_obj = wlan_serialization_get_psoc_obj(a1);
    if ( psoc_obj )
    {
      if ( a2 > 0x35 || a3 >= 0x22 )
      {
        __break(0x5512u);
        JUMPOUT(0x1B5D70);
      }
      v28 = psoc_obj;
      *(_QWORD *)(v28 + 432LL * a3 + 8LL * a2) = a4;
      return 0;
    }
    else
    {
      qdf_trace_msg(
        0x4Cu,
        2u,
        "%s: invalid ser_soc_obj",
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        "wlan_serialization_register_comp_info_cb");
      return 16;
    }
  }
}
