__int64 __fastcall hif_completion_thread_startup_by_ceid(_QWORD *a1, int a2)
{
  int *v4; // x9
  _QWORD *v5; // x10
  int v6; // w22
  __int64 v7; // x21
  int v8; // w23
  int v9; // w24
  _QWORD *v10; // x20
  int v11; // w25
  int v12; // w24
  __int64 v13; // x0

  if ( a2 > 11 )
    return 4294967274LL;
  if ( (unsigned int)a2 >= 0xD )
  {
    __break(0x5512u);
    v13 = MEMORY[0x3AE6DA4]();
    return hif_ce_ipa_get_ce_resource(v13);
  }
  else if ( a1[3639] && a1[3638] )
  {
    v4 = (int *)(a1[3425] + 32LL * a2);
    v5 = &a1[17 * a2];
    v6 = v4[2];
    v7 = a1[a2 + 60];
    v8 = *v4;
    v9 = v4[4];
    v10 = v5 + 3427;
    if ( v6 )
    {
      v11 = (int)a1;
      qdf_trace_msg(61, 8, "%s: pipe_num:%d pipe_info:0x%pK\n", "hif_completion_thread_startup_by_ceid", a2, v5 + 3427);
      ce_send_cb_register(*v10, hif_pci_ce_send_done, v10, v8 & 8);
      LODWORD(a1) = v11;
      *((_DWORD *)v10 + 18) = v6 - 1;
    }
    if ( v9 )
    {
      v12 = (int)a1;
      qdf_trace_msg(61, 8, "%s: pipe_num:%d pipe_info:0x%pK\n", "hif_completion_thread_startup_by_ceid", a2, v10);
      ce_recv_cb_register(*v10, hif_pci_ce_recv_data, v10, v8 & 8);
      LODWORD(a1) = v12;
    }
    if ( v6 )
    {
      *((_DWORD *)v10 + 14) = 0;
      v10[8] = 0;
    }
    if ( (*(_BYTE *)(v7 + 12) & 0x40) == 0 )
      qdf_mem_copy((_DWORD)v10 + 88, (_DWORD)a1 + 29096, 0x30u);
    return 0;
  }
  else
  {
    qdf_trace_msg(61, 2, "%s: no completion handler registered", "hif_completion_thread_startup_by_ceid");
    return 4294967282LL;
  }
}
