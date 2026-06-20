__int64 __fastcall fan_speed_show(__int64 a1, __int64 a2, char *a3)
{
  unsigned __int8 *v4; // x21
  unsigned int v5; // w20
  int v6; // w4
  int v7; // w8
  unsigned int v8; // w22
  int v9; // w8
  unsigned __int8 *v10; // x0
  int v11; // w21
  __int64 v12; // x22
  __int64 v13; // x22
  int v14; // w8
  int v15; // w19

  mutex_lock(chip + 24);
  v4 = *(unsigned __int8 **)(chip + 8);
  if ( *v4 )
  {
    v4[2] = 1;
    hrtimer_start_range_ns(v4 + 40, 1000000, 0, 1);
    msleep(1000);
    v6 = *v4;
    v5 = 40 * *((_DWORD *)v4 + 2);
    if ( v6 == 3 && v5 > 0xFA0 )
    {
      v7 = 13000;
LABEL_6:
      v8 = *((_DWORD *)v4 + 2) + v7;
      goto LABEL_14;
    }
    if ( v6 == 5 )
    {
      if ( v5 >= 0xFA1 )
      {
        v7 = 19000;
        goto LABEL_6;
      }
    }
    else if ( v6 == 4 && v5 > 0xFA0 )
    {
      v7 = 16000;
      goto LABEL_6;
    }
    v8 = 0;
LABEL_14:
    printk(&unk_80BA, "NB_FAN", "fan_rpm_get", 296);
    v9 = 0;
    if ( v8 > v5 )
      v5 = v8;
    v10 = *(unsigned __int8 **)(chip + 8);
    v11 = *v10;
    if ( *v10 && 1000 * v11 >= v5 )
    {
      if ( nb_fan_rpm_check_rst_cnt > 10 )
        goto LABEL_29;
      fan_level_set(v10, 0);
      v12 = *(_QWORD *)(chip + 72);
      if ( v12 && (unsigned int)regulator_is_enabled(*(_QWORD *)(chip + 72)) )
      {
        regulator_disable(v12);
        printk(&unk_7912, "NB_FAN", "nb_fan_power_set", 229);
      }
      msleep(50);
      v13 = *(_QWORD *)(chip + 72);
      if ( v13 && !(unsigned int)regulator_is_enabled(*(_QWORD *)(chip + 72)) )
      {
        regulator_enable(v13);
        msleep(10);
        printk(&unk_82EC, "NB_FAN", "nb_fan_power_set", 237);
      }
      fan_level_set(*(unsigned __int8 **)(chip + 8), v11);
      printk(&unk_84EC, "NB_FAN", "nb_fan_rpm_check", 429);
      v14 = nb_fan_rpm_check_rst_cnt;
      if ( nb_fan_rpm_check_rst_cnt == 10 )
      {
        printk(&unk_7F10, "NB_FAN", "nb_fan_rpm_check", 432);
        v14 = nb_fan_rpm_check_rst_cnt;
      }
      v9 = v14 + 1;
    }
    nb_fan_rpm_check_rst_cnt = v9;
    goto LABEL_29;
  }
  v5 = 0;
LABEL_29:
  v15 = sprintf(a3, "%d\n", v5);
  mutex_unlock(chip + 24);
  printk(&unk_8377, "NB_FAN", "fan_speed_show", 452);
  return v15;
}
