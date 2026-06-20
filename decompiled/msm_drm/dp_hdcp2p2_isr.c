__int64 __fastcall dp_hdcp2p2_isr(__int64 a1)
{
  __int64 v1; // x23
  unsigned int *v3; // x24
  unsigned __int64 StatusReg; // x25
  __int64 v5; // x8
  __int64 v6; // x27
  __int64 v7; // x0
  unsigned int v8; // w22
  __int64 ipc_log_context; // x0
  void (__fastcall *v10)(_QWORD); // x8
  __int64 v12; // x0

  if ( a1 && (v1 = *(_QWORD *)(a1 + 120)) != 0 )
  {
    v3 = *(unsigned int **)(a1 + 96);
    if ( v3 )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      do
      {
        v5 = *v3;
        if ( !(_DWORD)v5 )
          break;
        v6 = *((_QWORD *)v3 + 1);
        v7 = readl_relaxed(*(_QWORD *)(v1 + 8) + v5);
        if ( v6 )
        {
          v8 = v7;
          do
          {
            if ( !*(_DWORD *)v6 )
              break;
            if ( (v8 & (*(_DWORD *)v6 >> 2)) != 0 )
            {
              ipc_log_context = get_ipc_log_context(v7);
              ipc_log_string(ipc_log_context, "[d][%-4d]%s\n", *(_DWORD *)(StatusReg + 1800), *(const char **)(v6 + 8));
              if ( (_drm_debug & 4) != 0 )
                _drm_dev_dbg(
                  0,
                  0,
                  0,
                  "[msm-dp-debug][%-4d]%s\n",
                  *(_DWORD *)(StatusReg + 1800),
                  *(const char **)(v6 + 8));
              v10 = *(void (__fastcall **)(_QWORD))(v6 + 16);
              if ( v10 )
              {
                if ( *((_DWORD *)v10 - 1) != 803301357 )
                  __break(0x8228u);
                v10(a1);
              }
              v7 = writel_relaxed(v8 | (*(_DWORD *)v6 >> 1), *(_QWORD *)(v1 + 8) + *v3);
            }
            v6 += 24;
          }
          while ( v6 );
        }
        v3 += 4;
      }
      while ( v3 );
    }
    return 0;
  }
  else
  {
    v12 = get_ipc_log_context(a1);
    ipc_log_string(v12, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_275B6D, "dp_hdcp2p2_isr");
    return 4294967274LL;
  }
}
