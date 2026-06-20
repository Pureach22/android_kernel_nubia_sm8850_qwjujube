__int64 __fastcall wcd938x_mbhc_micb_adjust_voltage(__int64 a1, int a2, int a3)
{
  __int64 v5; // x22
  unsigned int v6; // w20
  char v7; // w0
  unsigned int v8; // w19
  unsigned int v9; // w21

  if ( (unsigned int)(a3 - 1) > 3 )
  {
    return (unsigned int)-22;
  }
  else
  {
    v5 = *(_QWORD *)(*(_QWORD *)(a1 + 24) + 152LL);
    v6 = dword_21DAC[a3 - 1];
    mutex_lock(v5 + 104);
    v7 = snd_soc_component_read(a1, v6);
    if ( (unsigned int)(a2 - 2851) > 0xFFFFF8C4 )
    {
      v9 = (unsigned __int16)(a2 - 1000) / 0x32u;
      if ( (v7 & 0x3F) != v9 )
      {
        if ( (v7 & 0xC0) == 0x40 )
        {
          snd_soc_component_update_bits(a1, v6, 192, 128);
          snd_soc_component_update_bits(a1, v6, 63, v9);
          snd_soc_component_update_bits(a1, v6, 192, 64);
          usleep_range_state(2000, 2100, 2);
        }
        else
        {
          snd_soc_component_update_bits(a1, v6, 63, v9);
        }
      }
      v8 = 0;
    }
    else
    {
      if ( (unsigned int)__ratelimit(&wcd938x_get_micb_vout_ctl_val__rs, "wcd938x_get_micb_vout_ctl_val") )
        printk(&unk_124B2, "wcd938x_get_micb_vout_ctl_val");
      v8 = -22;
    }
    mutex_unlock(v5 + 104);
  }
  return v8;
}
