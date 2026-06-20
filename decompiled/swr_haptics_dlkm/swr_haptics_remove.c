__int64 __fastcall swr_haptics_remove(__int64 a1)
{
  _QWORD *v2; // x21
  unsigned int v3; // w0
  unsigned int v4; // w20

  if ( a1 && (v2 = *(_QWORD **)(a1 + 224)) != nullptr )
  {
    if ( (*((_BYTE *)v2 + 186) & 4) != 0 )
      qcom_unregister_ssr_notifier(v2[21], v2 + 12);
    unregister_hboost_event_notifier(v2 + 9);
    if ( *((_BYTE *)v2 + 180) == 1 )
    {
      v3 = regulator_disable(v2[7]);
      if ( (v3 & 0x80000000) != 0 )
      {
        v4 = v3;
        if ( (unsigned int)__ratelimit(&swr_haptics_slave_disable__rs, "swr_haptics_slave_disable") )
          dev_err(*v2, "%s: disable swr-slave-vdd failed, rc=%d\n", "swr_haptics_slave_disable", v4);
        dev_err(*v2, "%s: disable swr-slave failed, rc=%d\n", "swr_haptics_remove", v4);
      }
      else
      {
        v4 = 0;
        *((_BYTE *)v2 + 180) = 0;
      }
    }
    else
    {
      v4 = 0;
    }
  }
  else
  {
    dev_err(a1 + 72, "%s: no data for swr_hap\n", "swr_haptics_remove");
    v4 = -19;
  }
  snd_soc_unregister_component(a1 + 72);
  *(_QWORD *)(a1 + 224) = 0;
  return v4;
}
