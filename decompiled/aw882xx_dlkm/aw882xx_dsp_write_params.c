__int64 __fastcall aw882xx_dsp_write_params(__int64 a1)
{
  __int64 v1; // x2
  __int64 *v4; // x8
  __int64 v5; // x1

  v1 = *(unsigned int *)(a1 + 52);
  if ( (unsigned int)v1 >= 8 )
  {
    printk(&unk_26A80, "aw_dsp_get_msg_num", v1);
    v4 = *(__int64 **)(a1 + 112);
    v5 = v4[14];
    if ( !v5 )
      v5 = *v4;
    printk(&unk_24C4E, v5, "aw882xx_dsp_write_params");
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
