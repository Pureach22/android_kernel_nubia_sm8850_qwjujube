__int64 __fastcall tgt_spectral_init_pdev_feature_caps(
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
  __int64 lmac_if_txops; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 (__fastcall *v19)(_QWORD); // x8

  if ( a1 )
  {
    lmac_if_txops = wlan_spectral_pdev_get_lmac_if_txops();
    if ( lmac_if_txops )
    {
      v19 = *(__int64 (__fastcall **)(_QWORD))(lmac_if_txops + 208);
      if ( *((_DWORD *)v19 - 1) != -2099273483 )
        __break(0x8228u);
      return v19(a1);
    }
    else
    {
      qdf_trace_msg(
        0x56u,
        2u,
        "%s: Spectral txops is null",
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        "tgt_spectral_init_pdev_feature_caps");
      return 16;
    }
  }
  else
  {
    qdf_trace_msg(0x56u, 2u, "%s: pdev is NULL!", a2, a3, a4, a5, a6, a7, a8, a9, "tgt_spectral_init_pdev_feature_caps");
    return 4;
  }
}
