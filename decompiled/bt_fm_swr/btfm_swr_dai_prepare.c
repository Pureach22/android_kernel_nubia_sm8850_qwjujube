__int64 __fastcall btfm_swr_dai_prepare(__int64 a1, int a2, __int64 a3, unsigned int a4)
{
  __int64 v6; // x22
  __int64 result; // x0

  v6 = *(_QWORD *)(*(_QWORD *)a1 + 152LL);
  bt_soc_enable_status = 0;
  printk(&unk_786E, "btfm_swr_dai_prepare");
  if ( !v6 || !*(_QWORD *)(v6 + 40) )
  {
    printk(&unk_757F, "btfm_swr_dai_prepare");
    return 4294967274LL;
  }
  if ( (unsigned __int8)usecase_codec >= 0xFuLL )
  {
    printk(&unk_730A, "btfm_get_sampling_rate");
    goto LABEL_20;
  }
  if ( a2 != 48000 && a2 != 44100 )
    goto LABEL_15;
  if ( (unsigned __int8)usecase_codec <= 0xDu )
  {
    if ( ((1 << usecase_codec) & 0xDC0) != 0 )
    {
      a2 = 96000;
      goto LABEL_19;
    }
    if ( ((1 << usecase_codec) & 0x2024) == 0 )
    {
      if ( usecase_codec == 9 )
        a2 = 192000;
      goto LABEL_19;
    }
    a2 *= 2;
LABEL_15:
    if ( (unsigned __int8)(usecase_codec - 6) < 6u )
      a2 = dword_7DF0[(unsigned __int8)(usecase_codec - 6)];
  }
LABEL_19:
  printk(&unk_71A0, "btfm_get_sampling_rate");
LABEL_20:
  *(_DWORD *)(v6 + 20) = a2;
  if ( a4 >= 5 )
  {
    printk(&unk_720F, "btfm_swr_dai_prepare");
    return 4294967274LL;
  }
  result = btfm_swr_enable_port(
             *(_BYTE *)(*(_QWORD *)(v6 + 40) + 24LL * a4 + 24),
             *(_BYTE *)(v6 + 30),
             a2,
             0x686765666BuLL >> (8 * (unsigned __int8)a4));
  if ( (_DWORD)result )
  {
    if ( (_DWORD)result == -106 )
    {
      printk(&unk_7512, "btfm_swr_dai_prepare");
      return 0;
    }
  }
  else
  {
    bt_soc_enable_status = 1;
  }
  return result;
}
