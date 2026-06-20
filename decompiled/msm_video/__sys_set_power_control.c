__int64 __fastcall _sys_set_power_control(__int64 a1)
{
  __int64 result; // x0
  __int64 v3; // x20
  void *v4; // x0
  const char *v5; // x1

  if ( !is_core_sub_state(a1, 2) )
  {
    if ( (msm_vidc_debug & 1) != 0 )
    {
      v4 = &unk_8D11D;
      v5 = "err ";
      goto LABEL_11;
    }
    return 0;
  }
  if ( !core_in_valid_state(a1) )
  {
    if ( (msm_vidc_debug & 1) != 0 )
    {
      core_state_name(*(_DWORD *)(a1 + 3704));
      printk(&unk_86386, "err ", 0xFFFFFFFFLL, "codec", "__sys_set_power_control");
    }
    return 0;
  }
  result = hfi_packet_sys_intraframe_powercollapse(a1, *(_QWORD *)(a1 + 6464), *(_DWORD *)(a1 + 6472), 1);
  if ( !(_DWORD)result )
  {
    v3 = *(_QWORD *)(a1 + 6464);
    result = _resume(a1);
    if ( !(_DWORD)result )
    {
      result = venus_hfi_queue_cmd_write(a1, v3);
      if ( !(_DWORD)result )
      {
        _schedule_power_collapse_work(a1);
        result = msm_vidc_change_core_sub_state(a1, 0, 8u, (__int64)"__sys_set_power_control");
        if ( !(_DWORD)result )
        {
          if ( (msm_vidc_debug & 2) != 0 )
          {
            v4 = &unk_94ECC;
            v5 = "high";
LABEL_11:
            printk(v4, v5, 0xFFFFFFFFLL, "codec", "__sys_set_power_control");
            return 0;
          }
          return 0;
        }
      }
    }
  }
  return result;
}
