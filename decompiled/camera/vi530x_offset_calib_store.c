__int64 __fastcall vi530x_offset_calib_store(__int64 a1, __int64 a2, const char *a3, __int64 a4)
{
  __int64 v4; // x20
  __int64 v7; // x8
  __int64 v8; // x8
  __int64 v9; // x0
  __int64 v10; // x9
  __int64 (__fastcall *v11)(_QWORD); // x9
  int v12; // w0
  __int64 v13; // x8
  int v14; // w21
  __int64 v15; // x8
  __int64 v16; // x0
  int v18; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v19; // [xsp+8h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 152);
  v18 = 0;
  if ( !v4 )
    goto LABEL_19;
  mutex_lock(v4 + 264);
  if ( sscanf(a3, "%d\n", &v18) != 1 )
  {
    mutex_unlock(v4 + 264);
LABEL_19:
    a4 = -1;
    goto LABEL_20;
  }
  if ( v18 <= 0 )
  {
    printk(&unk_4231A0);
    mutex_unlock(v4 + 264);
  }
  else
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
    *(_WORD *)(v4 + 44) = v18;
    v11 = *(__int64 (__fastcall **)(_QWORD))(v10 + 80);
    offset_mark = 1;
    if ( *((_DWORD *)v11 - 1) != 1318018478 )
      __break(0x8229u);
    v12 = v11(v4);
    v13 = *(_QWORD *)(v4 + 96);
    v14 = v12;
    offset_mark = 0;
    if ( v13 )
    {
      v15 = *(_QWORD *)(v13 + 24);
      if ( v15 )
      {
        if ( *(_BYTE *)(v4 + 312) == 1 )
        {
          v16 = *(_QWORD *)(v15 + 208);
          --tof_i2c_open_count;
          _pm_runtime_idle(v16, 4);
        }
      }
    }
    mutex_unlock(v4 + 264);
    if ( v14 )
      a4 = -1;
  }
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return a4;
}
