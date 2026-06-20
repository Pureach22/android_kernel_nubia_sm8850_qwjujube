__int64 __fastcall rmnet_map_do_flow_control(__int64 a1, __int64 a2, unsigned int a3)
{
  int v3; // w9
  __int64 v6; // x8
  __int64 v7; // x10
  int v8; // w8
  unsigned __int8 *endpoint; // x0
  unsigned int v10; // w20

  v3 = *(_DWORD *)(a1 + 116);
  if ( v3 && *(_DWORD *)(a1 + 112) == v3 )
  {
    v6 = *(_QWORD *)(a1 + 216) + *(unsigned int *)(a1 + 212);
    v7 = *(_QWORD *)(v6 + 88);
    if ( !v7 || (v7 & 1) != 0 )
      v8 = 21;
    else
      v8 = (unsigned __int8)byte_1[(((v7 << 6) + 0xFFFFD000000000LL) & 0xFFFFFFFFFFF000LL | 0xFF00000000000000LL)
                                 + *(unsigned int *)(v6 + 100)];
  }
  else
  {
    v8 = *(unsigned __int8 *)(*(_QWORD *)(a1 + 224) + 1LL);
  }
  if ( v8 == 255 || (endpoint = rmnet_get_endpoint(a2, v8)) == nullptr )
  {
    v10 = 0;
  }
  else
  {
    if ( !(unsigned int)rmnet_vnd_do_flow_control(*((_QWORD *)endpoint + 1), a3) )
      return 1;
    v10 = 2;
  }
  sk_skb_reason_drop(0, a1, 2);
  return v10;
}
