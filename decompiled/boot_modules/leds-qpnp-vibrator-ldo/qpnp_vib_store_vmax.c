__int64 __fastcall qpnp_vib_store_vmax(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x20
  int v6; // w0
  int v7; // w8
  int v9; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 152);
  v9 = 0;
  v6 = kstrtoint(a3, 10, &v9);
  if ( v6 < 0 )
  {
    a4 = v6;
  }
  else
  {
    v7 = 1000 * v9;
    if ( 1000 * v9 >= 3544000 )
      v7 = 3544000;
    if ( v7 <= 1504000 )
      v7 = 1504000;
    v9 = v7;
    mutex_lock(v5 + 456);
    *(_DWORD *)(v5 + 604) = v9;
    mutex_unlock(v5 + 456);
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
