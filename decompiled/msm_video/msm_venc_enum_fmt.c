__int64 __fastcall msm_venc_enum_fmt(__int64 result, unsigned int *a2)
{
  __int64 v2; // x8
  unsigned int v3; // w9
  __int64 v4; // x9
  unsigned __int64 v5; // x10
  __int64 v6; // x11
  __int64 v7; // x14
  unsigned int *v8; // x20
  __int64 v9; // x19
  unsigned int v10; // w0
  __int64 v11; // x9
  unsigned int v12; // w8
  __int64 v13; // x11
  __int64 v14; // x9
  unsigned __int64 v15; // x10
  __int64 v16; // x14
  unsigned int v17; // w8
  __int64 v18; // x19
  unsigned int v19; // w0
  unsigned int *v20; // x20
  __int64 v21; // x19
  unsigned int v22; // w0
  unsigned int v23; // w19
  __int64 v24; // x20
  _QWORD v25[17]; // [xsp+8h] [xbp-88h] BYREF

  v25[16] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *a2;
  memset(v25, 0, 128);
  if ( (unsigned int)v2 >= 0x20 )
  {
    if ( (msm_vidc_debug & 1) == 0 )
      goto LABEL_31;
    printk(&unk_83321, "err ", 0xFFFFFFFFLL, "codec", "msm_venc_enum_fmt");
    result = 4294967274LL;
    goto LABEL_32;
  }
  v3 = a2[1];
  if ( v3 - 13 < 2 )
  {
    if ( (_DWORD)v2 )
      goto LABEL_31;
    v8 = a2;
    v9 = result;
    v10 = v4l2_colorformat_from_driver(result, 0x80000000LL, "msm_venc_enum_fmt");
    a2 = v8;
    v11 = *(_QWORD *)"metadata";
    v12 = v10;
    result = v9;
    v8[11] = v12;
    *((_BYTE *)v8 + 20) = 0;
    goto LABEL_23;
  }
  if ( v3 == 10 )
  {
    v13 = *(_QWORD *)(result + 18120);
    v14 = 0;
    v15 = 0;
    while ( 1 )
    {
      v16 = (1LL << v14) & v13;
      if ( v16 )
      {
        if ( v15 > 0x1F )
        {
LABEL_20:
          v17 = *((_DWORD *)v25 + v2);
          if ( !v17 )
            goto LABEL_31;
          v8 = a2;
          v18 = result;
          v19 = v4l2_colorformat_from_driver(result, v17, "msm_venc_enum_fmt");
          v8[11] = v19;
          if ( !v19 )
            goto LABEL_31;
          v11 = *(_QWORD *)"colorformat";
          a2 = v8;
          v8[5] = 7627117;
          result = v18;
LABEL_23:
          *(_QWORD *)(v8 + 3) = v11;
LABEL_27:
          a2[15] = 0;
          *(_QWORD *)(a2 + 13) = 0;
          if ( result )
          {
            if ( (msm_vidc_debug & 2) != 0 )
            {
              v23 = *a2;
              v24 = result;
              v4l2_pixelfmt_name(result, a2[11]);
              printk(&unk_829D5, "high", v24 + 340, "msm_venc_enum_fmt", v23);
            }
            result = 0;
          }
          goto LABEL_32;
        }
        *((_DWORD *)v25 + v15++) = v16;
      }
      if ( ++v14 == 32 )
        goto LABEL_20;
    }
  }
  if ( v3 != 9 )
    goto LABEL_27;
  v4 = 0;
  v5 = 0;
  v6 = *(_QWORD *)(*(_QWORD *)(result + 320) + 3968LL);
  while ( 1 )
  {
    v7 = (1LL << v4) & v6;
    if ( v7 )
      break;
LABEL_8:
    if ( ++v4 == 32 )
      goto LABEL_24;
  }
  if ( v5 <= 0x1F )
  {
    if ( v7 != 8 )
      *((_DWORD *)v25 + v5++) = v7;
    goto LABEL_8;
  }
LABEL_24:
  if ( *((_DWORD *)v25 + v2) )
  {
    v20 = a2;
    v21 = result;
    v22 = v4l2_codec_from_driver();
    v20[11] = v22;
    if ( v22 )
    {
      a2 = v20;
      *((_WORD *)v20 + 8) = 99;
      result = v21;
      *((_QWORD *)v20 + 1) = 0x65646F6300000001LL;
      goto LABEL_27;
    }
  }
LABEL_31:
  result = 4294967274LL;
LABEL_32:
  _ReadStatusReg(SP_EL0);
  return result;
}
