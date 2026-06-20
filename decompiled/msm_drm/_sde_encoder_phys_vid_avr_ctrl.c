__int64 __fastcall sde_encoder_phys_vid_avr_ctrl(__int64 a1)
{
  __int64 v2; // x19
  __int64 v3; // x23
  __int64 v4; // x21
  __int64 result; // x0
  __int64 v6; // x8
  int v7; // w8
  __int64 v8; // x9
  unsigned int v9; // w22
  int v10; // w9
  char v11; // w10
  _BYTE *v12; // x24
  int v13; // w27
  __int64 v14; // x23
  unsigned int v15; // w0
  __int64 v16; // x25
  void (__fastcall *v17)(__int64, __int64, __int64, __int64, __int64, __int64); // x9
  __int64 v18; // x5
  __int64 v19; // x0
  void (*v20)(void); // x8
  __int64 v21; // x23
  unsigned int disp_op; // w0
  __int64 v23; // x25
  _DWORD *v24; // x9
  __int64 v25; // x0
  unsigned int v26; // w8
  __int64 v27; // x22
  void (__fastcall *v28)(__int64, __int64 *); // x8
  void (__fastcall *v29)(__int64, bool); // x8
  __int64 v30; // x21
  __int64 v31; // x22
  __int64 v32; // x23
  unsigned int v33; // w25
  __int64 v34; // x26
  __int64 v35; // x0
  __int64 v36; // x8
  __int64 v37; // x28
  unsigned __int64 v38; // x8
  __int64 v39; // x22
  __int64 v40; // x9
  __int64 v41; // x26
  __int64 (__fastcall *v42)(_QWORD); // x8
  int v43; // w25
  _DWORD *v44; // x8
  int v45; // w4
  int v46; // w4
  unsigned __int64 v47; // [xsp+20h] [xbp-30h]
  __int64 v48; // [xsp+28h] [xbp-28h]
  __int64 v49; // [xsp+30h] [xbp-20h] BYREF
  __int64 v50; // [xsp+38h] [xbp-18h]
  int v51; // [xsp+40h] [xbp-10h]
  __int64 v52; // [xsp+48h] [xbp-8h]

  v52 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)a1;
  v3 = *(_QWORD *)(a1 + 8);
  v4 = *(_QWORD *)(a1 + 424);
  result = sde_encoder_get_disp_op(*(_QWORD *)a1);
  if ( !v3 || (v6 = *(_QWORD *)(v3 + 2512)) == 0 )
  {
LABEL_81:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v7 = *(_DWORD *)(v6 + 1632);
  v8 = *(_QWORD *)(a1 + 8);
  v9 = result;
  v51 = 0;
  v49 = 0;
  v50 = 0;
  if ( !v8 )
  {
    v12 = (_BYTE *)(v2 + 749);
    if ( (*(_BYTE *)(v2 + 749) & 1) == 0 )
    {
      if ( *(_BYTE *)(v2 + 751) )
        v13 = 1;
      else
        v13 = v7;
      goto LABEL_26;
    }
    goto LABEL_11;
  }
  v10 = *(_DWORD *)(v8 + 4676);
  v11 = *(_BYTE *)(v2 + 749);
  v12 = (_BYTE *)(v2 + 749);
  LODWORD(v50) = v10;
  if ( (v11 & 1) != 0 )
  {
LABEL_11:
    v13 = 1;
    LODWORD(v50) = 1;
    goto LABEL_12;
  }
  if ( *(_BYTE *)(v2 + 751) )
    v13 = 1;
  else
    v13 = v7;
  if ( !v10 )
  {
LABEL_26:
    v21 = *(_QWORD *)a1;
    disp_op = sde_encoder_get_disp_op(*(_QWORD *)a1);
    if ( *(_BYTE *)(*(_QWORD *)(*(_QWORD *)(a1 + 512) + 152LL) + 22140LL) == 1 )
    {
      if ( disp_op >= 3 )
        goto LABEL_82;
      v23 = disp_op;
      v24 = *(_DWORD **)(*(_QWORD *)(a1 + 416) + 8LL * disp_op + 304);
      if ( v24 )
      {
        v25 = *(_QWORD *)(a1 + 416);
        if ( *(v24 - 1) != -1975722870 )
          __break(0x8229u);
        ((void (__fastcall *)(__int64, __int64, __int64, __int64, _QWORD, _QWORD))v24)(v25, 1, 1, 1, 0, 0);
      }
    }
    else
    {
      if ( disp_op > 2 )
        goto LABEL_82;
      v23 = disp_op;
    }
    v20 = *(void (**)(void))(*(_QWORD *)(a1 + 424) + 8 * v23 + 728);
    if ( !v20 || *(_BYTE *)(v21 + 751) != 1 )
      goto LABEL_39;
    goto LABEL_36;
  }
LABEL_12:
  v14 = *(_QWORD *)a1;
  v15 = sde_encoder_get_disp_op(*(_QWORD *)a1);
  if ( *(_BYTE *)(*(_QWORD *)(*(_QWORD *)(a1 + 512) + 152LL) + 22140LL) == 1 )
  {
    if ( v15 >= 3 )
      goto LABEL_82;
    v16 = v15;
    v17 = *(void (__fastcall **)(__int64, __int64, __int64, __int64, __int64, __int64))(*(_QWORD *)(a1 + 416)
                                                                                      + 8LL * v15
                                                                                      + 304);
    if ( v17 )
    {
      v18 = *(unsigned __int8 *)(v14 + 751);
      v19 = *(_QWORD *)(a1 + 416);
      if ( *((_DWORD *)v17 - 1) != -1975722870 )
        __break(0x8229u);
      v17(v19, 1, 1, 1, 1, v18);
    }
  }
  else
  {
    if ( v15 > 2 )
      goto LABEL_82;
    v16 = v15;
  }
  v20 = *(void (**)(void))(*(_QWORD *)(a1 + 424) + 8 * v16 + 728);
  if ( v20 && *(_BYTE *)(v14 + 751) == 1 )
  {
LABEL_36:
    if ( *((_DWORD *)v20 - 1) != -1839426449 )
      __break(0x8228u);
    v20();
  }
LABEL_39:
  if ( *v12 == 1 && *(_BYTE *)(*(_QWORD *)(*(_QWORD *)(a1 + 512) + 152LL) + 22140LL) == 1 )
    BYTE1(v51) = 1;
  v26 = *(_DWORD *)(v2 + 4812);
  if ( v26 && v13 == 1 )
    HIDWORD(v50) = *(unsigned __int16 *)(a1 + 540) % v26 * *(_DWORD *)(a1 + 2764) / v26
                 + *(unsigned __int16 *)(a1 + 540) / v26 * *(_DWORD *)(a1 + 2764);
  if ( v9 <= 2 )
  {
    v27 = v4 + 8LL * v9;
    v28 = *(void (__fastcall **)(__int64, __int64 *))(v27 + 752);
    if ( v28 )
    {
      if ( *((_DWORD *)v28 - 1) != -1902896818 )
        __break(0x8228u);
      v28(v4, &v49);
    }
    v29 = *(void (__fastcall **)(__int64, bool))(v27 + 800);
    if ( v29 && (*(_BYTE *)(v2 + 700) & 1) == 0 )
    {
      if ( *((_DWORD *)v29 - 1) != -1839426449 )
        __break(0x8228u);
      v29(v4, v13 == 1);
    }
    if ( (*(_QWORD *)(*(_QWORD *)(v4 + 40) + 32LL) & 0x100000) == 0 )
      goto LABEL_77;
    v30 = *(_QWORD *)a1;
    v31 = *(_QWORD *)(a1 + 8);
    v32 = *(_QWORD *)(a1 + 424);
    v33 = sde_encoder_get_disp_op(*(_QWORD *)a1);
    v34 = raw_spin_lock_irqsave(*(_QWORD *)(a1 + 824));
    v35 = ktime_get(v34);
    v36 = *(_QWORD *)(v31 + 2512);
    if ( !v36 || (v37 = *(_QWORD *)(v36 + 1664)) == 0 || (v38 = *(unsigned int *)(v30 + 4812), !(_DWORD)v38) )
    {
      raw_spin_unlock_irqrestore(*(_QWORD *)(a1 + 824), v34);
LABEL_77:
      if ( *(_QWORD *)a1 )
        v46 = *(_DWORD *)(*(_QWORD *)a1 + 24LL);
      else
        v46 = -1;
      result = sde_evtlog_log(
                 sde_dbg_base_evtlog,
                 "_sde_encoder_phys_vid_avr_ctrl",
                 576,
                 -1,
                 v46,
                 *(_DWORD *)(*(_QWORD *)(a1 + 424) + 32LL) - 1,
                 v50,
                 SHIDWORD(v50),
                 *(_DWORD *)(v2 + 4812));
      goto LABEL_81;
    }
    v39 = v35;
    v40 = v37 - v35;
    if ( v37 <= v35 )
    {
      LODWORD(v47) = 0;
      LODWORD(v48) = 0;
    }
    else
    {
      v47 = (v40 + (v38 + 999999999) / v38 - 1) / ((v38 + 999999999) / v38);
      v48 = v40 / 1000;
    }
    raw_spin_unlock_irqrestore(*(_QWORD *)(a1 + 824), v34);
    if ( v33 <= 2 )
    {
      v41 = v32 + 8LL * v33;
      v42 = *(__int64 (__fastcall **)(_QWORD))(v41 + 872);
      if ( v42 )
      {
        if ( *((_DWORD *)v42 - 1) != 1550245701 )
          __break(0x8228u);
        v43 = v42(v32);
      }
      else
      {
        v43 = 0;
      }
      v44 = *(_DWORD **)(v41 + 848);
      if ( v44 )
      {
        if ( *(v44 - 1) != -1913620264 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, _QWORD))v44)(v32, (unsigned int)(v43 + v47));
      }
      if ( *(_QWORD *)a1 )
        v45 = *(_DWORD *)(*(_QWORD *)a1 + 24LL);
      else
        v45 = -1;
      sde_evtlog_log(
        sde_dbg_base_evtlog,
        "_sde_encoder_phys_vid_set_num_avr_step",
        486,
        -1,
        v45,
        v37 / 1000,
        v39 / 1000,
        v48,
        *(_DWORD *)(v30 + 4812));
      goto LABEL_77;
    }
  }
LABEL_82:
  __break(0x5512u);
  return sde_encoder_phys_vid_mode_fixup();
}
