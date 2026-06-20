__int64 __fastcall cam_sfe_bus_handle_sfe_out_done_bottom_half(int *a1, _DWORD *a2)
{
  __int64 v2; // x20
  int *v3; // x23
  int v4; // w8
  unsigned int v5; // w19
  int v6; // w9
  unsigned int v7; // w23
  int v8; // w8
  int v9; // w6
  int *v10; // x23
  _DWORD *v11; // x24
  unsigned int v12; // w9
  int v13; // w10
  __int64 v14; // x1
  unsigned int v15; // w8
  int v16; // w8
  __int64 v17; // x0
  __int64 v18; // x10
  void (__fastcall *v19)(__int64, __int64, __int64 *); // x8
  _DWORD *v21; // x21
  int *v22; // x22
  int *v23; // x24
  _DWORD *v24; // [xsp+10h] [xbp-50h]
  unsigned __int64 v25; // [xsp+18h] [xbp-48h] BYREF
  __int64 v26; // [xsp+20h] [xbp-40h]
  __int64 v27; // [xsp+28h] [xbp-38h] BYREF
  unsigned __int64 v28; // [xsp+30h] [xbp-30h]
  __int64 v29; // [xsp+38h] [xbp-28h]
  __int64 v30; // [xsp+40h] [xbp-20h]
  unsigned __int64 *v31; // [xsp+48h] [xbp-18h]
  _QWORD v32[2]; // [xsp+50h] [xbp-10h] BYREF

  v32[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *((_QWORD *)a1 + 3);
  v32[0] = a2;
  v30 = 0;
  v31 = nullptr;
  v28 = 0;
  v29 = 0;
  v26 = 0;
  v27 = 0;
  v25 = 0;
  if ( !a2 )
  {
    v7 = 0;
    v5 = 1;
    v8 = debug_mdl;
    if ( (debug_mdl & 0x40000000) == 0 )
      goto LABEL_16;
    goto LABEL_15;
  }
  v3 = *(int **)(*(_QWORD *)(v2 + 40) + 24LL);
  if ( v3[5] && !v3[4] )
  {
    v9 = *v3;
    v10 = a1;
    v11 = a2;
    v5 = 1;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x40000000,
      1,
      "cam_sfe_bus_handle_comp_done_bottom_half",
      1725,
      "Invalid comp_grp:%u is_master:%u",
      v9,
      0);
    a1 = v10;
    a2 = v11;
    v7 = 0;
    v8 = debug_mdl;
    if ( (debug_mdl & 0x40000000) == 0 )
      goto LABEL_16;
    goto LABEL_15;
  }
  v4 = a2[5];
  if ( (v3[1] & v4) != 0 )
  {
    v5 = 0;
    a2[10] = 5;
    v6 = debug_mdl;
    if ( (debug_mdl & 0x40000000) == 0 )
      goto LABEL_12;
  }
  else
  {
    v5 = 1;
    v6 = debug_mdl;
    if ( (debug_mdl & 0x40000000) == 0 )
      goto LABEL_12;
  }
  if ( !debug_priority )
  {
    v24 = a2;
    v23 = a1;
    ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v6 & 0x40000000,
      4,
      "cam_sfe_bus_handle_comp_done_bottom_half",
      1739,
      "SFE:%d comp_grp:%d Bus IRQ status_0: 0x%X rc:%d",
      **((_DWORD **)v3 + 1),
      *v3,
      v4,
      v5);
    a2 = v24;
    a1 = v23;
  }
LABEL_12:
  v7 = *v3;
  v8 = debug_mdl;
  if ( (debug_mdl & 0x40000000) == 0 )
  {
LABEL_16:
    if ( v5 )
      goto LABEL_21;
    goto LABEL_17;
  }
LABEL_15:
  if ( debug_priority )
    goto LABEL_16;
  v21 = a2;
  v22 = a1;
  ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    v8 & 0x40000000,
    4,
    "cam_sfe_bus_handle_sfe_out_done_bottom_half",
    1764,
    "SFE:%d out_type:0x%x comp_grp_id:%d rc:%d",
    **(_DWORD **)(v2 + 8),
    *(_DWORD *)v2,
    v7,
    v5);
  a1 = v22;
  a2 = v21;
  if ( v5 )
    goto LABEL_21;
LABEL_17:
  v12 = a1[1];
  v13 = a2[24];
  v14 = (unsigned int)a2[10];
  v15 = *(_DWORD *)(*((_QWORD *)a1 + 2) + 4LL);
  LODWORD(v26) = v13;
  HIDWORD(v29) = 7;
  v28 = __PAIR64__(v15, v12);
  v31 = &v25;
  v16 = *a1;
  v17 = *(_QWORD *)(v2 + 104);
  v18 = *(_QWORD *)(v2 + 8);
  v25 = __PAIR64__(v7, v12);
  LODWORD(v27) = v16;
  v19 = *(void (__fastcall **)(__int64, __int64, __int64 *))(v18 + 27456);
  if ( v19 )
  {
    if ( *((_DWORD *)v19 - 1) != 414296116 )
      __break(0x8228u);
    v19(v17, v14, &v27);
  }
LABEL_21:
  cam_sfe_bus_wr_put_evt_payload(*(_QWORD *)(v2 + 8), v32);
  _ReadStatusReg(SP_EL0);
  return v5;
}
