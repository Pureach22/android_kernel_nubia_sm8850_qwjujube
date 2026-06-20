__int64 __fastcall cam_destroy_link_hdl(unsigned int a1)
{
  unsigned int v2; // w19

  if ( (debug_mdl & 0x10) != 0 && !debug_priority )
  {
    v2 = a1;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x10,
      4,
      "cam_destroy_link_hdl",
      467,
      "handle = %x",
      a1);
    a1 = v2;
  }
  return cam_destroy_hdl(a1, 3);
}
