__int64 __fastcall vi530x_chip_enable_store(__int64 a1, __int64 a2, const char *a3, __int64 a4)
{
  __int64 v6; // x21
  void *v8; // x0
  __int64 v9; // x8
  unsigned int v10; // [xsp+4h] [xbp-1Ch] BYREF
  __int64 v11; // [xsp+8h] [xbp-18h] BYREF
  __int64 v12; // [xsp+10h] [xbp-10h]
  __int64 v13; // [xsp+18h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 152);
  v10 = 0;
  printk(&unk_3D3F1B);
  if ( v6 )
  {
    mutex_lock(v6 + 264);
    if ( sscanf(a3, "%u\n", &v10) == 1 )
    {
      if ( v10 < 2 )
      {
        if ( v10 == 1 )
        {
          if ( (tof_enable & 1) != 0 )
          {
            v8 = &unk_3DC121;
          }
          else
          {
            v11 = 0;
            v12 = 0;
            tof_enable = 1;
            *(_DWORD *)(v6 + 224) = 1;
            ktime_get_real_ts64(&v11);
            v8 = &unk_3F08CB;
            v9 = v12 / 1000;
            *(_QWORD *)(v6 + 192) = v11;
            *(_QWORD *)(v6 + 200) = v9;
          }
        }
        else if ( tof_enable )
        {
          tof_enable = 0;
          v8 = &unk_4463FD;
          *(_DWORD *)(v6 + 224) = 0;
        }
        else
        {
          v8 = &unk_40FCD5;
        }
      }
      else
      {
        v8 = &unk_3E4220;
      }
      printk(v8);
    }
    else
    {
      a4 = -1;
    }
    mutex_unlock(v6 + 264);
  }
  else
  {
    a4 = -1;
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
