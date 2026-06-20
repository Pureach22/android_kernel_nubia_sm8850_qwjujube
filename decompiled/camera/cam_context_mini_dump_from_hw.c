__int64 __fastcall cam_context_mini_dump_from_hw(__int64 a1)
{
  __int64 v1; // x8
  unsigned int v2; // w7
  __int64 (*v3)(void); // x8

  v1 = *(_QWORD *)(a1 + 248);
  if ( !v1 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      2,
      1,
      "cam_context_mini_dump_from_hw",
      299,
      "Context [id %d name:%s] is not ready",
      *(_DWORD *)(a1 + 32),
      (const char *)a1);
    return 4294967274LL;
  }
  v2 = *(_DWORD *)(a1 + 240);
  if ( v2 - 1 > 4 )
    return 0;
  v3 = *(__int64 (**)(void))(v1 + 192LL * v2 + 168);
  if ( !v3 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      2,
      2,
      "cam_context_mini_dump_from_hw",
      308,
      "No dump ctx in dev %d, state %d",
      *(unsigned int *)(a1 + 60));
    return 0;
  }
  if ( *((_DWORD *)v3 - 1) != 1863972096 )
    __break(0x8228u);
  return v3();
}
