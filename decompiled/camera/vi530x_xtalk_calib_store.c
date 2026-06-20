__int64 __fastcall vi530x_xtalk_calib_store(__int64 a1, __int64 a2, const char *a3, __int64 a4)
{
  __int64 v4; // x20
  __int64 v7; // x8
  __int64 v8; // x8
  __int64 v9; // x0
  __int64 (__fastcall *v10)(_QWORD); // x8
  int v11; // w1
  int v12; // w2
  int v13; // w21
  __int64 v14; // x23
  __int64 v16; // x8
  __int64 v17; // x8
  __int64 v18; // x0
  int v20; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v21; // [xsp+8h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 152);
  v20 = 0;
  if ( !v4 )
    goto LABEL_22;
  mutex_lock(v4 + 264);
  if ( sscanf(a3, "%u\n", &v20) != 1 )
  {
    mutex_unlock(v4 + 264);
LABEL_22:
    a4 = -1;
    goto LABEL_23;
  }
  if ( v20 == 1 )
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
    xtalk_mark = 1;
    v10 = *(__int64 (__fastcall **)(_QWORD))(vi530x_func_tbl + 72);
    if ( *((_DWORD *)v10 - 1) != 1318018478 )
      __break(0x8228u);
    v13 = v10(v4);
    v14 = -600;
    do
      _const_udelay("d: %u rc: %d", v11, v12);
    while ( !__CFADD__(v14++, 1) );
    v16 = *(_QWORD *)(v4 + 96);
    xtalk_mark = 0;
    if ( v16 )
    {
      v17 = *(_QWORD *)(v16 + 24);
      if ( v17 )
      {
        if ( *(_BYTE *)(v4 + 312) == 1 )
        {
          v18 = *(_QWORD *)(v17 + 208);
          --tof_i2c_open_count;
          _pm_runtime_idle(v18, 4);
        }
      }
    }
    mutex_unlock(v4 + 264);
    if ( v13 )
      a4 = -1;
  }
  else
  {
    printk(&unk_4004F4);
    mutex_unlock(v4 + 264);
  }
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return a4;
}
