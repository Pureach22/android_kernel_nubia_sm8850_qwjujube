__int64 __fastcall pm8941_pwrkey_irq(__int64 a1, __int64 *a2)
{
  int v3; // w8
  int v4; // w10
  int v5; // w8
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x2
  _BOOL8 v9; // x3
  int ftm_flag; // w0
  __int64 v12; // x9
  bool v13; // zf
  __int64 v14; // x0
  const char *v15; // x1
  int v16; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v17; // [xsp+8h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *((_DWORD *)a2 + 19);
  v16 = 0;
  if ( (!v3 || ktime_get() >= a2[10])
    && !(unsigned int)regmap_read(a2[3], (unsigned int)(*((_DWORD *)a2 + 3) + 16), &v16) )
  {
    v4 = *((_DWORD *)a2 + 19);
    v5 = v16 & *(_DWORD *)(a2[12] + 4);
    v16 = v5;
    if ( v4 && !v5 )
    {
      v6 = ktime_get();
      v5 = v16;
      a2[10] = v6 + 1000LL * *((unsigned int *)a2 + 19);
    }
    if ( (*((_BYTE *)a2 + 92) & 1) == 0 && !v5 )
    {
      input_event(a2[4], 1, *((unsigned int *)a2 + 18), 1);
      input_event(a2[4], 0, 0, 0);
      v5 = v16;
    }
    v7 = a2[4];
    v8 = *((unsigned int *)a2 + 18);
    v9 = v5 != 0;
    *((_BYTE *)a2 + 92) = v9;
    input_event(v7, 1, v8, v9);
    input_event(a2[4], 0, 0, 0);
    if ( !strcmp(*(const char **)a2[4], "pmic_resin") )
    {
      dev_err(*a2, "skip zte set timer part 2\n");
    }
    else if ( v16 )
    {
      ftm_flag = socinfo_get_ftm_flag();
      v12 = 750;
      v13 = ftm_flag == 0;
      if ( !ftm_flag )
        v12 = 2500;
      v14 = *a2;
      if ( v13 )
        v15 = "%s: Normal mode, reboot in 10 Secs\n";
      else
        v15 = "%s: FTM mode, reboot in 3 Secs\n";
      a2[15] = v12 + jiffies;
      dev_info(v14, v15, "zte_set_timer");
      mod_timer(a2 + 13, a2[15]);
    }
    else
    {
      timer_delete(a2 + 13);
    }
  }
  _ReadStatusReg(SP_EL0);
  return 1;
}
