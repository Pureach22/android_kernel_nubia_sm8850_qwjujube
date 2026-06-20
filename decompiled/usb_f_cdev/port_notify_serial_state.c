__int64 __fastcall port_notify_serial_state(__int64 a1)
{
  __int64 v1; // x19
  __int64 v3; // x1
  unsigned int v4; // w21
  __int64 v5; // x21
  __int64 v6; // x1
  __int64 *v7; // x22
  __int64 v8; // x9
  __int16 v9; // w8

  v1 = a1 - 132;
  v3 = raw_spin_lock_irqsave(a1 - 132);
  if ( !*(_BYTE *)(a1 + 263) )
  {
    *(_BYTE *)(a1 + 263) = 1;
    raw_spin_unlock_irqrestore(v1, v3);
    v5 = *(_QWORD *)(a1 + 240);
    v6 = raw_spin_lock_irqsave(v1);
    if ( *(_BYTE *)(a1 + 360) == 1 )
    {
      v7 = *(__int64 **)(a1 + 248);
      v8 = *v7;
      *((_DWORD *)v7 + 2) = 10;
      *(_DWORD *)v8 = 8353;
      v9 = *(unsigned __int8 *)(a1 + 265);
      *(_WORD *)(v8 + 6) = 2;
      *(_WORD *)(v8 + 4) = v9;
      *(_WORD *)(v8 + 8) = *(_WORD *)(a1 + 266);
      raw_spin_unlock_irqrestore(v1, v6);
      v4 = usb_ep_queue(v5, v7, 2080);
      if ( (v4 & 0x80000000) == 0 )
      {
LABEL_8:
        v3 = raw_spin_lock_irqsave(v1);
        goto LABEL_9;
      }
      printk(&unk_8D7C, "usb_cser_notify", a1 - 148, v4);
      v6 = raw_spin_lock_irqsave(v1);
      *(_BYTE *)(a1 + 263) = 0;
    }
    else
    {
      v4 = -19;
    }
    raw_spin_unlock_irqrestore(v1, v6);
    goto LABEL_8;
  }
  v4 = 0;
  *(_BYTE *)(a1 + 264) = 1;
LABEL_9:
  raw_spin_unlock_irqrestore(v1, v3);
  return v4;
}
