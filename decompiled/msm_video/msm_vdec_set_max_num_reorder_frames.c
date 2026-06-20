__int64 __fastcall msm_vdec_set_max_num_reorder_frames(__int64 a1, unsigned int a2)
{
  __int64 result; // x0
  __int64 v4; // x8
  __int64 v5; // x4
  unsigned int hfi_port; // w0
  __int64 v7; // x4
  unsigned int v8; // w21
  __int64 v9; // x2
  unsigned int v10; // w19
  int v11; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v12; // [xsp+8h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 < 2 )
  {
    v4 = a1 + 56LL * a2;
    v5 = *(unsigned int *)(v4 + 3324);
    v11 = *(_DWORD *)(v4 + 3324);
    if ( a1 && (msm_vidc_debug & 2) != 0 )
    {
      v8 = a2;
      printk(&unk_8E1D9, "high", a1 + 340, "msm_vdec_set_max_num_reorder_frames", v5);
      a2 = v8;
    }
    hfi_port = get_hfi_port(a1, a2);
    result = venus_hfi_session_property(a1, 50331943, 0, hfi_port, 1, &v11, 4);
    if ( a1 && (_DWORD)result && (msm_vidc_debug & 1) != 0 )
    {
      v9 = a1 + 340;
      v10 = result;
      printk(&unk_8E17E, "err ", v9, "msm_vdec_set_max_num_reorder_frames", v7);
      result = v10;
    }
  }
  else
  {
    if ( a1 && (msm_vidc_debug & 1) != 0 )
      printk(&unk_80EB0, "err ", a1 + 340, "msm_vdec_set_max_num_reorder_frames", a2);
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
