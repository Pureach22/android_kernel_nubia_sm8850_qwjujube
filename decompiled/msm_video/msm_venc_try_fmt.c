__int64 __fastcall msm_venc_try_fmt(_DWORD *a1, unsigned int *a2)
{
  __int64 v2; // x4
  __int64 v5; // x4
  _DWORD *v6; // x0
  __int64 v7; // x1
  unsigned int v8; // w8
  __int64 v11; // x4
  _DWORD *v12; // x8

  v2 = *a2;
  a2[49] = 0;
  *(unsigned int *)((char *)a2 + 193) = 0;
  if ( (int)v2 > 12 )
  {
    if ( (_DWORD)v2 == 13 )
    {
      a2[2] = a1[254];
      v8 = a1[255];
    }
    else
    {
      if ( (_DWORD)v2 != 14 )
        goto LABEL_12;
      a2[2] = a1[202];
      v8 = a1[203];
    }
    a2[3] = v8;
LABEL_22:
    if ( !a2[5] )
      a2[5] = 1;
    *((_BYTE *)a2 + 188) = 1;
    return 0;
  }
  if ( (_DWORD)v2 == 9 )
  {
    if ( !(unsigned int)v4l2_codec_to_driver(a1, a2[4], "msm_venc_try_fmt") )
    {
      v12 = a1;
      if ( a1 && (msm_vidc_debug & 1) != 0 )
      {
        printk(&unk_8C8B4, "err ", a1 + 85, "msm_venc_try_fmt", v11);
        v12 = a1;
      }
      a2[2] = v12[150];
      a2[3] = v12[151];
      a2[4] = v12[152];
    }
    goto LABEL_22;
  }
  if ( (_DWORD)v2 == 10 )
  {
    if ( !(unsigned int)v4l2_colorformat_to_driver(a1, a2[4], "msm_venc_try_fmt") )
    {
      v6 = a1;
      if ( a1 && (msm_vidc_debug & 1) != 0 )
      {
        printk(&unk_9447C, "err ", a1 + 85, "msm_venc_try_fmt", v5);
        v6 = a1;
      }
      v7 = (unsigned int)v6[100];
      a2[4] = v7;
      a2[2] = v6[98];
      a2[3] = v6[99];
      v4l2_colorformat_to_driver(v6, v7, "msm_venc_try_fmt");
    }
    goto LABEL_22;
  }
LABEL_12:
  if ( !a1 || (msm_vidc_debug & 1) == 0 )
    return 4294967274LL;
  printk(&unk_9531A, "err ", a1 + 85, "msm_venc_try_fmt", v2);
  return 4294967274LL;
}
