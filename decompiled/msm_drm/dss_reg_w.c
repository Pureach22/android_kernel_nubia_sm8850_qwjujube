__int64 __fastcall dss_reg_w(__int64 a1, unsigned int a2, unsigned int a3, int a4)
{
  __int64 v4; // x30
  __int64 v5; // x8
  void *v11; // x0

  if ( !a1 || (v5 = *(_QWORD *)(a1 + 8)) == 0 )
  {
    v11 = &unk_22ECB8;
    return printk(v11, v4);
  }
  if ( *(_DWORD *)a1 < a2 )
  {
    v11 = &unk_269701;
    return printk(v11, v4);
  }
  writel_relaxed_7(a3, v5 + a2);
  if ( a4 )
    readl_relaxed_7(*(_QWORD *)(a1 + 8) + a2);
  return sde_reglog_log(33, a3, a2);
}
