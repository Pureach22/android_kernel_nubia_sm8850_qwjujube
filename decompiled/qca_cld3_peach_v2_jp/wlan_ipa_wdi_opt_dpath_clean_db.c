_BYTE *__fastcall wlan_ipa_wdi_opt_dpath_clean_db(
        _BYTE *result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  char *v9; // x20
  _BYTE *v10; // x19

  v9 = result + 4096;
  v10 = result;
  if ( result[7580] )
  {
    qdf_trace_msg(
      0x61u,
      8u,
      "%s: opt_dp: clean internal db of flt hdl - %d",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "wlan_ipa_wdi_opt_dpath_clean_db",
      0);
    v9[3432] = 0;
    qdf_mem_set(v10 + 7529, 4u, 0);
    result = qdf_mem_set(v10 + 7537, 0x10u, 0);
    *((_WORD *)v9 + 1742) = 0;
  }
  if ( v9[3588] )
  {
    qdf_trace_msg(
      0x61u,
      8u,
      "%s: opt_dp: clean internal db of flt hdl - %d",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "wlan_ipa_wdi_opt_dpath_clean_db",
      1);
    v9[3536] = 0;
    qdf_mem_set(v10 + 7633, 4u, 0);
    result = qdf_mem_set(v10 + 7641, 0x10u, 0);
    *((_WORD *)v9 + 1794) = 0;
  }
  return result;
}
