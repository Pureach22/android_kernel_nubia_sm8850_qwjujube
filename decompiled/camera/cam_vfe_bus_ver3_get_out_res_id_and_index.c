__int64 __fastcall cam_vfe_bus_ver3_get_out_res_id_and_index(__int64 a1, int a2, int *a3)
{
  __int64 v4; // x8
  int v5; // w9

  if ( (unsigned int)(a2 - 12288) < 0x2B && ((0x7FFFF7FFFDFuLL >> a2) & 1) != 0 )
  {
    v4 = dword_44EAF0[a2 - 12288];
    v5 = *(_DWORD *)(a1 + 4 * v4 + 34768);
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      2,
      "cam_vfe_bus_ver3_get_out_res_id_and_index",
      575,
      "VFE:%u Invalid isp res id: %d , assigning max",
      *(_DWORD *)(a1 + 8),
      a2);
    v5 = 44;
    LODWORD(v4) = 44;
  }
  *a3 = v5;
  return (unsigned int)v4;
}
