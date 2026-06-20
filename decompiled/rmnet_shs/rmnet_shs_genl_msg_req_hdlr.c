__int64 __fastcall rmnet_shs_genl_msg_req_hdlr(__int64 a1, __int64 a2)
{
  __int64 result; // x0

  result = 0xFFFFFFFFLL;
  if ( a2 )
  {
    if ( rmnet_shs_userspace_connected )
    {
      msg_last_net = *(_QWORD *)(a2 + 40);
      msg_last_snd_portid = *(_DWORD *)(a2 + 4);
      return 0;
    }
  }
  return result;
}
