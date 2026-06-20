__int64 __fastcall sde_encoder_phys_cmd_enable_helper(__int64 a1)
{
  unsigned int disp_op; // w21
  __int64 result; // x0
  __int64 v6; // x20
  __int64 v7; // x21
  _DWORD *v8; // x8
  __int64 v9; // x0
  _BOOL8 v10; // x1
  __int64 (__fastcall *v11)(__int64, __int64); // x8
  __int64 v12; // x9
  __int64 v13; // x9
  __int64 v14; // x8
  __int64 v15; // x8

  if ( !a1 || !*(_QWORD *)(a1 + 416) || !*(_QWORD *)(a1 + 496) || !*(_QWORD *)(a1 + 424) )
    return printk(&unk_26FF61, "sde_encoder_phys_cmd_enable_helper");
  disp_op = sde_encoder_get_disp_op(*(_QWORD *)a1);
  sde_encoder_helper_split_config((__int64 **)a1, *(_DWORD *)(a1 + 672));
  result = sde_encoder_phys_cmd_pingpong_config(a1);
  if ( disp_op >= 3 )
  {
    __break(0x5512u);
    __asm { FMLS            H2, H14, V8.H[5] }
    return sde_encoder_phys_cmd_connect_te(result);
  }
  else
  {
    v6 = *(_QWORD *)(a1 + 424);
    v7 = v6 + 8LL * disp_op;
    v8 = *(_DWORD **)(v7 + 1064);
    if ( v8 )
    {
      v9 = *(_QWORD *)(a1 + 424);
      v10 = *(_DWORD *)(a1 + 800) != 0;
      if ( *(v8 - 1) != -765163532 )
        __break(0x8228u);
      result = ((__int64 (__fastcall *)(__int64, _BOOL8, _QWORD))v8)(v9, v10, 0);
    }
    v11 = *(__int64 (__fastcall **)(__int64, __int64))(v7 + 1160);
    if ( v11 )
    {
      v12 = *(_QWORD *)a1;
      if ( *(_QWORD *)a1 )
        LOBYTE(v12) = *(_BYTE *)(v12 + 4720);
      if ( *((_DWORD *)v11 - 1) != -1839426449 )
        __break(0x8228u);
      result = v11(v6, v12 & 1);
    }
    if ( *(_BYTE *)(*(_QWORD *)a1 + 1313LL) == 1 )
    {
      v13 = *(_QWORD *)(a1 + 8);
      if ( v13 )
      {
        if ( *(_DWORD *)(v13 + 4676) && (*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 424) + 40LL) + 32LL) & 0x40000) == 0 )
          *(_BYTE *)(*(_QWORD *)a1 + 1314LL) = 1;
      }
    }
    v14 = *(_QWORD *)(a1 + 8);
    if ( !v14 )
      return sde_encoder_phys_cmd_update_flush_mask(a1);
    v15 = *(_QWORD *)(v14 + 2512);
    if ( !v15 || *(_DWORD *)(v15 + 1376) != 10 || *(_DWORD *)(a1 + 664) != 3 )
      return sde_encoder_phys_cmd_update_flush_mask(a1);
  }
  return result;
}
