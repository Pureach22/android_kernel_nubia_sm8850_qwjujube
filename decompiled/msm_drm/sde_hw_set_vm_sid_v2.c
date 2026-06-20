__int64 __fastcall sde_hw_set_vm_sid_v2(__int64 result, int a2, __int64 a3)
{
  unsigned int v4; // w20
  __int64 v5; // x19
  unsigned int v6; // w24
  unsigned int v7; // w22
  unsigned int v8; // w25
  unsigned int v9; // w22
  unsigned int v10; // w24
  unsigned int v11; // w22

  if ( result && a3 )
  {
    v4 = 4 * a2;
    v5 = result;
    if ( *(_DWORD *)(a3 + 5448) )
    {
      v6 = 0;
      v7 = 256;
      do
      {
        sde_reg_write(v5, v7, v4, "offset");
        ++v6;
        v7 += 4;
      }
      while ( v6 < *(_DWORD *)(a3 + 5448) );
    }
    if ( *(_DWORD *)(a3 + 19968) )
    {
      v8 = 0;
      v9 = 1024;
      do
      {
        sde_reg_write(v5, v9, v4, "offset");
        ++v8;
        v9 += 4;
      }
      while ( v8 < *(_DWORD *)(a3 + 19968) );
    }
    if ( *(_DWORD *)(v5 + 20) >> 29 >= 5u && *(_DWORD *)(a3 + 5448) )
    {
      v10 = 0;
      v11 = 784;
      do
      {
        sde_reg_write(v5, v11, v4, "offset");
        ++v10;
        v11 += 4;
      }
      while ( v10 < *(_DWORD *)(a3 + 5448) );
    }
    sde_reg_write(v5, 0x200u, v4, "MDP_SID_V2_IPC_READ");
    sde_reg_write(v5, 0x300u, v4, "MDP_SID_V2_LUTDMA_RD");
    sde_reg_write(v5, 0x304u, v4, "MDP_SID_V2_LUTDMA_WR");
    sde_reg_write(v5, 0x308u, v4, "MDP_SID_V2_LUTDMA_SB_RD");
    sde_reg_write(v5, 0x500u, v4, "MDP_SID_V2_DSI0");
    return sde_reg_write(v5, 0x504u, v4, "MDP_SID_V2_DSI1");
  }
  return result;
}
