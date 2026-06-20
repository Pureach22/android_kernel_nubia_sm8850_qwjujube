__int64 __fastcall rtc6226_vidioc_s_hw_freq_seek(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v5; // x0
  __int64 v6; // x19
  __int16 v7; // w8
  unsigned int v8; // w0
  int v9; // w2
  int v10; // w8
  __int16 v11; // w20
  __int64 result; // x0
  __int64 v13; // x1
  __int64 v14; // x2
  unsigned int v15; // w19

  v5 = video_devdata();
  if ( (*(_BYTE *)(a1 + 49) & 8) != 0 )
    return 4294967285LL;
  v6 = *(_QWORD *)(v5 + 336);
  v7 = *(_WORD *)(v6 + 1770);
  *(_BYTE *)(v6 + 1928) = 0;
  *(_WORD *)(v6 + 1770) = v7 & 0xEFFF;
  v8 = rtc6226_set_register(v6, 4);
  if ( (v8 & 0x80000000) != 0 )
  {
    v15 = v8;
    printk(&unk_CD42, "rtc6226_vidioc_s_hw_freq_seek");
    return v15;
  }
  v9 = *(unsigned __int8 *)(v6 + 1929);
  if ( v9 == 2 )
  {
    *(_BYTE *)(v6 + 1970) = 0;
    *(_QWORD *)(v6 + 1954) = 0;
    *(_QWORD *)(v6 + 1962) = 0;
    *(_QWORD *)(v6 + 1938) = 0;
    *(_QWORD *)(v6 + 1946) = 0;
    *(_QWORD *)(v6 + 1930) = 0;
    goto LABEL_11;
  }
  if ( v9 == 1 )
  {
LABEL_11:
    v13 = *(_QWORD *)(v6 + 2040);
    v14 = v6 + 2416;
    v15 = v8;
    queue_delayed_work_on(32, v13, v14, 3);
    return v15;
  }
  if ( *(_BYTE *)(v6 + 1929) )
  {
    printk(&unk_D0DB, "rtc6226_vidioc_s_hw_freq_seek");
    return 4294967274LL;
  }
  else
  {
    *(_BYTE *)(v6 + 1760) = 2;
    v10 = *(_DWORD *)(a3 + 8);
    v11 = *(_WORD *)(v6 + 1772);
    *(_WORD *)(v6 + 1772) = v11 & 0x1FFF | ((v10 != 0) << 14);
    result = rtc6226_set_register(v6, 5);
    if ( (result & 0x80000000) != 0
      || (*(_WORD *)(v6 + 1772) |= 0x8000u, result = rtc6226_set_register(v6, 5), (result & 0x80000000) != 0) )
    {
      *(_WORD *)(v6 + 1772) = v11;
    }
  }
  return result;
}
