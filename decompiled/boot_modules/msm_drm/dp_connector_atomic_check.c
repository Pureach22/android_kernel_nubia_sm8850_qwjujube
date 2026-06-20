__int64 __fastcall dp_connector_atomic_check(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 result; // x0
  int v5; // w9
  __int64 v6; // x10
  __int64 v7; // x9
  __int64 v8; // x10
  __int64 v9; // x19
  __int64 ipc_log_context; // x0
  unsigned __int64 StatusReg; // x20

  result = 4294967274LL;
  if ( a1 )
  {
    if ( a2 )
    {
      if ( a3 )
      {
        v5 = *(_DWORD *)(a1 + 152);
        if ( v5 < *(_DWORD *)(a3 + 40) )
        {
          v6 = *(_QWORD *)(a3 + 48) + 40LL * v5;
          v7 = *(_QWORD *)(v6 + 16);
          if ( v7 )
          {
            v8 = *(_QWORD *)(v6 + 24);
            if ( v8 )
            {
              if ( *(_DWORD *)(v8 + 128) == *(_DWORD *)(v7 + 128) )
              {
                return 0;
              }
              else
              {
                v9 = a1;
                ipc_log_context = get_ipc_log_context();
                StatusReg = _ReadStatusReg(SP_EL0);
                ipc_log_string(ipc_log_context, "[d][%-4d]colorspace has been updated\n", *(_DWORD *)(StatusReg + 1800));
                if ( (_drm_debug & 4) != 0 )
                  _drm_dev_dbg(
                    0,
                    0,
                    0,
                    "[msm-dp-debug][%-4d]colorspace has been updated\n",
                    *(_DWORD *)(StatusReg + 1800));
                *(_BYTE *)(v9 + 4744) = 1;
                return 0;
              }
            }
          }
        }
      }
    }
  }
  return result;
}
