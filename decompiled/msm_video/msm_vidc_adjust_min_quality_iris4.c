__int64 __fastcall msm_vidc_adjust_min_quality_iris4(__int64 a1)
{
  __int64 v1; // x8
  __int64 result; // x0
  __int64 v4; // x2
  unsigned int v5; // w21
  unsigned int v6; // w20
  unsigned int v7; // w22
  __int64 v8; // x4
  void *v9; // x0
  __int64 v10; // [xsp+0h] [xbp-20h] BYREF
  __int64 v11; // [xsp+8h] [xbp-18h] BYREF
  __int64 v12; // [xsp+10h] [xbp-10h]
  __int64 v13; // [xsp+18h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD *)(a1 + 1848);
  v11 = -1;
  v12 = -1;
  v10 = -1;
  if ( (*(_WORD *)(v1 + 320) & 1) != 0 )
    goto LABEL_8;
  if ( (unsigned int)((__int64 (*)(void))msm_vidc_get_parent_value)()
    || (unsigned int)((__int64 (__fastcall *)(__int64, __int64, __int64, __int64 *, const char *))msm_vidc_get_parent_value)(
                       a1,
                       71,
                       65,
                       &v11,
                       "msm_vidc_adjust_min_quality_iris4") )
  {
    goto LABEL_4;
  }
  if ( v12 )
    goto LABEL_6;
  v5 = *(_DWORD *)(a1 + 600);
  v6 = *(_DWORD *)(a1 + 19474);
  v7 = *(_DWORD *)(a1 + 604);
  if ( *(_DWORD *)(a1 + 312) != 2 )
    goto LABEL_21;
  if ( !(unsigned int)((__int64 (__fastcall *)(__int64, __int64, __int64, __int64 *, const char *))msm_vidc_get_parent_value)(
                        a1,
                        71,
                        82,
                        &v10,
                        "msm_vidc_adjust_min_quality_iris4") )
  {
    if ( (int)v10 > 127 )
    {
      if ( (_DWORD)v10 != 256 && (_DWORD)v10 != 128 )
        goto LABEL_21;
    }
    else if ( (_DWORD)v10 != 8 && (_DWORD)v10 != 16 )
    {
LABEL_21:
      if ( (res_is_greater_than(v5, v7, 1920, 1080) & 1) != 0 )
      {
        if ( a1 && (msm_vidc_debug & 2) != 0 )
          printk(&unk_80030, "high", a1 + 340, "msm_vidc_adjust_min_quality_iris4", v5);
        goto LABEL_6;
      }
      if ( v6 >= 0x3D )
      {
        if ( a1 && (msm_vidc_debug & 2) != 0 )
          printk(&unk_8980F, "high", a1 + 340, "msm_vidc_adjust_min_quality_iris4", v6);
        goto LABEL_6;
      }
      if ( v11 < 1 || *(_DWORD *)(a1 + 1832) == 3 )
      {
        v4 = 70;
        goto LABEL_7;
      }
      if ( !a1 || (msm_vidc_debug & 2) == 0 )
      {
LABEL_6:
        v4 = 0;
LABEL_7:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *))msm_vidc_update_cap_value)(
          a1,
          71,
          v4,
          "msm_vidc_adjust_min_quality_iris4");
LABEL_8:
        result = 0;
        goto LABEL_9;
      }
      v9 = &unk_81B91;
LABEL_35:
      printk(v9, "high", a1 + 340, "msm_vidc_adjust_min_quality_iris4", v8);
      goto LABEL_6;
    }
    if ( !a1 || (msm_vidc_debug & 2) == 0 )
      goto LABEL_6;
    v9 = &unk_95125;
    goto LABEL_35;
  }
LABEL_4:
  result = 4294967274LL;
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
