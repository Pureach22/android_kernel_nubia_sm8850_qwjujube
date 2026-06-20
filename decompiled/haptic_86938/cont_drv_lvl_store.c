__int64 __fastcall cont_drv_lvl_store(__int64 a1, int a2, char *s, __int64 a4)
{
  __int64 v5; // x21
  _WORD v7[2]; // [xsp+Ch] [xbp-14h] BYREF
  __int64 v8; // [xsp+10h] [xbp-10h] BYREF
  __int64 v9; // [xsp+18h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 152);
  v8 = 0;
  v7[0] = 0;
  if ( sscanf(s, "%x %x", &v8, (char *)&v8 + 4) == 2 )
  {
    *(_BYTE *)(v5 + 1010) = v8;
    *(_BYTE *)(v5 + 1011) = BYTE4(v8);
    mutex_lock(v5 + 584);
    i2c_r_bytes(v5 - 168, 29, v7, 1);
    LOBYTE(v7[0]) = *(_BYTE *)(v5 + 1010) | v7[0] & 0x80;
    HIBYTE(v7[0]) = *(_BYTE *)(v5 + 1011);
    i2c_w_bytes(v5 - 168, 29, v7, 2);
    mutex_unlock(v5 + 584);
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
