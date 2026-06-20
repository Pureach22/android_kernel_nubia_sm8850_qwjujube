__int64 __fastcall core_reg_num_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v6; // x21
  _DWORD *v7; // x8
  unsigned int v8; // w22
  int v9; // w23
  int updated; // w0
  int v11; // w21
  unsigned int v13; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v14; // [xsp+8h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 152);
  v13 = 0;
  if ( (unsigned int)kstrtouint(a3, 16, &v13) )
  {
    a4 = -22;
  }
  else
  {
    mutex_lock(v6);
    v7 = *(_DWORD **)(v6 + 56);
    if ( v7[4] || v7[6] )
    {
      dev_err(a1, "Couldn't set core_reg_num, register available in list\n");
      mutex_unlock(v6);
      a4 = -1;
    }
    else
    {
      v8 = v13;
      v9 = v7[3];
      mutex_unlock(v6);
      if ( v8 != v9 )
      {
        updated = update_reg_dump_table(a1, v13);
        if ( updated )
        {
          v11 = updated;
          dev_err(a1, "Couldn't set core_reg_num, no enough memory\n");
          a4 = v11;
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
