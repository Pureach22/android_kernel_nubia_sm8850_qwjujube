__int64 __fastcall wlan_hdd_add_extra_ie(
        __int64 result,
        __int64 a2,
        _WORD *a3,
        unsigned __int8 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v12; // x8
  unsigned __int8 *v13; // x20
  int v14; // w25
  bool v15; // cc
  int v18; // w26
  __int64 v19; // x5
  unsigned int v20; // w6
  __int64 v21; // x4
  __int64 v22; // x24

  v12 = *(_QWORD *)(result + 2432);
  v13 = *(unsigned __int8 **)(v12 + 8);
  v14 = *(_DWORD *)(v12 + 36);
  if ( v13 )
    v15 = v14 < 2;
  else
    v15 = 1;
  if ( !v15 )
  {
    v18 = a4;
    while ( 1 )
    {
      v19 = v13[1];
      v20 = v14 - 2;
      v21 = *v13;
      v14 = v14 - 2 - v19;
      if ( v20 < (unsigned int)v19 )
        break;
      v22 = v19 + 2;
      if ( (_DWORD)v21 == v18 )
      {
        if ( (unsigned int)v22 + (unsigned __int16)*a3 > 0x200 )
        {
          result = qdf_trace_msg(
                     0x33u,
                     2u,
                     "%s: IE Length is too big IEs eid: %d elem_len: %d total_ie_len: %d",
                     a5,
                     a6,
                     a7,
                     a8,
                     a9,
                     a10,
                     a11,
                     a12,
                     "wlan_hdd_add_extra_ie");
        }
        else
        {
          result = (__int64)qdf_mem_copy((void *)(a2 + (unsigned __int16)*a3), v13, (unsigned int)v22);
          *a3 += v22;
        }
      }
      v13 += v22;
      if ( v14 <= 1 )
        return result;
    }
    return qdf_trace_msg(
             0x33u,
             2u,
             "%s: **Invalid IEs eid: %d elem_len: %d left: %d**",
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             a12,
             "wlan_hdd_add_extra_ie",
             v21);
  }
  return result;
}
