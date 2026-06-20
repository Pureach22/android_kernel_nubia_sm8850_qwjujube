__int64 __fastcall sde_encoder_check_prog_fetch_region(__int64 a1)
{
  __int64 v1; // x23
  int v3; // w20
  __int64 v4; // x8
  __int64 result; // x0
  unsigned int v6; // w8
  __int64 v7; // x9
  __int64 (*v8)(void); // x8
  void *v9; // x0

  _ReadStatusReg(SP_EL0);
  if ( !a1 )
  {
    result = printk(&unk_26FCAB, "sde_encoder_check_curr_mode");
LABEL_24:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v1 = *(_QWORD *)(a1 + 328);
  v3 = *(_DWORD *)(a1 + 648);
  if ( !*(_QWORD *)a1 )
  {
    v9 = &unk_26FCAB;
    goto LABEL_20;
  }
  v4 = *(_QWORD *)(*(_QWORD *)a1 + 56LL);
  if ( !v4 || !*(_QWORD *)(v4 + 8) )
  {
    v9 = &unk_234896;
LABEL_20:
    result = printk(v9, "sde_encoder_get_kms");
    v6 = 0;
    goto LABEL_6;
  }
  result = sde_kms_get_disp_op();
  v6 = result;
LABEL_6:
  if ( *(_DWORD *)(a1 + 640) != 16 )
    goto LABEL_24;
  if ( v3 != 1 )
    goto LABEL_24;
  if ( !*(_QWORD *)(a1 + 4960) )
    goto LABEL_24;
  result = *(_QWORD *)(v1 + 424);
  if ( !result )
    goto LABEL_24;
  if ( v6 < 3 )
  {
    v7 = result + 8LL * v6;
    v8 = *(__int64 (**)(void))(v7 + 200);
    if ( v8 && *(_QWORD *)(v7 + 272) )
    {
      if ( *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 328) + 8LL) + 2512LL) )
      {
        if ( *((_DWORD *)v8 - 1) != -2009615442 )
          __break(0x8228u);
      }
      else if ( *((_DWORD *)v8 - 1) != -2009615442 )
      {
        __break(0x8228u);
      }
      result = v8();
    }
    goto LABEL_24;
  }
  __break(0x5512u);
  return sde_encoder_post_commit_bl_sr_work();
}
