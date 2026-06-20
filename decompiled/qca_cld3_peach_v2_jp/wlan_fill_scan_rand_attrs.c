__int64 __fastcall wlan_fill_scan_rand_attrs(
        __int64 result,
        char a2,
        int *a3,
        int *a4,
        _BYTE *a5,
        unsigned __int8 *a6,
        unsigned __int8 *a7)
{
  int v12; // w8
  int v13; // w11
  int v14; // w10
  int v15; // w4
  int v16; // w5
  int v17; // w6
  int v18; // w7
  int v19; // w9
  int v20; // w10
  int v21; // w11

  *a5 = 0;
  if ( (a2 & 8) != 0 && !*(_DWORD *)(result + 16) )
  {
    result = wlan_vdev_is_up();
    if ( (_DWORD)result )
    {
      v12 = (int)a7;
      *a5 = 1;
      v13 = *a3;
      *((_WORD *)a6 + 2) = *((_WORD *)a3 + 2);
      *(_DWORD *)a6 = v13;
      v14 = *a4;
      *((_WORD *)a7 + 2) = *((_WORD *)a4 + 2);
      *(_DWORD *)a7 = v14;
      if ( a6 )
      {
        v15 = *a6;
        v16 = a6[1];
        v17 = a6[2];
        v18 = a6[5];
        if ( a7 )
        {
LABEL_7:
          v19 = *a7;
          v20 = a7[1];
          v21 = a7[2];
          v12 = a7[5];
          return qdf_trace_msg(
                   72,
                   8,
                   "%s: Random mac addr: %02x:%02x:%02x:**:**:%02x and Random mac mask: %02x:%02x:%02x:**:**:%02x",
                   "wlan_fill_scan_rand_attrs",
                   v15,
                   v16,
                   v17,
                   v18,
                   v19,
                   v20,
                   v21,
                   v12);
        }
      }
      else
      {
        v17 = 0;
        v15 = 0;
        v16 = 0;
        v18 = 0;
        if ( a7 )
          goto LABEL_7;
      }
      v21 = 0;
      v19 = 0;
      v20 = 0;
      return qdf_trace_msg(
               72,
               8,
               "%s: Random mac addr: %02x:%02x:%02x:**:**:%02x and Random mac mask: %02x:%02x:%02x:**:**:%02x",
               "wlan_fill_scan_rand_attrs",
               v15,
               v16,
               v17,
               v18,
               v19,
               v20,
               v21,
               v12);
    }
  }
  return result;
}
