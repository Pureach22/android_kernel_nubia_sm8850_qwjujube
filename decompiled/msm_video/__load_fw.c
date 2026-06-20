__int64 __fastcall _load_fw(_QWORD *a1)
{
  __int64 v2; // x8
  __int64 (__fastcall *v3)(_QWORD); // x8
  __int64 result; // x0
  unsigned int v5; // w19
  unsigned int v6; // w19
  unsigned int v7; // w0
  unsigned int v8; // w21
  __int64 v9; // x8
  __int64 (__fastcall *v10)(_QWORD); // x8
  unsigned int v11; // w0

  if ( (msm_vidc_debug & 2) != 0 )
    printk(&unk_9723C, "high", 0xFFFFFFFFLL, "codec", "__load_fw");
  msm_vidc_change_core_sub_state((__int64)a1, 0xFFu, 0, (__int64)"__load_fw");
  if ( !is_core_sub_state((__int64)a1, 1) )
  {
    if ( a1 )
    {
      v2 = a1[818];
      if ( v2 )
      {
        v3 = *(__int64 (__fastcall **)(_QWORD))(v2 + 32);
        if ( v3 )
        {
          if ( *((_DWORD *)v3 - 1) != -1850880742 )
            __break(0x8228u);
          result = v3(a1);
          if ( (_DWORD)result )
          {
            if ( (msm_vidc_debug & 1) != 0 )
            {
              v5 = result;
              printk(&unk_81A64, "err ", 0xFFFFFFFFLL, "codec", (unsigned int)result);
              result = v5;
            }
            goto LABEL_13;
          }
        }
      }
    }
    result = msm_vidc_change_core_sub_state((__int64)a1, 0, 1u, (__int64)"__venus_power_on");
    if ( (_DWORD)result )
    {
LABEL_13:
      if ( (msm_vidc_debug & 1) != 0 )
      {
        v6 = result;
        printk(&unk_827A4, "err ", 0xFFFFFFFFLL, "codec", "__load_fw");
        return v6;
      }
      return result;
    }
  }
  v7 = fw_load(a1);
  if ( !v7 )
    return 0;
  v8 = v7;
  if ( is_core_sub_state((__int64)a1, 1) )
  {
    if ( !a1 )
      goto LABEL_26;
    v9 = a1[818];
    if ( !v9 )
      goto LABEL_26;
    v10 = *(__int64 (__fastcall **)(_QWORD))(v9 + 40);
    if ( !v10 )
      goto LABEL_26;
    if ( *((_DWORD *)v10 - 1) != -1850880742 )
      __break(0x8228u);
    v11 = v10(a1);
    if ( v11 )
    {
      if ( (msm_vidc_debug & 1) != 0 )
        printk(&unk_8DE17, "err ", 0xFFFFFFFFLL, "codec", v11);
    }
    else
    {
LABEL_26:
      msm_vidc_change_core_sub_state((__int64)a1, 1u, 0, (__int64)"__venus_power_off");
    }
  }
  return v8;
}
