__int64 __fastcall geni_se_get_tx_fifo_depth(_QWORD *a1)
{
  unsigned int qup_hw_version; // w0
  bool v4; // zf
  unsigned int *v5; // x0
  int v6; // w19

  qup_hw_version = geni_se_get_qup_hw_version();
  v4 = ((qup_hw_version & 0xFFE0000) <= 0x90000 || qup_hw_version >> 28 != 3) && (qup_hw_version & 0xC0000000) == 0;
  v5 = (unsigned int *)(*a1 + 3620LL);
  if ( v4 )
    v6 = 4128768;
  else
    v6 = 16711680;
  return (v6 & (unsigned int)readl_relaxed(v5)) >> 16;
}
