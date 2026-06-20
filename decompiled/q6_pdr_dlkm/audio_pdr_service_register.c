__int64 __fastcall audio_pdr_service_register(unsigned int a1, __int64 a2)
{
  if ( a1 )
  {
    printk(&unk_6198, "audio_pdr_service_register", a1);
    return -22;
  }
  else
  {
    audio_pdr_services = pdr_handle_alloc(a2, 0);
    return pdr_add_lookup(audio_pdr_services, aAvsAudio, aMsmAdspAudioPd);
  }
}
