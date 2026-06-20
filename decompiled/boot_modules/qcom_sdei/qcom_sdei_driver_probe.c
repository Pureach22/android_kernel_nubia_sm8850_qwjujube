__int64 qcom_sdei_driver_probe()
{
  unsigned int v0; // w0
  unsigned int v1; // w0
  unsigned int v2; // w0
  __int64 result; // x0
  unsigned int v4; // w19
  void *v5; // x0
  __int64 v6; // x1

  on_each_cpu_cond_mask(0, &register_cpu_mpidr, 0, 1, &_cpu_online_mask);
  v0 = sdei_event_register(0, &sdei_standard_cb, 0);
  if ( v0 )
  {
    v4 = v0;
    v5 = &unk_6624;
    v6 = 0;
  }
  else
  {
    v1 = ((__int64 (*)(void))sdei_event_enable)();
    if ( v1 )
    {
      v4 = v1;
      sdei_event_unregister(0);
      v5 = &unk_6655;
      v6 = 0;
    }
    else
    {
      v2 = sdei_event_register(0x40000000, sdei_wdg_bite_cb, 0);
      if ( v2 )
      {
        v4 = v2;
        sdei_event_disable(0);
        sdei_event_unregister(0);
        v5 = &unk_6624;
      }
      else
      {
        result = sdei_event_enable(0x40000000);
        if ( !(_DWORD)result )
          return result;
        v4 = result;
        sdei_event_unregister(0x40000000);
        sdei_event_disable(0);
        sdei_event_unregister(0);
        v5 = &unk_6655;
      }
      v6 = 0x40000000;
    }
  }
  printk(v5, v6);
  return v4;
}
