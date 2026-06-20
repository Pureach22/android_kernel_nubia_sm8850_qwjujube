unsigned __int64 __fastcall show_perf_gfx_evts(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned __int64 v4; // x20
  __int64 v5; // x1
  int v6; // w22
  int v7; // w23
  int v8; // w8
  unsigned int v9; // w8
  __int64 v10; // x8
  __int64 v11; // x1
  __int64 v12; // x2

  if ( (unsigned int)wait_for_completion_interruptible(&gfx_evt_arrival) )
    return 0;
  v5 = raw_spin_lock_irqsave(&gfx_circ_buff_lock);
  v6 = curr_pos_1;
  v7 = ((_WORD)curr_pos_0 - (_WORD)curr_pos_1) & 0x1FF;
  v8 = (v7 + curr_pos_1) & 0x1FF;
  if ( v7 + curr_pos_1 <= 0 )
    v8 = -(-(v7 + curr_pos_1) & 0x1FF);
  curr_pos_1 = v8;
  raw_spin_unlock_irqrestore(&gfx_circ_buff_lock, v5);
  v4 = 0;
  if ( v7 )
  {
    while ( 1 )
    {
      if ( v6 <= 0 )
        v9 = -(-v6 & 0x1FF);
      else
        v9 = v6 & 0x1FF;
      if ( v9 >= 0x200 )
        goto LABEL_19;
      if ( ((32LL * v9) | 4uLL) > 0x4000
        || (v10 = 32LL * v9, (v10 | 8uLL) > 0x4000)
        || (v10 | 0x18uLL) > 0x4000
        || (v10 | 0x10uLL) > 0x4000 )
      {
        __break(1u);
LABEL_19:
        __break(0x5512u);
        JUMPOUT(0x73B4);
      }
      v4 += (int)scnprintf(
                   a3 + v4,
                   4096 - v4,
                   "%d %d %u %d %lld :",
                   *(_DWORD *)((char *)&gpu_circ_buff + v10),
                   *(_DWORD *)((char *)&gpu_circ_buff + v10 + 4),
                   *(_DWORD *)((char *)&gpu_circ_buff + v10 + 8),
                   *(_DWORD *)((char *)&gpu_circ_buff + v10 + 24),
                   *(_QWORD *)((char *)&gpu_circ_buff + v10 + 16) / 1000LL);
      if ( v4 >= 0x1000 )
        break;
      --v7;
      ++v6;
      if ( !v7 )
        return v4;
    }
    printk(&unk_BB3C, v11, v12);
  }
  return v4;
}
