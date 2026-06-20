__int64 __fastcall sde_encoder_phys_vid_get_underrun_line_count(__int64 a1)
{
  unsigned int disp_op; // w0
  unsigned int v3; // w8
  __int64 v4; // x0
  __int64 v5; // x22
  void (*v6)(void); // x8
  char v7; // w21
  __int64 (*v8)(void); // x8
  unsigned int v9; // w20
  __int64 (*v11)(void); // x8
  int v12; // w4

  _ReadStatusReg(SP_EL0);
  if ( !a1
    || (disp_op = sde_encoder_get_disp_op(*(_QWORD *)a1), *(_DWORD *)(a1 + 664) == 3)
    || (v3 = disp_op, (v4 = *(_QWORD *)(a1 + 424)) == 0) )
  {
    v9 = -22;
LABEL_14:
    _ReadStatusReg(SP_EL0);
    return v9;
  }
  if ( v3 < 3 )
  {
    v5 = v3;
    v6 = *(void (**)(void))(v4 + 8LL * v3 + 200);
    if ( v6 )
    {
      if ( *((_DWORD *)v6 - 1) != -2009615442 )
        __break(0x8228u);
      v6();
      v4 = *(_QWORD *)(a1 + 424);
    }
    v7 = -83;
    v8 = *(__int64 (**)(void))(v4 + 8 * v5 + 296);
    if ( v8 )
    {
      if ( *((_DWORD *)v8 - 1) != 1550245701 )
        __break(0x8228u);
      v9 = v8();
      v4 = *(_QWORD *)(a1 + 424);
    }
    else
    {
      v9 = -340923475;
    }
    v11 = *(__int64 (**)(void))(v4 + 8 * v5 + 1184);
    if ( v11 )
    {
      if ( *((_DWORD *)v11 - 1) != 1550245701 )
        __break(0x8228u);
      v7 = v11();
    }
    if ( *(_QWORD *)a1 )
      v12 = *(_DWORD *)(*(_QWORD *)a1 + 24LL);
    else
      v12 = -1;
    sde_evtlog_log(sde_dbg_base_evtlog, "sde_encoder_phys_vid_get_underrun_line_count", 2770, -1, v12, v9, 0, 0, v7);
    goto LABEL_14;
  }
  __break(0x5512u);
  return sde_encoder_phys_vid_enact_updated_qsync_state();
}
