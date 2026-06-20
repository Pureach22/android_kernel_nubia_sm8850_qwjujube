__int64 sub_1D0868()
{
  unsigned int *v0; // x19

  atomic_load(v0);
  atomic_load(v0);
  return dsi_ctrl_flush_cmd_dma_queue();
}
