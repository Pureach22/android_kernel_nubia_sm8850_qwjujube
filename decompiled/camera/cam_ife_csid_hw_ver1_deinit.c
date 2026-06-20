__int64 __fastcall cam_ife_csid_hw_ver1_deinit(__int64 a1)
{
  __int64 v1; // x19

  if ( a1 )
  {
    v1 = *(_QWORD *)(a1 + 3680);
    ((void (__fastcall *)(__int64))cam_ife_csid_ver1_free_res)(v1);
    cam_ife_csid_deinit_soc_resources(*(_QWORD *)(v1 + 8) + 96LL);
    return 0;
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_csid_hw_ver1_deinit",
      4852,
      "Invalid param");
    return 4294967274LL;
  }
}
