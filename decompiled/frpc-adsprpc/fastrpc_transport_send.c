__int64 __fastcall fastrpc_transport_send(__int64 a1)
{
  if ( *(_DWORD *)(a1 + 64136) )
    return 4294967264LL;
  else
    return rpmsg_send(*(_QWORD *)(*(_QWORD *)(a1 + 160) + 968LL));
}
