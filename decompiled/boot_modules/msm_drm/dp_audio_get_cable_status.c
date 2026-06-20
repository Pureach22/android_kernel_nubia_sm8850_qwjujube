unsigned __int64 dp_audio_get_cable_status()
{
  unsigned __int64 result; // x0

  result = dp_audio_get_data();
  if ( result < 0xFFFFFFFFFFFFF001LL )
    return *(unsigned int *)(result + 148);
  return result;
}
