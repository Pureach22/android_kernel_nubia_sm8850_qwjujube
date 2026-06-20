__int64 sub_86F4()
{
  int v0; // w19

  if ( (v0 & 0x400000) != 0 )
    JUMPOUT(0x359C);
  return mem_buf_relinquish_hdlr();
}
