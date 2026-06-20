__int64 *__fastcall msm_vidc_batch_handler(__int64 a1)
{
  __int64 *result; // x0
  __int64 v2; // x19
  __int64 v3; // x20
  __int64 v4; // x4
  void *v5; // x0
  const char *v6; // x1
  __int64 v7; // x4
  __int64 v8; // x1
  __int64 v9; // x2
  __int64 v10; // x3
  __int64 v11; // x4
  __int64 *i; // x20
  __int64 v13; // x4
  __int64 v14; // x0

  result = get_inst_ref(g_core, (__int64 *)(a1 - 3688));
  if ( result )
  {
    v2 = (__int64)result;
    v3 = result[40];
    mutex_lock(result + 2);
    if ( *(_DWORD *)(v2 + 160) == 5 )
    {
      if ( (msm_vidc_debug & 1) != 0 )
      {
        v5 = &unk_8A890;
        v6 = "err ";
LABEL_10:
        printk(v5, v6, v2 + 340, "msm_vidc_batch_handler", v4);
      }
    }
    else
    {
      if ( (is_core_sub_state(v3, 4) & 1) == 0 )
      {
        if ( (is_state(v2, 0) & 1) != 0 || (is_state(v2, 1) & 1) != 0 )
        {
          if ( (msm_vidc_debug & 1) != 0 )
          {
            v14 = state_name(*(unsigned int *)(v2 + 160));
            printk(&unk_86A0E, "err ", v2 + 340, "msm_vidc_batch_handler", v14);
          }
        }
        else
        {
          if ( (msm_vidc_debug & 2) != 0 )
            printk(&unk_89CD1, "high", v2 + 340, "msm_vidc_batch_handler", v7);
          msm_vidc_scale_power(v2, 1);
          for ( i = *(__int64 **)(v2 + 2544); i != (__int64 *)(v2 + 2544); i = (__int64 *)*i )
          {
            if ( (i[10] & 1) != 0
              && (unsigned int)((__int64 (__fastcall *)(__int64, __int64 *))msm_vidc_queue_buffer)(v2, i) )
            {
              if ( (msm_vidc_debug & 1) != 0 )
                printk(&unk_8A8C1, "err ", v2 + 340, "msm_vidc_batch_handler", v13);
              msm_vidc_change_state(v2, 5, "msm_vidc_batch_handler");
              goto LABEL_15;
            }
          }
        }
        goto LABEL_15;
      }
      if ( (msm_vidc_debug & 2) != 0 )
      {
        v5 = &unk_92498;
        v6 = "high";
        goto LABEL_10;
      }
    }
LABEL_15:
    mutex_unlock(v2 + 16);
    return (__int64 *)put_inst(v2, v8, v9, v10, v11);
  }
  if ( (msm_vidc_debug & 1) != 0 )
    return (__int64 *)printk(&unk_86867, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_batch_handler");
  return result;
}
