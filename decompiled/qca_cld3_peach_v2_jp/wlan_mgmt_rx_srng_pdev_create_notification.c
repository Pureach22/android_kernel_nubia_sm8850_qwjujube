__int64 __fastcall wlan_mgmt_rx_srng_pdev_create_notification(
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
  _QWORD *context; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x21
  _QWORD *v20; // x22
  __int64 comp_private_obj; // x0
  __int64 v22; // x24
  __int64 v23; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x20
  unsigned int v33; // w0
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  unsigned int v42; // w19
  __int64 result; // x0
  const char *v44; // x2
  __int64 values; // x0
  __int64 v46; // x8
  unsigned int v47; // w22
  int entrysize; // w23
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  __int64 v57; // x0
  __int64 v58; // x0
  __int64 v59; // x0
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  __int64 v68; // x23
  __int64 v69; // x9
  __int64 v70; // x0
  double v71; // d0
  double v72; // d1
  double v73; // d2
  double v74; // d3
  double v75; // d4
  double v76; // d5
  double v77; // d6
  double v78; // d7
  __int64 v79; // x0
  double v80; // d0
  double v81; // d1
  double v82; // d2
  double v83; // d3
  double v84; // d4
  double v85; // d5
  double v86; // d6
  double v87; // d7
  __int64 v88; // x8
  __int64 v89; // x8
  const char *v90; // x2
  double v91; // d0
  double v92; // d1
  double v93; // d2
  double v94; // d3
  double v95; // d4
  double v96; // d5
  double v97; // d6
  double v98; // d7
  int c; // [xsp+Ch] [xbp-64h] BYREF
  _QWORD v100[2]; // [xsp+10h] [xbp-60h] BYREF
  __int64 v101; // [xsp+20h] [xbp-50h]
  __int64 v102; // [xsp+28h] [xbp-48h]
  __int64 v103; // [xsp+30h] [xbp-40h]
  __int64 v104; // [xsp+38h] [xbp-38h]
  __int64 v105; // [xsp+40h] [xbp-30h]
  __int64 v106; // [xsp+48h] [xbp-28h]
  __int64 v107; // [xsp+50h] [xbp-20h]
  __int64 v108; // [xsp+58h] [xbp-18h]
  __int64 v109; // [xsp+60h] [xbp-10h]
  __int64 v110; // [xsp+68h] [xbp-8h]

  v110 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = _cds_get_context(61, (__int64)"wlan_mgmt_rx_srng_pdev_create_notification", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !context )
  {
    v44 = "%s: invalid hif context";
LABEL_11:
    qdf_trace_msg(0xA5u, 2u, v44, v11, v12, v13, v14, v15, v16, v17, v18, "wlan_mgmt_rx_srng_pdev_create_notification");
LABEL_12:
    result = 16;
    goto LABEL_13;
  }
  v19 = *(_QWORD *)(a1 + 80);
  if ( !v19 )
  {
    v44 = "%s: psoc is NULL";
    goto LABEL_11;
  }
  v20 = context;
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(*(_QWORD *)(a1 + 80), 0x35u);
  if ( !comp_private_obj )
  {
    v44 = "%s: psoc priv is NULL";
    goto LABEL_11;
  }
  if ( *(_BYTE *)(comp_private_obj + 8) != 1 )
  {
    result = 0;
    goto LABEL_13;
  }
  v22 = comp_private_obj;
  v23 = _qdf_mem_malloc(0x60u, "wlan_mgmt_rx_srng_pdev_create_notification", 397);
  if ( !v23 )
  {
    qdf_trace_msg(
      0xA5u,
      2u,
      "%s: Failure to alloc mgmt rx srng pdev priv",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "wlan_mgmt_rx_srng_pdev_create_notification");
    result = 2;
    goto LABEL_13;
  }
  v32 = v23;
  v33 = wlan_objmgr_pdev_component_obj_attach(a1, 0x35u, v23, 0, v24, v25, v26, v27, v28, v29, v30, v31);
  if ( !v33 )
  {
    *(_QWORD *)v32 = a1;
    values = cfg_psoc_get_values(v19);
    v46 = v20[320];
    v47 = *(_DWORD *)(values + 32500);
    *(_QWORD *)(v32 + 24) = v46;
    v108 = 0;
    v109 = 0;
    entrysize = hal_srng_get_entrysize(v46, 14);
    v106 = 0;
    v107 = 0;
    v104 = 0;
    v105 = 0;
    v102 = 0;
    v103 = 0;
    v101 = 0;
    if ( *(_QWORD *)(v32 + 16) )
      goto LABEL_17;
    v88 = *(_QWORD *)(*(_QWORD *)v32 + 80LL);
    if ( !v88 )
    {
      v90 = "%s: psoc obj is NULL";
      goto LABEL_32;
    }
    v89 = *(_QWORD *)(v88 + 2120);
    *(_QWORD *)(v32 + 16) = v89;
    if ( v89 )
    {
LABEL_17:
      v57 = _qdf_mem_malloc(0xC00u, "wlan_mgmt_rx_srng_setup", 299);
      *(_QWORD *)(v32 + 80) = v57;
      if ( v57 )
      {
        v58 = *(_QWORD *)(v32 + 16);
        c = entrysize << 7;
        v59 = qdf_aligned_mem_alloc_consistent_fl(
                v58,
                (unsigned int *)&c,
                (__int64 *)(v32 + 40),
                (__int64 *)(v32 + 32),
                (__int64 *)(v32 + 48),
                0x20u,
                (__int64)"wlan_mgmt_rx_srng_setup",
                0x137u);
        if ( v59 )
        {
          v68 = v59;
          qdf_mem_set(*(void **)(v32 + 40), 0, c);
          v69 = *(_QWORD *)(v32 + 48);
          v70 = *(_QWORD *)(v32 + 24);
          *(_DWORD *)(v32 + 64) = c;
          *(_QWORD *)(v32 + 56) = v68;
          v100[0] = v69;
          v100[1] = v68;
          LODWORD(v101) = 128;
          v79 = hal_srng_setup(v70, 0xEu, 4, 0, (__int64)v100, 0, v71, v72, v73, v74, v75, v76, v77, v78);
          if ( v79 )
          {
            *(_QWORD *)(v32 + 72) = v79;
            *(_QWORD *)(v32 + 88) = 0;
            *(_DWORD *)(v32 + 8) = 0;
            if ( !(unsigned int)wlan_mgmt_rx_srng_attach_buffers(v32) )
            {
              if ( !(unsigned int)tgt_mgmt_rx_srng_register_ev_handler(v19) )
              {
                tgt_mgmt_rx_srng_send_reap_threshold(v19, v47);
                result = wlan_mgmt_rx_srng_htt_setup_send(a1);
                if ( !(_DWORD)result )
                  goto LABEL_13;
                tgt_mgmt_rx_srng_unregister_ev_handler(v19);
              }
              wlan_mgmt_rx_srng_free_buffers(v32);
            }
            wlan_mgmt_rx_srng_free(v32);
            goto LABEL_35;
          }
          qdf_trace_msg(
            0xA5u,
            2u,
            "%s: mgmt rx srng setup failed",
            v80,
            v81,
            v82,
            v83,
            v84,
            v85,
            v86,
            v87,
            "wlan_mgmt_rx_srng_setup");
          _qdf_mem_free_consistent(*(_QWORD *)(v32 + 16), *(_QWORD *)(*(_QWORD *)(v32 + 16) + 40LL), c);
        }
        else
        {
          qdf_trace_msg(
            0xA5u,
            2u,
            "%s: Failed to alloc mem for mgmt rx srng",
            v60,
            v61,
            v62,
            v63,
            v64,
            v65,
            v66,
            v67,
            "wlan_mgmt_rx_srng_setup");
        }
        _qdf_mem_free(*(_QWORD *)(v32 + 80));
LABEL_35:
        if ( (unsigned int)wlan_objmgr_pdev_component_obj_detach(a1, 0x35u, v32) )
          qdf_trace_msg(
            0xA5u,
            2u,
            "%s: Failed to detach mgmt rx srng pdev_priv",
            v91,
            v92,
            v93,
            v94,
            v95,
            v96,
            v97,
            v98,
            "wlan_mgmt_rx_srng_pdev_create_notification");
        _qdf_mem_free(v32);
        *(_BYTE *)(v22 + 8) = 0;
        goto LABEL_12;
      }
      v90 = "%s: Failure to alloc rx desc for mgmt rx srng";
    }
    else
    {
      v90 = "%s: no osdev";
    }
LABEL_32:
    qdf_trace_msg(0xA5u, 2u, v90, v49, v50, v51, v52, v53, v54, v55, v56, "wlan_mgmt_rx_srng_setup");
    goto LABEL_35;
  }
  v42 = v33;
  qdf_trace_msg(
    0xA5u,
    2u,
    "%s: Failed to attach mgmt rx srng priv to pdev",
    v34,
    v35,
    v36,
    v37,
    v38,
    v39,
    v40,
    v41,
    "wlan_mgmt_rx_srng_pdev_create_notification");
  _qdf_mem_free(v32);
  result = v42;
  *(_BYTE *)(v22 + 8) = 0;
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
