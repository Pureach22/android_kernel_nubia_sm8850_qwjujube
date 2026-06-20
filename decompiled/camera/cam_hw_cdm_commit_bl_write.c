__int64 __fastcall cam_hw_cdm_commit_bl_write(__int64 a1, unsigned int a2)
{
  bool v2; // w19

  if ( a2 >= 4 )
  {
    __break(0x5512u);
    return cam_hw_cdm_submit_gen_irq();
  }
  else
  {
    v2 = cam_cdm_write_hw_reg(
           a1,
           *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 3680) + 232LL) + 8LL * a2 + 8) + 8LL),
           1u);
    if ( v2 )
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        1,
        1,
        "cam_hw_cdm_commit_bl_write",
        840,
        "Failed to write CDM commit BL");
    return v2;
  }
}
