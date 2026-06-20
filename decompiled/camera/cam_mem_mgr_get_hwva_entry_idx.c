bool __fastcall cam_mem_mgr_get_hwva_entry_idx(unsigned int a1, int *a2)
{
  int v2; // w19
  int v3; // w20

  v2 = HIWORD(a1) & 0xFFF;
  v3 = dword_391BA8;
  if ( v2 >= dword_391BA8 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x400000,
      1,
      "cam_mem_mgr_get_hwva_entry_idx",
      165,
      "Invalid mem_hdl: 0x%x, failed to lookup",
      a1);
  else
    *a2 = v2;
  return v2 < v3;
}
