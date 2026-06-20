__int64 __fastcall cam_csiphy_irq(__int64 a1, __int64 a2)
{
  __int64 v2; // x20
  unsigned int *v3; // x19

  if ( a2 )
  {
    if ( *(_BYTE *)(a2 + 4729) == 1 )
    {
      v2 = *(_QWORD *)(a2 + 1200);
      v3 = **(unsigned int ***)(a2 + 112);
      cam_csiphy_common_status_reg_dump(a2, 1);
      cam_io_w_mb(1, v2 + *v3);
      cam_io_w_mb(0, v2 + *v3);
    }
    return 1;
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x8000,
      1,
      "cam_csiphy_irq",
      1521,
      "Invalid Args");
    return 0;
  }
}
