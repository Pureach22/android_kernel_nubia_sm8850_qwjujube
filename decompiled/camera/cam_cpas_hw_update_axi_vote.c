__int64 __fastcall cam_cpas_hw_update_axi_vote(__int64 a1, unsigned int a2, __int64 a3)
{
  __int64 v4; // x22
  __int64 v7; // x24
  unsigned int *v8; // x21
  __int64 v9; // x7
  __int64 v10; // x9
  unsigned __int64 v11; // x8
  unsigned int *v12; // x10
  __int64 v13; // x9
  unsigned int v14; // w6
  unsigned int v15; // w22
  unsigned __int64 StatusReg; // x23
  __int64 v18; // x25

  if ( !a3 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_hw_update_axi_vote",
      2493,
      "Invalid arg, client_handle=%d",
      a2);
    return 4294967274LL;
  }
  if ( a2 > 0x2A )
    return 4294967274LL;
  v4 = *(_QWORD *)(a1 + 3680);
  mutex_lock(a1);
  v7 = v4 + 48LL * a2;
  mutex_lock(v7 + 664);
  v8 = (unsigned int *)kmemdup_noprof(a3, 608, 3264);
  if ( v8 )
  {
    while ( 1 )
    {
      v4 += 320;
      cam_cpas_dump_axi_vote_info(*(_QWORD *)(v4 + 8LL * a2), "Incoming Vote", v8);
      v9 = *(_QWORD *)(v4 + 8LL * a2);
      if ( *(_BYTE *)(v9 + 168) != 1 || (*(_BYTE *)(v9 + 169) & 1) == 0 )
        break;
      v10 = *v8;
      if ( !(_DWORD)v10 )
      {
LABEL_16:
        cam_cpas_dump_axi_vote_info(v9, "Translated Vote", v8);
        v15 = cam_cpas_util_apply_client_axi_vote(a1, *(_QWORD *)(v4 + 8LL * a2), (unsigned __int64)v8, 3);
        cam_cpas_update_monitor_array(a1, "CPAS AXI post-update", a2);
        goto LABEL_20;
      }
      v11 = 0;
      v12 = v8 + 4;
      v13 = 40 * v10;
      while ( v11 != 600 )
      {
        if ( v11 - 592 < 0xFFFFFFFFFFFFFDA0LL )
        {
          __break(1u);
          break;
        }
        if ( v12[v11 / 4] <= 0xFF )
          v14 = v12[v11 / 4] & 0x1F;
        else
          v14 = v12[v11 / 4] & 0x1F | 0x20;
        v12[v11 / 4] = v14;
        if ( v14 >= 0x2A )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            4,
            1,
            "cam_cpas_util_translate_client_paths",
            1698,
            "index Invalid: %d",
            v14);
          v15 = -22;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            4,
            1,
            "cam_cpas_hw_update_axi_vote",
            2528,
            "Unable to translate per path votes rc: %d",
            -22);
          goto LABEL_20;
        }
        v11 += 40LL;
        if ( v13 == v11 )
        {
          v9 = *(_QWORD *)(v4 + 8LL * a2);
          goto LABEL_16;
        }
      }
      __break(0x5512u);
      StatusReg = _ReadStatusReg(SP_EL0);
      v18 = *(_QWORD *)(StatusReg + 80);
      *(_QWORD *)(StatusReg + 80) = &cam_cpas_hw_update_axi_vote__alloc_tag;
      v8 = (unsigned int *)kmemdup_noprof(v8, 608, 3264);
      *(_QWORD *)(StatusReg + 80) = v18;
      if ( !v8 )
        goto LABEL_24;
    }
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_hw_update_axi_vote",
      2520,
      "client=[%d][%s][%d] has not started",
      a2);
    v15 = -1;
LABEL_20:
    cam_free_clear();
    mutex_unlock(v7 + 664);
    mutex_unlock(a1);
    return v15;
  }
  else
  {
LABEL_24:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_hw_update_axi_vote",
      2506,
      "Out of memory");
    mutex_unlock(v7 + 664);
    mutex_unlock(a1);
    return 4294967284LL;
  }
}
