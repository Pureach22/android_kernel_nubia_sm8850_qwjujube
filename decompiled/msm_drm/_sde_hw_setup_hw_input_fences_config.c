__int64 __fastcall sde_hw_setup_hw_input_fences_config(unsigned int a1, int a2, unsigned int a3, __int64 a4, char a5)
{
  unsigned int v8; // w2
  unsigned int v9; // w22

  if ( a1 == 4 )
    v8 = 3;
  else
    v8 = a1;
  if ( (a5 & 1) != 0 )
    v9 = 0xFFFF;
  else
    v9 = -1;
  sde_reg_write(a4, a3, v8, "hw_fence_mdp_offset");
  sde_reg_write(a4, a3 + 32, 7u, "hw_fence_mdp_offset + MDP_CTL_HW_FENCE_QOS");
  sde_reg_write(a4, a3 + 4, 0x40000u, "hw_fence_mdp_offset + MDP_CTL_HW_FENCE_ID_START_ADDR");
  sde_reg_write(a4, a3 + 84, a2 + 16, "offset");
  sde_reg_write(a4, a3 + 96, 0x10021u, "offset");
  sde_reg_write(a4, a3 + 92, v9, "offset");
  sde_reg_write(a4, a3 + 108, 1u, "offset");
  sde_reg_write(a4, a3 + 80, 0, "offset");
  sde_reg_write(a4, a3 + 100, 0x10007u, "offset");
  return sde_reg_write(a4, a3 + 120, 0xFu, "offset");
}
