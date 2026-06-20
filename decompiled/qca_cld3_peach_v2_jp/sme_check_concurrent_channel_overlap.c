__int64 __fastcall sme_check_concurrent_channel_overlap(
        __int64 a1,
        unsigned __int16 a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int a5)
{
  unsigned int v11; // w20

  if ( (unsigned int)qdf_mutex_acquire(a1 + 12776) )
    return 0;
  v11 = csr_check_concurrent_channel_overlap(a1, a2, a3, a4, a5);
  qdf_mutex_release(a1 + 12776);
  return v11;
}
