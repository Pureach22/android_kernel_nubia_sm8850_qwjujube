__int64 __fastcall cam_sfe_bus_wr_handle_err_irq_bottom_half(_DWORD *a1, __int64 a2)
{
  __int64 result; // x0
  int v5; // w19
  _DWORD *v6; // x25
  unsigned int v7; // w22
  int v8; // w21
  __int64 v9; // x8
  unsigned int v10; // w6
  __int64 v11; // x8
  unsigned int *v12; // x23
  __int64 v13; // x25
  __int64 v14; // x20
  __int64 v15; // x19
  const char *v16; // x24
  __int64 v17; // x7
  __int64 v18; // x1
  __int64 v19; // x6
  __int64 v20; // x4
  const char *v21; // x5
  __int64 v22; // x28
  unsigned __int64 v23; // x8
  __int64 v24; // x19
  unsigned __int64 i; // x20
  unsigned int v26; // w8
  unsigned __int64 v27; // x24
  __int64 v28; // x20
  int v29; // w21
  unsigned __int64 v30; // x26
  __int64 v31; // x9
  unsigned int v32; // w6
  __int64 v33; // x19
  __int64 v34; // x22
  unsigned int v35; // w9
  int v36; // w20
  unsigned int *v37; // x23
  unsigned int v38; // w6
  int v39; // w26
  int v40; // w27
  int v41; // w28
  int v42; // w6
  _DWORD *v43; // x8
  int v44; // w19
  bool v45; // cf
  _DWORD *v46; // x8
  int v47; // [xsp+8h] [xbp-C8h]
  int v48; // [xsp+18h] [xbp-B8h]
  __int64 v49; // [xsp+48h] [xbp-88h]
  _DWORD *v50; // [xsp+50h] [xbp-80h]
  char v51; // [xsp+5Ch] [xbp-74h]
  _DWORD *v52; // [xsp+60h] [xbp-70h]
  unsigned int v53; // [xsp+68h] [xbp-68h]
  __int64 v54; // [xsp+68h] [xbp-68h]
  __int64 v55; // [xsp+70h] [xbp-60h]
  unsigned __int64 v56; // [xsp+70h] [xbp-60h]
  unsigned int *v57; // [xsp+78h] [xbp-58h]
  int v58; // [xsp+78h] [xbp-58h]
  int v59; // [xsp+84h] [xbp-4Ch] BYREF
  __int64 v60; // [xsp+88h] [xbp-48h]
  __int64 v61; // [xsp+90h] [xbp-40h] BYREF
  __int64 v62; // [xsp+98h] [xbp-38h] BYREF
  __int64 v63; // [xsp+A0h] [xbp-30h]
  __int64 v64; // [xsp+A8h] [xbp-28h]
  __int64 v65; // [xsp+B0h] [xbp-20h]
  int *v66; // [xsp+B8h] [xbp-18h]
  __int64 v67; // [xsp+C0h] [xbp-10h]

  result = 4294967274LL;
  v67 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v61 = a2;
  if ( !a1 || !a2 )
    goto LABEL_67;
  v5 = *(_DWORD *)(a2 + 20);
  v65 = 0;
  v66 = nullptr;
  v63 = 0;
  v64 = 0;
  v62 = 0;
  if ( (v5 & 0x40000000) != 0 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x40000000,
      1,
      "cam_sfe_bus_wr_handle_err_irq_bottom_half",
      2287,
      "SFE[%u] CCIF protocol violation occurred at [%llu: %09llu]",
      *a1,
      *(_QWORD *)(a2 + 48),
      *(_QWORD *)(a2 + 56));
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x40000000,
      1,
      "cam_sfe_bus_wr_handle_err_irq_bottom_half",
      2288,
      "Violation status: 0x%x",
      *(_DWORD *)(a2 + 24));
  }
  if ( v5 < 0 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x40000000,
      1,
      "cam_sfe_bus_wr_handle_err_irq_bottom_half",
      2296,
      "SFE[%d] IMAGE_SIZE_VIOLATION occurred at [%llu: %09llu]",
      *a1,
      *(_QWORD *)(a2 + 48),
      *(_QWORD *)(a2 + 56));
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x40000000,
      1,
      "cam_sfe_bus_wr_handle_err_irq_bottom_half",
      2298,
      "Sensor: Programmed image size is not same as actual image size from input");
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x40000000,
      1,
      "cam_sfe_bus_wr_handle_err_irq_bottom_half",
      2299,
      "Debug: Check SW programming/sensor config");
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x40000000,
      1,
      "cam_sfe_bus_wr_handle_err_irq_bottom_half",
      2301,
      "Violation status: 0x%x",
      *(_DWORD *)(a2 + 32));
  }
  v6 = a1 + 6144;
  v52 = a1;
  v49 = a2;
  v50 = a1 + 6144;
  if ( (v5 & 0x10000000) != 0 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x40000000,
      1,
      "cam_sfe_bus_wr_handle_err_irq_bottom_half",
      2309,
      "SFE[%u] CONSTRAINT_VIOLATION occurred at [%llu: %09llu]",
      *a1,
      *(_QWORD *)(a2 + 48),
      *(_QWORD *)(a2 + 56));
    if ( a1[6887] )
    {
      v7 = 0;
      v8 = 0;
      v51 = 0;
      v55 = *((_QWORD *)a1 + 3450);
      while ( 1 )
      {
        v9 = *((_QWORD *)a1 + 3451);
        if ( !v9 )
          break;
        v10 = *(_DWORD *)(v9 + 56LL * v8);
        if ( v10 >= 0x12 )
          goto LABEL_63;
        v11 = *((_QWORD *)a1 + 3447) + 152LL * v10;
        if ( v11 && (v12 = *(unsigned int **)(v11 + 24)) != nullptr )
        {
          if ( v12[6] )
          {
            v13 = 0;
            v57 = *((unsigned int **)v12 + 1);
            v53 = *v12;
            while ( 1 )
            {
              v14 = *((_QWORD *)v12 + 4) + 152 * v13;
              v15 = *(_QWORD *)(v14 + 24);
              if ( !v15 )
                goto LABEL_18;
              v7 = cam_io_r_mb(*((_QWORD *)v57 + 1) + *(unsigned int *)(*(_QWORD *)(v15 + 16) + 92LL));
              if ( !v7 )
                goto LABEL_18;
              v16 = (const char *)(v14 + 128);
              if ( v53 <= 4 && (((unsigned __int64)v7 >> *(_DWORD *)(v55 + 12)) & 1) != 0 )
                break;
              if ( (((unsigned __int64)v7 >> *(_DWORD *)(v55 + 16)) & 1) == 0 || (*(_BYTE *)(v15 + 98) & 1) == 0 )
              {
                v22 = *((_QWORD *)a1 + 3450);
                v23 = *(unsigned int *)(v22 + 8);
                if ( (_DWORD)v23 )
                {
                  v24 = 0;
                  for ( i = 0; i < v23; ++i )
                  {
                    if ( (*(_DWORD *)(*(_QWORD *)v22 + v24) & v7) != 0 )
                    {
                      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                        3,
                        0x40000000,
                        1,
                        "cam_sfe_bus_wr_print_constraint_errors",
                        393,
                        "Write Master: %s, Error_desc: %s",
                        v16,
                        *(const char **)(*(_QWORD *)v22 + v24 + 8));
                      v23 = *(unsigned int *)(v22 + 8);
                    }
                    v24 += 16;
                  }
                }
                a1 = v52;
                goto LABEL_18;
              }
              v51 = 1;
              if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
              {
                v17 = *v12;
                v18 = debug_mdl & 0x40000000;
                v19 = *v57;
                v20 = 470;
                v21 = "Ignoring Image Width Unalign error on SFE[%u] out rsrc: %u WM: %s in frame based mode";
LABEL_36:
                ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64, __int64))cam_print_log)(
                  3,
                  v18,
                  4,
                  "cam_sfe_bus_wr_get_constraint_errors",
                  v20,
                  v21,
                  v19,
                  v17,
                  v14 + 128);
                v51 = 1;
              }
LABEL_18:
              if ( ++v13 >= (unsigned __int64)v12[6] )
                goto LABEL_10;
            }
            v51 = 1;
            if ( (debug_mdl & 0x40000000) == 0 || debug_priority )
              goto LABEL_18;
            v17 = *v12;
            v18 = debug_mdl & 0x40000000;
            v19 = *v57;
            v20 = 461;
            v21 = "Ignoring Image Addr Unalign error on SFE[%u] out rsrc: %u WM: %s";
            goto LABEL_36;
          }
        }
        else if ( (debug_mdl & 8) != 0 && !debug_priority )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 8,
            4,
            "cam_sfe_bus_wr_get_constraint_errors",
            425,
            "SFE out:%d out rsrc node or data is NULL",
            v8);
        }
LABEL_10:
        v6 = v50;
        if ( (unsigned int)++v8 >= v50[743] )
          goto LABEL_41;
      }
      v10 = 18;
LABEL_63:
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x40000000,
        1,
        "cam_sfe_bus_wr_get_constraint_errors",
        418,
        "Invalid sfe out type:%d",
        v10);
      v26 = v6[743];
      if ( !v26 )
        goto LABEL_64;
LABEL_42:
      v27 = 0;
      v28 = 0;
      v29 = 0;
      v30 = *(_DWORD *)(v49 + 24) | v7 | *(_DWORD *)(v49 + 32);
      while ( 1 )
      {
        v31 = *((_QWORD *)a1 + 3451);
        if ( !v31 )
          break;
        v32 = *(_DWORD *)(v31 + 56LL * v29);
        if ( v32 >= 0x12 )
          goto LABEL_60;
        v33 = *((_QWORD *)a1 + 3447) + 152LL * v32;
        if ( v33 )
        {
          v34 = *(_QWORD *)(v33 + 24);
          if ( v34 )
          {
            if ( *(_DWORD *)(v33 + 8) == 4 )
            {
              v35 = *(_DWORD *)(v34 + 24);
              v28 = *(_QWORD *)(v34 + 104);
              if ( v35 )
              {
                v54 = *(_QWORD *)(v34 + 104);
                v36 = 0;
                v56 = v30;
                while ( 1 )
                {
                  v37 = *(unsigned int **)(*(_QWORD *)(v34 + 32) + 152LL * v36 + 24);
                  if ( v37 )
                  {
                    v38 = *v37;
                    if ( (*v37 & 0x80000000) != 0 || v38 >= v6[742] )
                    {
                      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                        3,
                        0x40000000,
                        1,
                        "cam_sfe_bus_wr_get_err_port_info",
                        2247,
                        "Unsupported SFE out %d",
                        v38);
                      v28 = v54;
                      goto LABEL_61;
                    }
                    if ( ((v30 >> v38) & 1) != 0 )
                    {
                      v27 |= 1LL << *(_BYTE *)(v33 + 4);
                      v58 = cam_io_r_mb(*(_QWORD *)(*((_QWORD *)v37 + 1) + 8LL) + *(unsigned int *)(*((_QWORD *)v37 + 2)
                                                                                                  + 68LL));
                      v39 = cam_io_r_mb(*(_QWORD *)(*((_QWORD *)v37 + 1) + 8LL) + *(unsigned int *)(*((_QWORD *)v37 + 2)
                                                                                                  + 72LL));
                      v40 = cam_io_r_mb(*(_QWORD *)(*((_QWORD *)v37 + 1) + 8LL) + *(unsigned int *)(*((_QWORD *)v37 + 2)
                                                                                                  + 76LL));
                      v41 = cam_io_r_mb(*(_QWORD *)(*((_QWORD *)v37 + 1) + 8LL) + *(unsigned int *)(*((_QWORD *)v37 + 2)
                                                                                                  + 80LL));
                      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                        3,
                        0x40000000,
                        3,
                        "__cam_sfe_bus_wr_print_wm_info",
                        1941,
                        "SFE:%u WM:%u width:%u height:%u stride:%u x_init:%u en_cfg:%u acquired width:%u height:%u pack_cfg: 0x%x",
                        **((_DWORD **)v37 + 1),
                        *v37,
                        v37[13],
                        v37[14],
                        v37[15],
                        v37[19],
                        v37[24],
                        v37[26],
                        v37[27],
                        v37[17]);
                      v6 = v50;
                      v48 = v41;
                      a1 = v52;
                      v47 = v39;
                      v30 = v56;
                      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                        3,
                        0x40000000,
                        3,
                        "__cam_sfe_bus_wr_print_wm_info",
                        1946,
                        "SFE:%u WM:%u last_consumed_image_addr:0x%x last_consumed_frame_header:0x%x fifo_word_cnt:%d [FH "
                        "+ Image] current_image_addr:0x%x",
                        *(_DWORD *)(*(_QWORD *)(*((_QWORD *)v37 + 1) + 16LL) + 4LL),
                        *v37,
                        v58,
                        v47,
                        v40,
                        v48);
                      v35 = *(_DWORD *)(v34 + 24);
                    }
                  }
                  if ( ++v36 >= v35 )
                  {
                    v26 = v6[743];
                    v28 = v54;
                    break;
                  }
                }
              }
            }
          }
        }
        if ( ++v29 >= v26 )
          goto LABEL_65;
      }
      v32 = 18;
LABEL_60:
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x40000000,
        1,
        "cam_sfe_bus_wr_get_err_port_info",
        2224,
        "Invalid sfe out type:%d",
        v32);
LABEL_61:
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x40000000,
        1,
        "cam_sfe_bus_wr_handle_err_irq_bottom_half",
        2321,
        "Failed to get err port info, violation_status = %d",
        v30);
      goto LABEL_65;
    }
  }
  v7 = 0;
  v51 = 0;
LABEL_41:
  v26 = v6[743];
  if ( v26 )
    goto LABEL_42;
LABEL_64:
  v28 = 0;
  v27 = 0;
LABEL_65:
  cam_sfe_bus_wr_put_evt_payload(a1, &v61);
  if ( (v51 & 1) == 0 )
  {
    v42 = *a1;
    v60 = 0;
    HIDWORD(v64) = 7;
    LODWORD(v62) = 12;
    v59 = 3;
    HIDWORD(v63) = v42;
    v66 = &v59;
    if ( !v28 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x40000000,
        2,
        "cam_sfe_bus_wr_handle_err_irq_bottom_half",
        2337,
        "SFE:[%d] out error notification failed, cb data is NULL",
        v42);
      result = 4294967274LL;
      goto LABEL_67;
    }
    v43 = *((_DWORD **)a1 + 3432);
    if ( v43 )
    {
      if ( v27 )
      {
        v44 = 24576;
        do
        {
          if ( (v27 & 1) != 0 )
          {
            v46 = *((_DWORD **)a1 + 3432);
            LODWORD(v63) = v44;
            if ( *(v46 - 1) != 414296116 )
              __break(0x8228u);
            ((void (__fastcall *)(__int64, _QWORD, __int64 *))v46)(v28, 0, &v62);
          }
          v45 = v27 >= 2;
          ++v44;
          v27 >>= 1;
        }
        while ( v45 );
      }
      else
      {
        LODWORD(v63) = 18;
        if ( *(v43 - 1) != 414296116 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, _QWORD, __int64 *))v43)(v28, 0, &v62);
      }
    }
  }
  result = 0;
LABEL_67:
  _ReadStatusReg(SP_EL0);
  return result;
}
