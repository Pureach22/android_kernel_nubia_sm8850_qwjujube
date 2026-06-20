void sub_3ADD8C()
{
  __int64 v0; // x9
  __int64 v1; // x19
  __int64 v2; // x20
  __int64 v3; // x21
  unsigned int v4; // w22
  int v5; // w23
  __int64 v6; // x29
  __int64 v7; // x24
  unsigned __int8 peer_bw; // w0
  int v9; // w8
  unsigned __int8 v10; // w20
  int v11; // w0
  int v12; // w8
  unsigned int v13; // w9
  int v14; // w9

  v7 = v0 + 2956;
  *(_BYTE *)(v6 - 12) = 8;
  if ( v3 && ((1 << *(_BYTE *)(v3 + 18)) & 0xFFFFEFBF) != 0 )
  {
    peer_bw = hdd_ndp_get_peer_bw(v2 + 2688, *(_QWORD *)(v1 + 224), v6 - 12);
    v9 = *(unsigned __int16 *)(v3 + 120);
    v10 = peer_bw;
    if ( v9 == 0xFFFF )
    {
      if ( v4 > 0x1F )
        JUMPOUT(0x3AE234);
      ++*(_DWORD *)(v7 + 48LL * v4 + 44);
      if ( (*(_BYTE *)(v1 + 130) & 6) == 0 )
        _skb_get_hash_net(0, v1);
      v12 = *(_DWORD *)(v1 + 152) >> 30;
      if ( v5 == 4 )
      {
        v13 = *(unsigned __int8 *)(v6 - 12);
        if ( v13 <= 7 )
          v11 = (v12 | (4 * v13)) + 14;
        else
          v11 = 13;
      }
      else
      {
        v11 = (v12 | (4 * v5)) - 3;
      }
      v9 = -1;
    }
    else
    {
      v11 = (unsigned __int8)*(_WORD *)(v3 + 120);
    }
    v14 = v11 | (v10 << 8);
    if ( v14 != v9 && *(_QWORD *)(v3 + 528) )
    {
      if ( v14 == 0xFFFF )
        JUMPOUT(0x3AE228);
      *(_WORD *)(v3 + 120) = v14;
    }
    JUMPOUT(0x3ADCD4);
  }
  JUMPOUT(0x3AE1C8);
}
