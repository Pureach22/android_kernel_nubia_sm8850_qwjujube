__int64 __fastcall aw882xx_dsp_read_spin(_DWORD *a1)
{
  if ( g_rx_topo_id )
    printk(&unk_23888, "aw_check_dsp_ready", 0);
  mutex_lock(&g_aw_dsp_lock);
  mutex_unlock(&g_aw_dsp_lock);
  *a1 = 0;
  return 0;
}
