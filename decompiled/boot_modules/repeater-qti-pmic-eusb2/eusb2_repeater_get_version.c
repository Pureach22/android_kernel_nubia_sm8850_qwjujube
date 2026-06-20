__int64 __fastcall eusb2_repeater_get_version(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x1
  int v4; // w0
  _BYTE v6[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v7; // [xsp+8h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 88);
  v3 = *(unsigned __int16 *)(a1 + 96);
  v6[0] = 0;
  v4 = regmap_bulk_read(v2, v3, v6, 1);
  if ( v4 )
    dev_err(*(_QWORD *)a1, "read failed: addr=0x%04x, ret=%d\n", *(unsigned __int16 *)(a1 + 96), v4);
  _ReadStatusReg(SP_EL0);
  return v6[0];
}
