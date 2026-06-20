bool __fastcall task_reject_partialhalt_cpu_0(__int64 a1, unsigned int a2)
{
  return *(int *)(a1 + 148) >= 100
      && ((*(unsigned __int64 *)((char *)_cpu_partial_halt_mask + (((unsigned __int64)a2 >> 3) & 0x1FFFFFF8)) >> a2) & 1) != 0
      && (task_fits_capacity_0(a1, 0) & 1) == 0;
}
