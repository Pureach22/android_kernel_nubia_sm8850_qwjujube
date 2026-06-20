__int64 __fastcall sde_encoder_phys_arp_sw_timer_frequency_stepping(__int64 a1, int a2)
{
  unsigned int v2; // w19
  unsigned int **v3; // x9
  unsigned int v4; // w23
  int v7; // w10
  unsigned int v8; // w9
  __int64 v9; // x10
  unsigned int v10; // w8
  int v11; // w22

  v2 = *(_DWORD *)(*(_QWORD *)a1 + 4808LL);
  if ( !v2 )
    return printk(&unk_234DBD, "sde_encoder_phys_arp_sw_timer_frequency_stepping");
  v3 = *(unsigned int ***)(a1 + 2408);
  v4 = *(_DWORD *)(*(_QWORD *)a1 + 4812LL);
  if ( a2 )
  {
    *(_DWORD *)(a1 + 2360) = 0;
    v7 = 1;
    v8 = **v3;
  }
  else
  {
    v9 = *(unsigned int *)(a1 + 2360);
    if ( (unsigned int)v9 >= *((_DWORD *)v3 + 2) )
    {
      v10 = 0x3B9ACA00 / v2 - 0x3B9ACA00 / v4;
      goto LABEL_7;
    }
    v8 = (*v3)[v9];
    v7 = v9 + 1;
  }
  v10 = 0x3B9ACA00 / v8 - 0x3B9ACA00 / v4;
  *(_DWORD *)(a1 + 2360) = v7;
LABEL_7:
  v11 = v10;
  hrtimer_start_range_ns(a1 + 2416, v10, 0, 1);
  return sde_evtlog_log(
           sde_dbg_base_evtlog,
           "sde_encoder_phys_arp_sw_timer_frequency_stepping",
           6411,
           2,
           a2,
           v11,
           *(_DWORD *)(a1 + 2360),
           v2,
           v4);
}
