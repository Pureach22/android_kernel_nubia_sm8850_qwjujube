__int64 __fastcall qdf_dpt_dump_stats_debugfs(
        __int64 a1,
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
  unsigned __int16 v12; // w23
  __int64 *v13; // x8
  __int64 v14; // x9
  __int64 v15; // x10
  __int64 v16; // x10
  __int64 v17; // x9
  __int64 v18; // x9
  __int64 v19; // x10
  __int64 v20; // x8
  __int64 v21; // x11
  _QWORD *v22; // t2
  __int64 result; // x0
  const char *v24; // x7
  const char *v25; // x9
  int v26; // w25
  int v27; // w26
  int v28; // w21
  int v29; // w22
  int v30; // w27
  int v31; // w23
  int v32; // w28
  int v33; // w24
  int v34; // w20
  const char *v35; // x19
  const char *v36; // x0
  const char *v37; // x7
  unsigned int v38; // w0
  const char *v39; // x4
  const char *v40; // x7
  int v41; // w25
  const char *v42; // x26
  const char *v43; // x0
  const char *v44; // x7
  unsigned int v45; // w0
  unsigned __int64 v46; // x21
  unsigned __int64 v47; // x22
  int v48; // w8
  int v49; // w19
  __int64 *v50; // x8
  __int64 v51; // x9
  __int64 v52; // x10
  __int64 v53; // x10
  __int64 v54; // x9
  __int64 v55; // x9
  __int64 v56; // x10
  __int64 v57; // x8
  __int64 v58; // x11
  _QWORD *v59; // t2
  const char *v60; // x7
  const char *v61; // x3
  const char *v62; // x3
  const char *v63; // x7
  int v64; // [xsp+28h] [xbp-1C8h]
  unsigned __int16 v65; // [xsp+3Ch] [xbp-1B4h]
  __int64 v66; // [xsp+40h] [xbp-1B0h]
  unsigned int v67; // [xsp+54h] [xbp-19Ch]
  __int64 v68; // [xsp+58h] [xbp-198h]
  _QWORD v69[4]; // [xsp+60h] [xbp-190h] BYREF
  __int64 v70; // [xsp+80h] [xbp-170h]
  __int64 v71; // [xsp+88h] [xbp-168h]
  __int64 v72; // [xsp+90h] [xbp-160h]
  __int64 v73; // [xsp+98h] [xbp-158h]
  __int64 v74; // [xsp+A0h] [xbp-150h]
  __int64 v75; // [xsp+A8h] [xbp-148h]
  __int64 v76; // [xsp+B0h] [xbp-140h] BYREF
  __int64 v77; // [xsp+B8h] [xbp-138h]
  __int64 v78; // [xsp+C0h] [xbp-130h]
  __int64 v79; // [xsp+C8h] [xbp-128h]
  __int64 v80; // [xsp+D0h] [xbp-120h]
  __int64 v81; // [xsp+D8h] [xbp-118h]
  __int64 v82; // [xsp+E0h] [xbp-110h]
  __int64 v83; // [xsp+E8h] [xbp-108h]
  __int64 v84; // [xsp+F0h] [xbp-100h]
  __int64 v85; // [xsp+F8h] [xbp-F8h]
  __int64 v86; // [xsp+100h] [xbp-F0h]
  __int64 v87; // [xsp+108h] [xbp-E8h]
  int v88; // [xsp+110h] [xbp-E0h]
  __int64 v89; // [xsp+118h] [xbp-D8h] BYREF
  __int64 v90; // [xsp+120h] [xbp-D0h]
  __int64 v91; // [xsp+128h] [xbp-C8h]
  __int64 v92; // [xsp+130h] [xbp-C0h]
  __int64 v93; // [xsp+138h] [xbp-B8h]
  __int64 v94; // [xsp+140h] [xbp-B0h]
  __int64 v95; // [xsp+148h] [xbp-A8h]
  __int64 v96; // [xsp+150h] [xbp-A0h]
  __int64 v97; // [xsp+158h] [xbp-98h]
  __int64 v98; // [xsp+160h] [xbp-90h]
  __int64 v99; // [xsp+168h] [xbp-88h]
  __int64 v100; // [xsp+170h] [xbp-80h]
  __int64 v101; // [xsp+178h] [xbp-78h]
  __int64 v102; // [xsp+180h] [xbp-70h]
  __int64 v103; // [xsp+188h] [xbp-68h]
  __int64 v104; // [xsp+190h] [xbp-60h]
  __int64 v105; // [xsp+198h] [xbp-58h]
  __int64 v106; // [xsp+1A0h] [xbp-50h]
  __int64 v107; // [xsp+1A8h] [xbp-48h]
  __int64 v108; // [xsp+1B0h] [xbp-40h]
  __int64 v109; // [xsp+1B8h] [xbp-38h]
  __int64 v110; // [xsp+1C0h] [xbp-30h]
  __int64 v111; // [xsp+1C8h] [xbp-28h]
  _QWORD v112[4]; // [xsp+1D0h] [xbp-20h]

  v112[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v74 = 0;
  v75 = 0;
  v72 = 0;
  v73 = 0;
  v70 = 0;
  v71 = 0;
  memset(v69, 0, sizeof(v69));
  if ( (byte_73EC28 & 1) == 0 )
  {
    qdf_trace_msg(0x38u, 2u, "%s: Tracing Disabled", a3, a4, a5, a6, a7, a8, a9, a10, "qdf_dpt_dump_stats_debugfs");
    result = 16;
    goto LABEL_80;
  }
  if ( dword_73EC18 >= (unsigned int)(unsigned __int16)dword_73EC22 )
    v12 = dword_73EC22;
  else
    v12 = dword_73EC18;
  raw_spin_lock_bh(&l_dp_trace_lock);
  if ( a2 >= 0x7D1 )
LABEL_81:
    __break(0x5512u);
  v13 = (__int64 *)((char *)&g_qdf_dp_trace_tbl + 88 * a2);
  v14 = v13[8];
  v15 = v13[9];
  v75 = v13[10];
  v73 = v14;
  v74 = v15;
  v16 = v13[5];
  v69[3] = v13[4];
  v70 = v16;
  v17 = v13[7];
  v71 = v13[6];
  v72 = v17;
  v19 = *v13;
  v18 = v13[1];
  v22 = v13 + 2;
  v20 = v13[2];
  v21 = v22[1];
  v68 = v19;
  v69[0] = v18;
  v69[1] = v20;
  v69[2] = v21;
  raw_spin_unlock_bh(&l_dp_trace_lock);
  if ( *(_QWORD *)(a1 + 8) - *(_QWORD *)(a1 + 24) >= 0x12Cu )
  {
    v65 = v12;
    v66 = a1;
    do
    {
      v67 = a2;
      if ( LOBYTE(v69[0]) <= 9u )
      {
        if ( LOBYTE(v69[0]) > 5u )
        {
          if ( (unsigned int)LOBYTE(v69[0]) - 8 >= 2 )
          {
            if ( LOBYTE(v69[0]) != 6 )
              goto LABEL_49;
            goto LABEL_44;
          }
        }
        else if ( (unsigned int)LOBYTE(v69[0]) - 2 >= 3 )
        {
          if ( LOBYTE(v69[0]) != 5 )
            goto LABEL_49;
LABEL_44:
          LODWORD(v101) = 0;
          v99 = 0;
          v100 = 0;
          v97 = 0;
          v98 = 0;
          v95 = 0;
          v96 = 0;
          v93 = 0;
          v94 = 0;
          v91 = 0;
          v92 = 0;
          v89 = 0;
          v90 = 0;
          LODWORD(v78) = 0;
          v76 = 0;
          v77 = 0;
          scnprintf(&v76, 20, "%llu", v68);
          v40 = "Invalid";
          if ( (unsigned int)LOBYTE(v69[0]) - 1 <= 0x29 )
            v40 = off_9DE8C0[(unsigned __int8)(LOBYTE(v69[0]) - 1)];
          scnprintf(
            &v89,
            100,
            "%s DPT: %04d:%02d%s %s",
            (const char *)&unk_8B9E43,
            a2,
            (unsigned __int8)v75,
            (const char *)&v76,
            v40);
          v41 = BYTE1(v69[0]);
          v42 = "invalid";
          if ( BYTE2(v69[0]) <= 6uLL )
            v42 = off_9DE888[BYTE2(v69[0])];
          v43 = qdf_dp_subtype_to_str(BYTE3(v69[0]));
          qdf_debugfs_printf(a1, "%s [%d] [%s %s]\n", (const char *)&v89, v41, v42, v43);
          goto LABEL_61;
        }
        LODWORD(v101) = 0;
        v99 = 0;
        v100 = 0;
        v97 = 0;
        v98 = 0;
        v95 = 0;
        v96 = 0;
        v93 = 0;
        v94 = 0;
        v91 = 0;
        v92 = 0;
        v89 = 0;
        v90 = 0;
        LODWORD(v78) = 0;
        v76 = 0;
        v77 = 0;
        scnprintf(&v76, 20, "%llu", v68);
        v24 = "Invalid";
        if ( (unsigned int)LOBYTE(v69[0]) - 1 <= 0x29 )
          v24 = off_9DE8C0[(unsigned __int8)(LOBYTE(v69[0]) - 1)];
        scnprintf(
          &v89,
          100,
          "%s DPT: %04d:%02d%s %s",
          (const char *)&unk_8B9E43,
          a2,
          (unsigned __int8)v75,
          (const char *)&v76,
          v24);
        v25 = "invalid";
        v26 = BYTE1(v69[2]);
        v27 = BYTE1(v69[0]);
        v28 = BYTE2(v69[0]);
        v29 = BYTE3(v69[0]);
        v30 = BYTE6(v69[0]);
        v31 = HIBYTE(v69[0]);
        if ( BYTE5(v69[1]) == 1 )
          v25 = " <-- ";
        v32 = LOBYTE(v69[1]);
        v33 = BYTE1(v69[1]);
        v34 = BYTE4(v69[1]);
        if ( BYTE5(v69[1]) )
          v35 = v25;
        else
          v35 = " --> ";
        v36 = qdf_dp_subtype_to_str(BYTE3(v69[2]));
        v64 = v34;
        a1 = v66;
        qdf_debugfs_printf(
          v66,
          "%s [%d] [%s] SA: %02x:%02x:%02x:**:**:%02x %s DA: %02x:%02x:%02x:**:**:%02x",
          (const char *)&v89,
          v26,
          v36,
          v27,
          v28,
          v29,
          v30,
          v35,
          v31,
          v32,
          v33,
          v64);
        qdf_debugfs_printf(v66, "\n");
        v12 = v65;
      }
      else
      {
        if ( LOBYTE(v69[0]) > 0x1Du )
        {
          if ( (unsigned int)LOBYTE(v69[0]) - 36 >= 2 )
          {
            if ( LOBYTE(v69[0]) == 30 )
            {
              qdf_debugfs_printf(a1, "DPT: %04d: %llu %s\n", a2, v68, "CE: TX: FAST: ERR:");
              qdf_debugfs_printf(a1, "CE Fast Packet Error\n");
              goto LABEL_61;
            }
            if ( LOBYTE(v69[0]) == 44 )
            {
              qdf_debugfs_printf(
                a1,
                "%s: QDF_DP_TRACE_MAX event should not be generated\n",
                "qdf_dpt_dump_stats_debugfs");
              goto LABEL_61;
            }
LABEL_49:
            v88 = 0;
            v86 = 0;
            v87 = 0;
            v84 = 0;
            v85 = 0;
            v82 = 0;
            v83 = 0;
            v80 = 0;
            v81 = 0;
            v78 = 0;
            v79 = 0;
            v76 = 0;
            v77 = 0;
            LODWORD(v91) = 0;
            v89 = 0;
            v90 = 0;
            scnprintf(&v89, 20, "%llu", v68);
            v44 = "Invalid";
            if ( (unsigned int)LOBYTE(v69[0]) - 1 <= 0x29 )
              v44 = off_9DE8C0[(unsigned __int8)(LOBYTE(v69[0]) - 1)];
            v45 = scnprintf(
                    &v76,
                    100,
                    "%s DPT: %04d:%02d%s %s",
                    (const char *)&unk_8B9E43,
                    a2,
                    (unsigned __int8)v75,
                    (const char *)&v89,
                    v44);
            if ( v45 <= 0x63 )
              snprintf((char *)&v76 + v45, 100LL - v45, "[%d]", *(unsigned __int16 *)((char *)v69 + 1));
            v46 = BYTE3(v74);
            if ( BYTE3(v74) )
            {
              v47 = 0;
              v109 = 0;
              v110 = 0;
              *(_QWORD *)((char *)v112 + 7) = 0;
              v48 = BYTE3(v74);
              v111 = 0;
              v112[0] = 0;
              v107 = 0;
              v108 = 0;
              v105 = 0;
              v106 = 0;
              v103 = 0;
              v104 = 0;
              v101 = 0;
              v102 = 0;
              v99 = 0;
              v100 = 0;
              v97 = 0;
              v98 = 0;
              v95 = 0;
              v96 = 0;
              v93 = 0;
              v94 = 0;
              v91 = 0;
              v92 = 0;
              v89 = 0;
              v90 = 0;
              do
              {
                v49 = v48 - 16;
                if ( v48 >= 16 )
                  v48 = 16;
                hex_dump_to_buffer((char *)&v69[v47 / 8] + 1, v48, 16, 1, &v89, 199, 0);
                qdf_debugfs_printf(a1, "%s %s\n", (const char *)&v76, (const char *)&v89);
                v47 += 16LL;
                v48 = v49;
              }
              while ( v47 < v46 );
            }
            goto LABEL_61;
          }
          goto LABEL_35;
        }
        if ( LOBYTE(v69[0]) <= 0xBu )
        {
          if ( LOBYTE(v69[0]) == 10 )
          {
            qdf_debugfs_printf(a1, "DPT: %04d: %llu %s\n", a2, v68, "HDD: STA: TO:");
            qdf_debugfs_printf(a1, "HDD TX Timeout\n");
            goto LABEL_61;
          }
          if ( LOBYTE(v69[0]) == 11 )
          {
            qdf_debugfs_printf(a1, "DPT: %04d: %llu %s\n", a2, v68, "HDD: SAP: TO:");
            qdf_debugfs_printf(a1, "HDD SoftAP TX Timeout\n");
            goto LABEL_61;
          }
          goto LABEL_49;
        }
        if ( LOBYTE(v69[0]) != 12 )
        {
          if ( LOBYTE(v69[0]) != 21 )
            goto LABEL_49;
LABEL_35:
          v88 = 0;
          v86 = 0;
          v87 = 0;
          v84 = 0;
          v85 = 0;
          v82 = 0;
          v83 = 0;
          v80 = 0;
          v81 = 0;
          v78 = 0;
          v79 = 0;
          v76 = 0;
          v77 = 0;
          LODWORD(v91) = 0;
          v89 = 0;
          v90 = 0;
          scnprintf(&v89, 20, "%llu", v68);
          v37 = "Invalid";
          if ( (unsigned int)LOBYTE(v69[0]) - 1 <= 0x29 )
            v37 = off_9DE8C0[(unsigned __int8)(LOBYTE(v69[0]) - 1)];
          v38 = scnprintf(
                  &v76,
                  100,
                  "%s DPT: %04d:%02d%s %s",
                  (const char *)&unk_8B9E43,
                  a2,
                  (unsigned __int8)v75,
                  (const char *)&v89,
                  v37);
          if ( v38 <= 0x63 )
          {
            if ( LOBYTE(v69[0]) == 21 )
              v39 = "status";
            else
              v39 = "vdev_id";
            scnprintf(
              (char *)&v76 + v38,
              100LL - v38,
              "[msdu id %d %s %d]",
              *(unsigned __int16 *)((char *)&v69[1] + 1),
              v39,
              *(unsigned __int16 *)((char *)&v69[1] + 3));
          }
          *(_QWORD *)((char *)v112 + 7) = 0;
          v111 = 0;
          v112[0] = 0;
          v109 = 0;
          v110 = 0;
          v107 = 0;
          v108 = 0;
          v105 = 0;
          v106 = 0;
          v103 = 0;
          v104 = 0;
          v101 = 0;
          v102 = 0;
          v99 = 0;
          v100 = 0;
          v97 = 0;
          v98 = 0;
          v95 = 0;
          v96 = 0;
          v93 = 0;
          v94 = 0;
          v91 = 0;
          v92 = 0;
          v89 = 0;
          v90 = 0;
          hex_dump_to_buffer((char *)v69 + 1, 8, 16, 1, &v89, 199, 0);
          qdf_debugfs_printf(a1, "%s %s\n", (const char *)&v76, (const char *)&v89);
          goto LABEL_61;
        }
        LODWORD(v101) = 0;
        v99 = 0;
        v100 = 0;
        v97 = 0;
        v98 = 0;
        v95 = 0;
        v96 = 0;
        v93 = 0;
        v94 = 0;
        v91 = 0;
        v92 = 0;
        v89 = 0;
        v90 = 0;
        LODWORD(v78) = 0;
        v76 = 0;
        v77 = 0;
        scnprintf(&v76, 20, "%llu", v68);
        v60 = "Invalid";
        if ( (unsigned int)LOBYTE(v69[0]) - 1 <= 0x29 )
          v60 = off_9DE8C0[(unsigned __int8)(LOBYTE(v69[0]) - 1)];
        scnprintf(
          &v89,
          100,
          "%s DPT: %04d:%02d%s %s",
          (const char *)&unk_8B9E43,
          a2,
          (unsigned __int8)v75,
          (const char *)&v76,
          v60);
        if ( *(_DWORD *)((char *)v69 + 5) == 3 )
        {
          v61 = "invalid";
          if ( *(_DWORD *)((char *)v69 + 1) <= 4u )
            v61 = off_9DE848[*(unsigned int *)((char *)v69 + 1)];
          qdf_debugfs_printf(
            a1,
            "%s [%s] [T: %d G0: %d G1: %d]\n",
            (const char *)&v89,
            v61,
            *(_DWORD *)((char *)&v69[1] + 5),
            *(_DWORD *)((char *)&v69[2] + 1),
            *(_DWORD *)((char *)&v69[2] + 5));
        }
        else
        {
          v62 = "invalid";
          if ( *(_DWORD *)((char *)v69 + 1) <= 4u )
            v62 = off_9DE848[*(unsigned int *)((char *)v69 + 1)];
          v63 = "invalid";
          if ( *(_DWORD *)((char *)v69 + 5) <= 2u )
            v63 = off_9DE870[*(unsigned int *)((char *)v69 + 5)];
          qdf_debugfs_printf(
            a1,
            "%s [%s] [T: %d G0: %d G1: %d] [%s %d]\n",
            (const char *)&v89,
            v62,
            *(_DWORD *)((char *)&v69[1] + 5),
            *(_DWORD *)((char *)&v69[2] + 1),
            *(_DWORD *)((char *)&v69[2] + 5),
            v63,
            *(_DWORD *)((char *)&v69[1] + 1));
        }
      }
LABEL_61:
      ++HIWORD(dword_73EC22);
      if ( HIWORD(dword_73EC22) == v12 )
      {
        result = 0;
        HIWORD(dword_73EC22) = 0;
        goto LABEL_80;
      }
      raw_spin_lock_bh(&l_dp_trace_lock);
      if ( v67 )
        a2 = v67 - 1;
      else
        a2 = 1999;
      if ( a2 > 0x7D0 )
        goto LABEL_81;
      v50 = (__int64 *)((char *)&g_qdf_dp_trace_tbl + 88 * a2);
      v51 = v50[8];
      v52 = v50[9];
      v75 = v50[10];
      v73 = v51;
      v74 = v52;
      v53 = v50[5];
      v69[3] = v50[4];
      v70 = v53;
      v54 = v50[7];
      v71 = v50[6];
      v72 = v54;
      v56 = *v50;
      v55 = v50[1];
      v59 = v50 + 2;
      v57 = v50[2];
      v58 = v59[1];
      v68 = v56;
      v69[0] = v55;
      v69[1] = v57;
      v69[2] = v58;
      raw_spin_unlock_bh(&l_dp_trace_lock);
    }
    while ( *(_QWORD *)(a1 + 8) - *(_QWORD *)(a1 + 24) >= 0x12Cu );
  }
  raw_spin_lock_bh(&l_dp_trace_lock);
  dword_73EC2C = a2;
  raw_spin_unlock_bh(&l_dp_trace_lock);
  result = 16;
LABEL_80:
  _ReadStatusReg(SP_EL0);
  return result;
}
