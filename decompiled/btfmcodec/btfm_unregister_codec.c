__int64 btfm_unregister_codec()
{
  __int64 btfmcodec; // x0

  btfmcodec = btfm_get_btfmcodec();
  return snd_soc_unregister_component(btfmcodec);
}
