__int64 __fastcall wlan_ll_lt_sap_continue_csa_after_tsf_rsp(
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
  if ( a1 && *(_QWORD *)(a1 + 8) )
  {
    ll_lt_sap_continue_csa_after_tsf_rsp();
    _qdf_mem_free(*(_QWORD *)(a1 + 8));
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0xA1u,
      2u,
      "%s: msg: 0x%pK",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "wlan_ll_lt_sap_continue_csa_after_tsf_rsp",
      a1);
    return 29;
  }
}
