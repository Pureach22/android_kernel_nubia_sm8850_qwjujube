__int64 __fastcall v4l2_codec_to_driver(__int64 a1, int a2, __int64 a3)
{
  unsigned int *v3; // x9
  __int64 v4; // x8
  unsigned int *v5; // x9

  v3 = *(unsigned int **)(*(_QWORD *)(*(_QWORD *)(a1 + 320) + 3912LL) + 336LL);
  v4 = v3[2];
  if ( (_DWORD)v4 )
  {
    v5 = (unsigned int *)(*(_QWORD *)v3 + 4LL);
    while ( *(v5 - 1) != a2 )
    {
      --v4;
      v5 += 4;
      if ( !v4 )
        goto LABEL_5;
    }
    return *v5;
  }
  else
  {
LABEL_5:
    if ( (msm_vidc_debug & 2) != 0 )
      printk(&unk_858CD, "high", 0xFFFFFFFFLL, "codec", a3);
    return 0;
  }
}
