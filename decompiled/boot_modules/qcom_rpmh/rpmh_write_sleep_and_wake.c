__int64 __fastcall rpmh_write_sleep_and_wake(__int64 a1)
{
  __int64 v1; // x19
  unsigned int channel; // w20
  __int64 v3; // x21
  unsigned int v4; // w22
  __int64 result; // x0

  v1 = *(_QWORD *)(*(_QWORD *)(a1 + 96) + 152LL);
  channel = rpmh_rsc_get_channel(v1);
  if ( (channel & 0x80000000) != 0 )
    return channel;
  if ( (rpmh_standalone & 1) != 0
    || (v3 = raw_spin_lock_irqsave(v1 + 1152),
        v4 = rpmh_flush(v1 + 1152, channel),
        raw_spin_unlock_irqrestore(v1 + 1152, v3),
        (result = v4) == 0) )
  {
    if ( (*(_BYTE *)(v1 + 1160) & 2) != 0 )
      return rpmh_rsc_switch_channel((_QWORD *)v1, channel);
    else
      return 0;
  }
  return result;
}
