__int64 __fastcall fan_pwm_store(int a1, int a2, char *s, __int64 a4)
{
  __int64 v5; // x1
  __int64 v6; // x10
  __int64 (*v7)(void); // x10
  int v8; // w21
  unsigned int v10; // [xsp+Ch] [xbp-24h] BYREF
  __int64 v11; // [xsp+10h] [xbp-20h]
  __int64 v12; // [xsp+18h] [xbp-18h]
  __int64 v13; // [xsp+20h] [xbp-10h]
  __int64 v14; // [xsp+28h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = 0;
  sscanf(s, "%d", &v10);
  if ( v10 >= 0x65 )
  {
    printk(&unk_7DB9, "NB_FAN", "fan_pwm_store", 385);
    a4 = -22;
  }
  else
  {
    mutex_lock(chip + 24);
    v5 = *(_QWORD *)(*(_QWORD *)(chip + 8) + 104LL);
    v6 = *(_QWORD *)(*(_QWORD *)(v5 + 24) + 912LL);
    v13 = *(_QWORD *)(v5 + 64);
    BYTE4(v13) = 1;
    v7 = *(__int64 (**)(void))(v6 + 24);
    v11 = 40000;
    v12 = 400LL * (unsigned __int8)v10;
    if ( *((_DWORD *)v7 - 1) != -573532208 )
      __break(0x822Au);
    v8 = v7();
    if ( v8 < 0 )
    {
      printk(&unk_7B41, "NB_FAN", "fan_pwm_set", 213);
    }
    else if ( !v8 )
    {
      mutex_unlock(chip + 24);
      printk(&unk_7BDF, "NB_FAN", "fan_pwm_store", 396);
      goto LABEL_7;
    }
    mutex_unlock(chip + 24);
    a4 = v8;
  }
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return a4;
}
