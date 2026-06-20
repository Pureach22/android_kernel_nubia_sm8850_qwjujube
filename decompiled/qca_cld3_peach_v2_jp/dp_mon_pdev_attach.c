__int64 __fastcall dp_mon_pdev_attach(
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
  __int64 *v9; // x20
  __int64 (__fastcall *v11)(_QWORD); // x8
  size_t v12; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x21
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  __int64 v47; // x8
  __int64 v48; // x9
  _QWORD *v49; // x23
  unsigned int (__fastcall *v50)(_QWORD); // x9
  const char *v51; // x2
  unsigned int v52; // w19
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  __int64 v61; // x4
  __int64 v63; // x8
  __int64 v64; // x24
  __int64 (__fastcall *v65)(_QWORD); // x8
  unsigned int v66; // w0
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  __int64 (__fastcall *v75)(_QWORD); // x8
  double v76; // d0
  double v77; // d1
  double v78; // d2
  double v79; // d3
  double v80; // d4
  double v81; // d5
  double v82; // d6
  double v83; // d7
  void (__fastcall *v84)(_QWORD); // x8
  unsigned int (__fastcall *v85)(_QWORD); // x8
  double v86; // d0
  double v87; // d1
  double v88; // d2
  double v89; // d3
  double v90; // d4
  double v91; // d5
  double v92; // d6
  double v93; // d7
  unsigned int (__fastcall *v94)(_QWORD); // x8
  double v95; // d0
  double v96; // d1
  double v97; // d2
  double v98; // d3
  double v99; // d4
  double v100; // d5
  double v101; // d6
  double v102; // d7
  void (__fastcall *v103)(_QWORD); // x8
  __int64 v104; // x8
  __int64 v105; // x8
  __int64 v106; // x24
  void (__fastcall *v107)(_QWORD); // x8
  void (__fastcall *v108)(_QWORD); // x8
  __int64 v109; // x8
  unsigned int v110; // w9
  char v111; // w8
  char v112; // w9

  if ( a1 )
  {
    v9 = *(__int64 **)(a1 + 8);
    v11 = (__int64 (__fastcall *)(_QWORD))v9[184];
    if ( *((_DWORD *)v11 - 1) != -1391804861 )
      __break(0x8228u);
    v12 = v11(5);
    v21 = dp_context_alloc_mem((__int64)v9, 0xAu, v12, v13, v14, v15, v16, v17, v18, v19, v20);
    if ( !v21 )
    {
      v61 = a1;
      v52 = 2;
      qdf_trace_msg(
        0x92u,
        2u,
        "%s: %pK: MONITOR pdev allocation failed",
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        "dp_mon_pdev_attach",
        v61);
      return v52;
    }
    v30 = v21;
    wlan_minidump_log(v22, v23, v24, v25, v26, v27, v28, v29, v21, 39328, v9[2]);
    wlan_minidump_log(v31, v32, v33, v34, v35, v36, v37, v38, v9[2507], 456, v9[2]);
    v47 = *(_QWORD *)(a1 + 8);
    *(_QWORD *)(a1 + 95560) = v30;
    if ( !v47 || (v48 = *(_QWORD *)(v47 + 20056)) == 0 || (v49 = *(_QWORD **)(v48 + 416)) == nullptr )
    {
      v51 = "%s: %pK: Invalid monitor ops";
      goto LABEL_15;
    }
    v50 = (unsigned int (__fastcall *)(_QWORD))v49[9];
    if ( v50 )
    {
      if ( *((_DWORD *)v50 - 1) != -1116635294 )
        __break(0x8229u);
      if ( v50(a1) )
      {
        v51 = "%s: %pK: MONITOR pdev alloc failed";
LABEL_15:
        qdf_trace_msg(0x92u, 2u, v51, v39, v40, v41, v42, v43, v44, v45, v46, "dp_mon_pdev_attach", a1);
LABEL_16:
        *(_QWORD *)(a1 + 95560) = 0;
        dp_context_free_mem((__int64)v9, 0xAu, v30, v53, v54, v55, v56, v57, v58, v59, v60);
        return 2;
      }
      v47 = *(_QWORD *)(a1 + 8);
      if ( !v47 )
        goto LABEL_31;
    }
    v63 = *(_QWORD *)(v47 + 20056);
    if ( !v63 || (v64 = *(_QWORD *)(v63 + 416)) == 0 )
    {
LABEL_31:
      qdf_trace_msg(0x92u, 2u, "%s: mon_ops is NULL", v39, v40, v41, v42, v43, v44, v45, v46, "dp_mon_rings_alloc");
      goto LABEL_32;
    }
    v65 = *(__int64 (__fastcall **)(_QWORD))(v64 + 688);
    if ( v65 )
    {
      if ( *((_DWORD *)v65 - 1) != -1116635294 )
        __break(0x8228u);
      v66 = v65(a1);
      if ( v66 )
        goto LABEL_30;
    }
    v75 = *(__int64 (__fastcall **)(_QWORD))(v64 + 696);
    if ( v75 )
    {
      if ( *((_DWORD *)v75 - 1) != -1116635294 )
        __break(0x8228u);
      v66 = v75(a1);
      if ( v66 )
      {
LABEL_30:
        qdf_trace_msg(0x92u, 2u, "%s: error: %d", v67, v68, v69, v70, v71, v72, v73, v74, "dp_mon_rings_alloc", v66);
LABEL_32:
        qdf_trace_msg(
          0x92u,
          2u,
          "%s: %pK: MONITOR rings setup failed",
          v76,
          v77,
          v78,
          v79,
          v80,
          v81,
          v82,
          v83,
          "dp_mon_pdev_attach",
          a1);
LABEL_33:
        v84 = (void (__fastcall *)(_QWORD))v49[10];
        if ( v84 )
        {
          if ( *((_DWORD *)v84 - 1) != -1557217772 )
            __break(0x8228u);
          v84(a1);
        }
        goto LABEL_16;
      }
    }
    v85 = (unsigned int (__fastcall *)(_QWORD))v49[98];
    if ( v85 )
    {
      if ( *((_DWORD *)v85 - 1) != -1116635294 )
        __break(0x8228u);
      if ( v85(a1) )
      {
        qdf_trace_msg(
          0x92u,
          2u,
          "%s: %pK: dp_rx_pdev_mon_attach failed",
          v86,
          v87,
          v88,
          v89,
          v90,
          v91,
          v92,
          v93,
          "dp_mon_pdev_attach",
          a1);
LABEL_50:
        v104 = *(_QWORD *)(a1 + 8);
        if ( v104 && (v105 = *(_QWORD *)(v104 + 20056)) != 0 && (v106 = *(_QWORD *)(v105 + 416)) != 0 )
        {
          v107 = *(void (__fastcall **)(_QWORD))(v106 + 704);
          if ( v107 )
          {
            if ( *((_DWORD *)v107 - 1) != -1557217772 )
              __break(0x8228u);
            v107(a1);
          }
          v108 = *(void (__fastcall **)(_QWORD))(v106 + 712);
          if ( v108 )
          {
            if ( *((_DWORD *)v108 - 1) != -1557217772 )
              __break(0x8228u);
            v108(a1);
          }
        }
        else
        {
          qdf_trace_msg(0x92u, 2u, "%s: mon_ops is NULL", v53, v54, v55, v56, v57, v58, v59, v60, "dp_mon_rings_free");
        }
        goto LABEL_33;
      }
    }
    v94 = (unsigned int (__fastcall *)(_QWORD))v49[126];
    if ( v94 )
    {
      if ( *((_DWORD *)v94 - 1) != -1116635294 )
        __break(0x8228u);
      if ( v94(a1) )
      {
        qdf_trace_msg(
          0x92u,
          2u,
          "%s: %pK: dp_rx_pdev_mon_attach failed",
          v95,
          v96,
          v97,
          v98,
          v99,
          v100,
          v101,
          v102,
          "dp_mon_pdev_attach",
          a1);
        v103 = (void (__fastcall *)(_QWORD))v49[99];
        if ( v103 )
        {
          if ( *((_DWORD *)v103 - 1) != -1557217772 )
            __break(0x8228u);
          v103(a1);
        }
        goto LABEL_50;
      }
    }
    v109 = *(_QWORD *)(a1 + 8);
    *(_QWORD *)(a1 + 95560) = v30;
    v110 = hal_get_target_type(*(__int64 **)(v109 + 1128)) - 31;
    if ( v110 > 0xA )
    {
      v111 = 0;
      v112 = 4;
    }
    else
    {
      v111 = byte_A2BEC8[v110];
      v112 = byte_A2BED4[v110];
    }
    v52 = 0;
    *(_BYTE *)(v30 + 39275) = v111;
    *(_BYTE *)(v30 + 39276) = v112;
  }
  else
  {
    v52 = 2;
    qdf_trace_msg(0x92u, 2u, "%s: pdev is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "dp_mon_pdev_attach");
  }
  return v52;
}
