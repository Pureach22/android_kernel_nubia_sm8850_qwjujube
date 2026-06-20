unsigned __int64 __fastcall rmnet_ctl_endpoint_setdev(unsigned __int64 result)
{
  atomic_store(result, (unsigned __int64 *)&ctl_ep);
  return result;
}
