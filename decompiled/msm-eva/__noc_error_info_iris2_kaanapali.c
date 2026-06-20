__int64 __fastcall _noc_error_info_iris2_kaanapali(__int64 result, __int64 a2, __int64 a3, __int64 a4)
{
  _DWORD *v4; // x22
  unsigned __int64 StatusReg; // x8
  int v6; // w23
  __int64 v7; // x19
  __int64 v8; // x8
  void (__fastcall *v9)(_QWORD); // x8
  int v10; // w0
  int v11; // w0
  int v12; // w0
  int v13; // w0
  int v14; // w0
  int v15; // w0
  int v16; // w0
  int v17; // w3
  int v18; // w0
  int v19; // w0
  int v20; // w0
  int v21; // w0
  int v22; // w0
  int v23; // w0
  int v24; // w0
  int v25; // w0
  int v26; // w0
  int v27; // w0
  int v28; // w0
  int v29; // w0
  int v30; // w0
  int v31; // w0
  int v32; // w0
  int v33; // w0
  unsigned int v34; // w21
  __int64 v35; // x1
  __int64 v36; // x2
  __int64 v37; // x3
  __int64 v38; // x4
  __int64 v39; // x5
  __int64 v40; // x6
  int v41; // w0
  unsigned __int64 v42; // x8

  v4 = *(_DWORD **)(cvp_driver + 48);
  if ( v4[1467] )
  {
    if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      return printk(&unk_9764B, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), "warn");
    }
  }
  else
  {
    v6 = v4[214];
    v7 = result;
    v4[1467] = 1;
    _disable_hw_power_collapse(result, a2, a3, a4);
    if ( v7 )
    {
      v8 = *(_QWORD *)(v7 + 2512);
      if ( v8 )
      {
        v9 = *(void (__fastcall **)(_QWORD))(v8 + 64);
        if ( v9 )
        {
          if ( *((_DWORD *)v9 - 1) != -1303076162 )
            __break(0x8228u);
          v9(v7);
        }
      }
    }
    _read_register(v7, 0xE0024u);
    _read_register(v7, 0xB0088u);
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v42 = _ReadStatusReg(SP_EL0);
      printk(&unk_855E7, *(unsigned int *)(v42 + 1800), *(unsigned int *)(v42 + 1804), &unk_8E7CE);
    }
    v10 = _read_register(v7, 0xD0000u);
    _err_log(v6 != 0, v4 + 1468, (__int64)"CVP_NOC_ERL_MAIN_SWID_LOW", v10);
    v11 = _read_register(v7, 0xD0004u);
    _err_log(v6 != 0, v4 + 1469, (__int64)"CVP_NOC_ERL_MAIN_SWID_HIGH", v11);
    v12 = _read_register(v7, 0xD0008u);
    _err_log(v6 != 0, v4 + 1470, (__int64)"CVP_NOC_ERL_MAIN_MAINCTL_LOW", v12);
    v13 = _read_register(v7, 0xD0010u);
    _err_log(v6 != 0, v4 + 1471, (__int64)"CVP_NOC_ERL_MAIN_ERRVLD_LOW", v13);
    v14 = _read_register(v7, 0xD0018u);
    _err_log(v6 != 0, v4 + 1472, (__int64)"CVP_NOC_ERL_MAIN_ERRCLR_LOW", v14);
    v15 = _read_register(v7, 0xD0020u);
    _err_log(v6 != 0, v4 + 1473, (__int64)"CVP_NOC_ERL_MAIN_ERRLOG0_LOW", v15);
    v16 = _read_register(v7, 0xD0024u);
    _err_log(v6 != 0, v4 + 1474, (__int64)"CVP_NOC_ERL_MAIN_ERRLOG0_HIGH", v16);
    v17 = _read_register(v7, 0xD0028u);
    _err_log(v6 != 0, v4 + 1475, (__int64)"CVP_NOC_ERL_MAIN_ERRLOG1_LOW", v17);
    v18 = _read_register(v7, 0xD002Cu);
    _err_log(v6 != 0, v4 + 1476, (__int64)"CVP_NOC_ERL_MAIN_ERRLOG1_HIGH", v18);
    v19 = _read_register(v7, 0xD0030u);
    _err_log(v6 != 0, v4 + 1477, (__int64)"CVP_NOC_ERL_MAIN_ERRLOG2_LOW", v19);
    v20 = _read_register(v7, 0xD0034u);
    _err_log(v6 != 0, v4 + 1478, (__int64)"CVP_NOC_ERL_MAIN_ERRLOG2_HIGH", v20);
    v21 = _read_register(v7, 0xD0038u);
    _err_log(v6 != 0, v4 + 1479, (__int64)"CVP_NOC_ERL_MAIN_ERRLOG3_LOW", v21);
    v22 = _read_register(v7, 0xD003Cu);
    _err_log(v6 != 0, v4 + 1480, (__int64)"CVP_NOC_ERL_MAIN_ERRLOG3_HIGH", v22);
    v23 = _read_register(v7, 0x1A000u);
    _err_log(v6 != 0, v4 + 1481, (__int64)"CVP_NOC__CORE_ERL_MAIN_SWID_LOW", v23);
    v24 = _read_register(v7, 0x1A004u);
    _err_log(v6 != 0, v4 + 1482, (__int64)"CVP_NOC_CORE_ERL_MAIN_SWID_HIGH", v24);
    v25 = _read_register(v7, 0x1A008u);
    _err_log(v6 != 0, v4 + 1483, (__int64)"CVP_NOC_CORE_ERL_MAIN_MAINCTL_LOW", v25);
    v26 = _read_register(v7, 0x1A010u);
    _err_log(v6 != 0, v4 + 1484, (__int64)"CVP_NOC_CORE_ERL_MAIN_ERRVLD_LOW", v26);
    v27 = _read_register(v7, 0x1A018u);
    _err_log(v6 != 0, v4 + 1485, (__int64)"CVP_NOC_CORE_ERL_MAIN_ERRCLR_LOW", v27);
    v28 = _read_register(v7, 0x1A020u);
    _err_log(v6 != 0, v4 + 1486, (__int64)"CVP_NOC_CORE_ERL_MAIN_ERRLOG0_LOW", v28);
    v29 = _read_register(v7, 0x1A024u);
    _err_log(v6 != 0, v4 + 1487, (__int64)"CVP_NOC_CORE_ERL_MAIN_ERRLOG0_HIGH", v29);
    v30 = _read_register(v7, 0x1A028u);
    _err_log(v6 != 0, v4 + 1488, (__int64)"CVP_NOC_CORE_ERL_MAIN_ERRLOG1_LOW", v30);
    v31 = _read_register(v7, 0x1A02Cu);
    _err_log(v6 != 0, v4 + 1489, (__int64)"CVP_NOC_CORE_ERL_MAIN_ERRLOG1_HIGH", v31);
    _print_reg_details_errlog1_high();
    v32 = _read_register(v7, 0x1A030u);
    _err_log(v6 != 0, v4 + 1490, (__int64)"CVP_NOC_CORE_ERL_MAIN_ERRLOG2_LOW", v32);
    v33 = _read_register(v7, 0x1A034u);
    _err_log(v6 != 0, v4 + 1491, (__int64)"CVP_NOC_CORE_ERL_MAIN_ERRLOG2_HIGH", v33);
    v34 = _read_register(v7, 0x1A038u);
    _err_log(v6 != 0, v4 + 1492, (__int64)"CORE ERRLOG3_LOW, below details", v34);
    _print_reg_details_errlog3_low_kaanapali(v34, v35, v36, v37, v38, v39, v40);
    v41 = _read_register(v7, 0x1A03Cu);
    _err_log(v6 != 0, v4 + 1493, (__int64)"CVP_NOC_CORE_ERL_MAIN_ERRLOG3_HIGH", v41);
    _write_register(v7, 0x1A018u, 1u);
    _write_register(v7, 8u, 0);
    _write_register(v7, 0xCu, 0x3Fu);
    return _write_register(v7, 0xB0088u, 0);
  }
  return result;
}
