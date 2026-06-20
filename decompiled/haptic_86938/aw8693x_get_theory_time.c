__int64 __fastcall aw8693x_get_theory_time(__int64 a1)
{
  int v2; // w8
  unsigned int v3; // w8
  __int64 v4; // x20
  _BYTE v6[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v7; // [xsp+8h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6[0] = 0;
  i2c_r_bytes(a1, 70, v6, 1);
  v2 = v6[0] & 0x60;
  if ( v2 == 64 )
  {
    v3 = 12;
  }
  else if ( v2 == 32 )
  {
    v3 = 48;
  }
  else
  {
    if ( (v6[0] & 0x60) != 0 )
    {
      v4 = 0;
      goto LABEL_9;
    }
    v3 = 24;
  }
  v4 = 1000 * *(_DWORD *)(a1 + 120) / v3;
LABEL_9:
  printk(&unk_16A21, "haptic_hv", 1696, "aw8693x_get_theory_time");
  _ReadStatusReg(SP_EL0);
  return v4;
}
