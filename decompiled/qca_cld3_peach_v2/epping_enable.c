__int64 __fastcall epping_enable(
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
  __int64 v10; // x0
  __int64 v11; // x1
  __int64 v12; // x2
  __int64 v13; // x3
  __int64 global_context; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x20
  __int64 v24; // x19
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  _QWORD *context; // x0
  const void *v34; // x21
  __int64 target_info_handle; // x22
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  int v44; // w8
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  _QWORD *v53; // x22
  int conparam; // w0
  _QWORD *v55; // x0
  _QWORD *v56; // x0
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  const char *v65; // x2
  const char *v66; // x2
  unsigned int v67; // w0
  __int64 result; // x0
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  unsigned int v77; // w0
  double v78; // d0
  double v79; // d1
  double v80; // d2
  double v81; // d3
  double v82; // d4
  double v83; // d5
  double v84; // d6
  double v85; // d7
  unsigned int v86; // w19
  __int64 v87; // [xsp+0h] [xbp-40h] BYREF
  __int64 (__fastcall *v88)(); // [xsp+8h] [xbp-38h]
  __int64 (__fastcall *v89)(); // [xsp+10h] [xbp-30h]
  __int64 v90; // [xsp+18h] [xbp-28h]
  __int64 v91; // [xsp+20h] [xbp-20h]
  __int64 v92; // [xsp+28h] [xbp-18h]
  int v93; // [xsp+30h] [xbp-10h] BYREF
  __int16 v94; // [xsp+34h] [xbp-Ch]
  __int64 v95; // [xsp+38h] [xbp-8h]

  v95 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v91 = 0;
  v92 = 0;
  v90 = 0;
  v94 = 0;
  v93 = 0;
  v10 = qdf_trace_msg(0x33u, 5u, "%s: Enter", a2, a3, a4, a5, a6, a7, a8, a9, "epping_enable");
  global_context = cds_get_global_context(v10, v11, v12, v13);
  if ( global_context )
  {
    v23 = g_epping_ctx;
    if ( g_epping_ctx )
    {
      v24 = global_context;
      *(_QWORD *)(g_epping_ctx + 32) = a1;
      epping_get_dummy_mac_addr((__int64)&v93);
      qdf_timer_module_init();
      context = _cds_get_context(61, (__int64)"epping_enable", v25, v26, v27, v28, v29, v30, v31, v32);
      if ( context )
      {
        v34 = context;
        target_info_handle = hif_get_target_info_handle((__int64)context);
        _cds_get_context(66, (__int64)"epping_enable", v36, v37, v38, v39, v40, v41, v42, v43);
        v44 = *(_DWORD *)(target_info_handle + 4);
        v87 = 0;
        v88 = ol_target_failure_0;
        *(_DWORD *)(v23 + 16) = v44;
        v89 = epping_target_suspend_acknowledge;
        v53 = _cds_get_context(64, (__int64)"epping_enable", v45, v46, v47, v48, v49, v50, v51, v52);
        conparam = cds_get_conparam();
        v55 = htc_create(v34, &v87, (__int64)v53, conparam);
        *(_QWORD *)(v24 + 40) = v55;
        if ( v55 )
        {
          v56 = _cds_get_context(62, (__int64)"epping_enable", v15, v16, v17, v18, v19, v20, v21, v22);
          *(_QWORD *)(v23 + 56) = v56;
          if ( v56 )
          {
            if ( (unsigned int)htc_wait_target(v56) )
            {
              v65 = "%s: htc_wait_target error";
            }
            else
            {
              qdf_trace_msg(
                0x33u,
                5u,
                "%s: HTC ready",
                v57,
                v58,
                v59,
                v60,
                v61,
                v62,
                v63,
                v64,
                "epping_enable",
                v87,
                v88,
                v89);
              if ( !(unsigned int)epping_connect_service(v23) )
              {
                if ( !(unsigned int)htc_start(*(__int64 **)(v23 + 56)) )
                {
                  qdf_trace_msg(0x33u, 5u, "%s: HTC started", v69, v70, v71, v72, v73, v74, v75, v76, "epping_enable");
                  v77 = epping_cookie_init(v23);
                  if ( (v77 & 0x80000000) == 0 )
                  {
                    v86 = v77;
                    qdf_trace_msg(0x33u, 5u, "%s: Exit", v78, v79, v80, v81, v82, v83, v84, v85, "epping_enable");
                    result = v86;
                    goto LABEL_16;
                  }
                  qdf_trace_msg(
                    0x33u,
                    1u,
                    "%s: cookie init failed",
                    v78,
                    v79,
                    v80,
                    v81,
                    v82,
                    v83,
                    v84,
                    v85,
                    "epping_enable");
                  htc_stop(*(_QWORD *)(v23 + 56));
                  epping_cookie_cleanup(v23);
                }
                goto LABEL_21;
              }
              v65 = "%s: htc_wait_targetdone";
            }
            qdf_trace_msg(0x33u, 1u, v65, v57, v58, v59, v60, v61, v62, v63, v64, "epping_enable", v87, v88, v89);
LABEL_21:
            htc_destroy(*(_QWORD **)(v24 + 40));
            *(_QWORD *)(v24 + 40) = 0;
            goto LABEL_15;
          }
          v66 = "%s: HTCHandle is NULL";
          goto LABEL_10;
        }
        v66 = "%s: Failed to Create HTC";
      }
      else
      {
        v66 = "%s: scn is null!";
      }
      v67 = 56;
      goto LABEL_14;
    }
    v66 = "%s: Failed to get epping_ctx";
  }
  else
  {
    v66 = "%s: Failed cds_get_global_context";
  }
LABEL_10:
  v67 = 51;
LABEL_14:
  qdf_trace_msg(v67, 1u, v66, v15, v16, v17, v18, v19, v20, v21, v22, "epping_enable", v87, v88, v89);
LABEL_15:
  result = 0xFFFFFFFFLL;
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
