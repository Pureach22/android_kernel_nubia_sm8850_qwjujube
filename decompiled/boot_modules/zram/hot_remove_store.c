__int64 __fastcall hot_remove_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  int v5; // w0
  int v6; // w20
  int v8; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = 0;
  v5 = kstrtoint(a3, 10, &v8);
  if ( !v5 )
  {
    if ( v8 < 0 )
    {
      a4 = -22;
      goto LABEL_10;
    }
    mutex_lock(&zram_index_mutex);
    if ( idr_find(&zram_index_idr, v8) )
    {
      v6 = zram_remove();
      if ( !v6 )
      {
        idr_remove(&zram_index_idr, v8);
        mutex_unlock(&zram_index_mutex);
        goto LABEL_10;
      }
    }
    else
    {
      v6 = -19;
    }
    mutex_unlock(&zram_index_mutex);
    a4 = v6;
    goto LABEL_10;
  }
  a4 = v5;
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return a4;
}
