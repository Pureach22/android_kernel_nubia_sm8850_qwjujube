__int64 __fastcall sde_hdcp_1x_off(__int64 a1)
{
  __int64 v1; // x20
  unsigned int v3; // w21
  int v4; // w0
  unsigned int v5; // w21
  int v6; // w8
  __int64 v7; // x1
  int v8; // w9
  void *v10; // x0

  if ( !a1 || (v1 = *(_QWORD *)(a1 + 888)) == 0 )
  {
    v10 = &unk_255B25;
    return printk(v10, "sde_hdcp_1x_off");
  }
  if ( !*(_DWORD *)(a1 + 40) )
  {
    v10 = &unk_21817B;
    return printk(v10, "sde_hdcp_1x_off");
  }
  v3 = *(_DWORD *)(a1 + 1128);
  v4 = dss_reg_r(*(_QWORD *)(a1 + 888), v3, 1);
  dss_reg_w(
    v1,
    v3,
    v4
  & ~(*(_DWORD *)(a1 + 1136) | *(_DWORD *)(a1 + 1132) | (unsigned int)(*(_DWORD *)(a1 + 1140) | *(_DWORD *)(a1 + 1144))),
    1);
  *(_DWORD *)(a1 + 40) = 0;
  complete_all(a1 + 840);
  complete_all(a1 + 808);
  cancel_delayed_work_sync(a1 + 704);
  if ( !*(_DWORD *)(a1 + 1000) || *(_BYTE *)(a1 + 35) == 1 )
    hdcp1_set_enc(*(_QWORD *)(a1 + 1448), 0);
  v5 = dss_reg_r(v1, *(unsigned int *)(a1 + 1116), 1);
  dss_reg_w(v1, *(unsigned int *)(a1 + 1116), *(_DWORD *)(a1 + 1120) | v5, 1);
  dss_reg_w(v1, *(unsigned int *)(a1 + 1032), 0, 1);
  dss_reg_w(v1, *(unsigned int *)(a1 + 1116), v5 & ~*(_DWORD *)(a1 + 1120), 1);
  v6 = *(_DWORD *)(a1 + 40);
  v7 = *(_QWORD *)(a1 + 1440);
  *(_BYTE *)(a1 + 32) = 0;
  if ( v6 == 2 )
  {
    *(_DWORD *)v7 = *(unsigned __int8 *)(a1 + 54);
    *(_DWORD *)(v7 + 4) = *(unsigned __int8 *)(a1 + 53);
    *(_DWORD *)(v7 + 8) = *(_DWORD *)(a1 + 696);
    v8 = *(_DWORD *)(a1 + 692);
    *(_QWORD *)(v7 + 16) = 0;
    *(_DWORD *)(v7 + 12) = v8;
  }
  else
  {
    *(_QWORD *)(v7 + 8) = 0;
    *(_QWORD *)(v7 + 16) = 0;
    *(_QWORD *)v7 = 0;
  }
  hdcp1_ops_notify(*(_QWORD *)(a1 + 1448));
  return hdcp1_stop(*(_QWORD *)(a1 + 1448));
}
