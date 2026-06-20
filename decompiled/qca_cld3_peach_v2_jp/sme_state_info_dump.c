void __fastcall sme_state_info_dump(
        __int64 *a1,
        _WORD *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v11; // x21
  _QWORD *context; // x0
  _QWORD *v14; // x22
  __int64 active; // x0
  int v16; // w3
  int v17; // w23
  int v18; // w0
  __int64 v19; // x24
  _DWORD *v20; // x27
  __int64 v21; // x28
  __int64 v22; // x8
  int v23; // w0
  int v24; // w23
  int v25; // w0

  v11 = *a1;
  context = _cds_get_context(52, (__int64)"sme_state_info_dump", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( context )
  {
    v14 = context;
    active = csr_nonscan_active_ll_peek_head(context, 1);
    if ( active && (v16 = *(unsigned __int8 *)(active + 24), v16 != 255) )
    {
      scnprintf(v11, (unsigned __int16)*a2, "\n active command sessionid %d", v16);
      v17 = v18;
    }
    else
    {
      v17 = 0;
    }
    v19 = 0;
    v20 = (_DWORD *)v14 + 4299;
    v21 = 1;
    do
    {
      v22 = v14[2153];
      if ( v22
        && *(_BYTE *)(v22 + v21) == 1
        && (wlan_get_opmode_from_vdev_id(v14[2695], v19) & 0xFFFFFFFD) == 0
        && cm_is_vdevid_connected(v14[2695], v19) )
      {
        scnprintf(
          v11 + (unsigned __int16)v17,
          (unsigned __int16)*a2 - (unsigned __int64)(unsigned __int16)v17,
          "\n RoamState: %d",
          *(v20 - 6));
        v24 = v17 + v23;
        scnprintf(
          v11 + (unsigned __int16)v24,
          (unsigned __int16)*a2 - (unsigned __int64)(unsigned __int16)v24,
          "\n RoamSubState: %d",
          *v20);
        v17 = v24 + v25;
      }
      ++v19;
      ++v20;
      v21 += 96;
    }
    while ( v19 != 6 );
    *a2 -= v17;
    *a1 += (unsigned __int16)v17;
  }
}
