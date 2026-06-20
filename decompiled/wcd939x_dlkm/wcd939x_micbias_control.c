__int64 __fastcall wcd939x_micbias_control(__int64 a1, int a2, int a3, int a4)
{
  __int64 v4; // x21
  __int64 v7; // x26
  int v8; // w27
  int v9; // w20
  char v10; // w28
  int v11; // w8
  __int64 v12; // x22
  __int64 v13; // x23
  __int64 v14; // x24
  __int64 v15; // x25
  int v17; // w8
  int v18; // w8
  int v19; // w10
  int v20; // w8
  int v21; // w10
  int v22; // w8
  __int64 v23; // x1
  __int64 v24; // x0
  __int64 v25; // x3
  __int64 v26; // x8
  int v27; // w9
  __int64 v28; // x9
  int v29; // w8
  int v30; // w10
  __int64 v31; // x2
  __int64 v32; // x0
  __int64 v33; // x1
  __int64 v34; // x2
  unsigned int v35; // w19
  __int64 v36; // x2
  __int64 v37; // x2
  unsigned int v38; // [xsp+8h] [xbp-8h]
  int v39; // [xsp+Ch] [xbp-4h]

  v4 = (unsigned int)(a2 - 1);
  if ( (unsigned int)v4 >= 4 )
  {
    if ( (unsigned int)__ratelimit(&wcd939x_micbias_control__rs, "wcd939x_micbias_control") )
    {
      dev_err(
        *(_QWORD *)(a1 + 24),
        "%s: Invalid micbias index, micb_ind:%d\n",
        "wcd939x_micbias_control",
        (unsigned int)v4);
      return 4294967274LL;
    }
    return 4294967274LL;
  }
  v7 = *(_QWORD *)(*(_QWORD *)(a1 + 24) + 152LL);
  if ( !v7 )
  {
    if ( (unsigned int)__ratelimit(&wcd939x_micbias_control__rs_6, "wcd939x_micbias_control") )
    {
      dev_err(*(_QWORD *)(a1 + 24), "%s: wcd939x private data is NULL\n", "wcd939x_micbias_control");
      return 4294967274LL;
    }
    return 4294967274LL;
  }
  if ( a2 > 2 )
  {
    if ( a2 == 3 )
    {
      v11 = 12325;
    }
    else
    {
      if ( a2 != 4 )
        goto LABEL_15;
      v11 = 12326;
    }
  }
  else
  {
    if ( a2 != 1 )
    {
      if ( a2 == 2 )
      {
        v8 = a3;
        v9 = a4;
        v10 = 0;
        v39 = 1;
        v11 = 12323;
        v12 = 8;
        v13 = 6;
        v14 = 4;
        v15 = 2;
        goto LABEL_20;
      }
LABEL_15:
      if ( (unsigned int)__ratelimit(&wcd939x_micbias_control__rs_8, "wcd939x_micbias_control") )
      {
        dev_err(*(_QWORD *)(a1 + 24), "%s: Invalid micbias number: %d\n", "wcd939x_micbias_control", (unsigned int)a2);
        return 4294967274LL;
      }
      return 4294967274LL;
    }
    v11 = 12322;
  }
  v8 = a3;
  v9 = a4;
  v15 = 0;
  v14 = 0;
  v39 = 0;
  v13 = 0;
  v12 = 0;
  v10 = 1;
LABEL_20:
  v38 = v11;
  mutex_lock(v7 + 104);
  v17 = 0;
  if ( v8 > 1 )
  {
    if ( v8 == 2 )
    {
      if ( *(_BYTE *)(v7 + 3216) == 1 )
      {
        v28 = v7 + 4LL * (unsigned int)v4;
        v29 = v9;
        v30 = *(_DWORD *)(v28 + 56);
        *(_DWORD *)(v28 + 56) = v30 + 1;
        if ( !v30 )
        {
          snd_soc_component_update_bits(a1, 13321, 128, 128);
          snd_soc_component_update_bits(a1, 13321, 64, 64);
          snd_soc_component_update_bits(a1, 13321, 32, 32);
          snd_soc_component_update_bits(a1, 13321, 16, 16);
          snd_soc_component_update_bits(a1, 13320, 16, 16);
          snd_soc_component_update_bits(a1, 13335, 1, 1);
          snd_soc_component_update_bits(a1, 12396, 7, 1);
          snd_soc_component_update_bits(a1, 12399, 7, 1);
          snd_soc_component_update_bits(a1, 12402, 7, 1);
          snd_soc_component_update_bits(a1, 12405, 7, 1);
          snd_soc_component_update_bits(a1, v38, 192, 64);
          v29 = v9;
          if ( (v10 & 1) == 0 )
          {
            blocking_notifier_call_chain(*(_QWORD *)(v7 + 256) + 976LL, v14);
            v29 = v9;
          }
        }
        if ( (v39 & v29) != 1 )
          goto LABEL_56;
        v31 = *(_QWORD *)(v7 + 256);
        if ( !v31 )
          goto LABEL_56;
        v32 = v31 + 976;
        v33 = v12;
        goto LABEL_55;
      }
    }
    else
    {
      if ( v8 != 3 )
        goto LABEL_57;
      v20 = *(_DWORD *)(v7 + 56 + 4LL * (unsigned int)v4);
      v21 = v20 - 1;
      if ( v20 >= 1 )
      {
        --v20;
        *(_DWORD *)(v7 + 56 + 4 * v4) = v21;
      }
      if ( *(_BYTE *)(v7 + 3216) == 1 )
      {
        if ( v20 )
          goto LABEL_52;
        v22 = *(_DWORD *)(v7 + 4 * v4 + 72);
        if ( v22 < 1 )
        {
          if ( v22 )
          {
LABEL_52:
            if ( (v39 & v9) != 1 )
              goto LABEL_56;
            v34 = *(_QWORD *)(v7 + 256);
            if ( !v34 )
              goto LABEL_56;
            v32 = v34 + 976;
            v33 = v13;
LABEL_55:
            blocking_notifier_call_chain(v32, v33);
LABEL_56:
            v17 = 0;
            goto LABEL_57;
          }
          if ( (v10 & 1) == 0 )
          {
            v36 = *(_QWORD *)(v7 + 256);
            if ( v36 )
              blocking_notifier_call_chain(v36 + 976, 1);
            snd_soc_component_update_bits(a1, v38, 192, 0);
            v37 = *(_QWORD *)(v7 + 256);
            if ( v37 )
              blocking_notifier_call_chain(v37 + 976, v15);
            goto LABEL_52;
          }
          v23 = v38;
          v24 = a1;
          v25 = 0;
        }
        else
        {
          v23 = v38;
          v24 = a1;
          v25 = 128;
        }
        snd_soc_component_update_bits(v24, v23, 192, v25);
        goto LABEL_52;
      }
    }
LABEL_49:
    v17 = -19;
    goto LABEL_57;
  }
  if ( !v8 )
  {
    if ( *(_BYTE *)(v7 + 3216) == 1 )
    {
      v26 = v7 + 4LL * (unsigned int)v4;
      v27 = *(_DWORD *)(v26 + 72);
      *(_DWORD *)(v26 + 72) = v27 + 1;
      if ( !v27 && !*(_DWORD *)(v7 + 4 * v4 + 56) )
        snd_soc_component_update_bits(a1, v38, 192, 128);
      goto LABEL_56;
    }
    goto LABEL_49;
  }
  if ( v8 == 1 )
  {
    v18 = *(_DWORD *)(v7 + 72 + 4LL * (unsigned int)v4);
    v19 = v18 - 1;
    if ( v18 >= 1 )
    {
      --v18;
      *(_DWORD *)(v7 + 72 + 4 * v4) = v19;
    }
    if ( *(_BYTE *)(v7 + 3216) == 1 )
    {
      if ( !v18 && !*(_DWORD *)(v7 + 4 * v4 + 56) )
        snd_soc_component_update_bits(a1, v38, 192, 0);
      goto LABEL_56;
    }
    goto LABEL_49;
  }
LABEL_57:
  v35 = v17;
  mutex_unlock(v7 + 104);
  return v35;
}
