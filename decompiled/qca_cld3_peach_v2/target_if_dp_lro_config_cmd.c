__int64 __fastcall target_if_dp_lro_config_cmd(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8
  __int64 v11; // x19
  __int64 result; // x0
  _QWORD v14[8]; // [xsp+14h] [xbp-4Ch] BYREF
  int v15; // [xsp+54h] [xbp-Ch]
  __int64 v16; // [xsp+58h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15 = 0;
  memset(v14, 0, sizeof(v14));
  if ( a1 && (v10 = *(_QWORD *)(a1 + 2800)) != 0 && a2 && (v11 = *(_QWORD *)(v10 + 16)) != 0 )
  {
    qdf_mem_copy(v14, (const void *)(a2 + 8), 0x14u);
    qdf_mem_copy((char *)&v14[2] + 4, (const void *)(a2 + 28), 0x2Cu);
    result = wmi_unified_lro_config_cmd(v11);
  }
  else
  {
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: wmi_handle or dp_lro_cmd is null",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "target_if_dp_lro_config_cmd");
    result = 16;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
