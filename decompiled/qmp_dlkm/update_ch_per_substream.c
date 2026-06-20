__int64 __fastcall update_ch_per_substream(int a1, __int64 a2)
{
  __int64 result; // x0
  __int64 v4; // x3

  result = get_matching_stream_index_or_first_available(a2);
  if ( (result & 0x80000000) != 0 )
    return printk(&unk_A95C, "update_ch_per_substream", (unsigned int)result, v4);
  if ( a1 )
  {
    if ( (unsigned int)result <= 8 )
    {
      ++num_chs[(unsigned int)result];
      return result;
    }
    goto LABEL_9;
  }
  if ( (unsigned int)result > 8 )
  {
LABEL_9:
    __break(1u);
    return get_matching_stream_index_or_first_available(result);
  }
  num_chs[(unsigned int)result] = 0;
  return result;
}
