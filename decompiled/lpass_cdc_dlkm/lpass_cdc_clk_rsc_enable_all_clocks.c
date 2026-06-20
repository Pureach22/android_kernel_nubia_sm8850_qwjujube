__int64 __fastcall lpass_cdc_clk_rsc_enable_all_clocks(__int64 a1, char a2)
{
  __int64 rsc_clk_device_ptr; // x0
  __int64 v4; // x21
  __int64 v5; // x22
  __int64 v6; // x23
  __int64 v7; // x20
  void *v9; // x0

  if ( a1 )
  {
    rsc_clk_device_ptr = lpass_cdc_get_rsc_clk_device_ptr(*(_QWORD *)(a1 + 96));
    if ( rsc_clk_device_ptr )
    {
      v4 = *(_QWORD *)(rsc_clk_device_ptr + 152);
      if ( v4 )
      {
        mutex_lock(v4 + 8);
        v5 = 0;
        v6 = v4 + 104;
        while ( 1 )
        {
          v7 = *(_QWORD *)(v6 + v5);
          if ( (a2 & 1) != 0 )
          {
            if ( !v7 || (unsigned int)clk_prepare(*(_QWORD *)(v6 + v5)) || !(unsigned int)clk_enable(v7) )
              goto LABEL_6;
          }
          else
          {
            if ( !v7 || (_clk_is_enabled(*(_QWORD *)(v6 + v5)) & 1) == 0 )
              goto LABEL_6;
            v7 = *(_QWORD *)(v6 + v5);
            clk_disable(v7);
          }
          clk_unprepare(v7);
LABEL_6:
          v5 += 8;
          if ( v5 == 64 )
            return mutex_unlock(v4 + 8);
        }
      }
      v9 = &unk_D361;
    }
    else
    {
      v9 = &unk_D96C;
    }
  }
  else
  {
    v9 = &unk_DCD3;
  }
  return printk(v9, "lpass_cdc_clk_rsc_enable_all_clocks");
}
