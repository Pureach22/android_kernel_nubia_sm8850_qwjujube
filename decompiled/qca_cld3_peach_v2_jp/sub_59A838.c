__int64 __usercall sub_59A838@<X0>(__int64 _X8@<X8>)
{
  __asm { STGP            X15, X14, [X8,#0x10] }
  return wmi_unified_ndp_responder_req_cmd_send();
}
