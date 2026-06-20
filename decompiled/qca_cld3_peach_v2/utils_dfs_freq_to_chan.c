unsigned __int64 __fastcall utils_dfs_freq_to_chan(unsigned __int64 result)
{
  if ( (_DWORD)result )
  {
    if ( (unsigned int)(result - 2408) > 0x4B )
    {
      if ( (_DWORD)result == 2484 )
      {
        return 14;
      }
      else if ( (unsigned int)(result - 2408) > 0xA1F )
      {
        return (unsigned int)(result - 5000) / 5uLL;
      }
      else
      {
        return ((int)result - 2512) / 0x14u + 15;
      }
    }
    else
    {
      return (unsigned __int8)(result - 103) / 5u;
    }
  }
  return result;
}
