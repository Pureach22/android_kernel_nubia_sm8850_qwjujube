__int64 __fastcall vi530x_xtalk_data_write(__int64 a1, __int64 a2, __int64 a3, _BYTE *a4, __int64 a5, __int64 a6)
{
  __int64 v6; // x19
  __int64 v9; // x8
  __int64 v10; // x8
  __int64 v11; // x0
  __int64 v12; // x20
  __int64 v13; // x9
  __int64 (__fastcall *v14)(_QWORD); // x8
  int v15; // w0
  __int64 v16; // x8
  __int64 v17; // x8
  __int64 v18; // x0
  __int64 v19; // x8
  __int64 v20; // x8
  __int64 v21; // x0

  v6 = *(_QWORD *)(a2 + 152);
  mutex_lock(v6 + 264);
  if ( (tof_enable & 1) == 0 )
  {
    printk(&unk_407C64);
    v12 = -16;
    goto LABEL_30;
  }
  if ( a6 != 2 )
  {
    printk(&unk_40BE04);
    v12 = -22;
    goto LABEL_30;
  }
  if ( *(_DWORD *)(v6 + 228) )
  {
    printk(&unk_427370);
    printk(&unk_3DC147);
    if ( v6 )
      goto LABEL_5;
  }
  else if ( v6 )
  {
LABEL_5:
    v9 = *(_QWORD *)(v6 + 96);
    if ( v9 )
    {
      v10 = *(_QWORD *)(v9 + 24);
      if ( v10 )
      {
        if ( *(_BYTE *)(v6 + 312) == 1 )
        {
          v11 = *(_QWORD *)(v10 + 208);
          ++tof_i2c_open_count;
          if ( (_pm_runtime_resume(v11, 4) & 0x80000000) != 0 )
            printk(&unk_3CC265);
        }
      }
    }
    goto LABEL_14;
  }
  printk(&unk_41F890);
LABEL_14:
  v13 = vi530x_func_tbl;
  *(_BYTE *)(v6 + 46) = *a4;
  *(_BYTE *)(v6 + 47) = a4[1];
  v14 = *(__int64 (__fastcall **)(_QWORD))(v13 + 96);
  if ( *((_DWORD *)v14 - 1) != 1318018478 )
    __break(0x8228u);
  v15 = v14(v6);
  if ( v15 )
  {
    LODWORD(v12) = v15;
    printk(&unk_40FCF9);
    if ( v6 )
    {
      v19 = *(_QWORD *)(v6 + 96);
      if ( v19 )
      {
        v20 = *(_QWORD *)(v19 + 24);
        if ( v20 )
        {
          if ( *(_BYTE *)(v6 + 312) == 1 )
          {
            v21 = *(_QWORD *)(v20 + 208);
            --tof_i2c_open_count;
            _pm_runtime_idle(v21, 4);
          }
        }
      }
      v12 = (int)v12;
    }
    else
    {
      printk(&unk_41F890);
      v12 = (int)v12;
    }
  }
  else
  {
    if ( v6 )
    {
      v16 = *(_QWORD *)(v6 + 96);
      if ( v16 )
      {
        v17 = *(_QWORD *)(v16 + 24);
        if ( v17 )
        {
          if ( *(_BYTE *)(v6 + 312) == 1 )
          {
            v18 = *(_QWORD *)(v17 + 208);
            --tof_i2c_open_count;
            _pm_runtime_idle(v18, 4);
          }
        }
      }
    }
    else
    {
      printk(&unk_41F890);
    }
    v12 = 2;
  }
LABEL_30:
  mutex_unlock(v6 + 264);
  return v12;
}
