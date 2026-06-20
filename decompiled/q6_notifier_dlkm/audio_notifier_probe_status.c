__int64 audio_notifier_probe_status()
{
  __int64 v0; // x9

  if ( adsp_private )
  {
    v0 = *(_QWORD *)(adsp_private + 168);
    if ( v0 )
    {
      if ( (*(_BYTE *)(v0 + 8) & 1) != 0 )
        return 1;
    }
    else
    {
      dev_err(adsp_private + 16, " %s: Private data get failed\n", "audio_notifier_probe_status");
    }
  }
  return 0;
}
