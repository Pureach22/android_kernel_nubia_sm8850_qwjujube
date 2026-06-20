__int64 sub_AA6E4()
{
  char v0; // w28

  if ( (v0 & 8) != 0 )
    JUMPOUT(0xB0098);
  return _bpf_trace_wiphy_enabled_evt();
}
