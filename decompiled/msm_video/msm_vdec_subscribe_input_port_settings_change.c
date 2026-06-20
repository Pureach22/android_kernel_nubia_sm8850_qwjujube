__int64 __fastcall msm_vdec_subscribe_input_port_settings_change(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5)
{
  __int64 v6; // x4
  __int64 v7; // x8
  __int64 v8; // x9
  unsigned int *v9; // x8
  unsigned int *v10; // x24
  __int64 v11; // x9
  __int64 v12; // x9
  __int64 v13; // x9
  __int64 v14; // x9
  __int64 v15; // x9
  __int64 v16; // x25
  __int64 v17; // x9
  __int64 v18; // x10
  __int64 result; // x0
  __int64 v20; // x4
  unsigned int v21; // t1
  _QWORD *v22; // x8
  _DWORD *v23; // x8
  unsigned int v24; // w8
  unsigned int v25; // [xsp+4h] [xbp-8Ch]
  int v26; // [xsp+8h] [xbp-88h] BYREF
  __int64 v27; // [xsp+Ch] [xbp-84h]
  __int64 v28; // [xsp+14h] [xbp-7Ch]
  __int64 v29; // [xsp+1Ch] [xbp-74h]
  __int64 v30; // [xsp+24h] [xbp-6Ch]
  __int64 v31; // [xsp+2Ch] [xbp-64h]
  __int64 v32; // [xsp+34h] [xbp-5Ch]
  __int64 v33; // [xsp+3Ch] [xbp-54h]
  __int64 v34; // [xsp+44h] [xbp-4Ch]
  __int64 v35; // [xsp+4Ch] [xbp-44h]
  __int64 v36; // [xsp+54h] [xbp-3Ch]
  __int64 v37; // [xsp+5Ch] [xbp-34h]
  __int64 v38; // [xsp+64h] [xbp-2Ch]
  __int64 v39; // [xsp+6Ch] [xbp-24h]
  __int64 v40; // [xsp+74h] [xbp-1Ch]
  __int64 v41; // [xsp+7Ch] [xbp-14h]
  int v42; // [xsp+84h] [xbp-Ch]
  __int64 v43; // [xsp+88h] [xbp-8h]

  v43 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v42 = 0;
  v41 = 0;
  v40 = 0;
  v39 = 0;
  v38 = 0;
  v37 = 0;
  v36 = 0;
  v35 = 0;
  v34 = 0;
  v33 = 0;
  v32 = 0;
  v31 = 0;
  v30 = 0;
  v29 = 0;
  v28 = 0;
  v27 = 0;
  if ( a1 && (msm_vidc_debug & 2) != 0 )
    printk(&unk_9602D, "high", a1 + 340, "msm_vdec_subscribe_input_port_settings_change", a5);
  v6 = *(unsigned int *)(a1 + 312);
  v7 = *(_QWORD *)(a1 + 320);
  if ( (int)v6 <= 7 )
  {
    if ( (_DWORD)v6 == 1 )
    {
      v14 = *(_QWORD *)(v7 + 3912);
      v9 = (unsigned int *)(v14 + 352);
      v10 = *(unsigned int **)(v14 + 344);
      if ( !v10 )
        goto LABEL_54;
      goto LABEL_27;
    }
    if ( (_DWORD)v6 != 2 )
    {
      if ( (_DWORD)v6 == 4 )
      {
        v11 = *(_QWORD *)(v7 + 3912);
        v9 = (unsigned int *)(v11 + 400);
        v10 = *(unsigned int **)(v11 + 392);
        if ( !v10 )
          goto LABEL_54;
        goto LABEL_27;
      }
      goto LABEL_23;
    }
    goto LABEL_19;
  }
  if ( (int)v6 <= 31 )
  {
    if ( (_DWORD)v6 != 8 )
    {
      if ( (_DWORD)v6 == 16 )
      {
        v8 = *(_QWORD *)(v7 + 3912);
        v9 = (unsigned int *)(v8 + 416);
        v10 = *(unsigned int **)(v8 + 408);
        if ( !v10 )
          goto LABEL_54;
        goto LABEL_27;
      }
      goto LABEL_23;
    }
LABEL_19:
    v13 = *(_QWORD *)(v7 + 3912);
    v9 = (unsigned int *)(v13 + 368);
    v10 = *(unsigned int **)(v13 + 360);
    if ( !v10 )
      goto LABEL_54;
    goto LABEL_27;
  }
  if ( (_DWORD)v6 == 32 )
  {
    v15 = *(_QWORD *)(v7 + 3912);
    v9 = (unsigned int *)(v15 + 432);
    v10 = *(unsigned int **)(v15 + 424);
    if ( !v10 )
    {
LABEL_54:
      if ( a1 && (msm_vidc_debug & 1) != 0 )
        printk(&unk_8BE9D, "err ", a1 + 340, "msm_vdec_subscribe_input_port_settings_change", v6);
      goto LABEL_57;
    }
LABEL_27:
    v16 = *v9;
    if ( (_DWORD)v16 )
    {
      v17 = 0;
      v26 = 1;
      while ( v17 != 31 )
      {
        v18 = v17 + 1;
        if ( ((v17 + 1) & 0x3FFFFFFFFFFFFFFFLL) == 0x20 )
          goto LABEL_61;
        *(&v26 + v17 + 1) = v10[v17];
        ++v17;
        if ( v16 == v18 )
        {
          result = msm_vidc_session_command(
                     a1,
                     16777227,
                     0,
                     11,
                     &v26,
                     (unsigned int)(4 * v16 + 4),
                     "msm_vdec_subscribe_input_port_settings_change");
          while ( 2 )
          {
            v21 = *v10++;
            v20 = v21;
            v22 = &msm_vdec_subscribe_input_port_settings_change_prop_type_handle_arr;
            switch ( v21 )
            {
              case 0x3000103u:
                goto LABEL_49;
              case 0x3000105u:
                v22 = &unk_9AD58;
                goto LABEL_49;
              case 0x3000107u:
                v22 = &unk_9ADC8;
                goto LABEL_49;
              case 0x3000108u:
                v22 = &unk_9ADD8;
                goto LABEL_49;
              case 0x3000109u:
                v22 = &unk_9ADE8;
                goto LABEL_49;
              case 0x300010Fu:
                v22 = &unk_9AD68;
                goto LABEL_49;
              case 0x3000120u:
                v22 = &unk_9AD78;
                goto LABEL_49;
              case 0x3000124u:
                v22 = &unk_9AD88;
                goto LABEL_49;
              case 0x3000127u:
                v22 = &unk_9ADA8;
                goto LABEL_49;
              case 0x3000128u:
                v22 = &unk_9AD98;
                goto LABEL_49;
              case 0x3000155u:
                v22 = &unk_9ADB8;
                goto LABEL_49;
              case 0x3000180u:
                v22 = &unk_9ADF8;
                goto LABEL_49;
              case 0x3000181u:
                v22 = &unk_9AE08;
LABEL_49:
                v23 = (_DWORD *)v22[1];
                if ( *(v23 - 1) != 173732240 )
                  __break(0x8228u);
                v24 = ((__int64 (__fastcall *)(__int64, _QWORD))v23)(a1, 0);
                result = 0;
                if ( !v24 )
                  goto LABEL_52;
                result = v24;
                goto LABEL_59;
              default:
                if ( a1 && (msm_vidc_debug & 1) != 0 )
                {
                  v25 = result;
                  printk(&unk_93808, "err ", a1 + 340, "msm_vdec_subscribe_input_port_settings_change", v20);
                  result = v25;
                }
LABEL_52:
                if ( !--v16 )
                  goto LABEL_59;
                continue;
            }
          }
        }
      }
      __break(0x5512u);
LABEL_61:
      __break(1u);
    }
    goto LABEL_54;
  }
  if ( (_DWORD)v6 == 64 )
  {
    v12 = *(_QWORD *)(v7 + 3912);
    v9 = (unsigned int *)(v12 + 384);
    v10 = *(unsigned int **)(v12 + 376);
    if ( !v10 )
      goto LABEL_54;
    goto LABEL_27;
  }
LABEL_23:
  if ( a1 && (msm_vidc_debug & 1) != 0 )
    printk(&unk_85739, "err ", a1 + 340, "msm_vdec_subscribe_input_port_settings_change", v6);
LABEL_57:
  result = 4294967274LL;
LABEL_59:
  _ReadStatusReg(SP_EL0);
  return result;
}
