__int64 __fastcall dsi_display_get_panel_scan_line(
        __int64 a1,
        _WORD *a2,
        _QWORD *a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        int a7,
        int a8)
{
  unsigned int v8; // w19
  __int64 v12; // x0
  int v13; // w23
  int v14; // w22
  int v15; // w24
  __int64 v16; // x9
  size_t v17; // x20
  __int64 v18; // x0
  char v20; // [xsp+0h] [xbp-30h]
  __int64 v21; // [xsp+10h] [xbp-20h] BYREF
  unsigned __int16 v22; // [xsp+1Ch] [xbp-14h] BYREF
  _QWORD v23[2]; // [xsp+20h] [xbp-10h] BYREF

  v8 = -22;
  v23[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v23[0] = 0x450100000A000106LL;
  v21 = 0;
  if ( a1 && a2 && a3 )
  {
    v22 = 0;
    sde_evtlog_log(sde_dbg_base_evtlog, "dsi_display_get_panel_scan_line", 8134, -1, 4369, -1059143953, a7, a8, v20);
    v12 = dsi_display_cmd_receive(a1, (__int64)v23, 8u, (__int64)&v22, 2u, &v21);
    v13 = (unsigned __int8)v22;
    v14 = v12;
    v15 = HIBYTE(v22);
    if ( (int)v12 <= 0 )
    {
      v8 = -22;
    }
    else
    {
      v16 = v21;
      v8 = 0;
      *a2 = _byteswap_ushort(v22);
      *a3 = v16;
    }
    v17 = sde_dbg_base_evtlog;
    v18 = ktime_get(v12);
    sde_evtlog_log(v17, "dsi_display_get_panel_scan_line", 8147, -1, 8738, v14, v13, v15, (v18 - v21) / 1000);
  }
  _ReadStatusReg(SP_EL0);
  return v8;
}
