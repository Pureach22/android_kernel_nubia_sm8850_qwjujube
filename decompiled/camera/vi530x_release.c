__int64 __fastcall vi530x_release(__int64 a1, __int64 a2)
{
  __int64 v3; // x8
  __int64 v4; // x9
  __int64 v5; // x9
  __int64 v6; // x0

  printk(&unk_427388);
  v3 = *(_QWORD *)(a2 + 32);
  if ( v3 == 112 )
  {
    printk(&unk_41F890);
  }
  else
  {
    v4 = *(_QWORD *)(v3 - 16);
    if ( v4 )
    {
      v5 = *(_QWORD *)(v4 + 24);
      if ( v5 )
      {
        if ( *(_BYTE *)(v3 + 200) == 1 )
        {
          v6 = *(_QWORD *)(v5 + 208);
          --tof_i2c_open_count;
          _pm_runtime_idle(v6, 4);
        }
      }
    }
  }
  return 0;
}
