__int64 __fastcall cam_icp_v1_irq(__int64 a1, __int64 a2)
{
  __int64 v3; // x21
  __int64 v4; // x0
  char v5; // w20
  __int64 v6; // x0
  void (__fastcall *v7)(__int64, bool); // x8
  __int64 v8; // x0

  if ( a2 )
  {
    raw_spin_lock(a2 + 48);
    if ( *(_DWORD *)(a2 + 92) )
    {
      raw_spin_unlock(a2 + 48);
      v3 = *(_QWORD *)(a2 + 3680);
      v4 = cam_io_r_mb(*(_QWORD *)(a2 + 408) + 28LL);
      v5 = v4;
      cam_io_w_mb(v4, *(_QWORD *)(a2 + 408) + 24LL);
      if ( (v5 & 6) != 0 )
      {
        if ( (unsigned int)__ratelimit(&cam_icp_v1_irq__rs, "cam_icp_v1_irq") )
          v6 = 3;
        else
          v6 = 2;
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          v6,
          256,
          1,
          "cam_icp_v1_irq",
          506,
          "watch dog interrupt from ICP");
      }
      raw_spin_lock(a2 + 48);
      v7 = *(void (__fastcall **)(__int64, bool))(v3 + 40);
      if ( v7 )
      {
        v8 = *(_QWORD *)(v3 + 48);
        if ( *((_DWORD *)v7 - 1) != -1297827279 )
          __break(0x8228u);
        v7(v8, (v5 & 6) != 0);
      }
    }
    else
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        256,
        2,
        "cam_icp_v1_irq",
        489,
        "ICP HW powered off");
    }
    raw_spin_unlock(a2 + 48);
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_v1_irq",
      483,
      "Invalid cam_dev_info or query_cap args");
  }
  return 1;
}
