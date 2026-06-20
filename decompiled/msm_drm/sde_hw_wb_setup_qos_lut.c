__int64 __fastcall sde_hw_wb_setup_qos_lut(__int64 result, __int64 a2)
{
  __int64 v3; // x19
  __int64 v4; // x8
  unsigned int v5; // w21

  if ( result && a2 )
  {
    v3 = result;
    sde_reg_write(result, 0x84u, *(_DWORD *)a2, "WB_DANGER_LUT");
    sde_reg_write(v3, 0x88u, *(_DWORD *)(a2 + 4), "WB_SAFE_LUT");
    v4 = *(_QWORD *)(v3 + 56);
    if ( v4 && (*(_QWORD *)(v4 + 32) & 0x200) != 0 )
    {
      sde_reg_write(v3, 0x98u, *(_DWORD *)(a2 + 8), "WB_CREQ_LUT_0");
      sde_reg_write(v3, 0x9Cu, *(_DWORD *)(a2 + 12), "WB_CREQ_LUT_1");
      v4 = *(_QWORD *)(v3 + 56);
    }
    v5 = *(unsigned __int8 *)(a2 + 24);
    if ( (*(_QWORD *)(v4 + 32) & 0x200000) != 0 )
    {
      sde_reg_write(v3, 0x40u, *(unsigned __int8 *)(a2 + 16), "WB_TS_WR_CLIENT");
      v5 |= 2 * *(_DWORD *)(a2 + 20);
    }
    return sde_reg_write(v3, 0x90u, v5, "WB_QOS_CTRL");
  }
  return result;
}
