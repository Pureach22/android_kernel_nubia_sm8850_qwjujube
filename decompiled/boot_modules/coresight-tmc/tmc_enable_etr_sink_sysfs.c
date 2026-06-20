unsigned __int64 __fastcall tmc_enable_etr_sink_sysfs(__int64 a1)
{
  __int64 v2; // x19
  unsigned __int64 result; // x0
  unsigned __int64 v4; // x22
  unsigned int v5; // w23
  int v6; // w8
  unsigned int v7; // w0
  __int64 v8; // x0
  int v9; // w8

  v2 = *(_QWORD *)(*(_QWORD *)(a1 + 152) + 152LL);
  result = tmc_etr_get_sysfs_buffer(a1);
  v4 = result;
  if ( result >= 0xFFFFFFFFFFFFF001LL )
    return (unsigned int)result;
  raw_spin_lock_irqsave(v2 + 104);
  if ( (unsigned int)*(_QWORD *)(a1 + 968) == 1 )
  {
    v5 = 0;
    ++*(_DWORD *)(a1 + 976);
    goto LABEL_15;
  }
  v6 = *(_DWORD *)(v2 + 332);
  if ( v6 == 1 || v6 == 2 && *(_DWORD *)(*(_QWORD *)(v2 + 336) + 8LL) == 1 )
  {
    if ( !v4 || *(_DWORD *)(v4 + 4) == 1 && (*(_BYTE *)(v2 + 204) & 1) == 0 )
    {
      __break(0x800u);
      v5 = -22;
      goto LABEL_15;
    }
    if ( *(_QWORD *)(v2 + 120) )
    {
      v5 = -16;
      __break(0x800u);
      goto LABEL_15;
    }
    v5 = coresight_claim_device(*(_QWORD *)(v2 + 16));
    if ( v5 )
    {
LABEL_15:
      raw_spin_unlock_irqrestore(v2 + 104);
      return v5;
    }
    *(_QWORD *)(v2 + 120) = v4;
    v7 = _tmc_etr_enable_hw(v2);
    if ( v7 )
    {
      v5 = v7;
      v8 = *(_QWORD *)(v2 + 16);
      *(_QWORD *)(v2 + 120) = 0;
      coresight_disclaim_device(v8);
      goto LABEL_15;
    }
  }
  if ( (*(_QWORD *)(a1 + 968) & 0xFFFFFFFELL) != 0 )
  {
    _warn_printk("Device already in use\n");
    __break(0x800u);
  }
  *(_QWORD *)(a1 + 968) = 1;
  ++*(_DWORD *)(a1 + 976);
  raw_spin_unlock_irqrestore(v2 + 104);
  v9 = *(_DWORD *)(v2 + 332);
  if ( v9 == 1 )
  {
    tmc_etr_byte_cntr_start(*(_QWORD *)(v2 + 304));
    v9 = *(_DWORD *)(v2 + 332);
  }
  if ( v9 == 2 )
    tmc_usb_enable(*(_QWORD *)(v2 + 336));
  return 0;
}
