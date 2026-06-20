__int64 __fastcall rtc6226_vidioc_querycap(__int64 a1, __int64 a2, __int64 a3)
{
  strcpy((char *)a3, "rtc6226-fmtuner");
  strcpy((char *)(a3 + 16), "Richwave rtc6226 FM Tuner");
  *(_QWORD *)(a3 + 84) = 0x105050081050500LL;
  return 0;
}
