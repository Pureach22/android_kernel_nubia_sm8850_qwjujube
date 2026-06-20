__int64 __fastcall swrm_wait_for_fifo_avail(__int64 a1, int a2)
{
  __int64 result; // x0
  int v5; // w20
  unsigned int v7; // w9
  unsigned int v8; // w8
  int v9; // w20

  result = swr_master_read(a1, (*(_WORD *)(a1 + 9056) << 12) + 16464);
  if ( a2 )
  {
    if ( (result & 0x1F0000) == 0 )
    {
      v5 = -31;
      while ( !__CFADD__(v5++, 1) )
      {
        usleep_range_state(500, 510, 2);
        result = swr_master_read(a1, ((unsigned __int16)*(_DWORD *)(a1 + 9056) << 12) + 16464);
        if ( (result & 0x1F0000) != 0 )
          return result;
      }
      result = __ratelimit(&swrm_wait_for_fifo_avail__rs, "swrm_wait_for_fifo_avail");
      if ( (_DWORD)result )
        return dev_err(*(_QWORD *)(a1 + 8512), "%s err read underflow\n", "swrm_wait_for_fifo_avail");
    }
  }
  else
  {
    v7 = ((unsigned int)result >> 8) & 0x1F;
    v8 = *(_DWORD *)(a1 + 15892);
    if ( v7 == v8 )
    {
      v9 = -29;
      do
      {
        usleep_range_state(500, 510, 2);
        result = swr_master_read(a1, ((unsigned __int16)*(_DWORD *)(a1 + 9056) << 12) + 16464);
        v8 = *(_DWORD *)(a1 + 15892);
        v7 = ((unsigned int)result >> 8) & 0x1F;
      }
      while ( v7 >= v8 && v9++ != 0 );
    }
    if ( v7 == v8 )
    {
      result = __ratelimit(&swrm_wait_for_fifo_avail__rs_51, "swrm_wait_for_fifo_avail");
      if ( (_DWORD)result )
        return dev_err(*(_QWORD *)(a1 + 8512), "%s err write overflow\n", "swrm_wait_for_fifo_avail");
    }
  }
  return result;
}
