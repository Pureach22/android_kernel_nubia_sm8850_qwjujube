__int64 sub_195B00()
{
  int v0; // w19

  if ( (v0 & 0x100000) == 0 )
    JUMPOUT(0x197894);
  return qdf_wake_up_process();
}
