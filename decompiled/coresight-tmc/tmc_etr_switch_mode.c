__int64 __fastcall tmc_etr_switch_mode(__int64 a1, const char *a2)
{
  int v4; // w21
  __int64 v5; // x0
  unsigned int v6; // w20
  __int64 v7; // x0
  unsigned int v8; // w20
  __int64 v10; // x0
  __int64 v11; // x0

  mutex_lock(a1 + 152);
  if ( !strcmp(a2, "mem") )
  {
    v4 = 1;
  }
  else
  {
    if ( strcmp(a2, "usb") )
    {
LABEL_7:
      v6 = -22;
LABEL_12:
      mutex_unlock(a1 + 152);
      return v6;
    }
    if ( !*(_DWORD *)(*(_QWORD *)(a1 + 336) + 8LL) )
    {
      dev_err(*(_QWORD *)(a1 + 16) + 56LL, "USB mode is not supported.\n");
      goto LABEL_7;
    }
    v4 = 2;
  }
  v5 = *(_QWORD *)(a1 + 16);
  if ( (unsigned int)*(_QWORD *)(v5 + 968) == 2 )
    goto LABEL_7;
  if ( v4 == *(_DWORD *)(a1 + 332) )
    goto LABEL_11;
  if ( !(unsigned int)*(_QWORD *)(v5 + 968) )
  {
    v6 = 0;
    *(_DWORD *)(a1 + 332) = v4;
    goto LABEL_12;
  }
  ((void (*)(void))tmc_disable_etr_sink)();
  v7 = *(_QWORD *)(a1 + 16);
  v8 = *(_DWORD *)(a1 + 332);
  *(_DWORD *)(a1 + 332) = v4;
  if ( !(unsigned int)tmc_enable_etr_sink_sysfs(v7) )
  {
LABEL_11:
    v6 = 0;
    goto LABEL_12;
  }
  v10 = *(_QWORD *)(a1 + 16);
  *(_DWORD *)(a1 + 332) = v8;
  v11 = tmc_enable_etr_sink_sysfs(v10);
  if ( v8 <= 2 )
  {
    dev_err(
      *(_QWORD *)(a1 + 16) + 56LL,
      "Switch to %s failed. Fall back to %s.\n",
      str_tmc_etr_out_mode[v4],
      str_tmc_etr_out_mode[v8]);
    goto LABEL_7;
  }
  __break(0x5512u);
  return tmc_disable_etr_sink(v11);
}
