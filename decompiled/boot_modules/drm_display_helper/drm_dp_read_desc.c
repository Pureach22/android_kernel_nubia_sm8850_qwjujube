__int64 __fastcall drm_dp_read_desc(const char **a1, unsigned __int16 *a2, char a3)
{
  unsigned int v5; // w1
  __int64 result; // x0
  __int64 v8; // x8
  int v9; // w23
  unsigned __int16 *v10; // x11
  int v11; // w12
  int v12; // w11
  char *v14; // x11
  bool v15; // zf
  bool v16; // zf
  size_t v17; // x0
  const char *v18; // x9
  __int64 v19; // x1
  const char *v20; // x5
  __int64 v21; // x0

  _ReadStatusReg(SP_EL0);
  if ( (a3 & 1) != 0 )
    v5 = 1280;
  else
    v5 = 1024;
  result = drm_dp_dpcd_read(a1, v5, (__int64)a2, 12);
  if ( (result & 0x80000000) != 0 )
  {
LABEL_32:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v8 = 0;
  v9 = 0;
  do
  {
    v10 = (unsigned __int16 *)&dpcd_quirk_list[v8];
    if ( dpcd_quirk_list[v8 + 9] == (a3 & 1) )
    {
      v11 = *v10;
      v12 = *((unsigned __int8 *)v10 + 2);
      if ( v11 == *a2 && v12 == *((unsigned __int8 *)a2 + 2) )
      {
        v14 = &dpcd_quirk_list[v8];
        v15 = !*(_DWORD *)&dpcd_quirk_list[v8 + 3] && *(_WORD *)&dpcd_quirk_list[v8 + 7] == 0;
        if ( v15
          || (*(_DWORD *)(v14 + 3) == *(_DWORD *)((char *)a2 + 3)
            ? (v16 = *(unsigned __int16 *)(v14 + 7) == *(unsigned __int16 *)((char *)a2 + 7))
            : (v16 = 0),
              v16) )
        {
          v9 |= *((_DWORD *)v14 + 3);
        }
      }
    }
    v8 += 16;
  }
  while ( v8 != 128 );
  *((_DWORD *)a2 + 3) = v9;
  v17 = strnlen((const char *)a2 + 3, 6u);
  if ( v17 < 7 )
  {
    v18 = a1[157];
    if ( v18 )
      v19 = *((_QWORD *)v18 + 1);
    else
      v19 = 0;
    if ( (a3 & 1) != 0 )
      v20 = "branch";
    else
      v20 = "sink";
    _drm_dev_dbg(
      0,
      v19,
      2,
      "%s: DP %s: OUI %*phD dev-ID %*pE HW-rev %d.%d SW-rev %d.%d quirks 0x%04x\n",
      *a1,
      v20,
      3,
      a2,
      v17,
      (char *)a2 + 3,
      *((unsigned __int8 *)a2 + 9) >> 4,
      *((_BYTE *)a2 + 9) & 0xF,
      *((unsigned __int8 *)a2 + 10),
      *((unsigned __int8 *)a2 + 11),
      v9);
    result = 0;
    goto LABEL_32;
  }
  v21 = _fortify_panic(2, 6, v17 + 1);
  return drm_dp_dsc_sink_bpp_incr(v21);
}
