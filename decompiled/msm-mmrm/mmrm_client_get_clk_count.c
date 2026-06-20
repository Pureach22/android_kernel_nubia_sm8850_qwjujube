__int64 mmrm_client_get_clk_count()
{
  if ( drv_data == -517 )
    return 0;
  else
    return *(unsigned int *)(*(_QWORD *)(drv_data + 96) + 72LL);
}
