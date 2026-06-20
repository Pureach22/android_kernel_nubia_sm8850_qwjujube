__int64 __fastcall cds_dp_open(
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
  __int64 v9; // x20
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  unsigned int v19; // w8
  __int64 **v20; // x0
  __int64 v21; // x9
  unsigned int (*v22)(void); // x9
  const char *v23; // x2
  const char *v24; // x3
  unsigned int v25; // w0
  unsigned int v26; // w1
  __int64 **v27; // x0
  __int64 v28; // x8
  unsigned int (*v29)(void); // x8
  const char *v30; // x2
  const char *v31; // x3
  unsigned int v32; // w0
  unsigned int v33; // w1
  __int64 v34; // x0
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  __int64 **v43; // x0
  __int64 v44; // x8
  void (*v45)(void); // x8
  __int64 **v46; // x0
  __int64 v47; // x8
  void (*v48)(void); // x8
  __int64 result; // x0
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  _QWORD *context; // x0
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  char v67; // w1
  int v68; // w0

  _ReadStatusReg(SP_EL0);
  v9 = *(_QWORD *)gp_cds_context;
  if ( !*(_QWORD *)gp_cds_context )
  {
    qdf_trace_msg(0x38u, 2u, "%s: HDD context is null", a2, a3, a4, a5, a6, a7, a8, a9, "cds_dp_open");
    goto LABEL_59;
  }
  if ( !gp_cds_context )
  {
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: cds context pointer is null (via %s)",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "__cds_get_context",
      "cds_dp_open");
    goto LABEL_9;
  }
  if ( !*(_QWORD *)(gp_cds_context + 64) )
  {
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: Module ID %d context is Null (via %s)",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "__cds_get_context",
      71,
      "cds_dp_open");
LABEL_9:
    if ( (unsigned int)ucfg_dp_txrx_pdev_attach() )
      goto LABEL_5;
LABEL_10:
    v19 = *(_DWORD *)(v9 + 528);
    if ( v19 > 0x2B || ((1LL << v19) & 0xD6498A00000LL) == 0 )
      goto LABEL_24;
    if ( gp_cds_context )
    {
      v20 = *(__int64 ***)(gp_cds_context + 64);
      if ( v20 )
      {
        if ( *v20 )
        {
          v21 = **v20;
          if ( v21 )
          {
            v22 = *(unsigned int (**)(void))(v21 + 408);
            if ( v22 )
            {
              if ( *((_DWORD *)v22 - 1) != -1936179147 )
                __break(0x8229u);
              if ( v22() )
              {
                v23 = "%s: Failed to init TXRX";
                v24 = "cds_dp_open";
                v25 = 56;
                v26 = 1;
                goto LABEL_57;
              }
            }
          }
LABEL_24:
          v27 = *(__int64 ***)(gp_cds_context + 64);
          if ( v27 && *v27 )
          {
            v28 = **v27;
            if ( v28 )
            {
              v29 = *(unsigned int (**)(void))(v28 + 544);
              if ( v29 )
              {
                if ( *((_DWORD *)v29 - 1) != 504489773 )
                  __break(0x8228u);
                if ( v29() )
                {
                  v30 = "%s: Failed to attach interrupts";
                  v31 = "cds_dp_open";
                  v32 = 56;
                  v33 = 1;
                  goto LABEL_48;
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
              v11,
              v12,
              v13,
              v14,
              v15,
              v16,
              v17,
              v18,
              "cdp_txrx_intr_attach");
          }
          v34 = ucfg_dp_txrx_set_default_affinity(a1);
          if ( (unsigned int)hdd_get_conparam(v34) == 4 )
          {
            if ( gp_cds_context )
              goto LABEL_35;
          }
          else if ( gp_cds_context )
          {
LABEL_35:
            if ( !*(_QWORD *)(gp_cds_context + 64) )
              qdf_trace_msg(
                0x38u,
                2u,
                "%s: Module ID %d context is Null (via %s)",
                v35,
                v36,
                v37,
                v38,
                v39,
                v40,
                v41,
                v42,
                "__cds_get_context",
                71,
                "cds_dp_open");
            goto LABEL_39;
          }
          qdf_trace_msg(
            0x38u,
            2u,
            "%s: cds context pointer is null (via %s)",
            v35,
            v36,
            v37,
            v38,
            v39,
            v40,
            v41,
            v42,
            "__cds_get_context",
            "cds_dp_open");
LABEL_39:
          if ( !(unsigned int)ucfg_dp_txrx_init() )
          {
            v50 = ucfg_pmo_psoc_set_txrx_pdev_id(a1, 0);
            context = _cds_get_context(71, (__int64)"cds_dp_open", v50, v51, v52, v53, v54, v55, v56, v57);
            cdp_set_rtpm_tput_policy_requirement(context);
            qdf_trace_msg(
              0x38u,
              8u,
              "%s: CDS successfully Opened",
              v59,
              v60,
              v61,
              v62,
              v63,
              v64,
              v65,
              v66,
              "cds_dp_open");
            v67 = (unsigned int)cdp_cfg_get(*(_QWORD *)(gp_cds_context + 64), 8) != 0;
            ucfg_dp_set_tc_based_dyn_gro(a1, v67);
            v68 = cdp_cfg_get(*(_QWORD *)(gp_cds_context + 64), 9);
            ucfg_dp_set_tc_ingress_prio(a1, v68);
            result = 0;
            goto LABEL_60;
          }
          v43 = *(__int64 ***)(gp_cds_context + 64);
          if ( v43 && *v43 )
          {
            v44 = **v43;
            if ( v44 )
            {
              v45 = *(void (**)(void))(v44 + 552);
              if ( v45 )
              {
                if ( *((_DWORD *)v45 - 1) != -1106481425 )
                  __break(0x8228u);
                v45();
              }
            }
            goto LABEL_49;
          }
          v30 = "%s: Invalid Instance:";
          v31 = "cdp_txrx_intr_detach";
          v32 = 137;
          v33 = 8;
LABEL_48:
          qdf_trace_msg(v32, v33, v30, v11, v12, v13, v14, v15, v16, v17, v18, v31);
LABEL_49:
          v46 = *(__int64 ***)(gp_cds_context + 64);
          if ( v46 && *v46 )
          {
            v47 = **v46;
            if ( v47 )
            {
              v48 = *(void (**)(void))(v47 + 64);
              if ( v48 )
              {
                if ( *((_DWORD *)v48 - 1) != 226555140 )
                  __break(0x8228u);
                v48();
              }
            }
            goto LABEL_58;
          }
          v23 = "%s: Invalid Instance:";
          v24 = "cdp_pdev_deinit";
          v25 = 137;
          v26 = 8;
LABEL_57:
          qdf_trace_msg(v25, v26, v23, v11, v12, v13, v14, v15, v16, v17, v18, v24);
LABEL_58:
          ucfg_dp_txrx_pdev_detach(*(__int64 ***)(gp_cds_context + 64), 0, 0);
          goto LABEL_59;
        }
      }
      else
      {
        qdf_trace_msg(
          0x38u,
          2u,
          "%s: Module ID %d context is Null (via %s)",
          v11,
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          "__cds_get_context",
          71,
          "cds_dp_open");
      }
    }
    else
    {
      qdf_trace_msg(
        0x38u,
        2u,
        "%s: cds context pointer is null (via %s)",
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        "__cds_get_context",
        "cds_dp_open");
    }
    qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance:", v11, v12, v13, v14, v15, v16, v17, v18, "cdp_pdev_init");
    goto LABEL_24;
  }
  if ( !(unsigned int)ucfg_dp_txrx_pdev_attach() )
    goto LABEL_10;
LABEL_5:
  qdf_trace_msg(0x38u, 1u, "%s: Failed to open TXRX", v11, v12, v13, v14, v15, v16, v17, v18, "cds_dp_open");
LABEL_59:
  result = 16;
LABEL_60:
  _ReadStatusReg(SP_EL0);
  return result;
}
