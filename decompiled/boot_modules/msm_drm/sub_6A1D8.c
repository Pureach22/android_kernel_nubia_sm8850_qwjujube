__int64 sub_6A1D8()
{
  __asm { STZ2G           X18, [X18,#-0x930]! }
  return dp_panel_read_sink_caps();
}
