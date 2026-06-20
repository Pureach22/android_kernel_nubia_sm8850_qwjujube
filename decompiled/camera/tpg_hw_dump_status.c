__int64 __fastcall tpg_hw_dump_status(__int64 a1)
{
  __int64 v1; // x9
  __int64 v2; // x8
  void (*v3)(void); // x8

  if ( !a1 )
    return 4294967274LL;
  v1 = *(_QWORD *)(a1 + 32);
  if ( !v1 )
    return 4294967274LL;
  v2 = *(_QWORD *)(v1 + 16);
  if ( !v2 )
    return 4294967274LL;
  if ( (unsigned int)(*(_DWORD *)v1 - 268435459) > 2 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x200000000LL,
      2,
      "tpg_hw_dump_status",
      553,
      "Hw version doesn't support status dump");
  }
  else
  {
    v3 = *(void (**)(void))(v2 + 56);
    if ( v3 )
    {
      if ( *((_DWORD *)v3 - 1) != 731976422 )
        __break(0x8228u);
      v3();
    }
  }
  return 0;
}
