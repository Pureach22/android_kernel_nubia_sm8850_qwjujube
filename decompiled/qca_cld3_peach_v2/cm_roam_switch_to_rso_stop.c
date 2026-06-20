__int64 __fastcall cm_roam_switch_to_rso_stop(__int64 a1, __int64 a2, unsigned int a3, unsigned __int8 *a4, char a5)
{
  __int64 v5; // x19
  unsigned int v9; // w20
  unsigned int roam_state; // w0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7

  v5 = *(_QWORD *)(a1 + 80);
  v9 = a2;
  roam_state = mlme_get_roam_state(v5, a2);
  if ( roam_state <= 5 && ((1 << roam_state) & 0x34) != 0 )
  {
    if ( (unsigned int)cm_roam_stop_req(v5, v9, a3, a4, a5 & 1) )
    {
      qdf_trace_msg(
        0x68u,
        2u,
        "%s: ROAM: Unable to switch to RSO STOP State",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "cm_roam_switch_to_rso_stop");
      return 16;
    }
    mlme_set_roam_state(v5, v9, 3u);
  }
  return 0;
}
