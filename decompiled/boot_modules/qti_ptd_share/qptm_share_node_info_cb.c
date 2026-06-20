__int64 __fastcall qptm_share_node_info_cb(__int64 a1, __int64 a2)
{
  unsigned int node_id; // w20
  const char *node_name; // x19
  __int64 v6; // x9
  __int64 v7; // x8
  _BYTE *v8; // x23
  __int64 v9; // x0
  __int64 i; // x20
  char v11; // w8
  char *v12; // x9
  __int64 v13; // x0

  node_id = -22;
  if ( a1 && a2 )
  {
    node_id = qptm_get_node_id();
    if ( (node_id & 0x80000000) != 0 )
    {
      v13 = *(_QWORD *)(a2 + 16);
      if ( v13 )
        ipc_log_string(v13, "[%s] unable to read node_id: %d\n", (const char *)(_ReadStatusReg(SP_EL0) + 2320), node_id);
    }
    else
    {
      node_name = (const char *)qptm_get_node_name(a1);
      v6 = smem_buffer;
      *(_WORD *)smem_buffer = node_id;
      v7 = *(_QWORD *)(a2 + 16);
      if ( v7 )
      {
        ipc_log_string(
          v7,
          "[%s] node_id=0x%x\n",
          (const char *)(_ReadStatusReg(SP_EL0) + 2320),
          (unsigned __int16)node_id);
        v6 = smem_buffer;
      }
      v8 = (_BYTE *)(v6 + 2);
      smem_buffer = v6 + 2;
      if ( node_name )
      {
        v9 = *(_QWORD *)(a2 + 16);
        if ( v9 )
        {
          ipc_log_string(v9, "[%s] node_name=%s\n", (const char *)(_ReadStatusReg(SP_EL0) + 2320), node_name);
          v8 = (_BYTE *)smem_buffer;
        }
        for ( i = 0; strlen(node_name) > (int)i; ++i )
        {
          v11 = node_name[(int)i];
          v12 = &v8[i];
          *v12 = v11;
          smem_buffer = (__int64)(v12 + 1);
        }
        v8 += i;
      }
      node_id = 0;
      *v8 = 0;
      smem_buffer = (__int64)(v8 + 1);
    }
  }
  return node_id;
}
