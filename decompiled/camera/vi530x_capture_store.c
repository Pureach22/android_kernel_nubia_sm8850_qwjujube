__int64 __fastcall vi530x_capture_store(__int64 a1, __int64 a2, const char *a3, __int64 a4)
{
  __int64 v4; // x20
  __int64 (__fastcall *v7)(_QWORD); // x8
  int v8; // w21
  __int64 (__fastcall *v9)(_QWORD); // x8
  unsigned int v11; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v12; // [xsp+8h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 152);
  v11 = 0;
  if ( v4 )
  {
    mutex_lock(v4 + 264);
    if ( sscanf(a3, "%u\n", &v11) == 1 )
    {
      if ( v11 >= 2 )
      {
        printk(&unk_42317A);
        mutex_unlock(v4 + 264);
      }
      else
      {
        if ( v11 == 1 )
        {
          if ( (tof_flag & 1) == 0 )
            tof_flag = 1;
          v7 = *(__int64 (__fastcall **)(_QWORD))(vi530x_func_tbl + 32);
          if ( *((_DWORD *)v7 - 1) != 1318018478 )
            __break(0x8228u);
          v8 = v7(v4);
        }
        else
        {
          v9 = *(__int64 (__fastcall **)(_QWORD))(vi530x_func_tbl + 40);
          if ( *((_DWORD *)v9 - 1) != 1318018478 )
            __break(0x8228u);
          v8 = v9(v4);
          tof_flag = 0;
        }
        mutex_unlock(v4 + 264);
        if ( v8 )
          a4 = -1;
      }
    }
    else
    {
      mutex_unlock(v4 + 264);
      a4 = -1;
    }
  }
  else
  {
    a4 = -1;
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
