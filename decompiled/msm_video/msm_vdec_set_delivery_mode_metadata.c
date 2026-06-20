__int64 __fastcall msm_vdec_set_delivery_mode_metadata(__int64 a1, unsigned int a2, __int64 a3, __int64 a4, __int64 a5)
{
  unsigned int v7; // w21
  _BYTE *v8; // x26
  __int64 v9; // x22
  _BYTE *v10; // x25
  bool v11; // cf
  char v12; // t1
  unsigned int v13; // w8
  _BYTE *v14; // x11
  __int64 v15; // x8
  _BYTE *v16; // x10
  char v17; // t1
  unsigned int v18; // w12
  __int64 result; // x0
  int v20; // [xsp+8h] [xbp-88h] BYREF
  __int64 v21; // [xsp+Ch] [xbp-84h]
  __int64 v22; // [xsp+14h] [xbp-7Ch]
  __int64 v23; // [xsp+1Ch] [xbp-74h]
  __int64 v24; // [xsp+24h] [xbp-6Ch]
  __int64 v25; // [xsp+2Ch] [xbp-64h]
  __int64 v26; // [xsp+34h] [xbp-5Ch]
  __int64 v27; // [xsp+3Ch] [xbp-54h]
  __int64 v28; // [xsp+44h] [xbp-4Ch]
  __int64 v29; // [xsp+4Ch] [xbp-44h]
  __int64 v30; // [xsp+54h] [xbp-3Ch]
  __int64 v31; // [xsp+5Ch] [xbp-34h]
  __int64 v32; // [xsp+64h] [xbp-2Ch]
  __int64 v33; // [xsp+6Ch] [xbp-24h]
  __int64 v34; // [xsp+74h] [xbp-1Ch]
  __int64 v35; // [xsp+7Ch] [xbp-14h]
  int v36; // [xsp+84h] [xbp-Ch]
  __int64 v37; // [xsp+88h] [xbp-8h]

  v37 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
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
  v26 = 0;
  v25 = 0;
  v24 = 0;
  v23 = 0;
  v22 = 0;
  v21 = 0;
  if ( a1 && (msm_vidc_debug & 2) != 0 )
    printk(&unk_9602D, "high", a1 + 340, "msm_vdec_set_delivery_mode_metadata", a5);
  v7 = 0;
  v20 = 4;
  if ( a2 )
  {
    v8 = (_BYTE *)(a1 + 4536);
    v9 = -196;
    v10 = (_BYTE *)(a1 + 4536);
    while ( 1 )
    {
      v12 = *v10;
      v10 += 168;
      if ( v12 < 0
        && (~*((_DWORD *)v8 - 4) & 5LL) == 0
        && (msm_vidc_allow_metadata_delivery(a1, (unsigned int)(v9 + 197), 1) & 1) != 0 )
      {
        v13 = v7 + 1;
        if ( v7 + 1 >= 0x20 )
          goto LABEL_20;
        ++v7;
        *(&v20 + v13) = *((_DWORD *)v8 - 1);
      }
      v11 = __CFADD__(v9++, 1);
      v8 = v10;
      if ( v11 )
        goto LABEL_18;
    }
  }
  v14 = (_BYTE *)(a1 + 4536);
  v15 = 196;
  v16 = (_BYTE *)(a1 + 4536);
  while ( 1 )
  {
    v17 = *v16;
    v16 += 168;
    if ( (v17 & 0x80) == 0 || (~*((_DWORD *)v14 - 4) & 3LL) != 0 )
      goto LABEL_13;
    v18 = v7 + 1;
    if ( v7 + 1 >= 0x20 )
      break;
    ++v7;
    *(&v20 + v18) = *((_DWORD *)v14 - 1);
LABEL_13:
    --v15;
    v14 = v16;
    if ( !v15 )
    {
LABEL_18:
      result = msm_vidc_session_command(a1, 16777226, a2, 11, &v20, 4 * v7 + 4, "msm_vdec_set_delivery_mode_metadata");
      goto LABEL_19;
    }
  }
LABEL_20:
  if ( a1 && (msm_vidc_debug & 1) != 0 )
  {
    printk(&unk_88E19, "err ", a1 + 340, "msm_vdec_set_delivery_mode_metadata", v7);
    result = 4294967274LL;
  }
  else
  {
    result = 4294967274LL;
  }
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return result;
}
