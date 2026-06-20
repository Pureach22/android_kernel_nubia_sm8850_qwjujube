__int64 __fastcall hdd_get_optimized_power_config(__int64 a1, __int64 a2)
{
  _QWORD *v3; // x20
  __int64 result; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x20
  _BYTE v14[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v15; // [xsp+8h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD **)(*(_QWORD *)a1 + 24LL);
  result = _wlan_hdd_validate_context(v3, "hdd_get_optimized_power_config");
  if ( !(_DWORD)result )
  {
    v14[0] = ucfg_pmo_get_power_save_mode(*v3);
    result = nla_put(a2, 71, 1, v14);
    if ( (_DWORD)result )
    {
      v13 = jiffies;
      if ( hdd_get_optimized_power_config___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: nla_put failure",
          v5,
          v6,
          v7,
          v8,
          v9,
          v10,
          v11,
          v12,
          "hdd_get_optimized_power_config");
        hdd_get_optimized_power_config___last_ticks = v13;
      }
      result = 4294967274LL;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
