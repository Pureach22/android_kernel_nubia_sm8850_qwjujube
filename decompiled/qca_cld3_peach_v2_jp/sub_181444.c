__int64 sub_181444()
{
  int v0; // w19

  if ( (v0 & 0x100000) == 0 )
    JUMPOUT(0x1831D8);
  return qdf_wake_up_process();
}
