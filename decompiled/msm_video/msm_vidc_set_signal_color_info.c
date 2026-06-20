__int64 __fastcall msm_vidc_set_signal_color_info(__int64 a1, unsigned int a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 result; // x0
  unsigned int v8; // w24
  int v9; // w0
  bool v10; // zf
  unsigned __int8 v12; // w22
  unsigned __int8 v13; // w21
  unsigned __int8 v14; // w0
  int v15; // w8
  int v16; // w9
  int v17; // w10
  int v18; // w11
  int v19; // w8
  int v20; // w9
  int v21; // w10
  int v22; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v23; // [xsp+8h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 >= 0xC6 )
    __break(0x5512u);
  if ( (*(_BYTE *)(a1 + 168LL * a2 + 4368) & 0x10) != 0 )
  {
    v8 = *(_DWORD *)(a1 + 168LL * a2 + 4352);
    v9 = v4l2_colorformat_to_driver(a1, *(unsigned int *)(a1 + 400), "msm_vidc_set_signal_color_info");
    if ( BYTE2(v8) )
      v10 = 0;
    else
      v10 = (unsigned __int8)v8 == 0;
    if ( v10 && BYTE1(v8) == 0 )
    {
      if ( v9 != 64 && v9 != 32 )
      {
        v17 = 0;
        v16 = 0;
        v15 = 0;
        v18 = 0;
        goto LABEL_19;
      }
      v15 = 0x10000;
      v16 = 256;
      v17 = 1;
    }
    else
    {
      v12 = v4l2_color_primaries_to_driver(a1, BYTE2(v8), "msm_vidc_set_signal_color_info");
      v13 = v4l2_matrix_coeff_to_driver(a1, (unsigned __int8)v8, "msm_vidc_set_signal_color_info");
      v14 = v4l2_transfer_char_to_driver(a1, BYTE1(v8), "msm_vidc_set_signal_color_info");
      v15 = v12 << 16;
      v16 = v14 << 8;
      v17 = v13;
    }
    v18 = 1;
LABEL_19:
    v19 = v17 | v16 | v15;
    if ( HIBYTE(v8) )
      v20 = 0x20000000;
    else
      v20 = v18 << 29;
    if ( HIBYTE(v8) )
      v21 = (HIBYTE(v8) == 1) << 25;
    else
      v21 = 0;
    v22 = v19 | v21 | (v18 << 24) | v20 | 0x14000000;
    result = ((__int64 (__fastcall *)(__int64, _QWORD, __int64, int *, __int64, const char *))msm_vidc_packetize_control)(
               a1,
               a2,
               10,
               &v22,
               4,
               "msm_vidc_set_signal_color_info");
    goto LABEL_26;
  }
  if ( a1 && (msm_vidc_debug & 2) != 0 )
    printk(&unk_91EDA, "high", a1 + 340, "msm_vidc_set_signal_color_info", a5);
  result = 0;
LABEL_26:
  _ReadStatusReg(SP_EL0);
  return result;
}
