__int64 __fastcall disable_audio_stream(__int64 **a1)
{
  __int64 v1; // x19

  v1 = **a1;
  snd_usb_hw_free(a1);
  return snd_usb_autosuspend(v1);
}
