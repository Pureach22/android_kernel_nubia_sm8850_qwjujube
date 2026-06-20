__int64 __fastcall _venus_power_off(__int64 a1)
{
  __int64 result; // x0
  __int64 v3; // x8
  __int64 (__fastcall *v4)(_QWORD); // x8

  result = is_core_sub_state(a1, 1);
  if ( (result & 1) != 0 )
  {
    if ( !a1 )
      return msm_vidc_change_core_sub_state(a1, 1u, 0, (__int64)"__venus_power_off");
    v3 = *(_QWORD *)(a1 + 6544);
    if ( !v3 )
      return msm_vidc_change_core_sub_state(a1, 1u, 0, (__int64)"__venus_power_off");
    v4 = *(__int64 (__fastcall **)(_QWORD))(v3 + 40);
    if ( !v4 )
      return msm_vidc_change_core_sub_state(a1, 1u, 0, (__int64)"__venus_power_off");
    if ( *((_DWORD *)v4 - 1) != -1850880742 )
      __break(0x8228u);
    result = v4(a1);
    if ( (_DWORD)result )
    {
      if ( (msm_vidc_debug & 1) != 0 )
        return printk(&unk_8DE17, "err ", 0xFFFFFFFFLL, "codec", (unsigned int)result);
    }
    else
    {
      return msm_vidc_change_core_sub_state(a1, 1u, 0, (__int64)"__venus_power_off");
    }
  }
  return result;
}
