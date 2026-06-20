__int64 __fastcall cam_ife_csid_ver2_get_primary_sof_timer_reg_addr(__int64 a1, __int64 a2)
{
  __int64 v2; // x7
  const char *v3; // x6
  __int64 v5; // x8
  __int64 v6; // x10
  __int64 v7; // x9

  v2 = *(unsigned int *)(a2 + 16);
  if ( !a1 )
  {
    v3 = "NULL";
    goto LABEL_5;
  }
  if ( (unsigned int)v2 >= 0xC )
  {
    v3 = "Non-NULL";
LABEL_5:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_csid_ver2_get_primary_sof_timer_reg_addr",
      9058,
      "Invalid params, csid_hw is null: %s, res_id: %u",
      v3,
      v2);
    return 4294967274LL;
  }
  v5 = *(_QWORD *)(a1 + 31128);
  v6 = *(_QWORD *)(a1 + 152LL * (unsigned int)v2 + 24);
  v7 = *(_QWORD *)(**(_QWORD **)(a1 + 31136) + 8 * v2 + 136);
  *(_QWORD *)a2 = *(_QWORD *)(v5 + 384) + *(unsigned int *)(v7 + 316) + *(unsigned int *)(*(_QWORD *)(v6 + 264) + 196LL);
  *(_QWORD *)(a2 + 8) = *(_QWORD *)(v5 + 384)
                      + *(unsigned int *)(v7 + 316)
                      + *(unsigned int *)(*(_QWORD *)(v6 + 264) + 200LL);
  return 0;
}
