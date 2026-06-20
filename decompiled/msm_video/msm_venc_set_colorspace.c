__int64 __fastcall msm_venc_set_colorspace(__int64 a1, unsigned int a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 result; // x0
  int v7; // w0
  __int64 v8; // x1
  unsigned __int8 v9; // w21
  unsigned __int8 v10; // w22
  unsigned __int8 v11; // w0
  int v12; // w8
  int v13; // w9
  int v14; // w11
  int v15; // w10
  int v16; // w8
  int v17; // w9
  int v18; // w8
  int v19; // w9
  unsigned int hfi_port; // w0
  int v21; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v22; // [xsp+8h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 )
  {
    if ( a1 && (msm_vidc_debug & 1) != 0 )
      printk(&unk_80EB0, "err ", a1 + 340, "msm_venc_set_colorspace", a2);
    result = 4294967274LL;
    goto LABEL_22;
  }
  if ( (*(_BYTE *)(a1 + 36456) & 0x10) == 0 )
  {
    v7 = v4l2_colorformat_to_driver(a1, *(unsigned int *)(a1 + 400), "msm_venc_set_colorspace");
    v8 = *(unsigned int *)(a1 + 408);
    if ( (_DWORD)v8 || *(_BYTE *)(a1 + 574) || *(_BYTE *)(a1 + 576) )
    {
      v9 = v4l2_color_primaries_to_driver(a1, v8, "msm_venc_set_colorspace");
      v10 = v4l2_matrix_coeff_to_driver(a1, *(unsigned __int8 *)(a1 + 574), "msm_venc_set_colorspace");
      v11 = v4l2_transfer_char_to_driver(a1, *(unsigned __int8 *)(a1 + 576), "msm_venc_set_colorspace");
      v12 = v9 << 16;
      v13 = v11 << 8;
      v14 = v10;
    }
    else
    {
      if ( v7 != 64 && v7 != 32 )
      {
        v13 = 0;
        v15 = 0;
        v12 = 0;
        v14 = 3;
        goto LABEL_12;
      }
      v12 = 0x10000;
      v13 = 256;
      v14 = 1;
    }
    v15 = 1;
LABEL_12:
    v16 = v13 | v14 | v12;
    v17 = v15 << 29;
    v18 = v16 | (v15 << 24) | ((*(_BYTE *)(a1 + 575) == 1) << 25);
    if ( *(_BYTE *)(a1 + 575) )
      v17 = 0x20000000;
    v19 = v17 | 0x14000000;
    v21 = v18 | v19;
    if ( a1 && (msm_vidc_debug & 2) != 0 )
      printk(&unk_84C02, "high", a1 + 340, "msm_venc_set_colorspace", v18 | (unsigned int)v19);
    hfi_port = get_hfi_port(a1, 0);
    result = venus_hfi_session_property(a1, 50331989, 0, hfi_port, 10, &v21, 4);
    goto LABEL_22;
  }
  if ( a1 && (msm_vidc_debug & 2) != 0 )
    printk(&unk_80F30, "high", a1 + 340, "msm_venc_set_colorspace", a5);
  result = 0;
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return result;
}
