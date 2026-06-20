__int64 __fastcall sde_power_data_bus_set_quota(__int64 a1, unsigned int a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x21

  if ( a1 && a2 < 4 )
  {
    v4 = a1 + 40LL * a2;
    if ( *(_DWORD *)(v4 + 216) )
    {
      mutex_lock(a1 + 48);
      LODWORD(a4) = sde_power_data_bus_set_quota(v4 + 184, a3, a4);
      mutex_unlock(a1 + 48);
      return (unsigned int)a4;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    printk(&unk_22B9D4, "sde_power_data_bus_set_quota");
    return 4294967274LL;
  }
}
