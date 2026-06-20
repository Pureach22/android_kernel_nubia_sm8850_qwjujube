__int64 __fastcall drm_dp_remove_payload_part1(__int64 a1, __int64 a2, __int64 *a3)
{
  __int64 v5; // x9
  __int64 v6; // x9
  __int64 v7; // x8
  __int64 v8; // x1
  __int64 v9; // x8
  __int64 v10; // x1
  __int64 result; // x0
  int v12; // w8

  mutex_lock(a1 + 800);
  v5 = *a3;
  while ( 1 )
  {
    v6 = *(_QWORD *)(v5 + 1616);
    if ( !v6 )
    {
LABEL_5:
      mutex_unlock(a1 + 800);
      v7 = *(_QWORD *)(a1 + 104);
      if ( v7 )
        v8 = *(_QWORD *)(v7 + 8);
      else
        v8 = 0;
      result = _drm_dev_dbg(
                 0,
                 v8,
                 2,
                 "Payload for VCPI %d not in topology, not sending remove\n",
                 *((unsigned __int8 *)a3 + 9));
      goto LABEL_16;
    }
    if ( v6 == *(_QWORD *)(a1 + 904) )
      break;
    v5 = *(_QWORD *)(v6 + 56);
    if ( !v5 )
      goto LABEL_5;
  }
  mutex_unlock(a1 + 800);
  v9 = *(_QWORD *)(a1 + 104);
  if ( v9 )
    v10 = *(_QWORD *)(v9 + 8);
  else
    v10 = 0;
  result = _drm_dev_dbg(0, v10, 2, "\n");
  v12 = *((_DWORD *)a3 + 6);
  if ( v12 != 2 )
  {
    if ( v12 != 3 )
      goto LABEL_16;
    drm_dp_payload_send_msg(a1, *a3, *((unsigned __int8 *)a3 + 9), 0);
    *((_DWORD *)a3 + 6) = 2;
  }
  result = drm_dp_dpcd_write_payload(a1, *((unsigned __int8 *)a3 + 9), *((unsigned __int8 *)a3 + 8), 0);
LABEL_16:
  *((_DWORD *)a3 + 6) = 1;
  return result;
}
