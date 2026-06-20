__int64 __fastcall _qdf_nbuf_set_rx_cksum(__int64 a1, _DWORD *a2, __int64 a3, __int64 a4)
{
  int v4; // w9
  int v6; // w10

  v4 = a2[1];
  if ( v4 == 32 )
  {
    v6 = *(_DWORD *)(a1 + 129);
    *(_BYTE *)(a1 + 128) = *(_BYTE *)(a1 + 128) & 0x9F | 0x20;
    *(_DWORD *)(a1 + 129) = v6 & 0xFFFFFF3F | ((a2[3] & 3) << 6);
    return 0;
  }
  else if ( v4 == 16 )
  {
    *(_BYTE *)(a1 + 128) |= 0x60u;
    *(_DWORD *)(a1 + 140) = a2[2];
    return 0;
  }
  else if ( v4 )
  {
    printk(&unk_A39F36, a2, a3, a4);
    return 11;
  }
  else
  {
    *(_BYTE *)(a1 + 128) &= 0x9Fu;
    return 0;
  }
}
