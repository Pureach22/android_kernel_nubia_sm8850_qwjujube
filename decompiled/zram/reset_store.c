__int64 __fastcall reset_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  int v6; // w0
  __int64 v7; // x20
  __int64 v8; // x21
  __int16 v10; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+8h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = 0;
  v6 = kstrtou16(a3, 10, &v10);
  if ( v6 )
  {
    a4 = v6;
  }
  else if ( v10 )
  {
    v7 = *(_QWORD *)(*(_QWORD *)(a1 - 224) + 88LL);
    v8 = *(_QWORD *)(v7 + 24);
    mutex_lock(v8 + 360);
    if ( *(_DWORD *)(*(_QWORD *)(v8 + 64) + 64LL) || *(_BYTE *)(v7 + 233) == 1 )
    {
      mutex_unlock(v8 + 360);
      a4 = -16;
    }
    else
    {
      *(_BYTE *)(v7 + 233) = 1;
      mutex_unlock(v8 + 360);
      sync_blockdev(*(_QWORD *)(v8 + 64));
      zram_reset_device(v7);
      mutex_lock(v8 + 360);
      *(_BYTE *)(v7 + 233) = 0;
      mutex_unlock(v8 + 360);
    }
  }
  else
  {
    a4 = -22;
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
