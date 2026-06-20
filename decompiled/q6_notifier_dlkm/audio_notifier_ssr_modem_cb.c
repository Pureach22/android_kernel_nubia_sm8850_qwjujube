__int64 __fastcall audio_notifier_ssr_modem_cb(__int64 a1, __int64 a2)
{
  audio_notifier_service_cb(a2, 0, 1u);
  return 1;
}
