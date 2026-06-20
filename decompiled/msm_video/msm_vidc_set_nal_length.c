__int64 __fastcall msm_vidc_set_nal_length(__int64 a1, __int64 a2)
{
  __int64 v2; // x4
  __int64 result; // x0
  __int64 v4; // x19
  unsigned int v5; // w20
  int v6; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v7; // [xsp+8h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_QWORD *)(a1 + 23840) )
  {
    v2 = *(_QWORD *)(a1 + 24008);
    if ( v2 == 3 )
    {
      v6 = 4;
    }
    else
    {
      v6 = 0;
      if ( a1 && (msm_vidc_debug & 1) != 0 )
      {
        v4 = a1;
        v5 = a2;
        printk(&unk_8A39B, "err ", a1 + 340, "msm_vidc_v4l2_to_hfi_enum", v2);
        a2 = v5;
        a1 = v4;
      }
    }
  }
  else
  {
    v6 = 0;
  }
  result = ((__int64 (__fastcall *)(__int64, __int64, __int64, int *, __int64, const char *))msm_vidc_packetize_control)(
             a1,
             a2,
             9,
             &v6,
             4,
             "msm_vidc_set_nal_length");
  _ReadStatusReg(SP_EL0);
  return result;
}
