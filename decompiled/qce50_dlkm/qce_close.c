__int64 __fastcall qce_close(_QWORD *a1)
{
  _QWORD *v2; // x21
  __int64 v3; // x20
  __int64 v4; // x20
  __int64 v5; // x22
  __int64 v6; // x23
  _QWORD *v7; // x24
  __int64 v8; // x20
  __int64 v9; // x20
  __int64 v10; // x0
  __int64 v11; // x2

  if ( !a1 )
    return 4294967277LL;
  v2 = a1 + 8704;
  mutex_lock(&qce_iomap_mutex);
  if ( *((_BYTE *)v2 + 629) == 1 )
    free_irq(*((unsigned int *)a1 + 16), a1);
  qce_enable_clk((__int64)a1);
  if ( *((_BYTE *)v2 + 618) == 1 && *((_DWORD *)a1 + 79) )
  {
    v3 = a1[190];
    sps_disconnect(v3);
    dma_free_attrs(*a1, *((unsigned int *)a1 + 402), a1[198], a1[199], 0);
    sps_free_endpoint(v3);
    v4 = a1[52];
    sps_disconnect(v4);
    dma_free_attrs(*a1, *((unsigned int *)a1 + 126), a1[60], a1[61], 0);
    sps_free_endpoint(v4);
  }
  v5 = 0;
  v6 = 320;
  do
  {
    if ( *((_BYTE *)v2 + 619) != 1 )
      break;
    if ( *(_DWORD *)((char *)a1 + v6) )
    {
      v7 = &a1[v5];
      v8 = a1[v5 + 213];
      sps_disconnect(v8);
      dma_free_attrs(*a1, *((unsigned int *)v7 + 448), v7[221], v7[222], 0);
      sps_free_endpoint(v8);
      v9 = a1[v5 + 75];
      sps_disconnect(v9);
      dma_free_attrs(*a1, *((unsigned int *)v7 + 172), v7[83], v7[84], 0);
      sps_free_endpoint(v9);
    }
    v5 += 23;
    v6 += 4;
  }
  while ( v5 != 115 );
  qce_sps_release_bam(a1);
  v10 = a1[10];
  if ( v10 )
    iounmap(v10);
  v11 = a1[2];
  if ( v11 )
    dma_free_attrs(*a1, *((int *)a1 + 8), v11, a1[3], 0);
  kfree(v2[75]);
  kfree(a1[5]);
  qce_disable_clk((__int64)a1);
  if ( (*((_BYTE *)v2 + 617) & 1) == 0 )
  {
    if ( a1[15] )
      clk_put();
    if ( a1[14] )
      clk_put();
    if ( a1[13] )
      clk_put();
    if ( a1[12] )
      clk_put();
  }
  mutex_unlock(&qce_iomap_mutex);
  kfree(a1);
  return 0;
}
