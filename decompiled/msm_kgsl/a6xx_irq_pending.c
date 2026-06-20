bool __fastcall a6xx_irq_pending(__int64 a1)
{
  _DWORD *v1; // x19

  v1 = (_DWORD *)(a1 + 20416);
  return (*(_DWORD *)(a1 + 20888) & (unsigned int)kgsl_regmap_read(a1 + 13200)) != 0 || *v1 != 0;
}
