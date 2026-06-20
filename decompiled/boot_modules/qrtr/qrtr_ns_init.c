__int64 qrtr_ns_init()
{
  __int64 result; // x0
  __int64 v1; // x2
  __int64 v2; // x3
  __int64 v3; // x4
  __int64 v4; // x5
  __int64 v5; // x6
  __int64 v6; // x7
  unsigned int v7; // w22
  unsigned __int64 v8; // x0
  __int64 v9; // x3
  __int64 v10; // x4
  __int64 v11; // x5
  __int64 v12; // x6
  __int64 v13; // x7
  __int64 v14; // x20
  __int64 v15; // x9
  unsigned int v16; // w0
  __int64 v17; // x2
  __int64 v18; // x3
  __int64 v19; // x4
  __int64 v20; // x5
  __int64 v21; // x6
  __int64 v22; // x7
  unsigned int v23; // w0
  __int64 v24; // x3
  __int64 v25; // x4
  __int64 v26; // x5
  __int64 v27; // x6
  __int64 v28; // x7
  int v29; // [xsp+4h] [xbp-ACh] BYREF
  __int64 v30; // [xsp+8h] [xbp-A8h] BYREF
  int v31; // [xsp+10h] [xbp-A0h]
  _QWORD v32[2]; // [xsp+18h] [xbp-98h] BYREF
  __int16 *v33; // [xsp+28h] [xbp-88h] BYREF
  int v34; // [xsp+30h] [xbp-80h]
  int v35; // [xsp+34h] [xbp-7Ch]
  __int64 v36; // [xsp+38h] [xbp-78h]
  __int64 v37; // [xsp+40h] [xbp-70h]
  __int64 v38; // [xsp+48h] [xbp-68h]
  __int64 v39; // [xsp+50h] [xbp-60h]
  __int64 v40; // [xsp+58h] [xbp-58h]
  __int64 v41; // [xsp+60h] [xbp-50h]
  __int64 v42; // [xsp+68h] [xbp-48h]
  __int64 v43; // [xsp+70h] [xbp-40h]
  __int64 v44; // [xsp+78h] [xbp-38h]
  __int64 v45; // [xsp+80h] [xbp-30h]
  __int64 v46; // [xsp+88h] [xbp-28h]
  int v47; // [xsp+94h] [xbp-1Ch] BYREF
  __int64 v48; // [xsp+98h] [xbp-18h]
  __int64 v49; // [xsp+A0h] [xbp-10h]
  __int64 v50; // [xsp+A8h] [xbp-8h]

  v50 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v31 = 0;
  v30 = 0;
  v29 = 0x7FFFFFFF;
  qword_D980 = (__int64)&qword_D980;
  qword_D988 = (__int64)&qword_D980;
  _kthread_init_worker(&unk_D990, "(&qrtr_ns.kworker)->lock", &qrtr_ns_init___key);
  qword_D9E0 = 0;
  qword_D9E8 = 0;
  qword_D9C8 = (__int64)&qword_D9C8;
  qword_D9D0 = (__int64)&qword_D9C8;
  qword_D9D8 = (__int64)qrtr_ns_worker;
  ns_ilc = ipc_log_context_create(4, "qrtr_ns", 0);
  result = sock_create_kern(&init_net, 42, 2, 42, &qrtr_ns);
  if ( (result & 0x80000000) == 0 )
  {
    v7 = kernel_getsockname(qrtr_ns, &v30);
    if ( (v7 & 0x80000000) != 0 )
    {
      printk(&unk_DCCD, "qrtr_ns_init", v1, v2, v3, v4, v5, v6);
    }
    else
    {
      v8 = kthread_create_on_node(&kthread_worker_fn, &unk_D990, 0xFFFFFFFFLL, "qrtr_ns");
      v14 = v8;
      if ( v8 >= 0xFFFFFFFFFFFFF001LL )
      {
        qword_D9F0 = v8;
        printk(&unk_E0D7, "qrtr_ns_init", v8, v9, v10, v11, v12, v13);
      }
      else
      {
        wake_up_process(v8);
        qword_D9F0 = v14;
        v31 = -2;
        v15 = *(_QWORD *)(qrtr_ns + 24);
        dword_D9F8 = HIDWORD(v30);
        *(_QWORD *)(v15 + 264) = qrtr_ns_data_ready;
        v16 = kernel_bind();
        if ( (v16 & 0x80000000) != 0 )
        {
          v7 = v16;
          printk(&unk_E038, "qrtr_ns_init", v17, v18, v19, v20, v21, v22);
        }
        else
        {
          sock_setsockopt(qrtr_ns, 1, 8, &v29, 1, 4);
          word_D970 = 42;
          qword_D974 = 0xFFFFFFFEFFFFFFFFLL;
          v32[0] = &v47;
          v32[1] = 20;
          v46 = 0;
          v44 = 0;
          v45 = 0;
          v42 = 0;
          v43 = 0;
          v40 = 0;
          v41 = 0;
          v38 = 0;
          v39 = 0;
          v36 = 0;
          v37 = 0;
          v48 = 0;
          v49 = 0;
          v47 = 2;
          v33 = &word_D970;
          v35 = 0;
          v34 = 12;
          v23 = kernel_sendmsg(qrtr_ns, &v33, v32, 1, 20);
          if ( (v23 & 0x80000000) == 0 )
          {
            module_put(*(_QWORD *)(*(_QWORD *)(qrtr_ns + 32) + 8LL));
            module_put(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(qrtr_ns + 24) + 576LL) + 392LL));
            result = 0;
            goto LABEL_13;
          }
          v7 = v23;
          printk(&unk_E189, "say_hello", v23, v24, v25, v26, v27, v28);
        }
        kthread_stop(qword_D9F0);
      }
    }
    sock_release(qrtr_ns);
    result = v7;
  }
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
