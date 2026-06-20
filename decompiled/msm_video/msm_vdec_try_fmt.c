__int64 __fastcall msm_vdec_try_fmt(__int64 a1, unsigned int *a2)
{
  __int64 v2; // x4
  __int64 v5; // x4
  __int64 v6; // x1
  unsigned int v7; // w8
  __int64 v9; // x4

  v2 = *a2;
  a2[49] = 0;
  *(unsigned int *)((char *)a2 + 193) = 0;
  if ( (int)v2 > 12 )
  {
    if ( (_DWORD)v2 == 13 )
    {
      a2[2] = *(_DWORD *)(a1 + 1016);
      v7 = *(_DWORD *)(a1 + 1020);
    }
    else
    {
      if ( (_DWORD)v2 != 14 )
        goto LABEL_12;
      a2[2] = *(_DWORD *)(a1 + 808);
      v7 = *(_DWORD *)(a1 + 812);
    }
    a2[3] = v7;
LABEL_26:
    if ( !a2[5] )
      a2[5] = 1;
    *((_BYTE *)a2 + 188) = 1;
    return 0;
  }
  if ( (_DWORD)v2 == 9 )
  {
    if ( !(unsigned int)v4l2_colorformat_to_driver(a1, a2[4], "msm_vdec_try_fmt") )
    {
      if ( a1 && (msm_vidc_debug & 1) != 0 )
        printk(&unk_9447C, "err ", a1 + 340, "msm_vdec_try_fmt", v9);
      a2[4] = *(_DWORD *)(a1 + 608);
      a2[2] = *(_DWORD *)(a1 + 600);
      a2[3] = *(_DWORD *)(a1 + 604);
    }
    if ( (*(_WORD *)(*(_QWORD *)(a1 + 1840) + 320LL) & 1) != 0
      && (*(_DWORD *)(a1 + 312) != 8 || *(_DWORD *)(a1 + 308) != 2) )
    {
      a2[3] = *(_DWORD *)(a1 + 396);
      a2[2] = *(_DWORD *)(a1 + 392);
    }
    goto LABEL_26;
  }
  if ( (_DWORD)v2 == 10 )
  {
    if ( !(unsigned int)v4l2_codec_to_driver(a1, a2[4], "msm_vdec_try_fmt") )
    {
      if ( a1 && (msm_vidc_debug & 1) != 0 )
        printk(&unk_8C8B4, "err ", a1 + 340, "msm_vdec_try_fmt", v5);
      a2[2] = *(_DWORD *)(a1 + 392);
      a2[3] = *(_DWORD *)(a1 + 396);
      v6 = *(unsigned int *)(a1 + 400);
      a2[4] = v6;
      v4l2_codec_to_driver(a1, v6, "msm_vdec_try_fmt");
    }
    goto LABEL_26;
  }
LABEL_12:
  if ( !a1 || (msm_vidc_debug & 1) == 0 )
    return 4294967274LL;
  printk(&unk_9531A, "err ", a1 + 340, "msm_vdec_try_fmt", v2);
  return 4294967274LL;
}
