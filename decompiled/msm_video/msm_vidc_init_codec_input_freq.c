__int64 __fastcall msm_vidc_init_codec_input_freq(__int64 a1, int a2, _DWORD *a3)
{
  __int64 result; // x0
  __int64 v7; // x8
  __int64 v8; // x5
  int v9; // w8
  int v10; // w8
  unsigned __int64 v11; // x8
  int v12; // w0
  int v13; // w8
  int v14; // w9
  int v15; // w0
  int v16; // w8
  int v17; // w9
  int v18; // w8
  unsigned int frame_rate; // w0
  unsigned int v20; // w8
  int v21; // w9
  int v22; // w8
  int v23; // w9
  _DWORD *v24; // x21
  unsigned int v25; // w23
  int v26; // w8

  a3[1] = 8;
  result = msm_vidc_init_codec(a1, a3);
  if ( (_DWORD)result )
    return result;
  a3[4] = *(_QWORD *)(a1 + 31400);
  a3[5] = *(_DWORD *)(a1 + 38700);
  v7 = a1 + 208LL * (*(_DWORD *)(a1 + 308) != 2);
  a3[6] = *(_DWORD *)(v7 + 392);
  a3[7] = *(_DWORD *)(v7 + 396);
  v8 = *(_QWORD *)(a1 + 11576);
  if ( v8 == 1 )
  {
    v9 = 1;
LABEL_6:
    a3[10] = v9;
    if ( *(_QWORD *)(a1 + 32072) == 524296 )
      v10 = 8;
    else
      v10 = 10;
    a3[15] = v10;
    if ( *(_DWORD *)(a1 + 308) == 1 )
    {
      if ( *(_QWORD *)(a1 + 16112) )
      {
        LODWORD(v11) = 7;
      }
      else
      {
        v11 = *(_QWORD *)(a1 + 15944);
        if ( v11 )
        {
          v11 = *(_QWORD *)(a1 + 15272);
          if ( v11 > 2 )
            LODWORD(v11) = 3;
          else
            LODWORD(v11) = dword_9ABB0[v11];
        }
      }
    }
    else
    {
      LODWORD(v11) = 0;
    }
    a3[12] = v11;
    if ( *(_DWORD *)(a1 + 308) == 2 )
    {
      v12 = v4l2_colorformat_to_driver(a1, *(unsigned int *)(a1 + 608), "msm_vidc_init_codec_input_freq");
      v13 = 1;
      if ( ((unsigned int)(v12 - 2) > 0x3E || ((1LL << ((unsigned __int8)v12 - 2)) & 0x4000000000004005LL) == 0)
        && v12 != 256 )
      {
        v13 = 0;
      }
      v14 = a3[5];
      a3[16] = v13;
      a3[22] = 8 * a2 * v14 / 0xF4240u;
      goto LABEL_45;
    }
    v15 = v4l2_colorformat_to_driver(a1, *(unsigned int *)(a1 + 400), "msm_vidc_init_codec_input_freq");
    v16 = 1;
    if ( ((unsigned int)(v15 - 2) > 0x3E || ((1LL << ((unsigned __int8)v15 - 2)) & 0x4000000000004005LL) == 0)
      && v15 != 256 )
    {
      v16 = 0;
    }
    v17 = a3[15];
    a3[18] = v16;
    if ( v17 != 10 )
    {
LABEL_42:
      frame_rate = msm_vidc_get_frame_rate(a1);
      v20 = *(_DWORD *)(a1 + 38700);
      v21 = (int)*(_QWORD *)(a1 + 15440) / 1000000;
      a3[22] = v21;
      if ( frame_rate && v20 > frame_rate )
        a3[22] = v20 * v21 / frame_rate;
LABEL_45:
      if ( *(_DWORD *)(a1 + 312) == 16 && a3[3] == 128 )
      {
        v22 = *(_DWORD *)(a1 + 2004);
        v23 = *(_DWORD *)(a1 + 2008);
        a3[28] = 1;
        v24 = a3 + 28;
        v25 = v23 * v22;
        if ( (res_is_less_than_or_equal_to((unsigned int)a3[6], (unsigned int)a3[7], 1920, 1088) & 1) != 0 )
        {
          if ( v25 >= 3 )
            goto LABEL_52;
        }
        else if ( (res_is_less_than_or_equal_to((unsigned int)a3[6], (unsigned int)a3[7], 4096, 2176) & 1) != 0 )
        {
          if ( v25 >= 5 )
            goto LABEL_52;
        }
        else if ( (res_is_less_than_or_equal_to((unsigned int)a3[6], (unsigned int)a3[7], 0x2000, 4320) & 1) == 0
               || v25 >= 0x11 )
        {
LABEL_52:
          a3[33] = 0;
          a3[29] = 1;
          if ( *(_QWORD *)(a1 + 35936) )
            v26 = 5;
          else
            v26 = 0;
          a3[33] = v26;
          if ( *(_QWORD *)(a1 + 23168) )
          {
            if ( a3[2] == 5 )
              a3[33] = 1;
          }
          result = 0;
          a3[32] = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 320) + 3912LL) + 328LL);
          return result;
        }
      }
      else
      {
        v24 = a3 + 28;
      }
      *v24 = 0;
      goto LABEL_52;
    }
    if ( v15 > 127 )
    {
      if ( v15 == 128 || v15 == 256 )
      {
        v18 = 3;
        goto LABEL_41;
      }
    }
    else
    {
      if ( v15 == 8 )
      {
LABEL_40:
        v18 = 0;
        goto LABEL_41;
      }
      if ( v15 == 16 )
      {
        v18 = 1;
LABEL_41:
        a3[31] = v18;
        goto LABEL_42;
      }
    }
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_87FEC, "err ", 0xFFFFFFFFLL, "codec", (unsigned int)v15);
    goto LABEL_40;
  }
  if ( v8 == 2 )
  {
    v9 = 2;
    goto LABEL_6;
  }
  if ( (msm_vidc_debug & 1) != 0 )
    printk(&unk_943FD, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_init_codec_input_freq");
  return 4294967274LL;
}
