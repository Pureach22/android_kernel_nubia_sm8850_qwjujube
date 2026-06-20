__int64 __fastcall cam_icp_context_deinit(_QWORD *a1)
{
  _DWORD *v2; // x0

  if ( a1 && (v2 = (_DWORD *)*a1) != nullptr )
  {
    cam_context_deinit(v2);
    memset(a1, 0, 0x16A0u);
    return 0;
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_context_deinit",
      574,
      "Invalid params: %pK",
      a1);
    return 4294967274LL;
  }
}
