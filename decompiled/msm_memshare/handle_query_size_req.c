__int64 __fastcall handle_query_size_req(__int64 a1, __int64 a2, __int64 a3, unsigned int *a4)
{
  unsigned __int16 *v7; // x0
  unsigned int v9; // w8
  __int64 v10; // x1
  unsigned __int16 *v11; // x22
  int v12; // w0
  int v13; // w2
  __int64 v14; // x10
  unsigned int v15; // w9
  __int64 *v16; // x11
  unsigned int v17; // w9
  unsigned int v18; // w12
  unsigned int v19; // w11

  mutex_lock(memsh_drv + 8);
  v7 = (unsigned __int16 *)_kmalloc_cache_noprof(_kmalloc_noprof, 3520, 12);
  if ( !v7 )
    return mutex_unlock(memsh_drv + 8);
  v9 = *a4;
  v10 = a4[2];
  v11 = v7;
  *(_DWORD *)v7 = 196609;
  v12 = check_client(v9, v10, 0);
  if ( v12 > 9 )
  {
    dev_err(*(_QWORD *)memsh_drv, "memshare_query: client not found, requested client: %d, proc_id: %d\n", *a4, a4[2]);
    goto LABEL_16;
  }
  if ( !num_clients )
    goto LABEL_15;
  v14 = memsh_child;
  v15 = *a4;
  if ( *(_DWORD *)memsh_child != *a4 )
  {
    if ( num_clients == 1 )
      goto LABEL_15;
    v14 = qword_8900;
    if ( *(_DWORD *)qword_8900 != v15 )
    {
      if ( num_clients == 2 )
        goto LABEL_15;
      v14 = qword_8908;
      if ( *(_DWORD *)qword_8908 != v15 )
      {
        if ( num_clients == 3 )
          goto LABEL_15;
        v14 = qword_8910;
        if ( *(_DWORD *)qword_8910 != v15 )
        {
          if ( num_clients == 4 )
            goto LABEL_15;
          v14 = qword_8918;
          if ( *(_DWORD *)qword_8918 != v15 )
          {
            if ( num_clients == 5 )
              goto LABEL_15;
            v14 = qword_8920;
            if ( *(_DWORD *)qword_8920 != v15 )
            {
              if ( num_clients == 6 )
                goto LABEL_15;
              v14 = qword_8928;
              if ( *(_DWORD *)qword_8928 != v15 )
              {
                if ( num_clients == 7 )
                  goto LABEL_15;
                v14 = qword_8930;
                if ( *(_DWORD *)qword_8930 != v15 )
                {
                  if ( num_clients == 8 )
                    goto LABEL_15;
                  v14 = qword_8938;
                  if ( *(_DWORD *)qword_8938 != v15 )
                  {
                    if ( num_clients == 9 )
                      goto LABEL_15;
                    v14 = qword_8940;
                    if ( *(_DWORD *)qword_8940 != v15 )
                    {
                      if ( num_clients != 10 )
                        goto LABEL_36;
LABEL_15:
                      dev_err(*(_QWORD *)memsh_drv, "memshare_query: No valid client node found\n");
                      goto LABEL_16;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  if ( !v14 )
    goto LABEL_15;
  if ( (unsigned int)v12 > 9 )
  {
LABEL_36:
    __break(0x5512u);
    goto LABEL_37;
  }
  v16 = &memblock[12 * (unsigned int)v12];
  *((_BYTE *)v11 + 4) = 1;
  v17 = *((_DWORD *)v16 + 15);
  if ( v17 )
  {
    v18 = *(_DWORD *)(v14 + 4);
    if ( v18 )
    {
      v19 = *((_DWORD *)v16 + 16);
      v17 = *(_DWORD *)(v14 + 4);
      if ( v18 > v19 )
      {
        v17 = v19;
        *(_DWORD *)(v14 + 4) = v19;
      }
    }
  }
  *((_DWORD *)v11 + 2) = v17;
  *(_DWORD *)v11 = 0;
LABEL_16:
  mutex_unlock(memsh_drv + 8);
  dev_info(
    *(_QWORD *)memsh_drv,
    "memshare_query: client_id : %d, query_resp.size :%d, query_resp.resp.result :%lx\n",
    *a4,
    *((_DWORD *)v11 + 2),
    *v11);
  v13 = qmi_send_response(mem_share_svc_handle, a2, a3, 36, 255, &mem_query_size_resp_msg_data_v01_ei, v11);
  if ( v13 < 0 )
LABEL_37:
    dev_err(*(_QWORD *)memsh_drv, "memshare_query: Error sending the query response: %d\n", v13);
  return kfree(v11);
}
