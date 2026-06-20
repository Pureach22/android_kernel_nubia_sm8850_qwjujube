void __fastcall sde_evtlog_dump_to_buffer(__int64 a1, __int64 a2)
{
  if ( a1 && a2 )
  {
    raw_spin_lock_irqsave(a1 + 786476);
    JUMPOUT(0x144CC4);
  }
  JUMPOUT(0x144E1C);
}
