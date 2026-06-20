__int64 __fastcall cam_vfe_top_ver4_set_primary_sof_timer_reg_addr(__int64 a1, __int64 a2)
{
  const void *v2; // x6
  const void *v3; // x7

  v2 = *(const void **)a2;
  v3 = *(const void **)(a2 + 8);
  if ( *(_QWORD *)a2 && v3 )
  {
    *(_QWORD *)(a1 + 10904) = v2;
    *(_QWORD *)(a1 + 10912) = *(_QWORD *)(a2 + 8);
    return 0;
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_top_ver4_set_primary_sof_timer_reg_addr",
      330,
      "Invalid SOF Qtimer address: curr0: 0x%pK, curr1: 0x%pK",
      v2,
      v3);
    return 4294967274LL;
  }
}
