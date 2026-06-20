__int64 __fastcall syna_dev_suspend(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x19
  __int64 v5; // x21
  _BOOL8 v6; // x2
  __int64 v7; // x2
  __int64 v8; // x8
  __int64 v9; // x0
  __int64 v10; // x2
  __int64 v11; // x2
  void *v12; // x0
  _DWORD *v13; // x8
  __int64 v14; // x2

  v3 = *(_QWORD *)(a1 + 152);
  if ( *(_DWORD *)(v3 + 1404) == 1 )
  {
    v5 = *(_QWORD *)(v3 + 624);
    printk(unk_3BF3F, "syna_dev_suspend", a3);
    v6 = (*(_DWORD *)(v3 + 1456) | *(_DWORD *)(v3 + 1476)) != 0;
    *(_BYTE *)(v3 + 1409) = v6;
    printk(unk_347BF, "syna_dev_suspend", v6);
    if ( !v3 )
    {
LABEL_16:
      printk(unk_3D163, "syna_dev_suspend", v7);
      return 4294967291LL;
    }
    v8 = *(_QWORD *)(v3 + 624);
    v9 = *(_QWORD *)v3;
    if ( *(_DWORD *)(v8 + 184) && (*(_BYTE *)(v8 + 188) & 1) != 0 )
      v10 = 0;
    else
      v10 = *(unsigned int *)(v9 + 524);
    if ( *(_BYTE *)(v3 + 1409) == 1 )
    {
      if ( (syna_dev_enable_lowpwr_gesture(v3, 1, v10) & 0x80000000) != 0 )
      {
        v12 = unk_37671;
LABEL_15:
        printk(v12, "syna_dev_enter_lowpwr_sensing", v11);
        goto LABEL_16;
      }
    }
    else
    {
      if ( (*(_BYTE *)(v3 + 1408) & 1) != 0 )
        goto LABEL_18;
      if ( (syna_tcm_sleep(v9, 1, v10) & 0x80000000) != 0 )
      {
        v12 = unk_376A7;
        goto LABEL_15;
      }
    }
    msleep(100);
LABEL_18:
    *(_DWORD *)(v3 + 1404) = 2;
    syna_dev_free_input_events(v3);
    syna_tcm_clear_command_processing(*(_QWORD *)v3);
    if ( (*(_BYTE *)(v3 + 1409) & 1) == 0 )
    {
      v13 = *(_DWORD **)(v5 + 64);
      if ( v13 )
      {
        if ( *(v13 - 1) != 875454897 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, _QWORD))v13)(v5 + 8, 0);
      }
    }
    v14 = *(unsigned int *)(v3 + 1404);
    *(_DWORD *)(v3 + 1504) = 0;
    printk(unk_360F0, "syna_dev_suspend", v14);
  }
  return 0;
}
