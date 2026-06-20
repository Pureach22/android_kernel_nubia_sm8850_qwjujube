__int64 __fastcall btfm_get_sampling_rate(unsigned int *a1)
{
  unsigned int v1; // w3
  unsigned int v2; // w8

  v1 = *a1;
  v2 = (unsigned __int8)usecase_codec;
  if ( (unsigned __int8)usecase_codec >= 0xFu )
    return printk(&unk_872C, "btfm_get_sampling_rate", v1);
  if ( v1 != 48000 && v1 != 44100 )
    goto LABEL_9;
  if ( (unsigned __int8)usecase_codec > 0xBu )
    return printk(&unk_8581, "btfm_get_sampling_rate", codec_text[v2]);
  if ( ((1 << usecase_codec) & 0xDC0) == 0 )
  {
    if ( ((1 << usecase_codec) & 0x24) == 0 )
      goto LABEL_14;
    *a1 = 2 * v1;
LABEL_9:
    if ( v2 > 0xB )
      return printk(&unk_8581, "btfm_get_sampling_rate", codec_text[v2]);
    if ( ((1 << v2) & 0xDC0) != 0 )
      goto LABEL_11;
LABEL_14:
    if ( v2 != 9 )
      return printk(&unk_8581, "btfm_get_sampling_rate", codec_text[v2]);
    goto LABEL_12;
  }
LABEL_11:
  *a1 = 96000;
  if ( v2 == 9 )
LABEL_12:
    *a1 = 192000;
  return printk(&unk_8581, "btfm_get_sampling_rate", codec_text[v2]);
}
