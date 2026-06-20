__int64 __fastcall cam_sfe_top_handle_err_irq_bottom_half(_QWORD *a1, __int64 a2)
{
  __int64 v3; // x8
  int v4; // w26
  _DWORD *v5; // x9
  __int64 v6; // x21
  __int64 v8; // x8
  __int64 v9; // x27
  unsigned __int64 v10; // x28
  __int64 v11; // x9
  const char *v12; // x6
  __int64 v13; // x8
  _DWORD *v14; // x8
  __int64 v15; // x0
  unsigned int v16; // w20
  int v18; // [xsp+1Ch] [xbp-44h] BYREF
  __int64 v19; // [xsp+20h] [xbp-40h]
  __int64 v20; // [xsp+28h] [xbp-38h] BYREF
  _DWORD v21[2]; // [xsp+30h] [xbp-30h] BYREF
  __int64 v22; // [xsp+38h] [xbp-28h]
  __int64 v23; // [xsp+40h] [xbp-20h]
  __int64 v24; // [xsp+48h] [xbp-18h]
  int *v25; // [xsp+50h] [xbp-10h]
  __int64 v26; // [xsp+58h] [xbp-8h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *a1;
  v24 = 0;
  v25 = nullptr;
  v4 = *(_DWORD *)(a2 + 24);
  v22 = 0;
  v23 = 0;
  LODWORD(v3) = *(_DWORD *)(v3 + 20);
  v20 = a2;
  v21[1] = 0;
  v21[0] = 10;
  v5 = (_DWORD *)a1[3];
  HIDWORD(v22) = v3;
  HIDWORD(v23) = 7;
  if ( (*v5 & v4) != 0 )
  {
    v6 = *(unsigned int *)(a2 + 28);
    v19 = 0;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x40000000,
      3,
      "cam_sfe_top_handle_err_irq_bottom_half",
      1859,
      "Violation status 0x%x",
      v6);
    v8 = a1[4037];
    if ( *(_DWORD *)(v8 + 116) )
    {
      v9 = 0;
      v10 = 0;
      do
      {
        v11 = *(_QWORD *)(v8 + 120);
        if ( (*(_DWORD *)(v11 + v9) & v4) != 0 )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            0x40000000,
            1,
            "cam_sfe_top_print_top_irq_error",
            1823,
            "SFE[%u] %s occurred at [%llu: %09llu]",
            *(_DWORD *)(*a1 + 20LL),
            *(const char **)(v11 + v9 + 8),
            *(_QWORD *)(a2 + 40),
            *(_QWORD *)(a2 + 48));
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            0x40000000,
            1,
            "cam_sfe_top_print_top_irq_error",
            1824,
            "%s",
            *(const char **)(*(_QWORD *)(a1[4037] + 120LL) + v9 + 16));
          v8 = a1[4037];
          v12 = *(const char **)(*(_QWORD *)(v8 + 120) + v9 + 24);
          if ( v12 )
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              0x40000000,
              1,
              "cam_sfe_top_print_top_irq_error",
              1827,
              "Debug: %s",
              v12);
            v8 = a1[4037];
          }
        }
        ++v10;
        v9 += 32;
      }
      while ( v10 < *(unsigned int *)(v8 + 116) );
    }
    if ( (*(_DWORD *)(a1[2] + 164LL) & v4) != 0 )
    {
      v13 = *(_QWORD *)(v8 + 24);
      if ( v13 )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x40000000,
          1,
          "cam_sfe_top_print_ipp_violation_info",
          1805,
          "SFE[%u] IPP Violation Module id: [%u %s]",
          *(_DWORD *)(*a1 + 20LL),
          *(_DWORD *)(v13 + 16 * v6),
          *(const char **)(v13 + 16 * v6 + 8));
    }
    v18 = 3;
    v25 = &v18;
    cam_sfe_top_print_debug_reg_info(a1);
    v14 = (_DWORD *)a1[4035];
    if ( v14 )
    {
      v15 = a1[4033];
      if ( *(v14 - 1) != 414296116 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _QWORD, _DWORD *))v14)(v15, 0, v21);
    }
    v16 = 3;
  }
  else
  {
    v16 = 4;
  }
  cam_sfe_top_put_evt_payload(a1, &v20);
  _ReadStatusReg(SP_EL0);
  return v16;
}
