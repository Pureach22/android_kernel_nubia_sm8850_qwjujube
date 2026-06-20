__int64 __fastcall spectral_register_legacy_cb(
        __int64 a1,
        _QWORD *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _QWORD *comp_private_obj; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7

  if ( a1 )
  {
    if ( (*(_BYTE *)(a1 + 30) & 0x80) != 0 )
    {
      qdf_trace_msg(
        0x56u,
        4u,
        "%s: Spectral feature is disabled",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "spectral_register_legacy_cb");
      return 39;
    }
    else
    {
      comp_private_obj = (_QWORD *)wlan_objmgr_psoc_get_comp_private_obj(a1, 0x13u);
      if ( comp_private_obj )
      {
        comp_private_obj[2] = *a2;
        comp_private_obj[3] = a2[1];
        comp_private_obj[4] = a2[2];
        comp_private_obj[5] = a2[3];
        return 0;
      }
      else
      {
        qdf_trace_msg(
          0x56u,
          2u,
          "%s: Invalid Context",
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          "spectral_register_legacy_cb");
        return 16;
      }
    }
  }
  else
  {
    qdf_trace_msg(0x56u, 2u, "%s: psoc is null", a3, a4, a5, a6, a7, a8, a9, a10, "spectral_register_legacy_cb");
    return 4;
  }
}
