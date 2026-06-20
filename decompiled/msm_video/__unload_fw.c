__int64 __fastcall _unload_fw(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x8
  __int64 (__fastcall *v3)(_QWORD); // x8
  unsigned int v4; // w0

  if ( *(_DWORD *)(*(_QWORD *)(result + 3904) + 144LL) )
  {
    v1 = result;
    cancel_delayed_work(result + 6112);
    if ( is_core_sub_state(v1, 1) )
    {
      if ( !v1 )
        goto LABEL_11;
      v2 = *(_QWORD *)(v1 + 6544);
      if ( !v2 )
        goto LABEL_11;
      v3 = *(__int64 (__fastcall **)(_QWORD))(v2 + 40);
      if ( !v3 )
        goto LABEL_11;
      if ( *((_DWORD *)v3 - 1) != -1850880742 )
        __break(0x8228u);
      v4 = v3(v1);
      if ( v4 )
      {
        if ( (msm_vidc_debug & 1) != 0 )
          printk(&unk_8DE17, "err ", 0xFFFFFFFFLL, "codec", v4);
      }
      else
      {
LABEL_11:
        msm_vidc_change_core_sub_state(v1, 1u, 0, (__int64)"__venus_power_off");
      }
    }
    fw_unload(v1);
    result = msm_vidc_change_core_sub_state(v1, 0xFFu, 0, (__int64)"__unload_fw");
    if ( (msm_vidc_debug & 2) != 0 )
      return printk(&unk_90F83, "high", 0xFFFFFFFFLL, "codec", "__unload_fw");
  }
  return result;
}
