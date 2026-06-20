__int64 __fastcall sde_encoder_phys_signal_frame_done(_QWORD *a1)
{
  __int64 v1; // x23
  __int64 v3; // x0
  __int64 result; // x0
  __int64 v5; // x20
  unsigned int v6; // w22
  unsigned int v7; // w9
  unsigned int v14; // w11
  _DWORD *v15; // x8
  __int64 v16; // x0
  int v17; // w21
  __int64 (__fastcall *v18)(_QWORD); // x8
  char v19; // w22
  int v20; // w4
  __int64 v21; // x8
  void (__fastcall *v22)(_QWORD); // x8
  _QWORD v23[15]; // [xsp+78h] [xbp-78h] BYREF

  v23[14] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *a1;
  memset(v23, 0, 112);
  result = sde_encoder_get_disp_op(v3);
  v5 = a1[52];
  if ( !v5 )
    goto LABEL_36;
  v6 = result;
  if ( a1[49] )
  {
    v7 = *((_DWORD *)a1 + 219);
    _X8 = (unsigned int *)a1 + 219;
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
        raw_spin_lock(a1[103]);
        v15 = (_DWORD *)a1[49];
        v16 = *a1;
        if ( *(v15 - 1) != -570463643 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, _QWORD *, __int64))v15)(v16, a1, 9);
        if ( *((_DWORD *)a1 + 671) )
          *((_BYTE *)a1 + 2336) = 1;
        raw_spin_unlock(a1[103]);
        v17 = 9;
        if ( v6 >= 3 )
          goto LABEL_22;
        goto LABEL_17;
      }
    }
  }
  v17 = 0;
  if ( (unsigned int)result < 3 )
  {
LABEL_17:
    v1 = v5 + 8LL * v6;
    v18 = *(__int64 (__fastcall **)(_QWORD))(v1 + 976);
    if ( v18 )
    {
      if ( *((_DWORD *)v18 - 1) != 1814623283 )
        __break(0x8228u);
      v19 = v18(v5);
      goto LABEL_24;
    }
  }
  else
  {
LABEL_22:
    __break(0x5512u);
  }
  v19 = -114;
LABEL_24:
  ((void (__fastcall *)(_QWORD, _QWORD *))sde_encoder_helper_get_pp_line_count)(*a1, v23);
  if ( *a1 )
    v20 = *(_DWORD *)(*a1 + 24LL);
  else
    v20 = -1;
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "_sde_encoder_phys_signal_frame_done",
    465,
    2,
    v20,
    *(_DWORD *)(v5 + 64) - 1,
    *(_DWORD *)(a1[62] + 32LL) - 1,
    v17,
    v19);
  if ( *((_BYTE *)a1 + 2337) == 1 )
  {
    v21 = a1[64];
    if ( v21 )
    {
      if ( *(_DWORD *)(*(_QWORD *)(v21 + 152) + 52LL) )
      {
        v22 = *(void (__fastcall **)(_QWORD))(v1 + 328);
        if ( v22 )
        {
          if ( *((_DWORD *)v22 - 1) != 729814110 )
            __break(0x8228u);
          v22(v5);
        }
      }
    }
    *((_BYTE *)a1 + 2337) = 0;
  }
  result = _wake_up(a1 + 112, 3, 0, 0);
LABEL_36:
  _ReadStatusReg(SP_EL0);
  return result;
}
