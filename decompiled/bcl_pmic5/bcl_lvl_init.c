unsigned __int64 __fastcall bcl_lvl_init(__int64 a1, unsigned int a2, int a3, __int64 a4)
{
  __int64 v6; // x24
  int *v9; // x21
  int irq_byname; // w0
  unsigned int v11; // w22
  int v12; // w0
  unsigned __int64 result; // x0

  v6 = a4 + 184LL * a2;
  _mutex_init(v6 + 72, "&lbat->state_trans_lock", &bcl_lvl_init___key);
  *(_DWORD *)(v6 + 124) = a2;
  *(_QWORD *)(v6 + 224) = a4;
  *(_DWORD *)(v6 + 52) = a3;
  mutex_lock(v6 + 72);
  *(_DWORD *)(v6 + 48) = 0;
  v9 = (int *)(v6 + 48);
  *(_BYTE *)(v6 + 120) = 0;
  irq_byname = platform_get_irq_byname(a1, &bcl_int_names[25 * a2]);
  if ( irq_byname >= 1 )
  {
    v11 = irq_byname;
    v12 = devm_request_threaded_irq(
            a1 + 16,
            (unsigned int)irq_byname,
            0,
            bcl_handle_irq,
            8193,
            &bcl_int_names[25 * a2],
            v6 + 48);
    if ( v12 )
    {
      dev_err(a1 + 16, "Error requesting trip irq. err:%d\n", v12);
    }
    else
    {
      disable_irq_nosync(v11);
      *v9 = v11;
    }
  }
  result = mutex_unlock(v6 + 72);
  if ( *v9 >= 1 )
  {
    *(_QWORD *)(v6 + 136) = bcl_read_lbat;
    *(_QWORD *)(v6 + 144) = bcl_set_lbat;
    *(_QWORD *)(v6 + 184) = bcl_get_trend;
    *(_QWORD *)(v6 + 152) = qti_tz_change_mode;
    result = devm_thermal_of_zone_register(a1 + 16, a2, v6 + 48, v6 + 128);
    *(_QWORD *)(v6 + 216) = result;
    if ( result < 0xFFFFFFFFFFFFF001LL )
      return thermal_zone_device_update();
    else
      *(_QWORD *)(v6 + 216) = 0;
  }
  return result;
}
