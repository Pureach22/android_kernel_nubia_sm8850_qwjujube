__int64 __fastcall fan_level_store(int a1, int a2, char *s, __int64 a4)
{
  __int64 v5; // x9
  int v6; // w20
  unsigned int v8; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = 0;
  sscanf(s, "%d", &v8);
  if ( v8 >= 6 )
  {
    printk(&unk_7978, "NB_FAN", "fan_level_store", 357);
    a4 = -22;
  }
  else
  {
    v5 = *(_QWORD *)(chip + 8);
    if ( (*(_BYTE *)(v5 + 12) & 1) != 0 )
    {
      mutex_lock(chip + 24);
      v6 = fan_level_set(*(unsigned __int8 **)(chip + 8), v8);
      mutex_unlock(chip + 24);
      if ( v6 )
        a4 = v6;
      else
        printk(&unk_8401, "NB_FAN", "fan_level_store", 373);
    }
    else
    {
      *(_BYTE *)(v5 + 1) = v8;
      printk(&unk_7C04, "NB_FAN", "fan_level_store", 363);
    }
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
