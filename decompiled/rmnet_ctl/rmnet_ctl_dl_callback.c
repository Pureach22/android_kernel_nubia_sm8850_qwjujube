__int64 __fastcall rmnet_ctl_dl_callback(__int64 a1, __int64 a2)
{
  ++*(_QWORD *)(a1 + 8);
  return rmnet_ctl_endpoint_post(a2, 0xFFFFFFFFLL);
}
