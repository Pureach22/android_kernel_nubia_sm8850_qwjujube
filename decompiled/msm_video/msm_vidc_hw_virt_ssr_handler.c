__int64 __fastcall msm_vidc_hw_virt_ssr_handler(__int64 result)
{
  _QWORD v1[5]; // [xsp+8h] [xbp-28h] BYREF

  v1[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v1, 0, 32);
  if ( result == 6368 )
  {
    if ( (msm_vidc_debug & 1) != 0 )
      result = printk(&unk_83566, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_hw_virt_ssr_handler");
  }
  else
  {
    if ( *(_DWORD *)(result + 32) == 0x80000000 )
      *(_BYTE *)(result - 1598) = 1;
    HIDWORD(v1[0]) = 83886083;
    result = ((__int64 (__fastcall *)(__int64, _QWORD *))handle_system_error)(result - 6368, v1);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
