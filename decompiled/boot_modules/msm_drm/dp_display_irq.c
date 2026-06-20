__int64 __fastcall dp_display_irq(__int64 a1, _QWORD *a2)
{
  __int64 v2; // x0
  void (*v4)(void); // x8
  void (*v5)(void); // x8
  void (*v6)(void); // x8
  unsigned int (__fastcall **v7)(_QWORD); // x8
  unsigned int (__fastcall *v8)(_QWORD); // x8
  __int64 v9; // x0
  __int64 v11; // x0
  unsigned int v12; // w20
  void *v13; // x0
  __int64 v14; // x0

  if ( !a2 )
  {
    if ( !g_dp_display || (v11 = *(_QWORD *)(g_dp_display + 56)) == 0 )
      v11 = 0;
    ipc_log_string(v11, "[e][%-4d]invalid data\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v12 = 0;
    v13 = &unk_245274;
    goto LABEL_22;
  }
  v2 = a2[16];
  if ( *(_DWORD *)v2 == 3 )
  {
    v4 = *(void (**)(void))(v2 + 16);
    if ( *((_DWORD *)v4 - 1) != -1799772427 )
      __break(0x8228u);
    v4();
  }
  v5 = *(void (**)(void))(a2[23] + 40LL);
  if ( *((_DWORD *)v5 - 1) != 1576769688 )
    __break(0x8228u);
  v5();
  v6 = *(void (**)(void))(a2[20] + 48LL);
  if ( *((_DWORD *)v6 - 1) != 268977780 )
    __break(0x8228u);
  v6();
  if ( *(_DWORD *)(a2[21] + 140LL) )
  {
    v7 = (unsigned int (__fastcall **)(_QWORD))a2[29];
    if ( v7 )
    {
      v8 = *v7;
      if ( v8 )
      {
        v9 = a2[28];
        if ( *((_DWORD *)v8 - 1) != -1066802076 )
          __break(0x8228u);
        if ( v8(v9) )
        {
          if ( !g_dp_display || (v14 = *(_QWORD *)(g_dp_display + 56)) == 0 )
            v14 = 0;
          ipc_log_string(v14, "[e][%-4d]dp_hdcp_isr failed\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
          v12 = 1;
          v13 = &unk_23AF15;
LABEL_22:
          printk(v13, "dp_display_irq");
          return v12;
        }
      }
    }
  }
  return 1;
}
