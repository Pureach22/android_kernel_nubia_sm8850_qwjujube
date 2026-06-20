__int64 __fastcall msm_vdec_set_profile(__int64 a1, unsigned int a2)
{
  __int64 result; // x0
  __int64 v4; // x4
  unsigned int hfi_port; // w0
  __int64 v6; // x4
  unsigned int v7; // w21
  __int64 v8; // x2
  unsigned int v9; // w19
  int v10; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+8h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 < 2 )
  {
    v4 = *(unsigned int *)(a1 + 15104);
    v10 = v4;
    *(_DWORD *)(a1 + 56LL * a2 + 3304) = v4;
    if ( a1 && (msm_vidc_debug & 2) != 0 )
    {
      v7 = a2;
      printk(&unk_802E7, "high", a1 + 340, "msm_vdec_set_profile", v4);
      a2 = v7;
    }
    hfi_port = get_hfi_port(a1, a2);
    result = venus_hfi_session_property(a1, 50331911, 0, hfi_port, 9, &v10, 4);
    if ( a1 && (_DWORD)result && (msm_vidc_debug & 1) != 0 )
    {
      v8 = a1 + 340;
      v9 = result;
      printk(&unk_8E17E, "err ", v8, "msm_vdec_set_profile", v6);
      result = v9;
    }
  }
  else
  {
    if ( a1 && (msm_vidc_debug & 1) != 0 )
      printk(&unk_80EB0, "err ", a1 + 340, "msm_vdec_set_profile", a2);
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
