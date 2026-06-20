__int64 __fastcall cdp_cfg_set_peer_unmap_conf_support(
        __int64 result,
        char a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8
  __int64 (__fastcall *v11)(_QWORD); // x8

  if ( !result || !*(_QWORD *)result )
    return qdf_trace_msg(
             0x89u,
             8u,
             "%s: invalid instance",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "cdp_cfg_set_peer_unmap_conf_support");
  v10 = *(_QWORD *)(*(_QWORD *)result + 104LL);
  if ( v10 )
  {
    v11 = *(__int64 (__fastcall **)(_QWORD))(v10 + 88);
    if ( v11 )
    {
      if ( *((_DWORD *)v11 - 1) != -1560483463 )
        __break(0x8228u);
      return v11(a2 & 1);
    }
  }
  return result;
}
