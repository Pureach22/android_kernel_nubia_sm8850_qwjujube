__int64 __fastcall fw_dump_set(__int64 a1, __int64 a2)
{
  __int64 result; // x0

  _ReadStatusReg(SP_EL0);
  if ( a2 && a1 && *(_QWORD *)(a2 + 32) )
  {
    result = kstrtouint();
    if ( !(_DWORD)result )
    {
      msm_vidc_fw_dump = 0;
      if ( (msm_vidc_debug & 2) != 0 )
        printk(&unk_8749E, "high", 0xFFFFFFFFLL, "codec", "Disabled");
      result = 0;
    }
  }
  else
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_80408, "err ", 0xFFFFFFFFLL, "codec", "fw_dump_set");
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
