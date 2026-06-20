__int64 __fastcall sde_encoder_update_periph_flush(unsigned int *a1, __int64 a2)
{
  __int64 v3; // x8
  __int64 v4; // x0
  unsigned int disp_op; // w20
  unsigned __int64 v6; // x8
  __int64 v7; // x22
  __int64 v8; // x26
  __int64 v9; // x0
  void (*v10)(void); // x10
  int v11; // w6
  int v12; // w7
  void *v14; // x0
  char vars0; // [xsp+0h] [xbp+0h]

  if ( !a1 )
  {
    printk(&unk_26FCAB, "sde_encoder_update_periph_flush");
    return 4294967274LL;
  }
  if ( *(_QWORD *)a1 )
  {
    v3 = *(_QWORD *)(*(_QWORD *)a1 + 56LL);
    if ( v3 )
    {
      v4 = *(_QWORD *)(v3 + 8);
      if ( v4 )
      {
        disp_op = sde_kms_get_disp_op(v4, a2);
        v6 = a1[49];
        if ( (_DWORD)v6 )
          goto LABEL_6;
        return 0;
      }
    }
    v14 = &unk_234896;
  }
  else
  {
    v14 = &unk_26FCAB;
  }
  printk(v14, "sde_encoder_get_kms");
  disp_op = 0;
  v6 = a1[49];
  if ( !(_DWORD)v6 )
    return 0;
LABEL_6:
  v7 = 0;
  while ( v7 != 4 )
  {
    v8 = *(_QWORD *)&a1[2 * v7 + 50];
    if ( (*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v8 + 424) + 40LL) + 32LL) & 0x400000) == 0 )
      return 4294967201LL;
    if ( v8 )
    {
      v9 = *(_QWORD *)(v8 + 416);
      if ( v9 )
      {
        if ( disp_op > 2 )
          break;
        v10 = *(void (**)(void))(v9 + 8LL * disp_op + 1192);
        if ( v10 )
        {
          if ( *((_DWORD *)v10 - 1) != 949740941 )
            __break(0x822Au);
          v10();
          sde_evtlog_log(
            sde_dbg_base_evtlog,
            "sde_encoder_update_periph_flush",
            7401,
            -1,
            *(_DWORD *)(*(_QWORD *)(v8 + 424) + 32LL),
            -1059143953,
            v11,
            v12,
            vars0);
          v6 = a1[49];
        }
      }
    }
    if ( ++v7 >= v6 )
      return 0;
  }
  __break(0x5512u);
  return sde_encoder_prepare_commit();
}
