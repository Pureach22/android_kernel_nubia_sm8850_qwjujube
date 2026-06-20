__int64 __fastcall wlan_dp_txrx_attach_target(
        __int64 (****a1)(void),
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
  __int64 (**v10)(void); // x8
  __int64 v12; // x21
  __int64 (*v13)(void); // x8
  __int64 (****v14)(void); // x22
  unsigned int v15; // w19
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 (****v24)(void); // x22
  unsigned int v25; // w0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  unsigned int v34; // w0
  const char *v35; // x2
  __int64 (**v37)(void); // x8
  __int64 (*v38)(void); // x8
  unsigned int v39; // w0
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7

  if ( a1 && *a1 )
  {
    v10 = **a1;
    v12 = gp_dp_ctx;
    if ( !v10 )
      goto LABEL_8;
    v13 = *v10;
    if ( !v13 )
      goto LABEL_8;
    v14 = a1;
    if ( *((_DWORD *)v13 - 1) != 504489773 )
      __break(0x8228u);
    v15 = v13();
    a1 = v14;
    if ( !v15 )
    {
LABEL_8:
      v24 = a1;
      v25 = dp_rx_fst_target_config(v12);
      if ( v25 != 11 )
      {
        v15 = v25;
        if ( v25 )
        {
          v35 = "%s: Failed to send htt fst setup config message to target";
          goto LABEL_23;
        }
        v34 = dp_rx_fisa_config(v12);
        if ( v34 )
        {
          v15 = v34;
          v35 = "%s: Failed to send htt FISA config message to target";
LABEL_23:
          qdf_trace_msg(0x45u, 2u, v35, v26, v27, v28, v29, v30, v31, v32, v33, "wlan_dp_rx_fisa_attach_target");
          return v15;
        }
      }
      if ( *v24 )
      {
        v37 = **v24;
        if ( v37 )
        {
          v38 = v37[1];
          if ( v38 )
          {
            if ( *((_DWORD *)v38 - 1) != 2077786039 )
              __break(0x8228u);
            v39 = ((__int64 (__fastcall *)(__int64 (****)(void), _QWORD))v38)(v24, a2);
            if ( v39 )
            {
              qdf_trace_msg(
                0x45u,
                2u,
                "%s: Failed to attach pdev target; errno:%d",
                v40,
                v41,
                v42,
                v43,
                v44,
                v45,
                v46,
                v47,
                "wlan_dp_txrx_attach_target",
                v39);
              return 16;
            }
          }
        }
      }
      else
      {
        qdf_trace_msg(
          0x89u,
          8u,
          "%s: Invalid Instance:",
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          "cdp_pdev_attach_target");
      }
      return 0;
    }
  }
  else
  {
    qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance:", a3, a4, a5, a6, a7, a8, a9, a10, "cdp_soc_attach_target");
    v15 = 4;
  }
  qdf_trace_msg(
    0x45u,
    2u,
    "%s: Failed to attach soc target; status:%d",
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    "wlan_dp_txrx_attach_target",
    v15);
  return v15;
}
