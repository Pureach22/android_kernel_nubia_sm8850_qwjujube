__int64 __fastcall cam_vfe_top_get_hw_caps(__int64 a1, _BYTE *a2)
{
  __int64 v3; // x8

  if ( a1 && a2 )
  {
    v3 = *(_QWORD *)(a1 + 10432);
    if ( v3 )
    {
      a2[12] = *(_BYTE *)(*(_QWORD *)(v3 + 3296) + 24LL);
      *((_DWORD *)a2 + 2) = *(unsigned __int16 *)(a1 + 10400);
      *((_DWORD *)a2 + 1) = *(_WORD *)(a1 + 10402) & 0xFFF;
      *(_DWORD *)a2 = *(_DWORD *)(a1 + 10400) >> 28;
      return 0;
    }
    else
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, _BYTE *))cam_print_log)(
        3,
        8,
        1,
        "cam_vfe_top_get_hw_caps",
        275,
        "soc_info is null",
        a1,
        a2);
      return 4294967282LL;
    }
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_top_get_hw_caps",
      267,
      "Invalid arguments device_priv:%p, args:%p",
      (const void *)a1,
      a2);
    return 4294967274LL;
  }
}
