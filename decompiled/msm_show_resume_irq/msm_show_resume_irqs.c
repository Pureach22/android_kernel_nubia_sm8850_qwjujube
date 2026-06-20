void msm_show_resume_irqs()
{
  char v0; // w0
  int v1; // w8
  __int64 v2; // x21
  int v3; // w22
  __int64 v4; // x23
  int v5; // w19
  __int64 v6; // x19
  unsigned int i; // w0
  unsigned int v8; // w22
  _QWORD v9[17]; // [xsp+8h] [xbp-88h] BYREF

  v9[16] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( msm_show_resume_irq_mask )
  {
    memset(v9, 0, 128);
    v0 = readl_relaxed(base + 4);
    v1 = 991;
    v2 = 0;
    if ( 32 * (v0 & 0x1Fu) >= 0x3DF )
      v3 = 991;
    else
      v3 = 32 * (v0 & 0x1F);
    if ( 32 * (unsigned __int64)(v0 & 0x1F) < 0x3DF )
      v1 = 32 * (v0 & 0x1F);
    v4 = (((unsigned int)(v1 + 31) >> 3) & 0xFCLL) + 4;
    do
    {
      v5 = readl_relaxed(base + v2 + 384);
      *(_DWORD *)((char *)v9 + v2) = readl_relaxed(base + v2 + 512) & v5;
      v2 += 4;
    }
    while ( v4 != v2 );
    v6 = (unsigned int)(v3 + 32);
    for ( i = find_first_bit(v9, v6); (unsigned int)v6 > i; i = find_next_bit(v9, v6, i + 1) )
    {
      if ( i >= 0x20 )
      {
        v8 = i;
        printk(&unk_7082, "msm_show_resume_irqs", i);
        i = v8;
      }
    }
  }
  _ReadStatusReg(SP_EL0);
}
