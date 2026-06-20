__int64 __fastcall dp_lphw_hpd_connect(__int64 result)
{
  __int64 (__fastcall **v1)(_QWORD); // x9
  __int64 (__fastcall *v2)(_QWORD); // x9
  __int64 v3; // x0
  __int64 ipc_log_context; // x0

  if ( result == 248 )
  {
    ipc_log_context = get_ipc_log_context(248);
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    return printk(&unk_275B6D, "dp_lphw_hpd_connect");
  }
  else
  {
    v1 = *(__int64 (__fastcall ***)(_QWORD))(result + 96);
    *(_WORD *)(result - 232) = 1;
    *(_BYTE *)(result - 230) = 1;
    if ( v1 )
    {
      v2 = *v1;
      if ( v2 )
      {
        v3 = *(_QWORD *)(result - 248);
        if ( *((_DWORD *)v2 - 1) != 711998475 )
          __break(0x8229u);
        return v2(v3);
      }
    }
  }
  return result;
}
