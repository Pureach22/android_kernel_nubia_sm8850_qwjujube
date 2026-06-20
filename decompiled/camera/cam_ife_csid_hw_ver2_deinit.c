__int64 __fastcall cam_ife_csid_hw_ver2_deinit(__int64 a1)
{
  __int64 v1; // x19

  v1 = *(_QWORD *)(a1 + 3680);
  if ( v1 )
  {
    cam_ife_csid_hw_deinit_irq(*(_QWORD *)(a1 + 3680));
    cam_ife_csid_ver2_free_res(v1);
    cam_ife_csid_deinit_soc_resources(*(_QWORD *)(v1 + 31128) + 96LL);
    return 0;
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_csid_hw_ver2_deinit",
      9808,
      "Invalid param");
    return 4294967274LL;
  }
}
