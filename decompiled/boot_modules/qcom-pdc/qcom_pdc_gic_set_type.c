__int64 __fastcall qcom_pdc_gic_set_type(__int64 a1, int a2)
{
  int v2; // w27
  __int64 v4; // x24
  unsigned int v5; // w20
  int v6; // w23
  int v7; // w0
  unsigned int v8; // w22
  int v9; // w21
  int v10; // w23
  int v11; // w8
  int v12; // w24
  unsigned __int64 v13; // x26
  __int64 result; // x0
  __int64 v15; // x28
  __int64 v16; // x8
  int v17; // w0
  unsigned int v18; // w8
  __int64 v19; // [xsp+0h] [xbp-20h]
  int v20; // [xsp+8h] [xbp-18h]
  int v21; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v22; // [xsp+18h] [xbp-8h]

  v2 = a2 - 1;
  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (unsigned int)(a2 - 1) >= 8 || ((0x8Fu >> v2) & 1) == 0 )
  {
    __break(0x800u);
    result = 4294967274LL;
    goto LABEL_9;
  }
  v4 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 8LL);
  v5 = dword_720C[v2];
  v6 = dword_722C[v2];
  v7 = readl_relaxed((unsigned int *)(pdc_base + 4LL * (unsigned int)*(_QWORD *)(a1 + 8) + 272));
  v8 = v7 & 0xFFFFFFF8 | v6;
  v9 = v7;
  writel_relaxed(v8, (unsigned int *)(pdc_base + 4LL * (unsigned int)*(_QWORD *)(a1 + 8) + 272));
  ipc_log_string(pdc_ipc_log, "Set type: PIN=%lu pdc_type=%d gic_type=%d", *(_QWORD *)(a1 + 8), v8, v5);
  v10 = v4 - 32;
  v11 = v4 - 1;
  if ( (int)v4 - 32 >= 0 )
    v11 = v4 - 32;
  if ( spi_cfg )
  {
    v12 = v11 >> 5;
    v13 = (unsigned int)(4 * (v11 >> 5));
    if ( *(_QWORD *)(spi_cfg + 8) < v13 )
    {
      result = 4294967282LL;
      goto LABEL_9;
    }
    v20 = v10 - (v11 & 0xFFFFFFE0);
    v15 = 1LL << (v10 - (v11 & 0xE0u));
    v19 = raw_spin_lock_irqsave(&pdc_lock);
    if ( *(_BYTE *)(spi_cfg + 16) == 1 )
    {
      v16 = *(_QWORD *)spi_cfg;
      v21 = 0;
      qcom_scm_io_readl(v16 + v13, &v21);
      v17 = v21;
    }
    else
    {
      v17 = readl(*(_QWORD *)spi_cfg + v13);
    }
    if ( (~v2 & 3) != 0 )
      v18 = v17 & ~(_DWORD)v15;
    else
      v18 = v17 | v15;
    if ( *(_BYTE *)(spi_cfg + 16) == 1 )
      qcom_scm_io_writel(*(_QWORD *)spi_cfg + v13, v18);
    else
      writel(v18, *(_QWORD *)spi_cfg + v13);
    ipc_log_string(pdc_ipc_log, "SPI config: GIC-SPI=%d (reg=%d,bit=%d) val=%d", v10, v12, v20, v5 & 4);
    raw_spin_unlock_irqrestore(&pdc_lock, v19);
  }
  result = irq_chip_set_type_parent(a1, v5);
  if ( !(_DWORD)result )
  {
    if ( v9 != v8 )
      irq_chip_set_parent_state(a1, 0, 0);
    result = 0;
  }
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
