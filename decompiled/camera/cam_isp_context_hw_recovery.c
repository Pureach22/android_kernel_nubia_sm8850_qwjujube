__int64 __fastcall cam_isp_context_hw_recovery(__int64 a1)
{
  __int64 *v1; // x9
  __int64 (__fastcall *v2)(_QWORD); // x8
  __int64 v3; // x0

  v1 = *(__int64 **)(a1 + 208);
  v2 = (__int64 (__fastcall *)(_QWORD))v1[18];
  if ( v2 )
  {
    v3 = *v1;
    if ( *((_DWORD *)v2 - 1) != 1863972096 )
      __break(0x8228u);
    return v2(v3);
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_isp_context_hw_recovery",
      10623,
      "hw mgr doesn't support recovery, ctx_idx: %u, link: 0x%x",
      *(_DWORD *)(a1 + 32),
      *(_DWORD *)(a1 + 64));
    return 0xFFFFFFFFLL;
  }
}
