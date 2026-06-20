__int64 __fastcall msm_vdec_set_bit_depth(__int64 a1, unsigned int a2)
{
  unsigned int v4; // w21
  __int64 result; // x0
  int v6; // w0
  unsigned int hfi_port; // w0
  __int64 v8; // x4
  __int64 v9; // x2
  unsigned int v10; // w19
  int v11; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v12; // [xsp+8h] [xbp-8h]

  v4 = 524296;
  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = 524296;
  if ( a2 >= 2 )
  {
    if ( a1 && (msm_vidc_debug & 1) != 0 )
      printk(&unk_80EB0, "err ", a1 + 340, "msm_vdec_set_bit_depth", a2);
    result = 4294967274LL;
    goto LABEL_20;
  }
  v6 = v4l2_colorformat_to_driver(a1, *(unsigned int *)(a1 + 608), "msm_vdec_set_bit_depth");
  if ( v6 > 127 )
  {
    if ( v6 != 256 && v6 != 128 )
      goto LABEL_13;
  }
  else if ( v6 != 8 && v6 != 16 )
  {
    goto LABEL_13;
  }
  v4 = 655370;
  v11 = 655370;
LABEL_13:
  *(_DWORD *)(a1 + 56LL * a2 + 3284) = v4;
  ((void (__fastcall *)(__int64, __int64, _QWORD, const char *))msm_vidc_update_cap_value)(
    a1,
    165,
    v4,
    "msm_vdec_set_bit_depth");
  if ( a1 && (msm_vidc_debug & 2) != 0 )
    printk(&unk_8E1B1, "high", a1 + 340, "msm_vdec_set_bit_depth", v4);
  hfi_port = get_hfi_port(a1, a2);
  result = venus_hfi_session_property(a1, 50331919, 0, hfi_port, 1, &v11, 4);
  if ( a1 && (_DWORD)result && (msm_vidc_debug & 1) != 0 )
  {
    v9 = a1 + 340;
    v10 = result;
    printk(&unk_8E17E, "err ", v9, "msm_vdec_set_bit_depth", v8);
    result = v10;
  }
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return result;
}
