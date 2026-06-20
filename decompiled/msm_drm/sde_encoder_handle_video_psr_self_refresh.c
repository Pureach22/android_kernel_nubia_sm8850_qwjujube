__int64 __fastcall sde_encoder_handle_video_psr_self_refresh(
        __int64 a1,
        char a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        int a8)
{
  __int64 result; // x0
  __int64 v11; // x8
  __int64 v12; // x21
  __int64 v13; // x25
  int v14; // w6
  int v15; // w0
  __int64 v16; // x5
  int v17; // w2
  int v18; // w4
  __int64 v20; // x26
  __int64 v21; // x26
  __int64 v22; // x22
  void (__fastcall *v23)(_QWORD); // x8
  __int64 v24; // x27
  __int64 v25; // x8
  unsigned int disp_op; // w0
  void (*v27)(void); // x8
  int v28; // w6
  int v29; // w7
  _QWORD *v30; // x28
  void (__fastcall *v31)(__int64, __int64, __int64, __int64); // x8
  __int64 v32; // x2
  void (__fastcall *v33)(__int64, __int64, __int64, __int64); // x8
  void *v34; // x0
  unsigned int v35; // w22
  __int64 v36; // x0
  int v37; // w6
  int v38; // w7
  __int64 v39; // x9
  int v40; // w0
  int v41; // w4
  int v42; // w5
  int v43; // w2
  int v44; // w6
  __int64 v45; // x2
  __int64 v46; // x8
  __int64 v47; // x8
  __int64 v48; // x0
  void (*v49)(void); // x8
  void (__fastcall *v50)(__int64, int *); // x8
  void (__fastcall *v51)(_QWORD); // x8
  void (__fastcall *v52)(_QWORD); // x8
  int v53; // w4
  void (*v54)(void); // x8
  unsigned int v55; // w3
  __int64 v56; // x2
  __int64 v57; // x3
  __int64 v58; // x4
  __int64 v59; // x5
  __int64 v60; // x6
  int v61; // w7
  __int64 v62; // x5
  void (*v63)(void); // x9
  void *v64; // x0
  unsigned int v70; // w9
  char v71; // [xsp+0h] [xbp-70h]
  char v72; // [xsp+0h] [xbp-70h]
  int v73[2]; // [xsp+28h] [xbp-48h] BYREF
  __int64 v74; // [xsp+30h] [xbp-40h]
  __int64 v75; // [xsp+38h] [xbp-38h]
  __int64 v76; // [xsp+40h] [xbp-30h]
  __int64 v77; // [xsp+48h] [xbp-28h]
  __int64 v78; // [xsp+50h] [xbp-20h]
  __int64 v79; // [xsp+58h] [xbp-18h]
  __int64 v80; // [xsp+60h] [xbp-10h]
  __int64 v81; // [xsp+68h] [xbp-8h]

  v81 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v79 = 0;
  v80 = 0;
  v77 = 0;
  v78 = 0;
  v75 = 0;
  v76 = 0;
  *(_QWORD *)v73 = 0;
  v74 = 0;
  result = sde_evtlog_log(
             sde_dbg_base_evtlog,
             "sde_encoder_handle_video_psr_self_refresh",
             5835,
             -1,
             4369,
             a2 & 1,
             -1059143953,
             a8,
             v71);
  if ( !a1 || !*(_QWORD *)(a1 + 328) )
    goto LABEL_87;
  if ( *(_QWORD *)a1 )
  {
    v11 = *(_QWORD *)(*(_QWORD *)a1 + 56LL);
    if ( v11 && *(_QWORD *)(v11 + 8) )
    {
      result = sde_kms_get_disp_op();
      goto LABEL_7;
    }
    v34 = &unk_234896;
  }
  else
  {
    v34 = &unk_26FCAB;
  }
  printk(v34, "sde_encoder_get_kms");
  result = 0;
LABEL_7:
  v12 = *(_QWORD *)(a1 + 328);
  v13 = *(_QWORD *)(v12 + 8);
  if ( v13 )
  {
    v14 = *(_DWORD *)(v13 + 4720);
    if ( v14 == 4 )
    {
      v15 = sde_dbg_base_evtlog;
      v16 = *(_QWORD *)(v13 + 4736);
      v17 = 5849;
      v18 = 13107;
LABEL_13:
      result = sde_evtlog_log(
                 v15,
                 "sde_encoder_handle_video_psr_self_refresh",
                 v17,
                 -1,
                 v18,
                 v16,
                 v14,
                 -1059143953,
                 v72);
      goto LABEL_87;
    }
    _X8 = *(unsigned __int16 *)(v12 + 2608);
    v20 = *(_QWORD *)(a1 + 1360);
    if ( (_DWORD)_X8 != 2 && (a2 & 1) != 0 )
    {
      v15 = sde_dbg_base_evtlog;
      v16 = *(_QWORD *)(v13 + 4736);
      v17 = 5856;
      v18 = 60333;
      goto LABEL_13;
    }
    if ( (a2 & 1) != 0 )
    {
      if ( (unsigned int)result > 2 )
        goto LABEL_100;
      v21 = (unsigned int)result;
      v22 = *(_QWORD *)(v12 + 416);
      v23 = *(void (__fastcall **)(_QWORD))(v22 + 688 + 8LL * (unsigned int)result);
      if ( v23 )
      {
        if ( *((_DWORD *)v23 - 1) != 1800103338 )
          __break(0x8228u);
        v23(v22);
      }
      v24 = *(_QWORD *)(a1 + 200);
      if ( !*(_QWORD *)(a1 + 4960) || !*(_QWORD *)(a1 + 1360) || !v24 || !*(_QWORD *)(v24 + 416) )
      {
LABEL_32:
        v30 = (_QWORD *)(v22 + 8 * v21);
        if ( (a2 & 1) != 0 )
        {
          sde_connector_update_cmd(*(_QWORD *)(v12 + 8), 0x1000000000LL, 1);
          *(_WORD *)(v12 + 2608) = 1;
          v31 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(v22 + 1192 + 8 * v21);
          if ( v31 )
          {
            v32 = *(unsigned int *)(*(_QWORD *)(v12 + 424) + 32LL);
            if ( *((_DWORD *)v31 - 1) != 949740941 )
              __break(0x8228u);
            v31(v22, 6, v32, 1);
            v33 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(v22 + 1192 + 8 * v21);
            goto LABEL_47;
          }
        }
        else
        {
          v33 = (void (__fastcall *)(__int64, __int64, __int64, __int64))v30[149];
          if ( v33 )
          {
LABEL_47:
            v45 = *(unsigned int *)(*(_QWORD *)(v12 + 424) + 32LL);
            if ( *((_DWORD *)v33 - 1) != 949740941 )
              __break(0x8228u);
            v33(v22, 7, v45, 1);
          }
        }
        v46 = *(_QWORD *)(v12 + 512);
        if ( !v46
          || (v47 = *(_QWORD *)(v46 + 152), v48 = *(_QWORD *)(v12 + 416), !*(_DWORD *)(v47 + 52))
          && *(_BYTE *)(v47 + 22140) != 1 )
        {
LABEL_58:
          v50 = (void (__fastcall *)(__int64, int *))v30[89];
          if ( v50 )
          {
            if ( *((_DWORD *)v50 - 1) != 1851168652 )
              __break(0x8228u);
            v50(v22, v73);
          }
          *(_DWORD *)(v22 + 96) |= 0x20000u;
          if ( *(_QWORD *)(a1 + 4960) )
            sde_cesta_poll_handshake();
          v51 = (void (__fastcall *)(_QWORD))v30[95];
          if ( v51 )
          {
            if ( *((_DWORD *)v51 - 1) != 1800103338 )
              __break(0x8228u);
            v51(v22);
          }
          v52 = *(void (__fastcall **)(_QWORD))(v22 + 688 + 8 * v21);
          if ( v52 )
          {
            if ( *((_DWORD *)v52 - 1) != 1800103338 )
              __break(0x8228u);
            v52(v22);
          }
          if ( *(_QWORD *)v12 )
            v53 = *(_DWORD *)(*(_QWORD *)v12 + 24LL);
          else
            v53 = -1;
          sde_evtlog_log(
            sde_dbg_base_evtlog,
            "sde_encoder_handle_video_psr_self_refresh",
            5921,
            -1,
            v53,
            v73[0],
            *(_DWORD *)(v13 + 4720),
            *(_QWORD *)(v13 + 4736),
            239);
          if ( (*(_BYTE *)(*(_QWORD *)(*(_QWORD *)(v12 + 512) + 152LL) + 22140LL) & 1) == 0 )
          {
            v54 = *(void (**)(void))(*(_QWORD *)(v12 + 424) + 8 * v21 + 704);
            if ( v54 )
            {
              if ( *((_DWORD *)v54 - 1) != -1596594834 )
                __break(0x8228u);
              v54();
            }
          }
          _X8 = v12 + 876;
          goto LABEL_101;
        }
        _X8 = *(unsigned int *)(v48 + 28);
        if ( (unsigned int)_X8 < 3 )
        {
          v49 = *(void (**)(void))(v48 + 8 * _X8 + 352);
          if ( v49 )
          {
            if ( *((_DWORD *)v49 - 1) != 729814110 )
              __break(0x8228u);
            v49();
          }
          goto LABEL_58;
        }
LABEL_100:
        __break(0x5512u);
LABEL_101:
        __asm { PRFM            #0x11, [X8] }
        do
          v70 = __ldxr((unsigned int *)_X8);
        while ( __stlxr(v70 + 1, (unsigned int *)_X8) );
        __dmb(0xBu);
        sde_encoder_wait_for_event(a1, 2u);
        v55 = *(_DWORD *)(v12 + 2304);
        if ( v55 >= 0x7D1 )
        {
          printk(&unk_249194, "sde_encoder_handle_video_psr_self_refresh");
          v55 = 2000;
        }
        usleep_range_state(v55, v55 + 10, 2);
        if ( (a2 & 1) != 0 )
        {
          *(_WORD *)(v12 + 2608) = 0;
          sde_encoder_vhm_wakelock(a1, 0, v56, v57, v58, v59, v60, v61);
          kthread_cancel_delayed_work_sync(a1 + 1224);
        }
        v40 = sde_dbg_base_evtlog;
        v42 = *(_DWORD *)(v12 + 876);
        v44 = a2 & 1;
        v43 = 5946;
        v41 = 8738;
        goto LABEL_86;
      }
      if ( *(_QWORD *)a1 )
      {
        v25 = *(_QWORD *)(*(_QWORD *)a1 + 56LL);
        if ( v25 && *(_QWORD *)(v25 + 8) )
        {
          disp_op = sde_kms_get_disp_op();
          _X8 = disp_op;
          if ( disp_op > 2 )
            goto LABEL_100;
          goto LABEL_28;
        }
        v64 = &unk_234896;
      }
      else
      {
        v64 = &unk_26FCAB;
      }
      printk(v64, "sde_encoder_get_kms");
      LODWORD(_X8) = 0;
LABEL_28:
      v27 = *(void (**)(void))(*(_QWORD *)(v24 + 416) + 8LL * (unsigned int)_X8 + 1624);
      if ( v27 )
      {
        if ( *((_DWORD *)v27 - 1) != -1386749835 )
          __break(0x8228u);
        v27();
        sde_evtlog_log(
          sde_dbg_base_evtlog,
          "_sde_encoder_cesta_update_self_refresh",
          2069,
          -1,
          *(_DWORD *)(a1 + 24),
          -1059143953,
          v28,
          v29,
          v72);
      }
      goto LABEL_32;
    }
    v35 = result;
    v36 = ktime_get(result);
    _X8 = *(_QWORD *)(v12 + 2568);
    if ( v20 )
    {
      v39 = *(_QWORD *)(a1 + 1360);
      if ( !v39 || *(_DWORD *)(v39 + 4712) || (*(_BYTE *)(v20 + 6040) & 1) != 0 || *(_DWORD *)(v12 + 876) )
      {
        v40 = sde_dbg_base_evtlog;
        v41 = *(unsigned __int8 *)(v20 + 6040);
        v42 = *(_DWORD *)(v12 + 876);
        v43 = 5869;
        v44 = 21845;
LABEL_86:
        result = sde_evtlog_log(
                   v40,
                   "sde_encoder_handle_video_psr_self_refresh",
                   v43,
                   -1,
                   v41,
                   v42,
                   v44,
                   -1059143953,
                   v72);
        goto LABEL_87;
      }
    }
    v62 = _X8 - v36;
    if ( _X8 > v36 )
    {
      _X8 = 1999999;
      if ( v62 <= 1999999 )
      {
        result = sde_evtlog_log(
                   sde_dbg_base_evtlog,
                   "sde_encoder_handle_video_psr_self_refresh",
                   5874,
                   -1,
                   17476,
                   v62,
                   -1059143953,
                   v38,
                   v72);
        goto LABEL_87;
      }
    }
    if ( v35 >= 3 )
      goto LABEL_100;
    v63 = *(void (**)(void))(*(_QWORD *)(v12 + 424) + 8LL * v35 + 200);
    if ( v63 )
    {
      if ( *((_DWORD *)v63 - 1) != -2009615442 )
        __break(0x8229u);
      v63();
    }
    result = sde_evtlog_log(
               sde_dbg_base_evtlog,
               "sde_encoder_handle_video_psr_self_refresh",
               5881,
               -1,
               26214,
               -1059143953,
               v37,
               v38,
               v72);
  }
LABEL_87:
  _ReadStatusReg(SP_EL0);
  return result;
}
