__int64 __fastcall msm_vidc_add_children(__int64 a1, unsigned int a2)
{
  __int64 v2; // x20
  __int64 *v3; // x19
  __int64 v4; // x21
  unsigned int v5; // w24
  __int64 v6; // x0
  __int64 v7; // x2

  if ( a2 >= 0xC7 )
  {
    __break(0x5512u);
    return add_node_list(a1);
  }
  v2 = 0;
  v3 = (__int64 *)(a1 + 4040);
  _ReadStatusReg(SP_EL0);
  v4 = a1 + 168LL * a2 + 4372;
  while ( 1 )
  {
    v5 = *(_DWORD *)(v4 + v2);
    if ( !v5 )
      return 0;
    if ( v5 <= 0xC4 )
      break;
LABEL_4:
    v2 += 4;
    if ( v2 == 100 )
      return 0;
  }
  v6 = vzalloc_noprof(24);
  if ( v6 )
  {
    *(_QWORD *)v6 = v6;
    *(_QWORD *)(v6 + 8) = v6;
    v7 = *v3;
    *(_DWORD *)(v6 + 16) = v5;
    if ( *(__int64 **)(v7 + 8) != v3 || (__int64 *)v6 == v3 || v7 == v6 )
    {
      _list_add_valid_or_report(v6);
    }
    else
    {
      *(_QWORD *)(v7 + 8) = v6;
      *(_QWORD *)v6 = v7;
      *(_QWORD *)(v6 + 8) = v3;
      *v3 = v6;
    }
    goto LABEL_4;
  }
  if ( (msm_vidc_debug & 1) != 0 )
    printk(&unk_8C985, "err ", 0xFFFFFFFFLL, "codec", "add_node_list");
  return 4294967284LL;
}
