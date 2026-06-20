__int64 __fastcall wcd_usbss_surge_period_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x8
  __int64 v6; // x0
  int v8; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = 0;
  if ( (kstrtouint(a3, 10, &v8) & 0x80000000) != 0 )
  {
    a4 = -22;
  }
  else
  {
    v5 = wcd_usbss_ctxt_;
    if ( (unsigned int)(v8 - 3) <= 0x11 )
      *(_DWORD *)(wcd_usbss_ctxt_ + 392) = 1000 * v8;
    v6 = *(_QWORD *)(v5 + 384);
    if ( v6 && *(_DWORD *)(v5 + 368) && *(_BYTE *)(v5 + 372) == 1 )
      wake_up_process(v6);
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
