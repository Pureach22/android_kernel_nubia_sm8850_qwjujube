__int64 __fastcall hif_init_dma_mask(__int64 a1, int a2)
{
  unsigned int v3; // w19

  if ( a2 == 6 )
  {
    v3 = dma_set_mask(a1, 0x1FFFFFFFFFLL);
    if ( v3 )
      qdf_trace_msg(61, 2, "%s: Failed to set dma mask error = %d", "hif_init_dma_mask", v3);
    else
      dma_set_coherent_mask(a1, 0x1FFFFFFFFFLL);
  }
  else
  {
    return 0;
  }
  return v3;
}
