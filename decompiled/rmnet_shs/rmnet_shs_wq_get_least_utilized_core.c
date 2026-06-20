__int64 __fastcall rmnet_shs_wq_get_least_utilized_core(__int64 cpus_taken)
{
  unsigned int v1; // w19
  char v2; // w8
  char v3; // w19

  if ( (cpus_taken & 0x80) == 0
    || (_cpu_active_mask & 0x80) == 0
    || (v1 = cpus_taken, v2 = walt_get_cpus_taken(), cpus_taken = v1, v2 < 0) )
  {
    v3 = cpus_taken;
    if ( (cpus_taken & 0x40) == 0
      || (_cpu_active_mask & 0x40) == 0
      || (cpus_taken = walt_get_cpus_taken(), (cpus_taken & 0x40) != 0) )
    {
      if ( (v3 & 0x20) == 0
        || (_cpu_active_mask & 0x20) == 0
        || (cpus_taken = walt_get_cpus_taken(), (cpus_taken & 0x20) != 0) )
      {
        if ( (v3 & 0x10) == 0
          || (_cpu_active_mask & 0x10) == 0
          || (cpus_taken = walt_get_cpus_taken(), (cpus_taken & 0x10) != 0) )
        {
          if ( (v3 & 8) == 0
            || (_cpu_active_mask & 8) == 0
            || (cpus_taken = walt_get_cpus_taken(), (cpus_taken & 8) != 0) )
          {
            if ( (v3 & 4) == 0
              || (_cpu_active_mask & 4) == 0
              || (cpus_taken = walt_get_cpus_taken(), (cpus_taken & 4) != 0) )
            {
              if ( (v3 & 2) == 0
                || (_cpu_active_mask & 2) == 0
                || (cpus_taken = walt_get_cpus_taken(), (cpus_taken & 2) != 0) )
              {
                if ( (v3 & 1) == 0 )
                  return 0xFFFFFFFFLL;
                if ( (_cpu_active_mask & 1) == 0 )
                  return 0xFFFFFFFFLL;
                cpus_taken = walt_get_cpus_taken();
                if ( (cpus_taken & 1) != 0 )
                  return 0xFFFFFFFFLL;
              }
            }
          }
        }
      }
    }
  }
  __break(1u);
  return rmnet_shs_wq_try_to_move_flow(cpus_taken);
}
