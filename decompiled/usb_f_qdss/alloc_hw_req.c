__int64 __fastcall alloc_hw_req(__int64 *a1)
{
  __int64 v1; // x19
  __int64 v2; // x0
  __int64 v3; // x1
  __int64 v4; // x8
  __int64 result; // x0

  v1 = *a1;
  v2 = usb_ep_alloc_request(a1, 2080);
  if ( v2 )
  {
    v4 = v2;
    result = 0;
    *(_DWORD *)(v4 + 8) = 0x8000;
    *(_QWORD *)(v1 + 288) = v4;
  }
  else
  {
    printk(&unk_85A0, v3);
    return 4294967284LL;
  }
  return result;
}
