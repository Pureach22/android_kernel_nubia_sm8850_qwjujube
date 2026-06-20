__int64 __fastcall sde_encoder_avoid_prog_fetch_region(__int64 **a1, __int64 a2)
{
  __int64 v4; // x8
  __int64 v5; // x8
  unsigned int disp_op; // w0
  void *v7; // x0
  __int64 (__fastcall *v8)(_QWORD); // x9
  __int64 *v9; // x0
  unsigned int v10; // w21
  unsigned int v11; // w22
  unsigned int v12; // w23

  if ( *a1 )
  {
    v4 = **a1;
    if ( v4 )
    {
      v5 = *(_QWORD *)(v4 + 56);
      if ( v5 && *(_QWORD *)(v5 + 8) )
      {
        disp_op = sde_kms_get_disp_op();
        if ( disp_op < 3 )
          goto LABEL_11;
        __break(0x5512u);
      }
      v7 = &unk_234896;
    }
    else
    {
      v7 = &unk_26FCAB;
    }
    printk(v7, "sde_encoder_get_kms");
  }
  disp_op = 0;
LABEL_11:
  v8 = (__int64 (__fastcall *)(_QWORD))a1[53][disp_op + 34];
  if ( v8 )
  {
    v9 = a1[53];
    if ( *((_DWORD *)v8 - 1) != 1550245701 )
      __break(0x8229u);
    v10 = v8(v9);
  }
  else
  {
    v10 = 0;
  }
  v11 = *((_DWORD *)a1 + 576) + 500;
  v12 = *((unsigned __int16 *)a1 + 270)
      - *((_DWORD *)a1 + 586)
      - (500 * (unsigned int)*((unsigned __int16 *)a1 + 270) * *(_DWORD *)(a2 + 3944) + 999999) / 0xF4240;
  if ( v11 >= 0x7D1 )
  {
    printk(&unk_25E73E, "_sde_encoder_avoid_prog_fetch_region");
    v11 = 2000;
    if ( v10 <= v12 )
      return sde_evtlog_log(
               sde_dbg_base_evtlog,
               "_sde_encoder_avoid_prog_fetch_region",
               5818,
               -1,
               v10,
               v12,
               *(_DWORD *)(a2 + 3944),
               *((_DWORD *)a1 + 576),
               v11);
    goto LABEL_18;
  }
  if ( v10 > v12 )
LABEL_18:
    usleep_range_state(v11, v11 + 10, 2);
  return sde_evtlog_log(
           sde_dbg_base_evtlog,
           "_sde_encoder_avoid_prog_fetch_region",
           5818,
           -1,
           v10,
           v12,
           *(_DWORD *)(a2 + 3944),
           *((_DWORD *)a1 + 576),
           v11);
}
