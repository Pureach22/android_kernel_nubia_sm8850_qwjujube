_QWORD *__fastcall dp_rx_get_per_ring_pkt_avg(_QWORD *result, _DWORD *a2, _DWORD *a3)
{
  *a2 = result[2036];
  *a3 += *((_DWORD *)result + 4072);
  a2[1] = result[2040];
  *a3 += *((_DWORD *)result + 4080);
  a2[2] = result[2044];
  *a3 += *((_DWORD *)result + 4088);
  a2[3] = result[2048];
  *a3 += *((_DWORD *)result + 4096);
  a2[4] = result[2052];
  *a3 += *((_DWORD *)result + 4104);
  a2[5] = result[2056];
  *a3 += *((_DWORD *)result + 4112);
  a2[6] = result[2060];
  *a3 += *((_DWORD *)result + 4120);
  a2[7] = result[2064];
  *a3 += *((_DWORD *)result + 4128);
  return result;
}
