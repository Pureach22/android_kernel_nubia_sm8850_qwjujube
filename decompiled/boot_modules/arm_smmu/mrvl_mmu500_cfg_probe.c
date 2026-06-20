__int64 __fastcall mrvl_mmu500_cfg_probe(__int64 a1)
{
  *(_DWORD *)(a1 + 32) &= 0xFFFFFC7F;
  return 0;
}
