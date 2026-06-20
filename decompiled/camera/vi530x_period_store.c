__int64 __fastcall vi530x_period_store(__int64 a1, __int64 a2, const char *a3, __int64 a4)
{
  __int64 v4; // x20
  __int64 v7; // x8
  __int64 v8; // x8
  __int64 v9; // x0
  __int64 v10; // x8
  void (__fastcall *v11)(_QWORD); // x8
  __int64 v12; // x8
  __int64 v13; // x8
  __int64 v14; // x0
  int v16; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v17; // [xsp+8h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 152);
  v16 = 0;
  if ( v4 )
  {
    mutex_lock(v4 + 264);
    if ( sscanf(a3, "%u\n", &v16) == 1 )
    {
      v7 = *(_QWORD *)(v4 + 96);
      if ( v7 )
      {
        v8 = *(_QWORD *)(v7 + 24);
        if ( v8 )
        {
          if ( *(_BYTE *)(v4 + 312) == 1 )
          {
            v9 = *(_QWORD *)(v8 + 208);
            ++tof_i2c_open_count;
            if ( (_pm_runtime_resume(v9, 4) & 0x80000000) != 0 )
              printk(&unk_3CC265);
          }
        }
      }
      v10 = vi530x_func_tbl;
      *(_DWORD *)(v4 + 252) = v16;
      v11 = *(void (__fastcall **)(_QWORD))(v10 + 16);
      if ( *((_DWORD *)v11 - 1) != 2100012607 )
        __break(0x8228u);
      v11(v4);
      v12 = *(_QWORD *)(v4 + 96);
      if ( v12 )
      {
        v13 = *(_QWORD *)(v12 + 24);
        if ( v13 )
        {
          if ( *(_BYTE *)(v4 + 312) == 1 )
          {
            v14 = *(_QWORD *)(v13 + 208);
            --tof_i2c_open_count;
            _pm_runtime_idle(v14, 4);
          }
        }
      }
    }
    else
    {
      a4 = -22;
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
