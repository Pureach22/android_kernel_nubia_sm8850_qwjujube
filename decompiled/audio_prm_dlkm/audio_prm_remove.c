__int64 audio_prm_remove()
{
  audio_notifier_deregister("audio_prm");
  mutex_lock(&unk_6D28);
  byte_6D68 = 0;
  g_prm = 0;
  mutex_unlock(&unk_6D28);
  return 0;
}
