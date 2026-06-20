__int64 __fastcall sme_extended_change_channel_ind(
        __int64 a1,
        unsigned __int8 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v12; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  int v21; // w8
  unsigned int v22; // w20
  __int64 v23; // x21

  if ( a2 )
  {
    v12 = _qdf_mem_malloc(0x180u, "sme_extended_change_channel_ind", 1441);
    if ( v12 )
    {
      v21 = *((_DWORD *)a2 + 1);
      v22 = *a2;
      *(_DWORD *)(v12 + 180) = v21;
      v23 = v12;
      qdf_trace_msg(
        0x34u,
        8u,
        "%s: sapdfs: Received eWNI_SME_EXT_CHANGE_CHANNEL_IND for session id [%d]",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "sme_extended_change_channel_ind",
        v22);
      csr_roam_call_callback(a1, v22, v23, 41, 19);
      _qdf_mem_free(v23);
      return 0;
    }
    else
    {
      return 2;
    }
  }
  else
  {
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: ext_chan_ind is NULL",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "sme_extended_change_channel_ind");
    return 16;
  }
}
