__int64 __fastcall btfm_slim_dai_prepare(__int64 a1, unsigned int a2, __int16 a3, unsigned int a4)
{
  __int64 v5; // x8
  int v6; // w20
  __int64 v7; // x21
  bool v8; // cf
  __int64 v9; // x2
  _DWORD *v10; // x8
  __int64 v11; // x1
  int v12; // w9
  int v13; // w9
  _DWORD *v14; // x9
  _DWORD *v15; // x8
  int v16; // w10
  int v17; // t1
  __int64 result; // x0
  __int64 v20; // x2

  v5 = (unsigned __int8)usecase_codec;
  v6 = a2;
  v7 = *(_QWORD *)(*(_QWORD *)a1 + 152LL);
  bt_soc_enable_status = 0;
  v8 = (unsigned __int8)usecase_codec >= 0xFuLL;
  *(_WORD *)(v7 + 1092) = a3;
  if ( v8 )
  {
    printk(&unk_872C, "btfm_get_sampling_rate", a2);
    goto LABEL_16;
  }
  if ( a2 != 48000 && a2 != 44100 )
    goto LABEL_11;
  if ( (unsigned int)v5 <= 0xB )
  {
    if ( ((1 << v5) & 0xDC0) != 0 )
    {
      v6 = 96000;
      goto LABEL_15;
    }
    if ( ((1 << v5) & 0x24) == 0 )
    {
      if ( (_DWORD)v5 == 9 )
        v6 = 192000;
      goto LABEL_15;
    }
    v6 = 2 * a2;
LABEL_11:
    if ( (unsigned __int8)(v5 - 6) < 6u )
      v6 = dword_9200[(unsigned __int8)(v5 - 6)];
  }
LABEL_15:
  printk(&unk_8581, "btfm_get_sampling_rate", codec_text[v5]);
LABEL_16:
  *(_DWORD *)(v7 + 1084) = v6;
  if ( a4 >= 4 )
  {
    printk(&unk_8B03, "btfm_slim_dai_prepare", a4);
    return 4294967274LL;
  }
  v10 = *(_DWORD **)((char *)*(&off_9350 + a4) + v7);
  if ( *v10 == 4 || *v10 == a4 )
  {
    v11 = *(_QWORD *)((char *)*(&off_9350 + a4) + v7);
  }
  else
  {
    v11 = (__int64)(v10 + 18);
    v12 = v10[18];
    if ( v12 != 4 && v12 != a4 )
    {
      v11 = (__int64)(v10 + 36);
      v13 = v10[36];
      if ( v13 != 4 && v13 != a4 )
      {
        v14 = v10 + 72;
        v17 = v10[54];
        v15 = v10 + 54;
        v16 = v17;
        if ( v17 == a4 || v16 == 4 )
          v11 = (__int64)v15;
        else
          v11 = (__int64)v14;
      }
    }
  }
  if ( *(_WORD *)(v11 + 16) == 255 || *(_DWORD *)v11 == 4 )
  {
    printk(&unk_8859, "btfm_slim_dai_prepare", v9);
    return 4294967274LL;
  }
  result = btfm_slim_enable_ch(v7, v11, 0x1010000u >> (8 * a4), v6, 0x1010102u >> (8 * a4));
  if ( (_DWORD)result )
  {
    if ( (_DWORD)result == -106 )
    {
      printk(&unk_8A34, "btfm_slim_dai_prepare", v20);
      return 0;
    }
  }
  else
  {
    bt_soc_enable_status = 1;
  }
  return result;
}
