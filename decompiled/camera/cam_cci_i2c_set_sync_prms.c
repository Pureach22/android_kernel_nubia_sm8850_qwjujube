__int64 __fastcall cam_cci_i2c_set_sync_prms(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  __int64 v3; // x9

  v2 = *(_QWORD *)(a1 + 240);
  if ( v2 )
  {
    v3 = *(_QWORD *)(a2 + 24);
    *(_QWORD *)(v2 + 5296) = v3;
    *(_BYTE *)(v2 + 5304) = (int)v3 >= 0;
    return 0;
  }
  else
  {
    ((void (*)(__int64, const char *, ...))cam_print_log)(
      3,
      print_fmt_cam_context_state,
      (_BYTE *)&_ksymtab_cam_cci_dump_registers + 1,
      "cam_cci_i2c_set_sync_prms",
      2369);
    return 4294967274LL;
  }
}
