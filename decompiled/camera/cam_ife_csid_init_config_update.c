__int64 __fastcall cam_ife_csid_init_config_update(_DWORD **a1, unsigned int a2)
{
  _QWORD *v2; // x8
  __int64 v3; // x9
  unsigned int v4; // w11
  int v5; // w12
  unsigned int v6; // w7
  __int64 result; // x0

  if ( a2 == 16 )
  {
    v2 = *a1;
    v3 = *((_QWORD *)*a1 + 3);
    if ( *(_BYTE *)(v3 + 253) != 1 )
      return 0;
    v4 = *(_DWORD *)(v3 + 160);
    v5 = *(_DWORD *)(v3 + 184);
    if ( *a1[1] * (v4 - *(_DWORD *)(v3 + 156)) / 0x64 >= v4 )
      v6 = *(_DWORD *)(v3 + 160);
    else
      v6 = *a1[1] * (v4 - *(_DWORD *)(v3 + 156)) / 0x64;
    *(_DWORD *)(v3 + 232) = v6;
    if ( v5 || *(_DWORD *)(v3 + 192) )
      *(_DWORD *)(v3 + 232) = v6 >> 1;
    result = 0;
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD *))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_ife_csid_init_config_update",
        8725,
        "Init Update for res_name: %s epoch_factor: %x",
        v2 + 16);
      return 0;
    }
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_csid_init_config_update",
      8704,
      "Invalid args size expected: %zu actual: %zu",
      0x10u,
      a2);
    return 4294967274LL;
  }
  return result;
}
