__int64 __fastcall populate_dot11f_ext_cap(
        __int64 a1,
        char a2,
        __int64 a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v16; // x23
  const char *v17; // x2
  int v18; // w8
  unsigned int ftm_cap; // w0
  int v20; // w8
  unsigned int v21; // w8
  __int64 v22; // x8
  int v23; // w8
  char v24; // w9
  __int16 v25; // w9

  v16 = a4 + 0x2000;
  *(_BYTE *)a3 = 1;
  if ( !a4 )
  {
    v17 = "%s: 11MC - enabled for non-SAP cases";
    goto LABEL_5;
  }
  if ( *(_BYTE *)(a4 + 8625) == 1 )
  {
    v17 = "%s: 11MC support enabled";
LABEL_5:
    qdf_trace_msg(0x35u, 8u, v17, a5, a6, a7, a8, a9, a10, a11, a12, "populate_dot11f_ext_cap");
LABEL_6:
    LOBYTE(v18) = 15;
    goto LABEL_7;
  }
  v18 = *(_DWORD *)(a4 + 88);
  if ( v18 != 1 )
    goto LABEL_6;
LABEL_7:
  *(_BYTE *)(a3 + 1) = v18;
  if ( (a2 & 1) != 0 )
    *(_QWORD *)(a3 + 2) |= 0x4000000000000000uLL;
  if ( *(_BYTE *)(*(_QWORD *)(a1 + 8) + 1049LL) == 1 )
  {
    ftm_cap = ucfg_wifi_pos_get_ftm_cap(*(_QWORD *)(a1 + 21624));
    if ( a4 )
    {
      v20 = *(_DWORD *)(a4 + 88);
      if ( v20 == 1 )
      {
        v21 = (ftm_cap >> 1) & 0x40 | (((ftm_cap >> 6) & 1) << 7) | *(_WORD *)(a3 + 10) & 0xFF3F;
        goto LABEL_17;
      }
      if ( v20 != 2 )
        goto LABEL_18;
    }
    v21 = *(_WORD *)(a3 + 10) & 0xFF3F | (__rbit32(ftm_cap & 3) >> 24);
LABEL_17:
    *(_WORD *)(a3 + 10) = v21;
  }
LABEL_18:
  v22 = *(_QWORD *)(a3 + 2) | *(unsigned __int8 *)(a1 + 17230);
  *(_QWORD *)(a3 + 2) = v22 | 4;
  if ( a4 )
  {
    if ( *(_BYTE *)(v16 + 1600) == 1 )
      *(_WORD *)(a3 + 10) |= 0x100u;
    if ( *(_BYTE *)(v16 + 1852) == 1 )
      *(_QWORD *)(a3 + 2) = v22 | 0x400004;
    v23 = *(_DWORD *)(a4 + 7036);
    if ( (v23 | 2) == 3 )
    {
      if ( (mlme_get_bigtk_support(*(_QWORD *)(a4 + 16), a5, a6, a7, a8, a9, a10, a11, a12) & 1) != 0 )
        v24 = 16;
      else
        v24 = 0;
      *(_BYTE *)(a3 + 12) = *(_BYTE *)(a3 + 12) & 0xEF | v24;
      v23 = *(_DWORD *)(a4 + 7036);
    }
    if ( (v23 & 0xFFFFFFFE) == 2 )
    {
      v25 = *(_WORD *)(a3 + 14) | 0x100;
      *(_QWORD *)(a3 + 2) |= 0x1000000uLL;
      *(_WORD *)(a3 + 14) = v25;
    }
    populate_dot11f_twt_extended_caps(a1, a4, a3);
  }
  if ( *(_BYTE *)a3 )
    *(_BYTE *)(a3 + 1) = lim_compute_ext_cap_ie_length((_BYTE *)a3);
  return 0;
}
