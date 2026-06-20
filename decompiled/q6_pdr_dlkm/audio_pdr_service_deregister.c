__int64 __fastcall audio_pdr_service_deregister(unsigned int a1)
{
  if ( a1 )
  {
    printk(&unk_6198, "audio_pdr_service_deregister", a1);
    return 4294967274LL;
  }
  else
  {
    pdr_handle_release(audio_pdr_services);
    return 0;
  }
}
