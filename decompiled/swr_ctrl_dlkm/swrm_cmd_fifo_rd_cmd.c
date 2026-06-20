__int64 __fastcall swrm_cmd_fifo_rd_cmd(
        __int64 a1,
        unsigned int *a2,
        unsigned __int8 a3,
        unsigned __int8 a4,
        unsigned __int16 a5,
        int a6)
{
  unsigned int v12; // w8
  int v13; // w8
  unsigned int v14; // w9
  int v15; // w27
  int v16; // w24
  unsigned int v17; // w0
  unsigned int v18; // w0
  unsigned int v19; // w0
  unsigned int v20; // w0

  mutex_lock(a1 + 8688);
  v12 = *(unsigned __int8 *)(a1 + 9048);
  if ( v12 == 15 )
  {
    v13 = 983040;
  }
  else
  {
    if ( v12 < 0xE )
      v14 = v12 + 1;
    else
      v14 = 0;
    *(_BYTE *)(a1 + 9048) = v14;
    v13 = v14 << 16;
  }
  v15 = v13 | a5;
  v16 = (a3 << 20) | (a6 << 24);
  if ( *(_QWORD *)(a1 + 9072) )
  {
    swr_master_write(a1, (*(_WORD *)(a1 + 9056) << 12) + 16420, v16 | v15);
  }
  else
  {
    swrm_wait_for_fifo_avail(a1, 0);
    usleep_range_state(100, 105, 2);
    swr_master_write(a1, (*(_WORD *)(a1 + 9056) << 12) + 16420, v16 | v15);
    usleep_range_state(250, 255, 2);
  }
  swrm_wait_for_fifo_avail(a1, 1);
  v17 = swr_master_read(a1, ((unsigned __int16)*(_DWORD *)(a1 + 9056) << 12) + 16448);
  *a2 = v17;
  if ( ((v17 >> 8) & 0xF) != *(_BYTE *)(a1 + 9048) )
  {
    usleep_range_state(500, 505, 2);
    v18 = swr_master_read(a1, ((unsigned __int16)*(_DWORD *)(a1 + 9056) << 12) + 16448);
    *a2 = v18;
    if ( ((v18 >> 8) & 0xF) != *(_BYTE *)(a1 + 9048) )
    {
      usleep_range_state(500, 505, 2);
      v19 = swr_master_read(a1, ((unsigned __int16)*(_DWORD *)(a1 + 9056) << 12) + 16448);
      *a2 = v19;
      if ( ((v19 >> 8) & 0xF) != *(_BYTE *)(a1 + 9048) )
      {
        usleep_range_state(500, 505, 2);
        swr_master_write(a1, (*(_WORD *)(a1 + 9056) << 12) + 16420, v16 | v15);
        v20 = swr_master_read(a1, ((unsigned __int16)*(_DWORD *)(a1 + 9056) << 12) + 16448);
        *a2 = v20;
        if ( ((v20 >> 8) & 0xF) != *(_BYTE *)(a1 + 9048) )
        {
          if ( (unsigned int)__ratelimit(&swrm_cmd_fifo_rd_cmd__rs, "swrm_cmd_fifo_rd_cmd") )
            dev_err(
              *(_QWORD *)(a1 + 8512),
              "%s: reg: 0x%x, cmd_id: 0x%x, \t\t\t\trcmd_id: 0x%x, dev_num: 0x%x, cmd_data: 0x%x\n",
              "swrm_cmd_fifo_rd_cmd",
              a5,
              a4,
              *(unsigned __int8 *)(a1 + 9048),
              a3,
              *a2);
          if ( (unsigned int)__ratelimit(&swrm_cmd_fifo_rd_cmd__rs_136, "swrm_cmd_fifo_rd_cmd") )
            dev_err(*(_QWORD *)(a1 + 8512), "%s: failed to read fifo\n", "swrm_cmd_fifo_rd_cmd");
        }
      }
    }
  }
  return mutex_unlock(a1 + 8688);
}
