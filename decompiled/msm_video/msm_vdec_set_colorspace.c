__int64 __fastcall msm_vdec_set_colorspace(__int64 a1, unsigned int a2)
{
  __int64 result; // x0
  unsigned int v4; // w23
  __int64 v5; // x24
  unsigned int v6; // w8
  int v7; // w9
  unsigned int v8; // w25
  unsigned __int8 v9; // w21
  unsigned __int8 v10; // w22
  unsigned __int8 v11; // w0
  int v12; // w8
  int v13; // w8
  int v14; // w9
  int v15; // w8
  __int64 v16; // x4
  unsigned int hfi_port; // w0
  __int64 v18; // x4
  unsigned int v19; // w21
  __int64 v20; // x2
  unsigned int v21; // w19
  int v22; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v23; // [xsp+8h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 < 2 )
  {
    if ( *(_DWORD *)(a1 + 312) == 4 )
    {
      result = 0;
    }
    else
    {
      v4 = a2;
      v5 = a1 + 208LL * a2;
      v6 = *(_DWORD *)(v5 + 408);
      if ( v6 || *(_BYTE *)(v5 + 574) || (v7 = *(unsigned __int8 *)(v5 + 576), *(_BYTE *)(v5 + 576)) )
      {
        v8 = a2;
        v9 = v4l2_color_primaries_to_driver(a1, v6, "msm_vdec_set_colorspace");
        v10 = v4l2_matrix_coeff_to_driver(a1, *(unsigned __int8 *)(v5 + 574), "msm_vdec_set_colorspace");
        v11 = v4l2_transfer_char_to_driver(a1, *(unsigned __int8 *)(v5 + 576), "msm_vdec_set_colorspace");
        a2 = v8;
        v7 = 1;
        v12 = v10 | (v9 << 16) | (v11 << 8);
      }
      else
      {
        v12 = 3;
      }
      v13 = v12 | (v7 << 24);
      v14 = (v7 << 29) | 0x14000000;
      v15 = v13 | ((*(_BYTE *)(v5 + 575) == 1) << 25);
      if ( *(_BYTE *)(v5 + 575) )
        v14 = 872415232;
      v16 = v14 | (unsigned int)v15;
      v22 = v16;
      *(_DWORD *)(a1 + 56LL * v4 + 3300) = v16;
      if ( a1 && (msm_vidc_debug & 2) != 0 )
      {
        v19 = a2;
        printk(&unk_84C02, "high", a1 + 340, "msm_vdec_set_colorspace", v16);
        a2 = v19;
      }
      hfi_port = get_hfi_port(a1, a2);
      result = venus_hfi_session_property(a1, 50331989, 0, hfi_port, 10, &v22, 4);
      if ( a1 && (_DWORD)result && (msm_vidc_debug & 1) != 0 )
      {
        v20 = a1 + 340;
        v21 = result;
        printk(&unk_8E17E, "err ", v20, "msm_vdec_set_colorspace", v18);
        result = v21;
      }
    }
  }
  else
  {
    if ( a1 && (msm_vidc_debug & 1) != 0 )
      printk(&unk_80EB0, "err ", a1 + 340, "msm_vdec_set_colorspace", a2);
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
