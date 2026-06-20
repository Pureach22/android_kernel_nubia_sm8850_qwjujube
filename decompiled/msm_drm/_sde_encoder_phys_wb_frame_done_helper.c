__int64 __fastcall sde_encoder_phys_wb_frame_done_helper(__int64 a1, char a2)
{
  __int64 v4; // x20
  int v5; // w22
  unsigned int disp_op; // w23
  unsigned int v7; // w9
  unsigned int v14; // w11
  unsigned int v15; // w8
  unsigned int v18; // w10
  int v19; // w8
  __int64 v20; // x0
  int v21; // w9
  _DWORD *v22; // x10
  void (__fastcall *v23)(__int64, __int64); // x8
  __int64 v24; // x0
  void (*v25)(void); // x8
  __int64 v26; // x9
  void (*v27)(void); // x8
  void (*v28)(void); // x8
  int v29; // w4
  __int64 v30; // x9
  int v31; // w5
  __int64 result; // x0
  _QWORD v33[3]; // [xsp+48h] [xbp-18h] BYREF

  v33[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)a1;
  v33[0] = 0;
  v33[1] = 0;
  if ( v4 )
  {
    if ( (((__int64 (__fastcall *)(__int64))sde_encoder_in_clone_mode)(v4) & 1) != 0 )
      v4 = 0;
    else
      v4 = *(_QWORD *)(v4 + 4960);
  }
  if ( (a2 & 1) != 0 )
    v5 = 2;
  else
    v5 = 0;
  disp_op = sde_encoder_get_disp_op(*(_QWORD *)a1);
  if ( !*(_DWORD *)(a1 + 832) && *(_BYTE *)(a1 + 2290) != 1 )
    goto LABEL_50;
  if ( *(_QWORD *)(a1 + 392) )
  {
    v7 = *(_DWORD *)(a1 + 876);
    _X8 = (unsigned int *)(a1 + 876);
    while ( v7 )
    {
      __asm { PRFM            #0x11, [X8] }
      while ( 1 )
      {
        v14 = __ldxr(_X8);
        if ( v14 != v7 )
          break;
        if ( !__stlxr(v7 - 1, _X8) )
        {
          __dmb(0xBu);
          break;
        }
      }
      _ZF = v14 == v7;
      v7 = v14;
      if ( _ZF )
      {
        if ( *(_DWORD *)(a1 + 2944) && *(_DWORD *)(a1 + 876) >= *(_DWORD *)(a1 + 880) )
        {
          v19 = v5 | 1;
        }
        else
        {
          v15 = *(_DWORD *)(a1 + 880);
          do
          {
            if ( !v15 )
              break;
            _X12 = (unsigned int *)(a1 + 880);
            __asm { PRFM            #0x11, [X12] }
            while ( 1 )
            {
              v18 = __ldxr(_X12);
              if ( v18 != v15 )
                break;
              if ( !__stlxr(v15 - 1, _X12) )
              {
                __dmb(0xBu);
                break;
              }
            }
            _ZF = v18 == v15;
            v15 = v18;
          }
          while ( !_ZF );
          v19 = v5 | 0x11;
        }
        v20 = *(_QWORD *)a1;
        if ( *(_BYTE *)(a1 + 2290) )
          v21 = 48;
        else
          v21 = 8;
        v22 = *(_DWORD **)(a1 + 392);
        LOBYTE(v5) = v21 | v19;
        if ( *(v22 - 1) != -570463643 )
          __break(0x822Au);
        ((void (__fastcall *)(__int64, __int64, _QWORD))v22)(v20, a1, v21 | (unsigned int)v19);
        break;
      }
    }
  }
  if ( (*(_BYTE *)(a1 + 2290) & 1) == 0 )
  {
    v23 = *(void (__fastcall **)(__int64, __int64))(a1 + 368);
    if ( v23 )
    {
      v24 = *(_QWORD *)a1;
      if ( *((_DWORD *)v23 - 1) != 468003652 )
        __break(0x8228u);
      v23(v24, a1);
    }
  }
  if ( disp_op >= 3 )
    goto LABEL_69;
  v25 = *(void (**)(void))(*(_QWORD *)(a1 + 2680) + 8LL * disp_op + 568);
  if ( !v25 )
  {
LABEL_50:
    if ( (a2 & 1) == 0 )
      goto LABEL_59;
LABEL_51:
    if ( disp_op <= 2 )
    {
      v26 = *(_QWORD *)(a1 + 2680) + 8LL * disp_op;
      v27 = *(void (**)(void))(v26 + 520);
      if ( v27 && *(_QWORD *)(v26 + 544) )
      {
        if ( *((_DWORD *)v27 - 1) != -403367322 )
          __break(0x8228u);
        v27();
        v28 = *(void (**)(void))(*(_QWORD *)(a1 + 2680) + 8LL * disp_op + 544);
        if ( *((_DWORD *)v28 - 1) != 454009647 )
          __break(0x8228u);
        v28();
      }
      goto LABEL_59;
    }
LABEL_69:
    __break(0x5512u);
  }
  if ( *((_DWORD *)v25 - 1) != -403367322 )
    __break(0x8228u);
  v25();
  if ( (a2 & 1) != 0 )
    goto LABEL_51;
LABEL_59:
  if ( *(_QWORD *)a1 )
  {
    v29 = *(_DWORD *)(*(_QWORD *)a1 + 24LL);
    if ( !a1 )
      goto LABEL_65;
  }
  else
  {
    v29 = -1;
    if ( !a1 )
      goto LABEL_65;
  }
  v30 = *(_QWORD *)(a1 + 2864);
  if ( v30 )
  {
    v31 = *(_DWORD *)(v30 + 12) - 1;
    goto LABEL_66;
  }
LABEL_65:
  v31 = -1;
LABEL_66:
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "_sde_encoder_phys_wb_frame_done_helper",
    2078,
    2,
    v29,
    v31,
    *(unsigned __int8 *)(a1 + 2290),
    *(_DWORD *)(a1 + 832),
    v5);
  if ( v4 )
    sde_cesta_get_status(v4, v33);
  result = _wake_up(a1 + 896, 3, 0, 0);
  _ReadStatusReg(SP_EL0);
  return result;
}
