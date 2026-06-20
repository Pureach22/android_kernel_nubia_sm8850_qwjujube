__int64 __fastcall _power_collapse(__int64 a1, char a2)
{
  __int64 v4; // x1
  __int64 result; // x0
  __int64 v6; // x8
  unsigned int (__fastcall *v7)(_QWORD); // x8
  __int64 v8; // x4
  __int64 v9; // x4
  void *v10; // x0
  __int64 v11; // x8
  _DWORD *v12; // x8
  __int64 v13; // x8
  __int64 (__fastcall *v14)(_QWORD); // x8
  unsigned int v15; // w0
  unsigned int v16; // w19
  unsigned int v17; // w19

  if ( !is_core_sub_state(a1, 1) )
  {
    if ( (msm_vidc_debug & 2) != 0 )
      printk(&unk_96D24, "high", 0xFFFFFFFFLL, "codec", "__power_collapse");
    return 0;
  }
  if ( core_in_valid_state(a1) )
  {
    if ( (a2 & 1) != 0 )
      v4 = 0;
    else
      v4 = *(_QWORD *)(a1 + 6464);
    _flush_debug_queue(a1, v4, *(unsigned int *)(a1 + 6472));
    if ( a1 )
    {
      v6 = *(_QWORD *)(a1 + 6544);
      if ( v6 )
      {
        v7 = *(unsigned int (__fastcall **)(_QWORD))(v6 + 24);
        if ( v7 )
        {
          if ( *((_DWORD *)v7 - 1) != -1850880742 )
            __break(0x8228u);
          if ( v7(a1) )
          {
            if ( (msm_vidc_debug & 1) != 0 )
              printk(&unk_8D16C, "err ", 0xFFFFFFFFLL, "codec", "__power_collapse");
            return 4294967285LL;
          }
        }
      }
    }
    if ( !is_core_sub_state(a1, 1) )
    {
      if ( (msm_vidc_debug & 2) == 0 )
        return 0;
      v10 = &unk_84718;
LABEL_30:
      printk(v10, "high", 0xFFFFFFFFLL, "codec", v8);
      return 0;
    }
    if ( (mutex_is_locked(a1 + 3856) & 1) == 0 )
    {
      __break(0x800u);
      if ( (msm_vidc_debug & 1) != 0 )
        printk(&unk_94E60, "err ", 0xFFFFFFFFLL, "codec", "__suspend");
      result = 4294967274LL;
      goto LABEL_34;
    }
    if ( (msm_vidc_debug & 2) != 0 )
      printk(&unk_81A9C, "high", 0xFFFFFFFFLL, "codec", v9);
    if ( (*(_BYTE *)(a1 + 4768) & 1) != 0 )
    {
      result = msm_vidc_change_core_sub_state(a1, 1u, 0, (__int64)"__suspend");
      if ( !(_DWORD)result )
        return result;
      goto LABEL_34;
    }
    result = fw_suspend();
    if ( (_DWORD)result )
    {
      if ( (msm_vidc_debug & 1) != 0 )
      {
        v17 = result;
        printk(&unk_8F6D3, "err ", 0xFFFFFFFFLL, "codec", (unsigned int)result);
        result = v17;
      }
LABEL_34:
      if ( (msm_vidc_debug & 1) != 0 )
      {
        v16 = result;
        printk(&unk_8893B, "err ", 0xFFFFFFFFLL, "codec", v9);
        return v16;
      }
      return result;
    }
    if ( a1 )
    {
      v11 = *(_QWORD *)(a1 + 6552);
      if ( v11 )
      {
        v12 = *(_DWORD **)(v11 + 88);
        if ( v12 )
        {
          if ( *(v12 - 1) != -254569353 )
            __break(0x8228u);
          ((void (__fastcall *)(__int64, _QWORD))v12)(a1, 0);
        }
      }
      if ( !is_core_sub_state(a1, 1) )
        goto LABEL_53;
      v13 = *(_QWORD *)(a1 + 6544);
      if ( v13 )
      {
        v14 = *(__int64 (__fastcall **)(_QWORD))(v13 + 40);
        if ( v14 )
        {
          if ( *((_DWORD *)v14 - 1) != -1850880742 )
            __break(0x8228u);
          v15 = v14(a1);
          if ( v15 )
          {
            if ( (msm_vidc_debug & 1) != 0 )
              printk(&unk_8DE17, "err ", 0xFFFFFFFFLL, "codec", v15);
            goto LABEL_53;
          }
        }
      }
    }
    else if ( !is_core_sub_state(0, 1) )
    {
LABEL_53:
      if ( (msm_vidc_debug & 2) == 0 )
        return 0;
      v10 = &unk_9345D;
      goto LABEL_30;
    }
    msm_vidc_change_core_sub_state(a1, 1u, 0, (__int64)"__venus_power_off");
    goto LABEL_53;
  }
  if ( (msm_vidc_debug & 1) != 0 )
    printk(&unk_89607, "err ", 0xFFFFFFFFLL, "codec", "__power_collapse");
  return 4294967274LL;
}
