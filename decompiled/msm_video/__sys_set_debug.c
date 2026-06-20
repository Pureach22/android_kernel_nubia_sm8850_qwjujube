__int64 __fastcall _sys_set_debug(__int64 a1, int a2)
{
  __int64 result; // x0
  __int64 v4; // x4
  __int64 v5; // x20
  unsigned int v6; // w19

  result = hfi_packet_sys_debug_config((_DWORD *)a1, *(_QWORD *)(a1 + 6464), *(_DWORD *)(a1 + 6472), a2);
  if ( (_DWORD)result
    || (v5 = *(_QWORD *)(a1 + 6464), result = _resume(a1), (_DWORD)result)
    || (result = venus_hfi_queue_cmd_write(a1, v5), (_DWORD)result) )
  {
    if ( (msm_vidc_debug & 1) != 0 )
    {
      v6 = result;
      printk(&unk_85319, "err ", 0xFFFFFFFFLL, "codec", v4);
      return v6;
    }
  }
  else
  {
    _schedule_power_collapse_work(a1);
    return 0;
  }
  return result;
}
