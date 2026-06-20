__int64 __fastcall mem_buf_request_mem(__int64 a1)
{
  unsigned __int64 inited; // x0
  unsigned __int64 v3; // x19
  unsigned __int64 v4; // x20
  unsigned __int64 v5; // x0
  int v6; // w21

  inited = mem_buf_init_txn(*(_QWORD *)msgqs, a1);
  v3 = inited;
  if ( inited < 0xFFFFFFFFFFFFF001LL )
  {
    v5 = mem_buf_construct_alloc_req(
           inited,
           *(_QWORD *)a1,
           *(_QWORD *)(a1 + 8),
           *(unsigned int *)(a1 + 32),
           *(_QWORD *)(a1 + 40),
           *(unsigned int *)(a1 + 28));
    v4 = v5;
    if ( v5 < 0xFFFFFFFFFFFFF001LL )
    {
      v6 = mem_buf_msgq_send(*(_QWORD *)msgqs, v5);
      kfree(v4);
      if ( v6 < 0 )
        LODWORD(v4) = v6;
      else
        LODWORD(v4) = mem_buf_txn_wait(*(_QWORD *)msgqs, v3);
    }
    mem_buf_destroy_txn(*(_QWORD *)msgqs, v3);
  }
  else
  {
    LODWORD(v4) = inited;
  }
  return (unsigned int)v4;
}
