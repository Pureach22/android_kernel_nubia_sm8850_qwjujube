__int64 __fastcall hif_affinity_mgr_set_irq_affinity(__int64 a1, unsigned int a2, __int64 a3, __int64 a4)
{
  __int64 cpus_taken; // x20
  unsigned __int64 StatusReg; // x22
  int v10; // w24
  __int64 v11; // x0
  unsigned int v12; // w20
  __int64 v13; // x8
  unsigned __int64 v14; // x8
  unsigned __int64 v15; // x8
  __int64 v16; // x22
  __int64 v18; // [xsp+8h] [xbp-28h] BYREF
  __int64 v19; // [xsp+10h] [xbp-20h] BYREF
  __int16 v20; // [xsp+18h] [xbp-18h]
  _QWORD v21[2]; // [xsp+20h] [xbp-10h] BYREF

  v21[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v20 = 0;
  v19 = 0;
  cpus_taken = qdf_walt_get_cpus_taken();
  v18 = cpus_taken;
  __isb(0xFu);
  StatusReg = _ReadStatusReg(CNTVCT_EL0);
  qdf_cpumask_copy(a3 + 8, a4);
  *(_BYTE *)(a3 + 40) = 1;
  v10 = hif_affinity_mgr_check_update_mask(a1, a3, cpus_taken, a4, StatusReg);
  irq_modify_status(a2, 0x2000, 0);
  v11 = _irq_apply_affinity_hint(a2, a4, 1);
  v12 = qdf_status_from_os_return(v11);
  irq_modify_status(a2, 0, 0x2000);
  if ( !v12 )
  {
    qdf_cpumask_copy(a3 + 16, &v18);
    qdf_cpumask_copy(a3, a4);
    if ( !v10 )
    {
      v13 = v18;
      *(_QWORD *)(a3 + 24) = StatusReg;
      v21[0] = v13;
      if ( (qdf_cpumask_equal(v21, a3 + 16) & 1) != 0
        || ((v14 = StatusReg - *(_QWORD *)(a3 + 32), 10 * v14 >= v14)
          ? (v15 = 10 * v14 / 0xC0)
          : (v15 = 10 * (v14 / 0xC0)),
            v15 >= *(_QWORD *)(a1 + 4200)) )
      {
        *(_QWORD *)(a3 + 32) = StatusReg;
        qdf_thread_cpumap_print_to_pagebuf(0, &v19, &v18);
        v16 = jiffies;
        if ( hif_affinity_mgr_set_irq_affinity___last_ticks - jiffies + 125 < 0 )
        {
          qdf_trace_msg(61, 4, "%s: Audio taken CPU mask: %s", "hif_affinity_mgr_set_irq_affinity", (const char *)&v19);
          hif_affinity_mgr_set_irq_affinity___last_ticks = v16;
        }
      }
    }
  }
  *(_BYTE *)(a3 + 40) = 0;
  _ReadStatusReg(SP_EL0);
  return v12;
}
