__int64 __fastcall cam_ife_mgr_acquire_hw_for_offline_ctx(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x27
  _BYTE *v5; // x26
  unsigned int v10; // w0
  __int64 v11; // x6
  const char *v12; // x3
  const char *v13; // x5
  unsigned int v14; // w19
  __int64 v15; // x4
  const char *v16; // x5
  __int64 v17; // x4
  __int64 result; // x0
  unsigned int v19; // w0
  __int64 v20; // x8
  int v21; // w23
  int v22; // w25
  __int64 v23; // x1
  unsigned int v24; // w0
  unsigned int v25; // w0
  __int64 v26; // x2
  _QWORD *v27; // x24
  _QWORD *v28; // x23
  _QWORD *v29; // x8
  __int64 v30; // x9
  __int64 v31; // x8
  __int64 v32; // x8
  __int64 v33; // x8
  int v34; // w0
  __int64 v35; // x8
  char v36; // w10
  unsigned int v37; // w11
  __int64 v38; // x8
  __int64 v39; // x2
  _QWORD *v40; // x1
  _QWORD *v41; // x1
  __int64 v42; // x25
  __int64 v43; // x9
  _QWORD *v44; // x10
  __int64 v45; // x11
  __int64 v46; // x10
  char v47; // w11
  __int64 v48; // x10
  __int64 v49; // x8
  __int64 v50; // x8
  __int64 v51; // x8
  __int64 v52; // x8
  __int64 (__fastcall *v53)(__int64, __int64 *, __int64); // x9
  __int64 v54; // x0
  unsigned int v55; // w0
  unsigned int v56; // w20
  _QWORD *v57; // x1
  __int64 v58; // x6
  const char *v59; // x5
  __int64 v60; // x4
  __int64 v61; // x9
  char v62; // w8
  _DWORD *v63; // x1
  __int64 v64; // x2
  _QWORD *v65; // x8
  __int64 v66; // x8
  __int64 v67; // x8
  __int64 (__fastcall *v68)(__int64, __int64 *, __int64); // x9
  __int64 v69; // x0
  unsigned int v70; // w0
  __int64 v71; // x9
  unsigned int v72; // w0
  unsigned int v73; // w23
  unsigned int v74; // w0
  unsigned int v75; // w0
  __int64 v76; // [xsp+18h] [xbp-88h] BYREF
  __int64 v77; // [xsp+20h] [xbp-80h]
  __int64 v78; // [xsp+28h] [xbp-78h]
  __int64 (__fastcall *v79)(); // [xsp+30h] [xbp-70h]
  __int64 v80; // [xsp+38h] [xbp-68h]
  __int64 v81; // [xsp+40h] [xbp-60h]
  __int64 v82; // [xsp+48h] [xbp-58h]
  __int64 v83; // [xsp+50h] [xbp-50h]
  __int64 v84; // [xsp+58h] [xbp-48h]
  __int64 v85; // [xsp+60h] [xbp-40h]
  __int64 v86; // [xsp+68h] [xbp-38h]
  __int64 v87; // [xsp+70h] [xbp-30h]
  __int64 (__fastcall *v88)(); // [xsp+78h] [xbp-28h]
  __int64 v89; // [xsp+80h] [xbp-20h]
  __int64 v90; // [xsp+88h] [xbp-18h]
  __int64 v91; // [xsp+90h] [xbp-10h]
  __int64 v92; // [xsp+98h] [xbp-8h]

  v5 = (_BYTE *)(a1 + 0x2000);
  v92 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *(_BYTE *)(a1 + 9379) = *(_DWORD *)(a2 + 80) != 0;
  if ( !*(_DWORD *)(a2 + 164) && !*(_DWORD *)(a2 + 180) || !*(_DWORD *)(a2 + 184) )
  {
    v16 = "Invalid %d BUS RD %d PIX %d LCR ports for FE ctx: %u";
    v17 = 5723;
    goto LABEL_11;
  }
  if ( *(_QWORD *)(a2 + 168) )
  {
    v16 = "%d RDI %d PPP ports invalid for FE ctx_idx: %u";
    v17 = 5730;
LABEL_11:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_mgr_acquire_hw_for_offline_ctx",
      v17,
      v16);
    result = 4294967274LL;
    goto LABEL_15;
  }
  if ( *(_DWORD *)(a1 + 9312) != 2 )
  {
    v19 = cam_ife_hw_mgr_acquire_res_ife_bus_rd();
    if ( v19 )
    {
      v11 = *(unsigned int *)(a1 + 56);
      v12 = "cam_ife_mgr_acquire_hw_ife_offline";
      v13 = "Acquire IFE BUS RD resource Failed, ctx_idx: %u";
      v14 = v19;
      v15 = 5672;
    }
    else
    {
      v23 = a2;
      if ( *(_DWORD *)(a2 + 164)
        && (v24 = cam_ife_hw_mgr_acquire_offline_res_ife_camif(a1, a2, 0, a3, a4), v23 = a2, v24) )
      {
        v11 = *(unsigned int *)(a1 + 56);
        v12 = "cam_ife_mgr_acquire_hw_ife_offline";
        v13 = "Acquire IFE IPP SRC resource Failed, ctx_idx: %u";
        v14 = v24;
        v15 = 5682;
      }
      else if ( *(_DWORD *)(v23 + 180)
             && (v25 = cam_ife_hw_mgr_acquire_offline_res_ife_camif(a1, a2, 1, a3, a4), v23 = a2, v25) )
      {
        v11 = *(unsigned int *)(a1 + 56);
        v12 = "cam_ife_mgr_acquire_hw_ife_offline";
        v13 = "Acquire IFE LCR SRC resource Failed, ctx_idx: %u";
        v14 = v25;
        v15 = 5692;
      }
      else
      {
        result = cam_ife_hw_mgr_acquire_res_ife_out(a1, v23);
        if ( !(_DWORD)result )
          goto LABEL_15;
        v11 = *(unsigned int *)(a1 + 56);
        v12 = "cam_ife_mgr_acquire_hw_ife_offline";
        v13 = "Acquire IFE OUT resource Failed, ctx_idx: %u";
        v14 = result;
        v15 = 5699;
      }
    }
    goto LABEL_14;
  }
  v10 = cam_ife_hw_mgr_acquire_sfe_bus_rd();
  if ( v10 )
  {
    v11 = *(unsigned int *)(a1 + 56);
    v12 = "cam_ife_mgr_acquire_hw_sfe_offline";
    v13 = "Acquire SFE BUS RD resource Failed, ctx_idx: %u";
    v14 = v10;
    v15 = 5593;
LABEL_14:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      8,
      1,
      v12,
      v15,
      v13,
      v11);
    result = v14;
    goto LABEL_15;
  }
  v20 = *(_QWORD *)(a1 + 256);
  if ( v20 )
  {
    v21 = *(_DWORD *)(v20 + 20);
    if ( v21 == 20481 )
    {
      v22 = 0;
    }
    else
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_ife_hw_mgr_get_csid_rdi_type_for_offline",
        1599,
        "maximum rdi output type exceeded 0x%x",
        v21);
      v22 = 12;
    }
    v26 = a2;
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_ife_hw_mgr_get_csid_rdi_type_for_offline",
        1604,
        "out_port: %x path_id: %d",
        v21,
        v22);
      v26 = a2;
    }
    if ( v21 == 20481 )
    {
      v27 = *(_QWORD **)(a1 + 288);
      v28 = (_QWORD *)(a1 + 288);
      if ( v27 == (_QWORD *)(a1 + 288) )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          8,
          1,
          "cam_ife_hw_mgr_get_res",
          2078,
          "No more free ife hw mgr ctx");
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_ife_hw_mgr_acquire_offline_res_csid",
          5529,
          "No more free hw mgr resource, ctx_idx: %u",
          *(_DWORD *)(a1 + 56));
        LODWORD(v4) = -1;
      }
      else
      {
        v29 = (_QWORD *)v27[1];
        if ( (_QWORD *)*v29 == v27 && (v30 = *v27, *(_QWORD **)(*v27 + 8LL) == v27) )
        {
          *(_QWORD *)(v30 + 8) = v29;
          *v29 = v30;
        }
        else
        {
          _list_del_entry_valid_or_report(*(_QWORD *)(a1 + 288));
          v26 = a2;
        }
        *v27 = v27;
        v27[1] = v27;
        LODWORD(v76) = 3;
        HIDWORD(v76) = v22;
        v31 = *(_QWORD *)(v26 + 224);
        v83 = 0;
        v84 = 0;
        v77 = v26;
        v78 = v31;
        v32 = *(_QWORD *)(a1 + 16);
        v86 = 0;
        v87 = 0;
        v84 = v32;
        v85 = 0;
        v33 = *(_QWORD *)(a1 + 8728);
        v89 = 0;
        v87 = v33;
        v88 = cam_ife_hw_mgr_event_handler;
        v81 = 0;
        v82 = 0;
        v79 = nullptr;
        v80 = 0;
        v90 = a1;
        v91 = 0;
        BYTE3(v83) = 1;
        v34 = cam_ife_hw_mgr_acquire_csid_hw(a1, &v76);
        if ( !v34 )
        {
          v35 = v81;
          if ( v81 )
          {
            v27[4] = v81;
            if ( !*(_QWORD *)(a1 + 9336) && v85 )
              *(_QWORD *)(a1 + 9336) = v85;
            v36 = BYTE3(v91);
            v37 = HIDWORD(v76);
            v5[1192] = BYTE4(v83);
            v5[1208] = v36;
            *((_DWORD *)v27 + 4) = 3;
            *(_QWORD *)((char *)v27 + 20) = v37;
            v27[4] = v35;
            v27[5] = 0;
            *(_DWORD *)(a1 + 60) = *(_DWORD *)(*(_QWORD *)(v35 + 16) + 4LL);
            v38 = a2;
            if ( v27 )
            {
              v39 = a1 + 208;
              v40 = *(_QWORD **)(a1 + 216);
              if ( v27 == (_QWORD *)(a1 + 208) || v40 == v27 || *v40 != v39 )
              {
                _list_add_valid_or_report(v27);
                v38 = a2;
              }
              else
              {
                *(_QWORD *)(a1 + 216) = v27;
                *v27 = v39;
                v27[1] = v40;
                *v40 = v27;
              }
            }
            goto LABEL_57;
          }
        }
        LODWORD(v4) = v34;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_ife_hw_mgr_acquire_offline_res_csid",
          5552,
          "CSID Path reserve failed  rc=%d res_id=%d ctx_idx: %u",
          v34,
          v22,
          *(_DWORD *)(a1 + 56));
        v38 = a2;
        if ( v27 )
        {
          v41 = *(_QWORD **)(a1 + 296);
          if ( v41 == v27 || (_QWORD *)*v41 != v28 )
            goto LABEL_104;
          *(_QWORD *)(a1 + 296) = v27;
          *v27 = v28;
          v27[1] = v41;
          *v41 = v27;
        }
        for ( ; !(_DWORD)v4; v38 = a2 )
        {
LABEL_57:
          v42 = *(_QWORD *)(a1 + 256);
          v85 = 0;
          v86 = 0;
          v83 = 0;
          v84 = 0;
          v81 = 0;
          v82 = 0;
          v79 = nullptr;
          v80 = 0;
          v77 = 0;
          v78 = 0;
          v76 = 0;
          if ( !v42 )
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              8,
              1,
              "cam_ife_hw_mgr_acquire_offline_res_sfe",
              5426,
              "BUS RD resource has not been acquired, ctx_idx: %u",
              *(_DWORD *)(a1 + 56));
            v56 = -22;
            goto LABEL_72;
          }
          v43 = *(_QWORD *)(a1 + 72);
          v27 = (_QWORD *)*v28;
          if ( (_QWORD *)*v28 == v28 )
          {
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
              3,
              8,
              1,
              "cam_ife_hw_mgr_get_res",
              2078,
              "No more free ife hw mgr ctx");
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              8,
              1,
              "cam_ife_hw_mgr_acquire_offline_res_sfe",
              5433,
              "No free resource, ctx_idx: %u",
              *(_DWORD *)(a1 + 56));
            v56 = -1;
            goto LABEL_72;
          }
          v44 = (_QWORD *)v27[1];
          if ( (_QWORD *)*v44 == v27 && (v45 = *v27, *(_QWORD **)(*v27 + 8LL) == v27) )
          {
            *(_QWORD *)(v45 + 8) = v44;
            *v44 = v45;
          }
          else
          {
            _list_del_entry_valid_or_report(*v28);
            v38 = a2;
          }
          *v27 = v27;
          v27[1] = v27;
          v46 = *(_QWORD *)(a1 + 8728);
          v47 = v5[1188];
          v85 = v38;
          LODWORD(v82) = 0;
          v83 = v46;
          v48 = *(_QWORD *)(a1 + 16);
          LOBYTE(v86) = v47;
          v49 = *(_QWORD *)(v42 + 32);
          v78 = a1;
          v79 = cam_ife_hw_mgr_event_handler;
          v77 = v48;
          v50 = *(_QWORD *)(v49 + 16);
          LODWORD(v76) = 10;
          v51 = *(unsigned int *)(v50 + 4);
          if ( (unsigned int)v51 < 3 )
          {
            v4 = v43 + 224;
            v52 = **(_QWORD **)(v43 + 224 + 8 * v51);
            v53 = *(__int64 (__fastcall **)(__int64, __int64 *, __int64))(v52 + 40);
            v54 = *(_QWORD *)(v52 + 112);
            if ( *((_DWORD *)v53 - 1) != 1989616049 )
              __break(0x8229u);
            v55 = v53(v54, &v76, 88);
            if ( v55 )
            {
              v56 = v55;
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                8,
                1,
                "cam_ife_hw_mgr_acquire_offline_res_sfe",
                5453,
                "Failed to acquire SFE PIX for offline, ctx_idx: %u",
                *(_DWORD *)(a1 + 56));
              if ( v27 )
              {
                v57 = *(_QWORD **)(a1 + 296);
                if ( v57 == v27 || (_QWORD *)*v57 != v28 )
                {
                  _list_add_valid_or_report(v27);
                }
                else
                {
                  *(_QWORD *)(a1 + 296) = v27;
                  *v27 = v28;
                  v27[1] = v57;
                  *v57 = v27;
                }
              }
LABEL_72:
              v58 = *(unsigned int *)(a1 + 56);
              v59 = "Acquire SFE PIX SRC resource Failed, ctx_idx: %u";
              v60 = 5609;
              goto LABEL_73;
            }
            v61 = v81;
            v62 = debug_mdl;
            v27[4] = v81;
            if ( (v62 & 8) != 0 && !debug_priority )
              ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                v62 & 8,
                4,
                "cam_ife_hw_mgr_acquire_offline_res_sfe",
                5459,
                "Acquired SFE: %u PIX LEFT for offline, ctx_idx: %u",
                *(_DWORD *)(*(_QWORD *)(v61 + 16) + 4LL),
                *(_DWORD *)(a1 + 56));
            v63 = (_DWORD *)a2;
            *((_DWORD *)v27 + 4) = v76;
            *((_DWORD *)v27 + 5) = v82;
            *((_DWORD *)v27 + 6) = *(_DWORD *)(a2 + 80);
            if ( v27 )
            {
              v64 = a1 + 240;
              v65 = *(_QWORD **)(a1 + 248);
              if ( v27 == (_QWORD *)(a1 + 240) || v65 == v27 || *v65 != v64 )
              {
                _list_add_valid_or_report(v27);
                v63 = (_DWORD *)a2;
              }
              else
              {
                *(_QWORD *)(a1 + 248) = v27;
                *v27 = v64;
                v27[1] = v65;
                *v65 = v27;
              }
            }
            if ( v5[1187] != 1 )
              goto LABEL_91;
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              8,
              2,
              "cam_ife_hw_mgr_acquire_offline_res_sfe",
              5468,
              "DUAL not supported for offline use-case, ctx_idx: %u",
              *(_DWORD *)(a1 + 56));
            v81 = 0;
            v66 = *(unsigned int *)(*(_QWORD *)(*(_QWORD *)(v42 + 40) + 16LL) + 4LL);
            if ( (unsigned int)v66 <= 2 )
            {
              v67 = **(_QWORD **)(v4 + 8 * v66);
              v68 = *(__int64 (__fastcall **)(__int64, __int64 *, __int64))(v67 + 40);
              v69 = *(_QWORD *)(v67 + 112);
              if ( *((_DWORD *)v68 - 1) != 1989616049 )
                __break(0x8229u);
              v70 = v68(v69, &v76, 88);
              if ( v70 )
              {
                v56 = v70;
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  8,
                  1,
                  "cam_ife_hw_mgr_acquire_offline_res_sfe",
                  5480,
                  "Failed to acquire SFE PIX for RIGHT, ctx_idx: %u",
                  *(_DWORD *)(a1 + 56));
                goto LABEL_72;
              }
              v71 = v81;
              v63 = (_DWORD *)a2;
              v27[5] = v81;
              if ( (debug_mdl & 8) != 0 && !debug_priority )
              {
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  debug_mdl & 8,
                  4,
                  "cam_ife_hw_mgr_acquire_offline_res_sfe",
                  5486,
                  "Acquired SFE:%d PIX RIGHT for offline, ctx_idx: %u",
                  *(_DWORD *)(*(__int64 *)((char *)&qword_10 + v71) + 4),
                  *(_DWORD *)(a1 + 56));
                v63 = (_DWORD *)a2;
              }
LABEL_91:
              ++*(_DWORD *)(v42 + 108);
              if ( v63[50] )
              {
                if ( v63[41] )
                {
                  v72 = cam_ife_hw_mgr_acquire_offline_res_ife_camif(a1, a2, 0, a3, a4);
                  v63 = (_DWORD *)a2;
                  if ( v72 )
                  {
                    v73 = v72;
                    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                      3,
                      8,
                      1,
                      "cam_ife_mgr_acquire_hw_sfe_offline",
                      5621,
                      "Acquire IFE IPP SRC resource Failed, ctx_idx: %u",
                      *(_DWORD *)(a1 + 56));
                    result = v73;
                    goto LABEL_15;
                  }
                }
                if ( v63[45] )
                {
                  v74 = cam_ife_hw_mgr_acquire_offline_res_ife_camif(a1, a2, 1, a3, a4);
                  if ( v74 )
                  {
                    v58 = *(unsigned int *)(a1 + 56);
                    v56 = v74;
                    v59 = "Acquire IFE LCR SRC resource Failed, ctx_idx: %u";
                    v60 = 5633;
                    goto LABEL_73;
                  }
                }
                v75 = cam_ife_hw_mgr_acquire_res_ife_out(a1, a2);
                v63 = (_DWORD *)a2;
                if ( v75 )
                {
                  v58 = *(unsigned int *)(a1 + 56);
                  v56 = v75;
                  v59 = "Acquire IFE OUT resource Failed, ctx_idx: %u";
                  v60 = 5643;
                  goto LABEL_73;
                }
              }
              result = cam_ife_hw_mgr_acquire_res_sfe_out(a1, v63);
              if ( !(_DWORD)result )
                goto LABEL_15;
              v58 = *(unsigned int *)(a1 + 56);
              v56 = result;
              v59 = "Acquire SFE OUT resource Failed, ctx_idx: %u";
              v60 = 5651;
LABEL_73:
              ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
                3,
                8,
                1,
                "cam_ife_mgr_acquire_hw_sfe_offline",
                v60,
                v59,
                v58);
              result = v56;
              goto LABEL_15;
            }
          }
          __break(0x5512u);
LABEL_104:
          _list_add_valid_or_report(v27);
        }
      }
    }
    else
    {
      LODWORD(v4) = -22;
    }
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_hw_mgr_acquire_offline_res_csid",
      5515,
      "BUS RD resource has not been acquired, ctx_idx: %u",
      *(_DWORD *)(a1 + 56));
    LODWORD(v4) = -22;
  }
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    8,
    1,
    "cam_ife_mgr_acquire_hw_sfe_offline",
    5601,
    "Acquire IFE CSID RDI0 resource Failed, ctx_idx: %u",
    *(_DWORD *)(a1 + 56));
  result = (unsigned int)v4;
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
