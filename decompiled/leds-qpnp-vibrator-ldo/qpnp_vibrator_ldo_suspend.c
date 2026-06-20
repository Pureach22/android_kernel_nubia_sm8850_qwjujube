__int64 __fastcall qpnp_vibrator_ldo_suspend(__int64 a1)
{
  __int64 v1; // x19
  unsigned int updated; // w0

  v1 = *(_QWORD *)(a1 + 152);
  mutex_lock(v1 + 456);
  if ( (*(_BYTE *)(v1 + 633) & 1) == 0 )
  {
    hrtimer_cancel(v1 + 504);
    cancel_work_sync(v1 + 568);
  }
  if ( *(_BYTE *)(v1 + 632) )
  {
    updated = regmap_update_bits_base(
                *(_QWORD *)(v1 + 448),
                (unsigned int)*(unsigned __int16 *)(v1 + 600) + 70,
                128,
                0,
                0,
                0,
                0);
    if ( (updated & 0x80000000) != 0 )
      printk(&unk_707F, "qpnp_vib_ldo_enable", "disable", updated);
    else
      *(_BYTE *)(v1 + 632) = 0;
  }
  mutex_unlock(v1 + 456);
  return 0;
}
