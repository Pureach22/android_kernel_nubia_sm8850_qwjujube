__int64 __fastcall msm_vidc_set_deblock_mode(__int64 a1)
{
  int v1; // w8
  unsigned __int64 v2; // x4
  __int64 result; // x0

  _ReadStatusReg(SP_EL0);
  v1 = *(_DWORD *)(a1 + 312);
  if ( v1 == 1 )
  {
    v2 = *(_QWORD *)(a1 + 30224);
    if ( v2 < 3 )
      goto LABEL_9;
  }
  else
  {
    if ( v1 != 2 )
      goto LABEL_9;
    v2 = *(_QWORD *)(a1 + 30224);
    if ( v2 < 3 )
      goto LABEL_9;
  }
  if ( a1 && (msm_vidc_debug & 1) != 0 )
    printk(&unk_8A39B, "err ", a1 + 340, "msm_vidc_v4l2_to_hfi_enum", v2);
LABEL_9:
  result = ((__int64 (*)(void))msm_vidc_packetize_control)();
  _ReadStatusReg(SP_EL0);
  return result;
}
