__int64 __fastcall debug_level_set_fw(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  _QWORD *v4; // x8
  char v5; // w10

  _ReadStatusReg(SP_EL0);
  if ( a2 && a1 && *(_QWORD *)(a2 + 32) )
  {
    result = kstrtouint();
    if ( !(_DWORD)result )
    {
      v4 = **(_QWORD ***)(a2 + 32);
      msm_fw_debug = 0;
      if ( v4 )
      {
        v5 = msm_vidc_debug;
        v4[544] = 1000;
        v4[538] = 1500;
        v4[542] = 3000;
        if ( (v5 & 2) != 0 )
          printk(&unk_8CA3C, "high", 0xFFFFFFFFLL, "codec", 1000);
      }
      else if ( (msm_vidc_debug & 1) != 0 )
      {
        printk(&unk_8835E, "err ", 0xFFFFFFFFLL, "codec", "debug_level_set_fw");
      }
      result = 0;
    }
  }
  else
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_80408, "err ", 0xFFFFFFFFLL, "codec", "debug_level_set_fw");
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
