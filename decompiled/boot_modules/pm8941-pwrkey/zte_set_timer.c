__int64 __fastcall zte_set_timer(__int64 *a1)
{
  int ftm_flag; // w0
  __int64 v3; // x9
  bool v4; // zf
  __int64 v5; // x0
  const char *v6; // x1

  ftm_flag = socinfo_get_ftm_flag();
  v3 = 750;
  v4 = ftm_flag == 0;
  if ( !ftm_flag )
    v3 = 2500;
  v5 = *a1;
  if ( v4 )
    v6 = "%s: Normal mode, reboot in 10 Secs\n";
  else
    v6 = "%s: FTM mode, reboot in 3 Secs\n";
  a1[15] = jiffies + v3;
  dev_info(v5, v6, "zte_set_timer");
  return mod_timer(a1 + 13, a1[15]);
}
