__int64 __fastcall handle_free_generic_req(__int64 a1, __int64 a2, __int64 a3, __int64 *a4)
{
  __int64 v4; // x25
  int v8; // w2
  int v9; // w3
  __int64 v10; // x0
  int v11; // w21
  int v12; // w2
  __int64 v13; // x24
  int v14; // w9
  __int64 v15; // x8
  __int64 v16; // x0
  __int64 v17; // x1
  int v18; // w8
  __int16 v19; // w8
  __int64 result; // x0
  int v21; // [xsp+Ch] [xbp-24h] BYREF
  _QWORD v22[4]; // [xsp+10h] [xbp-20h] BYREF

  v22[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v22[2] = 7;
  v22[0] = 0;
  v22[1] = 3;
  mutex_lock(memsh_drv + 56);
  v8 = *((_DWORD *)a4 + 259);
  v9 = *((_DWORD *)a4 + 261);
  v10 = *(_QWORD *)memsh_drv;
  v21 = 196609;
  dev_info(v10, "memshare_free: handling memory free request with client id: %d, proc_id: %d\n", v8, v9);
  v11 = check_client(*((unsigned int *)a4 + 259), *((unsigned int *)a4 + 261), 1);
  if ( v11 >= 10 )
    dev_err(*(_QWORD *)memsh_drv, "memshare_free: invalid client request to free memory\n");
  if ( !num_clients )
    goto LABEL_4;
  v12 = *((_DWORD *)a4 + 259);
  v13 = memsh_child;
  if ( *(_DWORD *)memsh_child == v12 )
    goto LABEL_6;
  if ( num_clients == 1 )
    goto LABEL_4;
  v13 = qword_8900;
  if ( *(_DWORD *)qword_8900 == v12 )
    goto LABEL_6;
  if ( num_clients == 2 )
    goto LABEL_4;
  v13 = qword_8908;
  if ( *(_DWORD *)qword_8908 == v12 )
    goto LABEL_6;
  if ( num_clients == 3 )
    goto LABEL_4;
  v13 = qword_8910;
  if ( *(_DWORD *)qword_8910 == v12 )
    goto LABEL_6;
  if ( num_clients == 4 )
    goto LABEL_4;
  v13 = qword_8918;
  if ( *(_DWORD *)qword_8918 == v12 )
    goto LABEL_6;
  if ( num_clients == 5 )
    goto LABEL_4;
  v13 = qword_8920;
  if ( *(_DWORD *)qword_8920 == v12 )
    goto LABEL_6;
  if ( num_clients == 6 )
    goto LABEL_4;
  v13 = qword_8928;
  if ( *(_DWORD *)qword_8928 == v12 )
    goto LABEL_6;
  if ( num_clients == 7 )
    goto LABEL_4;
  v13 = qword_8930;
  if ( *(_DWORD *)qword_8930 == v12 )
    goto LABEL_6;
  if ( num_clients == 8 )
    goto LABEL_4;
  v13 = qword_8938;
  if ( *(_DWORD *)qword_8938 == v12 )
    goto LABEL_6;
  if ( num_clients == 9 )
    goto LABEL_4;
  v13 = qword_8940;
  if ( *(_DWORD *)qword_8940 == v12 )
  {
LABEL_6:
    dev_info(*(_QWORD *)memsh_drv, "memshare_free: found client with client_id: %d, index: %d\n", v12, v11);
    if ( v13 )
    {
      if ( *(_QWORD *)(v13 + 16) )
      {
        qcom_glink_mem_entry_free();
        *(_QWORD *)(v13 + 16) = 0;
      }
      if ( v11 <= 9 )
      {
        if ( (unsigned int)v11 > 9 )
          goto LABEL_40;
        v4 = 96LL * (unsigned int)v11;
        if ( (v4 | 0x10uLL) > 0x3C0 )
          goto LABEL_58;
        a4 = &memblock[12 * (unsigned int)v11];
        if ( !*((_DWORD *)a4 + 4) )
        {
          if ( (v4 | 0x1CuLL) > 0x3C0 )
            goto LABEL_58;
          if ( !*((_DWORD *)a4 + 7) )
          {
            if ( (v4 | 0x14uLL) > 0x3C0 )
              goto LABEL_58;
            if ( *((_DWORD *)a4 + 5) )
            {
              v14 = *((_DWORD *)a4 + 9);
              if ( !v14 )
              {
LABEL_41:
                v15 = 0;
                goto LABEL_42;
              }
              v15 = 1LL << *((_DWORD *)a4 + 10);
              if ( v14 == 1 )
              {
LABEL_42:
                v16 = a4[9];
                v17 = *((unsigned int *)a4 + 14);
                v22[0] = v15;
                if ( (unsigned int)qcom_scm_assign_mem(v16, v17, v22) && *((_BYTE *)a4 + 89) == 1 )
                  dev_err(*(_QWORD *)memsh_drv, "memshare_free: failed to unmap the region for client id:%d\n", v11);
                v18 = *((_DWORD *)a4 + 14);
                if ( *((_DWORD *)a4 + 8) )
                  v18 += 4096;
                dma_free_attrs(*(_QWORD *)(v13 + 8), v18, a4[10], a4[9], 0);
                a4[2] = 0;
                a4[9] = 0;
                a4[10] = 0;
                if ( (v4 | 8uLL) <= 0x3C0 )
                {
                  *((_DWORD *)a4 + 2) = -1;
                  if ( (v4 | 0xCuLL) <= 0x3C0 )
                  {
                    *((_DWORD *)a4 + 3) = 1;
LABEL_51:
                    if ( v11 <= 9 )
                      v19 = 0;
                    else
                      v19 = 41;
                    LOWORD(v21) = v11 > 9;
                    HIWORD(v21) = v19;
                    goto LABEL_55;
                  }
                }
LABEL_58:
                __break(1u);
              }
              if ( v14 == 2 )
              {
                v15 |= 1LL << *((_DWORD *)a4 + 11);
                goto LABEL_42;
              }
LABEL_40:
              __break(0x5512u);
              goto LABEL_41;
            }
          }
        }
      }
      dev_err(
        *(_QWORD *)memsh_drv,
        "memshare_free: cannot free the memory for a guaranteed client (client index: %d)\n",
        v11);
      goto LABEL_51;
    }
  }
  else if ( num_clients != 10 )
  {
    goto LABEL_40;
  }
LABEL_4:
  dev_err(*(_QWORD *)memsh_drv, "memshare_free: No valid client node found\n");
LABEL_55:
  mutex_unlock(memsh_drv + 56);
  result = qmi_send_response(mem_share_svc_handle, a2, a3, 35, 255, &mem_free_generic_resp_msg_data_v01_ei, &v21);
  if ( (result & 0x80000000) != 0 )
    result = dev_err(*(_QWORD *)memsh_drv, "memshare_free: error sending the free response: %d\n", result);
  _ReadStatusReg(SP_EL0);
  return result;
}
