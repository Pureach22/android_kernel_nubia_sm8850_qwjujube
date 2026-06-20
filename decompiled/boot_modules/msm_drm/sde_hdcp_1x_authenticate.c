__int64 __fastcall sde_hdcp_1x_authenticate(__int64 a1)
{
  unsigned int v2; // w0
  __int64 v3; // x20
  __int64 v4; // x22
  __int64 v5; // x21
  int v6; // w8
  __int64 v7; // x1
  void *v9; // x0
  unsigned int v10; // w19
  _QWORD *v11; // x1
  void (__fastcall *v12)(_QWORD); // x8
  __int64 v13; // x0

  if ( !a1 )
  {
    v9 = &unk_255B25;
LABEL_16:
    printk(v9, "sde_hdcp_1x_authenticate");
    return 4294967274LL;
  }
  flush_delayed_work(a1 + 704);
  if ( *(_DWORD *)(a1 + 40) )
  {
    v9 = &unk_21817B;
    goto LABEL_16;
  }
  v2 = hdcp1_start(*(_QWORD *)(a1 + 1448), a1 + 24, a1 + 28);
  if ( !v2 )
  {
    v3 = *(_QWORD *)(a1 + 888);
    if ( !v3 || (v4 = *(_QWORD *)(a1 + 896)) == 0 || (v5 = *(_QWORD *)(a1 + 904)) == 0 )
    {
      printk(&unk_255B25, "sde_hdcp_1x_enable_hdcp_engine");
LABEL_19:
      v11 = *(_QWORD **)(a1 + 1440);
      *(_DWORD *)(a1 + 40) = 3;
      v11[1] = 0;
      v11[2] = 0;
      *v11 = 0;
      hdcp1_ops_notify(*(_QWORD *)(a1 + 1448));
      v12 = *(void (__fastcall **)(_QWORD))(a1 + 968);
      if ( v12 && *(_DWORD *)(a1 + 40) )
      {
        v13 = *(_QWORD *)(a1 + 960);
        if ( *((_DWORD *)v12 - 1) != -815732472 )
          __break(0x8228u);
        v12(v13);
      }
      return 0;
    }
    v6 = *(_DWORD *)(a1 + 40);
    if ( v6 > 1 )
    {
      if ( v6 != 3 )
      {
LABEL_18:
        printk(&unk_2520AB, "sde_hdcp_1x_enable_hdcp_engine");
        goto LABEL_19;
      }
    }
    else if ( v6 )
    {
      goto LABEL_18;
    }
    dss_reg_w(*(_QWORD *)(a1 + 896), *(unsigned int *)(a1 + 1036), *(unsigned int *)(a1 + 28), 1);
    dss_reg_w(v4, *(unsigned int *)(a1 + 1040), *(unsigned int *)(a1 + 24), 1);
    dss_reg_w(v5, *(unsigned int *)(a1 + 1044), 2986324223LL, 1);
    dss_reg_w(v5, *(unsigned int *)(a1 + 1048), 4027448014LL, 1);
    __dsb(0xEu);
    dss_reg_w(v3, *(unsigned int *)(a1 + 1032), 1, 1);
    v7 = *(_QWORD *)(a1 + 1432);
    *(_DWORD *)(a1 + 40) = 1;
    queue_delayed_work_on(32, v7, a1 + 704, 125);
    return 0;
  }
  v10 = v2;
  printk(&unk_23A6A2, "sde_hdcp_1x_authenticate");
  return v10;
}
