__int64 __fastcall wcd_usbss_standby_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  int v5; // w9
  __int64 v6; // x8
  _BOOL8 v7; // x0
  int v9; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = 0;
  if ( (kstrtouint(a3, 10, &v9) & 0x80000000) != 0 )
  {
    a4 = -22;
  }
  else
  {
    v5 = v9;
    v6 = wcd_usbss_ctxt_;
    *(_BYTE *)(wcd_usbss_ctxt_ + 400) = 1;
    if ( v5 )
      v7 = *(_DWORD *)(v6 + 368) == 0;
    else
      v7 = 0;
    wcd_usbss_standby_control(v7);
    *(_BYTE *)(wcd_usbss_ctxt_ + 400) = v9 != 0;
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
