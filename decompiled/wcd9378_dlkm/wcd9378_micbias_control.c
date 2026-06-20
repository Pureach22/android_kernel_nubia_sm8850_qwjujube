__int64 __fastcall wcd9378_micbias_control(__int64 a1, unsigned int a2, int a3, int a4)
{
  __int64 v4; // x0
  __int64 v7; // x25
  __int64 v8; // x24
  unsigned int v9; // w22
  __int64 v10; // x20
  int v11; // w27
  int v12; // w19
  unsigned int v13; // w28
  __int64 v14; // x8
  unsigned int v15; // w23
  int v16; // w8
  int v17; // w10
  int v18; // w8
  int v19; // w10
  __int64 v20; // x2
  __int64 v21; // x1
  __int64 v22; // x8
  int v23; // w9
  __int64 v24; // x8
  int v25; // w9
  int v27; // w8
  __int64 v28; // x2
  __int64 v29; // x2
  __int64 v30; // [xsp+0h] [xbp-30h]
  __int64 v31; // [xsp+8h] [xbp-28h]
  __int64 v32; // [xsp+10h] [xbp-20h]
  __int64 v33; // [xsp+18h] [xbp-18h]
  char v34; // [xsp+24h] [xbp-Ch]

  v4 = *(_QWORD *)(a1 + 24);
  v7 = a2 - 1;
  v8 = *(_QWORD *)(v4 + 152);
  v9 = 1090519192;
  v10 = *(_QWORD *)(*(_QWORD *)v8 + 144LL);
  switch ( a2 )
  {
    case 1u:
      v11 = a4;
      v30 = 0;
      v31 = 0;
      v12 = 0;
      v32 = 0;
      v33 = 0;
      v13 = 1;
      v34 = 1;
      v14 = 44;
      break;
    case 3u:
      v11 = a4;
      v12 = 0;
      v9 = 1098907800;
      v13 = 4;
      v34 = 1;
      v14 = 52;
      v30 = 0;
      v31 = 0;
      v32 = 0;
      v33 = 0;
      break;
    case 2u:
      v11 = a4;
      v34 = 0;
      v30 = 2;
      v9 = 1094713496;
      v32 = 8;
      v12 = 1;
      v33 = 6;
      v13 = 2;
      v31 = 4;
      v14 = 48;
      break;
    default:
      dev_err(v4, "%s: Invalid micbias number: %d\n", "wcd9378_micbias_control", a2);
      return 4294967274LL;
  }
  v15 = *(_DWORD *)(v10 + v14);
  mutex_lock(v8 + 136);
  if ( a3 <= 1 )
  {
    if ( !a3 )
    {
      v22 = v8 + 4LL * (unsigned int)v7;
      v23 = *(_DWORD *)(v22 + 84);
      *(_DWORD *)(v22 + 84) = v23 + 1;
      if ( !v23 && !*(_DWORD *)(v8 + 4 * v7 + 72) )
      {
        snd_soc_component_update_bits(a1, 1075316147, v13, v13);
        snd_soc_component_update_bits(a1, v9, 255, v15);
        if ( a2 == 2 )
        {
          snd_soc_component_update_bits(a1, 1086326680, 255, v15);
          *(_DWORD *)(v8 + 368) = *(_DWORD *)(v10 + 36);
        }
      }
      goto LABEL_37;
    }
    if ( a3 == 1 )
    {
      v16 = *(_DWORD *)(v8 + 84 + 4LL * (unsigned int)v7);
      v17 = v16 - 1;
      if ( v16 >= 1 )
      {
        --v16;
        *(_DWORD *)(v8 + 84 + 4 * v7) = v17;
      }
      if ( !v16 && !*(_DWORD *)(v8 + 4 * v7 + 72) )
      {
        snd_soc_component_update_bits(a1, v9, 255, 1);
        if ( a2 == 2 )
        {
          snd_soc_component_update_bits(a1, 1086326680, 255, 1);
          *(_DWORD *)(v8 + 368) = 0;
        }
      }
      goto LABEL_37;
    }
    goto LABEL_52;
  }
  if ( a3 == 2 )
  {
    v24 = v8 + 4LL * (unsigned int)v7;
    v25 = *(_DWORD *)(v24 + 72);
    *(_DWORD *)(v24 + 72) = v25 + 1;
    if ( !v25 )
    {
      snd_soc_component_update_bits(a1, v9, 255, v15);
      if ( a2 == 2 )
      {
        snd_soc_component_update_bits(a1, 1075314724, 28, 12);
        snd_soc_component_update_bits(a1, 1075314724, 128, 0);
        snd_soc_component_update_bits(a1, 1086326680, 255, v15);
        *(_DWORD *)(v8 + 368) = *(_DWORD *)(v10 + 36);
      }
      if ( (v34 & 1) == 0 )
        blocking_notifier_call_chain(*(_QWORD *)(v8 + 336) + 976LL, v31);
    }
    if ( (v12 & v11) != 1 )
      goto LABEL_37;
    v20 = *(_QWORD *)(v8 + 336);
    if ( !v20 )
      goto LABEL_37;
    v21 = v32;
  }
  else
  {
    if ( a3 != 3 )
    {
LABEL_52:
      dev_err(*(_QWORD *)(a1 + 24), "%s: Invalid req event: %d\n", "wcd9378_micbias_control", (unsigned int)a3);
      return 4294967274LL;
    }
    v18 = *(_DWORD *)(v8 + 72 + 4LL * (unsigned int)v7);
    v19 = v18 - 1;
    if ( v18 >= 1 )
    {
      --v18;
      *(_DWORD *)(v8 + 72 + 4 * v7) = v19;
    }
    if ( !v18 )
    {
      v27 = *(_DWORD *)(v8 + 4 * v7 + 84);
      if ( v27 < 1 )
      {
        if ( !v27 )
        {
          if ( (v34 & 1) == 0 )
          {
            v28 = *(_QWORD *)(v8 + 336);
            if ( v28 )
              blocking_notifier_call_chain(v28 + 976, 1);
          }
          snd_soc_component_update_bits(a1, v9, 255, 0);
          if ( a2 == 2 )
          {
            snd_soc_component_update_bits(a1, 1086326680, 255, 0);
            snd_soc_component_update_bits(a1, 1075314724, 28, 12);
            snd_soc_component_update_bits(a1, 1075314724, 128, 128);
            *(_DWORD *)(v8 + 368) = 0;
          }
          if ( (v34 & 1) == 0 )
          {
            v29 = *(_QWORD *)(v8 + 336);
            if ( v29 )
              blocking_notifier_call_chain(v29 + 976, v30);
          }
        }
      }
      else
      {
        snd_soc_component_update_bits(a1, 1075316147, v13, v13);
        if ( a2 == 2 )
          *(_DWORD *)(v8 + 368) = *(_DWORD *)(v10 + 36);
      }
    }
    if ( (v12 & v11) != 1 )
      goto LABEL_37;
    v20 = *(_QWORD *)(v8 + 336);
    if ( !v20 )
      goto LABEL_37;
    v21 = v33;
  }
  blocking_notifier_call_chain(v20 + 976, v21);
LABEL_37:
  mutex_unlock(v8 + 136);
  return 0;
}
