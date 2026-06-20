__int64 __fastcall cm_csr_set_ss_wait_for_key(
        unsigned __int8 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  _QWORD *mac_context; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7

  mac_context = sme_get_mac_context(a2, a3, a4, a5, a6, a7, a8, a9);
  if ( mac_context )
    return csr_roam_substate_change((__int64)mac_context, 5, a1, v11, v12, v13, v14, v15, v16, v17, v18);
  else
    return qdf_trace_msg(
             0x34u,
             2u,
             "%s: mac_ctx is NULL",
             v11,
             v12,
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             "cm_csr_set_ss_wait_for_key");
}
