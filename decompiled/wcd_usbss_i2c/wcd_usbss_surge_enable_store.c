__int64 __fastcall wcd_usbss_surge_enable_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x8
  int v7; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v8; // [xsp+8h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = 0;
  if ( (kstrtouint(a3, 10, &v7) & 0x80000000) != 0 )
  {
    a4 = -22;
  }
  else
  {
    v5 = wcd_usbss_ctxt_;
    if ( !*(_DWORD *)(wcd_usbss_ctxt_ + 392) )
      *(_DWORD *)(wcd_usbss_ctxt_ + 392) = 15000;
    *(_BYTE *)(v5 + 372) = v7 != 0;
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
