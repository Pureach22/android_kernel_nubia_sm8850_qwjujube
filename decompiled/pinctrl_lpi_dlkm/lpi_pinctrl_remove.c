__int64 __fastcall lpi_pinctrl_remove(__int64 a1)
{
  __int64 v2; // x20

  v2 = *(_QWORD *)(a1 + 168);
  _pm_runtime_disable(a1 + 16, 1);
  _pm_runtime_set_status(a1 + 16, 2);
  snd_event_client_deregister(a1 + 16);
  audio_notifier_deregister("lpi_tlmm");
  return gpiochip_remove(v2 + 16);
}
