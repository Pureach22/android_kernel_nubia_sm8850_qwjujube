__int64 __fastcall lim_mlo_sap_validate_and_update_ra(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 result; // x0
  __int64 v13; // x20
  __int64 mlpeer; // x0
  __int64 v15; // x8
  bool v16; // zf
  __int64 v17; // x0
  int v18; // t1
  bool v19; // zf
  __int16 v20; // w9
  int v21; // w8

  result = *(_QWORD *)(a1 + 16);
  if ( *(_DWORD *)(result + 16) == 1 )
  {
    result = wlan_vdev_mlme_is_mlo_vdev(result, a3, a4, a5, a6, a7, a8, a9, a10);
    if ( (result & 1) != 0 )
    {
      v13 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 1360LL);
      qdf_mutex_acquire(v13 + 1584);
      mlpeer = mlo_get_mlpeer(v13, a2);
      if ( mlpeer )
      {
        if ( *(_BYTE *)(mlpeer + 31) == 1
          && ((v15 = mlpeer + 24, *(_DWORD *)a2 == *(_DWORD *)(mlpeer + 24))
            ? (v16 = *(unsigned __int16 *)(a2 + 4) == *(unsigned __int16 *)(mlpeer + 28))
            : (v16 = 0),
              !v16)
          || *(_BYTE *)(mlpeer + 71) == 1
          && ((v18 = *(_DWORD *)(mlpeer + 64), v17 = mlpeer + 64, v15 = v17, *(_DWORD *)a2 == v18)
            ? (v19 = *(unsigned __int16 *)(a2 + 4) == *(unsigned __int16 *)(v17 + 4))
            : (v19 = 0),
              !v19) )
        {
          v20 = *(_WORD *)(v15 + 4);
          v21 = *(_DWORD *)v15;
          *(_WORD *)(a2 + 4) = v20;
          *(_DWORD *)a2 = v21;
        }
      }
      return qdf_mutex_release(v13 + 1584);
    }
  }
  return result;
}
