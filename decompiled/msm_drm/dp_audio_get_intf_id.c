unsigned __int64 dp_audio_get_intf_id()
{
  unsigned __int64 result; // x0

  result = dp_audio_get_data();
  if ( result <= 0xFFFFFFFFFFFFF000LL )
    return 44;
  else
    return (unsigned int)result;
}
