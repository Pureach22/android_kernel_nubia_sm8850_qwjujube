__int64 __fastcall cont_drv_time_store(__int64 a1, int a2, char *s, __int64 a4)
{
  __int64 v5; // x21
  char v6; // w8
  char v7; // w9
  _BYTE v9[4]; // [xsp+Ch] [xbp-14h] BYREF
  __int64 v10; // [xsp+10h] [xbp-10h] BYREF
  __int64 v11; // [xsp+18h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 152);
  v10 = 0;
  if ( sscanf(s, "%x %x", &v10, (char *)&v10 + 4) == 2 )
  {
    v6 = v10;
    *(_BYTE *)(v5 + 1016) = v10;
    v7 = BYTE4(v10);
    *(_BYTE *)(v5 + 1017) = BYTE4(v10);
    v9[0] = v6;
    v9[1] = v7;
    mutex_lock(v5 + 584);
    i2c_w_bytes(v5 - 168, 31, v9, 2);
    mutex_unlock(v5 + 584);
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
