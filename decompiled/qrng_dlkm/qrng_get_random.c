__int64 __fastcall qrng_get_random(__int64 a1, __int64 a2, __int64 a3, _DWORD *a4, unsigned int a5)
{
  _QWORD *StatusReg; // x8
  unsigned int v8; // w19

  if ( msm_rng_dev_cached )
  {
    if ( a4 )
    {
      StatusReg = (_QWORD *)_ReadStatusReg(SP_EL0);
      if ( (*StatusReg & 0x40) != 0 || (*StatusReg & 1) != 0 || (unsigned int)mutex_lock_interruptible(&cached_rng_lock) )
      {
        printk(&unk_6DA7);
        return (unsigned int)-512;
      }
      else if ( (*(_BYTE *)(msm_rng_dev_cached + 80) & 1) != 0 )
      {
        mutex_unlock(&cached_rng_lock);
        printk(&unk_6DC5);
        return (unsigned int)-14;
      }
      else
      {
        if ( (unsigned int)msm_rng_direct_read(msm_rng_dev_cached, a4, a5) == a5 )
          v8 = 0;
        else
          v8 = -14;
        mutex_unlock(&cached_rng_lock);
      }
    }
    else
    {
      printk(&unk_6E60);
      return (unsigned int)-22;
    }
  }
  else
  {
    printk(&unk_6EEE);
    return (unsigned int)-19;
  }
  return v8;
}
