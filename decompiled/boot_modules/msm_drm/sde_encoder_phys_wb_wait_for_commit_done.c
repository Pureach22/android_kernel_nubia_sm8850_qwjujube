__int64 __fastcall sde_encoder_phys_wb_wait_for_commit_done(__int64 a1)
{
  int v2; // w6
  unsigned int v3; // w20
  __int64 v4; // x0
  __int64 v5; // x21
  int v7; // w4
  __int64 v8; // x8
  int v9; // w5
  __int64 v10; // x8
  unsigned int v11; // w9
  __int64 v12; // x8
  int v13; // w22
  __int64 v14; // x0
  __int64 v15; // x8
  __int64 v16; // x9
  unsigned __int8 v17; // w21
  __int64 v18; // x1
  _QWORD *v19; // x19
  int v21; // w4
  unsigned int v22; // w8
  unsigned int v28; // w10
  __int64 v29; // x8
  __int64 v30; // x8
  int v31; // w5
  int v32; // w4
  __int64 v33; // x8
  int v34; // w5
  char v35; // [xsp+0h] [xbp-40h]
  __int64 v36; // [xsp+18h] [xbp-28h] BYREF
  __int64 v37; // [xsp+20h] [xbp-20h]
  __int64 v38; // [xsp+28h] [xbp-18h]
  __int64 v39; // [xsp+30h] [xbp-10h]
  __int64 v40; // [xsp+38h] [xbp-8h]

  v40 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(unsigned __int8 *)(a1 + 2290);
  if ( v2 == 1 )
  {
    v3 = sde_encoder_phys_wb_wait_for_idle(a1, 0);
    v4 = *(_QWORD *)(a1 + 2832);
    if ( !v4 )
      goto LABEL_31;
    goto LABEL_29;
  }
  v38 = 0;
  v5 = *(_QWORD *)(a1 + 416);
  if ( !*(_DWORD *)(a1 + 884) )
  {
    v3 = 0;
    goto LABEL_21;
  }
  _X23 = (unsigned int *)(a1 + 884);
  if ( *(_QWORD *)a1 )
  {
    v7 = *(_DWORD *)(*(_QWORD *)a1 + 24LL);
    if ( !a1 )
      goto LABEL_12;
  }
  else
  {
    v7 = -1;
    if ( !a1 )
      goto LABEL_12;
  }
  v8 = *(_QWORD *)(a1 + 2864);
  if ( v8 )
  {
    v9 = *(_DWORD *)(v8 + 12) - 1;
    goto LABEL_13;
  }
LABEL_12:
  v9 = -1;
LABEL_13:
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "_sde_encoder_phys_wb_wait_for_ctl_start",
    2406,
    -1,
    v7,
    v9,
    v2,
    *(_DWORD *)(a1 + 876),
    *(_DWORD *)(a1 + 880));
  LODWORD(v10) = *(_DWORD *)(a1 + 2688);
  v11 = *(_DWORD *)(a1 + 992);
  v36 = a1 + 896;
  v37 = a1 + 884;
  if ( (unsigned int)v10 <= v11 )
    v10 = v11;
  else
    v10 = (unsigned int)v10;
  v39 = v10;
  v3 = sde_encoder_helper_wait_for_irq((__int64 **)a1, 6u, &v36);
  if ( v3 == -110 )
  {
    if ( (v12 = *(_QWORD *)(*(_QWORD *)(a1 + 512) + 152LL), !*(_DWORD *)(v12 + 52)) && *(_BYTE *)(v12 + 22140) != 1
      || !v5
      || (v3 = ((__int64 (__fastcall *)(__int64, __int64, __int64 *, __int64))sde_encoder_helper_hw_fence_extended_wait)(
                 a1,
                 v5,
                 &v36,
                 6),
          v3 == -110) )
    {
      v22 = *_X23;
      do
      {
        if ( !v22 )
          break;
        __asm { PRFM            #0x11, [X23] }
        while ( 1 )
        {
          v28 = __ldxr(_X23);
          if ( v28 != v22 )
            break;
          if ( !__stlxr(v22 - 1, _X23) )
          {
            __dmb(0xBu);
            break;
          }
        }
        _ZF = v28 == v22;
        v22 = v28;
      }
      while ( !_ZF );
      v29 = *(_QWORD *)(*(_QWORD *)(a1 + 512) + 152LL);
      if ( *(_DWORD *)(v29 + 52) || *(_BYTE *)(v29 + 22140) == 1 )
        sde_encoder_helper_hw_fence_sw_override((__int64 **)a1, v5);
      printk(&unk_266A15, "_sde_encoder_phys_wb_wait_for_ctl_start");
      if ( *(_QWORD *)a1 )
        v32 = *(_DWORD *)(*(_QWORD *)a1 + 24LL);
      else
        v32 = -1;
      if ( a1 && (v33 = *(_QWORD *)(a1 + 2864)) != 0 )
        v34 = *(_DWORD *)(v33 + 12) - 1;
      else
        v34 = -1;
      sde_evtlog_log(
        sde_dbg_base_evtlog,
        "_sde_encoder_phys_wb_wait_for_ctl_start",
        2433,
        -1,
        v32,
        v34,
        60333,
        -1059143953,
        v35);
      v3 = -110;
    }
  }
LABEL_21:
  v13 = *(_DWORD *)(a1 + 876);
  v14 = *(_QWORD *)(a1 + 512);
  v15 = *(_QWORD *)(*(_QWORD *)(a1 + 2680) + 56LL);
  v16 = *(_QWORD *)(v15 + 72);
  LODWORD(v15) = *(_DWORD *)(v15 + 80);
  v36 = v16;
  LODWORD(v37) = v15;
  v17 = ((__int64 (__fastcall *)(__int64, __int64 *))sde_vbif_get_xin_status)(v14, &v36);
  if ( !v3 && v13 <= 1 && ((v13 != 0) & v17) == 0 && *(_DWORD *)(a1 + 2332) != 1 )
  {
    v3 = 0;
    v4 = *(_QWORD *)(a1 + 2832);
    if ( !v4 )
      goto LABEL_31;
    goto LABEL_29;
  }
  if ( v13 >= 1 )
  {
    do
    {
      --v13;
      v3 |= sde_encoder_phys_wb_wait_for_idle(a1, 1);
    }
    while ( v13 );
  }
  if ( !v3 )
  {
    v4 = *(_QWORD *)(a1 + 2832);
    if ( !v4 )
      goto LABEL_31;
    goto LABEL_29;
  }
  if ( *(_QWORD *)a1 )
    v21 = *(_DWORD *)(*(_QWORD *)a1 + 24LL);
  else
    v21 = -1;
  if ( a1 && (v30 = *(_QWORD *)(a1 + 2864)) != 0 )
    v31 = *(_DWORD *)(v30 + 12) - 1;
  else
    v31 = -1;
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "sde_encoder_phys_wb_wait_for_commit_done",
    2472,
    -1,
    v21,
    v31,
    *(_DWORD *)(a1 + 2332),
    *(_DWORD *)(a1 + 876),
    v17 & 1);
  printk(&unk_213888, "sde_encoder_phys_wb_wait_for_commit_done");
  v4 = *(_QWORD *)(a1 + 2832);
  if ( v4 )
  {
LABEL_29:
    v18 = *(_QWORD *)(a1 + 2840);
    if ( v18 )
    {
      v19 = (_QWORD *)(a1 + 2832);
      msm_framebuffer_cleanup(v4, v18);
      drm_mode_object_put(*v19 + 24LL);
      *v19 = 0;
      v19[1] = 0;
    }
  }
LABEL_31:
  _ReadStatusReg(SP_EL0);
  return v3;
}
