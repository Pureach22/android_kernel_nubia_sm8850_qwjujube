void __fastcall geni_i3c_enable_hotjoin_irq(_QWORD *a1, char a2)
{
  int v4; // w0
  bool v5; // zf
  const char *v6; // x20
  int v7; // w8
  __int64 v8; // x3
  __int64 v9; // x0

  v4 = readl_relaxed((unsigned int *)(a1[2666] + 20LL));
  v5 = (a2 & 1) == 0;
  if ( (a2 & 1) != 0 )
    v6 = "Enabled";
  else
    v6 = "Disabled";
  if ( v5 )
    v7 = 0;
  else
    v7 = 4;
  writel_relaxed(v4 & 0xFFFFFFFB | v7, (unsigned int *)(a1[2666] + 20LL));
  ipc_log_string(a1[316], "%s:%s\n", "geni_i3c_enable_hotjoin_irq", v6);
  v9 = a1[1];
  if ( v9 )
  {
    dev_err(v9, "%s:%s\n", "geni_i3c_enable_hotjoin_irq", v6);
    if ( !a1[1] )
      return;
    goto LABEL_11;
  }
  printk(&unk_12839, "geni_i3c_enable_hotjoin_irq", v6, v8);
  if ( a1[1] )
LABEL_11:
    i3c_trace_log();
}
