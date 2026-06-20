__int64 __fastcall msm_venc_s_param(__int64 a1, unsigned int *a2)
{
  __int64 v4; // x8
  unsigned int v5; // w21
  __int64 v6; // x9
  __int64 v7; // x10
  unsigned __int64 v8; // x25
  unsigned int v9; // w26
  unsigned int v10; // w9
  unsigned int v11; // w28
  unsigned int v12; // w8
  char v13; // w24
  unsigned int v14; // w23
  __int64 v15; // x8
  __int64 v16; // x10
  __int64 result; // x0
  __int64 v18; // x4
  __int64 v19; // x2
  unsigned int v20; // w19
  unsigned int v21; // w0
  __int64 v22; // x4
  unsigned int v23; // w21
  __int64 v24; // x4
  __int64 v25; // x0
  __int64 v26; // x4
  unsigned int v27; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v28; // [xsp+8h] [xbp-8h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = 19456;
  v5 = *a2;
  if ( *a2 == 10 )
  {
    v4 = 19624;
    v6 = 19640;
  }
  else
  {
    v6 = 19472;
  }
  v7 = 19448;
  v8 = *(_QWORD *)(a1 + v6);
  v9 = *(_DWORD *)(a1 + v4);
  if ( v5 == 10 )
    v7 = 19616;
  v10 = a2[4];
  v11 = *(_DWORD *)(a1 + v7);
  a2[1] = 4096;
  if ( !v10 || (v12 = a2[3]) == 0 )
  {
    if ( a1 && (msm_vidc_debug & 1) != 0 )
    {
      v25 = v4l2_type_name(v5);
      printk(&unk_85769, "err ", a1 + 340, "msm_venc_s_param", v25);
      v12 = a2[3];
      if ( v12 )
      {
LABEL_11:
        v10 = a2[4];
        if ( v10 )
          goto LABEL_12;
LABEL_51:
        v10 = v8 >> 16;
        a2[4] = v10;
        goto LABEL_12;
      }
    }
    else
    {
      v12 = a2[3];
      if ( v12 )
        goto LABEL_11;
    }
    v12 = 1;
    a2[3] = 1;
    v10 = a2[4];
    if ( v10 )
      goto LABEL_12;
    goto LABEL_51;
  }
LABEL_12:
  if ( v10 / v12 > HIWORD(v9) )
  {
    v27 = v9;
    if ( a1 )
    {
      if ( (msm_vidc_debug & 2) != 0 )
        goto LABEL_53;
      goto LABEL_21;
    }
LABEL_24:
    v13 = 1;
    goto LABEL_26;
  }
  if ( v10 / v12 >= HIWORD(v11) )
  {
    v9 = (v10 % v12) | ((v10 / v12) << 16);
    v27 = v9;
    if ( a1 )
      goto LABEL_21;
    goto LABEL_24;
  }
  v27 = v11;
  if ( !a1 )
  {
    v13 = 1;
    v9 = v11;
    goto LABEL_26;
  }
  if ( (msm_vidc_debug & 2) != 0 )
  {
    v9 = v11;
LABEL_53:
    v26 = v4l2_type_name(*a2);
    printk(&unk_7F809, "high", a1 + 340, "msm_venc_s_param", v26);
    goto LABEL_21;
  }
  v9 = v11;
LABEL_21:
  if ( (msm_vidc_debug & 2) != 0 )
  {
    v24 = v4l2_type_name(*a2);
    printk(&unk_8EE9E, "high", a1 + 340, "msm_venc_s_param", v24);
  }
  v13 = 0;
LABEL_26:
  if ( v5 == 10 )
    v14 = 91;
  else
    v14 = 90;
  ((void (__fastcall *)(__int64, _QWORD, _QWORD, const char *))msm_vidc_update_cap_value)(
    a1,
    v14,
    v9,
    "msm_venc_s_param");
  if ( *(_QWORD *)(a1 + 33416) )
    goto LABEL_30;
  if ( *a2 == 9 )
  {
    if ( (*(_WORD *)(*(_QWORD *)(a1 + 1848) + 320LL) & 1) == 0 )
    {
LABEL_30:
      v15 = 19488;
      if ( v5 == 10 )
        v15 = 19656;
      v16 = *(_QWORD *)(a1 + 1848);
      *(_DWORD *)(a1 + v15) |= 0x10u;
      if ( (*(_WORD *)(v16 + 320) & 1) != 0 )
      {
        result = venus_hfi_session_property(a1, 50331916, 0, 1, 8, &v27, 4);
        if ( (_DWORD)result )
        {
          if ( (v13 & 1) == 0 && (msm_vidc_debug & 1) != 0 )
          {
            v19 = a1 + 340;
            v20 = result;
            printk(&unk_8D63A, "err ", v19, "msm_venc_s_param", v18);
            result = v20;
          }
        }
        else
        {
          *(_DWORD *)(a1 + 38696) = v27;
        }
      }
      else
      {
        result = 0;
      }
      goto LABEL_48;
    }
  }
  else if ( *a2 != 10 || (*(_WORD *)(*(_QWORD *)(a1 + 1840) + 320LL) & 1) == 0 )
  {
    goto LABEL_30;
  }
  v21 = msm_vidc_check_core_mbps(a1);
  if ( !v21 )
    goto LABEL_30;
  v23 = v21;
  if ( (v13 & 1) == 0 && (msm_vidc_debug & 1) != 0 )
  {
    printk(&unk_9456E, "err ", a1 + 340, "msm_venc_s_param", v22);
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_921D8, "err ", a1 + 340, "msm_venc_s_param", HIWORD(v9));
  }
  ((void (__fastcall *)(__int64, _QWORD, unsigned __int64, const char *))msm_vidc_update_cap_value)(
    a1,
    v14,
    v8 & 0xFFFF0000,
    "msm_venc_s_param");
  result = v23;
LABEL_48:
  _ReadStatusReg(SP_EL0);
  return result;
}
