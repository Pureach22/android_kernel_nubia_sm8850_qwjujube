__int64 __fastcall mem_buf_msgq_alloc(__int64 a1)
{
  __int64 v2; // x19
  __int64 v3; // x21
  int v4; // w0
  unsigned __int64 v5; // x0
  int v6; // w9
  __int64 v7; // x0
  __int64 v8; // x20
  unsigned __int64 v9; // x8
  const char *v11; // [xsp+0h] [xbp-20h] BYREF
  _QWORD v12[3]; // [xsp+8h] [xbp-18h] BYREF

  v12[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12[0] = msgq_ops;
  v12[1] = 0;
  if ( (mem_buf_capability & 3) == 0 )
  {
LABEL_10:
    LODWORD(v2) = 0;
    goto LABEL_23;
  }
  v11 = nullptr;
  mem_buf_wq = alloc_workqueue("mem_buf_wq", 18, 0);
  if ( !mem_buf_wq )
  {
    dev_err(a1, "Unable to initialize workqueue\n");
    LODWORD(v2) = -22;
    goto LABEL_23;
  }
  LODWORD(v2) = of_property_read_string_helper(*(_QWORD *)(a1 + 744), "qcom,msgq-names", 0, 0, 0);
  if ( (v2 & 0x80000000) != 0 )
  {
    dev_err(a1, "Invalid qcom,msgq-names property %d\n", v2);
  }
  else
  {
    msgqs = _kmalloc_noprof(8LL * (unsigned int)v2, 3520);
    if ( msgqs )
    {
      num_msgqs = v2;
      if ( !(_DWORD)v2 )
        goto LABEL_23;
      v3 = 0;
      while ( 1 )
      {
        v4 = of_property_read_string_helper(*(_QWORD *)(a1 + 744), "qcom,msgq-names", &v11, 1, (unsigned int)v3);
        if ( v4 < 0 )
        {
          LODWORD(v2) = v4;
          goto LABEL_16;
        }
        v5 = mem_buf_msgq_register(v11, v12);
        *(_QWORD *)(msgqs + 8 * v3) = v5;
        if ( v5 >= 0xFFFFFFFFFFFFF001LL )
          break;
        if ( ++v3 >= num_msgqs )
          goto LABEL_10;
      }
      dev_err(a1, "Unable to register for mem-buf message queue %s\n", v11);
      v2 = *(_QWORD *)(msgqs + 8 * v3);
    }
    else
    {
      LODWORD(v2) = -12;
    }
  }
LABEL_16:
  v6 = num_msgqs;
  v7 = msgqs;
  if ( num_msgqs >= 1 )
  {
    v8 = 0;
    do
    {
      v9 = *(_QWORD *)(v7 + 8 * v8);
      if ( v9 && v9 <= 0xFFFFFFFFFFFFF000LL )
      {
        mem_buf_msgq_unregister(*(_QWORD *)(v7 + 8 * v8));
        v7 = msgqs;
        v6 = num_msgqs;
      }
      ++v8;
    }
    while ( v8 < v6 );
  }
  kfree(v7);
  num_msgqs = 0;
  msgqs = 0;
  destroy_workqueue(mem_buf_wq);
  mem_buf_wq = 0;
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v2;
}
