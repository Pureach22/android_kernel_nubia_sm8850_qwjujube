__int64 __fastcall cdsprm_resmgr_pdkill_state_show(__int64 a1)
{
  const char *v1; // x1
  __int64 v2; // x2

  if ( dword_99B0 )
  {
    if ( dword_99A8 )
    {
      v1 = "\nresmgr pdkill feature is enabled\n";
      v2 = 34;
    }
    else
    {
      v1 = "\nresmgr pdkill feature is enabled by debugfs override\n";
      v2 = 54;
    }
  }
  else if ( dword_99A8 )
  {
    v1 = "\nresmgr pdkill feature is disabled by debugfs override\n";
    v2 = 55;
  }
  else
  {
    v1 = "\nresmgr pdkill feature is disabled\n";
    v2 = 35;
  }
  seq_write(a1, v1, v2);
  return 0;
}
