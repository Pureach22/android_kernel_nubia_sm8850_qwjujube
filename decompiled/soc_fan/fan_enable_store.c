__int64 __fastcall fan_enable_store(int a1, int a2, char *s, __int64 a4)
{
  __int64 v5; // x9
  int v6; // w10
  _BYTE *v7; // x0
  int v9; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = 0;
  sscanf(s, "%d", &v9);
  v5 = *(_QWORD *)(chip + 8);
  v6 = v9 != 0;
  if ( *(unsigned __int8 *)(v5 + 12) == v6 )
  {
    printk(&unk_8134, "NB_FAN", "fan_enable_store", 319);
  }
  else
  {
    *(_BYTE *)(v5 + 12) = v6;
    printk(&unk_7F93, "NB_FAN", "fan_enable_store", 323);
    mutex_lock(chip + 24);
    v7 = *(_BYTE **)(chip + 8);
    if ( (v7[12] & 1) != 0 )
    {
      if ( v7[1] )
      {
        fan_level_set(v7, (unsigned __int8)v7[1]);
        printk(&unk_7E62, "NB_FAN", "fan_enable_store", 332);
        *(_BYTE *)(*(_QWORD *)(chip + 8) + 1LL) = 0;
      }
    }
    else
    {
      v7[1] = *v7;
      fan_level_set(*(_QWORD *)(chip + 8), 0);
    }
    mutex_unlock(chip + 24);
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
