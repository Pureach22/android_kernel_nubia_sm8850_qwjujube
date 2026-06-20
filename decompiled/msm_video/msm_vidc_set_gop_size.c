__int64 __fastcall msm_vidc_set_gop_size(__int64 result, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  int v5; // [xsp+4h] [xbp-Ch]
  __int64 v6; // [xsp+8h] [xbp-8h]

  v6 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (*(_WORD *)(*(_QWORD *)(result + 1848) + 320LL) & 1) != 0 && *(_DWORD *)(result + 1832) == 3 )
  {
    if ( result )
    {
      if ( (msm_vidc_debug & 4) != 0 )
        printk(&unk_86FB8, "low ", result + 340, "msm_vidc_set_gop_size", a5);
      result = 0;
    }
  }
  else
  {
    v5 = *(_QWORD *)(result + 15776);
    result = ((__int64 (*)(void))msm_vidc_packetize_control)();
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
