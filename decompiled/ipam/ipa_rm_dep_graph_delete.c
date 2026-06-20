long double __fastcall ipa_rm_dep_graph_delete(_QWORD *a1)
{
  long double result; // q0
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0

  if ( a1 )
  {
    kfree(*a1);
    kfree(a1[1]);
    kfree(a1[2]);
    kfree(a1[3]);
    kfree(a1[4]);
    kfree(a1[5]);
    kfree(a1[6]);
    kfree(a1[7]);
    kfree(a1[8]);
    kfree(a1[9]);
    kfree(a1[10]);
    kfree(a1[11]);
    kfree(a1[12]);
    kfree(a1[13]);
    kfree(a1[14]);
    kfree(a1[15]);
    kfree(a1[16]);
    kfree(a1[17]);
    kfree(a1[18]);
    kfree(a1[19]);
    kfree(a1[20]);
    kfree(a1[21]);
    a1[20] = 0;
    a1[21] = 0;
    a1[18] = 0;
    a1[19] = 0;
    a1[16] = 0;
    a1[17] = 0;
    a1[14] = 0;
    a1[15] = 0;
    a1[12] = 0;
    a1[13] = 0;
    a1[10] = 0;
    a1[11] = 0;
    a1[8] = 0;
    a1[9] = 0;
    a1[6] = 0;
    a1[7] = 0;
    a1[4] = 0;
    a1[5] = 0;
    a1[2] = 0;
    a1[3] = 0;
    *a1 = 0;
    a1[1] = 0;
  }
  else
  {
    printk(&unk_3DA65E, "ipa_rm_dep_graph_delete");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(ipc_logbuf, "ipa_rm %s:%d invalid params\n", "ipa_rm_dep_graph_delete", 49);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      return ipc_log_string(ipc_logbuf_low, "ipa_rm %s:%d invalid params\n", "ipa_rm_dep_graph_delete", 49);
    }
  }
  return result;
}
