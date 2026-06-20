__int64 __fastcall csr_send_mb_disassoc_req_msg(__int64 a1, unsigned int a2, const void *a3, __int16 a4)
{
  __int64 result; // x0
  __int64 v6; // x20
  __int64 v9; // x22
  __int64 v11; // x0
  char v12; // w1
  __int64 v13; // x23
  __int64 v14; // x20
  int v15; // w9

  if ( a2 > 5 )
    return 16;
  result = 16;
  if ( a1 )
  {
    v6 = *(_QWORD *)(a1 + 17296);
    if ( v6 )
    {
      if ( *(_BYTE *)(v6 + 96LL * a2 + 1) == 1 )
      {
        v9 = a1;
        v11 = _qdf_mem_malloc(0x16u, "csr_send_mb_disassoc_req_msg", 6074);
        if ( v11 )
        {
          v12 = a2;
          *(_BYTE *)(v11 + 4) = a2;
          v13 = v6 + 96LL * a2;
          *(_DWORD *)v11 = 1446920;
          v14 = v11;
          wlan_mlme_get_mac_vdev_id(*(_QWORD *)(v9 + 21632), v12, (void *)(v11 + 5));
          qdf_mem_copy((void *)(v14 + 11), a3, 6u);
          *(_WORD *)(v14 + 18) = a4;
          v15 = *(_DWORD *)(v13 + 68) + 1;
          ++*(_DWORD *)(v13 + 64);
          *(_DWORD *)(v13 + 68) = v15;
          return umac_send_mb_message_to_mac(v14);
        }
        else
        {
          return 2;
        }
      }
      else
      {
        return 16;
      }
    }
  }
  return result;
}
