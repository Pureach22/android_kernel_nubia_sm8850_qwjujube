__int64 __fastcall wlan_dp_lb_handler(
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
  __int64 result; // x0
  __int64 v11; // x1
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  char v20; // w8
  unsigned int v21; // w24
  unsigned int v22; // w20
  unsigned int v23; // w21
  unsigned __int64 v24; // x8
  unsigned __int64 v25; // x22
  __int64 v26; // x11
  __int64 v27; // x8
  _QWORD *v28; // x10
  int v29; // w9
  int v30; // w12
  unsigned __int64 v31; // x25
  unsigned int v32; // w9
  unsigned __int8 v33; // w26
  __int64 v34; // x27
  unsigned int v35; // w28
  unsigned int v36; // w5
  unsigned int v37; // w6
  unsigned int v38; // w7
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  __int64 **v47; // x0
  __int64 v48; // x8
  void (*v49)(void); // x8
  int v50; // w25
  bool v51; // w20
  unsigned __int64 v52; // x16
  int *v53; // x27
  int v54; // w4
  int v55; // w8
  int v56; // w9
  int v57; // w12
  int v58; // w10
  int v59; // w11
  int v60; // w14
  int v61; // w15
  int v62; // w13
  unsigned int v63; // w24
  int v64; // w8
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  int v73; // w5
  int v74; // w10
  int v75; // w11
  unsigned __int64 v76; // x8
  unsigned __int64 v77; // x20
  _QWORD *v78; // x28
  bool v80; // w8
  unsigned __int64 v81; // x10
  char *v82; // x27
  unsigned __int64 v83; // x25
  bool v85; // w24
  double v86; // d0
  double v87; // d1
  double v88; // d2
  double v89; // d3
  double v90; // d4
  double v91; // d5
  double v92; // d6
  double v93; // d7
  __int64 **v94; // x0
  __int64 v95; // x8
  __int64 (*v96)(void); // x8
  int v97; // w0
  unsigned __int64 v98; // x8
  int v99; // w10
  int v100; // w8
  __int64 v101; // x0
  __int64 v102; // x1
  __int64 v103; // x0
  double v104; // d0
  double v105; // d1
  double v106; // d2
  double v107; // d3
  double v108; // d4
  double v109; // d5
  double v110; // d6
  double v111; // d7
  int v112; // [xsp+8h] [xbp-1A8h]
  bool v113; // [xsp+1Ch] [xbp-194h]
  int v114; // [xsp+28h] [xbp-188h]
  __int64 v115; // [xsp+30h] [xbp-180h]
  __int64 v116; // [xsp+40h] [xbp-170h]
  __int64 v117; // [xsp+48h] [xbp-168h]
  __int64 v118; // [xsp+50h] [xbp-160h]
  __int64 v119; // [xsp+58h] [xbp-158h]
  _QWORD v120[32]; // [xsp+60h] [xbp-150h] BYREF
  __int64 v121; // [xsp+160h] [xbp-50h] BYREF
  __int64 v122; // [xsp+168h] [xbp-48h]
  __int64 v123; // [xsp+170h] [xbp-40h]
  __int64 v124; // [xsp+178h] [xbp-38h]
  __int64 v125; // [xsp+180h] [xbp-30h]
  __int64 v126; // [xsp+188h] [xbp-28h]
  __int64 v127; // [xsp+190h] [xbp-20h]
  __int64 v128; // [xsp+198h] [xbp-18h]
  __int64 v129; // [xsp+1A0h] [xbp-10h]

  v129 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v127 = 0;
  v128 = 0;
  v125 = 0;
  v126 = 0;
  v123 = 0;
  v124 = 0;
  v121 = 0;
  v122 = 0;
  memset(v120, 0, sizeof(v120));
  v118 = 0;
  v119 = 0;
  v116 = 0;
  v117 = 0;
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: cpu mask for load balance %*pbl ",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "wlan_dp_lb_handler",
    nr_cpu_ids,
    a1 + 2856);
  result = qdf_cpumask_weight((unsigned int *)(a1 + 2856));
  if ( (unsigned int)result >= 2 )
  {
    v115 = sched_clock(result, v11);
    raw_spin_lock(a1 + 2880);
    v20 = 0;
    v21 = 0;
    v22 = 0;
    v23 = 0;
    do
    {
      v24 = (unsigned int)(-1LL << v20) & _cpu_online_mask;
      if ( !(_DWORD)v24 )
        break;
      v25 = __clz(__rbit64(v24));
      if ( (unsigned int)qdf_cpumask_test_cpu(v25, a1 + 2856) )
      {
        if ( v23 > 0x20 )
          goto LABEL_106;
        if ( ((8LL * v23) | 4uLL) > 0x100
          || (v26 = v23,
              v27 = a1 + 1560 + 40LL * (unsigned int)v25,
              v28 = &v120[v26],
              v29 = *(unsigned __int8 *)(v27 + 36),
              BYTE4(v120[v26]) = v29,
              ((v26 * 8) | 5uLL) > 0x100)
          || (v30 = *(unsigned __int8 *)(v27 + 37), *((_BYTE *)v28 + 5) = v30, ((v26 * 8) | 6uLL) > 0x100) )
        {
LABEL_105:
          __break(1u);
LABEL_106:
          __break(0x5512u);
        }
        v22 += v29;
        v21 += v30;
        ++v23;
        *((_BYTE *)v28 + 6) = *(_DWORD *)(v27 + 32);
      }
      v20 = v25 + 1;
    }
    while ( v25 < 0x1F );
    v31 = 0;
    if ( v23 <= 1 )
      v32 = 1;
    else
      v32 = v23;
    v33 = 0;
    v34 = 8LL * v32;
    v35 = (unsigned __int8)(v22 / v23);
    do
    {
      if ( v31 == 264 )
        goto LABEL_106;
      if ( v31 + 4 > 0x100 || v31 + 5 > 0x100 )
        goto LABEL_105;
      v36 = BYTE4(v120[v31 / 8]);
      v37 = BYTE5(v120[v31 / 8]);
      if ( v36 > v37 )
        v33 = v36 - v37;
      v38 = v35 <= v33 ? 0 : 100 * (v35 - v33) / v21;
      if ( v31 > 0xFF )
        goto LABEL_105;
      LODWORD(v120[v31 / 8]) = v38;
      if ( v31 + 6 > 0x100 )
        goto LABEL_105;
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: cpu %d TL %d WL %d AW %d",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "wlan_dp_lb_handler",
        BYTE6(v120[v31 / 8]));
      v31 += 8LL;
    }
    while ( v34 != v31 );
    qdf_sort();
    v47 = *(__int64 ***)(a1 + 240);
    if ( v47 )
    {
      v48 = **v47;
      if ( v48 )
      {
        v49 = *(void (**)(void))(v48 + 952);
        if ( v49 )
        {
          if ( *((_DWORD *)v49 - 1) != 1828237104 )
            __break(0x8228u);
          v49();
        }
      }
    }
    else
    {
      qdf_trace_msg(
        0x89u,
        8u,
        "%s: Invalid Instance",
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        "cdp_get_per_ring_pkt_avg");
    }
    v50 = 0;
    v51 = 1;
    BYTE4(v121) = 0;
    BYTE4(v122) = 1;
    LODWORD(v121) = 100 * (int)v116 / 0u;
    BYTE4(v123) = 2;
    BYTE4(v124) = 3;
    BYTE4(v125) = 4;
    BYTE4(v126) = 5;
    BYTE4(v127) = 6;
    BYTE4(v128) = 7;
    LODWORD(v122) = 100 * HIDWORD(v116) / 0u;
    LODWORD(v123) = 100 * (int)v117 / 0u;
    LODWORD(v124) = 100 * HIDWORD(v117) / 0u;
    LODWORD(v125) = 100 * (int)v118 / 0u;
    LODWORD(v126) = 100 * HIDWORD(v118) / 0u;
    LODWORD(v127) = 100 * (int)v119 / 0u;
    LODWORD(v128) = 100 * HIDWORD(v119) / 0u;
    do
    {
      if ( ((8LL * v50) | 6uLL) > 0x100 )
        goto LABEL_105;
      v52 = v50;
      v53 = (int *)&v120[v52];
      v54 = BYTE6(v120[v52]);
      if ( *(unsigned __int8 *)(a1 + 2915) == v54 )
        v55 = v121;
      else
        v55 = 0;
      if ( *(unsigned __int8 *)(a1 + 2916) == v54 )
        v56 = v122;
      else
        v56 = 0;
      v57 = v125;
      if ( *(unsigned __int8 *)(a1 + 2917) == v54 )
        v58 = v123;
      else
        v58 = 0;
      if ( *(unsigned __int8 *)(a1 + 2918) == v54 )
        v59 = v124;
      else
        v59 = 0;
      v60 = v126;
      if ( *(unsigned __int8 *)(a1 + 2919) != v54 )
        v57 = 0;
      if ( *(unsigned __int8 *)(a1 + 2920) != v54 )
        v60 = 0;
      v61 = *(unsigned __int8 *)(a1 + 2921) == v54 ? v127 : 0;
      v62 = *(unsigned __int8 *)(a1 + 2922) == v54 ? v128 : 0;
      if ( v52 > 32 || v50 == 32 )
        goto LABEL_105;
      v63 = v56 + v55 + v58 + v59 + v57 + v60 + v61 + v62;
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: CPU%d CWW:%d AWW:%d",
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        "wlan_dp_is_load_balance_needed");
      v64 = *v53;
      if ( v63 | *v53 && (v64 - 10 > v63 || v64 + 10 < v63) )
        break;
      v51 = ++v50 < v23;
    }
    while ( v23 != v50 );
    if ( v51 && (*(_BYTE *)(a1 + 218) & 1) != 0 )
    {
      qdf_sort();
      v73 = v121;
      v74 = 0;
      v75 = 0;
LABEL_66:
      v76 = v74;
      v112 = v74;
      v77 = (v76 * 8) | 6;
      v78 = &v120[v76];
      v80 = v76 > 32 || v74 == 32;
      v113 = v80;
LABEL_73:
      v114 = v75;
      if ( v73 )
      {
        v81 = 8LL * v75;
        v82 = (char *)&v121 + v81;
        v83 = v81 | 4;
        v85 = v81 > 0x40 || v75 == 8;
        do
        {
          if ( v83 > 0x40 || v77 > 0x100 )
            goto LABEL_105;
          qdf_trace_msg(
            0x45u,
            5u,
            "%s: Applying ring%d weight %d on cpu%d",
            v65,
            v66,
            v67,
            v68,
            v69,
            v70,
            v71,
            v72,
            "wlan_dp_lb_irq_balance_handler",
            (unsigned __int8)v82[4]);
          v94 = *(__int64 ***)(a1 + 240);
          if ( v94 )
          {
            v95 = **v94;
            if ( v95 )
            {
              v96 = *(__int64 (**)(void))(v95 + 960);
              if ( v96 )
              {
                if ( *((_DWORD *)v96 - 1) != 2077786039 )
                  __break(0x8228u);
                v97 = v96();
                if ( (v97 & 0x80000000) == 0 )
                {
                  hif_check_and_apply_irq_affinity(*(_QWORD *)(a1 + 248), v97, *((unsigned __int8 *)v78 + 6));
                  v98 = (unsigned __int8)v82[4];
                  if ( v98 >= 8 )
                    goto LABEL_106;
                  *(_BYTE *)(a1 + 2915 + v98) = *((_BYTE *)v78 + 6);
                  if ( (unsigned __int64)(8LL * v114) > 0x40 || v113 )
                    goto LABEL_105;
                  v99 = v114 + 1;
                  v100 = *(_DWORD *)v78 - *(_DWORD *)v82;
                  *(_DWORD *)v78 = v100;
                  if ( v114 + 1 > 7 )
                    break;
                  v75 = v114 + 1;
                  if ( (unsigned __int64)(8LL * v99) > 0x40 )
                    goto LABEL_105;
                  v73 = *((_DWORD *)&v121 + 2 * v99);
                  if ( v100 + 5 < v73 )
                  {
                    if ( v112 + 1 < v23 )
                      v74 = v112 + 1;
                    else
                      v74 = 0;
                    goto LABEL_66;
                  }
                  goto LABEL_73;
                }
              }
            }
          }
          else
          {
            qdf_trace_msg(
              0x89u,
              8u,
              "%s: Invalid Instance",
              v86,
              v87,
              v88,
              v89,
              v90,
              v91,
              v92,
              v93,
              "cdp_get_ext_grp_id_from_reo_num");
          }
          qdf_trace_msg(
            0x45u,
            2u,
            "%s: failed to get grp id",
            v86,
            v87,
            v88,
            v89,
            v90,
            v91,
            v92,
            v93,
            "wlan_dp_lb_irq_balance_handler");
          if ( v85 )
            goto LABEL_105;
        }
        while ( *(_DWORD *)v82 );
      }
    }
    else
    {
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: load balance is not needed",
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        "wlan_dp_lb_handler");
    }
    v101 = raw_spin_unlock(a1 + 2880);
    v103 = sched_clock(v101, v102);
    *(_QWORD *)(a1 + 2904) = v103;
    *(_BYTE *)(a1 + 2913) = 0;
    result = qdf_trace_msg(
               0x45u,
               5u,
               "%s: Total time taken for load balance %lluns",
               v104,
               v105,
               v106,
               v107,
               v108,
               v109,
               v110,
               v111,
               "wlan_dp_lb_handler",
               v103 - v115);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
