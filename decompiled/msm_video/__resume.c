__int64 __fastcall _resume(__int64 a1)
{
  __int64 result; // x0
  __int64 v3; // x4
  __int64 v4; // x4
  unsigned int v5; // w19
  void *v6; // x0
  unsigned int v7; // w0
  unsigned int v8; // w20
  unsigned int v9; // w19
  __int64 v10; // x8
  __int64 (__fastcall *v11)(_QWORD); // x9
  unsigned int v12; // w0
  __int64 v13; // x4
  void *v14; // x0
  void (__fastcall *v15)(_QWORD); // x8
  __int64 v16; // x8
  __int64 (__fastcall *v17)(__int64, __int64); // x8
  __int64 v18; // x4
  __int64 v19; // x8
  void (__fastcall *v20)(_QWORD); // x8

  if ( is_core_sub_state(a1, 1) )
    return 0;
  if ( !core_in_valid_state(a1) )
  {
    if ( (msm_vidc_debug & 1) != 0 )
    {
      v6 = &unk_8276C;
LABEL_17:
      printk(v6, "err ", 0xFFFFFFFFLL, "codec", "__resume");
      return 4294967274LL;
    }
    return 4294967274LL;
  }
  if ( (mutex_is_locked(a1 + 3856) & 1) == 0 )
  {
    __break(0x800u);
    if ( (msm_vidc_debug & 1) != 0 )
    {
      v6 = &unk_94E60;
      goto LABEL_17;
    }
    return 4294967274LL;
  }
  if ( (msm_vidc_debug & 2) != 0 )
    printk(&unk_8EA9E, "high", 0xFFFFFFFFLL, "codec", v3);
  if ( (*(_BYTE *)(a1 + 4768) & 1) != 0 )
    return 4294967274LL;
  result = msm_vidc_change_core_sub_state(a1, 2u, 0, (__int64)"__resume");
  if ( (_DWORD)result )
    return result;
  result = msm_vidc_change_core_sub_state(a1, 8u, 0, (__int64)"__resume");
  if ( (_DWORD)result )
    return result;
  result = _venus_power_on(a1);
  if ( (_DWORD)result )
  {
    if ( (msm_vidc_debug & 1) != 0 )
    {
      v5 = result;
      printk(&unk_7FE3C, "err ", 0xFFFFFFFFLL, "codec", v4);
      result = v5;
    }
    goto LABEL_22;
  }
  v7 = fw_resume();
  if ( v7 )
  {
    v8 = v7;
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_888BC, "err ", 0xFFFFFFFFLL, "codec", v7);
    goto LABEL_21;
  }
  if ( a1 )
  {
    v10 = *(_QWORD *)(a1 + 6544);
    if ( v10 )
    {
      v11 = *(__int64 (__fastcall **)(_QWORD))v10;
      if ( !*(_QWORD *)v10 )
        goto LABEL_34;
      if ( *((_DWORD *)v11 - 1) != -1850880742 )
        __break(0x8229u);
      v12 = v11(a1);
      if ( v12 )
      {
        if ( (msm_vidc_debug & 1) != 0 )
        {
          v8 = v12;
          v14 = &unk_8D0CD;
LABEL_61:
          printk(v14, "err ", 0xFFFFFFFFLL, "codec", v13);
          goto LABEL_45;
        }
        goto LABEL_44;
      }
      v10 = *(_QWORD *)(a1 + 6544);
      if ( v10 )
      {
LABEL_34:
        v15 = *(void (__fastcall **)(_QWORD))(v10 + 72);
        if ( v15 )
        {
          if ( *((_DWORD *)v15 - 1) != -1850880742 )
            __break(0x8228u);
          v15(a1);
        }
      }
    }
    _sys_set_debug(a1, msm_fw_debug & 0xFFFFFFF);
    v16 = *(_QWORD *)(a1 + 6552);
    if ( v16 )
    {
      v17 = *(__int64 (__fastcall **)(__int64, __int64))(v16 + 88);
      if ( v17 )
      {
        if ( *((_DWORD *)v17 - 1) != -254569353 )
          __break(0x8228u);
        v12 = v17(a1, 1);
        if ( v12 )
        {
          if ( (msm_vidc_debug & 1) != 0 )
          {
            v8 = v12;
            v14 = &unk_895B7;
            goto LABEL_61;
          }
LABEL_44:
          v8 = v12;
LABEL_45:
          fw_suspend();
LABEL_21:
          _venus_power_off(a1);
          result = v8;
LABEL_22:
          if ( (msm_vidc_debug & 1) != 0 )
          {
            v9 = result;
            printk(&unk_8F62E, "err ", 0xFFFFFFFFLL, "codec", v4);
            return v9;
          }
          return result;
        }
      }
    }
  }
  else
  {
    _sys_set_debug(0, msm_fw_debug & 0xFFFFFFF);
  }
  _set_subcaches(a1);
  if ( (unsigned int)_sys_set_power_control(a1) )
  {
    if ( (msm_vidc_debug & 1) != 0 )
    {
      printk(&unk_966FF, "err ", 0xFFFFFFFFLL, "codec", "__resume");
      if ( a1 )
        goto LABEL_49;
    }
    else if ( a1 )
    {
LABEL_49:
      v19 = *(_QWORD *)(a1 + 6544);
      if ( v19 )
      {
        v20 = *(void (__fastcall **)(_QWORD))(v19 + 80);
        if ( v20 )
        {
          if ( *((_DWORD *)v20 - 1) != -1850880742 )
            __break(0x8228u);
          v20(a1);
        }
      }
    }
  }
  if ( (msm_vidc_debug & 2) == 0 )
    return 0;
  printk(&unk_96738, "high", 0xFFFFFFFFLL, "codec", v18);
  return 0;
}
