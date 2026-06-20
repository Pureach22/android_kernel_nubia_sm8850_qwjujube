__int64 __fastcall cam_vfe_bus_ver3_handle_vfe_out_done_bottom_half(int *a1, __int64 a2)
{
  __int64 v2; // x20
  unsigned int *v3; // x23
  int v4; // w8
  unsigned int v5; // w19
  char v6; // w9
  unsigned int v7; // w23
  char v8; // w8
  int v9; // w7
  int v10; // w6
  int *v11; // x19
  __int64 v12; // x23
  unsigned int v13; // w11
  int v14; // w8
  unsigned int v15; // w10
  int v16; // w9
  __int64 v17; // x0
  __int64 v18; // x8
  void (__fastcall *v19)(__int64, __int64, __int64 *); // x8
  __int64 v20; // x1
  const char *v22; // x9
  const char *v23; // x13
  const char *v24; // x10
  __int64 v25; // x21
  int *v26; // x22
  const char *v27; // x12
  int *v28; // [xsp+28h] [xbp-58h]
  __int64 v29; // [xsp+30h] [xbp-50h]
  unsigned __int64 v30; // [xsp+38h] [xbp-48h] BYREF
  __int64 v31; // [xsp+40h] [xbp-40h]
  __int64 v32; // [xsp+48h] [xbp-38h] BYREF
  unsigned __int64 v33; // [xsp+50h] [xbp-30h]
  __int64 v34; // [xsp+58h] [xbp-28h]
  __int64 v35; // [xsp+60h] [xbp-20h]
  unsigned __int64 *v36; // [xsp+68h] [xbp-18h]
  _QWORD v37[2]; // [xsp+70h] [xbp-10h] BYREF

  v37[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *((_QWORD *)a1 + 3);
  v36 = nullptr;
  v37[0] = a2;
  v34 = 0;
  v35 = 0;
  v32 = 0;
  v33 = 0;
  v30 = 0;
  v31 = 0;
  if ( a2 )
  {
    v3 = *(unsigned int **)(*(_QWORD *)(v2 + 56) + 24LL);
    if ( !v3[9] || v3[8] )
    {
      v4 = *(_DWORD *)(a2 + 40);
      if ( (v3[6] & v4) != 0 || *(_BYTE *)(a2 + 124) == 1 && (v3[7] & v4) != 0 || *(_BYTE *)(a2 + 125) == 1 )
      {
        v5 = 0;
        *(_DWORD *)(a2 + 36) = 5;
        v6 = debug_mdl;
        if ( (debug_mdl & 8) == 0 )
          goto LABEL_7;
      }
      else
      {
        v5 = -1;
        v6 = debug_mdl;
        if ( (debug_mdl & 8) == 0 )
          goto LABEL_7;
      }
      if ( !debug_priority )
      {
        v27 = "N";
        if ( *(_BYTE *)(a2 + 124) )
          v27 = "Y";
        v28 = a1;
        v29 = a2;
        ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          v6 & 8,
          4,
          "cam_vfe_bus_ver3_handle_comp_done_bottom_half",
          1926,
          "VFE:%u comp_grp:%d is_hw_ctxt_comp_irq:%s comp_done_mask:0x%x mc_comp_done_mask:0x%x Bus IRQ status_0:0x%x rc:%d",
          *(_DWORD *)(*((_QWORD *)v3 + 1) + 8LL),
          *v3,
          v27,
          v3[6],
          v3[7],
          v4,
          v5);
        a1 = v28;
        a2 = v29;
      }
LABEL_7:
      v7 = *v3;
      v8 = debug_mdl;
      if ( (debug_mdl & 8) == 0 )
        goto LABEL_17;
      goto LABEL_16;
    }
    v9 = *v3;
    v10 = *(_DWORD *)(*((_QWORD *)v3 + 1) + 8LL);
    v11 = a1;
    v12 = a2;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_bus_ver3_handle_comp_done_bottom_half",
      1907,
      "VFE:%u Invalid comp_grp:%u is_master:%u",
      v10,
      v9,
      0);
    a1 = v11;
    a2 = v12;
  }
  v7 = 0;
  v5 = -1;
  v8 = debug_mdl;
  if ( (debug_mdl & 8) == 0 )
    goto LABEL_17;
LABEL_16:
  if ( !debug_priority )
  {
    if ( *(_BYTE *)(v2 + 133) )
      v22 = "Y";
    else
      v22 = "N";
    if ( *(_BYTE *)(v2 + 134) )
      v23 = "Y";
    else
      v23 = "N";
    if ( *(_BYTE *)(a2 + 125) )
      v24 = "Y";
    else
      v24 = "N";
    v25 = a2;
    v26 = a1;
    ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v8 & 8,
      4,
      "cam_vfe_bus_ver3_handle_vfe_out_done_bottom_half",
      2752,
      "VFE:%u out_type:0x%x mc_based:%s cntxt_cfg_except:%s is_early_done:%s comp_grp_id:%d rc:%d",
      *(_DWORD *)(*(_QWORD *)(v2 + 16) + 8LL),
      *(_DWORD *)(v2 + 8),
      v22,
      v23,
      v24,
      v7,
      v5);
    a1 = v26;
    a2 = v25;
    if ( v5 )
      goto LABEL_22;
    goto LABEL_18;
  }
LABEL_17:
  if ( v5 )
    goto LABEL_22;
LABEL_18:
  v13 = *(_DWORD *)(*((_QWORD *)a1 + 2) + 4LL);
  v36 = &v30;
  v14 = *a1;
  v15 = a1[1];
  HIDWORD(v34) = 2;
  v16 = *(_DWORD *)(a2 + 120);
  v17 = *(_QWORD *)(v2 + 96);
  LODWORD(v32) = v14;
  v18 = *(_QWORD *)(v2 + 16);
  v33 = __PAIR64__(v13, v15);
  v30 = __PAIR64__(v7, v15);
  LOWORD(v15) = *(_WORD *)(a2 + 124);
  v19 = *(void (__fastcall **)(__int64, __int64, __int64 *))(v18 + 34680);
  v20 = *(unsigned int *)(a2 + 36);
  LODWORD(v31) = v16;
  WORD2(v31) = v15;
  if ( v19 )
  {
    if ( *((_DWORD *)v19 - 1) != 414296116 )
      __break(0x8228u);
    v19(v17, v20, &v32);
  }
LABEL_22:
  cam_vfe_bus_ver3_put_evt_payload(*(_QWORD *)(v2 + 16), v37);
  _ReadStatusReg(SP_EL0);
  return v5;
}
