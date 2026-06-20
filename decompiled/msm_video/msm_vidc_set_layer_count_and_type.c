__int64 __fastcall msm_vidc_set_layer_count_and_type(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  unsigned int v5; // w8

  _ReadStatusReg(SP_EL0);
  if ( (*(_WORD *)(*(_QWORD *)(a1 + 1848) + 320LL) & 1) != 0 )
  {
    if ( *(_DWORD *)(a1 + 1832) != 3 )
    {
LABEL_9:
      v5 = ((__int64 (*)(void))msm_vidc_packetize_control)();
      goto LABEL_10;
    }
    if ( a1 && (msm_vidc_debug & 4) != 0 )
      printk(&unk_86F78, "low ", a1 + 340, "msm_vidc_set_layer_count_and_type", a5);
    v5 = 0;
  }
  else
  {
    v5 = ((__int64 (__fastcall *)(__int64, __int64))msm_vidc_packetize_control)(a1, 139);
    if ( !v5 )
      goto LABEL_9;
  }
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return v5;
}
