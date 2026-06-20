__int64 __fastcall lim_process_assoc_rsp_t2lm(
        __int64 result,
        _BYTE *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x19
  __int64 v12; // x8
  __int64 v13; // x9
  const char *v14; // x2
  unsigned int v15; // w1
  __int64 v16; // x20
  __int64 v17; // x19

  if ( !result )
  {
    v14 = "%s: invalid input parameters";
LABEL_13:
    v15 = 2;
    return qdf_trace_msg(0x35u, v15, v14, a3, a4, a5, a6, a7, a8, a9, a10, "lim_process_assoc_rsp_t2lm");
  }
  v10 = *(_QWORD *)(result + 16);
  if ( !v10 )
    return result;
  result = wlan_vdev_mlme_is_mlo_vdev(*(_QWORD *)(result + 16), a3, a4, a5, a6, a7, a8, a9, a10);
  if ( (result & 1) == 0 )
    return result;
  v12 = *(_QWORD *)(v10 + 216);
  if ( !v12 )
    return result;
  result = *(_QWORD *)(v12 + 80);
  if ( !result )
    return result;
  result = wlan_mlme_get_t2lm_negotiation_supported(result);
  if ( !(_DWORD)result )
  {
    v16 = jiffies;
    if ( lim_process_assoc_rsp_t2lm___last_ticks - jiffies + 125 < 0 )
    {
      result = qdf_trace_msg(
                 0x35u,
                 2u,
                 "%s: T2LM negotiation not supported",
                 a3,
                 a4,
                 a5,
                 a6,
                 a7,
                 a8,
                 a9,
                 a10,
                 "lim_process_assoc_rsp_t2lm");
      lim_process_assoc_rsp_t2lm___last_ticks = v16;
    }
    return result;
  }
  v13 = *(_QWORD *)(v10 + 1360);
  if ( !v13 )
  {
    v14 = "%s: ml dev ctx is null";
    goto LABEL_13;
  }
  if ( (*(_BYTE *)(v10 + 60) & 2) != 0 )
    return result;
  if ( *((_DWORD *)a2 + 1939) == 4 && *((_DWORD *)a2 + 1925) == 4 )
  {
    v14 = "%s: No t2lm IE";
    v15 = 8;
    return qdf_trace_msg(0x35u, v15, v14, a3, a4, a5, a6, a7, a8, a9, a10, "lim_process_assoc_rsp_t2lm");
  }
  v17 = *(_QWORD *)(v13 + 2224);
  if ( a2[7706] == 1 && (a2[7705] & 1) == 0 && *((_DWORD *)a2 + 1925) != 4 )
    result = (__int64)qdf_mem_copy((void *)(v17 + 324), a2 + 7700, 0x34u);
  if ( a2[7761] == 1 && *((_DWORD *)a2 + 1925) != 4 )
    return (__int64)qdf_mem_copy((void *)(v17 + 380), a2 + 7756, 0x34u);
  return result;
}
