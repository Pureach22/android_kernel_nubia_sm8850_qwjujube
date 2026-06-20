__int64 __fastcall rtc6226_vidioc_s_frequency(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v4; // x0
  unsigned int v5; // w8
  __int64 v6; // x19
  unsigned int v7; // w20
  __int64 result; // x0
  unsigned int v9; // w19

  v4 = video_devdata();
  if ( !a3 )
  {
    printk(&unk_D6C0, "rtc6226_vidioc_s_frequency");
    return 4294967274LL;
  }
  if ( *(_DWORD *)(a3 + 4) != 1 )
    return 4294967274LL;
  v5 = *(_DWORD *)(a3 + 8);
  v6 = *(_QWORD *)(v4 + 336);
  v7 = v5 >> 4;
  *(_BYTE *)(v6 + 1760) = 1;
  result = rtc6226_set_freq(v6, v5 >> 4);
  if ( (result & 0x80000000) != 0 )
  {
    v9 = result;
    printk(&unk_D261, "rtc6226_vidioc_s_frequency");
    return v9;
  }
  else
  {
    *(_DWORD *)(v6 + 1860) = v7;
  }
  return result;
}
