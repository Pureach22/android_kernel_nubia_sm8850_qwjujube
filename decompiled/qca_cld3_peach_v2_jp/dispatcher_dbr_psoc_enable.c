__int64 __fastcall dispatcher_dbr_psoc_enable(__int64 a1)
{
  __int64 v1; // x8
  __int64 (*v2)(void); // x8

  if ( a1 && (v1 = *(_QWORD *)(a1 + 2128)) != 0 )
  {
    v2 = *(__int64 (**)(void))(v1 + 1776);
    if ( v2 )
    {
      if ( *((_DWORD *)v2 - 1) != -770124015 )
        __break(0x8228u);
      return v2();
    }
    else
    {
      return 0;
    }
  }
  else
  {
    qdf_trace_msg(56, 2, "%s: tx_ops is NULL", "dispatcher_dbr_psoc_enable");
    return 16;
  }
}
