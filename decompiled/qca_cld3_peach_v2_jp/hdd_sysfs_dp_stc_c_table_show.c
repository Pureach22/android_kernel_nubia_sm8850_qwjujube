__int64 __fastcall hdd_sysfs_dp_stc_c_table_show(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  __int64 *context; // x19
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 result; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x19
  __int64 v27[2]; // [xsp+0h] [xbp-10h] BYREF

  v27[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v27[0] = 0;
  context = _cds_get_context(51, (__int64)"hdd_sysfs_dp_stc_c_table_show", a1, a2, a3, a4, a5, a6, a7, a8);
  LODWORD(result) = _wlan_hdd_validate_context(
                      (__int64)context,
                      (__int64)"hdd_sysfs_dp_stc_c_table_show",
                      v9,
                      v10,
                      v11,
                      v12,
                      v13,
                      v14,
                      v15,
                      v16);
  if ( (_DWORD)result
    || (LODWORD(result) = _osif_psoc_sync_op_start(
                            *(_QWORD *)(context[3] + 488),
                            v27,
                            (__int64)"hdd_sysfs_dp_stc_c_table_show"),
        (_DWORD)result) )
  {
    result = (int)result;
  }
  else
  {
    if ( wlan_hdd_validate_modules_state((__int64)context, v18, v19, v20, v21, v22, v23, v24, v25) )
    {
      ucfg_dp_stc_print_classified_table(*context);
      v26 = 0;
    }
    else
    {
      v26 = -22;
    }
    _osif_psoc_sync_op_stop(v27[0], (__int64)"hdd_sysfs_dp_stc_c_table_show");
    result = v26;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
