__int64 sub_16AB2C()
{
  int v0; // w10

  if ( (v0 & 0x40000) == 0 )
    JUMPOUT(0x166690);
  return ce_batch_send();
}
