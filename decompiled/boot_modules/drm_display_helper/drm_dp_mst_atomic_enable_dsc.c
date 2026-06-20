__int64 __fastcall drm_dp_mst_atomic_enable_dsc(__int64 a1, __int64 *a2, int a3, char a4)
{
  char *private_obj_state; // x0
  unsigned int v9; // w20
  char *v10; // x24
  __int64 v11; // x8
  __int64 v12; // x1
  __int64 v13; // x8
  __int64 v14; // x1
  char v15; // w8
  int time_slots; // w0
  __int64 v17; // x8
  __int64 v18; // x1

  private_obj_state = (char *)drm_atomic_get_private_obj_state(a1);
  v9 = (unsigned int)private_obj_state;
  if ( (unsigned __int64)private_obj_state >= 0xFFFFFFFFFFFFF001LL )
    return v9;
  v10 = private_obj_state + 56;
  do
  {
    v10 = *(char **)v10;
    if ( v10 == private_obj_state + 56 )
      goto LABEL_9;
  }
  while ( *((__int64 **)v10 - 4) != a2 );
  if ( v10 == (char *)&unk_20 )
  {
LABEL_9:
    v13 = *(_QWORD *)(a1 + 8);
    if ( v13 )
      v14 = *(_QWORD *)(v13 + 8);
    else
      v14 = 0;
    _drm_dev_dbg(0, v14, 4, "[MST PORT:%p] Couldn't find payload in mst state %p\n", a2, private_obj_state);
    return (unsigned int)-22;
  }
  if ( ((*(v10 - 12) & 2) == 0) != (a4 & 1) )
  {
    v11 = *(_QWORD *)(a1 + 8);
    if ( v11 )
      v12 = *(_QWORD *)(v11 + 8);
    else
      v12 = 0;
    _drm_dev_dbg(
      0,
      v12,
      4,
      "[MST PORT:%p] DSC flag is already set to %d, returning %d time slots\n",
      a2,
      a4 & 1,
      *((_DWORD *)v10 - 5));
    v9 = *((_DWORD *)v10 - 5);
    if ( (a4 & 1) != 0 )
      goto LABEL_17;
LABEL_14:
    v15 = 0;
LABEL_22:
    *(v10 - 12) = *(v10 - 12) & 0xFD | v15;
    return v9;
  }
  v9 = 0;
  if ( (a4 & 1) == 0 )
    goto LABEL_14;
LABEL_17:
  time_slots = drm_dp_atomic_find_time_slots(a1, a2[204], (__int64)a2, a3);
  v17 = *(_QWORD *)(a1 + 8);
  v9 = time_slots;
  if ( v17 )
    v18 = *(_QWORD *)(v17 + 8);
  else
    v18 = 0;
  _drm_dev_dbg(0, v18, 4, "[MST PORT:%p] Enabling DSC flag, reallocating %d time slots on the port\n", a2, time_slots);
  if ( (v9 & 0x80000000) == 0 )
  {
    v15 = 2;
    goto LABEL_22;
  }
  return (unsigned int)-22;
}
