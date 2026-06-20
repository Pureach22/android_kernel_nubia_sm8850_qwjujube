__int64 __fastcall sme_send_rso_connect_params(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v11; // x8
  unsigned int v14; // w0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned int v23; // w19

  if ( (unsigned __int8)a2 >= 6u )
  {
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: Invalid sme vdev id: %d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "sme_send_rso_connect_params");
    return 4;
  }
  v11 = *(_QWORD *)(a1 + 8);
  if ( (*(_BYTE *)(v11 + 1563) & 1) != 0 )
  {
    if ( *(_BYTE *)(v11 + 1510) != 1 )
    {
      qdf_trace_msg(0x34u, 8u, "%s: LFR3 not enabled", a3, a4, a5, a6, a7, a8, a9, a10, "sme_send_rso_connect_params");
      return 4;
    }
    v14 = qdf_mutex_acquire(a1 + 12776);
    if ( v14 )
    {
      v23 = v14;
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: Failed to acquire SME lock",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "sme_send_rso_connect_params");
      return v23;
    }
    else
    {
      qdf_trace_msg(
        0x34u,
        8u,
        "%s: Updating fils config to fw",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "sme_send_rso_connect_params");
      wlan_roam_update_cfg(*(_QWORD *)(a1 + 21552), a2, 0x29u);
      qdf_mutex_release(a1 + 12776);
      return 0;
    }
  }
  else
  {
    qdf_trace_msg(0x34u, 8u, "%s: lfr enabled %d", a3, a4, a5, a6, a7, a8, a9, a10, "sme_send_rso_connect_params", 0);
    return 12;
  }
}
