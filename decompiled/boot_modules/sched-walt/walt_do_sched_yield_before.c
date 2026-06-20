__int64 __fastcall walt_do_sched_yield_before(__int64 a1, _QWORD *a2)
{
  __int64 result; // x0
  _BYTE *v3; // x20
  char v5; // w8

  result = _ReadStatusReg(SP_EL0);
  if ( (_UNKNOWN *)result == &init_task )
    v3 = &vendor_data_pad;
  else
    v3 = (_BYTE *)(result + 5184);
  if ( (walt_disabled & 1) == 0 && *(int *)(result + 148) >= 100 )
  {
    result = walt_is_idle_task((char *)result);
    if ( (result & 1) == 0 )
    {
      if ( sysctl_force_frequent_yielder
        && !sched_boost_type
        && (pipeline_nr || sysctl_sched_heavy_nr | sysctl_sched_pipeline_util_thres && have_heavy_list)
        && (v3[191] & 0xC) != 0 )
      {
LABEL_15:
        *a2 = 1;
        return ((__int64 (__fastcall *)(_BYTE *))inject_sleep)(v3);
      }
      v5 = v3[386];
      if ( (v5 & 0x7Fu) >= 0x19 )
      {
        ++total_yield_cnt;
        if ( (unsigned __int8)contiguous_yielding_windows < 2u )
          return result;
        goto LABEL_15;
      }
      v3[386] = v5 + 1;
    }
  }
  return result;
}
