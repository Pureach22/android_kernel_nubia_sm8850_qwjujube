__int64 __fastcall dp_ctrl_stream_off(__int64 result, __int64 a2)
{
  __int64 v2; // x19
  _DWORD *v3; // x8
  __int64 v5; // x0
  int v6; // w9
  __int64 v7; // x0
  __int64 (*v8)(void); // x8
  __int64 ipc_log_context; // x0

  if ( result )
  {
    if ( a2 )
    {
      v2 = result;
      if ( *(_BYTE *)(result + 257) == 1 )
      {
        v3 = *(_DWORD **)(a2 + 1024);
        if ( *(v3 - 1) != -2060240890 )
          __break(0x8228u);
        v5 = ((__int64 (__fastcall *)(__int64, _QWORD))v3)(a2, 0);
        v6 = *(_DWORD *)(a2 + 912);
        *(_BYTE *)(a2 + 972) = 0;
        if ( v6 == 1 )
        {
          v7 = *(_QWORD *)(v2 + 160);
        }
        else
        {
          if ( v6 )
          {
            ipc_log_context = get_ipc_log_context(v5);
            ipc_log_string(
              ipc_log_context,
              "[e][%-4d]Invalid stream:%d for clk disable\n",
              *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
              *(_DWORD *)(a2 + 912));
            result = printk(&unk_267D32, "dp_ctrl_disable_stream_clocks");
LABEL_13:
            --*(_DWORD *)(v2 + 276);
            return result;
          }
          v7 = *(_QWORD *)(v2 + 160);
        }
        v8 = *(__int64 (**)(void))(v7 + 48);
        if ( *((_DWORD *)v8 - 1) != -1712294539 )
          __break(0x8228u);
        result = v8();
        goto LABEL_13;
      }
    }
  }
  return result;
}
