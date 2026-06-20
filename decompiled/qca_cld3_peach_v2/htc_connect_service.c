__int64 __fastcall htc_connect_service(__int64 *a1, unsigned __int16 *a2, __int64 a3)
{
  int v6; // w1
  int v7; // w9
  int v8; // w27
  unsigned int v9; // w23
  unsigned int v10; // w8
  __int64 *v11; // x22
  __int64 *v12; // x22
  unsigned __int16 v13; // w1
  int v14; // w10
  unsigned int v15; // w10
  __int64 v16; // x8
  __int64 v17; // x10
  __int64 v18; // x11
  __int64 v19; // x0
  __int64 v20; // x8
  __int64 v21; // x10
  __int64 v22; // x11
  __int64 v23; // x8
  __int64 v24; // x9
  __int64 v25; // x10
  __int64 v26; // x11
  __int64 v27; // x0
  __int64 result; // x0
  int v29; // w3
  __int16 credit_allocation; // w22
  __int64 v31; // x0
  __int64 v32; // x25
  __int64 v33; // x23
  unsigned int v34; // w24
  int v35; // w8
  int v36; // w8
  int v37; // w9
  __int64 v38; // x25
  __int16 v39; // w9
  int v40; // w10
  __int64 v41; // x1
  size_t v42; // x2
  unsigned int v43; // w25
  int v44; // w23
  unsigned int v45; // w28
  __int64 v46; // x2
  unsigned int v47; // w24
  unsigned int v48; // w19

  if ( (dword_B804 & 8) == 0 )
  {
    v6 = *a2;
    if ( *a2 )
      goto LABEL_3;
LABEL_16:
    printk(
      &unk_94DB9D,
      "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/htc/htc_services.c",
      118,
      "pConnectReq->service_id != 0");
    v6 = *a2;
    if ( v6 == 1 )
      goto LABEL_4;
    goto LABEL_17;
  }
  qdf_trace_msg(56, 2, "%s: +htc_connect_service, target:%pK SvcID:0x%X\n", "htc_connect_service", a1, *a2);
  v6 = *a2;
  if ( !*a2 )
    goto LABEL_16;
LABEL_3:
  if ( v6 == 1 )
  {
LABEL_4:
    v7 = 0;
    v8 = 0;
    v9 = 0;
    v10 = 256;
LABEL_5:
    v11 = &a1[41 * v9];
    *((_DWORD *)v11 + 2) = v9;
    v12 = v11 + 1;
    if ( !*((_WORD *)v12 + 2) )
    {
      *(_DWORD *)(a3 + 12) = v9;
      *(_DWORD *)(a3 + 16) = v10;
      v13 = *a2;
      *((_WORD *)v12 + 2) = *a2;
      v14 = *((_DWORD *)a2 + 30);
      *((_DWORD *)v12 + 72) = v7;
      *((_DWORD *)v12 + 32) = v14;
      *((_DWORD *)v12 + 33) = v10;
      v15 = *((_DWORD *)a1 + 862);
      *((_DWORD *)v12 + 73) = v15;
      *((_DWORD *)v12 + 74) = v10 / v15;
      if ( v10 % *((_DWORD *)a1 + 862) )
        *((_DWORD *)v12 + 74) = v10 / v15 + 1;
      v16 = *((_QWORD *)a2 + 6);
      v17 = *((_QWORD *)a2 + 3);
      v18 = *((_QWORD *)a2 + 4);
      v19 = *a1;
      v12[3] = *((_QWORD *)a2 + 5);
      v12[4] = v16;
      v12[1] = v17;
      v12[2] = v18;
      v20 = *((_QWORD *)a2 + 10);
      v21 = *((_QWORD *)a2 + 7);
      v22 = *((_QWORD *)a2 + 8);
      v12[7] = *((_QWORD *)a2 + 9);
      v12[8] = v20;
      v12[5] = v21;
      v12[6] = v22;
      v24 = *((_QWORD *)a2 + 13);
      v23 = *((_QWORD *)a2 + 14);
      v25 = *((_QWORD *)a2 + 11);
      v26 = *((_QWORD *)a2 + 12);
      *((_BYTE *)v12 + 301) = 0;
      v12[11] = v24;
      v12[12] = v23;
      v12[9] = v25;
      v12[10] = v26;
      v27 = hif_map_service_to_pipe(
              v19,
              v13,
              (_BYTE *)v12 + 136,
              (_BYTE *)v12 + 137,
              (int *)v12 + 35,
              (_DWORD *)v12 + 54);
      result = qdf_status_from_os_return(v27);
      if ( !(_DWORD)result )
      {
        if ( *((_DWORD *)v12 + 35) )
        {
          v12[23] = (__int64)htc_send_complete_check_cleanup;
          v12[24] = (__int64)v12;
          init_timer_key(v12 + 18, _os_timer_shim_0, 0x80000, 0, 0);
        }
        qdf_trace_msg(
          62,
          8,
          "SVC:0x%4.4X, ULpipe:%d DLpipe:%d id:%d Ready",
          *((unsigned __int16 *)v12 + 2),
          *((unsigned __int8 *)v12 + 136),
          *((unsigned __int8 *)v12 + 137),
          *(_DWORD *)v12);
        if ( v8 && *((_BYTE *)v12 + 300) == 1 )
        {
          v29 = *((unsigned __int16 *)v12 + 2);
          *((_BYTE *)v12 + 300) = 0;
          qdf_trace_msg(62, 8, "SVC:0x%4.4X ep:%d TX flow control disabled", v29, v9);
        }
        result = 0;
      }
      goto LABEL_61;
    }
    v46 = 331;
LABEL_45:
    printk(&unk_94DB9D, "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/htc/htc_services.c", v46, "false");
    result = 27;
    goto LABEL_61;
  }
LABEL_17:
  credit_allocation = htc_get_credit_allocation((__int64)a1, v6);
  if ( !(_BYTE)credit_allocation && (dword_B804 & 8) != 0 )
    qdf_trace_msg(56, 2, "%s: Service %d does not allocate target credits!\n", "htc_connect_service", *a2);
  v31 = htc_alloc_control_tx_packet((__int64)a1);
  if ( !v31 )
  {
    printk(&unk_94DB9D, "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/htc/htc_services.c", 141, "false");
    result = 2;
    goto LABEL_61;
  }
  v32 = *(_QWORD *)(v31 + 96);
  v33 = v31;
  v34 = *((unsigned __int8 *)a2 + 16) + 8;
  if ( *(_DWORD *)(v32 + 116) )
  {
    v35 = 0;
  }
  else
  {
    v37 = *(_DWORD *)(v32 + 208);
    v36 = *(_DWORD *)(v32 + 212);
    if ( v36 - v37 >= v34 )
      goto LABEL_26;
    v35 = v37 - v36;
  }
  if ( !(unsigned int)pskb_expand_head(*(_QWORD *)(v31 + 96), 0, v35 + v34, 2080) )
  {
LABEL_26:
    skb_put(v32, v34);
    v38 = *(_QWORD *)(v32 + 224);
    if ( v38 )
      goto LABEL_27;
LABEL_60:
    printk(&unk_94DB9D, "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/htc/htc_services.c", 159, "0");
    result = 5;
    goto LABEL_61;
  }
  dev_kfree_skb_any_reason(v32, 1);
  v38 = *(_QWORD *)(v32 + 224);
  if ( !v38 )
    goto LABEL_60;
LABEL_27:
  qdf_mem_set(v38, 8u, 0);
  v39 = *((unsigned __int8 *)a2 + 2);
  *(_WORD *)v38 = 2;
  v40 = *a2;
  *(_WORD *)(v38 + 4) = v39 | (credit_allocation << 8);
  *(_DWORD *)v38 = (v40 << 16) | 2;
  v41 = *((_QWORD *)a2 + 1);
  if ( htc_credit_flow )
    v8 = (a2[1] >> 3) & 1;
  else
    v8 = 1;
  if ( v41 )
  {
    v42 = *((unsigned __int8 *)a2 + 16);
    if ( (unsigned int)v42 <= 0x80 )
    {
      qdf_mem_copy(v38 + 8, v41, v42);
      *(_BYTE *)(v38 + 6) = *((_BYTE *)a2 + 16);
    }
  }
  *(_QWORD *)(v33 + 16) = 0;
  *(_QWORD *)(v33 + 32) = v38;
  *(_DWORD *)(v33 + 44) = v34;
  *(_DWORD *)(v33 + 48) = 0;
  *(_WORD *)(v33 + 56) = 1;
  *(_DWORD *)(v33 + 72) = 0;
  *(_BYTE *)(v33 + 64) = 0;
  result = htc_send_pkt((__int64)a1, v33);
  if ( !(_DWORD)result )
  {
    result = htc_wait_recv_ctrl_message((__int64)a1);
    if ( !(_DWORD)result )
    {
      if ( (unsigned __int16)*((_DWORD *)a1 + 776) != 3 || *((_DWORD *)a1 + 840) <= 0xBu )
      {
        v46 = 255;
        goto LABEL_45;
      }
      v43 = *((_DWORD *)a1 + 777);
      v44 = HIWORD(*((_DWORD *)a1 + 776));
      v45 = *((unsigned __int8 *)a1 + 3112);
      if ( (dword_B804 & 8) != 0 )
        qdf_trace_msg(
          56,
          2,
          "%s: htc_connect_service, service 0x%X connect response from target status:%d, assigned ep: %d\n",
          "htc_connect_service",
          v44,
          (unsigned __int8)v43,
          BYTE1(v43));
      *(_BYTE *)(a3 + 20) = v43;
      if ( !(_BYTE)v43 )
      {
        v9 = BYTE1(v43);
        if ( *(_QWORD *)a3 && v45 - 1 <= 0x7F )
        {
          if ( v45 >= *(unsigned __int8 *)(a3 + 8) )
            v47 = *(unsigned __int8 *)(a3 + 8);
          else
            v47 = v45;
          qdf_mem_copy(*(_QWORD *)a3, (_DWORD)a1 + 3116, v47);
          *(_BYTE *)(a3 + 9) = v47;
        }
        *((_BYTE *)a1 + 3408) = 0;
        if ( BYTE1(v43) >= 9u )
        {
          v46 = 318;
          goto LABEL_45;
        }
        v10 = HIWORD(v43);
        if ( !HIWORD(v43) )
        {
          v46 = 323;
          goto LABEL_45;
        }
        v7 = (unsigned __int8)credit_allocation;
        goto LABEL_5;
      }
      if ( (unsigned int)*a2 - 261 >= 2 && (dword_B804 & 1) != 0 )
        qdf_trace_msg(
          56,
          2,
          "%s: Target failed service 0x%X connect request(status:%d)\n",
          "htc_connect_service",
          v44,
          (unsigned __int8)v43);
      *((_BYTE *)a1 + 3408) = 0;
      result = 27;
    }
  }
LABEL_61:
  if ( (dword_B804 & 8) != 0 )
  {
    v48 = result;
    qdf_trace_msg(56, 2, "%s: -htc_connect_service\n", "htc_connect_service");
    return v48;
  }
  return result;
}
