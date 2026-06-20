__int64 __fastcall swrm_cmd_fifo_wr_cmd(
        __int64 a1,
        int a2,
        unsigned __int8 a3,
        unsigned __int8 a4,
        unsigned __int16 a5)
{
  unsigned int v10; // w9
  int v11; // w23
  int v12; // w25
  unsigned __int8 v13; // w8
  unsigned int v14; // w9

  mutex_lock(a1 + 8688);
  if ( a4 == 15 )
  {
    v11 = 1;
    v12 = 983040;
  }
  else if ( a4 )
  {
    if ( a4 < 0xEu )
      v13 = a4 + 1;
    else
      v13 = 0;
    v11 = 0;
    v12 = v13 << 16;
  }
  else
  {
    v10 = *(unsigned __int8 *)(a1 + 9049);
    if ( v10 == 15 )
    {
      v11 = 0;
      v12 = 983040;
    }
    else
    {
      v11 = 0;
      if ( v10 < 0xE )
        v14 = v10 + 1;
      else
        v14 = 0;
      *(_BYTE *)(a1 + 9049) = v14;
      v12 = v14 << 16;
    }
  }
  swrm_wait_for_fifo_avail(a1, 0);
  swr_master_write(a1, (*(_WORD *)(a1 + 9056) << 12) + 16416, a5 | (a2 << 24) | (a3 << 20) | v12);
  if ( *(_QWORD *)(a1 + 9080) )
  {
    if ( !v11 )
      return mutex_unlock(a1 + 8688);
  }
  else
  {
    usleep_range_state(150, 155, 2);
    if ( !v11 )
      return mutex_unlock(a1 + 8688);
  }
  if ( *(_DWORD *)(a1 + 9128) == 17039360 )
    usleep_range_state(10000, 10100, 2);
  else
    wait_for_completion_timeout(a1 + 8608, 50);
  return mutex_unlock(a1 + 8688);
}
