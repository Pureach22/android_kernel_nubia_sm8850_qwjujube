__int64 __fastcall sde_hw_rc_setup_pu_roi(_QWORD *a1, int *a2)
{
  unsigned int *v3; // x20
  _DWORD *v5; // x22
  int v6; // w6
  int v7; // w7
  unsigned int ajusted_roi_0; // w0
  int v9; // w4
  unsigned int v10; // w21
  __int64 result; // x0
  unsigned int param_rb_0; // w0
  _QWORD *v13; // x8
  __int64 v14; // x9
  __int64 v15; // x11
  __int64 v16; // x12
  __int64 v17; // x9
  __int64 v18; // x11
  __int64 v19; // x12
  void *v20; // x0
  unsigned int v21; // w19
  void *v22; // x0
  char v23; // [xsp+0h] [xbp-70h]
  __int64 v24; // [xsp+8h] [xbp-68h] BYREF
  __int64 v25; // [xsp+10h] [xbp-60h] BYREF
  __int64 v26; // [xsp+18h] [xbp-58h] BYREF
  __int64 v27; // [xsp+20h] [xbp-50h] BYREF
  __int64 v28; // [xsp+28h] [xbp-48h]
  __int64 v29; // [xsp+30h] [xbp-40h]
  __int64 v30; // [xsp+38h] [xbp-38h]
  __int64 v31; // [xsp+40h] [xbp-30h]
  __int64 v32; // [xsp+48h] [xbp-28h]
  __int64 v33; // [xsp+50h] [xbp-20h]
  __int64 v34; // [xsp+58h] [xbp-18h]
  __int64 v35; // [xsp+60h] [xbp-10h]
  __int64 v36; // [xsp+68h] [xbp-8h]

  v36 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v34 = 0;
  v35 = 0;
  v32 = 0;
  v33 = 0;
  v30 = 0;
  v31 = 0;
  v28 = 0;
  v29 = 0;
  v26 = 0;
  v27 = 0;
  v24 = 0;
  v25 = 0;
  if ( !a1 || !a2 )
  {
    v20 = &unk_26FEB0;
LABEL_25:
    printk(v20, "sde_hw_rc_setup_pu_roi");
    result = 4294967274LL;
    goto LABEL_30;
  }
  if ( a2[2] != 72 )
  {
    v20 = &unk_2402E6;
    goto LABEL_25;
  }
  v3 = *(unsigned int **)a2;
  if ( !*(_QWORD *)a2 )
  {
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "full frame update\n");
    v3 = (unsigned int *)&v27;
    v34 = 0;
    v35 = 0;
    v32 = 0;
    v33 = 0;
    v30 = 0;
    v31 = 0;
    v28 = 0;
    v29 = 0;
    v27 = 0;
  }
  v5 = (_DWORD *)a1[185];
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "sde_hw_rc_setup_pu_roi",
    492,
    -1,
    *(_DWORD *)(*(_QWORD *)(a1[9] + 48LL) + 536LL),
    (int)v3,
    (int)v5,
    v5[4],
    239);
  if ( v5 && v5[4] )
  {
    sde_kms_rect_merge_rectangles(v3, (__int64)&v25);
    ajusted_roi_0 = sde_hw_rc_get_ajusted_roi_0(a2, (unsigned __int16 *)&v25, (unsigned __int16 *)&v26);
    if ( ajusted_roi_0 )
    {
      v21 = ajusted_roi_0;
      v22 = &unk_27E9ED;
    }
    else
    {
      v9 = a2[7];
      switch ( v9 )
      {
        case 1:
          v10 = 0;
          break;
        case 4:
          v10 = 3;
          break;
        case 2:
          v10 = 1;
          break;
        default:
          _drm_err("invalid number of mixers:%d\n", v9);
          printk(&unk_25FB20, "sde_hw_rc_setup_pu_roi");
          result = 4294967274LL;
          goto LABEL_30;
      }
      _drm_dev_dbg(0, 0, 0, "number mixers:%u, merge mode:%u\n", v9, v10);
      param_rb_0 = sde_hw_rc_get_param_rb_0(v5, (unsigned __int16 *)&v26, (_DWORD *)&v24 + 1, (int *)&v24);
      if ( param_rb_0 )
      {
        v21 = param_rb_0;
        v22 = &unk_243F2D;
      }
      else
      {
        result = sde_hw_rc_program_enable_bits(a1, v5, (unsigned int)v5[4], (unsigned int)v24, HIDWORD(v24), v10, &v26);
        if ( !(_DWORD)result )
        {
          v13 = (_QWORD *)a1[186];
          *v13 = *(_QWORD *)v3;
          v14 = *((_QWORD *)v3 + 4);
          v15 = *((_QWORD *)v3 + 1);
          v16 = *((_QWORD *)v3 + 2);
          v13[3] = *((_QWORD *)v3 + 3);
          v13[4] = v14;
          v13[1] = v15;
          v13[2] = v16;
          v17 = *((_QWORD *)v3 + 8);
          v18 = *((_QWORD *)v3 + 5);
          v19 = *((_QWORD *)v3 + 6);
          v13[7] = *((_QWORD *)v3 + 7);
          v13[8] = v17;
          v13[5] = v18;
          v13[6] = v19;
          goto LABEL_30;
        }
        v21 = result;
        v22 = &unk_23967F;
      }
    }
    printk(v22, "sde_hw_rc_setup_pu_roi");
    result = v21;
    goto LABEL_30;
  }
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "no previous rc mask programmed\n");
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "sde_hw_rc_setup_pu_roi",
    497,
    -1,
    *(_DWORD *)(*(_QWORD *)(a1[9] + 48LL) + 536LL),
    -1059143953,
    v6,
    v7,
    v23);
  result = 1;
LABEL_30:
  _ReadStatusReg(SP_EL0);
  return result;
}
