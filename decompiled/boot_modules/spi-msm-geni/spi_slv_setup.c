__int64 __fastcall spi_slv_setup(__int64 a1)
{
  unsigned int *v2; // x1
  unsigned int v3; // w0

  writel_relaxed(1u, (unsigned int *)(*(_QWORD *)(a1 + 184) + 700LL));
  v2 = (unsigned int *)(*(_QWORD *)(a1 + 184) + 36LL);
  if ( *(_BYTE *)(a1 + 516) == 1 )
  {
    writel_relaxed(4u, v2);
    v3 = 35844;
    v2 = (unsigned int *)(*(_QWORD *)(a1 + 184) + 576LL);
  }
  else
  {
    v3 = 1;
  }
  writel_relaxed(v3, v2);
  writel_relaxed(1u, (unsigned int *)(*(_QWORD *)(a1 + 184) + 132LL));
  __dsb(0xEu);
  return dev_info(*(_QWORD *)(a1 + 200), "spi slave setup done\n");
}
