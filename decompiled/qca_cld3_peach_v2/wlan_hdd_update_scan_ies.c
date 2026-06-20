__int64 __fastcall wlan_hdd_update_scan_ies(__int64 result, unsigned __int8 *a2, unsigned __int16 *a3)
{
  unsigned int v3; // w27
  unsigned __int8 *v4; // x21
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x22
  unsigned int v16; // w25
  unsigned int v17; // w28
  __int64 v18; // x5
  __int64 v19; // x8

  v3 = *(unsigned __int16 *)(result + 2064);
  if ( *(_WORD *)(result + 2064) )
  {
    v4 = *(unsigned __int8 **)(result + 2056);
    if ( v4 )
    {
      result = (__int64)wlan_get_vendor_ie_ptr_from_oui(&unk_9E723A, 4u, a2, *a3);
      if ( v3 >= 2 )
      {
        v15 = result;
        do
        {
          v16 = v4[1];
          v17 = v3 - 2;
          v18 = *v4;
          if ( v16 > (unsigned __int16)(v3 - 2) )
            return qdf_trace_msg(
                     0x33u,
                     2u,
                     "%s: Invalid element len %d for elem %d",
                     v7,
                     v8,
                     v9,
                     v10,
                     v11,
                     v12,
                     v13,
                     v14,
                     "wlan_hdd_update_scan_ies",
                     v4[1],
                     v18);
          if ( (_DWORD)v18 == 127 )
          {
            result = (__int64)wlan_get_ie_ptr_from_eid(0x7Fu, a2, *a3);
            if ( result )
              goto LABEL_6;
          }
          else
          {
            if ( (_DWORD)v18 != 221 )
              goto LABEL_6;
            if ( v15 || (unsigned int)qdf_mem_cmp(v4 + 2, &unk_9E723A, 4u) )
            {
              result = qdf_mem_cmp(v4 + 2, &unk_977A7E, 4u);
              if ( (_DWORD)result )
                goto LABEL_6;
            }
          }
          v19 = *a3;
          if ( (unsigned int)v19 + v16 >= 0x801 )
            return qdf_trace_msg(
                     0x33u,
                     2u,
                     "%s: Not enough buffer to save default scan IE's",
                     v7,
                     v8,
                     v9,
                     v10,
                     v11,
                     v12,
                     v13,
                     v14,
                     "wlan_hdd_update_scan_ies");
          result = (__int64)qdf_mem_copy(&a2[v19], v4, v16 + 2);
          *a3 += v16 + 2;
LABEL_6:
          v3 = v17 - v16;
          v4 += v16 + 2;
        }
        while ( (unsigned __int16)(v17 - v16) > 1u );
      }
    }
  }
  return result;
}
