__int64 __fastcall gsihal_check_ring_length_valid(unsigned int a1, unsigned int a2)
{
  if ( *(_DWORD *)gsihal_ctx < 0xAu )
  {
    if ( *(_DWORD *)gsihal_ctx < 8u )
    {
      if ( a1 >= 0x10000 )
      {
        dev_err(
          *(_QWORD *)(gsi_ctx + 8),
          "%s:%d bad params ring_len %u is out of bounds\n",
          "gsihal_check_ring_length_valid",
          2513);
        return 0;
      }
    }
    else if ( a1 >= 0x100000 )
    {
      dev_err(
        *(_QWORD *)(gsi_ctx + 8),
        "%s:%d bad params ring_len %u is out of bounds\n",
        "gsihal_check_ring_length_valid",
        2508);
      return 0;
    }
  }
  else
  {
    if ( HIBYTE(a1) )
    {
      dev_err(
        *(_QWORD *)(gsi_ctx + 8),
        "%s:%d bad params ring_len %u is out of bounds\n",
        "gsihal_check_ring_length_valid",
        2498);
      return 0;
    }
    if ( a1 / a2 >= 0x10000 )
    {
      dev_err(
        *(_QWORD *)(gsi_ctx + 8),
        "%s:%d bad params ring_len %u / re_size %u > 64k elements \n",
        "gsihal_check_ring_length_valid",
        2503,
        a1,
        a2);
      return 0;
    }
  }
  return 1;
}
