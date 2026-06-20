__int64 __fastcall msm_v4l2_open(__int64 a1)
{
  __int64 v2; // x20
  __int64 v3; // x0
  __int64 v4; // x0

  v2 = ((__int64 (*)(void))video_devdata)();
  v3 = *(_QWORD *)(video_devdata(a1) + 336);
  v4 = msm_vidc_open(v3, *(_DWORD *)(v2 - 8));
  if ( v4 )
  {
    *(_QWORD *)(a1 + 32) = v4 + 1648;
    return 0;
  }
  else
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_8F36B, "err ", 0xFFFFFFFFLL, "codec", *(unsigned int *)(v2 - 8));
    return 4294967284LL;
  }
}
