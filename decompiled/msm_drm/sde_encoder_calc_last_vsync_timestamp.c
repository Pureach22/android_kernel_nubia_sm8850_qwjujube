__int64 __fastcall sde_encoder_calc_last_vsync_timestamp(__int64 a1)
{
  __int64 v2; // x22
  unsigned int v3; // w20
  __int64 v4; // x8
  unsigned int disp_op; // w8
  _BOOL4 v6; // w9
  __int64 v7; // x0
  signed __int64 v8; // x2
  __int64 v9; // x21
  __int64 v10; // x10
  __int64 (*v11)(void); // x8
  void (*v12)(void); // x9
  unsigned __int64 v13; // x2
  int v14; // w0
  void *v15; // x0

  _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(a1 + 328);
  if ( !a1 )
  {
    printk(&unk_26FCAB, "sde_encoder_get_fps");
    printk(&unk_26FCAB, "sde_encoder_check_curr_mode");
    printk(&unk_26FCAB, "sde_encoder_check_curr_mode");
    v6 = 0;
    v3 = 0;
    disp_op = 0;
    if ( v2 )
      goto LABEL_7;
LABEL_25:
    v8 = 0;
LABEL_26:
    _ReadStatusReg(SP_EL0);
    return v8;
  }
  v3 = *(_DWORD *)(a1 + 3944);
  if ( *(_QWORD *)a1 )
  {
    v4 = *(_QWORD *)(*(_QWORD *)a1 + 56LL);
    if ( v4 && *(_QWORD *)(v4 + 8) )
    {
      disp_op = sde_kms_get_disp_op();
      goto LABEL_6;
    }
    v15 = &unk_234896;
  }
  else
  {
    v15 = &unk_26FCAB;
  }
  printk(v15, "sde_encoder_get_kms");
  disp_op = 0;
LABEL_6:
  v6 = (unsigned int)(*(_DWORD *)(a1 + 648) - 1) < 2;
  if ( !v2 )
    goto LABEL_25;
LABEL_7:
  v7 = *(_QWORD *)(v2 + 424);
  v8 = 0;
  if ( !v7 || !v3 )
    goto LABEL_26;
  if ( disp_op < 3 )
  {
    v9 = disp_op;
    v10 = v7 + 8LL * disp_op;
    v11 = *(__int64 (**)(void))(v10 + 1136);
    if ( !v11 )
      v6 = 0;
    if ( v6 )
    {
      if ( (*(_QWORD *)(*(_QWORD *)(v7 + 40) + 32LL) & 0x400) == 0 )
      {
        v12 = *(void (**)(void))(v10 + 200);
        if ( v12 )
        {
          if ( *((_DWORD *)v12 - 1) != -2009615442 )
            __break(0x8229u);
          v12();
          v11 = *(__int64 (**)(void))(*(_QWORD *)(v2 + 424) + 8 * v9 + 1136);
        }
      }
      if ( *((_DWORD *)v11 - 1) != 15937386 )
        __break(0x8228u);
      v13 = v11();
      if ( a1 )
        v14 = *(_DWORD *)(a1 + 24);
      else
        v14 = -1;
      v8 = sde_encoder_event_timestamp_adjust(v14, v3, v13);
      goto LABEL_26;
    }
    goto LABEL_25;
  }
  __break(0x5512u);
  return sde_encoder_get_fps(v7 + 172);
}
