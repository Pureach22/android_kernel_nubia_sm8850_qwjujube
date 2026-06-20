__int64 __fastcall st54spi_open(__int64 a1, __int64 a2)
{
  _UNKNOWN **v4; // x22
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x0
  unsigned int v9; // w19
  __int64 v11; // x0

  mutex_lock(&device_list_lock);
  v4 = &device_list;
  do
  {
    v4 = (_UNKNOWN **)*v4;
    if ( v4 == &device_list )
    {
      v9 = -6;
      goto LABEL_17;
    }
  }
  while ( *((_DWORD *)v4 - 6) != *(_DWORD *)(a1 + 76) );
  v5 = (__int64)*(v4 - 2);
  if ( *((_DWORD *)v4 + 16) )
  {
    if ( !v5 )
      v5 = (__int64)*(v4 - 1);
    dev_err(v5, "st54spi: already open\n");
    mutex_unlock(&device_list_lock);
    return (unsigned int)-16;
  }
  if ( !v5 )
    v5 = (__int64)*(v4 - 1);
  dev_info(v5, "st54spi: open\n");
  if ( !v4[9] )
  {
    v6 = _kmalloc_noprof((unsigned int)bufsiz, 3264);
    v4[9] = (_UNKNOWN *)v6;
    if ( !v6 )
    {
LABEL_15:
      v9 = -12;
LABEL_17:
      mutex_unlock(&device_list_lock);
      return v9;
    }
  }
  if ( !v4[10] )
  {
    v7 = _kmalloc_noprof((unsigned int)bufsiz, 3264);
    v4[10] = (_UNKNOWN *)v7;
    if ( !v7 )
    {
LABEL_14:
      kfree(v4[9]);
      v4[9] = nullptr;
      goto LABEL_15;
    }
  }
  if ( !v4[11] )
  {
    v8 = _kmalloc_noprof((unsigned int)bufsiz, 3520);
    v4[11] = (_UNKNOWN *)v8;
    if ( !v8 )
    {
      kfree(v4[10]);
      v4[10] = nullptr;
      goto LABEL_14;
    }
  }
  ++*((_DWORD *)v4 + 16);
  *(_QWORD *)(a2 + 32) = v4 - 3;
  nonseekable_open(a1, a2);
  mutex_unlock(&device_list_lock);
  v11 = (__int64)*(v4 - 2);
  if ( !v11 )
    v11 = (__int64)*(v4 - 1);
  dev_info(v11, "st54spi: open - force power on\n");
  st54spi_power_on(v4 - 3);
  st54spi_power_on_for_comm(v4 - 3);
  return 0;
}
