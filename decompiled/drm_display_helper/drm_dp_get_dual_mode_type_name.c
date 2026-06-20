const char *__fastcall drm_dp_get_dual_mode_type_name(unsigned int a1)
{
  if ( a1 < 7 )
    return off_1D448[a1];
  __break(0x800u);
  return "unknown";
}
