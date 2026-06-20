__int64 __fastcall hfi_kms_populate_catalog(__int64 a1, int a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 result; // x0
  unsigned int v13; // w9

  if ( a5 == 160 )
    return printk(&unk_2348DE, "hfi_kms_populate_catalog");
  result = *(_QWORD *)(a5 + 24);
  if ( !result )
    return printk(&unk_245D56, "hfi_kms_populate_catalog");
  if ( (unsigned int)(a2 - 16777219) >= 9 )
  {
    if ( a2 == 16777218 )
    {
      result = ((__int64 (*)(void))hfi_kms_init_device_caps)();
      _X8 = (unsigned int *)(a5 + 16);
      __asm { PRFM            #0x11, [X8] }
      do
        v13 = __ldxr(_X8);
      while ( __stxr(v13 + 1, _X8) );
    }
    else if ( a2 == 16777217 )
    {
      return ((__int64 (*)(void))hfi_kms_init_device_caps)();
    }
    else
    {
      return printk(&unk_211F63, "hfi_kms_populate_catalog");
    }
  }
  return result;
}
