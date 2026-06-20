__int64 __fastcall cam_sfe_bus_rd_handle_err_irq_bottom_half(_DWORD *a1, __int64 a2)
{
  __int64 result; // x0
  int v5; // w9
  int v6; // w8
  __int64 v7; // x21
  unsigned int v8; // w26
  __int64 v9; // x8
  __int64 v10; // x22
  __int64 v11; // x24
  __int64 v12; // x8
  int v13; // w0
  __int64 v14; // x25
  unsigned int v15; // w8
  int v16; // w27
  unsigned int i; // w28
  __int64 v18; // x9
  __int64 v19; // x24
  __int64 v20; // x8
  int v21; // w0
  __int64 v22; // x25
  unsigned int v23; // w8
  int v24; // w27
  unsigned int j; // w28
  __int64 v26; // x9
  int v27; // w20
  unsigned int v28; // w21
  unsigned int v29; // w8
  _DWORD *v30; // x9
  unsigned __int64 v31; // x21
  unsigned int v32; // w6
  __int64 v33; // x20
  int v34; // w22
  _DWORD *v35; // x8
  _DWORD *v36; // x10
  __int64 v37; // x11
  __int64 v38; // x13
  int v39; // w12
  __int64 v40; // x14
  __int64 v41; // x13
  unsigned int v42; // w6
  __int64 v43; // x12
  int v44; // w13
  __int64 v45; // x14
  __int64 v46; // x12
  __int64 v47; // x9
  int v48; // w10
  __int64 v49; // x12
  __int64 v50; // x9
  unsigned __int64 v51; // [xsp+10h] [xbp-50h]
  int v52; // [xsp+18h] [xbp-48h]
  int v53; // [xsp+1Ch] [xbp-44h] BYREF
  __int64 v54; // [xsp+20h] [xbp-40h]
  __int64 v55; // [xsp+28h] [xbp-38h] BYREF
  unsigned __int64 v56; // [xsp+30h] [xbp-30h]
  __int64 v57; // [xsp+38h] [xbp-28h]
  __int64 v58; // [xsp+40h] [xbp-20h]
  int *v59; // [xsp+48h] [xbp-18h]
  _QWORD v60[2]; // [xsp+50h] [xbp-10h] BYREF

  result = 4294967274LL;
  v60[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 && a2 )
  {
    v5 = *(_DWORD *)(a2 + 20);
    v6 = a1[459];
    v60[0] = a2;
    if ( (v6 & v5) == 0 )
      goto LABEL_63;
    v57 = 0;
    v58 = 0;
    v55 = 0;
    v56 = 0;
    v54 = 0;
    v52 = v5;
    if ( (v5 & 1) != 0 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x40000000,
        1,
        "cam_sfe_bus_rd_handle_err_irq_bottom_half",
        859,
        "SFE:[%u] Constraint Violation occurred at [%llu: %09llu]",
        *a1,
        *(_QWORD *)(a2 + 40),
        *(_QWORD *)(a2 + 48));
      if ( a1[467] )
      {
        v7 = 0;
        v51 = *(unsigned int *)(a2 + 24);
        while ( 1 )
        {
          if ( v7 == 3 )
            goto LABEL_92;
          v8 = *(_DWORD *)(*((_QWORD *)a1 + 348) + 28 * v7 + 244);
          if ( v8 >= 3 )
            break;
          v9 = (__int64)&a1[38 * v8 + 582];
          if ( v9 && (v10 = *(_QWORD *)(v9 + 24)) != 0 )
          {
            if ( *(_DWORD *)(v10 + 24) )
            {
              v11 = *(_QWORD *)(v10 + 32);
              v12 = *(_QWORD *)(v11 + 24);
              if ( v12 )
              {
                if ( ((v51 >> *(_DWORD *)(v12 + 24)) & 1) != 0 )
                {
                  v13 = cam_io_r_mb(*((_QWORD *)a1 + 1) + *(unsigned int *)(*(_QWORD *)(v12 + 8) + 40LL));
                  if ( v13 )
                  {
                    v14 = *(_QWORD *)(*((_QWORD *)a1 + 348) + 368LL);
                    v15 = *(_DWORD *)(v14 + 8);
                    if ( v15 )
                    {
                      v16 = v13;
                      for ( i = 0; i < v15; ++i )
                      {
                        v18 = *(_QWORD *)v14 + 16LL * (int)i;
                        if ( (*(_DWORD *)v18 & v16) != 0 )
                        {
                          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                            3,
                            0x40000000,
                            1,
                            "cam_sfe_bus_rd_print_constraint_error",
                            416,
                            "RD resource type: RDI%u, Read master: %s, Error_desc: %s",
                            v8,
                            (const char *)(v11 + 128),
                            *(const char **)(v18 + 8));
                          v15 = *(_DWORD *)(v14 + 8);
                        }
                      }
                    }
                  }
                }
              }
              if ( *(_DWORD *)(v10 + 24) >= 2u )
              {
                v19 = *(_QWORD *)(v10 + 40);
                v20 = *(_QWORD *)(v19 + 24);
                if ( v20 )
                {
                  if ( ((v51 >> *(_DWORD *)(v20 + 24)) & 1) != 0 )
                  {
                    v21 = cam_io_r_mb(*((_QWORD *)a1 + 1) + *(unsigned int *)(*(_QWORD *)(v20 + 8) + 40LL));
                    if ( v21 )
                    {
                      v22 = *(_QWORD *)(*((_QWORD *)a1 + 348) + 368LL);
                      v23 = *(_DWORD *)(v22 + 8);
                      if ( v23 )
                      {
                        v24 = v21;
                        for ( j = 0; j < v23; ++j )
                        {
                          v26 = *(_QWORD *)v22 + 16LL * (int)j;
                          if ( (*(_DWORD *)v26 & v24) != 0 )
                          {
                            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                              3,
                              0x40000000,
                              1,
                              "cam_sfe_bus_rd_print_constraint_error",
                              416,
                              "RD resource type: RDI%u, Read master: %s, Error_desc: %s",
                              v8,
                              (const char *)(v19 + 128),
                              *(const char **)(v26 + 8));
                            v23 = *(_DWORD *)(v22 + 8);
                          }
                        }
                      }
                    }
                  }
                }
                if ( *(_DWORD *)(v10 + 24) > 2u )
                  goto LABEL_92;
              }
            }
          }
          else if ( (debug_mdl & 8) != 0 && !debug_priority )
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 8,
              4,
              "cam_sfe_bus_rd_get_constraint_error",
              442,
              "SFE bus rd:%d in resc node or data is NULL",
              v7);
          }
          if ( ++v7 >= (unsigned __int64)(unsigned int)a1[467] )
            goto LABEL_35;
        }
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x40000000,
          1,
          "cam_sfe_bus_rd_get_constraint_error",
          436,
          "Invalid SFE RD resource type:%d",
          v8);
      }
    }
LABEL_35:
    if ( v52 < 0 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x40000000,
        1,
        "cam_sfe_bus_rd_handle_err_irq_bottom_half",
        867,
        "SFE:[%d] CCIF Violation occurred at [%llu: %09llu]",
        *a1,
        *(_QWORD *)(a2 + 40),
        *(_QWORD *)(a2 + 48));
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x40000000,
        1,
        "cam_sfe_bus_rd_handle_err_irq_bottom_half",
        868,
        "Violation status 0x%x",
        *(_DWORD *)(a2 + 28));
    }
    v28 = *(_DWORD *)(a2 + 24);
    v27 = *(_DWORD *)(a2 + 28);
    cam_sfe_bus_rd_put_evt_payload(a1, v60);
    v29 = a1[467];
    if ( !v29 )
    {
      v33 = 0;
      goto LABEL_58;
    }
    v30 = *((_DWORD **)a1 + 348);
    v31 = v27 | v28;
    v32 = v30[61];
    if ( v32 > 2 )
    {
      v33 = 0;
      goto LABEL_40;
    }
    v36 = a1 + 582;
    v37 = (__int64)&a1[38 * v32 + 582];
    if ( v37 )
    {
      v38 = *(_QWORD *)(v37 + 24);
      if ( !v38 )
      {
        v33 = 0;
LABEL_57:
        if ( v29 == 1 )
          goto LABEL_58;
LABEL_66:
        v32 = v30[68];
        if ( v32 > 2 )
          goto LABEL_40;
        v37 = (__int64)&v36[38 * v32];
        if ( v37 )
        {
          v43 = *(_QWORD *)(v37 + 24);
          if ( v43 )
          {
            if ( *(_DWORD *)(v37 + 8) == 4 )
            {
              v44 = *(_DWORD *)(v43 + 24);
              v33 = *(_QWORD *)(v43 + 72);
              if ( v44 )
              {
                v45 = *(_QWORD *)(*(_QWORD *)(v43 + 32) + 24LL);
                if ( v45 && ((v31 >> *(_DWORD *)(v45 + 24)) & 1) != 0 )
                  goto LABEL_88;
                if ( v44 != 1 )
                {
                  v46 = *(_QWORD *)(*(_QWORD *)(v43 + 40) + 24LL);
                  if ( v46 && ((v31 >> *(_DWORD *)(v46 + 24)) & 1) != 0 )
                    goto LABEL_88;
                  if ( v44 != 2 )
                    goto LABEL_92;
                }
              }
            }
          }
        }
        if ( v29 < 3 )
        {
LABEL_58:
          v34 = 3;
          v35 = *((_DWORD **)a1 + 228);
          if ( v35 )
            goto LABEL_59;
LABEL_63:
          result = 0;
          goto LABEL_64;
        }
        v32 = v30[75];
        if ( v32 > 2 )
        {
LABEL_40:
          v34 = 3;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            0x40000000,
            1,
            "cam_sfe_bus_rd_get_err_port_info",
            803,
            "Invalid SFE RD resource type:%d",
            v32);
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            0x40000000,
            1,
            "cam_sfe_bus_rd_handle_err_irq_bottom_half",
            879,
            "Failed to get err port info, violation_status = 0x%x",
            v31);
          v35 = *((_DWORD **)a1 + 228);
          if ( !v35 )
            goto LABEL_63;
LABEL_59:
          v42 = *a1;
          HIDWORD(v57) = 7;
          LODWORD(v55) = 11;
          v53 = 3;
          v56 = __PAIR64__(v42, v34);
          v59 = &v53;
          if ( !v33 )
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              0x40000000,
              2,
              "cam_sfe_bus_rd_handle_err_irq_bottom_half",
              894,
              "SFE:[%d] bus rd error notification failed, cb data is NULL",
              v42);
            result = 4294967274LL;
            goto LABEL_64;
          }
          if ( *(v35 - 1) != 414296116 )
            __break(0x8228u);
          ((void (__fastcall *)(__int64, _QWORD, __int64 *))v35)(v33, 0, &v55);
          goto LABEL_63;
        }
        v37 = (__int64)&v36[38 * v32];
        if ( !v37 )
          goto LABEL_91;
        v47 = *(_QWORD *)(v37 + 24);
        if ( !v47 )
          goto LABEL_91;
        if ( *(_DWORD *)(v37 + 8) != 4 )
          goto LABEL_91;
        v48 = *(_DWORD *)(v47 + 24);
        v33 = *(_QWORD *)(v47 + 72);
        if ( !v48 )
          goto LABEL_91;
        v49 = *(_QWORD *)(*(_QWORD *)(v47 + 32) + 24LL);
        if ( !v49 || ((v31 >> *(_DWORD *)(v49 + 24)) & 1) == 0 )
        {
          if ( v48 != 1 )
          {
            v50 = *(_QWORD *)(*(_QWORD *)(v47 + 40) + 24LL);
            if ( v50 && ((v31 >> *(_DWORD *)(v50 + 24)) & 1) != 0 )
              goto LABEL_88;
            if ( v48 != 2 )
              goto LABEL_92;
          }
LABEL_91:
          if ( v29 != 3 )
            goto LABEL_92;
          goto LABEL_58;
        }
LABEL_88:
        v34 = *(_DWORD *)(v37 + 4);
        v35 = *((_DWORD **)a1 + 228);
        if ( !v35 )
          goto LABEL_63;
        goto LABEL_59;
      }
      if ( *(_DWORD *)(v37 + 8) == 4 )
      {
        v39 = *(_DWORD *)(v38 + 24);
        v33 = *(_QWORD *)(v38 + 72);
        if ( v39 )
        {
          v40 = *(_QWORD *)(*(_QWORD *)(v38 + 32) + 24LL);
          if ( v40 && ((v31 >> *(_DWORD *)(v40 + 24)) & 1) != 0 )
            goto LABEL_88;
          if ( v39 != 1 )
          {
            v41 = *(_QWORD *)(*(_QWORD *)(v38 + 40) + 24LL);
            if ( v41 && ((v31 >> *(_DWORD *)(v41 + 24)) & 1) != 0 )
              goto LABEL_88;
            if ( v39 != 2 )
LABEL_92:
              __break(0x5512u);
          }
        }
        goto LABEL_57;
      }
    }
    v33 = 0;
    if ( v29 == 1 )
      goto LABEL_58;
    goto LABEL_66;
  }
LABEL_64:
  _ReadStatusReg(SP_EL0);
  return result;
}
