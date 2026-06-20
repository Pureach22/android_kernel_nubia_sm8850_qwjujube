__int64 __fastcall hfi_get_hw_caps_v2(unsigned int a1, _DWORD *a2)
{
  __int64 v3; // x8
  unsigned int v4; // w20

  if ( a1 >= 2 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x40000,
      1,
      "hfi_get_client_info",
      82,
      "Invalid HFI index: %u from hdl:%d",
      a1,
      a1);
    v4 = -22;
LABEL_7:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x40000,
      1,
      "hfi_get_hw_caps_v2",
      944,
      "Failed to get hfi info rc: %d for hdl: %d",
      v4,
      a1);
    return v4;
  }
  v3 = *(_QWORD *)&g_hfi[2 * a1 + 2];
  if ( !v3 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x40000,
      1,
      "hfi_get_client_info",
      89,
      "[%s] HFI interface not setup for client hdl: %d",
      byte_3EC,
      a1);
    v4 = -19;
    goto LABEL_7;
  }
  if ( a2 )
  {
    v4 = 0;
    a2[5] = *(unsigned __int8 *)(v3 + 1003);
    a2[6] = *(unsigned __int8 *)(v3 + 1002);
    a2[7] = *(unsigned __int16 *)(v3 + 1000);
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x40000,
      1,
      "hfi_get_hw_caps_v2",
      949,
      "[%s] query cap buf is NULL",
      (const char *)(v3 + 1004));
    return (unsigned int)-22;
  }
  return v4;
}
