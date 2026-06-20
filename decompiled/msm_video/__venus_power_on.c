__int64 __fastcall _venus_power_on(__int64 a1)
{
  __int64 result; // x0
  __int64 v3; // x8
  __int64 (__fastcall *v4)(_QWORD); // x8
  unsigned int v5; // w19

  if ( is_core_sub_state(a1, 1) )
    return 0;
  if ( !a1 )
    return msm_vidc_change_core_sub_state(a1, 0, 1u, (__int64)"__venus_power_on");
  v3 = *(_QWORD *)(a1 + 6544);
  if ( !v3 )
    return msm_vidc_change_core_sub_state(a1, 0, 1u, (__int64)"__venus_power_on");
  v4 = *(__int64 (__fastcall **)(_QWORD))(v3 + 32);
  if ( !v4 )
    return msm_vidc_change_core_sub_state(a1, 0, 1u, (__int64)"__venus_power_on");
  if ( *((_DWORD *)v4 - 1) != -1850880742 )
    __break(0x8228u);
  result = v4(a1);
  if ( !(_DWORD)result )
    return msm_vidc_change_core_sub_state(a1, 0, 1u, (__int64)"__venus_power_on");
  if ( (msm_vidc_debug & 1) != 0 )
  {
    v5 = result;
    printk(&unk_81A64, "err ", 0xFFFFFFFFLL, "codec", (unsigned int)result);
    return v5;
  }
  return result;
}
