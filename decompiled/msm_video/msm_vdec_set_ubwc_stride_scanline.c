__int64 __fastcall msm_vdec_set_ubwc_stride_scanline(_DWORD *a1)
{
  int v2; // w21
  int v3; // w20
  int v4; // w0
  __int64 v5; // x4
  __int64 result; // x0
  int v7; // w8
  int v8; // w5
  unsigned int v9; // w6
  int v10; // w8
  unsigned int v11; // w7
  unsigned int v12; // w8
  unsigned int v13; // w8
  unsigned int v14; // w9
  unsigned int v15; // w9
  unsigned int v16; // w10
  unsigned int v17; // w10
  unsigned int v18; // w12
  unsigned int v19; // w11
  unsigned int v20; // w11
  unsigned int hfi_port; // w0
  __int64 v22; // x4
  _DWORD *v23; // x2
  unsigned int v24; // w19
  _DWORD v25[4]; // [xsp+28h] [xbp-18h] BYREF
  __int64 v26; // [xsp+38h] [xbp-8h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = a1[150];
  v3 = a1[151];
  v4 = v4l2_colorformat_to_driver(a1, (unsigned int)a1[152], "msm_vdec_set_ubwc_stride_scanline");
  if ( a1[78] != 16 || ((unsigned int)v4 > 0x20 || ((1LL << v4) & 0x100000102LL) == 0) && v4 != 128 )
  {
    result = 0;
    goto LABEL_89;
  }
  if ( !v2 )
  {
    v5 = 0;
    if ( !v3 )
    {
LABEL_37:
      v8 = 0;
      if ( !v2 )
        goto LABEL_38;
      goto LABEL_26;
    }
    goto LABEL_19;
  }
  v5 = 0;
  if ( v4 > 7 )
  {
    if ( v4 == 8 )
    {
      v5 = (768 * ((v2 + 191) / 0xC0u) / 3 + 255) & 0x7FFFFF00;
      if ( !v3 )
        goto LABEL_37;
      goto LABEL_19;
    }
    if ( v4 == 16 || v4 == 128 )
      v5 = (2 * v2 + 255) & 0xFFFFFF00;
  }
  else if ( (unsigned int)(v4 - 1) < 2 || v4 == 4 )
  {
    v5 = (v2 + 127) & 0xFFFFFF80;
    if ( !v3 )
      goto LABEL_37;
    goto LABEL_19;
  }
  if ( !v3 )
    goto LABEL_37;
LABEL_19:
  if ( (unsigned int)v4 > 0x10 )
    goto LABEL_23;
  if ( ((1 << v4) & 0x10016) != 0 )
  {
    v7 = 32;
    goto LABEL_25;
  }
  if ( v4 != 8 )
  {
LABEL_23:
    if ( v4 != 128 )
      goto LABEL_37;
  }
  v7 = 16;
LABEL_25:
  v8 = (v3 + v7 - 1) & -v7;
  if ( !v2 )
  {
LABEL_38:
    v9 = 0;
    goto LABEL_39;
  }
LABEL_26:
  v9 = 0;
  if ( v4 <= 7 )
  {
    if ( (unsigned int)(v4 - 1) < 2 || v4 == 4 )
    {
      v9 = (v2 + 127) & 0xFFFFFF80;
      if ( !v3 )
        goto LABEL_49;
      goto LABEL_40;
    }
LABEL_39:
    if ( !v3 )
      goto LABEL_49;
    goto LABEL_40;
  }
  if ( v4 == 8 )
  {
    v9 = (768 * ((v2 + 191) / 0xC0u) / 3 + 255) & 0x7FFFFF00;
    if ( !v3 )
      goto LABEL_49;
    goto LABEL_40;
  }
  if ( v4 != 16 && v4 != 128 )
    goto LABEL_39;
  v9 = (2 * v2 + 255) & 0xFFFFFF00;
  if ( !v3 )
    goto LABEL_49;
LABEL_40:
  if ( (unsigned int)v4 <= 0x10 )
  {
    if ( ((1 << v4) & 0x10114) != 0 )
    {
      v10 = 16;
LABEL_43:
      v11 = (v10 + ((unsigned int)(v3 + 1) >> 1) - 1) & -v10;
      goto LABEL_50;
    }
    if ( v4 == 1 )
    {
      v10 = 32;
      goto LABEL_43;
    }
  }
  if ( v4 == 128 )
  {
    v11 = (v3 + 15) & 0xFFFFFFF0;
    goto LABEL_50;
  }
LABEL_49:
  v11 = 0;
LABEL_50:
  if ( !v2 )
    goto LABEL_57;
  v12 = 32;
  if ( v4 != 1 && v4 != 128 )
  {
    if ( v4 == 8 )
    {
      v12 = 48;
      goto LABEL_55;
    }
LABEL_57:
    v13 = 0;
    if ( !v3 )
      goto LABEL_62;
    goto LABEL_58;
  }
LABEL_55:
  v13 = ((v2 + v12 - 1) / v12 + 63) & 0xFFFFFC0;
  if ( !v3 )
    goto LABEL_62;
LABEL_58:
  if ( v4 == 1 )
  {
    v14 = 8;
LABEL_65:
    v15 = ((v3 + v14 - 1) / v14 + 15) & 0xFFFFFFF0;
    if ( !v2 )
      goto LABEL_72;
LABEL_66:
    v16 = 16;
    if ( v4 != 1 && v4 != 128 )
    {
      if ( v4 != 8 )
        goto LABEL_72;
      v16 = 24;
    }
    v17 = ((v16 + ((unsigned int)(v2 + 1) >> 1) - 1) / v16 + 63) & 0x1FFFFFC0;
    if ( !v3 )
      goto LABEL_77;
    goto LABEL_73;
  }
  if ( v4 == 128 || v4 == 8 )
  {
    v14 = 4;
    goto LABEL_65;
  }
LABEL_62:
  v15 = 0;
  if ( v2 )
    goto LABEL_66;
LABEL_72:
  v17 = 0;
  if ( !v3 )
  {
LABEL_77:
    v20 = 0;
    goto LABEL_82;
  }
LABEL_73:
  if ( v4 == 1 )
  {
    v19 = 8;
    goto LABEL_80;
  }
  if ( v4 == 8 )
  {
    v19 = 4;
LABEL_80:
    v18 = v19 + ((unsigned int)(v3 + 1) >> 1) - 1;
    goto LABEL_81;
  }
  if ( v4 != 128 )
    goto LABEL_77;
  v18 = v3 + 3;
  v19 = 4;
LABEL_81:
  v20 = (v18 / v19 + 15) & 0xFFFFFFF0;
LABEL_82:
  v25[0] = v8 | ((_DWORD)v5 << 16);
  v25[1] = v11 | (v9 << 16);
  v25[2] = v15 | (v13 << 16);
  v25[3] = v20 | (v17 << 16);
  if ( a1 && (msm_vidc_debug & 2) != 0 )
    printk(&unk_8FC0E, "high", a1 + 85, "msm_vdec_set_ubwc_stride_scanline", v5);
  hfi_port = get_hfi_port((__int64)a1, 1u);
  result = venus_hfi_session_property(a1, 50332048, 0, hfi_port, 11, v25, 16);
  if ( a1 && (_DWORD)result && (msm_vidc_debug & 1) != 0 )
  {
    v23 = a1 + 85;
    v24 = result;
    printk(&unk_8E17E, "err ", v23, "msm_vdec_set_ubwc_stride_scanline", v22);
    result = v24;
  }
LABEL_89:
  _ReadStatusReg(SP_EL0);
  return result;
}
