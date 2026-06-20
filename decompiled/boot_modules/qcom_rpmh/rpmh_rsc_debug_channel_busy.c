__int64 __fastcall rpmh_rsc_debug_channel_busy(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  unsigned int v7; // w21
  unsigned int v8; // w22
  unsigned int v9; // w23
  unsigned int v10; // w24
  unsigned int v11; // w25
  unsigned int v12; // w26
  unsigned int v13; // w27
  __int64 v14; // x4
  __int64 v15; // x5
  __int64 v16; // x5
  __int64 v17; // x4
  __int64 v18; // x5

  printk(&unk_DCEB, "qcom_rpmh", a1, a4, a5, a6);
  v7 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 24) + *(unsigned int *)(*(_QWORD *)(a1 + 1664) + 68LL)));
  v8 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 24) + *(unsigned int *)(*(_QWORD *)(a1 + 1664) + 64LL)));
  v9 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 24) + *(unsigned int *)(*(_QWORD *)(a1 + 1664) + 80LL)));
  v10 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 24) + *(unsigned int *)(*(_QWORD *)(a1 + 1664) + 84LL)));
  v11 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 24) + *(unsigned int *)(*(_QWORD *)(a1 + 1664) + 88LL)));
  v12 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 24) + *(unsigned int *)(*(_QWORD *)(a1 + 1664) + 72LL)));
  v13 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 24) + *(unsigned int *)(*(_QWORD *)(a1 + 1664) + 76LL)));
  printk(&unk_DD5D, "qcom_rpmh", v7, v8, v14, v15);
  printk(&unk_D8E0, "qcom_rpmh", v9, v10, v11, v16);
  printk(&unk_D96A, "qcom_rpmh", v12, v13, v17, v18);
  crm_dump_regs("cam_crm");
  return crm_dump_drv_regs("cam_crm", *(unsigned int *)(a1 + 44));
}
