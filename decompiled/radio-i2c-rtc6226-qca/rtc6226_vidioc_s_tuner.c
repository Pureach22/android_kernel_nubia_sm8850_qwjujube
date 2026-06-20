__int64 __fastcall rtc6226_vidioc_s_tuner(__int64 a1, __int64 a2, _DWORD *a3)
{
  __int64 v4; // x0
  __int64 result; // x0
  int v6; // w8
  _WORD *v7; // x19
  __int16 v8; // w8
  unsigned int v9; // w21
  unsigned int v10; // w20
  unsigned int v11; // w19

  v4 = video_devdata();
  if ( *a3 )
    return 0;
  v6 = a3[14];
  v7 = *(_WORD **)(v4 + 336);
  if ( v6 == 1 )
  {
    v8 = v7[883] & 0xDFFF;
    goto LABEL_7;
  }
  if ( !v6 )
  {
    v8 = v7[883] | 0x2000;
LABEL_7:
    v7[883] = v8;
  }
  rtc6226_set_register(v7, 2);
  v9 = a3[12] / 0xA0u;
  v10 = a3[11] / 0xA0u;
  v7[901] = v9;
  v7[902] = v10;
  if ( (rtc6226_set_register(v7, 20) & 0x80000000) != 0 )
    printk(&unk_D321, "rtc6226_vidioc_s_tuner");
  else
    v7[1015] = v9;
  result = rtc6226_set_register(v7, 21);
  if ( (result & 0x80000000) != 0 )
  {
    v11 = result;
    printk(&unk_D914, "rtc6226_vidioc_s_tuner");
    return v11;
  }
  else
  {
    v7[1014] = v10;
  }
  return result;
}
