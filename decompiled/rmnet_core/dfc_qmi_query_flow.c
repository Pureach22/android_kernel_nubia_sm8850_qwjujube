__int64 __fastcall dfc_qmi_query_flow(__int64 *a1)
{
  __int64 result; // x0
  unsigned __int16 *v3; // x19
  _BYTE *v4; // x21
  __int64 v5; // x22
  __int64 v6; // x23
  __int64 v7; // x9
  void *v8; // x0
  int v9; // w24

  result = _kmalloc_cache_noprof(netdev_rx_handler_register, 2336, 648);
  v3 = (unsigned __int16 *)result;
  if ( result )
  {
    v4 = (_BYTE *)_kmalloc_cache_noprof(netdev_rx_handler_register, 2336, 800);
    if ( !v4 )
      return kfree(v3);
    if ( !a1 )
      goto LABEL_19;
    v5 = _kmalloc_cache_noprof(nla_put, 2336, 18);
    if ( !v5 )
      goto LABEL_19;
    v6 = _kmalloc_cache_noprof(_kmalloc_cache_noprof, 2336, 72);
    if ( v6 )
    {
      if ( (qmi_txn_init(a1 + 6, v6, &dfc_get_flow_status_resp_msg_v01_ei, v3) & 0x80000000) != 0 )
      {
        v8 = &unk_2D786;
      }
      else if ( (qmi_send_request(a1 + 6, a1 + 44, v6, 35, 20, &dfc_get_flow_status_req_msg_v01_ei, v5) & 0x80000000) != 0 )
      {
        qmi_txn_cancel(v6);
        v8 = &unk_2CDDC;
      }
      else
      {
        if ( (qmi_txn_wait(v6, 250) & 0x80000000) == 0 )
        {
          if ( !*v3 )
          {
            kfree(v6);
            kfree(v5);
            goto LABEL_11;
          }
          printk(&unk_2D31A, "dfc_get_flow_status_req");
          v9 = *v3;
          kfree(v6);
          kfree(v5);
          if ( !v9 )
          {
LABEL_11:
            if ( *((_BYTE *)v3 + 4) )
            {
              v7 = *((unsigned __int8 *)v3 + 5);
              if ( (unsigned int)(v7 - 17) >= 0xFFFFFFF0 )
              {
                v4[20] = *((_BYTE *)v3 + 4);
                v4[21] = v7;
                memcpy(v4 + 24, v3 + 4, 40 * v7);
                dfc_do_burst_flow_control(a1, v4 + 20, 1);
              }
            }
          }
LABEL_19:
          kfree(v4);
          return kfree(v3);
        }
        v8 = &unk_2D7B0;
      }
      printk(v8, "dfc_get_flow_status_req");
      kfree(v6);
    }
    kfree(v5);
    goto LABEL_19;
  }
  return result;
}
