__int64 __fastcall msm_vidc_core_deinit_locked(__int64 a1, char a2)
{
  __int64 result; // x0
  unsigned int v5; // w19
  char v6; // w8
  void *v7; // x0
  const char *v8; // x1
  _QWORD *v9; // x22
  _QWORD *v10; // x20
  _QWORD *v11; // x24
  _QWORD *v12; // x8
  _QWORD *v13; // x9
  _QWORD *v14; // x1

  result = _strict_check(a1, "msm_vidc_core_deinit_locked");
  if ( !(_DWORD)result )
  {
    v6 = is_core_state(a1, 0);
    result = 0;
    if ( (v6 & 1) != 0 )
      return result;
    if ( (unsigned int)msm_vidc_allow_core_state_change(a1, 0) != 1 && (msm_vidc_debug & 1) != 0 )
    {
      core_state_name(*(unsigned int *)(a1 + 3704));
      core_state_name(0);
      printk(&unk_87573, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_core_deinit_locked");
      if ( (a2 & 1) != 0 )
      {
LABEL_8:
        if ( (msm_vidc_debug & 1) != 0 )
        {
          v7 = &unk_88565;
          v8 = "err ";
LABEL_32:
          printk(v7, v8, 0xFFFFFFFFLL, "codec", "msm_vidc_core_deinit_locked");
          goto LABEL_15;
        }
        goto LABEL_15;
      }
    }
    else if ( (a2 & 1) != 0 )
    {
      goto LABEL_8;
    }
    if ( *(_QWORD *)(a1 + 3528) != a1 + 3528 )
    {
      if ( (msm_vidc_debug & 2) != 0 )
        printk(&unk_9242F, "high", 0xFFFFFFFFLL, "codec", "msm_vidc_core_deinit_locked");
      return 0;
    }
    if ( (msm_vidc_debug & 2) != 0 )
    {
      v7 = &unk_8A7E1;
      v8 = "high";
      goto LABEL_32;
    }
LABEL_15:
    venus_hfi_core_deinit(a1, a2 & 1);
    v9 = *(_QWORD **)(a1 + 3528);
    if ( v9 != (_QWORD *)(a1 + 3528) )
    {
      v10 = (_QWORD *)(a1 + 3544);
      do
      {
        v11 = (_QWORD *)*v9;
        msm_vidc_change_state(v9, 5, "msm_vidc_core_deinit_locked");
        v12 = (_QWORD *)v9[1];
        if ( (_QWORD *)*v12 == v9 && (v13 = (_QWORD *)*v9, *(_QWORD **)(*v9 + 8LL) == v9) )
        {
          v13[1] = v12;
          *v12 = v13;
        }
        else
        {
          _list_del_entry_valid_or_report(v9);
        }
        v14 = *(_QWORD **)(a1 + 3552);
        if ( v9 == v10 || v14 == v9 || (_QWORD *)*v14 != v10 )
        {
          _list_add_valid_or_report(v9);
        }
        else
        {
          *(_QWORD *)(a1 + 3552) = v9;
          *v9 = v10;
          v9[1] = v14;
          *v14 = v9;
        }
        v9 = v11;
      }
      while ( v11 != (_QWORD *)(a1 + 3528) );
    }
    msm_vidc_change_core_state(a1, 0, "msm_vidc_core_deinit_locked");
    return 0;
  }
  if ( (msm_vidc_debug & 1) != 0 )
  {
    v5 = result;
    printk(&unk_955EF, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_core_deinit_locked");
    return v5;
  }
  return result;
}
