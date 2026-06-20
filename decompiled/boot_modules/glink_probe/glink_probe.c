__int64 __fastcall glink_probe(__int64 a1)
{
  __int64 v2; // x19
  __int64 next_available_child; // x0
  _QWORD *v4; // x20
  __int64 v5; // x23
  __int64 v6; // x3
  __int64 v7; // x0
  const char *v8; // x26
  __int64 v9; // x0
  __int64 v10; // x24
  const char *v11; // x26
  __int64 (__fastcall *v12)(); // x8
  __int64 (__fastcall *v13)(); // x9
  unsigned __int64 v14; // x0
  __int64 *v15; // x1
  char *s1[2]; // [xsp+0h] [xbp-10h] BYREF

  s1[1] = *(char **)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 760);
  next_available_child = of_get_next_available_child(v2, 0);
  if ( next_available_child )
  {
    v4 = (_QWORD *)next_available_child;
    v5 = a1 + 16;
    do
    {
      s1[0] = nullptr;
      v9 = devm_kmalloc(v5, 104, 3520);
      if ( !v9 )
        goto LABEL_5;
      v10 = v9;
      if ( (of_property_read_string(v4, "label", v9 + 32) & 0x80000000) != 0 )
        *(_QWORD *)(v10 + 32) = *v4;
      if ( (of_property_read_string(v4, "qcom,ssr-label", v10 + 40) & 0x80000000) != 0 )
      {
        v6 = *(_QWORD *)(v10 + 32);
        v7 = v5;
        v8 = "[%s]: no qcom,ssr-label for %s\n";
      }
      else
      {
        *(_QWORD *)(v10 + 16) = v5;
        *(_QWORD *)(v10 + 24) = v4;
        if ( (of_property_read_string(v4, "transport", s1) & 0x80000000) == 0 )
        {
          v11 = s1[0];
          if ( !strcmp(s1[0], "smem") )
          {
            v12 = glink_probe_smem_reg;
            v13 = glink_probe_smem_unreg;
LABEL_15:
            *(_QWORD *)(v10 + 56) = v12;
            *(_QWORD *)(v10 + 64) = v13;
          }
          else if ( !strcmp(v11, "spss") )
          {
            v12 = glink_probe_spss_reg;
            v13 = glink_probe_spss_unreg;
            goto LABEL_15;
          }
          *(_QWORD *)(v10 + 72) = glink_probe_ssr_cb;
          v14 = qcom_register_ssr_notifier(*(_QWORD *)(v10 + 40));
          if ( v14 && v14 < 0xFFFFFFFFFFFFF001LL )
          {
            *(_QWORD *)(v10 + 96) = v14;
            v15 = (__int64 *)off_128;
            if ( off_128 == (_UNKNOWN **)v10 || *off_128 != (_UNKNOWN *)&edge_infos )
            {
              _list_add_valid_or_report(v10);
            }
            else
            {
              off_128 = (_UNKNOWN **)v10;
              *(_QWORD *)v10 = &edge_infos;
              *(_QWORD *)(v10 + 8) = v15;
              *v15 = v10;
            }
            ipc_log_string(glink_ilc, "probe successful for %s\n", *(const char **)(v10 + 32));
            goto LABEL_5;
          }
          v6 = *(_QWORD *)(v10 + 32);
          v7 = v5;
          v8 = "[%s]: could not register for SSR notifier for %s\n";
          goto LABEL_4;
        }
        v6 = *(_QWORD *)(v10 + 32);
        v7 = v5;
        v8 = "[%s]: %s missing transport\n";
      }
LABEL_4:
      dev_err(v7, v8, "probe_subsystem", v6);
      ipc_log_string(glink_ilc, v8, "probe_subsystem", *(_QWORD *)(v10 + 32));
LABEL_5:
      v4 = (_QWORD *)of_get_next_available_child(v2, v4);
    }
    while ( v4 );
  }
  _ReadStatusReg(SP_EL0);
  return 0;
}
