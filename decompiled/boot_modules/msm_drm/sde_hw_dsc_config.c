__int64 __fastcall sde_hw_dsc_config(__int64 a1, unsigned __int8 *a2, unsigned int a3, char a4)
{
  int v6; // w22
  int v8; // w8

  v6 = *((_DWORD *)a2 + 35);
  sde_reg_write(a1, 0, a3, "DSC_COMMON_MODE");
  if ( (a4 & 1) != 0 )
    v8 = 805306368;
  else
    v8 = 0;
  sde_reg_write(
    a1,
    4u,
    v8
  | (v6 << 20)
  | (*((_DWORD *)a2 + 41) << 18)
  | (*((unsigned __int16 *)a2 + 8) << 8)
  | (a2[26] << 7)
  | (8 * *a2)
  | (4 * a2[8])
  | (2 * a2[2])
  | (a2[1] == 10),
    "DSC_ENC");
  sde_reg_write(a1, 8u, *((unsigned __int16 *)a2 + 6) | (*((unsigned __int16 *)a2 + 5) << 16), "DSC_PICTURE");
  sde_reg_write(a1, 0xCu, *((unsigned __int16 *)a2 + 3) | (*((unsigned __int16 *)a2 + 2) << 16), "DSC_SLICE");
  sde_reg_write(a1, 0x10u, *((unsigned __int16 *)a2 + 61) << 16, "DSC_CHUNK_SIZE");
  sde_reg_write(a1, 0x14u, *(_DWORD *)(a2 + 22), "DSC_DELAY");
  sde_reg_write(a1, 0x18u, a2[108], "DSC_SCALE_INITIAL");
  sde_reg_write(a1, 0x1Cu, *((unsigned __int16 *)a2 + 55), "DSC_SCALE_DEC_INTERVAL");
  sde_reg_write(a1, 0x20u, *((unsigned __int16 *)a2 + 56), "DSC_SCALE_INC_INTERVAL");
  sde_reg_write(a1, 0x24u, a2[27], "DSC_FIRST_LINE_BPG_OFFSET");
  sde_reg_write(a1, 0x28u, *((unsigned __int16 *)a2 + 58) | (*((unsigned __int16 *)a2 + 57) << 16), "DSC_BPG_OFFSET");
  sde_reg_write(a1, 0x2Cu, *((unsigned __int16 *)a2 + 59) | (*((unsigned __int16 *)a2 + 14) << 16), "DSC_DSC_OFFSET");
  sde_reg_write(a1, 0x30u, (32 * a2[107]) | (*((_DWORD *)a2 + 46) << 10) | a2[106], "DSC_FLATNESS");
  sde_reg_write(a1, 0x34u, *((unsigned __int16 *)a2 + 52), "DSC_RC_MODEL_SIZE");
  return sde_reg_write(
           a1,
           0x38u,
           (a2[14] << 14) | (a2[15] << 18) | (a2[19] << 9) | (16 * a2[20]) | (unsigned int)a2[18],
           "DSC_RC");
}
