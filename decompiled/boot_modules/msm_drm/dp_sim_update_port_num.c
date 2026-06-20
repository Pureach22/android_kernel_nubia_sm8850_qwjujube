__int64 __fastcall dp_sim_update_port_num(__int64 a1, unsigned int a2)
{
  __int64 ipc_log_context; // x0
  unsigned __int64 StatusReg; // x22
  unsigned int v7; // w19
  __int64 v8; // x23
  __int64 v9; // x8
  unsigned int v10; // w9
  unsigned __int64 v11; // x20
  char *v12; // x0
  __int64 v13; // x9
  size_t v14; // x2
  __int64 v15; // x22
  char *v16; // x21
  __int64 v17; // x10
  __int64 v18; // x11
  unsigned __int64 v19; // x1
  char *v20; // x14
  char *v21; // x13
  __int64 v22; // x0
  __int64 v23; // x2
  int v24; // w0
  unsigned int v25; // w19
  __int64 v26; // x0
  __int64 v27; // x1
  __int64 v28; // x2

  if ( a1 && (*(_DWORD *)(a1 + 16) & 0x80000000) != 0 )
  {
    ipc_log_context = get_ipc_log_context(a1);
    StatusReg = _ReadStatusReg(SP_EL0);
    v7 = a2;
    ipc_log_string(
      ipc_log_context,
      "[i][%-4d]Update port count from %d to %d\n",
      *(_DWORD *)(StatusReg + 1800),
      *(_DWORD *)(a1 + 2248),
      a2);
    v8 = a1;
    if ( (_drm_debug & 4) != 0 )
      printk(&unk_26BB53, *(unsigned int *)(StatusReg + 1800));
    else
      printk(&unk_272A5F, "dp_sim_update_port_num");
    mutex_lock(a1 + 80);
    v9 = a1;
    v10 = a2;
    if ( *(_DWORD *)(a1 + 2248) < a2 )
    {
      v11 = 48LL * a2;
      v12 = (char *)devm_kmalloc(*(_QWORD *)(a1 - 8), 48LL * v7, 3520);
      if ( !v12 )
      {
        v24 = -12;
LABEL_21:
        v25 = v24;
        mutex_unlock(v8 + 80);
        return v25;
      }
      v13 = *(unsigned int *)(a1 + 2248);
      v14 = 48 * v13;
      if ( (unsigned int)v13 > v7 )
      {
LABEL_24:
        v26 = _fortify_panic(17, v11, v14);
        return dp_sim_update_port_status(v26, v27, v28);
      }
      v15 = *(_QWORD *)(a1 + 2240);
      v16 = v12;
      memcpy(v12, *(const void **)(v8 + 2240), v14);
      if ( v15 )
        devm_kfree(*(_QWORD *)(v8 - 8));
      v17 = *(unsigned int *)(v8 + 2248);
      v9 = v8;
      v10 = v7;
      *(_QWORD *)(v8 + 2240) = v16;
      if ( (unsigned int)v17 < v7 )
      {
        v18 = 48 * v17;
        v19 = v11 - 48 * v17;
        while ( v19 > 0x2F )
        {
          v20 = &v16[v18];
          *((_QWORD *)v20 + 2) = 0;
          *((_QWORD *)v20 + 3) = 165153240;
          *((_QWORD *)v20 + 4) = 0;
          *((_QWORD *)v20 + 5) = 0;
          *(_QWORD *)v20 = 0x120003010000LL;
          *((_QWORD *)v20 + 1) = 0;
          if ( v11 < v18 + 6 )
            goto LABEL_23;
          v21 = &v16[v18];
          v18 += 48;
          v19 -= 48LL;
          v21[6] = v17++;
          if ( v7 == v17 )
            goto LABEL_18;
        }
        _fortify_panic(17, v19, 48);
LABEL_23:
        __break(1u);
        goto LABEL_24;
      }
    }
LABEL_18:
    v22 = *(_QWORD *)(v9 + 24);
    v23 = *(_QWORD *)(v9 + 2240);
    *(_DWORD *)(v9 + 2248) = v10;
    v24 = dp_mst_sim_update(v22, v10, v23);
    if ( !v24 )
      *(_DWORD *)(v8 + 2252) = v7;
    goto LABEL_21;
  }
  return 4294967274LL;
}
