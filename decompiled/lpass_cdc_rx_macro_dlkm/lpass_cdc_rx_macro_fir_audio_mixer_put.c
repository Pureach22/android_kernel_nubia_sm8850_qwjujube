__int64 __fastcall lpass_cdc_rx_macro_fir_audio_mixer_put(__int64 a1, __int64 a2)
{
  unsigned int *v2; // x8
  __int64 v3; // x21
  __int64 v4; // x19
  __int64 v5; // x20
  __int64 result; // x0
  _QWORD *v8; // x22
  __int64 v9; // x8
  __int64 v10; // x23
  _DWORD *v11; // x25
  __int64 v12; // x26
  __int64 v13; // x8
  __int64 v14; // x9
  __int64 v15; // x10
  int *v16; // x11
  _DWORD *v17; // x10
  __int64 v18; // x12
  int v19; // w13
  int v20; // w14
  __int64 v21; // x8
  int *v22; // x9
  int v23; // t1
  int v24; // w10
  _QWORD *v25; // [xsp+0h] [xbp-1B0h] BYREF
  __int64 v26; // [xsp+8h] [xbp-1A8h] BYREF
  int v27; // [xsp+14h] [xbp-19Ch] BYREF
  _BYTE v28[400]; // [xsp+18h] [xbp-198h] BYREF
  __int64 v29; // [xsp+1A8h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(unsigned int **)(a1 + 120);
  v3 = *(_QWORD *)(a1 + 128);
  v25 = nullptr;
  v4 = *v2;
  v5 = v2[1];
  if ( !v3 )
  {
    if ( (unsigned int)__ratelimit(
                         &lpass_cdc_rx_macro_fir_audio_mixer_put__rs,
                         "lpass_cdc_rx_macro_fir_audio_mixer_put") )
      printk(&unk_F49A, "lpass_cdc_rx_macro_fir_audio_mixer_put");
    goto LABEL_8;
  }
  if ( (lpass_cdc_rx_macro_get_data(v3, &v26, &v25, (__int64)"lpass_cdc_rx_macro_fir_audio_mixer_put") & 1) == 0 )
  {
LABEL_8:
    result = 4294967274LL;
    goto LABEL_9;
  }
  if ( (unsigned int)v4 >= 2 )
  {
    if ( (unsigned int)__ratelimit(
                         &lpass_cdc_rx_macro_fir_audio_mixer_put__rs_418,
                         "lpass_cdc_rx_macro_fir_audio_mixer_put") )
      dev_err(*v25, "%s: path_idx:%d is invalid\n", "lpass_cdc_rx_macro_fir_audio_mixer_put", (unsigned int)v4);
    goto LABEL_8;
  }
  if ( (unsigned int)v5 >= 2 )
  {
    if ( (unsigned int)__ratelimit(
                         &lpass_cdc_rx_macro_fir_audio_mixer_put__rs_419,
                         "lpass_cdc_rx_macro_fir_audio_mixer_put") )
      dev_err(*v25, "%s: grp_idx:%d is invalid\n", "lpass_cdc_rx_macro_fir_audio_mixer_put", (unsigned int)v5);
    goto LABEL_8;
  }
  v8 = v25;
  if ( v25[293] && *((_BYTE *)v25 + 93) == 1 )
  {
    v9 = a2;
    v10 = *(unsigned int *)(a2 + 72);
    v27 = v10;
    if ( (unsigned int)v10 <= 0x64 )
    {
      v11 = (_DWORD *)&v25[v4 + 284] + 1;
      v12 = v9;
      v11[v5] = v10;
      memset(v28, 0, sizeof(v28));
      memcpy(v28, (const void *)(v12 + 76), 4 * v10);
      if ( (_DWORD)v10 )
      {
        if ( (unsigned int)v10 >= 3 )
        {
          v15 = v10 & 1;
          if ( (v10 & 1) == 0 )
            v15 = 2;
          v13 = v10 - v15;
          v16 = (int *)&v28[4];
          v14 = v10 - v15 + 1;
          v17 = &v8[100 * (unsigned int)v4 + 85 + 50 * (unsigned int)v5];
          v18 = v13;
          do
          {
            v19 = *(v16 - 1);
            v20 = *v16;
            v18 -= 2;
            v16 += 2;
            *(v17 - 1) = v19;
            *v17 = v20;
            v17 += 2;
          }
          while ( v18 );
        }
        else
        {
          v13 = 0;
          v14 = 1;
        }
        v21 = v13 + 169;
        v22 = (int *)&v28[4 * v14 - 4];
        do
        {
          if ( v21 == 269 )
          {
            __break(0x5512u);
            JUMPOUT(0xD654);
          }
          v23 = *v22++;
          *((_DWORD *)&v8[100 * (unsigned int)v4 + 50 * (unsigned int)v5] + v21++) = v23;
        }
        while ( v21 - v10 != 169 );
      }
      result = 0;
      v24 = *((unsigned __int8 *)v8 + v4 + 84);
      *((_BYTE *)v8 + 2 * v4 + v5 + 89) = 0;
      if ( v11[1] + *v11 == v24 )
        result = ((__int64 (__fastcall *)(__int64, _QWORD *, _QWORD))set_fir_filter_coeff)(v3, v8, (unsigned int)v4);
    }
    else
    {
      if ( (unsigned int)__ratelimit(
                           &lpass_cdc_rx_macro_fir_audio_mixer_put__rs_421,
                           "lpass_cdc_rx_macro_fir_audio_mixer_put") )
        dev_err(
          *v8,
          "%s: inavlid number of RX_FIR coefficients:%d in path:%d, group:%d\n",
          "lpass_cdc_rx_macro_fir_audio_mixer_put",
          v10,
          v4,
          v5);
      result = 4294967274LL;
      *((_DWORD *)&v8[v4 + 284] + v5 + 1) = 0;
    }
  }
  else
  {
    result = 0;
  }
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
