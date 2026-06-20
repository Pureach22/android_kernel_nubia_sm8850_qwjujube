__int64 __fastcall usb_cser_notify_complete(__int64 a1, __int64 a2)
{
  __int64 v2; // x20
  __int64 v4; // x0
  __int64 v5; // x1

  v2 = *(_QWORD *)(a2 + 56);
  v4 = raw_spin_lock_irqsave(v2 + 1068);
  *(_BYTE *)(v2 + 1463) = 0;
  v5 = v4;
  if ( *(_DWORD *)(a2 + 84) != -108 && *(_BYTE *)(v2 + 1464) )
  {
    *(_BYTE *)(v2 + 1464) = 0;
    raw_spin_unlock_irqrestore(v2 + 1068, v4);
    port_notify_serial_state(v2 + 1200);
    v5 = raw_spin_lock_irqsave(v2 + 1068);
  }
  return raw_spin_unlock_irqrestore(v2 + 1068, v5);
}
