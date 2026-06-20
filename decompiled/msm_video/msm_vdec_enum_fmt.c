__int64 __fastcall msm_vdec_enum_fmt(__int64 result, unsigned int *a2)
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
  __int64 v16; // x2
  __int64 v17; // x3
  unsigned __int64 v18; // x3
  unsigned int v19; // w8
  __int64 v20; // x19
  unsigned int v21; // w0
  unsigned int *v22; // x20
  __int64 v23; // x19
  unsigned int v24; // w0
  unsigned int v25; // w19
  __int64 v26; // x20
  _QWORD v27[17]; // [xsp+8h] [xbp-88h] BYREF

  v27[16] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *a2;
  memset(v27, 0, 128);
  if ( (unsigned int)v2 >= 0x20 )
  {
    if ( (msm_vidc_debug & 1) == 0 )
      goto LABEL_49;
    printk(&unk_83321, "err ", 0xFFFFFFFFLL, "codec", "msm_vdec_enum_fmt");
    result = 4294967274LL;
    goto LABEL_50;
  }
  v3 = a2[1];
  if ( v3 - 13 < 2 )
  {
    if ( (_DWORD)v2 )
      goto LABEL_49;
    v8 = a2;
    v9 = result;
    v10 = v4l2_colorformat_from_driver(result, 0x80000000LL, "msm_vdec_enum_fmt");
    a2 = v8;
    v11 = *(_QWORD *)"metadata";
    v12 = v10;
    result = v9;
    v8[11] = v12;
    *((_BYTE *)v8 + 20) = 0;
    goto LABEL_41;
  }
  if ( v3 == 9 )
  {
    v13 = *(_QWORD *)(result + 18120);
    v14 = 0;
    v15 = 0;
    while ( 1 )
    {
      v16 = (1LL << v14) & v13;
      if ( !v16 )
        goto LABEL_16;
      if ( v15 > 0x1F )
      {
LABEL_38:
        v19 = *((_DWORD *)v27 + v2);
        if ( !v19 )
          goto LABEL_49;
        v8 = a2;
        v20 = result;
        v21 = v4l2_colorformat_from_driver(result, v19, "msm_vdec_enum_fmt");
        v8[11] = v21;
        if ( !v21 )
          goto LABEL_49;
        v11 = *(_QWORD *)"colorformat";
        a2 = v8;
        v8[5] = 7627117;
        result = v20;
LABEL_41:
        *(_QWORD *)(v8 + 3) = v11;
LABEL_45:
        a2[15] = 0;
        *(_QWORD *)(a2 + 13) = 0;
        if ( result )
        {
          if ( (msm_vidc_debug & 2) != 0 )
          {
            v25 = *a2;
            v26 = result;
            v4l2_pixelfmt_name(result, a2[11]);
            printk(&unk_829D5, "high", v26 + 340, "msm_vdec_enum_fmt", v25);
          }
          result = 0;
        }
        goto LABEL_50;
      }
      if ( (*(_WORD *)(*(_QWORD *)(result + 1840) + 320LL) & 1) != 0 )
        break;
LABEL_15:
      *((_DWORD *)v27 + v15++) = v16;
LABEL_16:
      if ( ++v14 == 32 )
        goto LABEL_38;
    }
    v17 = *(_QWORD *)(result + 32072);
    if ( v17 != 655370 )
    {
      if ( v17 != 524296 )
      {
        LOBYTE(v18) = 1;
        goto LABEL_32;
      }
      if ( (unsigned int)v16 < 0x41 )
      {
        v18 = 0x800000008000000BLL >> ((unsigned __int8)v16 - 1);
        goto LABEL_32;
      }
LABEL_31:
      LOBYTE(v18) = 0;
      goto LABEL_32;
    }
    LOBYTE(v18) = 1;
    if ( (int)v16 > 127 )
    {
      if ( (_DWORD)v16 != 128 && (_DWORD)v16 != 256 )
        goto LABEL_31;
    }
    else if ( (_DWORD)v16 != 8 && (_DWORD)v16 != 16 )
    {
      goto LABEL_31;
    }
LABEL_32:
    if ( *(_QWORD *)(result + 31904) == 1
      && ((unsigned int)v16 > 0x20 || ((1LL << v16) & 0x100000102LL) == 0)
      && (_DWORD)v16 != 128
      || (v18 & 1) == 0 )
    {
      goto LABEL_16;
    }
    goto LABEL_15;
  }
  if ( v3 != 10 )
    goto LABEL_45;
  v4 = 0;
  v5 = 0;
  v6 = *(_QWORD *)(*(_QWORD *)(result + 320) + 3984LL);
  while ( 1 )
  {
    v7 = (1LL << v4) & v6;
    if ( v7 )
      break;
LABEL_8:
    if ( ++v4 == 32 )
      goto LABEL_42;
  }
  if ( v5 <= 0x1F )
  {
    *((_DWORD *)v27 + v5++) = v7;
    goto LABEL_8;
  }
LABEL_42:
  if ( *((_DWORD *)v27 + v2) )
  {
    v22 = a2;
    v23 = result;
    v24 = v4l2_codec_from_driver();
    v22[11] = v24;
    if ( v24 )
    {
      a2 = v22;
      *((_WORD *)v22 + 8) = 99;
      result = v23;
      *((_QWORD *)v22 + 1) = 0x65646F6300000001LL;
      goto LABEL_45;
    }
  }
LABEL_49:
  result = 4294967274LL;
LABEL_50:
  _ReadStatusReg(SP_EL0);
  return result;
}
