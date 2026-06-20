__int64 __fastcall qpnp_vib_brightness_set(__int64 a1, int a2)
{
  unsigned int v3; // w20
  unsigned int v4; // w0
  __int64 result; // x0
  unsigned int updated; // w0
  __int64 v7; // x2
  __int64 v8; // x3
  unsigned int v9; // w20
  unsigned int v10; // w19
  __int64 v11; // x3
  __int64 v12; // x3

  *(_DWORD *)(a1 + 616) = a2;
  if ( !a2 )
  {
    if ( (*(_BYTE *)(a1 + 633) & 1) == 0 )
    {
      hrtimer_cancel(a1 + 504);
      cancel_work_sync(a1 + 568);
    }
    if ( !*(_BYTE *)(a1 + 632) )
      return 0;
    result = regmap_update_bits_base(
               *(_QWORD *)(a1 + 448),
               (unsigned int)*(unsigned __int16 *)(a1 + 600) + 70,
               128,
               0,
               0,
               0,
               0);
    if ( (result & 0x80000000) == 0 )
    {
      *(_BYTE *)(a1 + 632) = 0;
      return result;
    }
    v10 = result;
    printk(&unk_707F, "qpnp_vib_ldo_enable", "disable", (unsigned int)result);
    return v10;
  }
  v3 = *(_DWORD *)(a1 + 604);
  if ( (*(_BYTE *)(a1 + 633) & 1) == 0 )
  {
    v3 = *(_DWORD *)(a1 + 608);
    if ( !v3 )
    {
      if ( 2 * *(_DWORD *)(a1 + 604) >= 3544000 )
        v3 = 3544000;
      else
        v3 = 2 * *(_DWORD *)(a1 + 604);
    }
  }
  v4 = qpnp_vib_ldo_set_voltage(a1, v3);
  if ( (v4 & 0x80000000) != 0 )
  {
    v10 = v4;
    printk(&unk_71FB, "qpnp_vibrator_play_on", v3, v4);
LABEL_26:
    printk(&unk_70D0, "qpnp_vib_brightness_set", v10, v11);
    return v10;
  }
  if ( (*(_BYTE *)(a1 + 632) & 1) == 0 )
  {
    updated = regmap_update_bits_base(
                *(_QWORD *)(a1 + 448),
                (unsigned int)*(unsigned __int16 *)(a1 + 600) + 70,
                128,
                128,
                0,
                0,
                0);
    if ( (updated & 0x80000000) != 0 )
    {
      v10 = updated;
      printk(&unk_707F, "qpnp_vib_ldo_enable", "enable", updated);
    }
    else
    {
      result = qpnp_vib_ldo_poll_status(a1);
      if ( (result & 0x80000000) == 0 )
      {
        *(_BYTE *)(a1 + 632) = 1;
        if ( (*(_BYTE *)(a1 + 633) & 1) != 0 )
          return result;
        goto LABEL_19;
      }
      v10 = result;
      printk(&unk_7111, "qpnp_vib_ldo_enable", v7, v8);
    }
    printk(&unk_6EE5, "qpnp_vibrator_play_on", v10, v12);
    goto LABEL_26;
  }
  result = 0;
  if ( (*(_BYTE *)(a1 + 633) & 1) == 0 )
  {
LABEL_19:
    v9 = result;
    hrtimer_start_range_ns(a1 + 504, 30000000, 0, 1);
    return v9;
  }
  return result;
}
