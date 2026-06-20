__int64 __fastcall set_usb_online_fn(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x20
  _BOOL4 v7; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v8; // [xsp+8h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 152);
  v7 = 0;
  if ( (kstrtoint(a3, 10, &v7) & 0x80000000) != 0 )
  {
    a4 = -22;
  }
  else
  {
    v7 = v7;
    printk(&unk_18326);
    *(_BYTE *)(v5 + 746) = v7;
    dwc3_ext_event_notify(v5);
    forge_usb_offline = !v7;
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
