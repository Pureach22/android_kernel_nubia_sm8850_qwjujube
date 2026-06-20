__int64 __fastcall venus_hfi_core_init(__int64 a1)
{
  __int64 result; // x0
  __int64 v3; // x8
  __int64 (__fastcall *v4)(_QWORD); // x9
  __int64 (__fastcall *v5)(_QWORD); // x8
  __int64 v6; // x8
  __int64 (__fastcall *v7)(__int64, __int64); // x8
  __int64 v8; // x1
  __int64 v9; // x2
  __int64 v10; // x3
  __int64 v11; // x4
  __int64 v12; // x8
  void (__fastcall *v13)(_QWORD); // x8
  unsigned int v14; // w19
  void *v15; // x0
  const char *v16; // x4

  if ( (msm_vidc_debug & 2) != 0 )
    printk(&unk_8A0CF, "high", 0xFFFFFFFFLL, "codec", "venus_hfi_core_init");
  if ( (mutex_is_locked(a1 + 3856) & 1) == 0 )
  {
    __break(0x800u);
    if ( (msm_vidc_debug & 1) == 0 )
      return 4294967274LL;
    v15 = &unk_94E60;
    v16 = "venus_hfi_core_init";
    goto LABEL_47;
  }
  result = venus_hfi_queue_init(a1);
  if ( (_DWORD)result )
    goto LABEL_5;
  if ( *(_BYTE *)(a1 + 4768) == 1 )
  {
    if ( (*(_BYTE *)(a1 + 4769) & 1) != 0 )
      return 0;
    if ( (msm_vidc_debug & 2) != 0 )
    {
      printk(&unk_97CCE, "high", 0xFFFFFFFFLL, "codec", "__core_init_full_virtualization");
      if ( (msm_vidc_debug & 1) == 0 )
        return 4294967274LL;
    }
    else if ( (msm_vidc_debug & 1) == 0 )
    {
      return 4294967274LL;
    }
    v15 = &unk_97D20;
    v16 = "__core_init_full_virtualization";
LABEL_47:
    printk(v15, "err ", 0xFFFFFFFFLL, "codec", v16);
    return 4294967274LL;
  }
  result = _load_fw((_QWORD *)a1);
  if ( !(_DWORD)result )
  {
    if ( !a1 )
      goto LABEL_54;
    v3 = *(_QWORD *)(a1 + 6544);
    if ( !v3 )
      goto LABEL_55;
    v4 = *(__int64 (__fastcall **)(_QWORD))v3;
    if ( *(_QWORD *)v3 )
    {
      if ( *((_DWORD *)v4 - 1) != -1850880742 )
        __break(0x8229u);
      result = v4(a1);
      if ( (_DWORD)result )
        goto LABEL_5;
      v3 = *(_QWORD *)(a1 + 6544);
      if ( !v3 )
        goto LABEL_55;
    }
    v5 = *(__int64 (__fastcall **)(_QWORD))(v3 + 72);
    if ( !v5 )
      goto LABEL_55;
    if ( *((_DWORD *)v5 - 1) != -1850880742 )
      __break(0x8228u);
    result = v5(a1);
    if ( !(_DWORD)result )
    {
LABEL_55:
      v6 = *(_QWORD *)(a1 + 6552);
      if ( !v6 )
        goto LABEL_54;
      v7 = *(__int64 (__fastcall **)(__int64, __int64))(v6 + 88);
      if ( !v7 )
        goto LABEL_54;
      if ( *((_DWORD *)v7 - 1) != -254569353 )
        __break(0x8228u);
      result = v7(a1, 1);
      if ( !(_DWORD)result )
      {
LABEL_54:
        result = _sys_init(a1);
        if ( !(_DWORD)result )
        {
          result = _sys_image_version(a1);
          if ( !(_DWORD)result )
          {
            result = _sys_set_debug(a1, msm_fw_debug & 0xFFFFFFF);
            if ( !(_DWORD)result )
            {
              result = _set_subcaches(a1, v8, v9, v10, v11);
              if ( !(_DWORD)result )
              {
                if ( !(unsigned int)_sys_set_power_control(a1) )
                  goto LABEL_40;
                if ( (msm_vidc_debug & 1) != 0 )
                {
                  printk(&unk_966FF, "err ", 0xFFFFFFFFLL, "codec", "venus_hfi_core_init");
                  if ( !a1 )
                    goto LABEL_40;
                }
                else if ( !a1 )
                {
                  goto LABEL_40;
                }
                v12 = *(_QWORD *)(a1 + 6544);
                if ( v12 )
                {
                  v13 = *(void (__fastcall **)(_QWORD))(v12 + 80);
                  if ( v13 )
                  {
                    if ( *((_DWORD *)v13 - 1) != -1850880742 )
                      __break(0x8228u);
                    v13(a1);
                  }
                }
LABEL_40:
                if ( (msm_vidc_debug & 2) != 0 )
                {
                  printk(&unk_838C0, "high", 0xFFFFFFFFLL, "codec", "venus_hfi_core_init");
                  return 0;
                }
                return 0;
              }
            }
          }
        }
      }
    }
  }
LABEL_5:
  if ( (msm_vidc_debug & 1) != 0 )
  {
    v14 = result;
    printk(&unk_8F66F, "err ", 0xFFFFFFFFLL, "codec", "venus_hfi_core_init");
    return v14;
  }
  return result;
}
