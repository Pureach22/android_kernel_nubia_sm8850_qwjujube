__int64 __fastcall tpg_hw_write_settings(__int64 a1, __int64 a2, unsigned int *a3)
{
  unsigned int *v4; // x19
  __int64 v5; // x22
  unsigned int v6; // w21
  unsigned __int64 v7; // x23
  unsigned __int64 v8; // x8
  const char *v10; // x5
  __int64 v11; // x4

  if ( a1 && a2 && (v4 = a3) != nullptr )
  {
    if ( !*(_DWORD *)(a2 + 24) )
      return 0;
    v5 = *(_QWORD *)(a1 + 40);
    v6 = 0;
    v7 = *(_QWORD *)(*(_QWORD *)(v5 + 224) + 8LL) - **(_QWORD **)(v5 + 224) + 1LL;
    while ( 1 )
    {
      v8 = *v4;
      if ( v7 <= v8 )
        break;
      cam_io_w_mb(v4[1], *(_QWORD *)(v5 + 288) + v8);
      ++v6;
      v4 += 8;
      if ( v6 >= *(_DWORD *)(a2 + 24) )
        return 0;
    }
    v10 = "settings reg_offset error";
    v11 = 27;
  }
  else
  {
    v10 = "invalid params";
    v11 = 17;
  }
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    0x200000000LL,
    1,
    "tpg_hw_write_settings",
    v11,
    v10);
  return 4294967274LL;
}
