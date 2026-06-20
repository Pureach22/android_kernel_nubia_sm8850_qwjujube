__int64 __fastcall sde_encoder_prepare_commit(__int64 a1, __int64 a2)
{
  __int64 v3; // x8
  __int64 v4; // x0
  unsigned int disp_op; // w20
  __int64 v6; // x8
  int v7; // w7
  __int64 v8; // x8
  int v9; // w4
  void *v10; // x0
  __int64 v11; // x21
  void (__fastcall *v12)(_QWORD); // x8
  __int64 v13; // x0
  __int64 v14; // x0
  void (*v15)(void); // x8
  __int64 v16; // x22
  void (__fastcall *v17)(_QWORD); // x8
  __int64 v18; // x0
  __int64 v19; // x0
  void (*v20)(void); // x8
  __int64 v21; // x22
  void (__fastcall *v22)(_QWORD); // x8
  __int64 v23; // x0
  __int64 v24; // x0
  void (*v25)(void); // x8
  __int64 v26; // x22
  void (__fastcall *v27)(_QWORD); // x8
  __int64 v28; // x0
  __int64 v29; // x0
  void (*v30)(void); // x8
  __int64 v31; // x8
  char v33; // [xsp+0h] [xbp+0h]

  if ( !a1 )
  {
    printk(&unk_26FCAB, "sde_encoder_prepare_commit");
    LODWORD(v11) = -22;
    return (unsigned int)v11;
  }
  if ( !*(_QWORD *)a1 )
  {
    v10 = &unk_26FCAB;
LABEL_14:
    printk(v10, "sde_encoder_get_kms");
    disp_op = 0;
    v6 = *(_QWORD *)(a1 + 328);
    if ( !v6 )
      goto LABEL_15;
    goto LABEL_6;
  }
  v3 = *(_QWORD *)(*(_QWORD *)a1 + 56LL);
  if ( !v3 || (v4 = *(_QWORD *)(v3 + 8)) == 0 )
  {
    v10 = &unk_234896;
    goto LABEL_14;
  }
  disp_op = sde_kms_get_disp_op(v4, a2);
  v6 = *(_QWORD *)(a1 + 328);
  if ( !v6 )
    goto LABEL_15;
LABEL_6:
  sde_connector_set_qsync_params(*(_QWORD *)(v6 + 8));
  sde_connector_set_vrr_params(*(_QWORD *)(*(_QWORD *)(a1 + 328) + 8LL));
  if ( *(_BYTE *)(a1 + 749) == 1 )
  {
    v8 = *(_QWORD *)(*(_QWORD *)a1 + 56LL);
    v9 = *(_DWORD *)(a1 + 4916);
    if ( *(_QWORD *)(*(_QWORD *)(v8 + 8) + 2128LL) )
    {
      sde_evtlog_log(sde_dbg_base_evtlog, "sde_encoder_vhm_wakelock", 2277, -1, v9, 1, -1059143953, v7, v33);
    }
    else if ( !v9 )
    {
      *(_DWORD *)(a1 + 4916) = 1;
      sde_power_wakelock_ctrl(v8 + 16, 1);
    }
  }
LABEL_15:
  if ( !*(_DWORD *)(a1 + 196) )
  {
LABEL_78:
    LODWORD(v11) = 0;
    goto LABEL_79;
  }
  v11 = *(_QWORD *)(a1 + 200);
  if ( v11 )
  {
    v12 = *(void (__fastcall **)(_QWORD))(v11 + 24);
    if ( v12 )
    {
      v13 = *(_QWORD *)(a1 + 200);
      if ( *((_DWORD *)v12 - 1) != -511414616 )
        __break(0x8228u);
      v12(v13);
    }
    v14 = *(_QWORD *)(v11 + 416);
    LODWORD(v11) = *(_DWORD *)(v11 + 832) == 5 ? -110 : 0;
    if ( v14 && (*(_BYTE *)(a1 + 1313) & 1) == 0 )
    {
      if ( disp_op > 2 )
        goto LABEL_77;
      v15 = *(void (**)(void))(v14 + 8LL * disp_op + 688);
      if ( v15 )
      {
        if ( *((_DWORD *)v15 - 1) != 1800103338 )
          __break(0x8228u);
        v15();
      }
    }
  }
  if ( *(_DWORD *)(a1 + 196) < 2u )
    goto LABEL_79;
  v16 = *(_QWORD *)(a1 + 208);
  if ( v16 )
  {
    v17 = *(void (__fastcall **)(_QWORD))(v16 + 24);
    if ( v17 )
    {
      v18 = *(_QWORD *)(a1 + 208);
      if ( *((_DWORD *)v17 - 1) != -511414616 )
        __break(0x8228u);
      v17(v18);
    }
    v19 = *(_QWORD *)(v16 + 416);
    if ( *(_DWORD *)(v16 + 832) == 5 )
      LODWORD(v11) = -110;
    if ( v19 && (*(_BYTE *)(a1 + 1313) & 1) == 0 )
    {
      if ( disp_op > 2 )
        goto LABEL_77;
      v20 = *(void (**)(void))(v19 + 8LL * disp_op + 688);
      if ( v20 )
      {
        if ( *((_DWORD *)v20 - 1) != 1800103338 )
          __break(0x8228u);
        v20();
      }
    }
  }
  if ( *(_DWORD *)(a1 + 196) < 3u )
    goto LABEL_79;
  v21 = *(_QWORD *)(a1 + 216);
  if ( v21 )
  {
    v22 = *(void (__fastcall **)(_QWORD))(v21 + 24);
    if ( v22 )
    {
      v23 = *(_QWORD *)(a1 + 216);
      if ( *((_DWORD *)v22 - 1) != -511414616 )
        __break(0x8228u);
      v22(v23);
    }
    v24 = *(_QWORD *)(v21 + 416);
    if ( *(_DWORD *)(v21 + 832) == 5 )
      LODWORD(v11) = -110;
    if ( v24 && (*(_BYTE *)(a1 + 1313) & 1) == 0 )
    {
      if ( disp_op > 2 )
        goto LABEL_77;
      v25 = *(void (**)(void))(v24 + 8LL * disp_op + 688);
      if ( v25 )
      {
        if ( *((_DWORD *)v25 - 1) != 1800103338 )
          __break(0x8228u);
        v25();
      }
    }
  }
  if ( *(_DWORD *)(a1 + 196) < 4u )
    goto LABEL_79;
  v26 = *(_QWORD *)(a1 + 224);
  if ( !v26 )
    goto LABEL_76;
  v27 = *(void (__fastcall **)(_QWORD))(v26 + 24);
  if ( v27 )
  {
    v28 = *(_QWORD *)(a1 + 224);
    if ( *((_DWORD *)v27 - 1) != -511414616 )
      __break(0x8228u);
    v27(v28);
  }
  v29 = *(_QWORD *)(v26 + 416);
  if ( *(_DWORD *)(v26 + 832) == 5 )
    LODWORD(v11) = -110;
  if ( !v29 || (*(_BYTE *)(a1 + 1313) & 1) != 0 )
    goto LABEL_76;
  if ( disp_op > 2 )
  {
LABEL_77:
    __break(0x5512u);
    goto LABEL_78;
  }
  v30 = *(void (**)(void))(v29 + 8LL * disp_op + 688);
  if ( v30 )
  {
    if ( *((_DWORD *)v30 - 1) != 1800103338 )
      __break(0x8228u);
    v30();
  }
LABEL_76:
  if ( *(_DWORD *)(a1 + 196) > 4u )
    goto LABEL_77;
LABEL_79:
  v31 = *(_QWORD *)(a1 + 328);
  if ( v31 && *(_QWORD *)(v31 + 8) && (unsigned int)sde_connector_prepare_commit() )
    printk(&unk_238384, "sde_encoder_prepare_commit");
  return (unsigned int)v11;
}
