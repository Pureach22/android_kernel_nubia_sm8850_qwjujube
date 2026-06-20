__int64 __fastcall target_if_twt_register_events(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x8
  _QWORD *v10; // x20
  unsigned int v12; // w0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned int v21; // w21
  __int64 result; // x0
  unsigned int v23; // w0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  unsigned int v32; // w20
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  unsigned int v41; // w19

  if ( a1 && (v9 = *(_QWORD *)(a1 + 2800)) != 0 && (v10 = *(_QWORD **)(v9 + 16)) != nullptr )
  {
    v12 = wmi_unified_register_event_handler(
            *(_QWORD **)(v9 + 16),
            0xBEu,
            (__int64)target_if_twt_en_complete_event_handler,
            0,
            a2,
            a3,
            a4,
            a5,
            a6,
            a7,
            a8,
            a9);
    if ( v12 )
    {
      v21 = v12;
      qdf_trace_msg(
        0x49u,
        2u,
        "%s: Failed to register twt enable event cb",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "target_if_twt_register_events");
      if ( v21 == 11 )
        return 0;
      else
        return v21;
    }
    else
    {
      v23 = wmi_unified_register_event_handler(
              v10,
              0xBFu,
              (__int64)target_if_twt_disable_comp_event_handler,
              0,
              v13,
              v14,
              v15,
              v16,
              v17,
              v18,
              v19,
              v20);
      if ( v23 )
      {
        v32 = v23;
        qdf_trace_msg(
          0x49u,
          2u,
          "%s: Failed to register twt disable event cb",
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          "target_if_twt_register_events");
        if ( v32 == 11 )
          return 0;
        else
          return v32;
      }
      else
      {
        result = target_if_twt_register_ext_events(a1);
        if ( (_DWORD)result )
        {
          v41 = result;
          qdf_trace_msg(
            0x49u,
            2u,
            "%s: Failed to register twt ext events",
            v33,
            v34,
            v35,
            v36,
            v37,
            v38,
            v39,
            v40,
            "target_if_twt_register_events");
          if ( v41 == 11 )
            return 0;
          else
            return v41;
        }
      }
    }
  }
  else
  {
    qdf_trace_msg(0x49u, 2u, "%s: wmi_handle is null!", a2, a3, a4, a5, a6, a7, a8, a9, "target_if_twt_register_events");
    return 4;
  }
  return result;
}
