__int64 sub_84D0()
{
  int v0; // w19

  if ( (v0 & 0x400000) != 0 )
    JUMPOUT(0x3378);
  return mem_buf_alloc_req_hdlr();
}
