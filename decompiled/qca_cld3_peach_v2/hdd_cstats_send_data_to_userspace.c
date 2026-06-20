__int64 __fastcall hdd_cstats_send_data_to_userspace(_WORD *a1, unsigned int a2, int a3, char a4)
{
  unsigned int v6; // w26
  unsigned int v7; // w8
  unsigned int v8; // w28
  __int64 v9; // x23
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  _DWORD *v26; // x0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  int v35; // w9
  __int64 v36; // x21
  int v37; // w8
  __int64 result; // x0
  unsigned int v39; // w22
  __int64 v40; // x0
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  unsigned int v49; // w19
  __int64 v50; // [xsp+0h] [xbp-10h] BYREF
  __int64 v51; // [xsp+8h] [xbp-8h]

  v51 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a3 == 1 )
  {
    *a1 = 111;
    a1[1] = a2 - 4;
    if ( (a4 & 1) != 0 )
    {
      v6 = a2 - 1;
      v50 = 0;
      if ( a2 - 1 >= 3 )
      {
        v7 = 2;
        do
        {
          v8 = v7;
          if ( !(unsigned int)qdf_mem_cmp((char *)a1 + v7, "CS_FSM", 6u) && v8 + 6 < v6 )
          {
            v9 = 0;
            while ( (unsigned int)qdf_mem_cmp((char *)a1 + v8 + v9 + 6, "CS_FEM", 6u) )
            {
              if ( !(7 - a2 + v8 + (_DWORD)++v9) )
                goto LABEL_9;
            }
            if ( (unsigned int)v9 < 0x10 )
            {
              qdf_trace_msg(
                0x33u,
                8u,
                "%s: Payload too short",
                v10,
                v11,
                v12,
                v13,
                v14,
                v15,
                v16,
                v17,
                "hdd_print_second_64_bits_cstats_fw_type");
            }
            else
            {
              v50 = 0;
              qdf_mem_copy(&v50, (char *)a1 + v8 + 14, 8u);
              qdf_trace_msg(
                0x33u,
                8u,
                "%s: Second 64 bits:%llu",
                v18,
                v19,
                v20,
                v21,
                v22,
                v23,
                v24,
                v25,
                "hdd_print_second_64_bits_cstats_fw_type",
                v50);
            }
            v8 += v9 + 11;
          }
LABEL_9:
          v7 = v8 + 1;
        }
        while ( v8 + 1 < v6 );
      }
    }
  }
  else if ( !a3 )
  {
    *a1 = 110;
    a1[1] = a2 - 4;
  }
  v26 = (_DWORD *)_netdev_alloc_skb(0, 2048, 2080);
  if ( v26 )
  {
    v35 = v26[29];
    v36 = (__int64)v26;
    ++hdd_cstats_send_data_to_userspace_nlmsg_seq;
    if ( v35 )
      v37 = 0;
    else
      v37 = v26[53] - v26[52];
    v39 = (a2 + 23) & 0xFFFFFFFC;
    if ( v37 >= (int)v39 && (v40 = _nlmsg_put(v26, 0)) != 0 )
    {
      *(_DWORD *)(v40 + 16) = 0;
      memcpy((void *)(v40 + 20), a1, a2);
      result = nl_srv_bcast(v36, 1u, 28);
      if ( (result & 0x80000000) != 0 )
      {
        v49 = result;
        qdf_trace_msg(
          0x38u,
          2u,
          "%s: Send Failed %d",
          v41,
          v42,
          v43,
          v44,
          v45,
          v46,
          v47,
          v48,
          "hdd_cstats_send_data_to_userspace",
          (unsigned int)result);
        result = v49;
      }
    }
    else
    {
      qdf_trace_msg(
        0x38u,
        2u,
        "%s: nlmsg_put() failed for msg size[%d]",
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        "hdd_cstats_send_data_to_userspace",
        v39,
        v50,
        v51);
      consume_skb(v36);
      result = 4294967274LL;
    }
  }
  else
  {
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: dev_alloc_skb() failed",
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      "hdd_cstats_send_data_to_userspace");
    result = 4294967284LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
