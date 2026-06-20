__int64 __fastcall aw8693x_rtp_get_fifo_afi(__int64 a1)
{
  int v2; // w8
  _BYTE v4[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v5; // [xsp+8h] [xbp-8h]

  v5 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(unsigned __int8 *)(a1 + 17);
  v4[0] = 0;
  if ( v2 == 1 )
    *(_WORD *)(*(_QWORD *)(a1 + 808) + 2LL) = 91;
  i2c_r_bytes(a1, 2, v4, 1);
  if ( *(_BYTE *)(a1 + 17) == 1 )
    *(_WORD *)(*(_QWORD *)(a1 + 808) + 2LL) = 0;
  _ReadStatusReg(SP_EL0);
  return (v4[0] >> 3) & 1;
}
