__int64 zsw_pm_resume_calculate_wakepercent()
{
  __int64 result; // x0
  unsigned __int64 v1; // x0
  __int64 v2; // x21
  __int64 v3; // x19
  unsigned __int64 v4; // x8
  __int64 v5; // x24
  unsigned __int64 v6; // x19
  _UNKNOWN **v7; // x11
  _UNKNOWN **v8; // x20
  char *v9; // x20
  unsigned __int64 v10; // x8
  unsigned __int64 v11; // x9
  unsigned int v12; // w3
  bool v13; // cf
  unsigned __int64 v14; // x10
  unsigned __int64 v15; // x8
  unsigned __int64 v16; // x1
  unsigned int v17; // w9
  _UNKNOWN **v18; // x19
  __int64 real_seconds; // x0
  unsigned __int64 v20; // x0
  unsigned __int64 v21; // x8
  const char *v22; // x28
  unsigned __int64 v23; // x8
  __int64 v24; // x0
  int *v25; // x8
  int *v26; // x9
  int v27; // w8
  __int64 v28; // x19
  unsigned __int64 v29; // x0
  int v30; // w8
  unsigned __int64 v31; // x1
  unsigned __int64 v32; // x28
  char v33; // w19
  int v34; // w8
  const char *v35; // x28
  char v36; // w1
  int v37; // w8
  unsigned __int64 v38; // [xsp+8h] [xbp-28h]
  unsigned __int64 v39; // [xsp+20h] [xbp-10h]
  char v40; // [xsp+2Ch] [xbp-4h]

  if ( zsw_getsmem_error == 1 )
    return printk(&unk_A7CD);
  if ( !screenofftime_startpoint || screenofftime_endpoint )
  {
    screenofftime_delta = 0;
  }
  else
  {
    v1 = ((__int64 (*)(void))ktime_get_real_seconds)();
    v2 = screenofftime_delta;
    v3 = v1;
    v4 = v1 - screenofftime_startpoint;
    if ( v1 > screenofftime_startpoint )
    {
      screenofftime_delta = v1 - screenofftime_startpoint;
    }
    else
    {
      screenofftime_delta = 0;
      printk(&unk_A15B);
      v4 = screenofftime_delta;
    }
    if ( v4 > v2 + 3600 )
    {
      screenofftime_delta = 0;
      screenofftime_startpoint = v3;
      printk(&unk_A5D3);
    }
    printk(&unk_A521);
  }
  result = printk(&unk_9C1A);
  v5 = 0;
  v6 = 0;
  v7 = &off_9000;
  v40 = 0;
  sleep_zswsubsys_flag = 0;
  sleep_zswresumeparam_mask = 99;
  do
  {
    v9 = (char *)&subsystems_zte + v5;
    if ( *(_DWORD *)((char *)&subsystems_zte + v5 + 16) == 1 )
    {
      v10 = *((_QWORD *)v9 + 3);
      v11 = *((_QWORD *)v9 + 4);
      v12 = 0;
      v13 = v11 >= v10;
      v14 = v11 - v10;
      v15 = (unsigned __int64)v7[195];
      if ( v13 )
        v16 = v14;
      else
        v16 = 0;
      if ( v11 && v15 && v16 < v15 )
        v12 = 100 - 100 * v16 / v15;
      if ( zsw_getsmem_error == 1 )
        goto LABEL_13;
      v17 = trigger_wakepercent;
      if ( (unsigned int)trigger_wakepercent >= 0x65 )
      {
        v17 = 80;
        trigger_wakepercent = 80;
      }
      if ( v12 <= v17 && forcetrigger_which < 1 )
      {
        if ( v15 )
          *(_QWORD *)((char *)&subsystems_zte + v5 + 40) = 0;
        goto LABEL_70;
      }
      v39 = v6;
      if ( !*(_QWORD *)((char *)&subsystems_zte + v5 + 40) )
      {
        v18 = v7;
        real_seconds = ktime_get_real_seconds(result);
        v7 = v18;
        v6 = v39;
        *(_QWORD *)((char *)&subsystems_zte + v5 + 40) = real_seconds;
LABEL_70:
        sleep_zswresumeparam_mask = 99;
LABEL_13:
        v8 = v7;
        result = printk(&unk_A898);
        v7 = v8;
        goto LABEL_14;
      }
      if ( time_screen_off <= 0 )
        time_screen_off = 1;
      v20 = ktime_get_real_seconds(result);
      v21 = *(_QWORD *)((char *)&subsystems_zte + v5 + 40);
      v22 = *(const char **)v9;
      v13 = v20 >= v21;
      v23 = v20 - v21;
      if ( !v13 )
        v23 = 0;
      v38 = v23;
      v24 = strcmp(*(const char **)v9, "adsp");
      if ( (_DWORD)v24 )
      {
        v24 = strcmp(v22, "cdsp");
        v25 = &time_subsyswake;
        if ( !(_DWORD)v24 )
          v25 = &time_subsyswake_cdsp;
        v26 = &time_screen_off;
        if ( !(_DWORD)v24 )
          v26 = &time_screen_off_cdsp;
      }
      else
      {
        v25 = &time_subsyswake_adsp;
        v26 = &time_screen_off_adsp;
      }
      if ( screenofftime_delta > (unsigned __int64)(60 * *v26) )
      {
        v27 = *v25;
        if ( time_subsyswake <= 0 )
          time_subsyswake = 1;
        if ( v38 > 60 * v27 )
        {
          *(_QWORD *)((char *)&subsystems_zte + v5 + 40) = 0;
          if ( forcetrigger_which <= 0 )
          {
LABEL_50:
            v28 = zswtrigercrashtime_start;
            v29 = ktime_get_real_seconds(v24);
            if ( v28 )
            {
              v30 = time_nexttrigger;
              if ( v29 >= zswtrigercrashtime_start )
                v31 = v29 - zswtrigercrashtime_start;
              else
                v31 = 0;
              if ( time_nexttrigger <= 0 )
              {
                v30 = 1;
                time_nexttrigger = 1;
              }
              v32 = v31;
              v33 = (v31 > 60 * v30) | v40;
              printk(&unk_A41D);
              if ( (v33 & 1) == 0 )
              {
                v40 = 0;
                v6 = v32;
                sleep_zswresumeparam_mask = 99;
LABEL_72:
                v7 = &off_9000;
                goto LABEL_13;
              }
              v6 = v32;
            }
            else
            {
              zswtrigercrashtime_start = v29;
              v6 = v39;
              printk(&unk_9814);
            }
            sleep_zswresumeparam_mask = 99;
            v34 = forcetrigger_which - 1;
            if ( forcetrigger_which >= 1 )
            {
              if ( (unsigned int)forcetrigger_which < 9 && ((0x8Bu >> v34) & 1) != 0 )
                sleep_zswsubsys_flag |= dword_A92C[v34];
              result = printk(&unk_A350);
              goto LABEL_74;
            }
            v35 = *(const char **)v9;
            if ( !strcmp(*(const char **)v9, "cdsp") )
              sleep_zswsubsys_flag |= 8u;
            if ( !strcmp(v35, "slpi") )
              sleep_zswsubsys_flag |= 4u;
            if ( !strcmp(v35, "adsp") )
              sleep_zswsubsys_flag |= 2u;
            if ( !strcmp(v35, "modem") )
              sleep_zswsubsys_flag |= 1u;
            v40 = 1;
            goto LABEL_72;
          }
LABEL_49:
          v24 = printk(&unk_A797);
          goto LABEL_50;
        }
        if ( forcetrigger_which >= 1 )
          goto LABEL_49;
      }
      v7 = &off_9000;
      goto LABEL_70;
    }
LABEL_14:
    v5 += 48;
  }
  while ( v5 != 960 );
  if ( (v40 & 1) == 0 )
    goto LABEL_75;
LABEL_74:
  result = ktime_get_real_seconds(result);
  zswtrigercrashtime_start = result + 1;
LABEL_75:
  v36 = sleep_zswsubsys_flag;
  if ( (sleep_zswsubsys_flag & 1) != 0 )
  {
    if ( (sleep_zswsubsys_flag & 2) != 0 )
    {
      if ( (sleep_zswsubsys_flag & 4) != 0 )
        goto LABEL_78;
    }
    else
    {
      printk(&unk_A6A0);
      sleep_zswsubsys_flag = 0;
      sleep_zswresumeparam_mask = 1;
    }
    result = printk(&unk_A617);
    v36 = 0;
    sleep_zswsubsys_flag = 0;
    sleep_zswresumeparam_mask = 1;
  }
LABEL_78:
  if ( sleep_zswaod_state == 1 )
  {
    if ( (v36 & 3) == 2 )
    {
      result = printk(&unk_A65D);
      sleep_zswsubsys_flag = 0;
      v37 = 2;
    }
    else
    {
      if ( (v36 & 5) != 4 )
        goto LABEL_81;
      result = printk(&unk_9928);
      sleep_zswsubsys_flag = 0;
      v37 = 3;
    }
LABEL_87:
    sleep_zswresumeparam_mask = v37;
  }
  else
  {
LABEL_81:
    if ( (v36 & 8) != 0 )
    {
      result = printk(&unk_A2A8);
      v37 = 4;
      sleep_zswsubsys_flag = 0;
      goto LABEL_87;
    }
  }
  return result;
}
