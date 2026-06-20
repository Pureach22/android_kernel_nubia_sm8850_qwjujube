_QWORD *__fastcall msm_perf_events_update(_QWORD *result, int a2, int a3, int a4, int a5, char a6)
{
  __int64 v10; // x1
  __int64 v11; // x25
  int v12; // w9
  __int64 v13; // x13
  __int64 v14; // x24
  char *v15; // x19

  if ( !(_DWORD)result && a5 && game_status_pid == a3 && (a6 & 1) != 0 )
  {
    v10 = raw_spin_lock_irqsave(&gfx_circ_buff_lock);
    v11 = (unsigned int)curr_pos_0;
    v12 = (curr_pos_0 + 1) & 0x1FF;
    if ( curr_pos_0 + 1 <= 0 )
      v12 = -(-(curr_pos_0 + 1) & 0x1FF);
    curr_pos_0 = v12;
    result = (_QWORD *)raw_spin_unlock_irqrestore(&gfx_circ_buff_lock, v10);
    if ( (unsigned int)v11 < 0x200 )
    {
      v14 = 32 * v11;
      v15 = (char *)&gpu_circ_buff + 32 * v11;
      *(_DWORD *)v15 = a3;
      if ( ((32LL * (unsigned int)v11) | 4uLL) <= 0x4000 )
      {
        *((_DWORD *)v15 + 1) = a4;
        if ( (v14 | 8uLL) <= 0x4000 )
        {
          *((_DWORD *)v15 + 2) = a5;
          if ( (v14 | 0x18uLL) <= 0x4000 )
          {
            *((_DWORD *)v15 + 6) = a2;
            result = (_QWORD *)ktime_get(result);
            if ( (v14 | 0x10uLL) <= 0x4000 )
            {
              *((_QWORD *)v15 + 2) = result;
              if ( (a2 & 0xFFFFFFFD) == 1 )
                return (_QWORD *)complete(&gfx_evt_arrival);
              return result;
            }
          }
        }
      }
      __break(1u);
    }
    __break(0x5512u);
    *result = v13;
    return (_QWORD *)hotplug_notify_up((char *)result + 217);
  }
  return result;
}
