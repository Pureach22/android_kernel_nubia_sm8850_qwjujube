__int64 __fastcall lpass_cdc_rx_macro_fir_audio_mixer_get(__int64 a1, __int64 a2)
{
  __int64 v2; // x0
  unsigned int *v3; // x8
  __int64 v4; // x19
  __int64 v5; // x20
  __int64 result; // x0
  _QWORD *v8; // x10
  __int64 v9; // x9
  __int64 v10; // x8
  __int64 v11; // x12
  __int64 v12; // x11
  size_t v13; // x2
  __int64 v14; // x11
  __int64 v15; // x11
  __int64 v16; // x12
  _DWORD *v17; // x14
  int *v18; // x13
  __int64 v19; // x15
  int v20; // w16
  int v21; // w17
  __int64 v22; // x12
  __int64 v23; // x9
  __int64 v24; // x13
  _QWORD *v25; // x10
  int v26; // w15
  _QWORD *v27; // [xsp+0h] [xbp-1B0h] BYREF
  __int64 v28; // [xsp+8h] [xbp-1A8h] BYREF
  _DWORD src[101]; // [xsp+14h] [xbp-19Ch] BYREF
  __int64 v30; // [xsp+1A8h] [xbp-8h]

  v30 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(unsigned int **)(a1 + 120);
  v2 = *(_QWORD *)(a1 + 128);
  v27 = nullptr;
  v4 = *v3;
  v5 = v3[1];
  if ( !v2 )
  {
    if ( (unsigned int)__ratelimit(
                         &lpass_cdc_rx_macro_fir_audio_mixer_get__rs,
                         "lpass_cdc_rx_macro_fir_audio_mixer_get") )
      printk(&unk_F49A, "lpass_cdc_rx_macro_fir_audio_mixer_get");
    goto LABEL_8;
  }
  if ( (lpass_cdc_rx_macro_get_data(v2, &v28, &v27, (__int64)"lpass_cdc_rx_macro_fir_audio_mixer_get") & 1) == 0 )
  {
LABEL_8:
    result = 4294967274LL;
    goto LABEL_9;
  }
  if ( (unsigned int)v4 >= 2 )
  {
    if ( (unsigned int)__ratelimit(
                         &lpass_cdc_rx_macro_fir_audio_mixer_get__rs_414,
                         "lpass_cdc_rx_macro_fir_audio_mixer_get") )
      dev_err(*v27, "%s: path_idx:%d is invalid\n", "lpass_cdc_rx_macro_fir_audio_mixer_get", (unsigned int)v4);
    goto LABEL_8;
  }
  if ( (unsigned int)v5 >= 2 )
  {
    if ( (unsigned int)__ratelimit(
                         &lpass_cdc_rx_macro_fir_audio_mixer_get__rs_415,
                         "lpass_cdc_rx_macro_fir_audio_mixer_get") )
      dev_err(*v27, "%s: grp_idx:%d is invalid\n", "lpass_cdc_rx_macro_fir_audio_mixer_get", (unsigned int)v5);
    goto LABEL_8;
  }
  memset(&src[1], 0, 0x190u);
  v8 = v27;
  v9 = *((unsigned int *)&v27[v4 + 284] + v5 + 1);
  src[0] = v9;
  if ( (_DWORD)v9 )
  {
    v10 = a2;
    if ( (unsigned int)v9 > 2 )
    {
      v14 = v9 - 1;
      if ( (unsigned __int64)(v9 - 1) >= 0x64 )
        v14 = 100;
      v15 = v14 + 1;
      v16 = v15 & 1;
      if ( (v15 & 1) == 0 )
        v16 = 2;
      v11 = v15 - v16;
      v17 = &src[2];
      v12 = v11 + 1;
      v18 = (int *)&v27[100 * (unsigned int)v4 + 85 + 50 * (unsigned int)v5];
      v19 = v11;
      do
      {
        v20 = *(v18 - 1);
        v21 = *v18;
        v19 -= 2;
        v18 += 2;
        *(v17 - 1) = v20;
        *v17 = v21;
        v17 += 2;
      }
      while ( v19 );
    }
    else
    {
      v11 = 0;
      v12 = 1;
    }
    v22 = v11 + 169;
    v23 = -v9;
    v24 = 4 * v12;
    v25 = &v8[100 * (unsigned int)v4 + 50 * (unsigned int)v5];
    do
    {
      if ( v22 == 269 )
      {
        __break(0x5512u);
LABEL_30:
        __break(1u);
      }
      if ( (v12 & 0x3FFFFFFFFFFFFFFFLL) == 0x65 )
        goto LABEL_30;
      v26 = *((_DWORD *)v25 + v22++);
      src[v12] = v26;
      v24 += 4;
      ++v12;
    }
    while ( v23 + v22 != 169 );
    v13 = v24 & 0x3FFFFFFFCLL;
  }
  else
  {
    v13 = 4;
    v10 = a2;
  }
  memcpy((void *)(v10 + 72), src, v13);
  result = 0;
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
