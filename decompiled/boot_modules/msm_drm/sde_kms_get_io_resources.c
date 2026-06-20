__int64 __fastcall sde_kms_get_io_resources(__int64 a1, __int64 a2)
{
  __int64 v4; // x21
  unsigned int io_mem; // w0
  unsigned int pmic_io_mem; // w0
  unsigned int io_irq; // w0
  __int64 result; // x0
  unsigned int v9; // w19
  void *v10; // x0

  v4 = *(_QWORD *)(*(_QWORD *)(a1 + 136) + 8LL) - 16LL;
  io_mem = msm_dss_get_io_mem(v4, a2 + 16);
  if ( io_mem )
  {
    v9 = io_mem;
    v10 = &unk_27DA61;
  }
  else
  {
    pmic_io_mem = msm_dss_get_pmic_io_mem(v4, a2 + 16);
    if ( pmic_io_mem )
    {
      v9 = pmic_io_mem;
      v10 = &unk_2463F5;
    }
    else
    {
      io_irq = msm_dss_get_io_irq(v4, a2, 0);
      if ( io_irq )
      {
        v9 = io_irq;
        v10 = &unk_23F682;
      }
      else
      {
        result = sde_kms_get_tvm_inclusion_mem(*(_QWORD *)(a1 + 152), (__int64 *)(a2 + 16));
        if ( !(_DWORD)result )
          return result;
        v9 = result;
        v10 = &unk_23BDEA;
      }
    }
  }
  printk(v10, "sde_kms_get_io_resources");
  return v9;
}
