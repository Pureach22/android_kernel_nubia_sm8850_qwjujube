__int64 __fastcall rpmh_rsc_mode_solver_set(__int64 a1, char a2)
{
  unsigned int v4; // w20

  if ( (unsigned int)raw_spin_trylock(a1 + 1120) )
  {
    if ( (a2 & 1) != 0 && (rpmh_rsc_ctrlr_is_busy(a1) & 1) != 0 )
    {
      v4 = -16;
    }
    else
    {
      *(_BYTE *)(a1 + 60) = a2 & 1;
      ipc_log_string(*(_QWORD *)(a1 + 1672), "solver mode set: %d", a2 & 1);
      v4 = 0;
    }
    raw_spin_unlock(a1 + 1120);
  }
  else
  {
    return (unsigned int)-16;
  }
  return v4;
}
