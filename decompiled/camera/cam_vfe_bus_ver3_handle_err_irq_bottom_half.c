__int64 __fastcall cam_vfe_bus_ver3_handle_err_irq_bottom_half(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  int v4; // w19
  const char *v5; // x8
  const char *v6; // x7
  const char *v7; // x10
  __int64 v8; // x23
  unsigned int v9; // w21
  __int64 v10; // x7
  int v11; // w6
  unsigned int v12; // w21
  int v13; // w8
  _DWORD *v14; // x8
  unsigned __int64 v15; // x19
  int v16; // w20
  bool v17; // cf
  _DWORD *v18; // x8
  __int64 v19; // x0
  __int64 v20; // x9
  __int64 v21; // x8
  __int64 v22; // x25
  unsigned __int64 i; // x20
  __int64 v24; // x19
  __int64 v25; // x8
  int v26; // w0
  int v27; // w28
  unsigned __int64 v28; // x8
  __int64 v29; // x21
  unsigned __int64 j; // x22
  __int64 v31; // x0
  int v32; // [xsp+1Ch] [xbp-74h]
  __int64 v34; // [xsp+28h] [xbp-68h]
  __int64 v35; // [xsp+30h] [xbp-60h]
  unsigned __int64 v36; // [xsp+40h] [xbp-50h] BYREF
  _BYTE v37[4]; // [xsp+48h] [xbp-48h] BYREF
  int v38; // [xsp+4Ch] [xbp-44h] BYREF
  __int64 v39; // [xsp+50h] [xbp-40h]
  __int64 v40; // [xsp+58h] [xbp-38h] BYREF
  __int64 v41; // [xsp+60h] [xbp-30h]
  __int64 v42; // [xsp+68h] [xbp-28h]
  __int64 v43; // [xsp+70h] [xbp-20h]
  int *v44; // [xsp+78h] [xbp-18h]
  _QWORD v45[2]; // [xsp+80h] [xbp-10h] BYREF

  result = 4294967274LL;
  v45[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v45[0] = a2;
  v36 = 0;
  if ( !a1 || !a2 )
    goto LABEL_57;
  v4 = *(_DWORD *)(a2 + 40);
  v5 = "N";
  if ( v4 >= 0 )
    v6 = "N";
  else
    v6 = "Y";
  if ( (v4 & 0x40000000) != 0 )
    v7 = "Y";
  else
    v7 = "N";
  if ( (v4 & 0x10000000) != 0 )
    v5 = "Y";
  v35 = a1;
  v8 = a1 + 0x8000;
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, const char *, const char *, const char *))cam_print_log)(
    3,
    8,
    1,
    "cam_vfe_bus_ver3_handle_err_irq_bottom_half",
    3499,
    "VFE[%u] BUS error image size violation: %s, CCIF violation: %s, Constraint violation: %s",
    *(unsigned int *)(a1 + 8),
    v6,
    v7,
    v5);
  v42 = 0;
  v43 = 0;
  v40 = 0;
  v41 = 0;
  v39 = 0;
  v32 = v4;
  v37[0] = 0;
  if ( (v4 & 0x90000000) != 0 )
  {
    v9 = *(_DWORD *)(a2 + 32);
    v10 = *(_QWORD *)(a2 + 72);
    v11 = *(_DWORD *)(v35 + 8);
    if ( v9 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_vfe_bus_ver3_handle_err_irq_bottom_half",
        3519,
        "VFE[%u] IMAGE_SIZE_VIOLATION occurred at [%llu: %09llu]",
        v11,
        v10,
        *(_QWORD *)(a2 + 80));
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        8,
        1,
        "cam_vfe_bus_ver3_handle_err_irq_bottom_half",
        3521,
        "Sensor: Programmed image size is different as actual image size from input");
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        8,
        1,
        "cam_vfe_bus_ver3_handle_err_irq_bottom_half",
        3522,
        "Debug: Check SW programming/sensor config");
      cam_vfe_check_violations("Image Size", v9, v35, &v36, v37);
      goto LABEL_14;
    }
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_bus_ver3_handle_err_irq_bottom_half",
      3512,
      "VFE[%u] CONSTRAINT_VIOLATION occurred at [%llu: %09llu]",
      v11,
      v10,
      *(_QWORD *)(a2 + 80));
    if ( !*(_DWORD *)(v8 + 1964) )
      goto LABEL_14;
    v20 = 0;
    do
    {
      v34 = v20;
      v21 = *(_QWORD *)(v8 + 1992) + 152 * v20;
      if ( v21 && (v22 = *(_QWORD *)(v21 + 24)) != 0 )
      {
        if ( *(_DWORD *)(v22 + 32) )
        {
          for ( i = 0; i < *(unsigned int *)(v22 + 32); ++i )
          {
            if ( i == 2 )
              __break(0x5512u);
            v24 = *(_QWORD *)(v22 + 40 + 8 * i);
            v25 = *(_QWORD *)(v24 + 24);
            if ( !v25 )
              continue;
            v26 = cam_io_r_mb(
                    *(_QWORD *)(v35 + 16)
                  + *(unsigned int *)(v25 + 156)
                  + *(unsigned int *)(*(_QWORD *)(v25 + 8) + 120LL));
            if ( !v26 )
              continue;
            v27 = v26;
            if ( (debug_mdl & 8) != 0 && !debug_priority )
            {
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                debug_mdl & 8,
                4,
                "cam_vfe_bus_ver3_print_constraint_errors",
                702,
                "VFE[%u] Constraint violation bitflags: 0x%X",
                *(_DWORD *)(v35 + 8),
                v26);
              v28 = *(unsigned int *)(v8 + 2204);
              if ( (_DWORD)v28 )
              {
LABEL_44:
                v29 = 0;
                for ( j = 0; j < v28; ++j )
                {
                  if ( (*(_DWORD *)(*(_QWORD *)(v8 + 2208) + v29) & v27) != 0 )
                  {
                    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                      3,
                      8,
                      1,
                      "cam_vfe_bus_ver3_print_constraint_errors",
                      706,
                      "SW: Constraint Violation");
                    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                      3,
                      8,
                      1,
                      "cam_vfe_bus_ver3_print_constraint_errors",
                      709,
                      "Write master name: %s, violated constraint description: %s",
                      (const char *)(v24 + 128),
                      *(const char **)(*(_QWORD *)(v8 + 2208) + v29 + 8));
                    v28 = *(unsigned int *)(v8 + 2204);
                  }
                  v29 += 16;
                }
              }
            }
            else
            {
              v28 = *(unsigned int *)(v8 + 2204);
              if ( (_DWORD)v28 )
                goto LABEL_44;
            }
          }
        }
      }
      else if ( (debug_mdl & 8) != 0 && !debug_priority )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_vfe_bus_ver3_get_constraint_errors",
          728,
          "VFE:%u out:%d out rsrc node or data is NULL",
          *(_DWORD *)(v35 + 8),
          v20);
      }
      v20 = v34 + 1;
    }
    while ( v34 + 1 < (unsigned __int64)*(unsigned int *)(v8 + 1964) );
  }
LABEL_14:
  if ( (v32 & 0x40000000) != 0 )
  {
    v12 = *(_DWORD *)(a2 + 24);
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_bus_ver3_handle_err_irq_bottom_half",
      3533,
      "VFE[%u] CCIF protocol violation occurred at [%llu: %09llu]",
      *(_DWORD *)(v35 + 8),
      *(_QWORD *)(a2 + 72),
      *(_QWORD *)(a2 + 80));
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_bus_ver3_handle_err_irq_bottom_half",
      3534,
      "Violation status: 0x%x",
      v12);
    cam_vfe_check_violations("CCIF", v12, v35, &v36, v37);
  }
  if ( v32 < 0 && v37[0] == 1 )
  {
    LODWORD(v39) = 1;
    if ( (debug_mdl & 8) != 0 && !debug_priority )
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_vfe_bus_ver3_handle_err_irq_bottom_half",
        3541,
        "HWPD image size violation");
  }
  cam_vfe_bus_ver3_put_evt_payload(v35, v45);
  v13 = *(_DWORD *)(v35 + 8);
  HIDWORD(v42) = 2;
  HIDWORD(v41) = v13;
  v14 = *(_DWORD **)(v8 + 1912);
  LODWORD(v40) = 6;
  v38 = 3;
  v44 = &v38;
  if ( v14 )
  {
    v15 = v36;
    if ( v36 )
    {
      v16 = 12288;
      do
      {
        if ( (v15 & 1) != 0 )
        {
          v18 = *(_DWORD **)(v8 + 1912);
          v19 = *(_QWORD *)(v35 + 64);
          LODWORD(v41) = v16;
          if ( *(v18 - 1) != 414296116 )
            __break(0x8228u);
          ((void (__fastcall *)(__int64, _QWORD, __int64 *))v18)(v19, 0, &v40);
        }
        v17 = v15 >= 2;
        ++v16;
        v15 >>= 1;
      }
      while ( v17 );
    }
    else
    {
      v31 = *(_QWORD *)(v35 + 64);
      LODWORD(v41) = 44;
      if ( *(v14 - 1) != 414296116 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _QWORD, __int64 *))v14)(v31, 0, &v40);
    }
  }
  result = 0;
LABEL_57:
  _ReadStatusReg(SP_EL0);
  return result;
}
