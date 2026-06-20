__int64 __fastcall vi530x_open(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  __int64 v3; // x9
  __int64 v4; // x9
  __int64 v5; // x0

  v2 = *(_QWORD *)(a2 + 32);
  if ( v2 == 112 )
  {
    printk(&unk_41F890);
  }
  else
  {
    v3 = *(_QWORD *)(v2 - 16);
    if ( v3 )
    {
      v4 = *(_QWORD *)(v3 + 24);
      if ( v4 )
      {
        if ( *(_BYTE *)(v2 + 200) == 1 )
        {
          v5 = *(_QWORD *)(v4 + 208);
          ++tof_i2c_open_count;
          if ( (_pm_runtime_resume(v5, 4) & 0x80000000) != 0 )
            printk(&unk_3CC265);
        }
      }
    }
  }
  printk(&unk_403E42);
  return 0;
}
