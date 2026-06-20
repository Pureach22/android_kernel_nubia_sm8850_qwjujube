_QWORD *__fastcall dp_rx_get_per_ring_pkt_avg(_QWORD *result, _DWORD *a2, _DWORD *a3)
{
  *a2 = result[2029];
  *a3 += *((_DWORD *)result + 4058);
  a2[1] = result[2033];
  *a3 += *((_DWORD *)result + 4066);
  a2[2] = result[2037];
  *a3 += *((_DWORD *)result + 4074);
  a2[3] = result[2041];
  *a3 += *((_DWORD *)result + 4082);
  a2[4] = result[2045];
  *a3 += *((_DWORD *)result + 4090);
  a2[5] = result[2049];
  *a3 += *((_DWORD *)result + 4098);
  a2[6] = result[2053];
  *a3 += *((_DWORD *)result + 4106);
  a2[7] = result[2057];
  *a3 += *((_DWORD *)result + 4114);
  return result;
}
