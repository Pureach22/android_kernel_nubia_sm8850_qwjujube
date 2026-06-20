__int64 __fastcall aw882xx_dsp_write_spin(int a1)
{
  if ( a1 >= 4 )
  {
    printk(&unk_2245A, "aw882xx_dsp_write_spin", (unsigned int)a1);
    return 4294967274LL;
  }
  else
  {
    if ( g_rx_topo_id )
      printk(&unk_23888, "aw_check_dsp_ready", 0);
    mutex_lock(&g_aw_dsp_lock);
    mutex_unlock(&g_aw_dsp_lock);
    return 0;
  }
}
