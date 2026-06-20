__int64 __fastcall policy_mgr_decr_connection_count(__int64 a1, unsigned int a2)
{
  __int64 context; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x19
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  char *v21; // x8
  unsigned int v22; // w9
  char *v23; // x10
  __int64 v24; // x14
  char *v25; // x12
  char v26; // w13
  __int64 v27; // x13
  int v28; // w10
  char *v29; // x11
  __int64 v30; // x14
  char *v31; // x9
  char v32; // w13
  __int64 v33; // x13
  int v34; // w11
  char *v35; // x11
  __int64 v36; // x14
  char *v37; // x10
  char v38; // w13
  __int64 v39; // x13
  int v40; // w11
  __int64 v41; // x12
  char *v42; // x9
  char v43; // w11
  __int64 v44; // x11
  int v45; // w10
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  unsigned int pidx; // w20
  unsigned int i; // w21
  __int64 v64; // x0
  void (__fastcall *v65)(_QWORD); // x8

  context = policy_mgr_get_context(a1);
  if ( context )
  {
    v12 = context;
    qdf_mutex_acquire(context + 56);
    if ( BYTE4(qword_8D4F00) == 1 )
    {
      if ( (_DWORD)qword_8D4F00 == a2 )
      {
        v21 = nullptr;
        goto LABEL_5;
      }
      if ( BYTE4(qword_8D4F24) == 1 )
      {
        if ( (_DWORD)qword_8D4F24 == a2 )
        {
          v21 = (_BYTE *)(&off_0 + 1);
          goto LABEL_5;
        }
        if ( BYTE4(qword_8D4F48) == 1 )
        {
          if ( (_DWORD)qword_8D4F48 == a2 )
          {
            v21 = (_BYTE *)(&off_0 + 2);
            goto LABEL_5;
          }
          if ( BYTE4(qword_8D4F6C) == 1 )
          {
            if ( (_DWORD)qword_8D4F6C == a2 )
            {
              v21 = (_BYTE *)(&off_0 + 3);
LABEL_5:
              v22 = (_DWORD)v21 + 1;
              v23 = (char *)&pm_conc_connection_list + 36 * (unsigned int)((_DWORD)v21 + 1);
              if ( v23[28] != 1 )
              {
LABEL_22:
                qdf_mem_set((char *)&pm_conc_connection_list + 36 * (unsigned int)v21, 0x24u, 0);
                if ( (qword_8D4F00 & 0x100000000LL) != 0
                  && ((_DWORD)qword_8D4F00 == a2
                   || BYTE4(qword_8D4F24) == 1
                   && ((_DWORD)qword_8D4F24 == a2
                    || BYTE4(qword_8D4F48) == 1
                    && ((_DWORD)qword_8D4F48 == a2
                     || BYTE4(qword_8D4F6C) == 1
                     && ((_DWORD)qword_8D4F6C == a2 || BYTE4(qword_8D4F90) == 1 && (_DWORD)qword_8D4F90 == a2)))) )
                {
                  qdf_mutex_release(v12 + 56);
                  qdf_trace_msg(
                    0x4Fu,
                    2u,
                    "%s: dup entry occur",
                    v46,
                    v47,
                    v48,
                    v49,
                    v50,
                    v51,
                    v52,
                    v53,
                    "policy_mgr_decr_connection_count");
                  qdf_trace_msg(
                    0x4Fu,
                    2u,
                    "%s: fatal error detected to flush and pause host log",
                    v54,
                    v55,
                    v56,
                    v57,
                    v58,
                    v59,
                    v60,
                    v61,
                    "policy_mgr_debug_alert");
                  qdf_logging_flush_logs();
                  pidx = qdf_get_pidx();
                  for ( i = 0; i != 167; ++i )
                    v64 = ((__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD, _QWORD))qdf_print_set_category_verbose)(
                            pidx,
                            i,
                            0,
                            0);
                  v65 = *(void (__fastcall **)(_QWORD))(v12 + 536);
                  if ( !v65 )
                    return 0;
                }
                else
                {
                  v64 = qdf_mutex_release(v12 + 56);
                  v65 = *(void (__fastcall **)(_QWORD))(v12 + 536);
                  if ( !v65 )
                    return 0;
                }
                if ( *((_DWORD *)v65 - 1) != -440107680 )
                  __break(0x8228u);
                v65(v64);
                return 0;
              }
              v24 = *(_QWORD *)v23;
              v25 = (char *)&pm_conc_connection_list + 36 * (unsigned int)v21;
              *((_DWORD *)v25 + 6) = *((_DWORD *)v23 + 6);
              v26 = v23[12];
              *(_QWORD *)v25 = v24;
              LODWORD(v24) = *((_DWORD *)v23 + 2);
              v25[12] = v26;
              v27 = *((_QWORD *)v23 + 2);
              *((_DWORD *)v25 + 2) = v24;
              *((_QWORD *)v25 + 2) = v27;
              LOWORD(v27) = *((_WORD *)v23 + 15);
              v28 = *((_DWORD *)v23 + 8);
              v25[28] = 1;
              *((_WORD *)v25 + 15) = v27;
              *((_DWORD *)v25 + 8) = v28;
              if ( v21 != (_BYTE *)&off_0 + 3 )
              {
                v29 = (char *)&pm_conc_connection_list + 36 * (unsigned int)((_DWORD)v21 + 2);
                if ( v29[28] == 1 )
                {
                  v30 = *(_QWORD *)v29;
                  v31 = (char *)&pm_conc_connection_list + 36 * v22;
                  *((_DWORD *)v31 + 6) = *((_DWORD *)v29 + 6);
                  v32 = v29[12];
                  *(_QWORD *)v31 = v30;
                  LODWORD(v30) = *((_DWORD *)v29 + 2);
                  v31[12] = v32;
                  v33 = *((_QWORD *)v29 + 2);
                  *((_DWORD *)v31 + 2) = v30;
                  *((_QWORD *)v31 + 2) = v33;
                  LOWORD(v33) = *((_WORD *)v29 + 15);
                  v34 = *((_DWORD *)v29 + 8);
                  v31[28] = 1;
                  *((_WORD *)v31 + 15) = v33;
                  *((_DWORD *)v31 + 8) = v34;
                  if ( v21 == (_BYTE *)&off_0 + 2 )
                    goto LABEL_7;
                  v22 = (_DWORD)v21 + 3;
                  v35 = (char *)&pm_conc_connection_list + 36 * (unsigned int)((_DWORD)v21 + 3);
                  if ( v35[28] != 1 )
                  {
                    LODWORD(v21) = (_DWORD)v21 + 2;
                    goto LABEL_22;
                  }
                  v36 = *(_QWORD *)v35;
                  v37 = (char *)&pm_conc_connection_list + 36 * (unsigned int)((_DWORD)v21 + 2);
                  *((_DWORD *)v37 + 6) = *((_DWORD *)v35 + 6);
                  v38 = v35[12];
                  *(_QWORD *)v37 = v36;
                  LODWORD(v36) = *((_DWORD *)v35 + 2);
                  v37[12] = v38;
                  v39 = *((_QWORD *)v35 + 2);
                  *((_DWORD *)v37 + 2) = v36;
                  *((_QWORD *)v37 + 2) = v39;
                  LOWORD(v39) = *((_WORD *)v35 + 15);
                  v40 = *((_DWORD *)v35 + 8);
                  v37[28] = 1;
                  *((_WORD *)v37 + 15) = v39;
                  *((_DWORD *)v37 + 8) = v40;
                  if ( v21 == (_BYTE *)&off_0 + 1 )
                    goto LABEL_7;
                  v21 = (char *)&pm_conc_connection_list + 36 * ((unsigned int)v21 | 4);
                  if ( v21[28] == 1 )
                  {
                    v41 = *(_QWORD *)v21;
                    v42 = (char *)&pm_conc_connection_list + 36 * v22;
                    *((_DWORD *)v42 + 6) = *((_DWORD *)v21 + 6);
                    v43 = v21[12];
                    *(_QWORD *)v42 = v41;
                    LODWORD(v41) = *((_DWORD *)v21 + 2);
                    v42[12] = v43;
                    v44 = *((_QWORD *)v21 + 2);
                    v42[28] = 1;
                    v45 = *((_DWORD *)v21 + 8);
                    *((_QWORD *)v42 + 2) = v44;
                    LOWORD(v44) = *((_WORD *)v21 + 15);
                    LODWORD(v21) = 4;
                    *((_DWORD *)v42 + 2) = v41;
                    *((_WORD *)v42 + 15) = v44;
                    *((_DWORD *)v42 + 8) = v45;
                    goto LABEL_22;
                  }
                }
                LODWORD(v21) = v22;
                goto LABEL_22;
              }
LABEL_7:
              LODWORD(v21) = 4;
              goto LABEL_22;
            }
            if ( BYTE4(qword_8D4F90) == 1 && (_DWORD)qword_8D4F90 == a2 )
              goto LABEL_7;
          }
        }
      }
    }
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: can't find vdev_id %d in pm_conc_connection_list",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "policy_mgr_decr_connection_count",
      a2);
    qdf_mutex_release(v12 + 56);
  }
  else
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid Context",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "policy_mgr_decr_connection_count");
  }
  return 16;
}
