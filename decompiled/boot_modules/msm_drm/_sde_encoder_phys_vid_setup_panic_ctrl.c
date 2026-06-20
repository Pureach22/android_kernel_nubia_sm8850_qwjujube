__int64 __fastcall sde_encoder_phys_vid_setup_panic_ctrl(__int64 a1)
{
  __int64 v2; // x8
  __int64 v3; // x22
  _BOOL4 v4; // w24
  unsigned int disp_op; // w20
  int v6; // w25
  __int64 v7; // x0
  unsigned int v8; // w26
  unsigned int v9; // w21
  void (*v10)(void); // x8
  int bw_update_time_lines; // w23
  _BOOL4 v12; // w8
  unsigned int v13; // w11
  unsigned int v14; // w7
  __int64 result; // x0
  __int64 (*v16)(void); // x8

  _ReadStatusReg(SP_EL0);
  v3 = *(_QWORD *)a1;
  v2 = *(_QWORD *)(a1 + 8);
  if ( v2 )
    v4 = *(_DWORD *)(v2 + 4676) != 0;
  else
    v4 = 0;
  disp_op = sde_encoder_get_disp_op(v3);
  v6 = *(_DWORD *)(a1 + 2764);
  v7 = *(_QWORD *)(a1 + 424);
  v8 = *(_DWORD *)(v3 + 4808);
  v9 = *(_DWORD *)(a1 + 2296) + *(unsigned __int16 *)(a1 + 534) + *(_DWORD *)(a1 + 2704) + *(_DWORD *)(a1 + 2716);
  if ( v7 )
  {
    if ( disp_op >= 3 )
      goto LABEL_23;
    v10 = *(void (**)(void))(v7 + 8LL * disp_op + 200);
    if ( v10 )
    {
      if ( *((_DWORD *)v10 - 1) != -2009615442 )
        __break(0x8228u);
      v10();
    }
  }
  bw_update_time_lines = sde_encoder_helper_get_bw_update_time_lines(v3);
  *(_DWORD *)(a1 + 2344) = 0;
  if ( v8 )
    v12 = v4;
  else
    v12 = 0;
  v13 = *(unsigned __int16 *)(a1 + 540);
  if ( v12 )
    v13 = (v8 + v6 * *(unsigned __int16 *)(a1 + 540) - 1) / v8;
  v14 = -3 - (bw_update_time_lines + *(_DWORD *)(v3 + 3952)) + v13;
  if ( v9 >= v14 )
    v9 = -1;
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "_sde_encoder_phys_vid_setup_panic_ctrl",
    627,
    -1,
    *(_DWORD *)(*(_QWORD *)(a1 + 424) + 32LL) - 1,
    1,
    v9,
    v14,
    *(_WORD *)(a1 + 534));
  if ( disp_op > 2 )
LABEL_23:
    __break(0x5512u);
  result = *(_QWORD *)(a1 + 424);
  v16 = *(__int64 (**)(void))(result + 8LL * disp_op + 1328);
  if ( v16 )
  {
    if ( *((_DWORD *)v16 - 1) != 881512259 )
      __break(0x8228u);
    result = v16();
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
