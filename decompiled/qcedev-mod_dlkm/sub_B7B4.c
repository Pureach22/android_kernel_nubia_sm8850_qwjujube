__int64 __fastcall sub_B7B4(int a1, int a2, void *a3)
{
  __int64 v3; // x20

  if ( v3 )
    JUMPOUT(0xC9618);
  return qcedev_offload_cipher_req_cb(a1, a2, a3);
}
