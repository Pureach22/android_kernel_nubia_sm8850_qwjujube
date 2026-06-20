__int64 __fastcall qpnp_vib_overdrive_work(__int64 a1)
{
  __int64 v1; // x19
  unsigned int v3; // w0
  unsigned int updated; // w0

  v1 = a1 - 112;
  mutex_lock(a1 - 112);
  if ( *(_BYTE *)(a1 + 64) == 1 )
  {
    v3 = qpnp_vib_ldo_set_voltage(a1 - 568, *(unsigned int *)(a1 + 36));
    if ( (v3 & 0x80000000) != 0 )
    {
      printk(&unk_71B6, "qpnp_vib_overdrive_work", *(unsigned int *)(a1 + 36), v3);
      if ( *(_BYTE *)(a1 + 64) )
      {
        updated = regmap_update_bits_base(
                    *(_QWORD *)(a1 - 120),
                    (unsigned int)*(unsigned __int16 *)(a1 + 32) + 70,
                    128,
                    0,
                    0,
                    0,
                    0);
        if ( (updated & 0x80000000) != 0 )
          printk(&unk_707F, "qpnp_vib_ldo_enable", "disable", updated);
        else
          *(_BYTE *)(a1 + 64) = 0;
      }
    }
  }
  return mutex_unlock(v1);
}
