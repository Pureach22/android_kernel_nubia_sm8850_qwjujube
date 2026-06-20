__int64 __fastcall aw882xx_dsp_read_dsp_msg(__int64 a1, __int64 a2, __int64 a3, unsigned int a4)
{
  if ( *(_DWORD *)(a1 + 52) > 3u )
    return aw_read_msg_from_dsp_v_1_0_0_0(a3, a4);
  mutex_lock(&g_aw_dsp_msg_lock);
  if ( g_rx_topo_id )
    printk(&unk_23888, "aw_check_dsp_ready", 0);
  mutex_lock(&g_aw_dsp_lock);
  mutex_unlock(&g_aw_dsp_lock);
  if ( g_rx_topo_id )
    printk(&unk_23888, "aw_check_dsp_ready", 0);
  mutex_lock(&g_aw_dsp_lock);
  mutex_unlock(&g_aw_dsp_lock);
  mutex_unlock(&g_aw_dsp_msg_lock);
  return 0;
}
