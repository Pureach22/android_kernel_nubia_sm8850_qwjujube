__int64 sub_9CFB4()
{
  int v0; // w12

  if ( (v0 & 0x20000) != 0 )
    JUMPOUT(0xA2FE4);
  return _bpf_trace_drv_channel_switch_beacon();
}
