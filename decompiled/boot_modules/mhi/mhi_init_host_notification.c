__int64 __fastcall mhi_init_host_notification(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  int v5; // w8
  __int64 v6; // x8
  int v7; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v8; // [xsp+8h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = 0;
  result = mhi_get_capability_offset(a1, 6, &v7);
  if ( !(_DWORD)result )
  {
    v5 = v7;
    *(_QWORD *)(a1 + 64) = a2;
    v7 = v5 + 4;
    mhi_write_reg(a1);
    result = 0;
    v6 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
    if ( v6 )
    {
      if ( !*(_DWORD *)(v6 + 24) )
      {
        ipc_log_string(
          *(_QWORD *)(v6 + 32),
          "[D][%s] Host notification DB setup complete.\n",
          "mhi_init_host_notification");
        result = 0;
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
