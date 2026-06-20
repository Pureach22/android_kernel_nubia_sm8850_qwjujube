_QWORD *__fastcall usb_cser_alloc_req(__int64 a1, unsigned int a2, unsigned int a3)
{
  __int64 v6; // x0
  __int64 v7; // x2
  __int64 v8; // x3
  _QWORD *v9; // x19
  __int64 v10; // x0
  __int64 v11; // x2
  __int64 v12; // x3

  v6 = usb_ep_alloc_request(a1, a3);
  v9 = (_QWORD *)v6;
  if ( v6 )
  {
    *(_DWORD *)(v6 + 8) = a2;
    v10 = _kmalloc_noprof(a2, a3);
    *v9 = v10;
    if ( !v10 )
    {
      printk(&unk_9394, "usb_cser_alloc_req", v11, v12);
      usb_ep_free_request(a1, v9);
      return nullptr;
    }
  }
  else
  {
    printk(&unk_9024, "usb_cser_alloc_req", v7, v8);
  }
  return v9;
}
