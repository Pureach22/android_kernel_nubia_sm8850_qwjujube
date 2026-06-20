__int64 __fastcall cam_csiphy_reset(__int64 result)
{
  __int64 v1; // x19
  int v2; // w20
  __int64 v3; // x21
  int i; // w22
  __int64 v5; // x23

  v1 = result;
  v2 = *(_DWORD *)(**(_QWORD **)(result + 112) + 40LL);
  if ( v2 )
  {
    v3 = *(_QWORD *)(result + 1200);
    for ( i = 0; i != v2; ++i )
    {
      v5 = 16LL * i;
      cam_io_w_mb(
        *(unsigned int *)(*(_QWORD *)(*(_QWORD *)(v1 + 112) + 24LL) + v5 + 4),
        v3 + *(int *)(*(_QWORD *)(*(_QWORD *)(v1 + 112) + 24LL) + v5));
      result = *(unsigned int *)(*(_QWORD *)(*(_QWORD *)(v1 + 112) + 24LL) + v5 + 8);
      if ( (int)result >= 1 )
        result = usleep_range_state(result, (int)result + 5, 2);
    }
  }
  if ( *(_BYTE *)(v1 + 4730) == 1 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x8000,
      3,
      "cam_csiphy_reset",
      756,
      "Status Reg Dump after phy reset");
    return cam_csiphy_dump_status_reg(v1);
  }
  return result;
}
