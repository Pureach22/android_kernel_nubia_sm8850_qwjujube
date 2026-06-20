__int64 __fastcall msm_vdec_subscribe_property(__int64 a1, unsigned int a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v7; // x21
  _BYTE *v8; // x24
  __int64 v9; // x4
  __int64 v10; // x9
  unsigned int *v11; // x8
  unsigned int **v12; // x9
  __int64 v13; // x26
  __int64 v14; // x9
  unsigned int *v15; // x8
  int **v16; // x9
  __int64 v17; // x26
  __int64 v18; // x9
  unsigned int *v19; // x8
  __int64 v20; // x9
  unsigned int *v21; // x8
  __int64 v22; // x9
  unsigned int *v23; // x8
  __int64 v24; // x9
  unsigned int *v25; // x8
  __int64 v26; // x9
  unsigned int *v27; // x8
  __int64 result; // x0
  __int64 v29; // x9
  unsigned int *v30; // x8
  __int64 v31; // x9
  unsigned int *v32; // x8
  __int64 v33; // x9
  unsigned int *v34; // x8
  int *v35; // x27
  unsigned int v36; // w25
  __int64 v37; // x4
  int v38; // w8
  __int64 v39; // x9
  unsigned int *v40; // x8
  int *v41; // x27
  __int64 v42; // x4
  int v43; // w8
  __int64 v44; // x9
  unsigned int *v45; // x8
  int v46; // [xsp+8h] [xbp-88h] BYREF
  __int64 v47; // [xsp+Ch] [xbp-84h]
  __int64 v48; // [xsp+14h] [xbp-7Ch]
  __int64 v49; // [xsp+1Ch] [xbp-74h]
  __int64 v50; // [xsp+24h] [xbp-6Ch]
  __int64 v51; // [xsp+2Ch] [xbp-64h]
  __int64 v52; // [xsp+34h] [xbp-5Ch]
  __int64 v53; // [xsp+3Ch] [xbp-54h]
  __int64 v54; // [xsp+44h] [xbp-4Ch]
  __int64 v55; // [xsp+4Ch] [xbp-44h]
  __int64 v56; // [xsp+54h] [xbp-3Ch]
  __int64 v57; // [xsp+5Ch] [xbp-34h]
  __int64 v58; // [xsp+64h] [xbp-2Ch]
  __int64 v59; // [xsp+6Ch] [xbp-24h]
  __int64 v60; // [xsp+74h] [xbp-1Ch]
  __int64 v61; // [xsp+7Ch] [xbp-14h]
  int v62; // [xsp+84h] [xbp-Ch]
  __int64 v63; // [xsp+88h] [xbp-8h]

  v63 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(_QWORD *)(a1 + 320);
  v8 = (_BYTE *)(a1 + 38692);
  v62 = 0;
  v61 = 0;
  v60 = 0;
  v59 = 0;
  v58 = 0;
  v57 = 0;
  v56 = 0;
  v55 = 0;
  v54 = 0;
  v53 = 0;
  v52 = 0;
  v51 = 0;
  v50 = 0;
  v49 = 0;
  v48 = 0;
  v47 = 0;
  if ( a1 && (msm_vidc_debug & 2) != 0 )
    printk(&unk_9602D, "high", a1 + 340, "msm_vdec_subscribe_property", a5);
  v9 = *(unsigned int *)(a1 + 312);
  v46 = 2;
  if ( !a2 )
  {
    if ( (int)v9 <= 7 )
    {
      if ( (_DWORD)v9 == 1 )
      {
        v39 = *(_QWORD *)(v7 + 3912);
        v40 = (unsigned int *)(v39 + 448);
        v16 = (int **)(v39 + 440);
        v17 = *v40;
        if ( !(_DWORD)v17 )
          goto LABEL_67;
LABEL_56:
        v41 = *v16;
        v36 = 0;
        while ( (msm_vidc_allow_property(a1, (unsigned int)*v41) & 1) == 0 )
        {
          if ( *v41 == 50332026 )
            goto LABEL_63;
LABEL_57:
          --v17;
          ++v41;
          if ( !v17 )
            goto LABEL_68;
        }
        if ( ++v36 > 0x1F )
LABEL_71:
          __break(0x5512u);
        v43 = *v41;
        *(&v46 + v36) = *v41;
        if ( v43 != 50332026 )
          goto LABEL_57;
LABEL_63:
        *v8 = 1;
        if ( a1 && (msm_vidc_debug & 2) != 0 )
          printk(&unk_88E5D, "high", a1 + 340, "msm_vdec_subscribe_property", v42);
        goto LABEL_57;
      }
      if ( (_DWORD)v9 != 2 )
      {
        if ( (_DWORD)v9 != 4 )
          goto LABEL_37;
        v22 = *(_QWORD *)(v7 + 3912);
        v23 = (unsigned int *)(v22 + 496);
        v16 = (int **)(v22 + 488);
        v17 = *v23;
        if ( !(_DWORD)v17 )
          goto LABEL_67;
        goto LABEL_56;
      }
    }
    else
    {
      if ( (int)v9 > 31 )
      {
        if ( (_DWORD)v9 == 32 )
        {
          v44 = *(_QWORD *)(v7 + 3912);
          v45 = (unsigned int *)(v44 + 528);
          v16 = (int **)(v44 + 520);
          v17 = *v45;
          if ( !(_DWORD)v17 )
            goto LABEL_67;
        }
        else
        {
          if ( (_DWORD)v9 != 64 )
            goto LABEL_37;
          v26 = *(_QWORD *)(v7 + 3912);
          v27 = (unsigned int *)(v26 + 480);
          v16 = (int **)(v26 + 472);
          v17 = *v27;
          if ( !(_DWORD)v17 )
            goto LABEL_67;
        }
        goto LABEL_56;
      }
      if ( (_DWORD)v9 != 8 )
      {
        if ( (_DWORD)v9 != 16 )
          goto LABEL_37;
        v14 = *(_QWORD *)(v7 + 3912);
        v15 = (unsigned int *)(v14 + 512);
        v16 = (int **)(v14 + 504);
        v17 = *v15;
        if ( !(_DWORD)v17 )
          goto LABEL_67;
        goto LABEL_56;
      }
    }
    v29 = *(_QWORD *)(v7 + 3912);
    v30 = (unsigned int *)(v29 + 464);
    v16 = (int **)(v29 + 456);
    v17 = *v30;
    if ( !(_DWORD)v17 )
      goto LABEL_67;
    goto LABEL_56;
  }
  if ( (int)v9 <= 7 )
  {
    switch ( (_DWORD)v9 )
    {
      case 1:
        v31 = *(_QWORD *)(v7 + 3912);
        v32 = (unsigned int *)(v31 + 544);
        v12 = (unsigned int **)(v31 + 536);
        v13 = *v32;
        if ( (_DWORD)v13 )
          goto LABEL_45;
        break;
      case 2:
        goto LABEL_31;
      case 4:
        v18 = *(_QWORD *)(v7 + 3912);
        v19 = (unsigned int *)(v18 + 592);
        v12 = (unsigned int **)(v18 + 584);
        v13 = *v19;
        if ( (_DWORD)v13 )
          goto LABEL_45;
        break;
      default:
        goto LABEL_37;
    }
  }
  else
  {
    if ( (int)v9 <= 31 )
    {
      if ( (_DWORD)v9 != 8 )
      {
        if ( (_DWORD)v9 == 16 )
        {
          v10 = *(_QWORD *)(v7 + 3912);
          v11 = (unsigned int *)(v10 + 608);
          v12 = (unsigned int **)(v10 + 600);
          v13 = *v11;
          if ( !(_DWORD)v13 )
            goto LABEL_67;
          goto LABEL_45;
        }
LABEL_37:
        if ( a1 && (msm_vidc_debug & 1) != 0 )
        {
          printk(&unk_85739, "err ", a1 + 340, "msm_vdec_subscribe_property", v9);
          result = 4294967274LL;
        }
        else
        {
          result = 4294967274LL;
        }
        goto LABEL_69;
      }
LABEL_31:
      v24 = *(_QWORD *)(v7 + 3912);
      v25 = (unsigned int *)(v24 + 560);
      v12 = (unsigned int **)(v24 + 552);
      v13 = *v25;
      if ( !(_DWORD)v13 )
        goto LABEL_67;
      goto LABEL_45;
    }
    if ( (_DWORD)v9 == 32 )
    {
      v33 = *(_QWORD *)(v7 + 3912);
      v34 = (unsigned int *)(v33 + 624);
      v12 = (unsigned int **)(v33 + 616);
      v13 = *v34;
      if ( !(_DWORD)v13 )
        goto LABEL_67;
      goto LABEL_45;
    }
    if ( (_DWORD)v9 != 64 )
      goto LABEL_37;
    v20 = *(_QWORD *)(v7 + 3912);
    v21 = (unsigned int *)(v20 + 576);
    v12 = (unsigned int **)(v20 + 568);
    v13 = *v21;
    if ( (_DWORD)v13 )
    {
LABEL_45:
      v35 = (int *)*v12;
      v36 = 0;
      while ( 1 )
      {
        if ( (msm_vidc_allow_property(a1, (unsigned int)*v35) & 1) != 0 )
        {
          if ( ++v36 > 0x1F )
            goto LABEL_71;
          v38 = *v35;
          *(&v46 + v36) = *v35;
          if ( v38 == 50332026 )
          {
LABEL_52:
            v8[1] = 1;
            if ( a1 && (msm_vidc_debug & 2) != 0 )
              printk(&unk_96BD4, "high", a1 + 340, "msm_vdec_subscribe_property", v37);
          }
        }
        else if ( *v35 == 50332026 )
        {
          goto LABEL_52;
        }
        --v13;
        ++v35;
        if ( !v13 )
          goto LABEL_68;
      }
    }
  }
LABEL_67:
  v36 = 0;
LABEL_68:
  result = msm_vidc_session_command(a1, 16777227, a2, 11, &v46, 4 * v36 + 4, "msm_vdec_subscribe_property");
LABEL_69:
  _ReadStatusReg(SP_EL0);
  return result;
}
