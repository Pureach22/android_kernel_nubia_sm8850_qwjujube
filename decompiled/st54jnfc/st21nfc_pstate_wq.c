__int64 __fastcall st21nfc_pstate_wq(__int64 a1)
{
  __int64 v2; // x19
  int value; // w0
  __int64 v4; // x20
  __int64 v5; // x23
  _BOOL8 v6; // x22
  __int64 v7; // x0
  __int64 v8; // x21
  __int64 v9; // x8
  _QWORD *v10; // x9
  __int64 *v11; // x8
  __int64 v12; // x11
  __int64 v13; // x12
  __int64 v14; // x10

  v2 = ktime_get_with_offset(1) / 1000000;
  value = gpiod_get_value(*(_QWORD *)(a1 + 248));
  v4 = a1 - 648;
  v5 = *(unsigned int *)(a1 - 184);
  if ( *(_BYTE *)(a1 + 256) )
    v6 = value == 0;
  else
    v6 = value != 0;
  v7 = mutex_lock(a1 - 648);
  if ( (_DWORD)v5 == v6 )
  {
    if ( v6 || *(_QWORD *)(a1 - 152) )
    {
      v8 = a1 - 720;
      printk(&unk_8A87, "st21nfc_power_stats_switch");
      v9 = 664;
      if ( v6 )
        v9 = 680;
      ++*(_QWORD *)(v8 + v9);
      return mutex_unlock(v4);
    }
LABEL_14:
    if ( (unsigned int)v5 <= 2 )
    {
LABEL_15:
      printk(&unk_89E8, "st21nfc_power_stats_switch");
      *(_DWORD *)(a1 - 184) = v6;
      v10 = (_QWORD *)(a1 - 168 + 32 * v5);
      v11 = (__int64 *)(a1 - 168 + 32 * v6);
      v13 = v10[1];
      v12 = v10[2];
      v14 = *v11;
      v10[3] = v2;
      v11[2] = v2;
      *v11 = v14 + 1;
      v10[1] = v2 - v12 + v13;
      return mutex_unlock(v4);
    }
    __break(1u);
    goto LABEL_21;
  }
  if ( (_DWORD)v5 && v6 )
  {
    ++*(_QWORD *)(a1 - 64);
  }
  else if ( (_DWORD)v5 == 2 && !v6 )
  {
    ++*(_QWORD *)(a1 - 48);
    goto LABEL_15;
  }
  if ( (unsigned int)v5 <= 2 )
    goto LABEL_14;
LABEL_21:
  __break(0x5512u);
  return st21nfc_dev_power_stats_handler(v7, 0x805F000000000000LL);
}
