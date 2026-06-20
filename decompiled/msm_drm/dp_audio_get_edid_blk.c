unsigned __int64 __fastcall dp_audio_get_edid_blk(__int64 a1, __int64 a2)
{
  unsigned __int64 result; // x0
  __int64 v4; // x8
  __int64 v5; // x8
  int v6; // w9
  __int64 v7; // x0
  void *v8; // x0
  __int64 ipc_log_context; // x0

  if ( a2 )
  {
    result = dp_audio_get_data();
    if ( result >= 0xFFFFFFFFFFFFF001LL )
      return result;
    v4 = *(_QWORD *)(result + 136);
    if ( v4 )
    {
      v5 = *(_QWORD *)(v4 + 96);
      if ( v5 )
      {
        *(_QWORD *)a2 = v5 + 11;
        v6 = *(_DWORD *)(v5 + 164);
        *(_QWORD *)(a2 + 16) = v5 + 168;
        *(_DWORD *)(a2 + 8) = v6;
        *(_DWORD *)(a2 + 24) = *(_DWORD *)(v5 + 172);
        return 0;
      }
    }
    ipc_log_context = get_ipc_log_context(result);
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid panel data\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v8 = &unk_2760FF;
  }
  else
  {
    v7 = get_ipc_log_context(a1);
    ipc_log_string(v7, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v8 = &unk_275B6D;
  }
  printk(v8, "dp_audio_get_edid_blk");
  return 4294967274LL;
}
