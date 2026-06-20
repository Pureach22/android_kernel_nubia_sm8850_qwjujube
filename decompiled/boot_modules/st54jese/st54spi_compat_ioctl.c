__int64 __fastcall st54spi_compat_ioctl(__int64 a1, unsigned int a2, unsigned int a3)
{
  __int64 result; // x0
  __int64 v6; // x19
  __int64 v7; // x20
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v10; // x8
  unsigned __int64 ioc_message; // x0
  int v12; // w21
  __int64 v13; // x2
  _QWORD *v14; // x8
  __int64 v15; // x9
  __int64 v16; // x10
  unsigned __int64 v17; // x22
  __int64 v18; // x0
  unsigned int v19; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v20; // [xsp+8h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (a2 & 0xC000FFFF) == 0x40006B00 )
  {
    _ReadStatusReg(SP_EL0);
    v6 = *(_QWORD *)(a1 + 32);
    raw_spin_lock_irq(v6 + 4);
    v7 = *(_QWORD *)(v6 + 8);
    if ( v7 && !get_device(*(_QWORD *)(v6 + 8)) )
      v7 = 0;
    raw_spin_unlock_irq(v6 + 4);
    v8 = *(_QWORD *)(v6 + 8);
    if ( !v8 )
      v8 = *(_QWORD *)(v6 + 16);
    v9 = dev_info(v8, "st54spi compat_ioctl cmd %d\n", a2);
    if ( v7 )
    {
      v19 = 0;
      if ( v6 && *(_DWORD *)(v6 + 128) && *(_QWORD *)(v6 + 184) )
      {
        v10 = ktime_get(v9) - *(_QWORD *)(v6 + 184);
        if ( v10 <= 9999999 )
          usleep_range_state(1000 * (10 - v10 / 1000000), 1000 * (11 - v10 / 1000000), 2);
        *(_QWORD *)(v6 + 184) = 0;
      }
      mutex_lock(v6 + 40);
      ioc_message = st54spi_get_ioc_message(a2, a3, &v19);
      if ( ioc_message < 0xFFFFFFFFFFFFF001LL )
      {
        if ( ioc_message )
        {
          v13 = v19;
          if ( v19 )
          {
            v14 = (_QWORD *)(ioc_message + 8);
            v15 = v19;
            do
            {
              v16 = *(unsigned int *)v14;
              --v15;
              *(v14 - 1) = *((unsigned int *)v14 - 2);
              *v14 = v16;
              v14 += 4;
            }
            while ( v15 );
          }
          v17 = ioc_message;
          v12 = st54spi_message(v6, ioc_message, v13);
          kfree(v17);
        }
        else
        {
          v12 = 0;
        }
      }
      else
      {
        v12 = ioc_message;
      }
      mutex_unlock(v6 + 40);
      put_device(v7);
      v18 = *(_QWORD *)(v6 + 8);
      if ( !v18 )
        v18 = *(_QWORD *)(v6 + 16);
      dev_info(v18, "st54spi compat_ioctl retval %d\n", v12);
      result = v12;
    }
    else
    {
      result = -108;
    }
  }
  else
  {
    result = st54spi_ioctl(a1, a2, a3);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
