__int64 __fastcall msm_vidc_decoder_input_size(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 result; // x0
  __int64 v7; // x2
  unsigned int v8; // w19
  int v9; // w20
  __int64 v10; // x1
  unsigned int mbs_per_frame; // w0
  __int64 v12; // x4
  int v13; // w9
  int v14; // w8
  int v15; // w11
  unsigned int v16; // w8
  int v17; // w9
  unsigned int v18; // w9
  bool v20; // zf
  unsigned int v21; // w8
  unsigned int v24; // w9
  unsigned int v25; // w20

  result = *(unsigned int *)(a1 + 32408);
  if ( (_DWORD)result )
  {
    if ( a1 )
    {
      if ( (msm_vidc_debug & 2) != 0 )
      {
        v7 = a1 + 340;
        v8 = result;
        printk(&unk_8414E, "high", v7, (unsigned int)result, a5);
        return v8;
      }
    }
  }
  else
  {
    v9 = v4l2_codec_to_driver(a1, *(unsigned int *)(a1 + 400), "msm_vidc_decoder_input_size");
    mbs_per_frame = msm_vidc_get_mbs_per_frame(a1, v10);
    if ( mbs_per_frame <= 0x9000 )
    {
      v13 = 36864;
      if ( v9 == 4 )
        v14 = 1;
      else
        v14 = 2;
    }
    else
    {
      v13 = *(_DWORD *)(a1 + 18632);
      v14 = 4;
    }
    v15 = *(_DWORD *)(a1 + 312);
    if ( v15 == 8 )
      v13 = mbs_per_frame;
    v16 = v14 << (*(_QWORD *)(a1 + 21824) != 0);
    v17 = 3 * v13;
    if ( v15 == 8 )
      v16 = 1;
    v18 = (v17 & 0xFFFFFF) << 7;
    v20 = v9 == 16 || v9 == 4 || v9 == 2;
    v21 = v18 / v16;
    if ( v20 || v9 == 8 || v9 == 64 )
      v24 = v21 >> 2;
    else
      v24 = 0;
    v25 = v24 + v21;
    if ( a1 && (msm_vidc_debug & 2) != 0 )
      printk(&unk_8B3F4, "high", a1 + 340, v25, v12);
    return (v25 + 4095) & 0xFFFFF000;
  }
  return result;
}
