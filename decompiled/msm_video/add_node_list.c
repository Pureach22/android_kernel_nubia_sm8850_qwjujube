__int64 __fastcall add_node_list(_QWORD *a1, int a2)
{
  __int64 v4; // x0

  v4 = vzalloc_noprof(24);
  if ( v4 )
  {
    *(_QWORD *)v4 = v4;
    *(_QWORD *)(v4 + 8) = v4;
    *(_DWORD *)(v4 + 16) = a2;
    list_add((_QWORD *)v4, a1);
    return 0;
  }
  else
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_8C985, "err ", 0xFFFFFFFFLL, "codec", "add_node_list");
    return 4294967284LL;
  }
}
