__int64 __fastcall ucfg_p2p_register_callbacks(
        __int64 a1,
        __int64 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 comp_private_obj; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x9
  _QWORD *v21; // x8
  __int64 v22; // x11
  __int64 v23; // x12

  if ( a1 && a2 )
  {
    comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 5u);
    if ( comp_private_obj )
    {
      v20 = a2[3];
      v21 = (_QWORD *)comp_private_obj;
      v22 = *a2;
      v23 = a2[1];
      v21[25] = a2[2];
      v21[26] = v20;
      v21[23] = v22;
      v21[24] = v23;
      return 0;
    }
    else
    {
      qdf_trace_msg(
        0x4Eu,
        2u,
        "%s: p2p soc private object is NULL",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "ucfg_p2p_register_callbacks");
      return 16;
    }
  }
  else
  {
    qdf_trace_msg(
      0x4Eu,
      2u,
      "%s: psoc: %pK or cb_obj: %pK context passed is NULL",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "ucfg_p2p_register_callbacks",
      a1,
      a2);
    return 4;
  }
}
