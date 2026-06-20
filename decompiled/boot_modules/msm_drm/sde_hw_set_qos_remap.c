__int64 __fastcall sde_hw_set_qos_remap(__int64 result, unsigned int a2, int a3, char a4, char a5)
{
  char v5; // w24
  __int64 v8; // x21
  int v9; // w23
  int v10; // w22
  int v11; // w0
  int v12; // w9
  int v13; // w20

  if ( result )
  {
    v5 = 4 * (a2 & 7);
    v8 = result;
    v9 = (a2 >> 1) & 4 | (8 * a3);
    v10 = sde_reg_read(result, v9 + 1360);
    v11 = sde_reg_read(v8, v9 + 1424);
    v12 = (a4 & 7) << v5;
    v13 = v11 & ~(7 << v5);
    sde_reg_write(v8, v9 + 1360, v10 & ~(7 << v5) | v12, "VBIF_XINL_QOS_RP_REMAP_000 + reg_high");
    return sde_reg_write(
             v8,
             v9 + 1424,
             v13 | ((unsigned __int8)(a5 & 7) << v5),
             "VBIF_XINL_QOS_LVL_REMAP_000 + reg_high");
  }
  return result;
}
