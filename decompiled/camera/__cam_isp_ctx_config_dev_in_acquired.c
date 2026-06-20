__int64 __fastcall _cam_isp_ctx_config_dev_in_acquired(__int64 a1)
{
  __int64 v2; // x20
  __int64 result; // x0
  int v4; // w6
  int v5; // w7
  int v6; // w9
  unsigned int v7; // w19

  v2 = *(_QWORD *)(a1 + 256) + 45056LL;
  if ( (*(_BYTE *)(*(_QWORD *)(a1 + 256) + 45740LL) & 1) != 0 )
  {
    result = _cam_isp_ctx_config_dev_in_top_state(a1);
    if ( !(_DWORD)result && ((*(_DWORD *)(a1 + 64) & 0x80000000) == 0 || *(_BYTE *)(v2 + 681) == 1) )
      *(_DWORD *)(a1 + 240) = 3;
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      v4 = *(_DWORD *)(a1 + 240);
      v5 = *(_DWORD *)(a1 + 32);
      v6 = *(_DWORD *)(a1 + 64);
      v7 = result;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "__cam_isp_ctx_config_dev_in_acquired",
        9186,
        "next state %d, ctx %u link: 0x%x",
        v4,
        v5,
        v6);
      return v7;
    }
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "__cam_isp_ctx_config_dev_in_acquired",
      9174,
      "HW is not acquired, reject packet, ctx_id %u link: 0x%x",
      *(_DWORD *)(a1 + 32),
      *(_DWORD *)(a1 + 64));
    return 4294967274LL;
  }
  return result;
}
