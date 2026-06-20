__int64 __fastcall sde_hdcp_1x_isr(__int64 a1)
{
  __int64 v1; // x19
  unsigned int v3; // w21
  int v4; // w8
  _QWORD *v5; // x1
  void (__fastcall *v6)(_QWORD); // x8
  __int64 v7; // x0
  __int64 v8; // x1
  int v9; // w8

  if ( !a1 || (v1 = *(_QWORD *)(a1 + 888)) == 0 )
  {
    printk(&unk_255B25, "sde_hdcp_1x_isr");
    return 4294967274LL;
  }
  v3 = dss_reg_r(*(_QWORD *)(a1 + 888), *(unsigned int *)(a1 + 1128), 1);
  if ( *(_DWORD *)(a1 + 40) )
  {
    if ( (*(_DWORD *)(a1 + 1184) & v3) != 0 )
    {
      dss_reg_w(v1, *(unsigned int *)(a1 + 1128), *(_DWORD *)(a1 + 1156) | v3, 1);
      if ( *(_DWORD *)(a1 + 40) == 1 )
        complete_all(a1 + 808);
    }
    if ( (*(_DWORD *)(a1 + 1188) & v3) != 0 )
    {
      dss_reg_r(v1, *(unsigned int *)(a1 + 1016), 1);
      dss_reg_w(v1, *(unsigned int *)(a1 + 1128), *(_DWORD *)(a1 + 1160) | v3, 1);
      v4 = *(_DWORD *)(a1 + 40);
      if ( v4 == 1 )
      {
        complete_all(a1 + 808);
      }
      else if ( v4 == 2 )
      {
        v5 = *(_QWORD **)(a1 + 1440);
        *(_DWORD *)(a1 + 40) = 3;
        v5[1] = 0;
        v5[2] = 0;
        *v5 = 0;
        hdcp1_ops_notify(*(_QWORD *)(a1 + 1448));
        v6 = *(void (__fastcall **)(_QWORD))(a1 + 968);
        if ( v6 )
        {
          if ( *(_DWORD *)(a1 + 40) )
          {
            v7 = *(_QWORD *)(a1 + 960);
            if ( *((_DWORD *)v6 - 1) != -815732472 )
              __break(0x8228u);
            v6(v7);
          }
        }
      }
      dss_reg_w(v1, *(unsigned int *)(a1 + 1128), *(_DWORD *)(a1 + 1164) | v3, 1);
    }
    if ( (*(_DWORD *)(a1 + 1200) & v3) != 0 )
      dss_reg_w(v1, *(unsigned int *)(a1 + 1128), *(_DWORD *)(a1 + 1176) | v3, 1);
    if ( (*(_DWORD *)(a1 + 1204) & v3) != 0 )
      dss_reg_w(v1, *(unsigned int *)(a1 + 1128), *(_DWORD *)(a1 + 1180) | v3, 1);
    if ( (*(_DWORD *)(a1 + 1192) & v3) != 0 )
      dss_reg_w(v1, *(unsigned int *)(a1 + 1128), *(_DWORD *)(a1 + 1168) | v3, 1);
    if ( (*(_DWORD *)(a1 + 1196) & v3) == 0 )
      return 0;
    v8 = *(unsigned int *)(a1 + 1128);
    v9 = *(_DWORD *)(a1 + 1172);
  }
  else
  {
    v8 = *(unsigned int *)(a1 + 1128);
    v9 = *(_DWORD *)(a1 + 1156)
       | *(_DWORD *)(a1 + 1160)
       | *(_DWORD *)(a1 + 1164)
       | *(_DWORD *)(a1 + 1176)
       | *(_DWORD *)(a1 + 1168)
       | *(_DWORD *)(a1 + 1172)
       | *(_DWORD *)(a1 + 1180);
  }
  dss_reg_w(v1, v8, v9 | v3, 1);
  return 0;
}
