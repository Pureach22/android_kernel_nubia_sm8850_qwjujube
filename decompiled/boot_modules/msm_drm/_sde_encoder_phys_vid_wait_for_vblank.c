__int64 __fastcall sde_encoder_phys_vid_wait_for_vblank(__int64 a1, char a2)
{
  __int64 v2; // x22
  __int64 v4; // x8
  __int64 v7; // x21
  unsigned int v8; // w0
  __int64 *v9; // x0
  unsigned int disp_op; // w0
  __int64 v11; // x8
  __int64 (__fastcall *v12)(_QWORD); // x9
  __int64 v13; // x0
  __int64 v14; // x8
  unsigned int v15; // w24
  unsigned int v16; // w0
  __int64 v17; // x8
  __int64 (__fastcall *v18)(_QWORD); // x9
  __int64 v19; // x0
  int v20; // w0
  int v21; // w7
  __int64 v22; // x8
  __int64 v23; // x25
  unsigned int v24; // w23
  unsigned int v25; // w0
  __int64 v26; // x8
  __int64 (__fastcall *v27)(_QWORD); // x9
  __int64 v28; // x0
  int v29; // w0
  void (__fastcall *v30)(__int64, __int64); // x8
  unsigned int v31; // w9
  unsigned int v32; // w8
  unsigned int v33; // w10
  _BOOL4 v39; // w24
  unsigned int v40; // w0
  __int64 v41; // x8
  __int64 (__fastcall *v42)(_QWORD); // x9
  __int64 v43; // x0
  int v44; // w6
  __int64 v45; // x1
  int v46; // w22
  int v47; // w22
  int v48; // w7
  int v49; // w4
  unsigned int v50; // w8
  unsigned int v53; // w10
  void (__fastcall *v54)(__int64 *, __int64, __int64); // x8
  __int64 *v55; // x0
  int v56; // w4
  __int64 v57; // x1
  __int64 v58; // x2
  __int64 v59; // x3
  __int64 v60; // x4
  __int64 v61; // x5
  __int64 v62; // x6
  int v63; // w7
  char v65; // [xsp+0h] [xbp-70h]
  char v66; // [xsp+0h] [xbp-70h]
  __int64 v67; // [xsp+28h] [xbp-48h] BYREF
  __int64 v68; // [xsp+30h] [xbp-40h]
  __int64 v69; // [xsp+38h] [xbp-38h]
  __int64 v70; // [xsp+40h] [xbp-30h]
  _QWORD v71[5]; // [xsp+48h] [xbp-28h] BYREF

  v71[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v69 = 0;
  v70 = 0;
  v67 = 0;
  v68 = 0;
  if ( !a1 || (v2 = *(_QWORD *)(a1 + 416)) == 0 )
  {
    printk(&unk_2242B9, "_sde_encoder_phys_vid_wait_for_vblank");
    v24 = -22;
LABEL_78:
    _ReadStatusReg(SP_EL0);
    return v24;
  }
  v4 = *(unsigned int *)(a1 + 992);
  _X28 = (unsigned int *)(a1 + 876);
  v7 = *(_QWORD *)(a1 + 8);
  v67 = a1 + 896;
  v68 = a1 + 876;
  v70 = v4;
  v8 = sde_encoder_helper_wait_for_irq((__int64 **)a1, 0, &v67);
  if ( v8 != -110
    || *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 512) + 152LL) + 52LL)
    && (v8 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64 *, _QWORD))sde_encoder_helper_hw_fence_extended_wait)(
               a1,
               *(_QWORD *)(a1 + 416),
               &v67,
               0),
        v8 != -110) )
  {
    v24 = v8;
    goto LABEL_50;
  }
  v9 = *(__int64 **)a1;
  if ( *(_QWORD *)a1 )
  {
    if ( *((_BYTE *)v9 + 4936) == 1 )
    {
      disp_op = sde_encoder_get_disp_op((__int64)v9);
      v11 = *(_QWORD *)(a1 + 416);
      if ( v11 )
      {
        if ( disp_op >= 3 )
          goto LABEL_83;
        v12 = *(__int64 (__fastcall **)(_QWORD))(v11 + 8LL * disp_op + 1712);
        if ( v12 )
        {
          v13 = *(_QWORD *)(a1 + 416);
          if ( *((_DWORD *)v12 - 1) != 1245083594 )
            __break(0x8229u);
          if ( (v12(v13) & 1) != 0 )
          {
            v14 = *(_QWORD *)(a1 + 416);
            v71[2] = 0;
            if ( v14 )
            {
              v15 = sde_encoder_get_disp_op(*(_QWORD *)a1);
              v16 = sde_encoder_get_disp_op(*(_QWORD *)a1);
              v17 = *(_QWORD *)(a1 + 416);
              if ( !v17 )
                goto LABEL_81;
              if ( v16 >= 3 )
                goto LABEL_83;
              v18 = *(__int64 (__fastcall **)(_QWORD))(v17 + 8LL * v16 + 784);
              if ( !v18 )
                goto LABEL_81;
              v19 = *(_QWORD *)(a1 + 416);
              if ( *((_DWORD *)v18 - 1) != 1814623283 )
                __break(0x8229u);
              v20 = v18(v19);
              if ( !v20 )
                goto LABEL_81;
              v22 = *(unsigned int *)(a1 + 992);
              v71[0] = a1 + 896;
              v71[1] = _X28;
              v23 = *(_QWORD *)(a1 + 416);
              v71[3] = v22;
              sde_evtlog_log(
                sde_dbg_base_evtlog,
                "_sde_encoder_handle_flush_sync_timeout",
                1905,
                -1,
                v20,
                13107,
                -1059143953,
                v21,
                v65);
              v24 = sde_encoder_helper_wait_for_irq((__int64 **)a1, 0, v71);
              v25 = sde_encoder_get_disp_op(*(_QWORD *)a1);
              v26 = *(_QWORD *)(a1 + 416);
              if ( !v26 )
                goto LABEL_81;
              if ( v25 >= 3 )
                goto LABEL_83;
              v27 = *(__int64 (__fastcall **)(_QWORD))(v26 + 8LL * v25 + 784);
              if ( !v27 )
                goto LABEL_81;
              v28 = *(_QWORD *)(a1 + 416);
              if ( *((_DWORD *)v27 - 1) != 1814623283 )
                __break(0x8229u);
              v29 = v27(v28);
              if ( v29 )
              {
                sde_evtlog_log(
                  sde_dbg_base_evtlog,
                  "_sde_encoder_handle_flush_sync_timeout",
                  1911,
                  -1,
                  v24,
                  v29,
                  17476,
                  -1059143953,
                  v66);
                if ( v15 >= 3 )
                  goto LABEL_83;
                v30 = *(void (__fastcall **)(__int64, __int64))(v23 + 8LL * v15 + 1688);
                if ( v30 )
                {
                  if ( *((_DWORD *)v30 - 1) != -1792093723 )
                    __break(0x8228u);
                  v30(v23, 1);
                  v24 = sde_encoder_helper_wait_for_irq((__int64 **)a1, 0, v71);
                }
                if ( v24 == -110 )
                  goto LABEL_33;
              }
              else
              {
LABEL_81:
                v24 = 0;
              }
            }
            else
            {
              v24 = -22;
            }
LABEL_50:
            v48 = 0;
LABEL_73:
            if ( *(_QWORD *)a1 )
              v56 = *(_DWORD *)(*(_QWORD *)a1 + 24LL);
            else
              v56 = -1;
            sde_evtlog_log(
              sde_dbg_base_evtlog,
              "_sde_encoder_phys_vid_wait_for_vblank",
              1995,
              -1,
              v56,
              26,
              a2 & 1,
              v48,
              v24);
            if ( !v24 )
              sde_encoder_clear_fence_error_in_progress(a1, v57, v58, v59, v60, v61, v62, v63);
            goto LABEL_78;
          }
        }
      }
    }
  }
LABEL_33:
  v31 = *_X28;
  do
  {
    v32 = v31;
    if ( !v31 )
      break;
    v33 = v31 - 1;
    __asm { PRFM            #0x11, [X28] }
    while ( 1 )
    {
      v31 = __ldxr(_X28);
      if ( v31 != v32 )
        break;
      if ( !__stlxr(v33, _X28) )
      {
        __dmb(0xBu);
        break;
      }
    }
  }
  while ( v31 != v32 );
  v39 = v32 != 0;
  v40 = sde_encoder_get_disp_op(*(_QWORD *)a1);
  v41 = *(_QWORD *)(a1 + 416);
  if ( !v41 )
    goto LABEL_51;
  if ( v40 < 3 )
  {
    v42 = *(__int64 (__fastcall **)(_QWORD))(v41 + 8LL * v40 + 784);
    if ( v42 )
    {
      v43 = *(_QWORD *)(a1 + 416);
      if ( *((_DWORD *)v42 - 1) != 1814623283 )
        __break(0x8229u);
      v44 = v42(v43);
      if ( v44 )
      {
        if ( *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 512) + 152LL) + 52LL) )
        {
          v45 = v2;
          v46 = v44;
          sde_encoder_helper_hw_fence_sw_override((__int64 **)a1, v45);
          v44 = v46;
        }
        v24 = -110;
        v47 = 1;
      }
      else
      {
        v47 = 0;
        v24 = 0;
      }
      goto LABEL_52;
    }
LABEL_51:
    v47 = 0;
    v24 = 0;
    v44 = 0;
LABEL_52:
    if ( *(_QWORD *)a1 )
      v49 = *(_DWORD *)(*(_QWORD *)a1 + 24LL);
    else
      v49 = -1;
    sde_evtlog_log(sde_dbg_base_evtlog, "_sde_encoder_phys_vid_wait_for_vblank", 1981, -1, v49, v39, v44, v24, 51);
    if ( (a2 & 1) != 0 )
    {
      v50 = *(_DWORD *)(a1 + 880);
      while ( v50 )
      {
        _X12 = (unsigned int *)(a1 + 880);
        __asm { PRFM            #0x11, [X12] }
        while ( 1 )
        {
          v53 = __ldxr(_X12);
          if ( v53 != v50 )
            break;
          if ( !__stlxr(v50 - 1, _X12) )
          {
            __dmb(0xBu);
            break;
          }
        }
        _ZF = v53 == v50;
        v50 = v53;
        if ( _ZF )
        {
          v54 = *(void (__fastcall **)(__int64 *, __int64, __int64))(a1 + 392);
          if ( v54 )
          {
            v55 = *(__int64 **)a1;
            if ( *((_DWORD *)v54 - 1) != -570463643 )
              __break(0x8228u);
            v54(v55, a1, 26);
            if ( v47 )
            {
              if ( (sde_encoder_recovery_events_enabled(*(_QWORD *)a1) & 1) != 0 )
              {
                sde_connector_event_notify(v7, 2147483655LL, 1, 2);
                v48 = 1;
                v24 = -110;
              }
              else
              {
                v24 = -110;
                v48 = 1;
              }
              goto LABEL_73;
            }
          }
          break;
        }
      }
    }
    v48 = 1;
    goto LABEL_73;
  }
LABEL_83:
  __break(0x5512u);
  return sde_encoder_phys_vid_is_master();
}
