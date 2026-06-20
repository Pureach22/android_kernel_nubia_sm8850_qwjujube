__int64 __fastcall sde_hdcp_1x_reauthenticate(__int64 a1)
{
  __int64 v1; // x19
  unsigned int v2; // w21
  int v4; // w0
  unsigned int v5; // w21
  void *v7; // x0

  if ( !a1 || (v1 = *(_QWORD *)(a1 + 888)) == 0 )
  {
    v7 = &unk_255B25;
LABEL_8:
    printk(v7, "sde_hdcp_1x_reauthenticate");
    return 4294967274LL;
  }
  if ( *(_DWORD *)(a1 + 40) != 3 )
  {
    v7 = &unk_21817B;
    goto LABEL_8;
  }
  v2 = *(_DWORD *)(a1 + 1128);
  v4 = dss_reg_r(*(_QWORD *)(a1 + 888), v2, 1);
  dss_reg_w(
    v1,
    v2,
    v4
  & ~(*(_DWORD *)(a1 + 1136) | *(_DWORD *)(a1 + 1132) | (unsigned int)(*(_DWORD *)(a1 + 1140) | *(_DWORD *)(a1 + 1144))),
    1);
  v5 = dss_reg_r(v1, *(unsigned int *)(a1 + 1116), 1);
  dss_reg_w(v1, *(unsigned int *)(a1 + 1116), *(_DWORD *)(a1 + 1120) | v5, 1);
  dss_reg_w(v1, *(unsigned int *)(a1 + 1032), 0, 1);
  dss_reg_w(v1, *(unsigned int *)(a1 + 1116), v5 & ~*(_DWORD *)(a1 + 1120), 1);
  *(_DWORD *)(a1 + 40) = 0;
  return sde_hdcp_1x_authenticate(a1);
}
