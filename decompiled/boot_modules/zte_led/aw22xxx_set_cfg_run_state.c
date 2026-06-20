__int64 __fastcall aw22xxx_set_cfg_run_state(unsigned int a1)
{
  unsigned int v1; // w19
  int v3; // w20
  __int64 result; // x0
  int v5; // w9
  int v6; // w10

  v1 = HIBYTE(a1);
  printk(&unk_13125, "aw22xxx_set_cfg_run_state");
  v3 = (a1 >> 12) & 0xFFF;
  printk(&unk_12A70, "aw22xxx_set_cfg_run_state");
  result = printk(&unk_140EE, "aw22xxx_set_cfg_run_state");
  if ( v1 != 1 || v3 )
  {
    if ( v1 != 3 || v3 )
    {
      if ( v1 == 3 && v3 == 2 )
      {
        v5 = g_cfg_cur_state | 1;
      }
      else if ( v1 != 2 || v3 )
      {
        if ( v1 == 2 && (unsigned int)(v3 - 257) <= 3 )
        {
          v5 = g_cfg_cur_state | 4;
        }
        else
        {
          if ( v1 == 3 )
            v6 = 1;
          else
            v6 = 2;
          v5 = g_cfg_cur_state | v6;
        }
      }
      else
      {
        v5 = g_cfg_cur_state & 0xFFFFFFFB;
      }
    }
    else
    {
      v5 = g_cfg_cur_state & 0xFFFFFFFE;
    }
  }
  else
  {
    v5 = g_cfg_cur_state & 0xFFFFFFFD;
  }
  g_cfg_cur_state = v5;
  return result;
}
