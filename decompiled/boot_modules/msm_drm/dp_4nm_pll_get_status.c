bool __fastcall dp_4nm_pll_get_status(__int64 a1, signed int a2)
{
  __int64 v2; // x21
  int v4; // w20
  __int64 v5; // x22
  int v6; // w0
  __int64 v7; // x23
  int v8; // w21
  int v10; // w20
  __int64 ipc_log_context; // x0
  int v12; // w2
  const char *v13; // x19

  v2 = (__int64)*(&off_284A80 + a2);
  v4 = dword_284A68[a2];
  v5 = *(_QWORD *)(*(_QWORD *)((char *)*(&off_284A40 + a2) + a1) + 24LL);
  v6 = readl_2(v5 + v2);
  if ( (v6 & v4) == 0 )
  {
    v7 = 10500001;
    while ( 1 )
    {
      v7 -= 500001;
      if ( v7 < 0 )
        break;
      _const_udelay(2147500);
      __yield();
      v6 = readl_2(v5 + v2);
      if ( (v6 & v4) != 0 )
        goto LABEL_7;
    }
    v6 = readl_2(v5 + v2);
  }
LABEL_7:
  v8 = v6 & v4;
  if ( (v6 & v4) == 0 )
  {
    v10 = v6;
    ipc_log_context = get_ipc_log_context();
    v12 = *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800);
    if ( (unsigned int)a2 > 4 )
      v13 = "unknown";
    else
      v13 = off_284AA8[a2];
    ipc_log_string(ipc_log_context, "[e][%-4d]%s failed, status=%x\n", v12, v13, v10);
    printk(&unk_27CC3B, "dp_4nm_pll_get_status");
  }
  return v8 != 0;
}
