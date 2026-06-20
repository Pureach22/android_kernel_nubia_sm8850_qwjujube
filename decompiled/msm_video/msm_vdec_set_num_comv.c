__int64 __fastcall msm_vdec_set_num_comv(__int64 a1)
{
  __int64 v2; // x4
  unsigned int hfi_port; // w0
  __int64 result; // x0
  __int64 v5; // x4
  __int64 v6; // x2
  unsigned int v7; // w19
  int v8; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(unsigned int *)(a1 + 36272);
  v8 = *(_DWORD *)(a1 + 36272);
  if ( a1 && (msm_vidc_debug & 2) != 0 )
    printk(&unk_920FF, "high", a1 + 340, "msm_vdec_set_num_comv", v2);
  hfi_port = get_hfi_port(a1, 0);
  result = venus_hfi_session_property(a1, 50332051, 0, hfi_port, 1, &v8, 4);
  if ( a1 && (_DWORD)result && (msm_vidc_debug & 1) != 0 )
  {
    v6 = a1 + 340;
    v7 = result;
    printk(&unk_8E17E, "err ", v6, "msm_vdec_set_num_comv", v5);
    result = v7;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
