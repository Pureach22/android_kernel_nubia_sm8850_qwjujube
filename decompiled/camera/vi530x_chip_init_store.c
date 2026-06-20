__int64 __fastcall vi530x_chip_init_store(__int64 a1, __int64 a2, const char *a3, __int64 a4)
{
  __int64 v4; // x21
  int v8; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 152);
  v8 = 0;
  if ( v4 )
  {
    mutex_lock(v4 + 264);
    if ( sscanf(a3, "%u\n", &v8) == 1 )
    {
      if ( v8 )
        printk(&unk_43E6BB);
      else
        a4 = -22;
    }
    else
    {
      a4 = -1;
    }
    mutex_unlock(v4 + 264);
  }
  else
  {
    a4 = -1;
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
