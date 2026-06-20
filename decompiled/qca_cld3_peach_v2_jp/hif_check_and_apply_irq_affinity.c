__int64 __fastcall hif_check_and_apply_irq_affinity(__int64 a1, unsigned __int8 a2, unsigned int a3)
{
  __int64 result; // x0
  unsigned int *v7; // x25
  unsigned __int64 v8; // x26
  __int64 v9; // x27
  unsigned int *v10; // x21
  unsigned int v11; // w23
  __int64 v12; // x0
  int v13; // w24
  _QWORD v14[2]; // [xsp+0h] [xbp-10h] BYREF

  v14[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14[0] = 0;
  qdf_cpumask_clear(v14);
  result = qdf_cpumask_set_cpu(a3, v14);
  if ( *(_DWORD *)(a1 + 27264) <= (unsigned int)a2 )
  {
    result = qdf_trace_msg(61, 8, "%s: Invalid group id received %d", "hif_check_and_apply_irq_affinity", a2);
  }
  else
  {
    if ( a2 >= 0x12u )
      goto LABEL_16;
    v7 = *(unsigned int **)(a1 + 8LL * a2 + 27120);
    if ( v7[4] )
    {
      v8 = 0;
      v9 = 682;
      while ( v8 != 26 )
      {
        if ( (qdf_cpumask_equal(&v7[v9], v14) & 1) != 0 )
        {
          result = qdf_trace_msg(
                     61,
                     8,
                     "%s: Skip affining same cpu for grp_id %d cpu_mask %*pbl",
                     "hif_check_and_apply_irq_affinity",
                     v7[58],
                     nr_cpu_ids,
                     v14);
        }
        else
        {
          if ( v8 == 25 )
            break;
          v10 = &v7[v8];
          v11 = v10[30];
          irq_modify_status(v11, 0x2000, 0);
          v12 = _irq_apply_affinity_hint(v11, v14, 1);
          v13 = qdf_status_from_os_return(v12);
          irq_modify_status(v11, 0, 0x2000);
          if ( v13 )
          {
            result = qdf_trace_msg(
                       61,
                       2,
                       "%s: set affinity failed for IRQ %d",
                       "hif_check_and_apply_irq_affinity",
                       v10[30]);
          }
          else
          {
            qdf_cpumask_copy(&v7[v9], v14);
            v7[732] = -1;
            result = qdf_trace_msg(
                       61,
                       8,
                       "%s: Affined IRQ %d to cpu_mask %*pbl",
                       "hif_check_and_apply_irq_affinity",
                       v10[30],
                       nr_cpu_ids,
                       &v7[v9]);
          }
        }
        ++v8;
        v9 += 2;
        if ( v8 >= v7[4] )
          goto LABEL_15;
      }
LABEL_16:
      __break(0x5512u);
    }
  }
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
