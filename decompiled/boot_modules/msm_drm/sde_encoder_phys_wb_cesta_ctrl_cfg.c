void __fastcall sde_encoder_phys_wb_cesta_ctrl_cfg(__int64 a1, __int64 a2, _BYTE *a3)
{
  *(_DWORD *)(a2 + 16) = 0;
  *(_BYTE *)a2 = 1;
  *(_BYTE *)(a2 + 8) = 1;
  *(_BYTE *)(a2 + 12) = 0;
  *a3 = 1;
}
