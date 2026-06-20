__int64 __fastcall sde_hw_rc_check_pu_roi(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        int a7,
        int a8)
{
  unsigned int *v9; // x22
  __int64 v11; // x21
  __int64 v12; // x8
  int v13; // w4
  unsigned int v14; // w0
  unsigned int ajusted_roi_0; // w0
  __int64 result; // x0
  unsigned int v17; // w19
  void *v18; // x0
  void *v19; // x0
  char v20; // [xsp+0h] [xbp-70h]
  __int64 v21; // [xsp+8h] [xbp-68h] BYREF
  __int64 v22; // [xsp+10h] [xbp-60h] BYREF
  __int64 v23; // [xsp+18h] [xbp-58h] BYREF
  __int64 v24; // [xsp+20h] [xbp-50h] BYREF
  __int64 v25; // [xsp+28h] [xbp-48h]
  __int64 v26; // [xsp+30h] [xbp-40h]
  __int64 v27; // [xsp+38h] [xbp-38h]
  __int64 v28; // [xsp+40h] [xbp-30h]
  __int64 v29; // [xsp+48h] [xbp-28h]
  __int64 v30; // [xsp+50h] [xbp-20h]
  __int64 v31; // [xsp+58h] [xbp-18h]
  __int64 v32; // [xsp+60h] [xbp-10h]
  __int64 v33; // [xsp+68h] [xbp-8h]

  v33 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v31 = 0;
  v32 = 0;
  v29 = 0;
  v30 = 0;
  v27 = 0;
  v28 = 0;
  v25 = 0;
  v26 = 0;
  v23 = 0;
  v24 = 0;
  v21 = 0;
  v22 = 0;
  if ( !a1 || !a2 )
  {
    v19 = &unk_26FEB0;
LABEL_21:
    printk(v19, "sde_hw_rc_check_pu_roi");
    result = 4294967274LL;
    goto LABEL_18;
  }
  if ( *(_DWORD *)(a2 + 8) != 72 )
  {
    v19 = &unk_2402E6;
    goto LABEL_21;
  }
  v9 = *(unsigned int **)a2;
  if ( *(_QWORD *)a2 )
  {
    v11 = *(_QWORD *)(a1 + 1480);
    if ( !v11 )
      goto LABEL_15;
  }
  else
  {
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "full frame update\n");
    v12 = *(_QWORD *)(a1 + 72);
    v31 = 0;
    v32 = 0;
    v29 = 0;
    v30 = 0;
    v13 = *(_DWORD *)(*(_QWORD *)(v12 + 48) + 536LL);
    v27 = 0;
    v28 = 0;
    v25 = 0;
    v26 = 0;
    v24 = 0;
    sde_evtlog_log(sde_dbg_base_evtlog, "sde_hw_rc_check_pu_roi", 426, -1, v13, -1059143953, a7, a8, v20);
    v9 = (unsigned int *)&v24;
    v11 = *(_QWORD *)(a1 + 1480);
    if ( !v11 )
      goto LABEL_15;
  }
  if ( *(_DWORD *)(v11 + 16) )
  {
    v14 = sde_hw_rc_check_mask_cfg(a1, a2, (__int64 *)v11);
    if ( v14 )
    {
      v17 = v14;
      v18 = &unk_254AA4;
    }
    else
    {
      sde_kms_rect_merge_rectangles(v9, (__int64)&v22);
      ajusted_roi_0 = sde_hw_rc_get_ajusted_roi_0(a2, &v22, &v23);
      if ( ajusted_roi_0 )
      {
        v17 = ajusted_roi_0;
        v18 = &unk_27E9ED;
      }
      else
      {
        result = sde_hw_rc_get_param_rb_0(v11, &v23, (char *)&v21 + 4, &v21);
        if ( !(_DWORD)result )
          goto LABEL_18;
        v17 = result;
        v18 = &unk_254AE3;
      }
    }
    printk(v18, "sde_hw_rc_check_pu_roi");
    result = v17;
    goto LABEL_18;
  }
LABEL_15:
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "no previous rc mask programmed\n");
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "sde_hw_rc_check_pu_roi",
    434,
    -1,
    *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL) + 536LL),
    -1059143953,
    a7,
    a8,
    v20);
  result = 1;
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
