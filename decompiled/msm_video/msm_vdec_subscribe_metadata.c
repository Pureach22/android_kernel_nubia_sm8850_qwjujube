__int64 __fastcall msm_vdec_subscribe_metadata(__int64 a1, unsigned int a2)
{
  unsigned int v4; // w21
  __int64 v5; // x22
  _BYTE *v6; // x26
  _BYTE *v7; // x25
  bool v8; // cf
  char v9; // t1
  unsigned int v10; // w8
  __int64 v11; // x22
  _BYTE *v12; // x26
  _BYTE *v13; // x25
  char v14; // t1
  unsigned int v15; // w8
  __int64 result; // x0
  int v17; // [xsp+8h] [xbp-88h] BYREF
  __int64 v18; // [xsp+Ch] [xbp-84h]
  __int64 v19; // [xsp+14h] [xbp-7Ch]
  __int64 v20; // [xsp+1Ch] [xbp-74h]
  __int64 v21; // [xsp+24h] [xbp-6Ch]
  __int64 v22; // [xsp+2Ch] [xbp-64h]
  __int64 v23; // [xsp+34h] [xbp-5Ch]
  __int64 v24; // [xsp+3Ch] [xbp-54h]
  __int64 v25; // [xsp+44h] [xbp-4Ch]
  __int64 v26; // [xsp+4Ch] [xbp-44h]
  __int64 v27; // [xsp+54h] [xbp-3Ch]
  __int64 v28; // [xsp+5Ch] [xbp-34h]
  __int64 v29; // [xsp+64h] [xbp-2Ch]
  __int64 v30; // [xsp+6Ch] [xbp-24h]
  __int64 v31; // [xsp+74h] [xbp-1Ch]
  __int64 v32; // [xsp+7Ch] [xbp-14h]
  int v33; // [xsp+84h] [xbp-Ch]
  __int64 v34; // [xsp+88h] [xbp-8h]

  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
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
  v20 = 0;
  v19 = 0;
  v18 = 0;
  if ( a1 && (msm_vidc_debug & 2) != 0 )
    printk(&unk_8B2D6, "high", a1 + 340, "msm_vdec_subscribe_metadata", a2);
  v17 = 4;
  if ( a2 )
  {
    if ( a2 == 1 )
    {
      v4 = 0;
      v5 = -196;
      v6 = (_BYTE *)(a1 + 4536);
      v7 = (_BYTE *)(a1 + 4536);
      while ( 1 )
      {
        v9 = *v7;
        v7 += 168;
        if ( v9 < 0
          && (~*((_DWORD *)v6 - 4) & 0x11LL) == 0
          && (msm_vidc_allow_metadata_subscription(a1, (unsigned int)(v5 + 197), 1) & 1) != 0 )
        {
          v10 = v4 + 1;
          if ( v4 + 1 >= 0x20 )
            goto LABEL_26;
          ++v4;
          *(&v17 + v10) = *((_DWORD *)v6 - 1);
        }
        v8 = __CFADD__(v5++, 1);
        v6 = v7;
        if ( v8 )
          goto LABEL_20;
      }
    }
    if ( a1 && (msm_vidc_debug & 1) != 0 )
      printk(&unk_833BC, "err ", a1 + 340, "msm_vdec_subscribe_metadata", a2);
    goto LABEL_24;
  }
  v4 = 0;
  v11 = -196;
  v12 = (_BYTE *)(a1 + 4536);
  v13 = (_BYTE *)(a1 + 4536);
  while ( 1 )
  {
    v14 = *v13;
    v13 += 168;
    if ( (v14 & 0x80) == 0
      || (~*((_DWORD *)v12 - 4) & 9LL) != 0
      || (msm_vidc_allow_metadata_subscription(a1, (unsigned int)(v11 + 197), 0) & 1) == 0 )
    {
      goto LABEL_14;
    }
    v15 = v4 + 1;
    if ( v4 + 1 >= 0x20 )
      break;
    ++v4;
    *(&v17 + v15) = *((_DWORD *)v12 - 1);
LABEL_14:
    v8 = __CFADD__(v11++, 1);
    v12 = v13;
    if ( v8 )
    {
LABEL_20:
      result = msm_vidc_session_command(a1, 16777227, a2, 11, &v17, 4 * v4 + 4, "msm_vdec_subscribe_metadata");
      goto LABEL_25;
    }
  }
LABEL_26:
  if ( a1 && (msm_vidc_debug & 1) != 0 )
    printk(&unk_88E19, "err ", a1 + 340, "msm_vdec_subscribe_metadata", v4);
LABEL_24:
  result = 4294967274LL;
LABEL_25:
  _ReadStatusReg(SP_EL0);
  return result;
}
