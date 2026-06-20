__int64 __fastcall msm_venc_set_colorformat(__int64 a1, unsigned int a2)
{
  __int64 result; // x0
  unsigned int v4; // w20
  unsigned int v5; // w0
  unsigned int hfi_colorformat; // w0
  unsigned int hfi_port; // w0
  __int64 v8; // x0
  unsigned int v9; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 )
  {
    if ( a1 && (msm_vidc_debug & 1) != 0 )
      printk(&unk_80EB0, "err ", a1 + 340, "msm_venc_set_colorformat", a2);
LABEL_5:
    result = 4294967274LL;
    goto LABEL_11;
  }
  v4 = *(_DWORD *)(a1 + 400);
  v5 = v4l2_colorformat_to_driver(a1, v4, "msm_venc_set_colorformat");
  if ( (*(_QWORD *)(a1 + 18120) & v5) == 0 )
  {
    if ( a1 && (msm_vidc_debug & 1) != 0 )
    {
      v8 = v4l2_pixelfmt_name(a1, v4);
      printk(&unk_8815D, "err ", a1 + 340, "msm_venc_set_colorformat", v8);
    }
    goto LABEL_5;
  }
  hfi_colorformat = get_hfi_colorformat(a1, v5);
  v9 = hfi_colorformat;
  if ( a1 && (msm_vidc_debug & 2) != 0 )
    printk(&unk_8C903, "high", a1 + 340, "msm_venc_set_colorformat", hfi_colorformat);
  hfi_port = get_hfi_port(a1, 0);
  result = venus_hfi_session_property(a1, 50331905, 0, hfi_port, 9, &v9, 4);
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
