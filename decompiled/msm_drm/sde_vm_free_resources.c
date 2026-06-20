__int64 __fastcall sde_vm_free_resources(__int64 a1)
{
  msm_dss_clean_io_mem(a1 + 16);
  return msm_dss_clean_io_irq(a1);
}
