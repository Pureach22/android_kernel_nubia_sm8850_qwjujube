__int64 __fastcall sde_hw_setup_hw_fences_config_with_dir_write(__int64 *a1, unsigned int a2, __int64 a3)
{
  __int64 v3; // x8
  int v4; // w20
  __int64 v5; // x9
  __int64 v6; // x8
  __int64 v7; // x10
  __int64 v8; // x19
  __int64 v9; // x4
  __int64 result; // x0
  __int64 v11; // [xsp+8h] [xbp-28h] BYREF
  __int64 v12; // [xsp+10h] [xbp-20h]
  __int64 v13; // [xsp+18h] [xbp-18h]
  __int64 v14; // [xsp+20h] [xbp-10h]
  __int64 v15; // [xsp+28h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    v3 = a1[1];
    v4 = a3;
    v11 = *a1;
    v12 = v3;
    v5 = a1[5];
    v6 = a1[2];
    v7 = a1[3];
    v8 = *(unsigned int *)(v5 + 68);
    v9 = *(unsigned __int8 *)(v5 + 72);
    LODWORD(v12) = 0;
    v13 = v6;
    v14 = v7;
    sde_hw_setup_hw_input_fences_config(a2, a3, v8, &v11, v9);
    sde_reg_write((__int64)&v11, v8 + 164, v4 + 12, "offset");
    sde_reg_write((__int64)&v11, v8 + 176, 0x21u, "offset");
    sde_reg_write((__int64)&v11, v8 + 172, 0xFFFFFFFF, "offset");
    sde_reg_write((__int64)&v11, v8 + 160, 0x40006u, "offset");
    sde_reg_write((__int64)&v11, v8 + 180, 3u, "offset");
    sde_reg_write((__int64)&v11, v8 + 200, 0x104u, "offset");
    sde_reg_write((__int64)&v11, v8 + 220, 0x402u, "offset");
    result = sde_reg_write((__int64)&v11, (int)v8 + 240, 0xFu, "offset");
  }
  else
  {
    result = printk(&unk_269D2C, "sde_hw_setup_hw_fences_config_with_dir_write");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
