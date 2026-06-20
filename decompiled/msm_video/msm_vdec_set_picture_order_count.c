__int64 __fastcall msm_vdec_set_picture_order_count(__int64 a1, unsigned int a2)
{
  __int64 result; // x0
  unsigned int hfi_port; // w0
  __int64 v5; // x4
  unsigned int v6; // w21
  __int64 v7; // x2
  unsigned int v8; // w19
  int v9; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = 0;
  if ( a2 < 2 )
  {
    *(_DWORD *)(a1 + 56LL * a2 + 3296) = 0;
    if ( a1 && (msm_vidc_debug & 2) != 0 )
    {
      v6 = a2;
      printk(&unk_80EDA, "high", a1 + 340, "msm_vdec_set_picture_order_count", 0);
      a2 = v6;
    }
    hfi_port = get_hfi_port(a1, a2);
    result = venus_hfi_session_property(a1, 50331944, 0, hfi_port, 1, &v9, 4);
    if ( a1 && (_DWORD)result && (msm_vidc_debug & 1) != 0 )
    {
      v7 = a1 + 340;
      v8 = result;
      printk(&unk_8E17E, "err ", v7, "msm_vdec_set_picture_order_count", v5);
      result = v8;
    }
  }
  else
  {
    if ( a1 && (msm_vidc_debug & 1) != 0 )
      printk(&unk_80EB0, "err ", a1 + 340, "msm_vdec_set_picture_order_count", a2);
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
