void ipi_entry()
{
  __int64 v0; // x8
  _BYTE *v1; // x19
  __int64 v2; // x0

  if ( (suspend_in_progress & 1) == 0 )
  {
    v0 = *(unsigned int *)(_ReadStatusReg(SP_EL0) + 40);
    if ( (unsigned int)v0 >= 0x20 )
    {
      __break(0x5512u);
      lpm_idle_enter();
    }
    else
    {
      v1 = &lpm_cpu_data[_per_cpu_offset[v0]];
      if ( *((_DWORD *)v1 + 1) )
      {
        v2 = raw_spin_lock_irqsave(v1 + 320);
        v1[316] = 0;
        raw_spin_unlock_irqrestore(v1 + 320, v2);
      }
    }
  }
}
