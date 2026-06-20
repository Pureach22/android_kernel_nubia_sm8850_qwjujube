__int64 __fastcall send_peer_txq_flush_tids(
        __int64 a1,
        const void *a2,
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
  __int64 v11; // x19
  unsigned int v12; // w0
  __int64 result; // x0
  _QWORD v14[2]; // [xsp+10h] [xbp-10h] BYREF

  v14[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)(a1 + 2800);
  v14[0] = 0;
  if ( v10 && (v11 = *(_QWORD *)(v10 + 16)) != 0 )
  {
    qdf_mem_copy((char *)v14 + 1, a2, 6u);
    v12 = wmi_unified_peer_flush_tids_send(v11);
    result = qdf_status_to_os_return(v12);
  }
  else
  {
    qdf_trace_msg(0x49u, 2u, "%s: Invalid wmi handle", a3, a4, a5, a6, a7, a8, a9, a10, "send_peer_txq_flush_tids");
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
