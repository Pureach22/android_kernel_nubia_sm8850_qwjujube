__int64 __fastcall aw882xx_dsp_get_afe_module_en(unsigned int a1)
{
  void *v1; // x0

  if ( a1 == 1 )
  {
    if ( g_tx_topo_id )
    {
      v1 = &unk_28355;
      goto LABEL_10;
    }
  }
  else
  {
    if ( a1 )
    {
      printk(&unk_26276, "aw882xx_dsp_get_afe_module_en", a1);
      return 4294967274LL;
    }
    if ( g_rx_topo_id )
    {
      v1 = &unk_23888;
LABEL_10:
      printk(v1, "aw_check_dsp_ready", 0);
    }
  }
  mutex_lock(&g_aw_dsp_lock);
  mutex_unlock(&g_aw_dsp_lock);
  return 0;
}
