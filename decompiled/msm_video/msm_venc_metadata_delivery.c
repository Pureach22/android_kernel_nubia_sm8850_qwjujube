__int64 __fastcall msm_venc_metadata_delivery(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x4
  _BYTE *v6; // x11
  __int64 v7; // x8
  _BYTE *v8; // x10
  char v9; // t1
  unsigned int v10; // w12
  __int64 result; // x0
  __int64 v12; // x19
  int v13; // [xsp+8h] [xbp-88h] BYREF
  __int64 v14; // [xsp+Ch] [xbp-84h]
  __int64 v15; // [xsp+14h] [xbp-7Ch]
  __int64 v16; // [xsp+1Ch] [xbp-74h]
  __int64 v17; // [xsp+24h] [xbp-6Ch]
  __int64 v18; // [xsp+2Ch] [xbp-64h]
  __int64 v19; // [xsp+34h] [xbp-5Ch]
  __int64 v20; // [xsp+3Ch] [xbp-54h]
  __int64 v21; // [xsp+44h] [xbp-4Ch]
  __int64 v22; // [xsp+4Ch] [xbp-44h]
  __int64 v23; // [xsp+54h] [xbp-3Ch]
  __int64 v24; // [xsp+5Ch] [xbp-34h]
  __int64 v25; // [xsp+64h] [xbp-2Ch]
  __int64 v26; // [xsp+6Ch] [xbp-24h]
  __int64 v27; // [xsp+74h] [xbp-1Ch]
  __int64 v28; // [xsp+7Ch] [xbp-14h]
  int v29; // [xsp+84h] [xbp-Ch]
  __int64 v30; // [xsp+88h] [xbp-8h]

  v30 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
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
  v17 = 0;
  v16 = 0;
  v15 = 0;
  v14 = 0;
  if ( a1 && (msm_vidc_debug & 2) != 0 )
  {
    v12 = a1;
    printk(&unk_9602D, "high", a1 + 340, "msm_venc_metadata_delivery", a5);
    a1 = v12;
  }
  v5 = 0;
  v6 = (_BYTE *)(a1 + 4536);
  v13 = 4;
  v7 = 196;
  v8 = (_BYTE *)(a1 + 4536);
  while ( 1 )
  {
    v9 = *v8;
    v8 += 168;
    if ( (v9 & 0x80) == 0 || (~*((_DWORD *)v6 - 4) & 3LL) != 0 )
      goto LABEL_5;
    v10 = v5 + 1;
    if ( (unsigned int)(v5 + 1) >= 0x20 )
      break;
    v5 = v10;
    *(&v13 + v10) = *((_DWORD *)v6 - 1);
LABEL_5:
    --v7;
    v6 = v8;
    if ( !v7 )
    {
      result = msm_vidc_session_command(
                 a1,
                 16777226,
                 0,
                 11,
                 &v13,
                 (unsigned int)(4 * v5 + 4),
                 "msm_venc_metadata_delivery");
      goto LABEL_11;
    }
  }
  if ( a1 && (msm_vidc_debug & 1) != 0 )
  {
    printk(&unk_88E19, "err ", a1 + 340, "msm_venc_metadata_delivery", v5);
    result = 4294967274LL;
  }
  else
  {
    result = 4294967274LL;
  }
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
