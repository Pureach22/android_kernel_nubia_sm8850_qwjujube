__int64 __fastcall tmc_disable_etr_sink(__int64 a1, char a2)
{
  __int64 v4; // x19
  int v5; // w8
  int v7; // w8
  __int64 v8; // x22

  v4 = *(_QWORD *)(*(_QWORD *)(a1 + 152) + 152LL);
  raw_spin_lock_irqsave(v4 + 104);
  if ( *(_BYTE *)(v4 + 112) == 1 || (v5 = *(_DWORD *)(a1 + 976) - 1, (*(_DWORD *)(a1 + 976) = v5) != 0) && (a2 & 1) == 0 )
  {
    raw_spin_unlock_irqrestore(v4 + 104);
    return 4294967280LL;
  }
  if ( !(unsigned int)*(_QWORD *)(a1 + 968) )
    __break(0x800u);
  v7 = *(_DWORD *)(v4 + 332);
  if ( v7 != 1 )
  {
    if ( v7 != 2 || *(_DWORD *)(*(_QWORD *)(v4 + 336) + 8LL) != 1 )
    {
      raw_spin_unlock_irqrestore(v4 + 104);
      tmc_usb_disable(*(_QWORD *)(v4 + 336));
      raw_spin_lock_irqsave(v4 + 104);
      goto LABEL_13;
    }
    raw_spin_unlock_irqrestore(v4 + 104);
    tmc_usb_disable(*(_QWORD *)(v4 + 336));
    raw_spin_lock_irqsave(v4 + 104);
  }
  _tmc_etr_disable_hw((_QWORD *)v4);
  coresight_disclaim_device(*(_QWORD *)(v4 + 16));
  *(_QWORD *)(v4 + 120) = 0;
LABEL_13:
  v8 = *(_QWORD *)(a1 + 968);
  *(_DWORD *)(v4 + 108) = -1;
  *(_QWORD *)(a1 + 968) = 0;
  *(_QWORD *)(v4 + 296) = 0;
  raw_spin_unlock_irqrestore(v4 + 104);
  if ( (_DWORD)v8 == 1 && *(_DWORD *)(v4 + 332) == 1 )
    tmc_etr_byte_cntr_stop(*(_QWORD *)(v4 + 304));
  return 0;
}
